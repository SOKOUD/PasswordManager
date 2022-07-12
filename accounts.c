#include "accounts.h"
 char SysFile[20]="SystemDB";
//procedure qui affiche le menu du systeme
void systemMenu(){

  printf("##################-SYSTEME-#################\n");
  printf("#------------------------------------------#\n");
  printf("#  Nouvelle Session de connexion :         #\n");
  printf("#------------------------------------------#\n");
  printf("#  1. Creer un compte utilisateur          #\n");
  printf("#------------------------------------------#\n");
  printf("#  2. Connexion a un compte existant       #\n");
  printf("#------------------------------------------#\n");
  printf("#------------------------------------------#\n");
}
//procedure qui affiche le menu d'un utilisateur
void userMenu(char name[]){
 printf("\n\n\n\n");
          printf("##################-Bienvenu %s -##################\n",name);
          printf("#------------------------------------------------#\n");
          printf("#1. Creer une connexion a un site en generant    #\n");
          printf("#   un mot de passe aleatoire                    #\n");
          printf("#------------------------------------------------#\n");
          printf("#2. Voir tout les combinaisons nom d'Utilisateur #\n");
          printf("#   Mot de Passe de tous les sites               #\n");
          printf("#------------------------------------------------#\n");
          printf("#3. Supprimer un site                            #\n");
          printf("#------------------------------------------------#\n");
          printf("#4. Modifier les informations du compte          #\n");
          printf("#------------------------------------------------#\n");
          printf("#5. Modifier les informations d'un site          #\n");
          printf("#------------------------------------------------#\n");
          printf("#6. Deconnexion                                  #\n");
          printf("#------------------------------------------------#\n");
          printf("#------------------------------------------------#\n");

}



//fonction qui initialise une connexion a un compte
SystemPtr connectionAccount(SystemPtr Sys){
SystemPtr utilis;
FILE* in=NULL;
char name[20],pass[20],temp[20];


int ans=1,n=1;
         printf("Choisisez un compte : \n");
         printf("Entrer votre nom d'Utilisateur : ");
         scanf("%s",name);
         printf("Entrer votre mot de passe : ");
         scanf("%s",pass);
         utilis=searchUser(Sys,name,pass);//recherche de l'utilisateur
         if(utilis==NULL){
          printf("Mot de Passe Incorrect !! ou utilisateur inexistant!!\n\n");
         }
         else{

          userMenu(utilis->U.name);
          printf("#---Entrer votre choix : ");
          scanf("%d",&ans);
            do{
             switch(ans){

              case 1:utilis->U.l=readFile(in,utilis->fileName,utilis->U.l);
                     utilis->U.l=addList(utilis->U.l);//ajout d'un site
                     emptyFile(in,utilis->fileName);
                     addFile(in,utilis->fileName,utilis->U.l);
                     printf("#--Site ajouter avec Success !!-#\n");
                     break;
              case 2:utilis->U.l=readFile(in,utilis->fileName,utilis->U.l);
                     printList(utilis->U.l);//affichage de la liste de tous les sites
                     break;
              case 3:printf("Entrer le nom du site : ");
                     scanf("%s",name);
                     printf("Entrer le nom d'Utilisateur: ");
                     scanf("%s",pass);
                     utilis->U.l=deleteList(utilis->U.l,name,pass);//suppression d'un site
                     emptyFile(in,utilis->fileName);
                     addFile(in,utilis->fileName,utilis->U.l);
                     printf("#--Site supprimer avec success !!--#\n");
                     break;
              case 4:strcpy(temp,utilis->fileName);
                     utilis=modifyUser(utilis);//modification des informations relative au compte
                     n=rename(temp,utilis->fileName);//renommer le fichier contenant toutes les infos
                     //sur les sites de l'utilisateur avec son nouveau nom
                     emptyFile(in,SysFile);//vidage du fichier sur le systeme
                     addFileSys(SysFile,Sys);//ajouter la liste des utilisateurs dans le fichier

                     break;
              case 5:printf("Entrer le nom du site : ");
                     scanf("%s",name);
                     printf("Entrer le nom d'utilisateur : ");
                     scanf("%s",pass);
                     utilis->U.l=modifyList(utilis->U.l,name,pass);
                     emptyFile(in,utilis->fileName);
                     addFile(in,utilis->fileName,utilis->U.l);
                     break;

             }
             userMenu(utilis->U.name);//affichage du menu
             printf("#---Entrer votre choix : ");
          scanf("%d",&ans);
            }while(ans!=6);
         }
         return Sys;
}

