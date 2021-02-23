/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "players.c"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player *players[NUM_PLAYERS];
    

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char name [256];

    for(int i = 0; i < NUM_PLAYERS; i++){
        printf("Enter name: ");
        scanf("%s", name);

        players[i] = malloc(sizeof(player));

        if (player_exists(players, NUM_PLAYERS, name)){
            printf("This player already exist, please enter another name. \n");
        }
         
      players[i]->name = name;
        
    }
    
    printf("START");

    // Display the game introduction and initialize the questions
   // initialize_game();

    // Prompt for players names
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
