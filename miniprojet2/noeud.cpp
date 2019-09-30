#include "noeud.h"


returner Search(grille_t wordBoard){
	mots answer;
	returner rt;		//pour return
	rt.longeur = 0;
	rt.value = (char**)malloc(128 * sizeof(char**));
	for (int c=0;c<128;c++)
		rt.value[c]=(char*)malloc(16*sizeof(char));
	int nb=0;
	int i, j, x, y, d, bufferCounter = 0;
	int a, b;
  int** visited;
  visited= (int**)malloc(sizeof(int*) * 4);
	for (a = 0; a < 4; a++) {
		visited[a] = (int*)malloc(sizeof(int) * 4);
		
}
	char* buffer = (char*)malloc(sizeof(char) * (17));//buffer[lettre+1]=='\0'.
	printf("traitement en cours\n");
	for (i= 0;  i < 4; i++) {            //position x de premiere lettre.
		for (j = 0; j < 4; j++) {         //position y de premiere lettre.
			for (d = 0; d < 8; d++) {	//direction
				bufferCounter = 0;		//nb. de lettre
				x = i;
				y = j;
        	for (a = 0; a < 4; a++) {
					  for (b = 0; b < 4; b++) {
						  visited[a][b] = 0;//par defaut
					  }
          }
				while ((x >= 0 && x < 4) && (y >= 0 && y < 4)) {
					visited[x][y] = 1;
					buffer[bufferCounter +1] = '\0';//add letter
					buffer[bufferCounter] = wordBoard.lettre[x][y];
						x += DX[d];
						y += DY[d];
						bufferCounter++;
						//printf("buffercounter =%d\n",bufferCounter);
					//printf("x=%d,y=%d£¬direction is%c\n",x,y,direction_fleche[d]);
						if (strlen(buffer) >= 3) 
						{
							//answer = compaire(buffer);
							answer = boucle(wordBoard,buffer, visited, x, y);
							//printf("bufffer is:%s\t answer.value is:%s\n",buffer,answer.value);
							if(strcmp(answer.value,"0")!=0)
							{
								strcpy(rt.value[nb],answer.value);
								nb++;
								rt.longeur++;
								printf("%s oui\n",answer.value);
							}
						}
//
					}//end while
			//break;
			} //end boucle d
		}//end j
	}//end i
	return rt;

}



mots boucle(grille_t grille, char* buffer, int** visited, int x, int y){
int i;
  mots answer;
	char* newWord = (char*)malloc(sizeof(char) * 17);
	answer.is_terminal =0;
	strcpy(newWord, buffer);
	int wordCounter;
  wordCounter = strlen(newWord);						

	for ( i= 0;  i < 8; i++) {
		int X = x+DX[i];
		int Y = y+DY[i];
		//printf("wordcounter =%d\n",wordCounter);
		answer = compaire(newWord);
		if ((X >= 0 && X < 4) && (Y >= 0 && Y < 4) && visited[X][Y] == 0) { //grile_size = 4
			newWord[wordCounter + 1] = '\0';
			newWord[wordCounter] = grille.lettre[X][Y]; 
			wordCounter++;
			//printf("wordcounter =%d,newword = %s,newword[%c],%c%c%c%c\n",wordCounter,newWord,newWord[wordCounter],newWord[0],newWord[1],newWord[2],newWord[3]);  ///////////////////////////////////////
			visited[X][Y] = 1;   //////////////////////
			//printf("check %s\n",newWord);
			if (answer.is_terminal != 1){
				boucle(grille,buffer, visited, X, Y);
			}
		}
		else
			continue;
	} // end for
	return answer;
}