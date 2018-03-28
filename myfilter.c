#include <stdio.h>
#include <stdlib.h>

void filter(int rows, int cols, char table[rows][cols], char *scanfile){

	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int current;
	int rowcount = 0; 

	FILE* sf = fopen(scanfile, "r");
	if(sf == NULL){
		exit(EXIT_FAILURE);
	}
	while( (read = getline(&line, &len, sf)) != -1){

		for(int i = 0; i < read; ++i){
			current = (int)line[i];
         if ( table[rowcount][current] == '1' && rowcount == rows-1)
         {
         	printf("%s", line); //print line with match
         	rowcount = 0; 
         	i = read;
         }			
		else if(table[rowcount][current] == '1'){

			++rowcount;
		}
         else 
         {
            if (table[rowcount][current] == '0')
            {
               rowcount = 0;
            }
         }
 		}

	}

	fclose(sf);
	if(line){
		free(line);
	}


}