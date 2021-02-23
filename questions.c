/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2021, <Kaushik Ramani(100651855), Anson Tu(100655482), Cristina Chung(100711128)
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    //programming category
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "This is the original branch for a git repo");
    strcpy(questions[0].answer, "master");
    questions[0].value=200;
    questions[0].answered=false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "In programming these symbols are standing by to represent actions; in C++ some are = * ++");
    strcpy(questions[1].answer, "operators");
    questions[1].value=400;
    questions[1].answered=false;

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "It's the basic unit of information in quantum computers");
    strcpy(questions[2].answer, "qubit");
    questions[2].value=600;
    questions[2].answered=false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "Data type that would be used to display the digits of pie");
    strcpy(questions[3].answer, "double");
    questions[3].value=800;
    questions[3].answered=false;

    //algorithms category
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "Searching in this tree has the worst case complexity of O(n)");
    strcpy(questions[4].answer, "binary search tree");
    questions[4].value=200;
    questions[4].answered=false;

    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "is the worst-case performance of MergeSort");
    strcpy(questions[5].answer, "O(n log n)");
    questions[5].value=400;
    questions[5].answered=false;

    strcpy(questions[6].category, "algorithms");
    strcpy(questions[6].question, "Also known as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.");
    strcpy(questions[6].answer, "bubble sort");
    questions[6].value=600;
    questions[6].answered=false;

    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "Developed by British computer scientist Tony Hoare in 1959 and published in 1961,  it can be somewhat faster than merge sort and about two or three times faster than heapsort");
    strcpy(questions[7].answer, "quick sort");
    questions[7].value=800;
    questions[7].answered=false;

    //databases category
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "Is a source-available cross-platform document-oriented database program. Classified as a NoSQL database program, it uses JSON-like documents with optional schemas.");
    strcpy(questions[8].answer, "mongodb");
    questions[8].value=200;
    questions[8].answered=false;

    strcpy(questions[9].category, "databases");
    strcpy(questions[9].question, "Developed at the University of California, Berkeley. it is known as The World's Most Advanced Open Source Relational Database");
    strcpy(questions[9].answer, "postgresql");
    questions[9].value=400;
    questions[9].answered=false;

    strcpy(questions[10].category, "databases");
    strcpy(questions[10].question, "A domain-specific language used in programming and designed for managing data held in a relational database management system");
    strcpy(questions[10].answer, "SQL");
    questions[10].value=600;
    questions[10].answered=false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "Is an SQL statement used to extract data from a database");
    strcpy(questions[11].answer, "select");
    questions[11].value=800;
    questions[11].answered=false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    int width = 20;
    for (int i = 0; i < 3; ++i) {
		putchar('+');
		for (int j = 0; j < width; ++j)
			putchar('-');
	}
	printf("+\n");

    for(int i = 0; i < 12; i++) {
		if(questions[i].answered == false) {
			printf("| $&-*d", width - 2, questions[i].value);
		} else {
			printf("| %-*s", width - 2, " - ");
		}

		if(i % 3 == 2)
			printf("|\n");
	}

	for(int i = 0; i < 3; i++) 
		printf("| %-*s", width - 1, categories[i]);
	printf("|\n");

	for (int i = 0; i < 3; ++i) {
		putchar('+');
		for (int j = 0; j < width; ++j)
			putchar('-');
	}

	for (int i = 0; i < 3; ++i) {
		putchar('+');
		for (int j = 0; j < width; ++j)
			putchar('-');
	}
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			printf("Question: %s (%d)\n", questions[i].question, questions[i].value);
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    bool is_valid;

	for (int i = 0; i < 12; i++) {
		if ((questions[i].category == category) && (questions[i].value == value)) {
			if (strcmp(questions[i].answer, answer) == 0) {

				is_valid = true;
			
			} else {
				
				is_valid = false;
			}
		}
	}

	return is_valid;

}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for(int i = 0; i < 12; i++)
		if (questions[i].value == value && strcmp(questions[i].category, category) == 0)
			return questions[i].answered;

    // lookup the question and see if it's already been marked as answered
    return true;
}
