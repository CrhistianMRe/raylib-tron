#ifndef _triangle_h
#define _triangle_h
#include "raylib.h" 


typedef struct Triangle{
    Vector2 position;
    long int height;
    long int width;
    Color color;
    float rotation;
    bool state;
    long int trailLength;
    Vector2 trail[];
} Triangle;




#endif // !_triangle_h
