#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <windows.h>


typedef struct
{
  char** lettre;
  int taille;
}grille_t;

grille_t constructeur(int taille);
