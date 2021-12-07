#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

<<<<<<< HEAD
int RETOUR()
{
    int choix3;
do {

    printf("Appuyez sur 0 pour retourner au menu aide.\n");
    scanf("%d",&choix3);}
    while (choix3!=0);
    return(choix3);}




void gotoligcol( int lig, int col )
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}



void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);

}
=======
/*------------------------------------------------------------------S T R U C T U R E S--------------------------------------------------------------------------------------------------------------------------------*/
>>>>>>> b1f0c7ebe336e3a1de6d802060a0ba07ab66fc64

typedef struct plateau
{
    int occupant; // Ne sert à rien pr l'instant
}t_plateau;

typedef struct position
{
    int x;
    int y;

}t_position;


typedef struct joueur
{ //ll
    char nom[50];
    int couleur;
    int *score;
    int *nmbrMur;
    int *nmbrMurres;
    char sigle;
    t_position emplacement;

}t_joueur;
void coter(int a,t_joueur T[a])
{
    gotoligcol(1,65);Color(15,0);printf("Nombres de joueurs : %d",a);
    gotoligcol(3,65); printf("               ");gotoligcol(3,65);Color(15,0);printf("Joueur : "); Color(T[a].couleur,0); printf("%s", T[a].nom);
    gotoligcol(5,65);Color(15,0);printf("Score partie : %d", T[a].score);
    gotoligcol(7,65);Color(15,0);printf("Jeton : "); Color(T[a].couleur,0); printf("%c", T[a].sigle);
    gotoligcol(9,65);Color(15,0);printf("Barrieres restantes : ");Color(T[a].couleur,0); printf("%d", T[a].nmbrMurres);

}


typedef struct positionm
{
    int x1, x2;
    char y1;
    char y2;

}t_positionm;

/*--------------------------------------------------------------F I N   S T R U C T U R E S--------------------------------------------------------------------------------------------------------------------------------*/





void gotoligcol( int lig, int col )
{
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);

}




                                            /* Menu AIDE et RETOUR AU MENU PRINCIPAL */
 void Aide(int choix2)

 {
     int choix;
     switch(choix2)
     {
        case 1:
            system("cls");
            affichePlateau();
            printf("Les barrieres se mettent entre deux lignes ou deux colonnes. Leur longueur est de 2 cases. Elle est utilisee pour tracer son chemin ou ralentir son adversaire.\n Pour les positionner, il ne faut pas bloquer totalement le chemin de son adversaire. Le joueur saisira les coordonnees de 2 cases voisines et précisera si la barriere est mise en haut, en bas, a droite ou à gauche de ces cases : Voici un exemple de saisie\n case1 : D1\n case2 : D2\n position : G\n Cela positionnera la barriere à gauche des cases D1 et D2 sur le plateau.\n En cas d’impossibilite, le coup n’est pas pris en compte et le joueur rejoue.\n Elles sont representees par la lettre ‘B’ sur le plateau.\n");
            printf("                                0. Retour au menu aide                 \n");
            Aide(MenuAide(RETOUR()));
            break;
        case 2 :
            system("cls");
            affichePlateau();
            printf("Il y a 2 joueurs ou 4 joueurs possibles dans une partie (choix a faire avant de lancer la partie.)\n - tous les joueurs sont humains.\nLes joueurs jouent à tour de role tel que defini dans les regles. Chaque joueur saisi son nom. Leur ordre de jeu est defini par hasard. C’est le joueur1 qui commence.\nLe nom de chaque joueur sera stocke pour la partie. S il a deja joue et est connu alors il prendra son score precedemment sauvegarde.\nLe jeton du joueur sera choisi par le joueur parmis les caracteres suivants :\n %c %c %c %c %c %c %c %c %c\n %c %c %c %c %c %c %c %c %c\n",0x3F,0x23,0x26,0x40,0x25,0x24,0x0C,0x11,0x0B,0x02,0x03,0x04,0x05,0x0E,0xFE,0x06,0x0F,0x10);
            printf("Chaque joueur aura son symbole unique.\n ");
            printf("                                0. Retour au menu aide                \n");
            Aide(MenuAide(RETOUR()));
            break;
        case 3:
            system("cls");
            affichePlateau();
            printf("");
            printf("                                0. Retour au menu aide                 \n");
            Aide(MenuAide(RETOUR()));
            break;
        case 4 :
            system("cls");
            affichePlateau();
            printf("Il est possible d’interrompre la partie en cours. Dans ce cas la partie est sauvegardee dans un fichier. Elle pourra etre reprise ulterieurement. Ce sera alors la derniere partie interrompue qui sera chargee.\n");
            printf("                                0. Retour au menu aide                 \n");
            Aide(MenuAide(RETOUR()));
            break;
        case 5 :
            system("cls");
            affichePlateau();
            printf("Calcul des scores :\n - Chaque partie rapporte au gagnant 5 points. En cas de blocage, aucun point n’est attribue.\n - Dans les parties bonus, les cases primees rapportent au joueur le nombre de points indique. Ce sera ajoute à son score.\n");
            printf("                                0. Retour au menu aide                 \n");
            Aide(MenuAide(RETOUR()));
            break;
        case 6 :
            system("cls");
            affichePlateau();
            menup(menu());
            break;

        default :
            printf("Erreur!");
            break;


    }
 }
int RETOUR()
{
    int choix3;
do {

    printf("Appuyez sur 0 pour retourner au menu aide.\n");
    scanf("%d",&choix3);}
    while (choix3!=0);
    return(choix3);}


