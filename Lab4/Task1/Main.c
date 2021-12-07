#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(void)
{
	char szSentence[100];
	int iCnt = 0, iMaxCnt = 0, iMinCnt, iStart = 0, iMaxStart = 0, iMinStart = 0;
	gets(szSentence);
	bool b = 0;
	iMinCnt = strlen(szSentence);
	for (int i = 0; i < strlen(szSentence); i++)
	{
		if (szSentence[i] == ' ' || szSentence[i] == '.')
		{
			if (!b)
			{
				if (iCnt > iMaxCnt)
				{
					iMaxCnt = iCnt;
					iMaxStart = iStart;
				}
				if (iCnt < iMinCnt)
				{
					iMinCnt = iCnt;
					iMinStart = iStart;
				}
				iCnt = 0;
			}
			b = 1;
			iStart = i + 1;
		}
		else
		{
			iCnt++;
			b = 0;
		}
	}
	printf("\nShortest word: ");
	for (int i = iMinStart; i < iMinStart + iMinCnt; i++)
		printf("%c",szSentence[i]);
	printf("\nLongest word: ");
	for (int i = iMaxStart; i < iMaxStart + iMaxCnt; i++)
		printf("%c",szSentence[i]);
	printf("\n %i %i %i %i", iMinStart, iMinCnt, iMaxStart, iMaxCnt);
	char szSwappedSentence[100];
	int j = 0, k = 0;
	while (j < strlen(szSentence))
	{
		if (j == iMinStart)
		{
			for (int l = iMaxStart; l < iMaxStart + iMaxCnt; l++)
			{
				szSwappedSentence[k] = szSentence[l];
				k++;
			}
			j = iMinStart + iMinCnt;
		}
		else if (j == iMaxStart)
		{
			for (int l = iMinStart; l < iMinStart + iMinCnt; l++)
			{
				szSwappedSentence[k] = szSentence[l];
				k++;
			}
			j = iMaxStart + iMaxCnt;
		}
		else
		{
			szSwappedSentence[k] = szSentence[j];
			k++;
			j++;
		}
	}
	szSwappedSentence[k] = '\0';
	printf("\n%s",szSwappedSentence);
}