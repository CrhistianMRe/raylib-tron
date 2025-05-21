#include "../include/player.h"
#include "../include/raylib.h"
#include <math.h>
#include <stdio.h>
#include "collision.c"
Vector2 vertexP1[3]; 
Vector2 vertexP2[3]; 


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

int displayTriangle(Triangle *player1, Triangle *player2) {
if (!player1 || !player2) {
    printf("Error: player1 or player2 is NULL\n");
}else{

    /*printf("Player1 vertices:\n");
    for (int i = 0; i < 3; i++) {
        printf("  vertexP1[%d] = (%.2f, %.2f)\n", i, vertexP1[i].x, vertexP1[i].y);
    }
    printf("Player2 vertices:\n");
    for (int i = 0; i < 3; i++) {
        printf("  vertexP2[%d] = (%.2f, %.2f)\n", i, vertexP2[i].x, vertexP2[i].y);
    }*/
    
    DrawLineV(vertexP1[0], vertexP1[1], WHITE);
    DrawLineV(vertexP1[1], vertexP1[2], WHITE);
    DrawLineV(vertexP1[2], vertexP1[0], WHITE);

    DrawLineV(vertexP2[0], vertexP2[1], WHITE);
    DrawLineV(vertexP2[1], vertexP2[2], WHITE);
    DrawLineV(vertexP2[2], vertexP2[0], WHITE);


    DrawTriangle(vertexP1[0], vertexP1[1], vertexP1[2], player1->color);
    DrawTriangle(vertexP2[0], vertexP2[1], vertexP2[2], player2->color);

    /*DrawCircleV(vertexP1[0], 5, RED);
    DrawCircleV(vertexP1[1], 5, GREEN);
    DrawCircleV(vertexP1[2], 5, BLUE);*/
    //printf("DrawTriangle called\n");
}
    return 0;
}

int defineTriShape(Triangle *player1, Triangle *player2){
    //printf("defineTriShape called\n");
    Vector2 p1 = { player1->position.x + player1->width / 2, player1->position.y };

    Vector2 p2 = { player1->position.x - player1->width / 2, player1->position.y - player1->height / 2 };

    Vector2 p3 = { player1->position.x - player1->width / 2, player1->position.y + player1->height / 2 };

    // Player 2
    Vector2 q1 = { player2->position.x + player2->width / 2, player2->position.y };

    Vector2 q2 = { player2->position.x - player2->width / 2, player2->position.y - player2->height / 2 };

    Vector2 q3 = { player2->position.x - player2->width / 2, player2->position.y + player2->height / 2 };

    //La rotacion no es el problema de la desaparicion
    p1 = RotatePoint(p1, player1->position, player1->rotation);

    p2 = RotatePoint(p2, player1->position, player1->rotation);

    p3 = RotatePoint(p3, player1->position, player1->rotation);

    q1 = RotatePoint(q1, player2->position, player2->rotation);

    q2 = RotatePoint(q2, player2->position, player2->rotation);

    q3 = RotatePoint(q3, player2->position, player2->rotation);

    vertexP1[0] = p1;

    vertexP1[1] = p2;

    vertexP1[2] = p3;

    vertexP2[0] = q1;

    vertexP2[1] = q2;

    vertexP2[2] = q3;

    displayTriangle(player1, player2);

    //printf("P1 Pos: (%f, %f), Rot: %f\n", player1->position.x, player1->position.y, player1->rotation);
    //printf("P1 Points: (%f, %f), (%f, %f), (%f, %f)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    //printf("Player1 Pos: %f, %f\n", player1->position.x, player1->position.y);
    //printf("Player2 Pos: %f, %f\n", player2->position.x, player2->position.y);

    //printf("Player1 Color - R: %d, G: %d, B: %d, A: %d\n", player1->color.r, player1->color.g, player1->color.b, player1->color.a);
    //printf("Player2 Color - R: %d, G: %d, B: %d, A: %d\n", player2->color.r, player2->color.g, player2->color.b, player2->color.a);



    return 0;
}


//Calling as a parameter another instance for trail



int createLine(Triangle *player1, Triangle *player2, Vector2 trailFix[]){
    for (long int a = 1;a < player1->trailLength -3; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(trailFix[a], trailFix[a +1], player1->color);
        //printf("counter %d", a); debug
       //if (trailFix[a] == player2->trail[a] || trailFix[a+1] == player2->trail[a+1]) {
         //   player-> state = true;
        //}
    } 
    for (long int a = 1;a < player2->trailLength -3; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(player2->trail[a], player2->trail[a +1], player2->color);
        //printf("2counter %d", a); debug
    }
    //checkCollision(player1, player2, trailFix);

        checkCollision(player1, player2, trailFix, vertexP1, vertexP2);
    return 0;
}