void affichePlateau(char *plateau)
{
    int x;


        for (x=0; x<9; x++)
        {

                printf("___ ___   ___   ___   ___   ___   ___   ___   ___   ___ \n");

                printf("_%d_|",x+1);
                printf("___| |___| |___| |___| |___| |___| |___| |___| |___|\n");

        }
        printf("   | A | | B | | C | | D | | E | | F | | G | | H | | I | \n");



}



int MenuAide()
{
    int choix2;
    char plateau[19][56];
    system("cls");
    affichePlateau(plateau);
    printf("        MENU AIDE       \n");
    printf("1. Les barrieres\n");
    printf("2. Les joueurs\n");
    printf("3. Se deplacer\n");
    printf("4.Intterompre la partie\n");
    printf("5. Calcul des scores\n");
    printf("6. Revenir au menu principal\n");
    do { printf("Sur quoi voulez-vous des renseignements?\n Saisir une action entre 1,2,3,4,5 ou 6 :\n");
         scanf("%d",&choix2);}
    while ((choix2>6) || (choix2<1));
    return (choix2);
}




int saisiejoueurs(int a,t_joueur *TableauJoueurs,t_positionm *TableauPositionMur)
{   int i=0;
    int choix6;
    char plateau[19][56];
    TableauJoueurs=malloc(a*sizeof(t_joueur));
    FILE *fichierJoueur=fopen("SauvegardeJoueurs.txt","a+");
    while (i<a)
    {
        system("cls");
        affichePlateau(plateau);
        printf("Veuillez saisir le nom du joueur\n");
        scanf("%s",&(TableauJoueurs[i].nom));
        fprintf(fichierJoueur,"%s",TableauJoueurs[i].nom);

        do
        {
            system("cls");
            affichePlateau(plateau);
            printf("Veuillez saisir un nombre compris entre 1 et 15 pour choisir votre couleur votre couleur:\n");
<<<<<<< HEAD
            printf("1 : gris clair"); Color(1,0);
            printf("               2 : Bleu fluo");Color(2,0);
            printf("               3 : Vert fonce\n"); Color(3,0);
            printf("4 : Bleu clair"); Color(4,0);
            printf("                5 : Rouge fonce");Color(5,0);
            printf("             6 : Violet\n"); Color(6,0);
            printf("7 : Jaune"); Color(7,0);
            printf("                    8 : Blanc"); Color(8,0);
            printf("                   9 : gris fonce\n"); Color(9,0);
            printf("10 : Bleu fonce"); Color(10,0);
            printf("              11 : Vert"); Color(11,0);
            printf("                   12 : turquoise\n"); Color(12,0);
            printf("13 : Rouge fluo"); Color(13,0);
            printf("              14 : Magenta"); Color(14,0);
            printf("                15 : Jaune clair\n"); Color(15,0);
            scanf("%d",&TableauJoueurs[i].couleur);
            fprintf(fichierJoueur," %d",TableauJoueurs[i].couleur);
=======
            printf("0 : gris clair"); Color(1,0);
            printf("               1 : Bleu fluo");Color(2,0);
            printf("               2 : Vert fonce\n"); Color(3,0);
            printf("3 : Bleu clair"); Color(4,0);
            printf("               4 : Rouge fonce");Color(5,0);
            printf("             5 : Violet\n"); Color(6,0);
            printf("6 : Jaune"); Color(7,0);
            printf("                    7 : Blanc"); Color(8,0);
            printf("                   8 : gris fonce\n"); Color(9,0);
            printf("9 : Bleu fonce"); Color(10,0);
            printf("               10 : Vert"); Color(11,0);
            printf("                   11 : turquoise\n"); Color(12,0);
            printf("12 : Rouge fluo"); Color(13,0);
            printf("              13 : Magenta"); Color(14,0);
            printf("                14 : Jaune clair\n"); Color(15,0);
            scanf("%d",&T[i].couleur);
            fprintf(fichierJoueur," %d",T[i].couleur);
>>>>>>> 910164eca46bf3125f30f804eea998473aede187
        }
        while ((TableauJoueurs[i].couleur<1) || (TableauJoueurs[i].couleur>15));
        do
        {
            system("cls");
            affichePlateau(plateau);
            printf("Veuillez saisir le symbole qui vous representera sur le plateau, vous avez le choix parmis:\n");
            printf("1.%c    ",0x02);
            printf("2.%c    ",0x03);
            printf("3.%c    \n",0x04);
            printf("4.%c    ",0x05);
            printf("5.%c    ",0x06);
            printf("6.%c    \n",0xFE);
            printf("7.%c    ",0x10);
            printf("8.%c    ",0x0E);
            printf("9.%c    \n",0x0F);
            printf("10.%c   ",0x11);
            printf("11.%c   ",0x0B);
            printf("12.%c    \n",0x0C);
            printf("13.%c   ",0x24);
            printf("14.%c   ",0x25);
            printf("15.%c    \n",0x40);
            printf("16.%c   ",0x26);
            printf("17.%c   ",0x23);
            printf("18.%c    \n",0x3F);
            scanf("%d",&choix6);
        }
        while((choix6>18) || (choix6<1));
        switch(choix6)
        {
            case 1 :
            TableauJoueurs[i].sigle=0x02;
            fprintf(fichierJoueur," %d",1);
            break;
        case 2 :
            TableauJoueurs[i].sigle=0x03;
            fprintf(fichierJoueur," %d",2);
            break;
        case 3 :
             TableauJoueurs[i].sigle=0x04;
             fprintf(fichierJoueur," %d",3);
             break;
        case 4 :
             TableauJoueurs[i].sigle=0x05;
             fprintf(fichierJoueur," %d",4);
             break;
        case 5 :
             TableauJoueurs[i].sigle=0x06;
             fprintf(fichierJoueur," %d",5);
             break;
        case 6 :
             TableauJoueurs[i].sigle=0xFE;
             fprintf(fichierJoueur," %d",6);
             break;
        case 7 :
             TableauJoueurs[i].sigle=0x10;
             fprintf(fichierJoueur," %d",7);
             break;
        case 8 :
             TableauJoueurs[i].sigle=0x0E;
             fprintf(fichierJoueur," %d",8);
             break;
        case 9 :
             TableauJoueurs[i].sigle=0x0F;
             fprintf(fichierJoueur," %d",9);
             break;
        case 10 :
             TableauJoueurs[i].sigle=0x11;
             fprintf(fichierJoueur," %d",10);
             break;
        case 11 :
             TableauJoueurs[i].sigle=0x0B;
             fprintf(fichierJoueur," %d",11);
             break;
        case 12 :
             TableauJoueurs[i].sigle=0x0C;
             fprintf(fichierJoueur," %d",12);
             break;
        case 13 :
             TableauJoueurs[i].sigle=0x24;
             fprintf(fichierJoueur,"% d",13);
             break;
        case 14 :
             TableauJoueurs[i].sigle=0x25;
             fprintf(fichierJoueur,"% d",14);
             break;
        case 15 :
             TableauJoueurs[i].sigle=0x40;
             fprintf(fichierJoueur,"% d",15);
             break;
        case 16 :
             TableauJoueurs[i].sigle=0x26;
             fprintf(fichierJoueur," %d",16);
             break;
        case 17 :
             TableauJoueurs[i].sigle=0x23;
             fprintf(fichierJoueur," %d",17);
             break;
        case 18 :
             TableauJoueurs[i].sigle=0x3F;
             fprintf(fichierJoueur," %d",18);
             break;
        default :
            printf("Erreur\n");
            break;


        }
        TableauJoueurs[i].score=0;
        fprintf(fichierJoueur," %d\n",TableauJoueurs[i].score);
        printf("Profil du joueur etabli. Bonne partie !\n");
        i++;



    }
    fclose(fichierJoueur);
    int firstp,secondp,thirdp,fourthp;
    srand(time(NULL));
    firstp=rand()%(a);
    do { secondp=rand()%(a);} while (secondp==firstp);
    if (a>2)
        {
            do { thirdp=rand()%(a);} while ( (thirdp==secondp) || (thirdp==firstp));
            do { fourthp=rand()%(a);} while ((fourthp==firstp) || (fourthp==secondp) || (fourthp==thirdp)); }

    printf("Le premier joueur est : %s\n",TableauJoueurs[firstp].nom);
    int compteur=0;
    int compteurmur;

    Partie(a,firstp,secondp,thirdp,fourthp,TableauJoueurs,compteur,TableauPositionMur,compteurmur);





}


