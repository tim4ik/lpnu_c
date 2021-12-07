#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
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
} Student;

float averageGrade(Student st)
{
	float sum = 0;
	for (int i = 0; i < EXAM_QUANTITY; i++)
	{
		sum += st.exams[i];
	}
	return sum / EXAM_QUANTITY;
}

bool compareDates(Date d1, Date d2)
{
	if (d1.year > d2.year)
		return 1;
	else if (d1.year == d2.year)
	{
		if (d1.month > d2.month)
			return 1;
		else if (d1.month == d2.month)
		{
			if (d1.day > d2.day)
				return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

Date stringToDate(char str[])
{
	Date date;
	char* day = strtok(str, ".");
	date.day = strtol(day,NULL,10);
	char* month = strtok(NULL, ".");
	date.month = strtol(month,NULL,10);
	char* year = strtok(NULL, ".");
	date.year = strtol(year,NULL,10);
	return date;
}

Student stringToStudent(char* str)
{
	Student st;
	char* name = strtok(str, ", ");
	strcpy(st.name, name);
	char* surname = strtok(NULL, ", ");
	strcpy(st.surname, surname);
	char* date = strtok(NULL, ", ");
	char* grade = strtok(NULL,", ");
	int cnt = 0;
	while (grade!=NULL)
	{
		st.exams[cnt] = strtol(grade,NULL,10);
		cnt++;
		grade = strtok(NULL, ", ");
	}
	st.birthdate = stringToDate(date);
	return st;
}

int readFromFile(Student students[], char filename[])
{
	FILE* fp;
	char str[256];
	int cnt = 0;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		perror("Error occured while opening file");
		return NULL;
	}
	while (fgets(str, 256, fp) != NULL)
	{
		printf("%s\n", str);
		students[cnt] = stringToStudent(str);
		cnt++;
	}
	fclose(fp);
	return cnt;
}

int studentsWithout5(Student students[], Student studentsResult[], int cnt)
{
	int cntResult = 0;
	for (int i = 0; i < cnt; i++)
	{
		bool has5 = 0;
		for (int j = 0; j < EXAM_QUANTITY; j++)
		{
			if (students[i].exams[j] == 5)
			{
				has5 = 1;
				break;
			}
		}
		if (!has5)
		{
			studentsResult[cntResult] = students[i];
			cntResult++;
		}
	}
	return cntResult;
}

void swap(Student array[], long pos1, long pos2)
{
	Student tmp;
	tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}

void sortStudentsByAverageGrade(Student students[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < cnt; j++)
		{
			if (averageGrade(students[j]) < averageGrade(students[minIndex]))
				minIndex = j;
		}
		swap(students, minIndex, i);
	}
}

Student youngestStudent(Student students[], int cnt)
{
	Student res = students[0];
	for (int i = 1; i < cnt; i++)
	{
		if (compareDates(res.birthdate, students[i].birthdate))
			res = students[i];
	}
	return res;
}

Student oldestStudent(Student students[], int cnt)
{
	Student res = students[0];
	for (int i = 1; i < cnt; i++)
	{
		if (!compareDates(res.birthdate, students[i].birthdate))
			res = students[i];
	}
	return res;
}

int main(void)
{
	Student students[100];
	char filename[20] = "students.txt";
	int cnt = readFromFile(students, filename);
	Student without5[100];
	int cntWithout5 = studentsWithout5(students, without5, cnt);
	sortStudentsByAverageGrade(without5, cntWithout5);
	printf("Students without 5: \n");
	for (int i = 0; i < cntWithout5; i++)
	{
		printf("%s %s %f\n", without5[i].name, without5[i].surname, averageGrade(without5[i]));
	}
	printf("Youngest student without 5:\n");
	Student youngest = youngestStudent(without5, cntWithout5);
	printf("%s %s %f\n", youngest.name, youngest.surname, averageGrade(youngest));
	printf("Oldest student without 5:\n");
	Student oldest = oldestStudent(without5, cntWithout5);
	printf("%s %s %f\n", oldest.name, oldest.surname, averageGrade(oldest));
}