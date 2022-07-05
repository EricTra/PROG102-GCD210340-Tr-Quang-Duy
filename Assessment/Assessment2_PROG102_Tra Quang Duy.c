#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void viewMenu();
void viewStudentsInfo( int studentsID[], float studentGrade[], int numberOfStudent);
void enterStudentsInfo(int studentArray[], float gradeArray[], int numberOfStudent);
float findlowestGrade(float gradeArr[], int numberOfStudent);
void findIdlowestgrade( int studentsID[], float gradeArr[], int numberOfStudent, float min);
float findHighestGrade(float gradeArr[], int numberOfStudent);
void findIDHighestGrade(int studentsID[], float gradeArr[], int numberOfStudent, float max);
int i, a=0;
int main(){
	int studentsID[100];
	float studentsGrade[100];
	int choice, numberOfStudent;
	float lowestGrade, highestGrade;
	// Menu option
	do{
		viewMenu(); // show Menu to choose
		printf("\n\tEnter your choice"); // enter user's choice from the menu
		scanf("%d", &choice);
		switch(choice){ // match the value of the variable "choice" with the existing request
		case 1:
			printf("\n\tEnter number of student:"); // enter number of student
			scanf("%d", &numberOfStudent);
			printf("\n\tYour choice is enter all student's information:\n");
			enterStudentsInfo(studentsID, studentsGrade, numberOfStudent); // run option 1
			a=1; 
			break;
			case 2:
				if (a !=0){
				printf("\n\tYour choice is view all student's information:\n");
				 viewStudentsInfo(studentsID, studentsGrade, numberOfStudent);} // run option 2
			break;
			case 3:
				if (a !=0) {
				printf("\n\tYour choice is view student has highest grade:\n");
				highestGrade=findHighestGrade(studentsGrade, numberOfStudent);
				findIDHighestGrade(studentsID, studentsGrade, numberOfStudent, highestGrade);} // run option 3
			break;
			case 4:
				if (a !=0) {
				printf("\n\tYour choice is view student has lowest grade:\n");
				lowestGrade=findlowestGrade(studentsGrade, numberOfStudent);
				findIdlowestgrade(studentsID, studentsGrade, numberOfStudent, lowestGrade);} // run option 4
			break;
			case 5:
				printf("\n\tExit sucessfully. Good bye!"); //exit program when option is chosen
			break;
			default:
				printf("\n\tYour choice is not correct. Please choose again!"); // request to re-enter choice if user's choice is wrong
			break;
		}
		}
		while(choice!=5); //set the condition to back to the Menu
		printf("\n\t See you again!");
		return 0;
	}
	// Menu option directerly
	void viewMenu(){
		    printf("\n ============== Student grade management system ===============\n");
    printf("\t Enter number 1: Enter all student's information \n");
    printf("\t Enter number 2: View all student's information \n");
    printf("\t Enter number 3: Student has highest grade \n");
    printf("\t Enter number 4: Student has lowest grade \n");
    printf("\t Enter number 5: Exit ");
    printf("\n ==============================================================\n");
	}
	// enterStudentsInfo
	void enterStudentsInfo(int studentArray[], float gradeArray[], int numberOfStudent){
	for( i=0; i<numberOfStudent; i++){   //run for loop to input data
		do{
			printf("\n\tEnter student's Id %d (from 01 to 1000):", i+1);
			scanf("%d", &studentArray[i]);
		}
		while ((studentArray[i]<1) || (studentArray[i]>1001)); // set the condition of ID from 1 to 1000
		do{
			printf("\n\tEnter student's Grade %d (from 0 to 10):",i+1);
			scanf("%f", &gradeArray[i]);
		}
		while ((gradeArray[i]<0) || (gradeArray[i]>10)); // set the condition of Grade from 0 to 10
	}
}
// viewStudentsInfo
void viewStudentsInfo( int studentsID[], float studentGrade[], int numberOfStudent){
	for(i=0; i< numberOfStudent; i++){  // run for loop to input data
		printf("\n\tThe student's ID %d is:\t%d", i+1, studentsID[i]); // display student's ID
		printf("\t\t\t\tThe student's grade %d is:\t%f", i+1, studentGrade[i]); // display student's Grade
	}
}
// Find lowestGrade
float findlowestGrade(float gradeArr[], int numberOfStudent){
	float lowestGrade = gradeArr[0];
	for(i =0; i < numberOfStudent; i++){  // run for loop to compare the value of each element
		if(lowestGrade > gradeArr[i]){  // compare current minimum value with other values to find lower grade
			lowestGrade = gradeArr[i];
		}
	}
	return lowestGrade;
}
// void find lowestID
void findIdlowestgrade( int studentsID[], float gradeArr[], int numberOfStudent, float min){
	int id=studentsID[0];
	for(i=0; i< numberOfStudent; i++){ // run a for loop to find the ID corresponding to the lowest grade
if (min == gradeArr[i]){
	id=studentsID[i]; //assign new ID value if condition is true
	printf("\n\tStudent with ID %d has the lowest grade of %f", id, min);
}
	}
}
// Find highestGrade
float findHighestGrade(float gradeArr[], int numberOfStudent){
	float highestGrade = gradeArr[0];
	for(i=0; i< numberOfStudent; i++){  // run for loop to compare the value of each element
	if(highestGrade < gradeArr[i]){  // compare current maximum value with other values to find the highest grade
		highestGrade = gradeArr[i];
	}	
	}
	return highestGrade;
}
// void find highestID
void findIDHighestGrade(int studentsID[], float gradeArr[], int numberOfStudent, float max){
	int id=studentsID[0];
	for(i = 0; i < numberOfStudent; i++){ // run a loop to find the ID corresponding to the highest grade
	if(max == gradeArr[i]){
		id=studentsID[i]; //assign new ID value if condition is true
		printf("\n\tStudent with ID %d has the highest grade of %f", id, max);
	}
	}
}
