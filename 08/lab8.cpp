/*
   Kyle Wilson
   545178782
   
   Lab8.cpp
   
   In this lab a program is created that will take all of the characters
   from one file and copy them into another.
*/

#include <cstdio>

// copy the contents of the source file into the destination file,
//    one character at a time
// generates error message and returns false if it is unable to open
//    either of the files, 
// otherwise performs the copy and returns true
bool copyFileByChars(const char srcfile[], const char destfile[]);

// takes two command line arguments, 
//    the name of the file to be copied,
// and the name to use for the copy
// e.g.   ./lab8x  originalFile  copiedVersion
int main(int argc, char *argv[])
{
   
   // if they don't give both filenames,
   //    tell them how to run the program correctly
   if (argc != 3)  {
      printf("correct use is\n   %s infile outfile\n", argv[0]);
   } else if (copyFileByChars(argv[1], argv[2])) {
      printf("Copied %s to %s\n", argv[1], argv[2]);
   } else {
      printf("Unable to perform copy operation\n");
   }
   
   // end the program
   return 0;
}

// copy the contents of the source file into the destination file,
//    one character at a time
// generates error message and returns false if it is unable to open
//    either of the files, 
// otherwise performs the copy and returns true
bool copyFileByChars(const char srcfile[], const char destfile[])
{
   // Setup file pointers
   FILE* fpin;
   FILE* fpout;
   
   fpin = fopen(srcfile, "r");
   
   // Error checking for file read
   if (fpin == NULL) {
      printf("Error! File not found.\n");
      return false;
   }
   
   fpout = fopen(destfile, "w"); // w sets us up for writing
   
   // Error checking for file write
   if (fpout == NULL) {
      printf("Error! Cannot write file.\n");
      return false;
   }
   
   // Reading and writing goes here
   char currCh;
   do {
      currCh = getc(fpin); // Read char from fpin, put in currCh
      if (!feof(fpin)) {
         fprintf(fpout, "%c", currCh); // Write currCh into fpout
      }
   } while(!feof(fpin));
   
   // Close both of the files
   fclose(fpin);
   fclose(fpout);
   
   // Everything went as expected, return true
   return true;
}