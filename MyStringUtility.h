#ifndef _MYSTRINGUTILITY_H_
#define _MYSTRINGUTILITY_H_

#include <stdio.h> //fonctions qui g�rent les entr�es/sorties des programmes �crits en C. Vous en aurez besoin � cause des printf et scanf
#include <stdlib.h> //d�clare des fonctions qui effectuent la conversion de nombres, la gestion de la m�moire et d'autres t�ches.
#include <stdint.h> //d�clare des types standards d'entier
#include <stdbool.h> //g�re le type bool�en
#include <string.h>
//#include <math.h> //d�clare les fonctions math�matiques usuelles

void fget_string(FILE* Stream, char Str[], char lastChar);
void get_string(char Str[], char lastChar);
unsigned int find_replace(char StrIn[], char ToFind[], char ToReplaceWith[], size_t max);
char* dfind_replace(char StrIn[], char ToFind[], char ToReplaceWith[], long* currentAllocation, long* NumberOfOccurences);

#endif