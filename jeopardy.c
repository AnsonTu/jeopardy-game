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
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " ");
};

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    // Sort results in descending order
    for (int i = 0; i < num_players-1; i++) {
        int tempIdx = i;
        for (int j = i+1; j < num_players; j++) {
            if (players[tempIdx].score < players[j].score) {
                tempIdx = j;
            }
        }
        player tempValue = players[tempIdx];
        players[tempIdx] = players[i];
        players[i] = tempValue;
    }
    printf("FINAL RESULTS:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d: %s %d\n", i+1, players[i].name, players[i].score);
    }
};


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name: ");
        scanf("%s", buffer);

        if (player_exists(players, NUM_PLAYERS, buffer)){
            printf("Name already taken, changing name to %s\n", strcat(buffer, "1"));
        }
        strcpy(players[i].name, buffer);
    }
    
    // initialize each of the players in the array
    printf("List of Players:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].score = 0;
        printf("%s\n", players[i].name);
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered
        int numOfAnsweredQuestions = 0;
        while (numOfAnsweredQuestions < 12) {
            display_categories();
            char name[BUFFER_LEN] = { 0 };
            char category[BUFFER_LEN] = { 0 };
            char answer[BUFFER_LEN] = { 0 };
            int dollars = 0;

            printf("Enter player's name: ");
            scanf("%s", name);
            if (player_exists(players, NUM_PLAYERS, name)) {
                printf("Enter a category (programming, algorithms, databases): ");
                scanf("%s", category);
                printf("Enter a dollar value (200, 400, 600, 800): ");
                scanf("%d", &dollars);
                if (!already_answered(category, dollars)) {
                    display_question(category, dollars);
                    printf("Your answer?: ");
                    scanf("%s", answer);
                    if (valid_answer(category, dollars, answer)) {
                        printf("Correct! %s gets %d points!\n", name, dollars);
                        update_score(players, NUM_PLAYERS, name, dollars);
                    }
                    numOfAnsweredQuestions++;
                }
            } else {
                printf("Player not found.\n");
            }
        }

        // Display the final results and exit
        show_results(players, NUM_PLAYERS);
        break;
    }
    return EXIT_SUCCESS;
}
