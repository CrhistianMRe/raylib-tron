#ifndef _triangle_h
#define _triangle_h
#include "raylib.h" 

#define MAX_TRAIL 100000
#define KEY_AMOUNT 4 
typedef struct Triangle{
    Vector2 position;
    long int height;
    long int width;
    Color color;
    float rotation;
    bool state;
    long int trailLength;
    Vector2 trail[MAX_TRAIL];
    int key[4];
} Triangle;




#endif // !_triangle_h
