#include "../include/player.h"
#include "unistd.h"
#include "render.c"
#include "../include/raylib.h"
#include "stdlib.h"
//No tocar esto lo reconoce raylib
static bool gameStarted = false;
static bool gameOver = false;

int speed = 2;

Triangle player1 = {(Vector2){500, 200}, 20, 40, RED, false, 0, 0};
Triangle player2 = {(Vector2){500, 800}, 20, 40, BLUE, false, 0, 0};


/*I tried to use the same player.h header for both but i have the theory that as it is a pointer and both being arrays
it breaks because being dynamic also saves it on the same memory so i implemented different approaches/instances*/
Vector2 trailFix[100000]; 

int scoreP1 = 0; 
int scoreP2 = 0; 

void savePos1(){
    if (player1.trailLength < 10000) {
        trailFix[player1.trailLength] = player1.position;
        player1.trailLength+=1;
    }
}

void savePos2(){
    if (player2.trailLength < 10000) {
        player2.trail[player2.trailLength] = player2.position;
        player2.trailLength+=1;
    }
}

void movePlayer1(){
    if (IsKeyDown(KEY_UP)) {
        player1.position.y -= speed;
        player1.rotation = 270;
        savePos1();
    }
    if (IsKeyDown(KEY_DOWN)) {
        player1.position.y += speed;
        player1.rotation = 90;
        savePos1();
    }
    if (IsKeyDown(KEY_LEFT)) {
        player1.position.x -= speed;
        player1.rotation = 180;
        savePos1();
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player1.position.x += speed;
        player1.rotation = 0;
        savePos1();
    }
}

void movePlayer2(){
    if (IsKeyDown(KEY_W)) {
        player2.position.y -= speed;
        player2.rotation = 270;
        savePos2();
    }
    if (IsKeyDown(KEY_S)) {
        player2.position.y += speed;
        player2.rotation = 90;
        savePos2();
    }
    if (IsKeyDown(KEY_A)) {
        player2.position.x -= speed;
        player2.rotation = 180;
        savePos2();
    }
    if (IsKeyDown(KEY_D)) {
        player2.position.x += speed;
        player2.rotation = 0;
        savePos2();
    }
}   


void restartPos(){

    player1.position = (Vector2){500, 200};

    player2.position = (Vector2){500, 800};
    
    player1.height = 20;

    player2.height = 20;

    player1.width = 40;

    player2.width = 40;

    player1.rotation = 0;

    player2.rotation = 0;

    player1.state = false;

    player2.state = false;

    for (int i = 0; i < player1.trailLength; i++) {
        trailFix[i] = (Vector2){0, 0}; 
    }
    for (int i = 0; i < player2.trailLength; i++) {
        player2.trail[i] = (Vector2){0, 0}; 
    }
    player1.trailLength = 0;

    player2.trailLength = 0;               
}

void initStage(){
    if (!(player1.state || player2.state)) {

        movePlayer1();

        movePlayer2();

        defineTriShape(&player1, &player2);

        createLine(&player1, &player2, trailFix);

        DrawText(TextFormat("Player1 score: %d", scoreP1), 1, 1, 20, RED);

        DrawText(TextFormat("Player2 score: %d", scoreP2), 820, 1, 20, BLUE);
    } else {

        if (player2.state && player1.state) {

            DrawText(TextFormat("Both players died!"), 300, 500, 20, RED);

            scoreP1 += 1;
            scoreP2 += 1;

        } else if (player2.state){


            //Sleep or anything t2o show who won and restart
            DrawText(TextFormat("Player 1 won!"), 300, 500, 20, RED);

            scoreP2+= 1;

        } else if (player1.state){

            //Sleep or anything to show who won and restart
            DrawText(TextFormat("Player 2 won!"), 300, 500, 20, RED);
            scoreP1+=1;
        }
        gameOver = true;
        gameStarted = false;
    }
}

void initController(Texture2D texture) {
    if (!gameStarted && !gameOver) {
        DrawText(TextFormat("Press space to start!"), 200, 500, 60, GREEN);

        DrawTexture(texture, -15, -300, WHITE);

        if (IsKeyPressed(KEY_SPACE)) {
            gameStarted = true;
        }
    } else if (!gameStarted && gameOver){
        DrawText(TextFormat("Press R to restart!"),300, 500, 50, BLUE);

        printf("player 1: %d\n", player1.state);
        printf("player 2: %d\n", player2.state);

        if (IsKeyPressed(KEY_R)) {

            //Restart game
            restartPos();
            gameOver = false;

        }
    } else if(gameStarted){
        initStage();
    }
}





