#ifndef data_H
#define data_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Site{
char name[50];
 char username[20];
 char password[20];
}Site;

Site makeSite(char name[],char username[],char pass[]);
char *genererPass(int size);
void printSite(Site s);

#endif
