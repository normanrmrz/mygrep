#include <stdio.h>
#include <stdlib.h>
#include "matchsize.h"

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