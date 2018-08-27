## bxiplan.h 

For planimetry purposes the following definitions, types and functions are set:
```c
#define MM_PER_INCH
```
```c
bxi_pointf
bxi_pointi
bxi_pointu
bxi_lineu
bxi_linei
bxi_linef
bxi_recti
bxi_rectu
bxi_rectf
bxi_triangleu
bxi_trianglei
bxi_trianglef
bxi_tetragonu
bxi_tetragoni
bxi_tetragonf
bxi_circlei
bxi_circleu
bxi_circlef
```
```c
bxi_point
bxi_line
bxi_rect
bxi_circle
bxi_triangle
bxi_tetragon
bxi_size
```
```c
bxi_size     bxi_size_c    (u32 x,  u32 y);
bxi_point    bxi_point_c   (i32 x,  i32 y);
bxi_line     bxi_line_c    (bxi_point p1, bxi_point p2);
bxi_rect     bxi_rect_c    (bxi_point p1, bxi_point p2);
bxi_circle   bxi_circle_c  (bxi_point c,  i32 r);
bxi_triangle bxi_triangle_c(bxi_point p1, bxi_point p2, bxi_point p3);
bxi_tetragon bxi_tetragon_c(bxi_point p1, bxi_point p2, bxi_point p3, bxi_point p4);
```
```c
bool bxi_segment_cross(bxi_line * l1, bxi_line * l2, bxi_point * c);
```
