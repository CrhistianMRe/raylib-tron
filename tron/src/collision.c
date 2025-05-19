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


int checkCollision(Triangle *player1, Triangle *player2, Vector2 trailFix[], Vector2 points[]){

    //Checkear la punta creo cuando pega jugador 1
    for (long int a= 0;a < player1->trailLength; a++) {
        if ((trailFix[a].x == points[3].x && trailFix[a].y == points[3].y) && player1->state == false) {
            player1->state = true;
        }
        //Punta pega a el mismo
        if ((trailFix[a].x == points[0].x && trailFix[a].y == points[0].y) && player1->state == false) {
            player1->state = true;
        }
    }
    //Checkear la punta creo cuando pega jugador 2
    for (long int a= 0 ;a < player2->trailLength; a++) {
        if ((player2->trail[a].x == points[0].x && player2->trail[a].y == points[0].y)&& player2->state == false) {
            player2->state = true;

        }
        //Punto pega a el mismo 2
        if ((player2->trail[a].x == points[3].x && player2->trail[a].y == points[3].y)&& player2->state == false) {
            player2->state = true;

        }
    }
    checkBorders(player1, points[0]);
    checkBorders(player2, points[3]);

    //Solucion: Checkear la colision de la punta con el array de trail de cada jugador
    /*if (playerq != 1) {
        player1->state = (CheckCollisionPointTriangle(player2->trail[playerp],  points[0], points[1], points[2]));
    //} else if (playerp != 1){
        player2->state = (CheckCollisionPointTriangle(trailFix[playerp], points[3], points[4], points[5]));
    } else {
        
    }* test 3/
        //printf("player 1: %d\n", player1->state); debug
        //Vector2* collisionPoint;
    
    /*I dont know why this function doesnt work so i will make my own one to check the collision. Update= it doesnt work with triangles 
        player1->state = CheckCollisionLines(trailFix[playerq], trailFix[playerq+1], trailFix[playerq], trailFix[playerq+1], collisionPoint);
        player2->state = CheckCollisionLines(player2->trail[playerq], player2->trail[playerq +1], player2->trail[playerq], player2->trail[playerq+1], collisionPoint);
        printf("player 2: %d\n", player2->state);
    *Test 2/


    /*for (int first; first < player1->trailLength ;first++ {
        for (int second; second < player2->trailLength;second++) {
            if (true) {
            }

        }
    test 1*//* */
  return 0;
}


