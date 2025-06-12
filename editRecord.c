
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
	int f,rollno;
	
	p =fopen("student.db","r");
	t =fopen("temp.db","w");
	if(p== NULL) {
		printf("File not Found....");
		
	}
	else {
		printf("Enter Student Roll No you Want to Edit: ");
		scanf("%d",&rollno);
		
		printf("\t\t\t\t\tStudent Rocords\n");
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("Roll NO\t\tName\t\t\tPhysics\t\t\tChemistry\t\tMathematics\n");
		printf("------------------------------------------------------------------------------------------------------------\n");
			
		while(!feof(p)) {
			fread(&S,sizeof(S),1,p);
			if(feof(p)) 
			break;
			
			if(S.rollno == rollno) {
		
			
			printf("%d\t\t1: %s\t\t2: %.2f\t\t3: %.2f\t\t4: %.2f5: Exit\n",S.rollno,S.name,S.psy,S.che,S.maths);
			printf("Which felid you want to Edit: ");
			scanf("%d",&f);
			switch(f) {
				case 1:
					printf("Enter New Name: ");
					fflush(stdin);
					gets(S.name);
					break;
				case 2:
					printf("Enter Physics Marks: ");
					scanf("%f",S.psy);
					break;
				case 3:
					printf("Enter Chemistry Marks: ");
					scanf("%f",S.che);
					break;
				case 4:
					printf("Enter Mathematics Marks: ");
					scanf("%f",S.maths);
					break;
				case 5:
//					printf("Exit");
					break;
				default:
					printf("Invalid Choise ");
					break;
			}
			found = 1;
			printf("\t\tRecord Updated Successfully.....");
		}
	
		fwrite(&S,sizeof(S),1,t);
	
	}
	if(found == 0) {
		printf("\t\t Employee not exit....");
	}
}
	fclose(p);
	fclose(t);
	remove("student.db");
	rename("temp.db","student.db");
}
