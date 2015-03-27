//Chris Grant
//Project 3 Testing Program
//Prof. Misurda 
//myMalloc and myFree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "myMalloc.h"

#define MALLOC my_malloc
#define FREE my_free

int main(){
	char *t0;
	char *t1;
	char *t3;
	int *t4;
	int i=0;

	printf("value of sbrk: %p\n", sbrk(0));

	t0 = (char*)MALLOC(20);
	t1 = (char*)MALLOC(50);
	

	strcpy(t0,"Hello!");
	printf("Testing t0 is: %p\n",t0 );
	printf("Value of t0 is: %s\n", t0);
	FREE(t0);
	strcpy(t1,"This string is designed to make sure longer strings dont mess things up");
	printf("Testing t1 is: %p\n",t1 );
	printf("Value of t1 is: %s\n", t1);
	
	FREE(t1);

	t3= MALLOC(0);
	if(t3 == NULL)
	{
		printf("t3 is null, everything worke\n");
	}
	FREE(t3);

	t4 = (int*)MALLOC(20);
	for(i=0; i<20; i++)
	{
		t4[i]=i;
	}
	for(i =0;i<20; i++)
	{
		printf("%d ",t4[i]);
	}
	printf("\n")
	FREE(t4);
	printf("Value of sbrk(0) is %p\n",sbrk(0));

	return 0;
}