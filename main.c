/*
 ============================================================================
 Name        : calcul_surface.c
 Author      : E.Chancerel
 Version     : 1 du 27.09.2021
 Copyright   : Your copyright notice
 Description : 
 ============================================================================
 */

#include <stdio.h> //fonctions qui gèrent les entrées/sorties des programmes écrits en C. Vous en aurez besoin à cause des printf et scanf
#include <stdlib.h> //déclare des fonctions qui effectuent la conversion de nombres, la gestion de la mémoire et d'autres tâches.
#include <stdint.h> //déclare des types standards d'entier
#include <stdbool.h> //gère le type booléen
#include <math.h> //déclare les fonctions mathématiques usuelles
#include <string.h>
#include "MyStringUtility.h"



#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//disable unwanted warnings in VS compiler 


int main(void) //fonction principale. Tout programme fait appel à cette fonction
{
	//Init local variables
	char Input[100] = "Salut, je m'appelle Erwann. Salut ceci est le premier test. Salut ceci est un test2.";
	char cat[] = "phrase de test ";
	long N = 0;
	char* Str = NULL;
	long currentAllocation;
	FILE* myFile = NULL;

	

	myFile = fopen("example.txt", "r+");

	fseek(myFile, 0, SEEK_END); // seek to end of file
	currentAllocation = ftell(myFile); // get current file pointer
	fseek(myFile, 0, SEEK_SET); // seek back to beginning of file

	Str = (char*)calloc(currentAllocation, sizeof(char));

	fget_string(myFile, Str, EOF);	//get the whole file content
	fclose(myFile);

	printf("%s\n\n", Str);
	Str = dfind_replace(Str, " il ", " REPLACEMENT ", &currentAllocation, &N);

	myFile = fopen("example.txt", "w");
	fwrite(Str, 1, currentAllocation, myFile);
	fclose(myFile);

	printf("\nN = %ld\n", N);

	free(Str);

	


	//================================

	/*printf("Input : \n%s\n", Input);
	currentAllocation = strlen(Input) + 1;
	Str = (char*)calloc(currentAllocation, sizeof(char));
	strcpy(Str, Input);
	printf("Str : \n%s\n", Str);
	Str = dfind_replace(Str, "Salut", "Avec mes plus plates et Mes meilleures salutations", &currentAllocation, &N);

	printf("%s\n", Str);

	printf("N = %ld\n", N);

	free(Str);*/
	
	//================================

	/*Str = (char*)calloc(strlen(Input) + 1, sizeof(char));
	strcpy(Str, Input);
	printf("%s\n", Str);
	for (unsigned int i = 0; i <= 5; i++)
	{
		Str = (char*)realloc(Str, strlen(Str) + strlen(cat) + 2);
		strcpy(Str + strlen(Str), cat);
		printf("%s\n", Str);
	}

	free(Str);*/
	//================================
	
	//system("PAUSE"); //ligne à rajouter pour ceux qui utilisent VS
    return EXIT_SUCCESS;
}
