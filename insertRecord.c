
#include<stdio.h>

typedef struct Student {
	int rollno;
	char name[30];
	float psy,che,maths;
} STD;

void main() {
	STD S;
	FILE *p;
	char ch;
	p =fopen("student.db","r");
	if(p== NULL) {
		p = fopen("student.db","w");
	}
	else {
		p = fopen("student.db","a");
	}
	
	do{
		printf("Enter Roll no: ");
		scanf("%d",&S.rollno);
		
		printf("Enter Student Name: ");
		fflush(stdin);
		gets(S.name);
		
		printf("Enter Physics Marks: ");
		scanf("%f",&S.psy);
		
		printf("Enter Chemistry Marks: ");
		scanf("%f",&S.che);
		
		printf("Enter Mathematics Marks: ");
		scanf("%f",&S.maths);
		
		fwrite(&S,sizeof(S),1,p);
		
		printf("Add more recorder: (yes/no) ?");
		fflush(stdin);
		scanf("%c",&ch);
	}
	while(ch =='y'||ch=='Y');
	fclose(p);
}


