void MenuJoueur(int numerojoueur, t_joueur *TableauJoueurs)
{   int choix7;
    system("cls");
    char plateau[19][56];
    affichePlateau(plateau);
    do
    {
        printf("Choix possibles :");
        printf("1. Deplacer son pion");
        printf("2. Poser une barriere");
        printf("3. Passer son tour");
        printf("4. Annuler l'action précédente");
        printf("5. Interrompre la partie");
        printf("%s, veuillez faire un choix", TableauJoueurs[numerojoueur].nom);
        scanf("%d",choix7);

    }
    while ((choix7>5) || (choix7<1));
    switch(choix7)
    {
    case 1 :
        //possibilite
        break;
    case 2 :
        break;
    case 3 :
        break;
    case 4 :
        break;
    case 5 :
        break;
    default :
        printf("Erreur!");
        break;
    }
}

int inputNbJoueurs()
{
    int choix5=0;
    system("cls");
    char plateau[19][56];
    affichePlateau(plateau);
    do {
        printf("Combien de joueurs souhaitez-vous pour cette partie?\n");
        printf("1. 2 joueurs\n");
        printf("2. 4 joueurs\n");
        printf("3. Retour au menu principal\n");
        scanf("%d",&choix5);
        }
    while ((choix5>3)||(choix5<1));
    switch(choix5){
    case 1 :
        return(2);
        break;
    case 2 :
        return(4);
        break;
    case 3 :
        menup(menu());
        break;
        return 0;
    default :
        printf("Error \n");
        break;
    }
}


char ReadChar(int transit, char sigle) // SS Prog qui permets de récupérer le charactère hexadecimal associé au joueur car les caractères choisis sont des indicateur de début de texte ou autre
{

    switch(transit)
    {
        case 1 :
            sigle=0x02;
            printf("%c\n",sigle);
            break;
        case 2 :
            sigle=0x03;
            printf("%c\n",sigle);
            break;
        case 3 :
             sigle=0x04;
             printf("%c\n",sigle);
             break;
        case 4 :
             sigle=0x05;
             printf("%c\n",sigle);
             break;
        case 5 :
             sigle=0x06;
             printf("%c\n",sigle);
             break;
        case 6 :
             sigle=0xFE;
             printf("%c\n",sigle);
             break;
        case 7 :
             sigle=0x10;
             printf("%c\n",sigle);
             break;
        case 8 :
             sigle=0x0E;
             printf("%c\n",sigle);
             break;
        case 9 :
             sigle=0x0F;
             printf("%c\n",sigle);
             break;
        case 10 :
             sigle=0x11;
             printf("%c\n",sigle);
             break;
        case 11 :
             sigle=0x0B;
             printf("%c\n",sigle);
             break;
        case 12 :
             sigle=0x0C;
             printf("%c\n",sigle);
             break;
        case 13 :
             sigle=0x24;
             printf("%c\n",sigle);
             break;
        case 14 :
             sigle=0x25;
             printf("%c\n",sigle);
             break;
        case 15 :
             sigle=0x40;
             printf("%c\n",sigle);
             break;
        case 16 :
             sigle=0x26;
             printf("%c\n",sigle);
             break;
        case 17 :
             sigle=0x23;
             printf("%c\n",sigle);
             break;
        case 18 :
            sigle=0x3F;
            printf("%c\n",sigle);
             break;
        default :
            printf("ErreurRR!\n");
            break;
    }

}


