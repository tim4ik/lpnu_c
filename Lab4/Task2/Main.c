#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void)
{
	FILE* fileLog;
	if ((fileLog = fopen("log.txt", "a+")) == NULL)
	{
		perror("Error occured while opening log file.");
		exit(0);
	}
	struct tm* ptr;
	time_t It;
	It = time(NULL);
	ptr = localtime(&It);
	fprintf(fileLog, "%s Program started.\n", asctime(ptr));
	const float fEulerConstant = exp(1.0);
	float fX, fZ, fB;
	printf("Name of the file to read from? ");
	char readPath[100];
	gets(readPath);
	FILE* fileRead;
	if ((fileRead = fopen(readPath, "rb")) == NULL)
	{
		perror("Error occured while opening read file.");
		exit(0);
	}
	char* c;
	int i;
	int size = sizeof(float)*2;
	float* fptr = (float*)malloc(size);
	c = (char*)fptr;
	while ((i = getc(fileRead)) != EOF)
	{
		*c = i;
		c++;
	}
	fX = fptr[0];
	fZ = fptr[1];
	It = time(NULL);
	ptr = localtime(&It);
	fprintf(fileLog, "%s Parameters file %s opened. X = %f, Z = %f.\n", asctime(ptr), readPath, fX, fZ);
	fB = fX * (atan(fZ) + pow(fEulerConstant, -1.0 * (fX + 3.0)));
	It = time(NULL);
	ptr = localtime(&It);
	fprintf(fileLog, "%s Expression calculated. Result = %f.\n", asctime(ptr), fB);
	printf("Name of the file to write to? ");
	char writePath[100];
	gets(writePath);
	FILE* fileWrite;
	if ((fileWrite = fopen(writePath, "w+")) == NULL)
	{
		perror("Error occured while opening write file.");
		exit(0);
	}
	fprintf(fileWrite, "%f", fB);
	It = time(NULL);
	ptr = localtime(&It);
	fprintf(fileLog, "%s Output file %s saved.\n", asctime(ptr), writePath);
	It = time(NULL);
	ptr = localtime(&It);
	fprintf(fileLog, "%s Program ended.\n", asctime(ptr));
	fclose(fileLog);
	fclose(fileRead);
	fclose(fileWrite);
}