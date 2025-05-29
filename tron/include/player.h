#ifndef _player_h
#define _player_h
#include "raylib.h" 
#include "triangle.h" 


#define MAX_TRAIL 100000
#define KEY_AMOUNT 4 

typedef struct Player{
    Vector2 position;
    Triangle triangle;
    Color color;
    bool state;
    long int trailLength;
    Vector2 trail[MAX_TRAIL];
    int key[4];
    int score;
} Player;




#endif // !_player_h
