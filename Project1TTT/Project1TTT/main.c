//
//  main.c
//  Project1TTT
//
//  Created by Chris Grant on 1/21/15.
//  Copyright (c) 2015 Chris Grant. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int gameLoop() {
    int high = 2;
    int low = 0;
    int value;
    int playerScore = 0;
    int cpuScore = 0;
    char playerInput;
    /*
        0=Rock
        2=Paper
        1=Scissors
     */

    while (playerScore != 3 && cpuScore != 3) {
        value = rand() % (high - low + 1) + low;
        printf("What is your choice: ");
        do {
            scanf("%c", &playerInput);
        } while (playerInput != '\n');//Flushes the scanf buffer in the most ghetto way
        scanf("%c", &playerInput);

        //printf("\n%d\n",playerInput);
        if (playerInput == 's' || playerInput == 'S') {
            printf("\nYou chose Scissors!\n");
            playerInput = 1;
        }
        else if (playerInput == 'r' || playerInput == 'R') {
            printf("\nYou chose Rock!\n");
            playerInput = 0;
        }
        else if (playerInput == 'p' || playerInput == 'P') {
            printf("\nYou chose Paper!\n");
            playerInput = 2;
        }
        if (value == 0) {
            printf("The computer chose Rock\n");
        }
        else if (value == 1) {
            printf("The computer chose Scissors \n");
        }
        else if (value == 2) {
            printf("The computer chose Paper\n");
        }
        if (playerInput == value) {
            printf("It is a Tie, no points!\n");
        }
        else if (value == 0) {
            if (playerInput == 1) {
                printf("Rock Crushes Scissors! You lose \n");
                cpuScore++;
            }
            else if (playerInput == 2) {
                printf("Paper covers Rock! You win \n");
                playerScore++;
            }
        }
        else if (value == 1) {
            if (playerInput == 0) {
                printf("Rock Crushes Scissors! You Win \n");
                playerScore++;
            }
            else if (playerInput == 2) {
                printf("Scicors cuts Paper! You lose \n");
                cpuScore++;
            }
        }
        else if (value == 2) {
            if (playerInput == 0) {
                printf("Paper covers Rock! You lose \n");
                cpuScore++;
            }
            else if (playerInput == 1) {
                printf("Scicors cuts Paper! You Win \n");
                playerScore++;
            }
        }
        printf("The Score is now: You: %d Computer: %d\n", playerScore, cpuScore);
    }
    if (playerScore == 3) {
        return 0;
    }
    else
        return 1;
}
int main() {
    // insert code here...
    char input;

    int winner;
    printf("Welcome to Rock Paper Scissors!\n");
    printf("Would you like to play a best of 5 game?");
    scanf("%c",&input);
    //printf("\n%d\n",input);
    if(input == 121 || input==89 )//Lowercase or Uppercase y
    {
        //printf("Ok We are playing");
        winner=gameLoop();
        if(winner ==0)
        {
            printf("You Win!\n");
        }
        else{
            printf("The Computer Wins!\n");
        }

    }
    else{
        printf("Then why did you run it!\n");
    }
    return 0;
}