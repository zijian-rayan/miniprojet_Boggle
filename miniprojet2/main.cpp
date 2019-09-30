//#include "grille.h"
//#include "dictionnaire.h"
#include "noeud.h"
void freefunction(char**answer);
void notefunction();

void main()
{
  int taille = 4;
  grille_t A=constructeur(taille);
    printf("Welcome to Booggle!\n");
  printf("********************** Grille *************************\n#\t");
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
          printf("%c\t",A.lettre[i][j]);  // afficher des lettre
        }
		if(i!=3)
			printf("#\n#\t");
		else
			printf("#\n*");
    }
	printf("********************** Fin ***************************\n");


	returner answer;


	answer = Search(A);
	FILE* p = fopen("answer.txt", "wb");
	for (int j=0;j< (answer.longeur);j++)
		fprintf(p,"%s\n",answer.value[j]);

		//fprintf(p,"main\ntoto\ntiti\ntata\nname\n");

    fclose(p);

		notefunction();


}






void notefunction(){
	char** iscompted;
	iscompted = (char**)malloc(128 * sizeof(char**));
	for (int i=0;i<128;i++)
		iscompted[i]=(char*)malloc(16*sizeof(char));
	char* malettre;
	malettre = (char*)malloc(16*sizeof(char));
	char* fanswer;
	fanswer = (char*)malloc(sizeof(char) * 16);
	int point = 0 ;
	int a = 0;
	printf("your word\n");
	while (1){
		scanf("%s",malettre);
		int used = 0;
		if(malettre[0]=='q' && malettre[1]=='u' &&malettre[2]=='i'&& malettre[3]=='t')
			break;
                        
		else {
			fanswer = compaire_with_answer(malettre );
            
                          for(int i = 0;i<=a;i++){
							  if(strstr(fanswer, iscompted[i]) != NULL){
                              used = 1;
							  printf("your word has been used...please try a new word£¬used is %d\n",used);
							}
                          }//end for;

                          if(fanswer != "0"&& used==0)
                          {
	                              if(strlen(fanswer)==3||strlen(fanswer)==4)
		                              point = point+1;
	                              else if(strlen(fanswer)==5)
		                              point = point +2;
	                              else if (strlen(fanswer)==6)
		                              point = point + 3;
	                              else if (strlen(fanswer)==7)
		                              point = point + 5;
	                              else if (strlen(fanswer)>=8)
		                              point = point + 11;
	                              else
		                              point = point;
	                              printf("answer %s yes,your point is:%d,used is %d\n",fanswer,point,used);
	                              iscompted[a]=fanswer;
	                              //printf("used is:%d",used);
								  a++;
                          }//end if;
						  else
							  used = 0;
                        }//end else ===>quit!
		
		}//end while;
	printf("Fin du projet BOOGGLE.\tAu revoir\n");
  //free(malettre);
	//free (fanswer);
  //freefunction (answer.value );
	//freefunction (A.lettre );
	//freefunction (iscompted );
}

void freefunction(char**answer)
{
  	for (int i=0;i<128;i++)
		free (answer[i]);
	free (answer);
}
