#include "../include/player.h"
#include "../include/raylib.h"
#include <math.h>
#include <stdio.h>
#include "collision.c"
Vector2 points[5]; 


// Función para rotar un punto
Vector2 RotatePoint(Vector2 point, Vector2 center, float rotation) {
    float rad = rotation * (PI / 180.0f);

    float cosR = cosf(rad);

    float sinR = sinf(rad);

    Vector2 rotated;

    rotated.x = center.x + (point.x - center.x) * cosR - (point.y - center.y) * sinR;

    rotated.y = center.y + (point.x - center.x) * sinR + (point.y - center.y) * cosR;

    //rotated.x = trunc(rotated.x);
    //rotated.y = trunc(rotated.y);
    
    
    return rotated;
}

int displayTriangle(Triangle *player1, Triangle *player2 ) {
    DrawTriangle(points[0], points[1], points[2], player1->color);
    DrawTriangle(points[3], points[4], points[5], player2->color);
    return 0;
}

int defineTriShape(Triangle *player1, Triangle *player2){
    Vector2 p1 = { player1->position.x + player1->width / 2, player1->position.y };

    Vector2 p2 = { player1->position.x - player1->width / 2, player1->position.y - player1->height / 2 };

    Vector2 p3 = { player1->position.x - player1->width / 2, player1->position.y + player1->height / 2 };

    p1 = RotatePoint(p1, player1->position, player1->rotation);

    p2 = RotatePoint(p2, player1->position, player1->rotation);

    p3 = RotatePoint(p3, player1->position, player1->rotation);

    // Player 2
    Vector2 q1 = { player2->position.x + player2->width / 2, player2->position.y };

    Vector2 q2 = { player2->position.x - player2->width / 2, player2->position.y - player2->height / 2 };

    Vector2 q3 = { player2->position.x - player2->width / 2, player2->position.y + player2->height / 2 };

    q1 = RotatePoint(q1, player2->position, player2->rotation);

    q2 = RotatePoint(q2, player2->position, player2->rotation);

    q3 = RotatePoint(q3, player2->position, player2->rotation);

    points[0] = p1;

    points[1] = p2;

    points[2] = p3;

    points[3] = q1;

    points[4] = q2;

    points[5] = q3;

    displayTriangle(player1, player2);

    return 0;
}


//Calling as a parameter another instance for trail



int createLine(Triangle *player1, Triangle *player2, Vector2 trailFix[]){
    for (long int a = 1;a < player1->trailLength -6; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(trailFix[a], trailFix[a +1], player1->color);
        //printf("counter %d", a); debug
       //if (trailFix[a] == player2->trail[a] || trailFix[a+1] == player2->trail[a+1]) {
         //   player-> state = true;
        //}
    } 
    for (long int a = 1;a < player2->trailLength -6; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(player2->trail[a], player2->trail[a +1], player2->color);
        //printf("2counter %d", a); debug
    }
    //checkCollision(player1, player2, trailFix);

        checkCollision(player1, player2, trailFix, points);
    return 0;
}






