/*
 ============================================================================
 Name        : MyStringUtility.c
 Author      : E.Chancerel
 Version     : 1.00 06.02.2021
 Copyright   : Your copyright notice
 Description : 
 ============================================================================
 */

#include "MyStringUtility.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//disable unwanted warnings in VS compiler 




/* this function get a string into Str[] from specified file Stream until lastChar
*  is reached, then add \0 at the end to indicate end of string
*/
void fget_string(FILE* Stream, char Str[], char lastChar)
{
	long PtrStr = 0;

	while ((Str[PtrStr] = getc(Stream)) != lastChar)
	{
		PtrStr++;
	}
	Str[PtrStr] = '\0';
}

/* Same as fget_string(...) but directly for console stdin
*/
void get_string(char Str[], char lastChar)
{
	fget_string(stdin, Str, lastChar);
}
/*
* Output : number of items replaced
* StrIn[] : String to scan 
* ToFind[] : String to find
* ToReplaceWith[] : String to replace
* max : StrIn[] max size 
*/ 
unsigned int find_replace(char StrIn[], char ToFind[], char ToReplaceWith[], unsigned int max)
{
	char* Occurence = StrIn;
	unsigned int ToFindLength = strlen(ToFind);
	unsigned int ToReplaceLength = strlen(ToReplaceWith);
	int LengthDiff = ToReplaceLength - ToFindLength;
	unsigned int OccurenceLength = 0;
	unsigned int NumberOfOccurences = 0;
	unsigned int FinalLength = 0;	//string final length


	do {
		Occurence = strstr(Occurence, ToFind);
		FinalLength = strlen(StrIn) + abs(LengthDiff);
		//check if there is still an occurence in the string and if the output string length will not exceed array size
		if (Occurence != NULL)
		{
			NumberOfOccurences++;
			OccurenceLength = strlen(Occurence);
			if (LengthDiff > 0)	//Do if ToReplaceWith > ToFind
			{
				for (unsigned int i = OccurenceLength - 1; i > 0; i--)
				{
					Occurence[i + LengthDiff] = Occurence[i];
				}
			}
			else if (LengthDiff < 0)//Do if ToReplaceWith < ToFind
			{
				for (unsigned int i = 0; i <= OccurenceLength - 1; i++)
				{
					Occurence[i] = Occurence[i + abs(LengthDiff)];
				}
			}
			else;//Do if ToReplaceWith == ToFind
			//do nothing
			for (unsigned int i = 0; i <= ToReplaceLength - 1; i++)
			{
				Occurence[i] = ToReplaceWith[i];
			}			
		}
		else if(FinalLength >= max)//array overflow error handler
		{
			printf("\Final array too long, killing program");
			exit(EXIT_FAILURE);
		}

	} while (Occurence != NULL);

	return NumberOfOccurences;
}