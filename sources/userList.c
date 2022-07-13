#include "userList.h"
//fonction qui cree un noeud de notre list apartir d'un site
ListPtr makeList(Site s){
 ListPtr np=(ListPtr)malloc(sizeof(List));
 np->s=s;
 np->next=NULL;

 return np;
}

 //fonction qui ajoute un site dans une liste
ListPtr addList(ListPtr head){
 char name[50],username[20],pass[20];
 Site s;
 int t;
 ListPtr np;
 printf("Entrer le nom du site : ");
 scanf("%s",name);
 printf("Entrer le nom d'Utilisateur : ");
 scanf("%s",username);
 printf("Entrer la taille du mot de passe : ");
 scanf("%d",&t);
 strcpy(pass,genererPass(t));//genere un mot de passe aleatoire de longueur t
 printf("\n");
 s=makeSite(name,username,pass);
 np=makeList(s);
 np->next=head;
 head=np;

 return head;

}
//fonction qui recherche un site  pour un utilisateur ayant un nom username et le nom du site a rechercher nom
ListPtr searchList(ListPtr head,char nom[],char username[]){
  ListPtr curr=head;

  while(curr!=NULL){
  if(strcmp(curr->s.name,nom)==0 && strcmp(curr->s.username,username)==0)
  {
  return curr;
  break;
  }
  curr=curr->next;
  }
}

//fonction qui supprime un site de la liste
ListPtr deleteList(ListPtr head,char nom[],char username[]){
  ListPtr curr=head;
  ListPtr old;
  while(curr!=NULL && strcmp(curr->s.name,nom)!=0 && strcmp(curr->s.username,username)!=0){
  old=curr;
  curr=curr->next;
  }
 old->next=curr->next;
 free(curr);
  return head;
}
//fonction qui moodifie les informations d'un site
ListPtr modifyList(ListPtr head,char nom[],char username[]){
 ListPtr np;
 /* while(curr!=NULL){
  if(strcmp(curr->s.name,nom)!=0 && strcmp(curr->s.username,username)!=0){
  np=curr;
  break;
  }
  curr=curr->next;
  }*/
  np=searchList(head,nom,username);
  printf("%s %s %s\n",np->s.name,np->s.username,np->s.password);
  printf("Entrer le nouveau nom du site : ");
 scanf("%s",np->s.name);
 printf("Entrer le nom d'Utilisateur : ");
 scanf("%s",np->s.username);
 printf("Entrer le mot de Passe : ");
 scanf("%s",np->s.password);

 return head;
}

//fonction qui affiche la liste des sites
 void printList(ListPtr head){
  ListPtr curr=head;
  while(curr!=NULL){
  printSite(curr->s);

  printf("\n\n");
  curr=curr->next;
  }
 }
//fonction qui lis le contenu du fichier dans la liste
 ListPtr readFile(FILE* in,char name[],ListPtr head){
 char n[50],p[50],q[50];
 /*
 n represente le nom du site
 p represente le nom d'utilisateur
 q represente le mot de passe
 */
  ListPtr np;
  head=NULL;
  ListPtr last=(ListPtr)malloc(sizeof(List));
  in=fopen(name,"r");
  if(in==NULL){
   return NULL;
  }
 else{
  while(fscanf(in,"%s %s %s",n,p,q)!=EOF){

    np=makeList(makeSite(n,p,q));//on cree un noeud de notre liste a partir de chaque ligne du fichier
    //pour l'inserer dans notre liste
    if(head==NULL){
     head=last=np;
    }
    else{
     last->next=np;
     last=np;
    }
   }
   fclose(in);
 return head;
 }

 }

 //procedure qui sauveguarde le contenu de notre liste dans un fichier
 void addFile(FILE* in,char name[],ListPtr head){
  in=fopen(name,"a");
  ListPtr curr=head;
  if(in==NULL){
   printf("Erreur sur le fichier !!!\n");
 }
  while(curr!=NULL){
    fprintf(in,"%s %s %s\n",curr->s.name,curr->s.username,curr->s.password);
    curr=curr->next;

  }
  fclose(in);
}
