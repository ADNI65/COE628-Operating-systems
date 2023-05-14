// 
// Input stdin data is read from "Input_Test_Data" txt file
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

extern int pop();
extern void push(int);
extern void printHeap(int position);
extern void addHeap(int thing2add);
extern int heapDelete();
extern int isEmpty();

int main(int argc, char * argv[])
{
	FILE*f;
    int value, i;
    f=fopen("Input_Test_Data", "r");
    
    while (fscanf(f, "%d\n", &value) != EOF) {
    	fprintf(stderr, "READING INPUT: %d\n", value);    	
    	addHeap(value);
    }
	printf("Heap:\n");
	printHeap(0);
	printf("\n");
	
	for(i=0; i<100; i++){
		value=heapDelete();
		if(value==0) continue;
		printf("%d\n", value);
		push(value);
	}
	
	printf("\n\n");
	
	for(i=0; i<100; i++){
		if(isEmpty()) continue;
		value=pop();
		printf("%d\n", value);
	}
	
    exit(0);
}