int menu()
{
    int choix;
    system("cls");
    char plateau[19][56];
    affichePlateau(plateau);
    printf("    MENU PRINCIPAL\n");
    printf ("1.Lancer une nouvelle partie\n");
    printf ("2.Reprendre une partie sauvegardée\n");
    printf ("3.Afficher l’aide\n");
    printf("4.Afficher les scores des joueurs\n");
    printf ("5.Quitter le jeu\n");
    do { printf("Que voulez vous faire ?\nSaisir une action entre 1,2,3,4 ou 5 :\n");
         scanf("%d",&choix);
         printf("%d",choix);}
    while ((choix>5) || (choix<1));
    return (choix);
}

void menup()
{   t_joueur *TableauJoueurs;
    t_positionm *TableauPositionMur;
    int choix;
    int pion1;
    int choix2;
    switch(choix)
    {
  case 1:
    saisiejoueurs(inputNbJoueurs(),TableauJoueurs,TableauPositionMur);
    //partie();
    break;

    case 3:
     choix2=MenuAide();
     Aide(choix2);
     break;

    case 5 :
        exit(1);
        break;




    default:
        printf("\nerreur\n");
        break;
    }


}

<<<<<<< HEAD


=======
<<<<<<< HEAD
=======
>>>>>>> b1f0c7ebe336e3a1de6d802060a0ba07ab66fc64
void choixpremiereposition2(t_position *caseee, t_joueur T[1])
{

    int A=5;
    int B=11;
    int C=17;
    int D=23;
    int E=29;
    int F=35;
    int G=41;
    int H=47;
    int I=53;

    Color(15,0); gotoligcol(30,0);printf("Pour le second joueur, saisir lettre de la case ou vous voulez commencer:\n");
    scanf("%s",&(caseee->y));
    if (caseee->y=='A') caseee->y=A;
    if (caseee->y=='B') caseee->y=B;
    if (caseee->y=='C') caseee->y=C;
    if (caseee->y=='D') caseee->y=D;
    if (caseee->y=='E') caseee->y=E;
    if (caseee->y=='F') caseee->y=F;
    if (caseee->y=='G') caseee->y=G;
    if (caseee->y=='H') caseee->y=H;
    if (caseee->y=='I') caseee->y=I;
    caseee->x=1;
    gotoligcol (caseee->x,caseee->y); Color(T[1].couleur,0);printf("%c", T[1].sigle); gotoligcol(23,0);
}

void positionpion(t_position *pion)
{

    printf("saisir ligne:\n");
    scanf("%d",&(pion->x));
    printf("saisir colonne:\n");
    scanf("%d",&(pion->y));
}

typedef struct positionm
{
    int x1, x2;
    int y1;
    int y2;

}t_positionm;
>>>>>>> 910164eca46bf3125f30f804eea998473aede187

void positionm(t_positionm *mur)
{
    int A=5;
    int B=11;
    int C=17;
    int D=23;
    int E=29;
    int F=35;
    int G=41;
    int H=47;
    int I=53;

    printf("saisir lettre premiere case:\n");
    scanf("%s",&(mur->y1));
    if (mur->y1=='A') mur->y1=A;
    if (mur->y1=='B') mur->y1=B;
    if (mur->y1=='C') mur->y1=C;
    if (mur->y1=='D') mur->y1=D;
    if (mur->y1=='E') mur->y1=E;
    if (mur->y1=='F') mur->y1=F;
    if (mur->y1=='G') mur->y1=G;
    if (mur->y1=='H') mur->y1=H;
    if (mur->y1=='I') mur->y1=I;
    printf("saisir numero premiere case:\n");
    scanf("%d",&(mur->x1));
    if (mur->x1==6) mur->x1=11;
    if (mur->x1==7) mur->x1=13;
    if (mur->x1==8) mur->x1=15;
    if (mur->x1==9) mur->x1=17;
    if (mur->x1==5) mur->x1=9;
    if (mur->x1==3) mur->x1=5;
    if (mur->x1==2) mur->x1=3;
    if (mur->x1==4) mur->x1=7;
    printf("saisir lettre deuxieme case:\n");
    scanf("%s",&(mur->y2));
    if (mur->y2=='A') mur->y2=A;
    if (mur->y2=='B') mur->y2=B;
    if (mur->y2=='C') mur->y2=C;
    if (mur->y2=='D') mur->y2=D;
    if (mur->y2=='E') mur->y2=E;
    if (mur->y2=='F') mur->y2=F;
    if (mur->y2=='G') mur->y2=G;
    if (mur->y2=='H') mur->y2=H;
    if (mur->y2=='I') mur->y2=I;

    printf("saisir numero deuxieme case:\n");
    scanf("%d",&(mur->x2));
    if (mur->x2==6) mur->x2=11;
    if (mur->x2==7) mur->x2=13;
    if (mur->x2==8) mur->x2=15;
    if (mur->x2==9) mur->x2=17;
    if (mur->x2==3) mur->x2=5;
    if (mur->x2==9) mur->x2=17;
    if (mur->x2==2) mur->x2=3;
    if (mur->x2==4) mur->x2=7;

}

