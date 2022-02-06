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
#include "MyStringUtility.h"


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//disable unwanted warnings in VS compiler 


int main(void) //fonction principale. Tout programme fait appel à cette fonction
{
	//Init local variables
	char Input[100] = "Salut, je m'appelle Erwann. Salut ceci est le premier test. Salut ceci est un test2.";
	unsigned int N = 0;

	printf("%s\n", Input);

	N = find_replace(Input, "Salut ", "Hello_", 100);

	printf("%s\n%d\n", Input, N);

	
	//system("PAUSE"); //ligne à rajouter pour ceux qui utilisent VS
    return EXIT_SUCCESS;
}
