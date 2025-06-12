
#include<stdio.h>

typedef struct Student {
	int rollno;
	char name[30];
	float psy,che,maths;
} STD;

void main() {
	STD S;
	FILE *p,*t;
	char ch;
	int found =0;
	float total,per;
	char grade;
	int rollno;
	
	p =fopen("student.db","r");
	t =fopen("temp.db","w");
	if(p== NULL) {
		printf("File not Found....");
		
	}
	else {
		printf("Enter Student Roll No you Want to Delete: ");
		scanf("%d",&rollno);
		
		printf("\t\t\t\t\tStudents Rocords\n");
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("Roll NO\t\tName\tPhysics\t\tChemistry\tMathematics\tTotal\tPercentage\tGrade\n");
		printf("------------------------------------------------------------------------------------------------------------\n");
			
		while(!feof(p)) {
			fread(&S,sizeof(S),1,p);
			if(feof(p)) 
			break;
			
			if(S.rollno == rollno) {
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
			found = 1;
			printf("\t\tRecord Deleted Successfully.....");
		}
		else {
			fwrite(&S,sizeof(S),1,t);
		}
	}
	if(found == 0) {
		printf("\t\t Student not exit....");
	}
	}
	fclose(p);
	fclose(t);
	remove("student.db");
	rename("temp.db","student.db");
}
