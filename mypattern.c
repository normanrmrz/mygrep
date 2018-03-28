#include <stdio.h>
#include <stdlib.h>
#include "mypattern.h"

	const int cols = 256;
	int rows;
    int matchsize (char *regexp, char *scanfile)
    {

		rows = 0; 
        char c = regexp[0];
        int i = 0; 
        int ascii; 
        int ascii2;


        while(c != '\0'){
        c = regexp[i];
        if (c == '['){
            ++i;
            c = regexp[i];
            if(c == ']'){
                ++i;
                c = regexp[i];
            }
            while(c != ']'){
                ascii = (int) c;
                if(regexp[i+1] == '-'){
                    ascii2 = (int) regexp[i+2];
                    for(int n = ascii; n <= ascii2; ++n){
                    }
                    ++i;
                    ++i;
                    c = regexp[i];
                }
                else if (c == '\\' && regexp[i+1] == '.'){
                    ++i;
                    c = regexp[i];
                }
                else if(c == '.'){
                    for (int j = 0; j <= 127; ++j){
                        if(j <= 32){
                        if(j != 10){
                    }
                }
                    else{
                    }
                    } 
                }
                else {
                }
                ++i;
                c = regexp[i];
            }
            ++rows;
        }
        c = regexp[i];
        if(c == ']'){
        ++i;
        c = regexp[i];
        }
        if (c == '\\' && regexp[i+1] == '.'){
                    ++i;
                    ++rows;
                    c = regexp[i];
                }
        else if(c == '.'){
                    for (int j = 0; j <= 127; ++j){
                        if(j <= 32){
                        if(j != 10){
                    }
                }
                    else{
                    }
                    } 
                    ++rows;
                }
        else if(c != '\0' && c != '['){
        ++rows;
    }
    if(c != '['){
        ++i;
    }
    }
    return rows;
}

	void filltable(char *regexp, char *scanfile, int rows, int cols, char table[rows][cols]){
    char c = regexp[0];
    int i = 0; 
    int ascii; 
    int ascii2;
    //fill table with 0s
    for(int i = 0; i < rows; ++i){
      	for(int j = 0; j < cols; j++){
      		table[i][j] = '0';
      	}
      }

      	c = regexp[0];
      	i = 0; 
      	int rowcur = 0; 

        //fill table with matching characters.
        while(c != '\0'){
        c = regexp[i];
        if (c == '['){
            ++i;
            c = regexp[i];
            if(c == ']'){
                table[rowcur][(int)c] = '1';
                ++i;
                c = regexp[i];
            }
            while(c != ']'){
                ascii = (int) c;
                if(regexp[i+1] == '-'){
                    ascii2 = (int) regexp[i+2];
                    for(int n = ascii; n <= ascii2; ++n){
                        table[rowcur][n] = '1';

                    }
                    ++i;
                    ++i;
                    c = regexp[i];
                }
                else if (c == '\\' && regexp[i+1] == '.'){
                    table[rowcur][(int)regexp[i+1]] = '1';
                    ++i;
                    c = regexp[i];
                }
                else if(c == '.'){
                    for (int j = 0; j <= 127; ++j){
                        if(j <= 32){
                        if(j != 10){
                        table[rowcur][j] = '1';
                    }
                }
                    else{
                        table[rowcur][j] = '1';
                    }
                    } 
                }
                else {
                    table[rowcur][(int)c] = '1';
                }
                ++i;
                c = regexp[i];
            }
            ++rowcur;
        }
        c = regexp[i];
        if(c == ']'){
        ++i;
        c = regexp[i];
        }
        if (c == '\\' && regexp[i+1] == '.'){
                    table[rowcur][regexp[i+1]] = '1';
                    ++i;
                    ++rowcur;
                    c = regexp[i];
                }
        else if(c == '.'){
                    for (int j = 0; j <= 127; ++j){
                        if(j <= 32){
                        if(j != 10){
                        table[rowcur][j] = '1';
                    }
                }
                    else{
                        table[rowcur][j] = '1';
                    }
                    } 
                    ++rowcur;
                }
        else if(c != '\0' && c != '['){
        table[rowcur][(int)c] = '1';
        ++rowcur;
    }
    if(c != '['){
        ++i;
    }
    }


    }

