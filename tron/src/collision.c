#include "../include/raylib.h"
#include "../include/player.h"
#include <math.h>
#include <stdio.h>


int checkBorders(Player *player, Vector2 front){
    if (((front.x > 1000 || front.y > 1000) || (front.x < 0 || front.y < 0)) && !(player->state)) {
        player->state = true;
    }
    return 0;
}

//Checks if a player hits another player
int checkTriangle(Vector2 vertexP1[], Vector2 vertexP2[], Player *player){

    
    for(int i = 0; i < 3; i++) {
        if (CheckCollisionPointTriangle(player->triangle.vertex[i], vertexP2[0], vertexP2[1], vertexP2[2] )) {
            player->state= true;
        }
        if (CheckCollisionPointTriangle(player->triangle.vertex[i], vertexP1[0], vertexP1[1], vertexP1[2])) {
            player->state= true;
        }
    }



    return 0;
}


int checkCollision(Player *player1, Player *player2, Vector2 trailFix[], Vector2 vertexP1[], Vector2 vertexP2[]){

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
    checkTriangle(player1->triangle.vertex, player2->triangle.vertex, player1);

    checkTriangle(player1->triangle.vertex, player2->triangle.vertex, player2);

    checkBorders(player1, player1->triangle.vertex[0]);

    checkBorders(player2, player2->triangle.vertex[0]);

    
  return 0;
}


