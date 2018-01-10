/*

   Kyle J. Wilson
   545178782
   Lab9.cpp

   This is a program that reads information from the user 
   and inserts it into a struct and reads it back to them.

 */

#include <cstdio>

// Minimum/Maximum number of tags supported
const long MinTags = 1;
const long MaxTags = 20;
const long MinID = 1000;
const long MaxID = 9999;
const long MinPhoneNumber = 1000000000;
const long MaxPhoneNumber = 9999999999;
const long MinYear = 1900;
const long MaxYear = 2100;

// Dogtag definition
struct dogtag {
   long id;
   long phone;
   long year;
};

// Welcomes the user to the program and give a brief explaination
void welcome(); 

// Get the user to provide the id, phone, and year for the tag
void tagEntry(dogtag &d);

// Asks the user to provide a valid number of tags
long getLong(const char* text, long minTags, long maxTags);

// Fill an array of dogtags
void fillTags(dogtag tags[], long size);

// Show the tags
void showTags(dogtag tags[], long size);

int main() {
   
   long numTags;
   // An array of dog tags large enough to support the maximum number of tags
   dogtag Tags[MaxTags];
   
   welcome();
   
   // Let the user select how many tags will be processed
   numTags = getLong("Please specify the number of tags you intend to store (1-20): ", 
      MinTags, MaxTags);
      
   // Obtain the data for for the dog tags
   fillTags(Tags, numTags);
   
   // Display the data for the dog tags
   showTags(Tags, numTags);
   
   // End program
   return 0;
}

// Welcomes the user to the program and give a brief explaination
void welcome() {
   printf("Wlcome to TagRecorder\n\n");
   printf("This program allows you to enter data for a collection of\n");
   printf("dog tags, providing an id, phone number, and year for each.\n\n");
}

// Get the user to provide the id, phone, and year for the tag
void tagEntry(dogtag &d) {

   /* Add id to tag */
   bool bIDOkay = false; // Used for do-while-loop
   do {
      printf("Please enter a positive integer id for the tag (%ld-%ld): ", MinID, MaxID);
      
      int scanCheck = scanf("%ld", &d.id);
      
      // Check if input was valid and within range
      if((d.id >= MinID) && (d.id <= MaxID) && (scanCheck > 0)) {
         bIDOkay = true; // No errors
      } else if (scanCheck <= 0) { // Clean garbage
         scanf("%*s");
      }
   } while(!bIDOkay);
   
   /* Add phone number to tag */
   bool bPhoneOkay = false; // Used for do-while-loop
   do {
      printf("Enter the phone number, digits only (%ld-%ld): ", MinPhoneNumber, 
      MaxPhoneNumber);

      int scanCheck = scanf("%ld", &d.phone);
      
      // Check if input was valid and within range
      if((d.phone >= MinPhoneNumber) && (d.phone <= MaxPhoneNumber) && (scanCheck > 0)) {
         bPhoneOkay = true; // No errors
      } else if (scanCheck <= 0) { // Clean garbage
         scanf("%*s");
      }
   } while(!bPhoneOkay);
   
   /* Add year to tag */
   bool bYearOkay = false; // Used for do-while-loop
   do {
      printf("Enter the year as an integer (%ld-%ld): ", MinYear, MaxYear);

      int scanCheck = scanf("%ld", &d.year);
      
      // Check if input was valid and within range
      if((d.year >= MinYear) && (d.year <= MaxYear) && (scanCheck > 0)) {
         bYearOkay = true; // No errors
      } else if (scanCheck <= 0) { // Clean garbage
         scanf("%*s");
      }
   } while(!bYearOkay);
   
}

// Asks the user to provide a valid number of tags
long getLong(const char* text, long minTags, long maxTags) {
   long numTags;
   
   printf("%s ", text);
   
   int scanCheck = scanf("%ld", &numTags);
   
   // Remove garbage and ask user to try again
   if ((scanCheck <= 0)) {
      scanf("%*s");
      numTags = getLong("Please enter a valid double. ", 
         MinTags, MaxTags);
   }

   // Check to see if the user entered more or less than the required tags
   if ((numTags < minTags) || (numTags > maxTags)) {
      numTags = getLong("Please specify the number of tags you intend to store (1-20): ", 
         MinTags, MaxTags);
   }
   
   return numTags;
}

// Fill an array of dogtags
void fillTags(dogtag tags[], long size) {
   // Setup tag variable for counting
   int tag = 0;
   
   do {
      printf("\nProcessing tag %d\n", tag+1); // Add one to make human readable
      tagEntry(tags[tag]);
      
      // Increment tag up 1
      tag++;
   } while (tag < size);
}

// Show the tags
void showTags(dogtag tags[], long size) {
   printf("\nThe supplied tag information is:\n");
   for(int i = 0; i < size; i++) {
      printf("ID %ld, ", tags[i].id);
      printf("Phone %ld, ", tags[i].phone);
      printf("Year %ld\n", tags[i].year);
   }
}