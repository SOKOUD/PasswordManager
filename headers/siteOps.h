#ifndef data_H
#define data_H
#define MAX 1000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Site{
char name[MAX];
 char username[MAX];
 char password[MAX];
}Site;

Site makeSite(char name[],char username[],char pass[]);
char *genererPass(int size);
void printSite(Site s);

#endif
