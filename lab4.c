#include <stdio.h>
#include <stdlib.h>

struct Node{
	int grade;
	struct Node *next;
};
int main()
{
	int tempGrade;
	int size =0;
	struct Node grades;
	
	struct Node *dummy = (Node *)malloc(sizeof(Node));
	struct Node *currGrade= dummy;
	dummy->grade=-1;
	while(scanf("%d" %tempGrade)>0 && tempGrade!=-1)
	{
		struct Node *ptr = (Node*)malloc(sizeof(Node));
		ptr->grade = tempGrade;
		ptr->next=NULL;
		currGrade->next=ptr;
		currGrade=currGrade->next;

	}
	grades=dummy->next;
	for(size=0; grades.next!=NULL; size++)
	{
		printf("%d\n",grades.grade);
		grades=*grades.next;
	}
	return 0;
}