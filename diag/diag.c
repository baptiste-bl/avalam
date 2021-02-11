#include "avalam.h"
#include "topologie.h"
#include <string.h>


int main(int argc, char *argv[], char *fen)
{
	t=topologie();
	FILE* fichier = NULL;
	if (argv[0] != '\0')
	{
		strcpy(argv,"position_description.json");
	}	
  fichier = fopen(argv, "w+");

  FEN(t,argv);

}
