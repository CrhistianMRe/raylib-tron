#ifndef _RENDER_H
#define _RENDER_H

#include "../include/player.h"
#include "../include/raylib.h"



Vector2 RotatePoint(Vector2 point, Vector2 center, float rotation);
void displayTriangle(Player *player);
void defineTriShape(Player *player);
void drawTrail(Player *player);
//Main render function
void initRender(Player *player1, Player *player2);

#endif





