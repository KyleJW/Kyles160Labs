/*
   Kyle J. Wilson
   545178782
   Lab5.cpp
   
   This lab is designed to print out a square in the dimentions provided
   by the user.
   
*/

#include <cstdio>

// Welcome prototype
void welcome();

// Prototype for getting the information from the user.
int getUserValue();

// Prototype for printing the box
void printBox(int boxDimension);

int main() {
   int boxDimension;
   
   // Welcome the user to the program and provide instruction   
   welcome();
   
   // Get the the boxDimension - Error checking
   boxDimension = getUserValue();

   // Print the box using the dimension the user supplied
   printBox(boxDimension);   

   // Tell the user the program is finished running
   printf("done!\n");

   // End program
   return 0;
}

// Welcome the user to the program and print instructions 
void welcome() {
   printf("Welcome to the box drawing program!\n");
   printf("\n This program will draw a square box on the screen,\n");
   printf("allowing you to select the box size.\n\n");
}

// Function used for getting the value from the user
int getUserValue() {
   // Create local variables
   int userValue, scanCheck;

   // Ask the user to input a number
   printf("Please enter the box size as an integer 3..15 (inclusive).\n");

   // Read the users input and check validity
   scanCheck = scanf("%d", &userValue);
   
   // If the user enters an invalid character into the program, inform them of this
   // and have them try again.
   if(scanCheck == 0) {
      printf("Sorry, that was not an integer value, please try again.\n");
      scanf("%*s"); // Clear out the garbage the user entered
      // Call function again      
      userValue = getUserValue();
   }
   
   // If the user supplies the program with an integer that is not within the valid
   // range, ask them to try again.
   if((userValue < 3) || (userValue > 15)) {
      printf("Sorry, %d is not in the range 3..15, please try again\n", userValue);
      // Call function again
      userValue = getUserValue();
   }

   // Return the user value
   return userValue;
}

// Print out the box using the users input
void printBox(int boxDimension) {
   // Nested for loop used for creating row and columns
   for (int boxRow = 1; boxRow <= boxDimension; boxRow++) {
      for (int boxColumn = 1; boxColumn <= boxDimension; boxColumn++) {
         printf("*");
      }
      // Adds new line at the end of the Row
      printf("\n");
   }
}


