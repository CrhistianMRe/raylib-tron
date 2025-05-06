#include "player.h"
#include "render.c"
//No tocar esto lo reconoce raylib
static bool gameStarted = false;
static bool gameOver = false;

Triangle player1 = {(Vector2){250, 100}, 20, 40, RED, false, 0, 0};
Triangle player2 = {(Vector2){250, 400}, 20, 40, BLUE, false, 0, 0};
/*I tried to use the same player.h header for both but i have the theory that as it is a pointer and both being arrays
it breaks because being dynamic also saves it on the same memory so i implemented different approaches/instances*/
Vector2 trailFix[1000]; 


//player1.position.X = (Vector2){250};
//player1.position.Y = (Vector2){100};
//player1.height = 20;
//player1.width = 40;
//player1.color = RED;
//player1.state = true;

//player2.position.X = (Vector2){250};
//player2.position.Y = (Vector2) {400};
//player2.height = 20; 
//player2.width = 40;
//player2.color = BLUE;
//player2.state = true;
//
void savePos1(){
if (player1.trailLength <= 10000) {
            trailFix[player1.trailLength] = player1.position;
            player1.trailLength+=1;
        }
}

void savePos2(){
if (player2.trailLength <= 10000) {
            player2.trail[player2.trailLength] = player2.position;
            player2.trailLength+=1;
        }
}

 void movePlayer1(){
    if (IsKeyDown(KEY_UP)) {
        player1.position.y -= 5;
        player1.rotation = 270;
        savePos1();
    }
    if (IsKeyDown(KEY_DOWN)) {
        player1.position.y += 5;
        player1.rotation = 90;
        savePos1();
    }
    if (IsKeyDown(KEY_LEFT)) {
        player1.position.x -= 5;
        player1.rotation = 180;
        savePos1();
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player1.position.x += 5;
        player1.rotation = 0;
        savePos1();
    }
}

void movePlayer2(){
    if (IsKeyDown(KEY_W)) {
        player2.position.y -= 5;
        player2.rotation = 270;
        savePos2();
    }
    if (IsKeyDown(KEY_S)) {
        player2.position.y += 5;
        player2.rotation = 90;
        savePos2();
    }
    if (IsKeyDown(KEY_A)) {
        player2.position.x -= 5;
        player2.rotation = 180;
        savePos2();
    }
    if (IsKeyDown(KEY_D)) {
        player2.position.x += 5;
        player2.rotation = 0;
        savePos2();
    }
}   
    

void initGame(){
    if ((player1.state == false && player2.state == false )) {
     
    gameOver = false; 

    gameStarted = false;
    //player1
    movePlayer1();

    movePlayer2();

    //movePlayer1();
    defineTriShape(&player1, &player2);
    createLine(&player1, &player2, trailFix);
  } 
}

void updateGame() {
    if (!gameStarted) {
        if (IsKeyPressed(KEY_SPACE)) {
            gameStarted = true;
        }
    }
    else if (!gameOver) {
        //updatePlayer(&player1);
        
        //updatePlayer(&player2);
        movePlayer1();

        movePlayer2();
    }
    else {
        if (IsKeyPressed(KEY_R)) {
            initGame();
        }
    }
}

