#ifndef _COLLISION_H
#define _COLLISION_H

#include "../include/raylib.h"
#include "../include/player.h"

void checkBorders(Player *player);
//Checks if a player triangle hits another player triangle
void checkTriangles(Player *player1, Player *player2);
//Check self and collision against other player
void checkTrailCollision(Player *player1, Player *player2);
//Main collision method
void initCheckCollision(Player *player1, Player *player2);

#endif // !_COLLISION_H
