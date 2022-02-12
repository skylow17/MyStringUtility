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
unsigned int find_replace(char StrIn[], char ToFind[], char ToReplaceWith[], size_t max)
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
			printf("\nFinal array too long, killing program");
			exit(EXIT_FAILURE);
		}

	} while (Occurence != NULL);

	return NumberOfOccurences;
}

/*
* Output : pointer to the newly allocated string position
* StrIn[] : String to scan
* ToFind[] : String to find
* ToReplaceWith[] : String to replace
* currentAllocation : pointer to the variable that store the current memory allocation for the string
* NumberOfOccurences : pointer to the variable that store the number of occurence replaced
* 
* Note : The return value has to be the new pointer as using realloc could force the program the set the new string pointer 
* to another memory location.
*/
char* dfind_replace(char StrIn[], char ToFind[], char ToReplaceWith[], long* currentAllocation, long* NumberOfOccurences)
{
	char* Occurence = StrIn;
	unsigned int ToFindLength = strlen(ToFind);
	unsigned int ToReplaceLength = strlen(ToReplaceWith);
	int LengthDiff = ToReplaceLength - ToFindLength;
	unsigned int OccurenceLength = 0;
	unsigned int FinalLength = 0;	//string final length


	do {
		Occurence = strstr(StrIn, ToFind);
		FinalLength = strlen(StrIn) + abs(LengthDiff);
		//check if there is still an occurence in the string and if the output string length will not exceed array size
		if (Occurence != NULL)
		{
			*NumberOfOccurences += 1;
			OccurenceLength = strlen(Occurence);
			if (LengthDiff > 0)	//Do if ToReplaceWith > ToFind
			{
				*currentAllocation += LengthDiff;
				//reallocate memory as necessary
				StrIn = (char*)realloc(StrIn, *currentAllocation);
				//set end of string char at the new final position
				StrIn[*currentAllocation - 1] = '\0';
				Occurence = strstr(StrIn, ToFind);
				//shift all char to welcome the new string
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

	} while (Occurence != NULL);


	return StrIn;
}

