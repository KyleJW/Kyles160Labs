/*
   Author: Kyle J. Wilson
   Lab6
   This program asks the user to enter a valid integer and it rotates 
   that integer and prints it out
   
*/

#include <cstdio>

// min/max supported array sizes for rotation
const int MinSize = 1;
const int MaxSize = 20;

// Welcomes user to program
void welcome();

// Asks user to pick the array size
int pickSize(int min, int max);

// Adds the integers into the array
void initialize(int arr[], int size);

// Prints out the contents of the array
void display(int arr[], int size);

// Performs the rotation of the array
void rotate(int arr[], int size); 

int main()
{
   // array to be rotated
   int dataArray[MaxSize];

   // introduce the program to the user
   welcome();

   // let the user pick how much of the array will be used
   int sizeUsed = pickSize(MinSize, MaxSize);

   // initialize the contents in use
   initialize(dataArray, sizeUsed);

   // Space between input and displayed data
   //printf("\n");
   
   // display the initial content
   display(dataArray, sizeUsed);

   // repeatedly rotate and display the contents
   // until we are back to the original layout
   for (int i = 0; i < sizeUsed; i++) {
       rotate(dataArray, sizeUsed);
       display(dataArray, sizeUsed);
   }

   // end the program
   return 0;
}

// Welcome the user to the program
void welcome() {
   printf("Welcome to the array rotation program\n\n");
   printf("This program will initialize an array and then repeatedly rotate ");
   printf("its contents \n\n");
}

// As the user to pick a size of the array
int pickSize(int min, int max) { 

   int size, scanCheck; 

   // Loop through this until the user enters valid input
   do {

      printf("Please select an array in the range of %d...%d\n", min, max);
      scanCheck = scanf("%d", &size);
      
      // Check to see if  player entered valid user input
      if (scanCheck == 0) {
         // Clean up garbage
         scanf("%*s");
      }

   // Continue to loop through while size variable is out of bounds
   } while((size < min) || (size > max));

   // Everything went as expected so return user input
   return size;
}

// Display the array
void display(int arr[], int size) {
   // Space between input and displayed value
   
   for (int i = 0; i < size; i++) {
      printf("%d", arr[i]);
      // Add comma to each number array but the last row
      if (i != size-1) {
         printf(", ");
      }
   }
   // Adds the new line
   printf("\n");
}

// Fill the array using the size the user entered
void initialize(int arr[], int size)
{
   for (int i = 0; i < size; i++) {
       arr[i] = i;
   }
}

// Rotate the array left by 1
void rotate(int arr[], int size) {
   int rotated, i;   
   // Set rotated variable to first array
   rotated = arr[0];
   // Go through array and swap by adding one
   for (i = 0; i < size-1; i++) {
      arr[i] = arr[i+1];
   }
   // Set rotated to the last point in array
   arr[size-1] = rotated;
}
