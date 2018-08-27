## bxicrypt.h 

The following functions provide ability to XOR-crypt provided data string. If
the key or salt is shorter than data the salt/key will be circularly extended.

```c
BXI_USES_MEM void bxi_crypt  (const char *    string, const char * salt, const char * key, char * out); /* @test */
BXI_USES_MEM void bxi_decrypt(const char * hexstring, const char * salt, const char * key, char * out); /* @test */
```