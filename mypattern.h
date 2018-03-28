#ifndef MYPATTERN_H_   /* Include guard */
#define MYPATTERN_H_

int matchsize(char *regexp, char *scanfile);
void filltable(char *regexp, char *scanfile, int rows, int cols, char table[rows][cols]);

#endif //MYPATTERN_H_