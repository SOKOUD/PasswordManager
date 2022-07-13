#ifndef fileOp_H
#define fileOp_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE* initFile(char *name,char *mode);
void emptyFile(FILE* in,char name[]);


#endif // fileOp_H
