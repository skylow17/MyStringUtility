#ifndef _MYSTRINGUTILITY_H_
#define _MYSTRINGUTILITY_H_

#include <stdio.h> //fonctions qui gèrent les entrées/sorties des programmes écrits en C. Vous en aurez besoin à cause des printf et scanf
#include <stdlib.h> //déclare des fonctions qui effectuent la conversion de nombres, la gestion de la mémoire et d'autres tâches.
#include <stdint.h> //déclare des types standards d'entier
#include <stdbool.h> //gère le type booléen
#include <string.h>
//#include <math.h> //déclare les fonctions mathématiques usuelles

void fget_string(FILE* Stream, char Str[], char lastChar);
void get_string(char Str[], char lastChar);
unsigned int find_replace(char StrIn[], char ToFind[], char ToReplaceWith[], size_t max);
char* dfind_replace(char StrIn[], char ToFind[], char ToReplaceWith[], long* currentAllocation, long* NumberOfOccurences);

#endif