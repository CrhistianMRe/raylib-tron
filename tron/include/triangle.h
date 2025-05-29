#ifndef _TRIANGLE_H 
#define _TRIANGLE_H 
#include "raylib.h" 

#define VERTEX_AMOUNT 3
typedef struct Triangle{
    Vector2 position;
    long int height;
    long int width;
    float rotation;
    int vertex[VERTEX_AMOUNT];
} Triangle;


#endif // 
