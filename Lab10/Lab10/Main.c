#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXAM_QUANTITY 5

typedef struct Date
{
	int day;
	int month;
	int year;
} Date;

typedef struct Student
{
	char name[20];
	char surname[20];
	int exams[EXAM_QUANTITY];
	Date birthdate;
	struct Student* next;
} Student;


Date stringToDate(char str[])
{
	Date date;
	char* day = strtok(str, ".");
	date.day = strtol(day, NULL, 10);
	char* month = strtok(NULL, ".");
	date.month = strtol(month, NULL, 10);
	char* year = strtok(NULL, ".");
	date.year = strtol(year, NULL, 10);
	return date;
}

Student* stringToStudent(char* str)
{
	Student* st = (Student*)malloc(sizeof(Student));
	char* surname = strtok(str, ", ");
	strcpy(st->surname, surname);
	char* name = strtok(NULL, ", ");
	strcpy(st->name, name);
	char* date = strtok(NULL, ", ");
	char* grade = strtok(NULL, ", ");
	int cnt = 0;
	while (grade != NULL)
	{
		st->exams[cnt] = strtol(grade, NULL, 10);
		cnt++;
		grade = strtok(NULL, ", ");
	}
	st->birthdate = stringToDate(date);
	st->next = NULL;
	return st;
}

Student* readFromFile(char filename[])
{
	Student* pFirst=(Student*)malloc(sizeof(Student));
	FILE* fp;
	char str[256];
	int cnt = 0;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		perror("Error occured while opening file");
		return NULL;
	}
	if (fgets(str, 256, fp) != NULL)
	{
		printf("%s\n", str);
		pFirst = stringToStudent(str);
		cnt++;
	}
	Student* pStudent = pFirst;
	while (fgets(str, 256, fp) != NULL)
	{
		printf("%s\n", str);
		Student* test = stringToStudent(str);
		pStudent->next = test;
		pStudent = test;
		cnt++;
	}
	fclose(fp);
	return pFirst;
}

int main(void)
{
	Student* pFirst = readFromFile("students.txt");
	Student* pStudent = pFirst;
	while (pStudent != NULL)
	{
		if (pStudent->exams[0] == 3 && pStudent->exams[2] == 3)
			printf("%s %s\n", pStudent->name, pStudent->surname);
		pStudent = pStudent->next;
	}	
}