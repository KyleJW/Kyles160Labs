#include <cstdio>

// Display welcome message
void welcome();

// Test the user input and return either true or false
bool getTwoInts(int &numerator, int &demoninator);

// Print input and do math to display remainders
void printDivision(int numerator, int demoninator);

int main()
{
   // Create the variables
   int numerator, denominator;
   bool testInts = false;
   welcome();
   // Variable tests if the information user entered was valid
   testInts = getTwoInts(numerator, denominator);
   // If the getTwoInts test does not equal true it has failed
   // and the correct error message will be printed to the user
   if (!testInts)
   {
      printf("Sorry, you did not enter two integers.\n");
   }
   // If the test passes the division will be printed to the user
   else
   {
      printDivision(numerator, denominator);
   }
   // End program
   return 0;
}
// Display welcome message
void welcome()
{
   printf("Welcome to the division program\n\n");
   printf("This program allows you to enter two integers,\n");
   printf("\tdetermines how many times the second integer goes into the first,\n");
   printf("\tand how much is left afterwards.\n");
}

// Test user input and return either true or false
bool getTwoInts(int &numerator, int &denominator)
{
   // Create local variables for testing if integers were used
   // 1 is true
   // 0 is false
   int scanCount1, scanCount2;
   printf("\nPlease enter the numerator and denominator as integers\n");
   scanCount1 = scanf("%d", &numerator);
   scanCount2 = scanf("%d", &denominator);
   // Check if BOTH the scanCounts return 1
   // if they do the user has entered valid information
   if ((scanCount1 == 1) & (scanCount2 == 1))
   {
   return true;
   }
   // All other combinations are incorrect and therefore
   // will always return false
   else
   {
      return false;
   }
}

// print input and do math to display remainders
void printDivision(int numerator, int denominator)
{
   // Check to see if the denominator is 0
   // if it is print error
   if (denominator == 0)
   {
      printf("Cannot divide by 0.\n");
   }
   else
   {
      // Math for remainder using local variables
      int intoTimes  = numerator / denominator;
      int remainder = numerator % denominator;

      printf("%d goes into %d a total of %d times, with a remainder of %d.\n", denominator, numerator, intoTimes, remainder);
   }
}
