/*
   Author: Kyle J. Wilson
 
   In this program I'm learning about 
   null-terminated character arrays in cpp 
*/

#include <cstdio>
#include <cctype> 
#include <cstdlib> 
#include <cstring>

// Declare constants 
const int Size = 64; 

// Display the welcome message 
void welcome(); 

// Convert a null-terminated text string to uppercase 
void convertToUpper(char str[]); 

// Convert a null-terminated text string to lowercase 
void convertToLower(char str[]); 

// Display final output
void displayOutput(char upper[], char lower[]);

int main(int argc, char *argv[]) {

   char upperCopy[Size];
   char lowerCopy[Size];

   // Welcome the user to program
   welcome();

   // Test to see if user entered less than or more than 3 arguments
   if ((argc < 3) || (argc > 3)) {
      // Error checking here
      printf("An incorrect number of command line arguments were provided: ");
      printf("exactly two words are expected.\n");
   } else {
      // Success here
      // Set the uppercase variable text
      strncpy(upperCopy, argv[1], Size);
      
      // Set the lowercase variable text
      strncpy(lowerCopy, argv[2], Size);
      
      // Provide the user with their original input
      printf("Your original arguments were\n");
      printf("\"%s %s\"\n", upperCopy, lowerCopy);
      
      // Do the conversions
      convertToUpper(upperCopy);
      convertToLower(lowerCopy);

      // Display output
      displayOutput(upperCopy, lowerCopy);
   }

   // End program loop
   return 0;
}

// Welcome the user to the program 
void welcome() {
   printf("Welcome to the word converter!\n\n");
   printf("This program accepts two command line arguments,\n");
   printf("converting the first to uppercase and the second to lowercase. \n\n");
}

// Convert the user input to uppercase characters 
void convertToUpper(char str[]) {
   // This is for traveling the while-loop -- in scope
   int pos = 0;
   
   // Initialize array to NULL
   char tempArr[Size] = { '\0' };

   // Add the contents on str[] into temp variable for ease of use
   strncpy(tempArr, str, Size);
   
   // Set the size of array for search purposes
   int arrSize = strlen(tempArr);

   // Loop through the temp array and set the characters to uppercase
   while(tempArr[pos] != '\0') {
      tempArr[pos] = toupper(tempArr[pos]);
      pos++;
   }
   
   // Copy contents of temp (uppercase) back to original
   strncpy(str, tempArr, arrSize);
   
}
// Convert the second string to all lowercase char 
void convertToLower(char str[]) {
   // This is for traveling the while-loop -- in scope
   int pos = 0;
   
   // Initialize temp array to NULL
   char tempArr[Size] = { '\0' };
   
   // Add the contents on str[] into temp variable for ease of use
   strncpy(tempArr, str, Size);
      
   // Set the size of array for search purposes
   int arrSize = strlen(tempArr);

   // Loop through the temp array and set the characters to lowercase
   while(tempArr[pos] != '\0') {
      tempArr[pos] = tolower(tempArr[pos]);
      pos++;
   }
      
   // Copy the temp (lowercase) contents back to the original string
   strncpy(str, tempArr, arrSize);
}

// Display output to user
void displayOutput(char upper[], char lower[]) {
   printf("and the converted arguments are\n");
   printf("\"%s %s\"\n", upper, lower);
}