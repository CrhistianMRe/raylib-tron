#include "../include/player.h"
#include "../include/raylib.h"
#include <math.h>
#include <stdio.h>
#include "collision.c"


// Función para rotar un punto
Vector2 RotatePoint(Vector2 point, Vector2 center, float rotation) {

    float rad = rotation * (PI / 180.0f);

    float cosR = cosf(rad);

    float sinR = sinf(rad);

    Vector2 rotated;

    rotated.x = center.x + (point.x - center.x) * cosR - (point.y - center.y) * sinR;

    rotated.y = center.y + (point.x - center.x) * sinR + (point.y - center.y) * cosR;

    return rotated;
}

int displayTriangle(Player *player1, Player *player2) {
if (!player1 || !player2) {
    printf("Error: player1 or player2 is NULL\n");
}else{
    DrawTriangle(player1->triangle.vertex[0], player1->triangle.vertex[1], player1->triangle.vertex[2], player1->color);
    DrawTriangle(player2->triangle.vertex[0], player2->triangle.vertex[1], player2->triangle.vertex[2], player2->color);
}
    return 0;
}

int defineTriShape(Player *player1, Player *player2){
    Vector2 p1 = { player1->position.x + player1->triangle.width / 2, player1->position.y };

    Vector2 p2 = { player1->position.x - player1->triangle.width / 2, player1->position.y - player1->triangle.height / 2 };

    Vector2 p3 = { player1->position.x - player1->triangle.width / 2, player1->position.y + player1->triangle.height / 2 };

    // Player 2
    Vector2 q1 = { player2->position.x + player2->triangle.width / 2, player2->position.y };

    Vector2 q2 = { player2->position.x - player2->triangle.width / 2, player2->position.y - player2->triangle.height / 2 };

    Vector2 q3 = { player2->position.x - player2->triangle.width / 2, player2->position.y + player2->triangle.height / 2 };

    //La rotacion no es el problema de la desaparicion
    p1 = RotatePoint(p1, player1->position, player1->triangle.rotation);

    p2 = RotatePoint(p2, player1->position, player1->triangle.rotation);

    p3 = RotatePoint(p3, player1->position, player1->triangle.rotation);

    q1 = RotatePoint(q1, player2->position, player2->triangle.rotation);

    q2 = RotatePoint(q2, player2->position, player2->triangle.rotation);

    q3 = RotatePoint(q3, player2->position, player2->triangle.rotation);

    player1->triangle.vertex[0] = p1;

    player1->triangle.vertex[1] = p2;

    player1->triangle.vertex[2] = p3;

    player2->triangle.vertex[0] = q1;

    player2->triangle.vertex[1] = q2;

    player2->triangle.vertex[2] = q3;

    displayTriangle(player1, player2);

    return 0;
}


//Calling as a parameter another instance for trail

int drawTrail(Player *player1, Player *player2, Vector2 trailFix[]){
    for (long int a = 1;a < player1->trailLength -3; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(player1->trail[a], player1->trail[a +1], player1->color);
    } 
    for (long int a = 1;a < player2->trailLength -3; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(player2->trail[a], player2->trail[a +1], player2->color);
    }
        checkCollision(player1, player2, player1->trail, player1->triangle.vertex, player2->triangle.vertex);

    return 0;
}






