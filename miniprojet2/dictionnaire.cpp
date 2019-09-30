#include "dictionnaire.h"

mots comp2(const char *filename,const char* malettre,int len)  // enregistrer dans un char**
{
	mots myword;
	//myword.is_word = 0;
	//myword.is_terminal =0;
	myword.value = (char*)malettre;
	//strcpy(myword.value,malettre);
	//printf("myword%s",myword);
	bool isword;
    FILE *fp;

    if((fp=fopen(filename,"rb"))==NULL)
    {
        printf("can't open\n");
    }
	else{
			char temp[256];
			while(fgets(temp,255,fp))
		{  
			isword = 0;
			temp[strlen(temp) -1] = '\0';
			if(strstr(temp, malettre)!=NULL)
			{
				 // myword.is_terminal = 0;
				  if (strlen(temp)==len)
				  {
					myword.is_terminal = 0;
					isword = 1;
					break;
				  }
				  else
				  {isword = 0;
					 myword.is_terminal = 0;
					 }
			}
			else{
				myword.is_terminal =1;
			}
		} 
		fclose(fp);
		myword.is_word = isword;
		//printf("isword=%d\t",isword);
		//isword = 0;
	
	return myword;
}
}



mots compaire(char* malettre)
{
	
	char fname[128] = "dict.txt";
	int n = strlen(malettre);
	mots a;
	a = comp2(fname,malettre,n);
	if(!(a.is_word)) {
		//printf("%s n'est pas dans la dictionnaire\n",malettre);
		a.value ="0";
	}
	return a;
}

	char* compaire_with_answer(char* malettre)
{
	char fname[128] = "answer.txt";
	int n = strlen(malettre);
	if(!(comp(fname,malettre,n))) printf("%s erreur\n",malettre);
	else
	{
		return malettre;
	}
	return ( "0");
}

	bool comp(const char *filename,const char* malettre,int len)  // enregistrer dans un char**
{

    FILE *fp;
    char temp[256];
    if((fp=fopen(filename,"rb"))==NULL)
    {
        printf("can't open\n");
        return false;
    }
    while(fgets(temp,255,fp))
    {  

        temp[strlen(temp) -1] = '\0';
        if(strstr(temp, malettre)!=NULL)
        {
          if (strlen(temp)==len)
          {
            return true;
          }
        }
		
	//printf("%s why false:,%d\n",temp,strlen(temp));
    } 
    fclose(fp);
    return false;
}
