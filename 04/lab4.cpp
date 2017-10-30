// Kyle J. Wilson
// 545178782
// This is a program thaty asks for a number between 1 and 10.
// There is basic error checking and looping via recurssion.

#include <cstdio>

const double minVal = 1;
const double maxVal = 10;

float getInRange(float minVal, float maxVal);

int main()
{
   // Get the user to provide a value in the range 1...10,
   // using the getInRange function
   printf("In this program you will simply be asked to enter a number in the range %g..%g.\n", minVal, maxVal);
   printf("if you supply an invalid value the program will tell you what you have done wrong,\n");
   printf("   and ask you to try again.\n");
   printf("This cycle will continue until you provide a valid response.\n");

   // Use the recursive function to get a valid value
   // then display it
   float value = getInRange(minVal, maxVal);
   printf("Thank you for providing value %g\n", value);

   // End the program
   return 0;
}

float getInRange(float minVal, float maxVal) 
{
   int valsRead; // the number of values successfully read during a scanf
   float userVal = 0; // The value supplied by the user

   printf("Please enter a number in the range %g to %g\n", minVal, maxVal);
   valsRead = scanf("%g", &userVal);  

   if(valsRead == 1) {
      if(userVal < 1) {
         printf("Error: the value %g is too small, please try again\n", userVal);
         userVal = getInRange(minVal, maxVal);
      } else if(userVal > 10) {
         printf("Error: the value %g is too large, please try again\n", userVal);
         userVal = getInRange(minVal, maxVal);
      } 
   } else {
      scanf("%*s");
      printf("That was not a valid number, please try again\n");
      userVal = getInRange(minVal, maxVal);
   }

   return userVal;
}