void posibilitem(t_positionm muur,t_joueur T[0],t_positionm *TableauPositionMur[19], int compteurm)
{

    char h;
    char plateau[19][56];
    printf("de quel cote voulez vous mettre la barriere?\n");
    printf("tappez H pour en haut G pour a gauche D pour a droite et B pour en bas:\n");
    scanf("%s", &h);

                        switch (h){
                        case 'D':
                        gotoligcol(muur.x1,muur.y1+3); Color(T[0].couleur,0); printf("%c",0xDB);
<<<<<<< HEAD
                        gotoligcol(muur.x1+1,muur.y1+3); Color(T[0].couleur,0); printf("%c",0xDB);
                        gotoligcol(muur.x2,muur.y2+3); Color(T[0].couleur,0); printf("%c",0xDB);
=======
                        gotoligcol(muur.x2,muur.y2+3); Color(T[0].couleur,0); printf("%c",0xDB);
                        TableauPositionMur[compteurm].x1=muur.x1;
                        TableauPositionMur[compteurm].x2=muur.x2;
                        TableauPositionMur[compteurm].y2=muur.y2+3;
                        TableauPositionMur[compteurm].y1=muur.y1+3;

>>>>>>> b1f0c7ebe336e3a1de6d802060a0ba07ab66fc64
                        break;
                        case 'G':
<<<<<<< HEAD
                        gotoligcol(muur.x1-3,muur.y1); Color(T[0].couleur,0); printf("%c",0xDB);
                        gotoligcol(muur.x2-3,muur.y2); Color(T[0].couleur,0); printf("%c",0xDB);
                        TableauPositionMur[compteurm].x1=muur.x1-3;
                        TableauPositionMur[compteurm].x2=muur.x2-3;
                        TableauPositionMur[compteurm].y2=muur.y2;
                        TableauPositionMur[compteurm].y1=muur.y1;
=======
                        gotoligcol(muur.x1,muur.y1-3); Color(T[0].couleur,0); printf("B");
                        gotoligcol(muur.x2,muur.y2-3); Color(T[0].couleur,0); printf("B");
>>>>>>> 910164eca46bf3125f30f804eea998473aede187
                        break;
                        case 'B':
                        gotoligcol(muur.x1+1,muur.y1); Color(T[0].couleur,0); printf("%c",0xDB);
                        gotoligcol(muur.x2+1,muur.y2); Color(T[0].couleur,0); printf("%c",0xDB);
                        TableauPositionMur[compteurm].x1=muur.x1+1;
                        TableauPositionMur[compteurm].x2=muur.x2+1;
                        TableauPositionMur[compteurm].y2=muur.y2;
                        TableauPositionMur[compteurm].y1=muur.y1;
                        break;
                        case 'H':
                        gotoligcol(muur.x1-1,muur.y1); Color(T[0].couleur,0); printf("%c",0xDB);
                        gotoligcol(muur.x2-1,muur.y2); Color(T[0].couleur,0); printf("%c",0xDB);
                        TableauPositionMur[compteurm].x1=muur.x1-1;
                        TableauPositionMur[compteurm].x2=muur.x2-1;
                        TableauPositionMur[compteurm].y2=muur.y2;
                        TableauPositionMur[compteurm].y1=muur.y1;
                        break;
                        default:
                            printf("erreur\n");
                            break;

                        }
}

void affichepion(t_position pion,t_joueur T[0])
{
    gotoligcol(pion.x,pion.y); Color(T[0].couleur,0); printf("%c", T[0].sigle);
}

