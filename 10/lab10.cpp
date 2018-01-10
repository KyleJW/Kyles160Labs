/*
    Kyle J. Wilson
    545178782
    lab10.cpp
    
    This is a lab that uses pointers to allow the user to pick the size of an array
    and set the contents of said array
*/

#include <cstdio>

const int MinSize = 1;
const int MaxSize = 25000;

// Display the program intro
void welcome();

// get the user to select an array size (from 1..MaxSize),
//     allocate an array of that size,
//     record the size in the parameter,
// and return a pointer to the array
double* allocate(int &size);

// fill the given array with user-supplied values
void fill(double arr[], int size);

// display the current array contents, one element per line
void print(double arr[], int size);

int main() {
    int arrSize = 0;
    welcome();
    double *array = allocate(arrSize);
    fill(array, arrSize);
    print(array, arrSize);
    delete [] array;
    return 0;
}

void welcome() {
    printf("Welcome goes here!\n");
}

double* allocate(int &size) {
    double *arr = NULL;
    
    do {
        printf("Please enter your desired array size as an integer in the range %d..%d\n",
            MinSize, MaxSize);
        int valsRead = scanf("%d", &size);
        if(valsRead < 1) {
            printf("Error, you did not enter valid input. Please try again!\n\n");
            scanf("%*s");
        } else if ((size < MinSize) || (size > MaxSize)) {
            printf("Error, you did not enter a valid size. Please try again.\n\n");
        } else {
            // Try to allocate the array
            arr = new double[size];
            
            // It might fail, i.e. we're almost out of memory, in which case arr will be
            // NULL still
            if (arr == NULL) {
                printf("Sorry, we are unable to allocate an array of that size. ");
                printf("Please try again\n");
            } else {
                printf("\nArray allocation successful, initializing contents\n");
            }
        }
    } while (arr == NULL);
    
    return arr;
}

void fill(double arr[], int size) {
    int i = 0;
    do {
        printf("Please enter a value for element %d: ", i);
        int valsRead = scanf("%lf", &arr[i]);
        
        // Error checking if user entered garbage
        if (valsRead < 1) {
            scanf("%*s");
            printf("Input invalid! Please try again.\n");
        } else {
            // Only increment to the next element if user entered valid input
            i++;   
        }
    } while (i < size);
}

void print(double arr[], int size) {
    printf("\nInitializing complete, array contents are as follows:\n");
    for(int i = 0; i < size; i++) {
        printf("Array element %d: %lf\n", i, arr[i]);
    }
    // Inform the user that the array is being deallocated after contents have been
    // printed to the screen
    printf("\nDeallocating array\n");
}