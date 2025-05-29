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

void displayTriangle(Player *player) {
if (!player) {
    printf("Error: player1 or player2 is NULL\n");
}else{
    DrawTriangle(player->triangle.vertex[0], player->triangle.vertex[1], player->triangle.vertex[2], player->color);
}
}

void defineTriShape(Player *player){
    //Vertex shape
    Vector2 p1 = { player->position.x + player->triangle.width / 2, player->position.y };
    Vector2 p2 = { player->position.x - player->triangle.width / 2, player->position.y - player->triangle.height / 2 };
    Vector2 p3 = { player->position.x - player->triangle.width / 2, player->position.y + player->triangle.height / 2 };

    //Add rotation to vertex
    p1 = RotatePoint(p1, player->position, player->triangle.rotation);
    p2 = RotatePoint(p2, player->position, player->triangle.rotation);
    p3 = RotatePoint(p3, player->position, player->triangle.rotation);

    //Assing values to player instance
    player->triangle.vertex[0] = p1;
    player->triangle.vertex[1] = p2;
    player->triangle.vertex[2] = p3;
}

void drawTrail(Player *player){
    for (long int a = 1;a < player->trailLength -3; a++) {
        //Empieza desde a y el +1 es para aumentar el rango
        DrawLineV(player->trail[a], player->trail[a +1], player->color);
    } 
}

void drawPlayer(Player *player1, Player *player2){

    //Define first the shape of the triangle
    defineTriShape(player1);
    defineTriShape(player2);

    //After defining shape draw the triangle
    displayTriangle(player1);
    displayTriangle(player2);

    //Trail
    drawTrail(player1);
    drawTrail(player2);

    //Main collision method in collision.c
    checkCollision(player1, player2, player1->trail, player1->triangle.vertex, player2->triangle.vertex);
}







