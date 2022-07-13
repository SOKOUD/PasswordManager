#ifndef nav_H
#define nav_H
#include "siteOps.h"

//structure de donnees aui represente la liste de tous les sites
 typedef struct List{
  Site s;
  /*char fileName[50];*/
  struct List *next;
 }*ListPtr,List;

 ListPtr makeList(Site s);
 ListPtr initList(ListPtr head);
 ListPtr addList(ListPtr head);
 ListPtr searchList(ListPtr head,char nom[],char username[]);
 ListPtr deleteList(ListPtr head,char nom[],char username[]);
 ListPtr modifyList(ListPtr head,char nom[],char username[]);
 void printList(ListPtr head);
 ListPtr readFile(FILE* in,char name[],ListPtr head);
 void addFile(FILE* in,char name[],ListPtr head);
#endif // nav_H
