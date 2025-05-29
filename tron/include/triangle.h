#ifndef _TRIANGLE_H 
#define _TRIANGLE_H 
#include "raylib.h" 

#define VERTEX_AMOUNT 3
typedef struct Triangle{
    long int height;
    long int width;
    float rotation;
    Vector2 vertex[VERTEX_AMOUNT];
} Triangle;


#endif // 
