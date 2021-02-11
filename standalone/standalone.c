#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avalam.h"
#include "topologie.h"


int main(int argc, char argv[])
{
	FILE* fichier = NULL;
	if (argv[0] != '\0')
	{
		strcpy(argv,"position_score.json");
	}
	
	
	_Bool FALSE;
	int pstop = 1, choix, choix2, cancel = 1;
	T_Score s;
	T_Position p;
	char af;
	p = getPositionInitiale();
	T_ListeCoups l; 
	l = getCoupsLegaux(p);


	printf("Début de la partie\n");
	printf("Les jaunes jouent en premier!\n");

	while (pstop == 1)
	{
		cancel=1;
		while (cancel == 1)
		{
			
			printf("Quel pion voulez-vous jouer ?\n");
			scanf("%d",&choix);
			printf("Où le déplacer ? Tapez un nombre supérieur à 47 pour annuler\n");
	    scanf("%d",&choix2);
			if((choix2>47 || choix2<0 || choix<0 ||choix>47) && (estValide(p,choix,choix2))==FALSE) 
				{
					cancel=1;
				}
			else
			{
				cancel=0;
				p=jouerCoup(p,choix,choix2);
				addCoup(&l,choix,choix2);
			}
			s=evaluerScore(p);
			afficherScore(s);
			
    
			fichier = fopen(argv, "w+");

			stdout = fichier;
			afficherPosition(p);
			afficherScore(s);

			fclose(fichier);
		}
  }

}
