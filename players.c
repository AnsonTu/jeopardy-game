/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Anson Tu (100655482), Kaushik Ramani (100651855), Cristina Chung (100711128)>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

//Array of players **We probably will have to move this to jeopardy.c
struct player players[4];

// Number of players
int num_players = 4;

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{   
    for(int i = 0; i < num_players; i++){
        if(players[i].name == name){
            return true;
        }
    }
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{
    for(int i = 0; i < num_players; i++){
        if(players[i].name == name){
            players[i].score = players[i].score + score;
        }
}