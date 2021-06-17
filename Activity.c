#include<stdio.h>

void main(){
	int numStudents, x, mark;
	char name[30];
	long size;
	FILE *fptr;
	
	printf("Enter number of students: ");
	scanf("%d", &numStudents);
	
	fptr = (fopen("File_Handling.txt","a"));
	
	for(x = 0; x < numStudents; x++){
		printf("%d. Enter name of student: ", x + 1);
		scanf("%s", name);
		printf("Enter marks: ");
		scanf("%d", &mark);
		
		fseek (fptr, 0, SEEK_END);
		size = ftell(fptr);
		
		if(size == 0){
			fprintf(fptr, "Name: %s \nMarks: %d \n", name, mark);
		} else{
			fprintf(fptr, "\nName: %s \nMarks: %d \n", name, mark);
		}
	}
	fclose(fptr);
}