void possibilite(t_position piioonn,t_position *pioonn,t_joueur TableauJoueurs,t_positionm *TableauPositionMur,int compteurmur)
{

    char mouv;
    char plateau[19][56];
    int i=0;

    gotoligcol(21,0); Color(15,0);
    printf("tappez H pour en haut G pour a gauche D pour a droite et B pour en bas:\n");
    scanf("%s", &mouv);
                        switch (mouv){
                        case 'D':
<<<<<<< HEAD
=======
<<<<<<< HEAD
                        gotoligcol(piioonn.x,piioonn.y); Color(T[0].couleur,0);printf("%c",T[0].sigle);
=======

>>>>>>> b1f0c7ebe336e3a1de6d802060a0ba07ab66fc64
                        gotoligcol(piioonn.x,piioonn.y); Color(15,0);printf("_");
>>>>>>> 910164eca46bf3125f30f804eea998473aede187
                        piioonn.y=piioonn.y+6;
                        affichepion(piioonn,&T[0]);
                        for (int i=0,i<compteurmur,i++)
                        {
                            if ((TableauPositionMur[i].x1)
                        }
                        pioonn->x=pioonn->x;
                        pioonn->y=pioonn->y+6;

                        break;
                        case 'G':
                        gotoligcol(piioonn.x,piioonn.y); Color(T[0].couleur,0);printf("%c",
                                                                                      T[0].sigle);
                        piioonn.y=piioonn.y-6;
                        affichepion(piioonn,&T[0]);
                        pioonn->x=pioonn->x;
                        pioonn->y=pioonn->y-6;
                        break;
                        case 'B':
                        gotoligcol(piioonn.x,piioonn.y); Color(T[0].couleur,0);printf("%c",T[0].sigle);
                        piioonn.x=piioonn.x+2;
                        affichepion(piioonn,&T[0]);
                        pioonn->x=pioonn->x+2;
                        pioonn->y=pioonn->y;
                        break;
                        case 'H':
                        gotoligcol(piioonn.x,piioonn.y); Color(T[0].couleur,0);printf("%c",T[0].sigle);
                        piioonn.x=piioonn.x-2;
                        affichepion(piioonn,&T[0]);
                        pioonn->x=pioonn->x-2;
                        pioonn->y=pioonn->y;
                        break;
                        default: printf("erreur\n");
                        }



}
void possibiliteee(t_position casee)
{

    gotoligcol(casee.x,casee.y); Color(15,0);printf("#");

}


void choixpremiereposition1(int a, int cptj,int premierjoueur, int deuxiemejoueur, int troisiemejoueur, int quatriemejoueur ,t_joueur *TableauJoueurs)
{

<<<<<<< HEAD

    int A=5;
    int B=11;
    int C=17;
    int D=23;
    int E=29;
    int F=35;
    int G=41;
    int H=47;
    int I=53;
=======
char plateau[19][56];
int A=5;
int B=11;
int C=17;
int D=23;
int E=29;
int F=35;
int G=41;
int H=47;
int I=53;
>>>>>>> b1f0c7ebe336e3a1de6d802060a0ba07ab66fc64


    if (cptj==1)
   {
    system("cls");
    affichePlateau(plateau);
    Color(15,0); printf("%s,vous etes le premier joueur. Veuillez saisir lettre de la case ou vous souhaitez demarrer la partie :\n",TableauJoueurs[premierjoueur].nom);
    scanf("%s",&(TableauJoueurs[premierjoueur].emplacement.y));
    if (TableauJoueurs[premierjoueur].emplacement.y=='A') TableauJoueurs[premierjoueur].emplacement.y=A;
    if (TableauJoueurs[premierjoueur].emplacement.y=='B') TableauJoueurs[premierjoueur].emplacement.y=B;
    if (TableauJoueurs[premierjoueur].emplacement.y=='C') TableauJoueurs[premierjoueur].emplacement.y=C;
    if (TableauJoueurs[premierjoueur].emplacement.y=='D') TableauJoueurs[premierjoueur].emplacement.y=D;
    if (TableauJoueurs[premierjoueur].emplacement.y=='E') TableauJoueurs[premierjoueur].emplacement.y=E;
    if (TableauJoueurs[premierjoueur].emplacement.y=='F') TableauJoueurs[premierjoueur].emplacement.y=F;
    if (TableauJoueurs[premierjoueur].emplacement.y=='G') TableauJoueurs[premierjoueur].emplacement.y=G;
    if (TableauJoueurs[premierjoueur].emplacement.y=='H') TableauJoueurs[premierjoueur].emplacement.y=H;
    if (TableauJoueurs[premierjoueur].emplacement.y=='I') TableauJoueurs[premierjoueur].emplacement.y=I;
    TableauJoueurs[premierjoueur].emplacement.x=17;
    gotoligcol (TableauJoueurs[premierjoueur].emplacement.x,TableauJoueurs[premierjoueur].emplacement.y); Color(TableauJoueurs[premierjoueur].couleur,0); printf("%c", TableauJoueurs[premierjoueur].sigle);
    gotoligcol(19,0);
    cptj++;
   }

<<<<<<< HEAD
    if (cptj==2)
    {   system("cls");
        affichePlateau(plateau); Color(15,0);
        gotoligcol (TableauJoueurs[premierjoueur].emplacement.x,TableauJoueurs[premierjoueur].emplacement.y); Color(TableauJoueurs[premierjoueur].couleur,0); printf("%c", TableauJoueurs[premierjoueur].sigle);
        gotoligcol(19,0);
       Color(15,0); printf("%s, vous etes le deuxieme joueur. Veuillez saisir lettre de la case ou vous souhaitez demarrer la partie :\n",TableauJoueurs[deuxiemejoueur].nom);
       scanf("%s",&(TableauJoueurs[deuxiemejoueur].emplacement.y));
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='A') TableauJoueurs[deuxiemejoueur].emplacement.y=A;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='B') TableauJoueurs[deuxiemejoueur].emplacement.y=B;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='C') TableauJoueurs[deuxiemejoueur].emplacement.y=C;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='D') TableauJoueurs[deuxiemejoueur].emplacement.y=D;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='E') TableauJoueurs[deuxiemejoueur].emplacement.y=E;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='F') TableauJoueurs[deuxiemejoueur].emplacement.y=F;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='G') TableauJoueurs[deuxiemejoueur].emplacement.y=G;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='H') TableauJoueurs[deuxiemejoueur].emplacement.y=H;
    if (TableauJoueurs[deuxiemejoueur].emplacement.y=='I') TableauJoueurs[deuxiemejoueur].emplacement.y=I;
    TableauJoueurs[deuxiemejoueur].emplacement.x=1;
    printf("%d %d",TableauJoueurs[deuxiemejoueur].emplacement.x,TableauJoueurs[deuxiemejoueur].emplacement.y)
    printf("%d %d", TableauJoueurs[premierjoueur].emplacement.x,TableauJoueurs[premierjoueur].emplacement.y )
    gotoligcol (TableauJoueurs[deuxiemejoueur].emplacement.x,TableauJoueurs[deuxiemejoueur].emplacement.y); Color(TableauJoueurs[deuxiemejoueur].couleur,0); printf("%c", TableauJoueurs[deuxiemejoueur].sigle);
    gotoligcol(19,0);
    cptj++;
    }

    if (a>2)
    {

=======
    Color(15,0); printf("Pour le premier joueur, saisir lettre de la case ou vous voulez commencer:\n");
    scanf("%s",&(casee->y));
    if (casee->y=='A') casee->y=A;
    if (casee->y=='B') casee->y=B;
    if (casee->y=='C') casee->y=C;
    if (casee->y=='D') casee->y=D;
    if (casee->y=='E') casee->y=E;
    if (casee->y=='F') casee->y=F;
    if (casee->y=='G') casee->y=G;
    if (casee->y=='H') casee->y=H;
    if (casee->y=='I') casee->y=I;
    casee->x=17;
    gotoligcol (casee->x,casee->y); Color(T[0].couleur,0); printf("%c", T[0].sigle); gotoligcol(21,0);

}

