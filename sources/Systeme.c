#include "Systeme.h"

//fonction qui cree un noeud de notre systeme apartir d'un utilisateur
SystemPtr makeSystem(User U){
 SystemPtr np=(SystemPtr)malloc(sizeof(Systeme));
 np->U=U;
 np->next=NULL;

 return np;
}

//fonction qui ajoute un utilisateur a notre systeme
SystemPtr addUser(SystemPtr head){
 User U;
SystemPtr np;
char name[50],pass[20];

printf("Entrer le nom d'Utilisateur : ");
 scanf("%s",name);

 printf("Entrer le mot de Passe : ");
 scanf("%s",pass);
 printf("\n");
 U=makeUser(name,pass);
 np=makeSystem(U);
 np->next=head;
 head=np;

 return head;
}

//fonction qui recherche un utilisateur du systeme
SystemPtr searchUser(SystemPtr head,char username[],char password[]){
 SystemPtr curr=head;

  while(curr!=NULL){
  if(strcmp(curr->U.name,username)==0 && strcmp(curr->U.password,password)==0){
  return curr;
  break;
  }
   curr=curr->next;
  }

}



//fonction qui modifie un utlisateur du systeme
SystemPtr modifyUser(SystemPtr curr){
  curr->U=modifyInfo(curr->U);
  strcpy(curr->fileName,curr->U.name);
  strcat(curr->fileName,"DB");
  /*strcpy(curr->password,curr->U.password);*/
return curr;
}


void printInfo(SystemPtr head){
  SystemPtr curr=head;
  char type[20];
  int i=1;
   strcpy(type,"User");
   while(curr!=NULL){

    printf("######-Account %d-######\n",i);
    printf("#----------------------#\n");
    printf("#-Username     :    %s #\n",curr->U.name);
    printf("#-Account type :    %s #\n",type);
    printf("#----------------------#\n");
    curr=curr->next;
    i++;
   }
}

SystemPtr readSys(char name[],SystemPtr head){
 char n[50],p[50],q[50];
  SystemPtr np;
  head=NULL;
  SystemPtr last=(SystemPtr)malloc(sizeof(Systeme));
  FILE* in=fopen(name,"r");

  if(in==NULL){
    return NULL;
  }
  else{
   while(fscanf(in,"%s %s %s",n,p,q)!=EOF){
    np=makeSystem(makeUser(n,p));
    strcpy(np->fileName,q);
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

 void addFileSys(char name[],SystemPtr head){
  FILE* in=fopen(name,"a");
  SystemPtr curr=head;
  if(in==NULL){
   printf("Erreur sur le fichier !!!\n");
 }
  while(curr!=NULL){
    fprintf(in,"%s %s %s\n",curr->U.name,curr->U.password,curr->fileName);
    curr=curr->next;

  }
  fclose(in);
}
