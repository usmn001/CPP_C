/*
 ============================================================================
 Name        : Double_Pointers.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


void allocateMemory(int *ptr){
ptr = (int*)malloc(sizeof(int));
printf("In allocate memory func : %i\n",*ptr);
}



int main(void) {
clock_t start,end;
uint16_t b=0xFFFF;
b = ~( b ^ ( b<<4 ) );


// Challenge 1:
start = clock();
int var = 55;



//int *ptr1 = &var,**ptr2 = &ptr1; In this way at the time of defining pointers we can also assign addresses using * with pointers ,
                                  //& symbol with addresses we want to store.

int *ptr1 = NULL,**ptr2 = NULL;   // In 2nd way we do it later on in preceeding program statements without using *notation.

ptr1 = &var;
ptr2 = &ptr1;

//printf("Address of ptr1 %p,pointed val = %i , ptr2 %p,pointed address = %p,val stored : %i \n ",ptr1,*ptr1,ptr2,*ptr2,**ptr2);

// Challenge 2:
allocateMemory(ptr1);
*ptr1 = 6;
printf("%i\n",*ptr1);
free(ptr1);
end = clock();
double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds
printf("fun() took %lf seconds to execute \n", time_taken);
for (uint8_t i=0;i >=0;)
{
++i;
}
printf("%ld\n", __STDC_VERSION__);
printf(b);
return 0;


}
