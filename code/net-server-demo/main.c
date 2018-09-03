/*
 * "Bixi" - Basic types management C89 library
 *
 *  Copyright (C) Alexey Shishkin 2017
 *
 *  This file is part of Project "Bixi".
 *
 *  Project "Bixi" is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project "Bixi" is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project "Bixi". If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE 1
#include <libbixi.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* After running this application connect to machine where app is
 * running to port NET_PORT to receive current time in one of three
 * available forms */

#define NET_PORT (20622)

#define MESSAGE ("Current time: %u\n"\
                 "System: %s/%u")
#define HEADER_TEMPLATE ("POST /time HTTP/1.1\n" \
                         "Content-type: %s\n"    \
                         "Content-length: %u\n"  \
                         "Connection: close\n"   \
                         "\r\n")

typedef enum
{
    DEMO_PROTO_BASE64,
    DEMO_PROTO_HEX,
    DEMO_PROTO_TEXT,

    DEMO_PROTO_COUNT
} demo_proto_type;

static void my_memerr(u32 req, const char * file, u32 line)
{
    printf("[E]: [my_memerr] on %s:%u while requesting %u bytes\n",
           file, line, req);
    exit(1);
}

static void * my_malloc(u32 size, const char * file, u32 line)
{
    UNUSED(file); UNUSED(line);
    return calloc(size, 1);
}

static void my_free(void * ptr, const char * file, u32 line)
{
    UNUSED(file); UNUSED(line);
    free(ptr);
}

static void * my_realloc(void * ptr, u32 size, const char * file, u32 line)
{
    UNUSED(file); UNUSED(line);
    return realloc(ptr, size);
}

static void nsleep(u32 sec, u32 nsec)
{
    struct timespec ts;
    ts.tv_sec  = sec;
    ts.tv_nsec = nsec;

    nanosleep(&ts, NULL);
}

static void net_init_memory(void)
{
    bxi_memerr_set (my_memerr);
    bxi_malloc_set (my_malloc);
    bxi_realloc_set(my_realloc);
    bxi_free_set   (my_free);
}

static void net_init_sleep (void)
{
    bxi_nsleep_set(nsleep);
}

void net_bixi_init(void)
{
    net_init_memory();
    net_init_sleep();
}


static void _form_header(bxi_bts * out, demo_proto_type type)
{
    char buffer[1024];
    bxi_bts bts = BXI_BTS_INIT;
    sprintf(buffer, HEADER_TEMPLATE,
            type == DEMO_PROTO_BASE64 ? "text/html" :
            type == DEMO_PROTO_TEXT   ? "application/base64" :
            type == DEMO_PROTO_HEX    ? "text/hex" : "",
            out->size);

    bxi_bts_append_string(&bts, buffer);
    bxi_bts_insert(out, &bts, 0);
}

static void _form_package(bxi_bts * in, bxi_bts * out, demo_proto_type type)
{
    char buffer[1024] = { 0 };

    switch (type)
    {
    case DEMO_PROTO_TEXT:
        bxi_memcpy(buffer, in->data, in->size);
        break;
    case DEMO_PROTO_HEX:
        bxi_raw2hex(buffer, in->data, in->size, BXI_HEX_COMBO_C);
        buffer[bxi_strlen(buffer) - 2] = '\0';
        break;
    case DEMO_PROTO_BASE64:
        bxi_bin2base64(in->data, in->size, buffer, BXI_BASE64_STANDARD);
        break;
    default:
        break;
    }

    bxi_bts_append_string(out, buffer);
    bxi_bts_append_string(out, "\r\n");

    _form_header(out, type);
}

static void send_time(i32 client)
{
    char buffer[1024] = { 0 };
    bxi_bts bts = BXI_BTS_INIT;
    bxi_bts out = BXI_BTS_INIT;

    sprintf(buffer, MESSAGE, (u32)time(NULL), BXI_OS, BXI_BITS);
    bxi_bts_append_string(&bts, buffer);

    _form_package(&bts, &out, bxi_randu8() % DEMO_PROTO_COUNT);

    send(client, out.data, out.size, MSG_NOSIGNAL);

    bxi_free(bts.data);
    bxi_free(out.data);
}

int main(void)
{
    struct sockaddr_in addr;
    fd_set readfds;
    i32 listener;
    i32 opt = 1;

    net_bixi_init();
    bxi_srand((u32)time(NULL));

    addr.sin_family      = AF_INET;
    addr.sin_port        = bxi_u162u16_be(NET_PORT);
    addr.sin_addr.s_addr = bxi_u322u32_be(INADDR_ANY);

    listener = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bind(listener, (struct sockaddr *)&addr, sizeof(addr));
    listen(listener, 1);

    fprintf(stdout, "[I] Ready. Connect to 127.0.0.1:%u\n", NET_PORT);

    while (1)
    {
        i32 sel;

        FD_ZERO(&readfds);
        FD_SET(listener, &readfds);

        sel = select(listener + 1, &readfds, NULL, NULL, NULL);

        if (sel < 0)
        {
            fprintf(stderr, "[E] Bad select\n");
            exit(1);
        }
        else if (sel == 0)
        {
            fprintf(stderr, "[E] Select timeout\n");
            exit(1);
        }
        else
        {
            if (FD_ISSET(listener, &readfds))
            {
                i32 client = accept(listener, NULL, NULL);
                fprintf(stdout, "[I] Client connected\n");

                send_time(client);
                close(client);
            }
        }
    }

    return 0;
}
