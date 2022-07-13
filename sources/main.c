#include <stdio.h>
#include <stdlib.h>
#include "siteOps.h"
#include "userList.h"
#include "user.h"
#include "Systeme.h"
#include "accounts.h"
#include "fileOp.h"
/*
Mes salutations a vous tres chers utilisateurs,
 Ceci est un Systeme comportant de plusieurs utilisateurs
 il y'a deux categories d'Utilisateurs
-Utilisateur simple
-Administrateur

Un utilisateur peut effectuer les operations suivantes
-Creer une connexion a un site et generer un mot de passe aleatoire d'une longueur donner
-Voir toutes les combinaisons nom d'Utilisateur-MotDePasse des differents sites
-Supprimer un site
-Modifier les informations du compte comme le mot de passe et le nom d'utilisateur
*/
int main()
{
FILE* in=NULL;

char SysFile[20]="SystemDB";
SystemPtr Sys=NULL;
int choix=1;

  systemMenu();//Procedure qui affiche le menu du systeme
  Sys=readSys(SysFile,Sys);
  /*afficherInfo(Sys);*/
  printf("#---Entrer votre choix : ");
  scanf("%d",&choix);

   do{
     switch(choix){

  case 1:Sys=addUser(Sys);//fonction qui ajoute un utilisateur a notre systeme
         strcpy(Sys->fileName,Sys->U.name);
         strcat(Sys->fileName,"DB");//cree un fichier ayant le nom de l'utilisateur concatener au mot DB
         //qui sera utiliser pour contenir toutes les donnees des differents sites de l'utilisateur
         emptyFile(in,SysFile);//procedure qui vide le contenu du fichier pour eviter la redundance des donnees
         addFileSys(SysFile,Sys);//procedure qui ajoute le contenu de la liste dans le fichier
         break;

  case 2:Sys=readSys(SysFile,Sys);//fonction qui lis le contenu du fichier dans la liste
         Sys=connectionAccount(Sys);//fonction qui effectue une connexion a notre systeme

         break;
  case 3:printf("FERMETURE DU SYSTEME REUSSIE !!!\n");
         break;

        }

        systemMenu();
  printf("#---Entrer votre choix : ");
  scanf("%d",&choix);
  }while(choix!=0);
  free(Sys);
    return 0;
}
