#include "grille.h"

char cara[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

grille_t constructeur(int taille) // créer des lettre al?
{
  grille_t G;
  G.taille = taille;
  G.lettre = (char**)malloc(taille * sizeof(char**));
  srand((unsigned)time(NULL));
  for (int i=0;i<taille;i++)
  {
    G.lettre[i]=(char*)malloc(taille*sizeof(char));
    for (int j=0;j<taille;j++)
    {
      G.lettre[i][j] = cara[rand()%26];
	 /* G.isused[i][j] = 0;*/
    }
  }
  return G;
}