/*

   Kyle J. Wilson
   545178782
   Lab02
   This program uses functions to calculate the cost of the users trip.

*/

#include <cstdio>

// Constants for use in program are set here, above the rest of the code
const float CostPerDay = 9.99;
const float CostPerKm = 0.12;

// Prototype for displaying the welcome message
void welcome();

// Prototype for prompting the user to enter a number of days
// read and return their response (no error checking currently performed)
int getNumDays();

// Prototype for prompting the user to enter the number of KMs they traveled
// Again, no error checking is performed
float getNumKms();

// Prototype for calculate the final price by adding the Cost per day and KMs travelled. 
float calculatePrice(int days, float kms);

// Prototype for displaying the results and stored input back to the user
void displaySummary(int days, float kms, float price);

// Main program function
int main()
{
   // Declare variable for number of days
   int days;
   // Decalre variable for kms and price
   float kms, price;

   // Display the welcome/intro message
   welcome();

   // Get and store the number of days
   days = getNumDays();

   // Get and store the number of kilometres
   kms = getNumKms();

   // Calculate and store the price
   price = calculatePrice(days, kms);

   // Display the results
   displaySummary(days, kms, price);

   // End the program
   return 0;
}

// Display welcome message
void welcome()
{
   printf("welcome to the car rental pricer.\n\n");
   printf("You will be prompted to enter the number of days the car was rented,\n");
   printf("an the number of kilometres driven, and the price will then be calculated\n");
   printf("based on $%.2f per day plus $%.2f per kilometre.\n", CostPerDay, CostPerKm);
}

// Prompt the user to enter a number of days,
// read and return their response
// (no error checking currently performed)
int getNumDays()
{
   // Local variable to store what the user enters for days
   int numDays;
   printf("\nPlease enter the number of days the car was rented (e.g. 3): ");
   scanf("%d", &numDays);
   return numDays;
}

// This function will prompt the user to enter 
// the number of KMs they traveled
// Again, no error checking is performed
float getNumKms()
{
   // Local variable to store what the user enters for kms
   float numKms;
   printf("\nPlease enter the number of kilometres driven (e.g. 172.4): ");
   scanf("%f", &numKms);
   return numKms;
}

// This function uses the input from the user to calculate the price
// by adding the Cost per day and KMs travelled. 
float calculatePrice(int days, float kms)
{
   // local variable for price so it can be returned
   float finalPrice;
   // Calculate the price
   finalPrice = (CostPerDay * days) + (CostPerKm * kms);
   return finalPrice;
}

// Display the result and input back to the user
void displaySummary(int days, float kms, float price)
{
   printf("\nThe final price for %d days and %g kilometres is $%.2f.\n", days, kms, price);
}
