#include "grille.h"
#include "dictionnaire.h"


typedef struct
{
  char** value;
  int longeur;
}returner;



const int DX[] = {-1,-1,-1,0,0,1,1,1};//direction x
const int DY[] = {-1,0,1,-1,1,-1,0,1};//direction y
#define SIZE 4
#define WORD 16

returner Search(grille_t wordBoard);
mots compaire(char* malettre);
mots boucle(grille_t grille,char* buffer,int** visited,int x,int y);