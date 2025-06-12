
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
	float total,per;
	char grade;
	p =fopen("student.db","r");
	if(p== NULL) {
		printf("File not Found....");
	}
	else {
		printf("\t\t\t\t\t\t\t\b\bStudent Rocords\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("Roll No\t\tName\t\tPhysics\t\tChemistry\tMathematics\tTotal\t\tPercentage\tGrade\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
			 
		while(!feof(p)) {
			fread(&S,sizeof(S),1,p);
			if(feof(p)) 
			break;
			
			total = S.rollno + S.che + S.maths;
			per = total/3;
			total = S.rollno + S.che + S.maths;
			per = total/3;
			
			if(per > 80) {
				grade ='A';
			}
			else if(per >=60 && per <= 79) {
				grade ='B';
			}
			else if(per >= 50 && per <= 59) {
				grade ='C';
			}
			else {
				grade ='D';
			}
			printf("%d\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%c\n",S.rollno,S.name,S.psy,S.che,S.maths,total,per,grade);
		}
	}
	fclose(p);
}
