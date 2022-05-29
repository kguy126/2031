/***********************************
* EECS 2031 - Lab 5		   
* Filename: lab5.c	  	
* Author: Adesanya, Kamal	    
* Email: kamal124@my.yorku.ca	 	
* Login ID: kamal124	
************************************/


#include <stdio.h>
#include <stdlib.h>

/* Definition of structure extendableArray */

struct extendableArray {
   int *arr;	/* array of integers */
   int size;	/* number of elements currently stored in the array */
   int capacity;/* capacity of the currently allocated array */
};



/* Initializes the extendable array */

struct extendableArray *initArr()
{
   struct extendableArray *a = ( struct extendableArray * ) malloc( sizeof( struct extendableArray ) );
   if( !a ) {
	printf( "Insufficient memory!" );
	exit( 1 );
   }
   a->capacity = 4;		/* initial capacity */
   a->arr = ( int * ) malloc( a->capacity * sizeof( int ));
   if( !a->arr ) {
	printf( "Insufficient memory!" );
	exit( 1) ;
   }
   a->size = 0;			/* no element added to the array yet */
   return a;
}



/* Returns the size of the array */

int arrSize( struct extendableArray *a ) 
{
	return( a->size );
}



/* Returns the capacity of the array. */

int arrCapacity( struct extendableArray *a ) 
{
	return( a->capacity );
}



/* Returns true (1) if the array is empty, and false (0) otherwise. */

int isEmpty( struct extendableArray *a) 
{
	return( a->size == 0 );
}



/* Returns true (1) if the array is full, and false (0) otherwise. */

int isFull( struct extendableArray *a ) 
{
	return( a->size ==  a->capacity );
}



/* Prints the error message msg. */

void printErr( char *msg )
{
   printf( "\n%s\n", msg );
}



/* Prints the content of the array. */

void printArray( struct extendableArray *a )
{
   int i;

   if( isEmpty( a ) ) 
	printErr( "printArray(): empty array." );
    
   for( i = 0; i < a->size; i++)
	printf( "%3d ",  a->arr[i] );

   printf("\n");
}




/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Inserts integer d at the rear of the array, right behind the last element. */
/* Assume all inputs are non-negative integers. */

void insertLast( struct extendableArray *a, int d ) 
{

	/* Add your implementation here */
int *temp,s,i=0;
s=a->size;
if(isFull(a)){
	a->capacity*=2;
	temp= malloc(a->capacity*sizeof(int));
	while(i<s){
		temp[i]=a->arr[i];
		i++;
			}
	free(a->arr);
	a->arr=temp;
}
a->arr[s]=d;
a->size++;
}



/* Removes and returns the last element of the array (the element that was inserted last). */
/* If the array is empty, call printErr() to display a message and return -1. */

int removeLast( struct extendableArray *a )
{



	/* Add your implementation here */
int *temp,s,i=0;
s=a->size;

if(isEmpty(a)){
printErr("printArray(): empty array.");
return (-1);
}
int last= a->arr[s-1];
a->size--;
if(a->size<a->capacity/4&&a->capacity>4){
	a->capacity/=2;
	temp= malloc(a->capacity*sizeof(int));
	while(i<s){
		temp[i]=a->arr[i];
		i++;
			}
	free(a->arr);
	a->arr=temp;
}


   return(last);  
}


/************************** END OF FILE ***************************/



