#include <stdio.h>
#include <stdlib.h>
#include "mypattern.h"
#include "myfilter.h"

/* 
mygrep supports the use of text strings, files, and a simplified 
regular expression language to test files for the presence of a certain 
string or pattern of characters. 
For the purposes of this particular grep implementation, the only characters that 
have special meaning to the program are ( [...], [-], and . ). 
All other characters will be treated regularly and have no effect on the 
regular expression. 

The program takes in a pattern string, followed by a file to be scanned/searched.
The format for input is as follows:
./mygrep <pattern> [FILE]

Ex: ./mygrep test mytestfile.txt
    matches: "test" in mytestfile
    ./mygrep te[sx]t mytestfile.txt
    matches "test" or "text" in mytestfile
    ./mygrep [a-z]
    matches matches any lowercase character between a-z
    would not match a line of just numbers or uppercase. 

So, to run the program, using the included Makefile:
make (or make mygrep)
./mygrep <pattern> [FILE]

use make clean to clear .o files from the directory. 

given the test pattern and a file to be scanned, input is scanned from the 
file line by line. Every line is searched for a string that is able to match the pattern, 
and if the pattern occurs at least one time in any string, the entire line is output to 
stdout and the next line will begin to be processed. 

If the entire file is scanned and the program finds no strings that match
the given pattern, then the program will print nothing to the console, 
as there is no matched lines to be shown to the user. 

This part of the program is handled by mypattern.c:
mygrep functions by first processing the input pattern, and finding out how many 
characters of text need to be matched. 
This number will be the number of rows in a pattern matching table
that keeps track of what ASCII codes are a suitable match at every position 
in a potential match string. Once this is figured out, the pattern itself is 
processed to figure out which ASCII codesto turn "on" in the table 
(meaning that it is valid at the position).
EX: if table[2][116] == '1' , then that means ASCII code 116 is a valid match at 
position 2 of some string. 
If the pattern is something like [a-z] then all the codes for that range will be turned on/
set to 1.

Once this table is constructed, then the program knows what codes can construct 
a suitable string.
From here the rest of the work is done by myfilter.c:
Given the newly constructed table and a file to be scanned, myfilter.c takes input from the 
file to be scanned line-by-line. Starting at position 0, if that character in the string being 
searched is a match, then the program checks the next position in the string, and the next row
in the lookup table. This is repeated until a match is found for all rows in the lookup table. 
If this happens, the entire line of output is printed to the console. 
If a string of input matches for say the only first few rows of the table, then a no-match is 
encountered, then the search position in the string is advanced and the row position being 
searched in the table is set back to 0. 
*/
int main(int argc, char *argv[]){
    char *regexp = argv[1];
    char *scanfile = argv[2];
    int rows = 0;
    const int cols = 256;
    rows = matchsize(regexp, scanfile);
    char table[rows][cols];
    filltable(regexp, scanfile,rows, cols, table);


    filter(rows, cols, table, scanfile);
    return 0;
}