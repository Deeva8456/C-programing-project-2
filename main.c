/**
 * @file main.c
 * @brief Text-menu driver for CE4703 Assignment 1.
  This program serves as a text-menu interface that allows users
 * to select and execute one of three menu functions (MF1–MF3) or
 * terminate the program. It uses a simple do while loop to repeatedly prompt
 * for user input until the user chooses to exit.
 */
#include <stdio.h>
#include <stdlib.h>
#include "menufunc.h"
#include "randomNum.h"

 /**
  * @brief Entry point showing text menu and calling MF1–MF3.
  *Initializes the random number generator and displays a text-based menu
 * that allows the user to choose from several options. Based on the user's
 * selection, corresponding menu functions are called.
 *
 * @return int Returns 0 upon successful program termination.
 */ 
  
int main(void) {
    randomNumInit();// initilze random number genertor
    int choice= 0;// variable to store user menu choice
    do {
        // Display menu options
        printf("\n=== MENU OPTIONS ===\n");
        printf("1. Perform MF1 \n");
        printf("2. Perform MF2 \n");
        printf("3. Perform MF3 \n");
        printf("4. Terminate\n");
        printf("Enter choice: ");
        /**
        * Read user input safely using scanf_s().
        * If invalid input is entered flush the input buffer
        * and reset choice to 0 to prevent unexpected behavior.
        */
        if (scanf_s("%d", &choice) != 1) {
            while (getchar() != '\n');// flush input buffer
            choice = 0;
        }
        // handles user choices using a switch statment
        switch (choice) {
        case 1:MF1();//calls menu function1 , prints MF1
            break;
        case 2:MF2();// calls menu function2 prints MF2
            break;
        case 3:MF3();//calls menu function3  prints MF3
            break;
        case 4:printf("Exiting...\n");// exits  the program
            break;
        default:printf("Invalid choice please enter 1-4.\n");// handles invalid input
			break;                                                          
        }
	} while (choice != 4);// continues until user chooses to exit
	return 0;// returns 0 upon successful termination
}
