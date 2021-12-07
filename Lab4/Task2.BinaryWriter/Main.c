	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	int main(void)
	{
		float fX, fZ;
		printf("fX? ");
		scanf("%f", &fX);
		printf("fZ? ");
		scanf("%f", &fZ);
		char path[100];
		printf("File path? ");
		gets(path);
		gets(path);
		FILE* f;
		if ((f = fopen(path, "w+b")) == NULL)
		{
			perror("Error occured while opening file.");
			exit(0);
		}
		char* c = (char*)&fX;
		int size = sizeof(float);
		for (int i = 0; i < size; i++)
			putc(*c++, f);
		c = (char*)&fZ;
		for (int i = 0; i < size; i++)
			putc(*c++, f);
		fclose(f);
	}