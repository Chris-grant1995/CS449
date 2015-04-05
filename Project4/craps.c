//Chris Grant
//Prof Misurda 449 
//Project 4

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int rollDice(){
	FILE * f = fopen("/dev/dice", "r");
	char buffer[1];
	int d1;
	fseek(f, 0,SEEK_SET);
	fread(&buffer,1,1,f);
	d1 = buffer[0]+1; 
	printf("%d\n", d1);
	fclose(f);
	return d1;
}
int getRoll(){
	int d1;
	int d2;
	d1=rollDice();
	d2=rollDice();
	printf("You rolled %d + %d = %d\n", d1,d2, d1+d2);
	return d1+d2;
}
int main()
{
	int roll = getRoll();
	printf("%d", roll);
	return 0;
}
