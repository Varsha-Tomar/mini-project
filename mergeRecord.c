#include<stdio.h>
#include<stdlib.h>
 
 void main() {
 
	
 	int ch;
 	char fake;
 	do{
 	system("cls");
 	printf("main menu\n1: Insert Record\n2: Display All Record\n3: Search Record\n4: Delete Record\n5: Edit Record\n6: Exit\n");
 	printf("Enter your choise ? ");
 	scanf("%d",&ch);
 	system("cls");	
 	switch(ch) {
 		case 1:
 			system("insertRecord.exe");
 			break;
 		case 2:
 			system("displayAllRecord.exe");
 			break;
 		case 3:
 			system("searchRecord.exe");
 			break;
 		case 4:
 			system("deleteRecord.exe");
 			break;
 		case 5:
 			system("editRecord.exe");
 			break;
 		case 6:
 			system("Good Bye..");
 			break;
 		default:
 			printf("Invailid choise...");
 			
	 }
	 printf("\n \t\tPress any key to continue....\n");
	 fflush(stdin);
	 scanf("%c",&fake);
}	
	while(ch != 6);
	 
 }
 
 
 
 
 
 
 
 
 
 
