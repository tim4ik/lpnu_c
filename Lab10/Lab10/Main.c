#include <stdio.h>
#define EXAM_QUANTITY 5

typedef struct Student
{
	char name[20];
	char surname[20];
	int exams[EXAM_QUANTITY];
	struct Student* next;
} Student;

int main(void)
{
	int n;
	printf("Number of students? ");
	scanf_s("%i", &n);
	Student* pStudent = (Student*)malloc(sizeof(Student));
	Student* pFirst = pStudent;
	for (int i = 0; i < n; i++)
	{
		printf("Name? ");
		char testname[20]=scanf_s("%s".)
		scanf_s("%s", &pStudent->name);
		printf("Surname? ");
		scanf_s("%s", &pStudent->surname);
		for (int j = 0; j < EXAM_QUANTITY; j++)
		{
			printf("Exam %i? ", j);
			scanf_s("%i", &pStudent->exams[i]);
		}
		Student* pNext = (Student*)malloc(sizeof(Student));
		pStudent->next = pNext;
		pStudent = pNext;
	}
	pStudent->next = NULL;
	Student* pRead = pFirst;
	while (pRead != NULL)
	{
		printf("%s\n", pRead->name);
		pRead = pRead->next;
	}
}