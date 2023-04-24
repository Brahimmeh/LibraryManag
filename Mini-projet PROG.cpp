#include<stdio.h>
#include<string.h>
//biblio pour variables boolean//
#include<stdbool.h>
//declaration des structures//
struct date {
	int j,m,a;
};

struct Bouquin{
	char RefBouquin[50], Nom[50];
	float Prix; 
};

typedef struct {
	char Refbibliothecaire[50],Nom[50], Prenom[50],AdresseEmail[50];
                              
}Bibliothecaire;

struct Client {
	char RefClient[50];
	date Datedupret[100];
    Bouquin Bouquinprte[100]; 
    int NB;
                
};
int main() {
//declaration des variables//
char g;
Client c[100],ic;
Bouquin bo[100],ibo;
Bibliothecaire bi[100],ibi;
int i=0,j=0,a,chx,s,y,e,Bo=0,Bi=0,C=0,k=0,B=0,R;
char x,refbo[50],refbi[50],refc[50],iBouquinprte[50];
bool v=true,exist,exist1;
printf("Bienvenue dans le programme du gestion de la Bibliotheque \n");	
do{
	
	
	do{  //affichage du menu//
	    printf("--------------------------------------------------------------MENU---------------------------------------------------- \n\n");
		printf("\t1- Ajouter un Bouquin \n");
		printf("\t2- Modifier un Bouquin  \n");
		printf("\t3- Supprimer un Bouquin  \n");
		printf("\t4- Afficher un Bouquin  \n");
		printf("\t5- Ajouter un Biblothecaire  \n");
		printf("\t6- Modifier un Bibliothecaire \n");
		printf("\t7- Supprimer un Bibliothecaire \n");
		printf("\t8- Afficher un Bibliothecaire  \n");
		printf("\t9- Ajouter un Client  \n");
		printf("\t10- Modifier un Client  \n");
		printf("\t11- Supprimer un Client  \n");
		printf("\t12- Afficher un Client  \n");
		//saisie du choix//
		printf("\t\t\t\t\t\t\t\t\t\t\tEntrez un choix valide :  \n");
		printf("\t\t\t\t\t\t\t\t\t\t\t");
		scanf("%d",&a);
		printf("\n\n-------------------------------------------------------------------------------------------------------------------- \n");
		//verfication du choix//
		if(a<1 || a >12 )
		{printf("\tveuillez entrer un choix valid (1-12)!!!!! \n");
		 v=false;
		
		}
		else {v=true;
		//cas de saisie d'un nombre de type float//
		chx=int(a);}
	}while(v==false);
//traitement//

switch(chx){
	case 1 : { do{
	            do {   exist=false;
				       printf("entrer la reference du nouveau Bouquin : \n");
	                   fflush(stdin);
	                   gets(refbo);
	                   for(e=0;e<Bo;e++)
	                   { if(strcmp(refbo,bo[e].RefBouquin)==0)
	                     { exist=true;
	                       printf("ce reference deja utilise pour un autre Bouquin veuillez le rentrer\n");
	                       break;
						 }
					   }}while(exist==true);
			   strcpy(bo[Bo].RefBouquin,refbo);
	           printf("entrer le nom du nouveau Bouquin : \n");
	           fflush(stdin);
	           gets(bo[Bo].Nom);
	           printf("entrer le prix du nouveau Bouquin : \n");
	           scanf("%f" ,&bo[Bo].Prix);
	           Bo++;
	           
			   do{
			   printf("voulez-vous ajouter un autre Bouquin ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			   if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			    }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
	           break;
			 }
	case 2 : { 
		       do{exist=false;
	           if(Bo==0)
	           {printf("il n y a aucune informations correspondants aux Bouquins dans ce programme veuillez ajouter les Bouquins en choissisant le choix numero 1 \nMerci \n");
	            
	            break;
			   }
			   else{
	           printf("entrer la reference du Bouquin a modifiee : \n");
	           fflush(stdin);
	           gets(ibo.RefBouquin);
	           for(i=0;i<Bo;i++){
	           if(strcmp(ibo.RefBouquin,bo[i].RefBouquin)==0)
	           { printf("entrer le nouveau nom du Bouquin de reference (%s) \n",ibo.RefBouquin);
	             fflush(stdin);
				 gets(bo[i].Nom);
	             printf("entrer le nouveau prix du Bouquin de reference (%s) \n",ibo.RefBouquin);
	             scanf("%f" ,&bo[i].Prix);
				 exist=true;
	             break;
	             
			   }}
			   if(exist==false)
			   printf("le bouquin n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
			   do{
			   printf("voulez-vous modifier un autre Bouquin ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
		       break;
	          }
	case 3 :{ do{exist=false;
		     if(Bo==0)
	           {printf("il n y a aucune informations correspondants aux Bouquins dans ce programme veuillez ajouter les Bouquins en choissisant le choix numero 1 \nMerci \n");
	            
	            break;
			   }
			   else{
	          printf("entrer la reference du Bouquin a supprime : \n");
	          fflush(stdin);
	          gets(ibo.RefBouquin);
		      for(i=0;i<Bo;i++){
	           if(strcmp(ibo.RefBouquin,bo[i].RefBouquin)==0)
			   {
	           	for(s=i;s<Bo-1;s++)
	           	{ bo[s]=bo[s+1];
				}
				Bo--;
				printf("le Bouquin a ete supprime avec succes \n");
				exist=true;
	           	break;}
		         }
			   if(exist==false)
			   printf("le bouquin n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
			  do{
			  printf("voulez-vous supprimer un autre Bouquin ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			  fflush(stdin);
			  scanf("%c" ,&x);
			   if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
	          break;
	        }
	case 4 :{ do{exist=false;
		      if(Bo==0)
	           {printf("il n y a aucune informations correspondants aux Bouquins dans ce programme veuillez ajouter les Bouquins en choissisant le choix numero 1 \nMerci \n");
	            
	            break;
			   }
			   else{
	          printf("entrer la reference du Bouquin a affiche : \n");
	          fflush(stdin);
	          gets(ibo.RefBouquin);
		      for(i=0;i<Bo;i++){
	           if(strcmp(ibo.RefBouquin,bo[i].RefBouquin)==0){
	           	printf("les informations correspondantes au Boquin du reference \" %s \" sont : \n ",ibo.RefBouquin);
	           	printf("le nom du Bouquin : \" %s \" \n",bo[i].Nom);
	           	printf("le prix du Bouquin :  %.2f DH \n",bo[i].Prix);
	           	exist=true;
				break;}}
			if(exist==false)
			   printf("le bouquin n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
	        do{
			printf("voulez-vous afficher un autre Bouquin ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			  fflush(stdin);
			  scanf("%c" ,&x); 
			   if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			    }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
	          break;
	        }
	case 5 : { do{
	            do {   exist=false;
				       printf("entrer la reference du nouveau Biblothecaire : \n");
	                   fflush(stdin);
	                   gets(refbi);
	                   for(e=0;e<Bi;e++)
	                   { if(strcmp(refbi,bi[e].Refbibliothecaire)==0)
	                     { exist=true;
	                       printf("ce reference deja utilise pour un autre Biblothecaire veuillez le rentrer\n");
	                       break;
						 }
					   }}while(exist==true);
			   strcpy(bi[Bi].Refbibliothecaire,refbi);
	           printf("entrer le nom du nouveau Biblothecaire : \n");
	           fflush(stdin);
	           gets(bi[Bi].Nom);
	           printf("entrer le Prenom du nouveau Biblothecaire : \n");
	           fflush(stdin);
	           gets(bi[Bi].Prenom);
	           printf("entrer l'AdresseEmail du nouveau Biblothecaire : \n");
	           fflush(stdin);
	           gets(bi[Bi].AdresseEmail);
	           Bi++;
			   do{
			   printf("voulez-vous ajouter un autre Biblothecaire ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
	           break;
			}
	case 6 : { do{exist=false;
		        if(Bi==0)
	           {printf("il n y a aucune informations correspondants aux Biblothecaires dans ce programme veuillez ajouter les Biblothecaires en choissisant le choix numero 5 \nMerci \n");
	            
	            break;
			   }
			   else{
	           printf("entrer la reference du Biblothecaire a modifiee : \n");
	           fflush(stdin);
	           gets(ibi.Refbibliothecaire);
	           for(j=0;j<Bi;j++){
	           if(strcmp(ibi.Refbibliothecaire,bi[j].Refbibliothecaire)==0)
	           { printf("entrer le nouveau nom du Biblothecaire de reference (%s) \n",ibi.Refbibliothecaire);
	             fflush(stdin);
				 gets(bi[j].Nom);
	             printf("entrer le nouveau Prenom du Biblothecaire de reference (%s) \n",ibi.Refbibliothecaire);
	             fflush(stdin);
	             gets(bi[j].Prenom);
	             printf("entrer la nouvelle AdresseEmail du Biblothecaire de reference (%s) \n",ibi.Refbibliothecaire);
	             fflush(stdin);
	             gets(bi[j].AdresseEmail);
	             exist=true;
	        
	             break;
			   }}
			   if (exist == false)
			   printf("le Biblothecaire n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
			   do{
			   printf("voulez-vous modifier un autre Biblothecaire ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
		       break;
	          }
	case 7 :{ do{exist=false;
		      if(Bi==0)
	           {printf("il n y a aucune informations correspondants aux Biblothecaires dans ce programme veuillez ajouter les Biblothecaires en choissisant le choix numero 5 \nMerci \n");
	            
	            break;
			   }
			   else{
	          printf("entrer la reference du Biblothecaire a supprime : \n");
	          fflush(stdin);
	          gets(ibi.Refbibliothecaire);
		      for(j=0;j<Bi;j++){
	           if(strcmp(ibi.Refbibliothecaire,bi[j].Refbibliothecaire)==0)
	             {
	           	for(s=j;s<Bi-1;s++)
	           	{ bi[s]=bi[s+1];
				}
				Bi--;
				exist=true;
				printf("le Biblothecaire a ete supprime avec succes \n");
	           	break;
			   }}
			if(exist == false)
			   printf("le Biblothecaire n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
			  do{
			  printf("voulez-vous supprimer un autre Biblothecaire ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			  fflush(stdin);
			  scanf("%c" ,&x);
			   if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
	          break;
	        }
	case 8 :{ do{exist=false;
		      if(Bi==0)
	           {printf("il n y a aucune informations correspondants aux Biblothecaires dans ce programme veuillez ajouter les Biblothecaires en choissisant le choix numero 5 \nMerci \n");
	            
	            break;
			   }
			   else{
	          printf("entrer la reference du Biblothecaire a affiche : \n");
	          fflush(stdin);
	          gets(ibi.Refbibliothecaire);
		      for(j=0;j<Bi;j++){
	           if(strcmp(ibi.Refbibliothecaire,bi[j].Refbibliothecaire)==0){
	           	printf("les informations correspondantes au Biblothecaire du reference \" %s \" sont : \n ",ibi.Refbibliothecaire);
	           	printf("le Nom du Biblothecaire : \" %s \" \n",bi[j].Nom);
	           	printf("le Prenom du Biblothecaire : \" %s \" \n",bi[j].Prenom);
	           	printf("l'AdresseEmail du Biblothecaire : \" %s \" \n",bi[j].AdresseEmail);
	           	exist=true;
	            break;}}
				 if(exist == false)
			   printf("le Biblothecaire n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
	        do{
			printf("voulez-vous afficher un autre Biblothecaire ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			fflush(stdin);
			scanf("%c" ,&x);
			 if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			    }while(x!='n' && x!='N');
	          break;
	        }
	case 9 : { do{B=0;c[C].NB=0;
	          do {   exist=false;
				       printf("entrer la reference du nouveau/elle Client(e) : \n");
	                   fflush(stdin);
	                   gets(refc);
	                   for(e=0;e<C;e++)
	                   { if(strcmp(refc,c[e].RefClient)==0)
	                     { exist=true;
	                       printf("ce reference deja utilise pour un(e) autre Client(e) veuillez le rentrer\n");
	                       break;
						 }
					   }}while(exist==true);
			   strcpy(c[C].RefClient,refc);
			 do{ exist1=false; 
	           printf("entrer la reference du Bouquin pris  N %d du Client de reference (%s) \n",B+1,c[C].RefClient);
	           fflush(stdin);
	           gets(c[C].Bouquinprte[B].RefBouquin);
	           
	         
			     for(i=0;i<Bo;i++)
	           {
			    if(strcmp(bo[i].RefBouquin,c[C].Bouquinprte[B].RefBouquin)==0)
	             { strcpy(c[C].Bouquinprte[B].Nom , bo[i].Nom);
	               c[C].Bouquinprte[B].Prix=bo[i].Prix;
	               printf("ce Bouquin deja exist dans ce programme, ces informations vont etre attribue a ce client \n");
	               exist1=true;
	               break;
				 }}
			   if(exist1==false ){
			   printf("ce bouquin n'existe pas dans la bibliotheque ! veuillez saisir ses informations (Ce dernier sera ajoutee a les autres Bouquins de ce programme )\n");
	           printf("---> entrer le nom du Bouquin pris N %d du Client de reference (%s) \n",B+1,c[C].RefClient);
	           fflush(stdin);
	           gets(c[C].Bouquinprte[B].Nom);
	           printf("---> entrer le prix du Bouquin pris N %d du Client de reference (%s) \n",B+1,c[C].RefClient);
	           scanf("%f" ,&c[C].Bouquinprte[B].Prix);
	           strcpy(bo[Bo].RefBouquin,c[C].Bouquinprte[B].RefBouquin);
	           strcpy(bo[Bo].Nom,c[C].Bouquinprte[B].Nom);
	           bo[Bo].Prix = c[C].Bouquinprte[B].Prix;
	           Bo++;
	        
			   }
	          do{y=0;
			   printf("entrer la date du pret du Bouquin N %d (jj/mm/aa) veuillez separer les nombres avec des '/': \n",B+1);
	          R= scanf("%d/%d/%d" ,&c[C].Datedupret[B].j,&c[C].Datedupret[B].m,&c[C].Datedupret[B].a);
	           if(c[C].Datedupret[B].j<1 || c[C].Datedupret[B].j>31 || c[C].Datedupret[B].m<1 || c[C].Datedupret[B].m>12 || c[C].Datedupret[B].a<1000 ||
			    (c[C].Datedupret[B].j>30 && (c[C].Datedupret[B].m==2 || c[C].Datedupret[B].m==4 || c[C].Datedupret[B].m==6 || c[C].Datedupret[B].m==9 ||c[C].Datedupret[B].m==11)) 
				|| (c[C].Datedupret[B].m==2 && c[C].Datedupret[B].j==29 && (c[C].Datedupret[B].a % 400 !=0 && c[C].Datedupret[B].a % 4 !=0 || c[C].Datedupret[B].a % 100 ==0)  )
				|| (c[C].Datedupret[B].m==2 && c[C].Datedupret[B].j>29) || R!=3 )
	           {
			   printf("veuillez entrer une date valide !!! \n");
	           y=1;}
	           
	          }while(y==1);
	          B++;
	          	do{
			   printf("voulez-vous ajouter un autre Bouquin pour ce/cette Client(e) ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
	          
	          }while (x !='o' && x !='O' && x !='n' && x !='N');
			   
	           }while(x!='n' && x!='N');
	           c[C].NB = B;
	           C++;
			   do{
			   printf("voulez-vous ajouter un(e) autre Client(e) ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
	           break;
			}
	case 10 : { do{exist=false;
		       if(C==0)
	           {printf("il n y a aucune informations correspondants aux Clients dans ce programme veuillez ajouter les Clients en choissisant le choix numero 9 \nMerci \n");
	            break;
			   }
			   else{
	           printf("entrer la reference du Client(e) a modifie : \n");
	           fflush(stdin);
	           gets(ic.RefClient);
	           
	           for(k=0;k<C;k++){
	           if(strcmp(ic.RefClient,c[k].RefClient)==0)
	           {exist=true;
	       do{   exist1=false;
		         printf("entrer la reference du Bouquin a modifie pour le Client de reference (%s) \n",c[k].RefClient);
		         fflush(stdin);
	             gets(iBouquinprte);
                for(B=0;B<c[k].NB;B++){
				if(strcmp(iBouquinprte,c[k].Bouquinprte[B].RefBouquin)==0){
			   printf("entrer le nouveau nom du Bouquin pris(e) du ref: \" %s \" par client(e) de reference (%s) \n",c[k].Bouquinprte[B],c[k].RefClient);
	           fflush(stdin);
	           gets(c[k].Bouquinprte[B].Nom);
	           printf("entrer le nouveau prix du Bouquin pris(e) du ref: \" %s \" par client(e) de reference (%s) \n",c[k].Bouquinprte[B],c[k].RefClient);
	           scanf("%f" ,&c[k].Bouquinprte[B].Prix);
	           exist1=true; break;}}

			   if(exist1==false ){
			   	strcpy(c[k].Bouquinprte[B].RefBouquin,iBouquinprte);
			   for(i=0;i<Bo;i++)
	           {
			    if(strcmp(bo[i].RefBouquin,iBouquinprte)==0)
			     
	             { 
				  strcpy(c[k].Bouquinprte[B].Nom , bo[i].Nom);
	               c[k].Bouquinprte[B].Prix=bo[i].Prix;
	               printf("ce Bouquin deja exist dans ce programme, ces informations vont etre attribue a ce client \n");
	               exist1=true;
	               c[k].NB++;
	               break;
	               
				 }}
			   if(exist1==false ){
			   
			   printf("ce bouquin n'existe pas dans la bibliotheque ! veuillez saisir ses informations (Ce dernier sera ajoutee a les autres Bouquins de ce programme )\n");
	           printf("---> entrer le nom du nouveau Bouquin pris du Client de reference (%s) \n",c[k].Bouquinprte[B].RefBouquin);
	           fflush(stdin);
	           gets(c[k].Bouquinprte[B].Nom);
	           printf("---> entrer le prix du nouveau Bouquin pris du Client de reference (%s) \n",c[k].Bouquinprte[B].RefBouquin);
	           scanf("%f" ,&c[k].Bouquinprte[B].Prix);
	           strcpy(bo[Bo].Nom,c[k].Bouquinprte[B].Nom);
	           bo[Bo].Prix = c[k].Bouquinprte[B].Prix;
	           strcpy(bo[Bo].RefBouquin,iBouquinprte);
	           Bo++;
	           c[k].NB++;
			  }}

	          do{y=0;
			   printf("entrer la nouvelle date du pret du Bouquin du ref: \" %s \" par client(e) de reference (%s) \" (jj/mm/aa) veuillez separer les nombres avec des '/': \" \n ",c[k].Bouquinprte[B],c[k].RefClient);
	          R= scanf("%d/%d/%d" ,&c[k].Datedupret[B].j,&c[k].Datedupret[B].m,&c[k].Datedupret[B].a);
	        
	         if(c[k].Datedupret[B].j<1 || c[k].Datedupret[B].j>31 || c[k].Datedupret[B].m<1 || c[k].Datedupret[B].m>12 || c[k].Datedupret[B].a<1000 ||
			    (c[k].Datedupret[B].j>30 && (c[k].Datedupret[B].m==2 || c[k].Datedupret[B].m==4 || c[k].Datedupret[B].m==6 || c[k].Datedupret[B].m==9 ||c[k].Datedupret[B].m==11)) 
				|| (c[k].Datedupret[B].m==2 && c[k].Datedupret[B].j==29 && (c[k].Datedupret[B].a % 400 !=0 && c[k].Datedupret[B].a % 4 !=0 || c[k].Datedupret[B].a % 100 ==0)  )
				|| (c[k].Datedupret[B].m==2 && c[k].Datedupret[B].j>29)  || R!=3)
	           {
			   printf("veuillez entrer une date valide !!! \n");
	           y=1;}
	           
	          }while(y==1);
	          
	          do{
			   printf("voulez-vous modifier un autre Bouquin pour ce/cette Client(e) ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   
	           }while(x!='n' && x!='N');
	           break;
	          
			}}  
			    if(exist==false)
			   printf("le Client(e) n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");
			  do{
			   printf("voulez-vous modifier un(e) autre Client(e) ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			   }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }}while(x!='n' && x!='N');
		       break;
	          }
	case 11 : { do{exist=false;
		        if(C==0)
	           {printf("il n y a aucune informations correspondants aux Clients dans ce programme veuillez ajouter les Clients en choissisant le choix numero 9 \nMerci \n");
	            
	            break;
			   }
			   else{
	           printf("entrer la reference du Client(e) a supprime(e) : \n");
	           fflush(stdin);
	           gets(ic.RefClient);
	           for(k=0;k<C;k++){
	           if(strcmp(ic.RefClient,c[k].RefClient)==0)
	           {  
	            	for(s=k;s<C-1;s++)
	           	{ c[s]=c[s+1];
				}
				C--;
	           printf("le Client(e) a ete supprime(e) avec succes \n");
	           
	           exist=true;
	        
	             break;
			   }}
			   if( exist==false)
			   printf("le Client(e) n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");
			   }
			   do{
			   printf("voulez-vous supprimer les informations d'un(e) autre Client(e) ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			    }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
		       break;
	          }
	case 12 : { do{exist=false;
		        if(C==0)
	           {printf("il n y a aucune informations correspondants aux Clients dans ce programme veuillez ajouter les Clients en choissisant le choix numero 9 \nMerci \n");
	            
	            break;
			   }
			   else{
			   	 
	           printf("entrer la reference du Client(e) a affiche(e) : \n");
	           fflush(stdin);
	           gets(ic.RefClient);
	           for(k=0;k<C;k++){
	           	
	           if(strcmp(ic.RefClient,c[k].RefClient)==0)
	           {
	           printf("------>les informations correspondants(es) au Client(e) de reference \" %s \" sont : \n ",ic.RefClient);
	           for(B=0;B<c[k].NB;B++){
			   
	           printf("--->la reference du Bouquin pris N %d est : \" %s \" \n",B+1,c[k].Bouquinprte[B].RefBouquin);
	           printf("le nom du Bouquin pris N %d est : \" %s \" \n",B+1,c[k].Bouquinprte[B].Nom);
	           printf("le prix du Bouquin pris N %d est : %.2f \n",B+1,c[k].Bouquinprte[B].Prix);
	           printf("la date du pret du Bouquin  N %d est : %d/%d/%d \n ",B+1,c[k].Datedupret[B].j,c[k].Datedupret[B].m,c[k].Datedupret[B].a);
	           exist=true;
	             
			   }}}
			   if(exist == false)
			   printf("le Client(e) n'existe pas dans les donnes de la bibliotheque veuillez l'ajouter\n");}
			   do{
			   printf("voulez-vous afficher un(e) autre Client(e) ? (taper 'o' ou 'O' pour accepter et 'n' ou 'N' pour refuser )\n");
			   fflush(stdin);
			   scanf("%c" ,&x);
			    if(x !='o' && x !='O' && x !='n' && x !='N')
			   printf("le choix invalide !!! \n");
			    }while (x !='o' && x !='O' && x !='n' && x !='N');
			   }while(x!='n' && x!='N');
		       break;
	          }

}

do{
printf("voulez-vous faire un autre traitement ? (taper 'o' ou 'O' pour \" oui \" et 'n' ou 'N' pour \" non \")\n");
fflush(stdin);
scanf("%c" ,&g);
 if(g !='o' && g !='O' && g !='n' && g !='N')
			   printf("le choix invalide !!! \n");
			    }while (g !='o' && g !='O' && g !='n' && g !='N');

}while(g!='n' && g!='N');
//fin du programme//
printf("Merci,A toute a l'heure\n------------------------------------------------- FIN DU PROGRAMME --------------------------------------------------- \n\n");
return 0;
}
/*
Réalisé par :
MEHDAOUI Brahim - 1AP3
MOUKHTASSER Salma - 1AP3
BELMOKHTAR El Mehdi - 1AP3
*/
