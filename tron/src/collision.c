#include "../include/raylib.h"
#include "../include/player.h"
#include <math.h>
#include <stdio.h>


int checkBorders(Triangle *player, Vector2 front){
    if (((front.x > 1000 || front.y > 1000) || (front.x < 0 || front.y < 0)) && !(player->state)) {
        player->state = true;
    }
    return 0;
}

//Checks if a player hits another player
int checkTriangle(Vector2 vertexP1[], Vector2 vertexP2[], Triangle *player){

    
    for(int i = 0; i < 3; i++) {
        if (CheckCollisionPointTriangle(vertexP1[i], vertexP2[0], vertexP2[1], vertexP2[2])) {
            player->state= true;
        }
        if (CheckCollisionPointTriangle(vertexP2[i], vertexP1[0], vertexP1[1], vertexP1[2])) {
            player->state= true;
        }
    }



    return 0;
}


int checkCollision(Triangle *player1, Triangle *player2, Vector2 trailFix[], Vector2 vertexP1[], Vector2 vertexP2[]){

    //Checkear la punta player 2 cuando pega jugador 1
    for (long int a= 0;a < player1->trailLength; a++) {
        if ((trailFix[a].x == vertexP2[0].x && trailFix[a].y == vertexP2[0].y) && player1->state == false) {
            player1->state = true;
        }
        //Punta pega a el mismo player 1
        if ((trailFix[a].x == vertexP1[0].x && trailFix[a].y == vertexP1[0].y) && player1->state == false) {
            player1->state = true;
        }
    }
    //Checkear la punta creo cuando pega jugador 2
    for (long int a= 0 ;a < player2->trailLength; a++) {
        if ((player2->trail[a].x == vertexP1[0].x && player2->trail[a].y == vertexP1[0].y)&& player2->state == false) {
            player2->state = true;

        }
        //Punto pega a el mismo 2
        if ((player2->trail[a].x == vertexP2[0].x && player2->trail[a].y == vertexP2[0].y)&& player2->state == false) {
            player2->state = true;

        }
    }
    checkTriangle(vertexP1, vertexP2, player1);

    checkTriangle(vertexP1, vertexP2, player2);

    checkBorders(player1, vertexP1[0]);

    checkBorders(player2, vertexP2[0]);

    
  return 0;
}


