#include "fileOp.h"

//fonction qui initialise un fichier ayant un nom name et un mode mode
FILE* initFile(char name[],char mode[]){
 FILE* in=fopen(name,mode);

 return in;
}

//procedure qui vide le contenu d'un fichier
void emptyFile(FILE* in,char name[]){
in=fopen(name,"w");
in=NULL;
}

