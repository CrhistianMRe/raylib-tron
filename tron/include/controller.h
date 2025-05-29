#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "../include/player.h"
#include "../include/raylib.h"



void savePlayerPos(Player *player);
//call savePlayerPos in each movement 
void movePlayerPos(Player *player);
void restartPlayer();
//load 
void initStage();

void initController(Texture2D texture); 



