#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <windows.h>


typedef struct
{
  char** racine;
  int mots,noeuds;
}dic_t;

typedef struct
{
  char* value;
  bool is_terminal;
  bool is_word;
}mots;

bool comp(const char *filename,const char* malettre,int len);
mots comp2(const char *filename,const char* malettre,int len);
void findWord(struct trie* dictionary, char** wordBoard, char* word, int** visitedArray, int xLocation, int yLocation);
mots compaire(char* malettre);
char* compaire_with_answer(char* malettre);