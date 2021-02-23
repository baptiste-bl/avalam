#include "topologie.h"


int main(int argc, char argv[])
{
	FILE* fichier = NULL;
	if (argv[0] != '\0')
	{
		strcpy(argv,"refresh-data.js"); //création fichier js
	}
	
	
	_Bool FALSE;
	int pstop = 1, choix, choix2, cancel = 1;
  	int i; //variable comptage
	T_Score s; //score
	T_Position p; //position
	char af; //????

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

			/* stdout = fichier;
			afficherPosition(p);
			afficherScore(s);
      */
			fprintf(fichier,"traiterJson({\n%s:%d,\n%s:%d,\n%s:%d,\n%s:%d,\n%s:%d,\n%s:[\n",STR_TURN,p.trait,STR_SCORE_J,s.nbJ,STR_SCORE_J5,s.nbJ5,STR_SCORE_R,s.nbR,STR_SCORE_R5,s.nbR5,STR_COLS);
			for(i=0;i<NBCASES;i++) 
			{
			fprintf(fichier,"{%s:%3d, %s:%3d},\n", STR_NB, p.cols[i].nb,STR_COULEUR, p.cols[i].couleur);
			}
			fprintf(fichier,"]\n});");

			fclose(fichier);
		}
  }

}