void choixpremiereposition3(t_position *casee, t_joueur T[2])
{


    printf("Pour le troisieme, saisir numero de la case ou vous voulez commencer:\n");
    scanf("%d",&(casee->x));
    if (casee->x==6) casee->x=11;
    if (casee->x==7) casee->x=13;
    if (casee->x==8) casee->x=15;
    if (casee->x==9) casee->x=17;
    if (casee->x==5) casee->x=9;
    if (casee->x==3) casee->x=5;
    if (casee->x==2) casee->x=3;
    if (casee->x==4) casee->x=7;
    casee->y=47;
    gotoligcol (casee->x,casee->y); Color(T[2].couleur,0); printf("%c", T[2].sigle); gotoligcol(21,0);

}

void choixpremiereposition4(t_position *casee, t_joueur T[3])
{

    printf("Pour le quatrieme joueur, saisir numero de la case ou vous voulez commencer:\n");
    scanf("%d",&(casee->x));
    if (casee->x==6) casee->x=11;
    if (casee->x==7) casee->x=13;
    if (casee->x==8) casee->x=15;
    if (casee->x==9) casee->x=17;
    if (casee->x==5) casee->x=9;
    if (casee->x==3) casee->x=5;
    if (casee->x==2) casee->x=3;
    if (casee->x==4) casee->x=7;
    casee->y=5;
<<<<<<< HEAD
    gotoligcol(casee->x,casee->y); Color(T[3].couleur,0); printf("%c", T[3].sigle); gotoligcol(21,0);
=======
    gotoligcol (casee->x,casee->y); Color(T[3].couleur,0); printf("%c", T[3].sigle); gotoligcol(21,0);
>>>>>>> 910164eca46bf3125f30f804eea998473aede187
>>>>>>> b1f0c7ebe336e3a1de6d802060a0ba07ab66fc64

    if (cptj==3)
    {   Color(15,0);
        system("cls");
        affichePlateau(plateau); Color(15,0);
        gotoligcol (TableauJoueurs[premierjoueur].emplacement.x,TableauJoueurs[premierjoueur].emplacement.y); Color(TableauJoueurs[premierjoueur].couleur+1,0); printf("%c", TableauJoueurs[premierjoueur].sigle);
        gotoligcol (TableauJoueurs[deuxiemejoueur].emplacement.x,TableauJoueurs[deuxiemejoueur].emplacement.y); Color(TableauJoueurs[deuxiemejoueur].couleur+1,0); printf("%c", TableauJoueurs[deuxiemejoueur].sigle);
        gotoligcol(19,0); Color(15,0);
    printf("%s, vous etes le troisieme joueur. Veuillez saisir numero de la case ou vous souhaitez demarrer la partie:\n", TableauJoueurs[troisiemejoueur].nom);
    scanf("%d",&(TableauJoueurs[troisiemejoueur].emplacement.x));
    if (TableauJoueurs[troisiemejoueur].emplacement.x==6) TableauJoueurs[troisiemejoueur].emplacement.x=11;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==7) TableauJoueurs[troisiemejoueur].emplacement.x=13;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==8) TableauJoueurs[troisiemejoueur].emplacement.x=15;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==9) TableauJoueurs[troisiemejoueur].emplacement.x=17;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==5) TableauJoueurs[troisiemejoueur].emplacement.x=9;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==3) TableauJoueurs[troisiemejoueur].emplacement.x=5;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==2) TableauJoueurs[troisiemejoueur].emplacement.x=3;
    if (TableauJoueurs[troisiemejoueur].emplacement.x==4) TableauJoueurs[troisiemejoueur].emplacement.x=7;
    TableauJoueurs[troisiemejoueur].emplacement.y=I;
    gotoligcol (TableauJoueurs[troisiemejoueur].emplacement.x,TableauJoueurs[troisiemejoueur].emplacement.y); Color(TableauJoueurs[troisiemejoueur].couleur+1,0); printf("%c",TableauJoueurs[troisiemejoueur].sigle);
    gotoligcol(19,0);
    cptj++;
    }

    if (cptj==4)
        {
    Color(15,0);
    system("cls");
    affichePlateau(plateau); Color(15,0);
    gotoligcol (TableauJoueurs[premierjoueur].emplacement.x,TableauJoueurs[premierjoueur].emplacement.y); Color(TableauJoueurs[premierjoueur].couleur+1,0); printf("%c", TableauJoueurs[premierjoueur].sigle);
    gotoligcol (TableauJoueurs[deuxiemejoueur].emplacement.x,TableauJoueurs[deuxiemejoueur].emplacement.y); Color(TableauJoueurs[deuxiemejoueur].couleur+1,0); printf("%c", TableauJoueurs[deuxiemejoueur].sigle);
    gotoligcol (TableauJoueurs[troisiemejoueur].emplacement.x,TableauJoueurs[troisiemejoueur].emplacement.y); Color(TableauJoueurs[troisiemejoueur].couleur+1,0); printf("%c",TableauJoueurs[troisiemejoueur].sigle);
    gotoligcol(19,0); Color(15,0);
    printf("%s, vous etes le quatrieme joueur. Veuillez  saisir numero de la case ou vous souhaitez demarrer la partie: \n", TableauJoueurs[quatriemejoueur].nom);
    scanf("%d",&(TableauJoueurs[quatriemejoueur].emplacement.x));
    if (TableauJoueurs[quatriemejoueur].emplacement.x==6) TableauJoueurs[quatriemejoueur].emplacement.x=11;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==7) TableauJoueurs[quatriemejoueur].emplacement.x=13;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==8) TableauJoueurs[quatriemejoueur].emplacement.x=15;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==9) TableauJoueurs[quatriemejoueur].emplacement.x=17;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==5) TableauJoueurs[quatriemejoueur].emplacement.x=9;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==3) TableauJoueurs[quatriemejoueur].emplacement.x=5;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==2) TableauJoueurs[quatriemejoueur].emplacement.x=3;
    if (TableauJoueurs[quatriemejoueur].emplacement.x==4) TableauJoueurs[quatriemejoueur].emplacement.x=7;
    TableauJoueurs[quatriemejoueur].emplacement.y=A;
    gotoligcol(TableauJoueurs[quatriemejoueur].emplacement.x,TableauJoueurs[quatriemejoueur].emplacement.y);Color(TableauJoueurs[quatriemejoueur].couleur+1,0); printf("%c",TableauJoueurs[quatriemejoueur].sigle);
    gotoligcol(19,0);
    }

}
}

 void Partie (int a,int premierjoueur, int deuxiemejoueur, int troisiemejoueur, int quatriemejoueur,t_joueur *TableauJoueurs,int compteur, t_positionm TableauPositionMur, int compteurmur)
{   int cptj=1;
    //FILE *fichierPartie=fopen("PartieEnCours.txt","w+"); // Ouverture en w+ pour qu'à chaque fois qu'un joueur joue le fichier soit mis à jour "Automatiquement"
    printf("%s %d %c %d", TableauJoueurs[premierjoueur].nom, TableauJoueurs[premierjoueur].couleur, TableauJoueurs[premierjoueur].sigle,TableauJoueurs[premierjoueur].score);
    if (compteur==0)
    {
        choixpremiereposition1(a,cptj,premierjoueur,deuxiemejoueur,troisiemejoueur,quatriemejoueur,TableauJoueurs);
        compteur++;
    }

    /*if (a=2)
    {
        while (((TableauJoueurs[premierjoueur].emplacement.x)!=1) && ((TableauJoueurs[deuxiemejoueur].emplacement.x)!=17) && TableauJoueurs[troisiemejoueur].emplacement.y!=)
        {

        }
    }*/

}


