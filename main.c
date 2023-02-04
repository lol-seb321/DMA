#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Student {
  char name[20];
  int score;
};

int main(void) {

  /*
    pointer of type int that holds dynamically allocated memory of type int of 40 bytes 
  (4 bytes(int) * 10)
  */ 
  int *ptr1 = (int*) malloc(10*sizeof(int)); 
  /* we are casting (i.e., (int*)) because malloc ALWAYS returns a void pointer, which is a pointer       that can point to any type of data 
   
  Therefore, the void pointer must be cast to the type of data it is pointing to, in this case an         integer pointer.
   
  Keep in mind that malloc always returns a void pointer, which is a pointer that can point to any        type of data. */
  
  int *ptr2;
  // This is a declaration of an int pointer a pointer that can store an address of type int

  int i;
  if(ptr1 == NULL)
  {
    printf("Could not allocate memory\n");
    exit(-1);
    // Exit(-1) is a function in C that causes the program to terminate with an error code of -1. It is     typically used to indicate that an error has occurred and the program cannot continue.
  }
  else
  {
    printf("Memory allocated. Printing data after malloc: \n");
  }

  // This loops through the allocated memory of ptr1 and prints the values
  // The memory is not initialized, so the values in the allocated memory are whatever values were        already in memory before it was allocated. Which are random numbers 
  for(i = 0; i < 10; i++)
    {
         printf("%d ", ptr1[i]);
    }
 
  printf("\n");
  // Here ptr2 is already allocated as a pointer that can hold an int address
  // this is how we use the calloc function to initalize 40 bytes (4 bytes(int) * 10)
  ptr2 = (int*) calloc(10, sizeof(int));
  if(ptr2 == NULL){
    printf("Could not allocate memory\n");
    exit(-1);
  }
  else
  {
    printf("Memory allocated. Printing data after calloc: \n");
    for(i = 0; i < 10; i++)
    {
      printf("%d ", ptr2[i]);
      // it will print 0 for all elements as calloc initializes the allocated memory to zero.
    }
  }
  
  printf("\n");

  int n;
  // How to allocate and create an array of N students
  struct Student *students;
  struct Student *s = (struct Student*) malloc(n*sizeof(struct Student));

  /* Example of memory leak:

  int* readArray(int size){
  int *p1 = (int *) malloc(size*sizeof(int));
  int *p2 = (int *) malloc(size*sizeof(int));
  for(int i = 0; i < size; i++){
  scanf("%d", &p1[i]);
  }

  // When this line gets executed p2 now points to the same allocated array for p1 so we lose the array   p2 was originally pointing to

  p2 = p1;
  return 
  }
  */

  // How to increase size of array using realloc
  ptr1 = (int*)realloc(ptr1, 20*sizeof(int));
  printf("Memory reallocated. Printing data after realloc:\n");
  for(i = 0; i < 20; i++)
    printf("%d ", ptr1[i]);
  printf("\n");

  // Filling the array with random numbers using user input
  srand(time(0));
  int nums;
  printf("How many random numbers?");
  scanf("%d", &nums);
  ptr2 = (int*)realloc(ptr2, nums*sizeof(int));
  for(i = 0; i < nums; i++)
    ptr2[i] = rand()%100;
  for(i = 0; i < nums; i++)
    printf("%d ", ptr2[i]);
  
  free(ptr1);
  free(ptr2);
}