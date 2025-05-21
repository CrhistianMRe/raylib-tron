#ifndef _triangle_h
#define _triangle_h
#include "raylib.h" 

#define MAX_TRAIL 100000
typedef struct Triangle{
    Vector2 position;
    long int height;
    long int width;
    Color color;
    float rotation;
    bool state;
    long int trailLength;
    Vector2 trail[MAX_TRAIL];
} Triangle;




#endif // !_triangle_h