void partie(int a)
{

    t_joueur T[0];
    T[0].nmbrMurres=10;
    T[1].nmbrMurres=10;



    saisiejoueurs(2,&T[0]);

    t_position casee1;
    t_position casee2;
    t_position piioonn;

    //choixpremiereposition1(&casee1,&T[0]);
    //choixpremiereposition2(&casee2,&T[0]);

    int c,d;
    t_positionm mur1;
    t_positionm mur2;





   for (int i=1; i<1000; i++) {
     if (i%2!=0) {
   for ( int i=20; i<32; i++) { gotoligcol(i,0); printf("                                                                                                \n"); }
   coter(0,&T[0]);
   gotoligcol(19,0); Color(15,0); printf("JOUEUR n1 : tapper 1 pour bouger votre pion ou 2 pour placer un mur\n");
    scanf("%d",&c);

    switch(c) {

      case 1 :

        possibilite(casee1,&casee1,&T[0]);

        break;
      case 2:
          positionm(&mur1);
          posibilitem(mur1,&T[0]);
         for ( int i=23; i<32; i++) { gotoligcol(i,0); printf("                                                                                                \n"); }
         printf("ici %d",T[0].nmbrMurres) ; T[0].nmbrMurres=T[0].nmbrMurres-1; printf("la %d",T[0].nmbrMurres);
         break;
     default : printf("erreur"); } }

   if (i%2==0) {
   for ( int i=19; i<30; i++) { gotoligcol(i,0); printf("                                                                                                \n"); }
   coter(1,&T[0]);
   gotoligcol(19,0); Color(15,0); printf("JOUEUR n2 : tapper 1 pour bouger votre pion ou 2 pour placer un mur\n");
    scanf("%d",&d);

    switch(d) {

      case 1 :
          possibilite(casee2,&casee2, &T[1]);
          break;
      case 2:
          positionm(&mur2);
          posibilitem(mur2,&T[1]);
          for ( int i=23; i<32; i++) { gotoligcol(i,0); printf("                                                                                                \n"); }
          T[1].nmbrMurres--;
          break;
      default : printf("erreur");

} }   if ( (casee1.x==1) || (casee2.x==17) ){  printf("VOUS AVEZ GAGNER !!");   }   }        }


int main()
{
    char *plat;
    int nb=2;
    int lig=19;
    int col=56;
    int choix;
    t_joueur T[0];
    //int choix2;
    //int choix3;
    t_joueur *TableauJoueurs = NULL;
    t_positionm *TableauPositionMur[19]=NULL;
    //printf(inputNbJoueurs();
    affichePlateau(&plat);
    t_position pion1;
    t_position pion2;
    t_joueur premier;
    t_joueur second;
     t_positionm mur;

    choix=menu();
    menup();




    return 0;
}
