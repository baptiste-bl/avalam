#include "avalam.h"
#include "topologie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char argv[], char *fen)
{
	T_Voisins t;
	FILE* fichier = NULL;
	t=topologie[NBCASES];
	
	if (argv[0] != '\0')
	{
		strcpy(argv,"position_description.json");//création du fichier json
	}	
  fichier = fopen(argv, "w+");

  fprintf(fichier,"traiterJson({\n%s:%d,\n%s:%d,\n%s:%d,\n%s:%d,\n%s:%d,\n%s:[\n",STR_TURN,p.trait,STR_COLS);
      for(i=0;i<NBCASES;i++) 
      {
		    fprintf(fichier,"{%s:%3d, %s:%3d},\n", STR_NB, p.cols[i].nb,STR_COULEUR, p.cols[i].couleur);
      }
      fprintf(fichier,"]\n});");

	fclose(fichier);
 // fen(t,argv);

}

/*
char saisie (char tab)
{
tab [80];
int i;
char fg

printf("\nSaisissez votre chaîne:")
fgets(fg,80,stdin);
while(i!=('u,d,t,q,c,U,D,T,Q,C'))



}


//Description compacte d’une position d’échecs
//rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w
//avalam-fen : utilisation des symboles 
//u d t q c pour les jaunes
//U D T Q C pour les rouges
//1 … n pour indiquer un nombre de colonnes vides
//en suivant l’ordre des indices des cases
//un espace; puis j/r pour le trait




			fichier = fopen(argv, "w+");

			stdout = fichier;
			afficherPosition(p);
			afficherScore(s);
      
      