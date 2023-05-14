#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int heap[100]={0};
static int last=0;

int heapSize();

void heapify(int i)
{
	int left, right, tmp, largest;
	left=/*heap[*/2*i+1;
	right=/*heap[*/2*i+2;
	
	if(left<heapSize() && heap[i]<heap[2*i+1]) largest=left;
	else largest=i;
	
	if(right<heapSize() && heap[largest]<heap[right]) largest=right;
	
	if(largest!=i){
		tmp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=tmp;
		heapify(largest);
	}
}

int heapDelete()
{
	int max;
	max=heap[0];
	heap[0]=heap[last];
	if(last<0) return 0;
	last--;
	heapify(0);
	
    return max;
}

void addHeap(int thing2add)
{
	int i;
	double parent;
	heap[last]=thing2add;
	i=last;
	parent=(i-1)/2;
	
	while( !(parent<0) && heap[(int) parent]<thing2add){
		heap[i]=heap[(int)parent];
		heap[(int)parent]=thing2add;
		i= (int) parent;
		parent=(i-1)/2;
	}
	last++;
}

int heapSize()
{
    return last; 
}

void printHeap(int position)
{	int next;

	printf("<node id=\"%d\" > ", heap[position]);
	next=2*position+1;
	if(next<heapSize()) printHeap(next);
	next=2*position+2;
	if(next<heapSize()) printHeap(next);
	
	printf("<\\node>\n");
	
}
