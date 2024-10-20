#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTUDENT 80

typedef struct{
	char name[20];
	char surname[20];
	int student_id;
	char department[50];
}STUDENT;

typedef struct{
	int size; //sinif mevcudu
	STUDENT list[MAXSTUDENT];
}COURSE;

void readStudent(STUDENT *sptr){
	printf("Enter student's: \n");
	printf("Name: ");
	scanf("%s", sptr->name);
	printf("Surname: ");
	scanf("%s", sptr->surname);
	printf("Student id: ");
	scanf("%d", &sptr->student_id);
	printf("Department: ");
	scanf("%s", sptr->department);
}

void insertStudent(COURSE *cptr, STUDENT *s){
	if(cptr->size<MAXSTUDENT){
		cptr->list[cptr->size]=*s;
		cptr->size++;
	}
}

void addStudent(COURSE *cptr){
	STUDENT s1;
	readStudent(&s1);
	insertStudent(cptr,&s1);
}

void printStudent(STUDENT s1){
	printf("-%s %s %d %s\n", s1.name, s1.surname, s1.student_id, s1.department);
}

void printCourse(COURSE *cptr){
	printf("\nCourse class list: \n");
	int i;
	for(i=0;i<cptr->size;i++){
		printStudent(cptr->list[i]);
	}
	if(cptr->size==0){
		printf("-EMPTY CLASS!-");
		printf("\n");
	}
	printf("\n");
}

void update(COURSE *cptr){
	int id;
	printf("Update Module: \n");
	printf("Enter id: ");
	scanf("%d", &id);
	int index=0;
	while(index<cptr->size){//sinif listesini tarar
		if(cptr->list[index].student_id==id){
			STUDENT newStudent;
			printf("Existing record is: ");
			printStudent(cptr->list[index]);
			readStudent(&newStudent);
			cptr->list[index]=newStudent;
		}
		index++;
	}
}

void eraseStudent(COURSE *cptr,int index){
	int i;
	for(i=index;i<cptr->size-1;i++){
		cptr->list[i]=cptr->list[i+1];
	}
	cptr->size--;
}

void removeStudent(COURSE *cptr){
	int id;
	int index=0;
	printf("Enter the id that you want to delete: ");
	scanf("%d", &id);
	while(index<cptr->size){
		if(cptr->list[index].student_id==id){
			eraseStudent(cptr,index);
		}
		index++;
	}
}

void printMenu(){
	printf("---Student Registration System---\n");
	printf("1.Add a new student\n");
	printf("2.Remove a student\n");
	printf("3.Update student information\n");
	printf("4.Print all registered students\n");
	printf("5.Exit\n");
	printf("Choose an option: ");
}
/*
void initializeCourses(COURSE *courses, int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        printf("Enter the name of course %d: ", i + 1);
        scanf("%s", courses[i].course_name);
        courses[i].size = 0; // Initialize size to 0
    }
}

int chooseCourse(COURSE *courses, int numCourses) {
    printf("Choose a course by number:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("%d. %s\n", i + 1, courses[i].course_name);
    }
    int courseIndex;
    scanf("%d", &courseIndex);
    return courseIndex - 1; // Array index starts at 0
}
*/
int main(){
	COURSE ceng241={0};//init func
	int option;
	while(1){
		printMenu();
		scanf("%d", &option);
		switch(option){
			case 1:
				addStudent(&ceng241);
				break;
			case 2:
				removeStudent(&ceng241);
				break;
			case 3:
				update(&ceng241);
				break;
			case 4: 
				printCourse(&ceng241);
				break;
			case 5:
				return 0;
		}	
	}
	return 0;
}
