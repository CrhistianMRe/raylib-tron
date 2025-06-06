#include "../include/player.h"
#include "../include/triangle.h"
#include "../include/raylib.h"
#include "../include/render.h"

#include "unistd.h"
#include "stdlib.h"
//No tocar esto lo reconoce raylib
static bool gameStarted = false;
static bool gameOver = false;

const int speed = 2;

Player player1 = {(Vector2){500, 200},(Triangle) {20, 40, 0}, RED, false, 0,{},{KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT}, 0};
Player player2 = {(Vector2){500, 800},(Triangle) {20, 40, 0}, BLUE, false, 0,{}, {KEY_W, KEY_S, KEY_A, KEY_D}, 0};


void savePlayerPos(Player *player){
    if (player->trailLength < 10000) {
        player->trail[player->trailLength] = player->position;
        player->trailLength+=1;
    }
}

void movePlayerPos(Player *player){
    if (IsKeyDown(player->key[0])) {
        player->position.y -= speed;
        player->triangle.rotation = 270;
        savePlayerPos(player);
    }
    if (IsKeyDown(player->key[1])) {
        player->position.y += speed;
        player->triangle.rotation = 90;
        savePlayerPos(player);
    }
    if (IsKeyDown(player->key[2])) {
        player->position.x -= speed;
        player->triangle.rotation = 180;
        savePlayerPos(player);
    }
    if (IsKeyDown(player->key[3])) {
        player->position.x += speed;
        player->triangle.rotation = 0;
        savePlayerPos(player);
    }
}



void restartPlayer(){

    player1.position = (Vector2){500, 200};
    player1.triangle.height = 20;
    player1.triangle.width = 40;
    player1.triangle.rotation = 0;
    player1.state = false;
    player1.trailLength = 0;

    player2.position = (Vector2){500, 800};
    player2.triangle.height = 20;
    player2.triangle.width = 40;
    player2.triangle.rotation = 0;
    player2.state = false;
    player2.trailLength = 0;               

    for (int i = 0; i < player1.trailLength; i++) {
        player1.trail[i] = (Vector2){0, 0}; 
    }
    for (int i = 0; i < player2.trailLength; i++) {
        player2.trail[i] = (Vector2){0, 0}; 
    }

}

void initStage(){
    if (!(player1.state || player2.state)) {
        movePlayerPos(&player1);
        movePlayerPos(&player2);
        initRender(&player1, &player2);

        DrawText(TextFormat("Player1 score: %d", player1.score), 1, 1, 20, RED);
        DrawText(TextFormat("Player2 score: %d", player2.score), 820, 1, 20, BLUE);

    } else {
        if (player2.state && player1.state) {
            DrawText(TextFormat("Both players died!"), 300, 500, 20, RED);
            player1.score += 1;
            player2.score += 1;

        } else if (player1.state){
            //Sleep or anything t2o show who won and restart
            DrawText(TextFormat("Player 1 won!"), 300, 500, 20, RED);
            player2.score += 1;

        } else if (player2.state){
            //Sleep or anything to show who won and restart
            DrawText(TextFormat("Player 2 won!"), 300, 500, 20, RED);
            player1.score += 1;

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

        if (IsKeyPressed(KEY_R)) {
            //Restart game
            restartPlayer();
            gameOver = false;

        }
    } else if(gameStarted){
        initStage();

    }
}





