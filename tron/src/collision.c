#include "../include/raylib.h"
#include "../include/player.h"
#include <math.h>
#include <stdio.h>


void checkBorders(Player *player){
    if (((player->position.x > 1000 || player->position.y > 1000) || (player->position.x < 0 || player->position.y < 0)) && !(player->state)) {
        player->state = true;
    }
}

//Checks if a player hits another player
void checkTriangles(Player *player1, Player *player2){
    for(int i = 0; i < 3; i++) {
        if (CheckCollisionPointTriangle(player1->triangle.vertex[i], player2->triangle.vertex[0], player2->triangle.vertex[1], player2->triangle.vertex[2] )) {
            player1->state= true;
        }
        if (CheckCollisionPointTriangle(player2->triangle.vertex[i], player1->triangle.vertex[0], player1->triangle.vertex[1], player1->triangle.vertex[2])) {
            player2->state= true;
        }
    }
}


void initCheckCollision(Player *player1, Player *player2, Vector2 trailFix[], Vector2 vertexP1[], Vector2 vertexP2[]){

    //Checkear la punta player 2 cuando pega jugador 1
    for (long int a= 0;a < player1->trailLength; a++) {
        if ((player1->trail[a].x == player2->triangle.vertex[0].x && player1->trail[a].y == player2->triangle.vertex[0].y) && player1->state == false) {
            player2->state = true;
        }
        //Punta pega a el mismo player 1
        if ((player1->trail[a].x == player1->triangle.vertex[0].x && player1->trail[a].y == player1->triangle.vertex[0].y) && player1->state == false) {
            player1->state = true;
        }
    }
    //Checkear la punta creo cuando pega jugador 2
    for (long int a= 0 ;a < player2->trailLength; a++) {
        if ((player2->trail[a].x == player1->triangle.vertex[0].x && player2->trail[a].y == player1->triangle.vertex[0].y)&& player2->state == false) {
            player1->state = true;

        }
        //Punto pega a el mismo 2
        if ((player2->trail[a].x == player2->triangle.vertex[0].x && player2->trail[a].y == player2->triangle.vertex[0].y)&& player2->state == false) {
            player2->state = true;

        }
    }
    checkTriangles(player1, player2);


    checkBorders(player1);

    checkBorders(player2);
}


