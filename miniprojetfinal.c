#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include <shlobj.h>
//#include <curses.h>

int mois[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
BOOL haute_saison=FALSE;
float selvol;
float selnuite;
char selhot[50];
char seldest[50];
char hotelchoisis[50];
char selpension[20];
float selpensionprix;
float total;
void menu(){
logo:
system("MODE CON: COLS=95 LINES=40");
system("COLOR 17");
system ("cls");
printf("\n\n\n\n\n");
printf("\t\t  _     _                                      \n");
printf("\t\t | |   (_)                                     \n");
printf("\t\t | |__  _  ___ _ ____   _____ _ __  _   _  ___ \n");
printf("\t\t | '_ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\\n");
printf("\t\t | |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/\n");
printf("\t\t |_.__/|_|\\___|_| |_|\\_/ \\___|_| |_|\\__,_|\\___|\n");
printf("\t\t                                               \n");
printf("    \t\t                                           \n");
printf("");
sleep(1);
printf("\n");
printf("\n");
system("COLOR 17");
printf("\t\t\t\xCB\xCD\xBB\xC9\xCD\xCB\xC9\xCB\xBB\xCB\xCD\xBB\xC9\xCD\xBB\n");
printf("\t\t\t\xCC\xCB\xBC\xCC\xB9  \xBA \xCC\xCB\xBC\xBA \xBA\n");
printf("\t\t\t\xCA\xC8\xCD\xC8\xCD\xBC \xCA \xCA\xC8\xCD\xC8\xCD\xBC\n");
printf("");
printf("\t\t\t\xC9\xCB\xBB\xCB\xCD\xBB\xCB\xC9\xCD\xBB\xC9\xCD\xBB\xC9\xCB\xBB\xCB  \xCB\xCB\xC9\xCD\xBB\xC9\xCD\xBB\xCB\xCD\xBB\n");
printf("\t\t\t \xBA \xCC\xCB\xBC\xBA\xCC\xCD\xBC\xCC\xCD\xB9 \xBA\xBA\xC8\xBB\xC9\xBC\xBA\xC8\xCD\xBB\xBA \xBA\xCC\xCB\xBC\n");
printf("\t\t\t \xCA \xCA\xC8\xCD\xCA\xCA  \xCA \xCA\xCD\xCA\xBC \xC8\xBC \xCA\xC8\xCD\xBC\xC8\xCD\xBC\xCA\xC8\xCD\n");
printf("\n");
sleep(1);
printf("\n\t\tBienvenue sur RERTO TRIPADVISOR !\n");
printf("\t\tVeuillez choisir une destination parmi les notres!\n");

}

void main(){
	
/****declaration fonctions****/

void Color(int t,int f);
int curseur(int posreel,int poscur);
void gotoxy(short  x, short y);
void scroll();
int leap(int y);
int gregoriantojd(int d, int m, int y);
int dayOfWeek(int d, int m, int y);
int validerdate(int d ,int m,int y);
void gotoxy(short  x, short y);

/*variables declaration */

char jour[8][10]={"Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi"};
char moisalpha[12][10]={"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","octobre","Novembre","Decembre"};
int d1,d2,m1,m2,y1,y2;
int nuite=0;
int hours, minutes, seconds, day, month, year;
char hotel[20];

menu();
gotoxy(15,38);printf("Appuyer sur un bouton pour commencer...\n");
getch();
menu_voyageurs:
system("cls");
//printf("\n\n\n");
int adulte;
int enfant;
char nom[20];
char prenom[20];
char chambre[][50]={"Simple","Confort(Double/Twin)","Familiale"};
int tel[8];
char mail[40];
printf("\n\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
printf("\t\t\t\xBA\t NOMBRE DE VOYAGEURS       \xBA\n");
printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n\n");

printf("\n\n");
gotoxy(18,10);printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
gotoxy(18,11);printf("\t\xB3\t\xB3\n");
gotoxy(8,11);printf("Adulte(s):");
gotoxy(8,12);printf("[1 - 30]");
gotoxy(18,12);printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

gotoxy(18,14);printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
gotoxy(18,15);printf("\t\xB3\t\xB3\n");
gotoxy(8,15);printf("Enfant(s):");
gotoxy(8,16);printf("[0 - 10]");
gotoxy(18,16);printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
gotoxy(28,11);scanf("%d",&adulte);
gotoxy(28,15);scanf("%d",&enfant);

while((adulte<1 || enfant<0)||(adulte>30 || enfant>10))
{	
	gotoxy(19,25);printf("\aNombre invalide");
	getch();
	gotoxy(19,25);printf("                     \n");
	goto menu_voyageurs;
}


gotoxy(8,20);printf("Nombre de voyageur(s): %d\n\n",adulte+enfant);
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
getch();
hebergement:
system("cls");
	// time_t is arithmetic time type
	time_t now;
	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);
	// Convert to local time format and print to stdout
	// localtime converts a time_t value to calendar time and
	// returns a pointer to a tm structure with its members
	// filled with the corresponding values
	struct tm *local = localtime(&now);

    day = local->tm_mday;        	// get day of month (1 to 31)
    month = local->tm_mon + 1;   	// get month of year (0 to 11)
    year = local->tm_year + 1900;	// get year since 1900
    hours=local->tm_hour;
    minutes=local->tm_min;
    seconds=local->tm_sec;
    
depart:
// print current date
gotoxy(30,1);printf("%s %02d %s %d %d:%d:%d\n\n\n",jour[dayOfWeek(day,month,year)],day,(moisalpha[month-1]), year,hours,minutes,seconds);
gotoxy(2,5);printf("\t+---------------------------------+\n");
gotoxy(2,6);printf("\t|\tChoisir date de d\x82part :  |\n");
gotoxy(2,7);printf("\t|\t (jj mm aaaa)             |\n");
gotoxy(2,8);printf("\t+---------------------------------+\n");
//gotoxy(21,9);printf("%d\\%d\\%d",day,month,year);
gotoxy(21,9);scanf("%d%d%d",&d1,&m1,&y1);
while (validerdate(d1,m1,y1)==-1 || validerdate(d1,m1,y1)==0) 
{
	gotoxy(19,25);printf("\aDate d\x82part non valide, Appyuer pour saisir une date valide!\n ");
	getch();
	gotoxy(19,25);printf("                                                              \n");
	gotoxy(21,9);printf("                                         ");
	gotoxy(21,9);scanf("%d%d%d",&d1,&m1,&y1);
}
while (gregoriantojd(d1,m1,y1)-gregoriantojd(day,month,year)<=0){
	gotoxy(19,25);printf("\aChoisir date ulterieure a aujourd'hui");
	getch();
	gotoxy(19,25);printf("                                                             ");
    gotoxy(21,9);printf("                            "); 
    gotoxy(21,9);scanf("%d%d%d",&d1,&m1,&y1);
		while (validerdate(d1,m1,y1)==-1 || validerdate(d1,m1,y1)==0){
		gotoxy(19,25);printf("\aDate non valide Appyuer pour saisir date valide!");
		getch();
		gotoxy(21,9);printf("                                                           ");
		gotoxy(21,9);scanf("%d%d%d",&d1,&m1,&y1);
		
		}
 }
 
gotoxy(16,16);printf("La date de d\x82part est: %s  %d/%d/%d\n",(jour[dayOfWeek(d1,m1,y1)]),d1,m1,y1);
retour:
gotoxy(45,5);printf("\t+---------------------------------+\n");
gotoxy(45,6);printf("\t|\tChoisir date de retour :  |\n");
gotoxy(45,7);printf("\t|\t (jj mm aaaa)             |\n");
gotoxy(45,8);printf("\t+---------------------------------+\n");
gotoxy(58,9);scanf("%d%d%d",&d2,&m2,&y2);

while(validerdate(d2,m2,y2)==-1 || validerdate(d2,m2,y2)==0)
{
		gotoxy(19,25);printf("\aDate non valide, Appyuer pour saisir date retour valide!\n");
		getch();
		gotoxy(19,25);printf("                                                            \n");
		gotoxy(58,9);printf("                                                             \n");
		gotoxy(58,9);scanf("%d%d%d",&d2,&m2,&y2);
}

nuite=gregoriantojd(d2,m2,y2)-gregoriantojd(d1,m1,y1);
while(nuite<=0)
{
	gotoxy(19,25);printf("\aDate retour < date de d\x82part!\n");
	getch();
	gotoxy(19,25);printf("                                                                           \n");
	gotoxy(58,9);printf("                                                                            \n");
	goto retour;
	//fflush(stdout);
}
gotoxy(16,17);printf("La date de retour est: %s %d/%d/%d\n",(jour[dayOfWeek(d2,m2,y2)]),d2,m2,y2);
gotoxy(16,18);printf("Dur\x82""e totale du s""\x82jour : %d nuits\n\n",nuite);

 while (nuite>=30){
	gotoxy(10,20);printf("\tDesol\x82, il est impossible de r\x82servation plus de 30 nuits.");
	getch();
	gotoxy(19,20);printf("\t                                                                        ");
	goto hebergement;
}
if( m1>4 && m1<9 || m2>4 && m2<9 ) haute_saison=TRUE;
else if ( m1==04 || m2==9 && d1>=27 && d2<=30) haute_saison=TRUE;
else haute_saison=FALSE;
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
getch();
system("cls");
int position=1;
int keypressed=0;
int maxoption=7;
char destination[8][20]={"Paris","Barcelone","Rome","Casablanca","New York","Bali","Istanbul"};
float prix_billets[]={979,985,990,1102,3450,4747,1130};

while (keypressed!=13)
{
	menu_destination:
	system("cls");
	//printf("\n\n");
	printf("\n\n\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t   DESTINATIONS   \t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	gotoxy(12,11);printf("\xBA  #  \xBA    Destination         \xBA   Prix billet x1 adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t\t%.3f\t\t\t\t\n",destination[0],prix_billets[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t\t%.3f\t\t\t\t\t\n",destination[1],prix_billets[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t\t\t%.3f\t\t\t\t\n",destination[2],prix_billets[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t\t%.3f\t\t\t\t\n",destination[3],prix_billets[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\t\t\t\t\n",destination[4],prix_billets[4]);
	gotoxy(12,18);curseur(6,position);printf("6\t\t%s\t\t\t\t%.3f\t\t\t\t\n",destination[5],prix_billets[5]);
	gotoxy(12,19);curseur(7,position);printf("7\t\t%s\t\t\t%.3f\t\t\t\t\n",destination[6],prix_billets[6]);
	gotoxy(12,20);curseur(8,position);printf("   \n");
	//printf("Prix pour 1 adulte.");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir une destination");


	keypressed=getch();
	if(keypressed == 80 && position <maxoption)	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
}

gotoxy(20,30);printf("Vous avez choisi :  %s",destination[position-1]);
selvol=prix_billets[position-1];
strcpy(seldest,(destination[position-1]));
gotoxy(15,38);printf("                                                             ");
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");

if ((position==1) && (getch()==13))

{
	int position=1;
	int keypressed=0;
	int maxoption=5;
	int choix=0;
	char hotel[50][50]={"Timhotel Montmartre","Le Six","Magda Champs Elysees","Le 10 Bis","Maison Souquet"};
	float prix_nuitee[]={180,420,190,260,550};

while(keypressed!=13)
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t   PARIS H\x93TELS\t\t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");

   
	keypressed=getch();

	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	//else if (keypressed== 77 ){goto main;}//right arrow
	//else if (keypressed== 27 ){goto Exit;}//esc key
	else {position =position;}

}
 gotoxy(20,30);printf("Vous avez choisi:  %s",hotel[position-1]);
 strcpy(selhot,hotel[position-1]);
 selnuite=prix_nuitee[position-1];
 gotoxy(15,38);printf("                                                             ");
 gotoxy(30,38);printf("Appuyer sur une touche pour continuer ...");
 getch();

  
}
if ((position==2) && (getch()==13))

{
     int position=1;
     int keypressed=0;
     int maxoption=5;
	 int choix=0;
	 char hotel[100][100]={"Barcelo Raval","Olivia Balmes Hotel","Grand Hotel Central","W Barcelona","The One Barcelona"};
	 float prix_nuitee[]={233,301,380,556,780};

while(keypressed!=13)
{
	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  H\x93TELS BARCELONE         \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");

    keypressed=getch();

	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
}
gotoxy(20,30);printf("Vous avez choisi:  %s",hotel[position-1]);
strcpy(selhot,hotel[position-1]);
selnuite=prix_nuitee[position-1];
gotoxy(15,38);printf("                                                             ");
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
getch();


}

if ((position==3) && (getch()==13))
{

{
    int position=1;
    int keypressed=0;
    int maxoption=5;
	int choix=0;
	char hotel[100][100]={"Colosseum","Villa San Pio","Italia","The Independent ","Rome Life Hotel"};
	float prix_nuitee[]={170,165,130,230,240};
	
while(keypressed!=13)
{

	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  H\x93TELS ROME    \t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");
        
    keypressed=getch();

	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
        
}
gotoxy(20,30);printf("Vous avez choisi:  %s",hotel[position-1]);
selnuite=prix_nuitee[position-1];
strcpy(selhot,hotel[position-1]);
gotoxy(15,38);printf("                                                             ");
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
getch();

}

       
}
if ((position==4) && (getch()==13))

{
    int position=1;
    int keypressed=0;
    int maxoption=5;
	int choix=0;
	char hotel[100][100]={"La Maison Arabe","Kasbah Le Mirage","Sahrai","Sirayane Boutique Hotel & Spa","Les Deux Tours"};
	float prix_nuitee[]={110,170,210,260,320};
	
    while(keypressed!=13)

{
	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  H\x93TELS CASABLANCA  \t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");
    
    keypressed=getch();
	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
        


}
gotoxy(20,30);printf("Vous avez choisi:  %s",hotel[position-1]);
strcpy(selhot,hotel[position-1]);
selnuite=prix_nuitee[position-1];
gotoxy(15,38);printf("                                                             ");
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
getch();
}
if ((position==5) && (getch()==13))
{

    int position=1;
    int keypressed=0;
    int maxoption=5;
	int choix=0;
	char hotel[100][100]={"Pod 39 ","The Bentley","The Roxy Hotel Tribeca","Warwick New York","The Kitano"};
	float prix_nuitee[]={115,160,280,290,320};
	
 while(keypressed!=13)
{

	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  H\x93TELS NEW YORK\t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");


    keypressed=getch();

	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
        
}      
gotoxy(20,30);printf("Vous avez choisi:  %s",hotel[position-1]);
 strcpy(selhot,hotel[position-1]);
 selnuite=prix_nuitee[position-1];
 gotoxy(15,38);printf("                                                             ");
 gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
 getch();

}
if ((position==6) && (getch()==13))
{

    int position=1;
    int keypressed=0;
    int maxoption=5;
	int choix=0;
	char hotel[100][100]={"Puri Santrian","Ayodya Resort Bali","The Trans Resort Bali","The Udaya Resorts & Spa","Segara Village"};
	float prix_nuitee[]={90,110,152,180,240};

 while(keypressed!=13)
{

	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  H\x93TEL BALI        \t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");


   	keypressed=getch();

	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
}
gotoxy(20,20);printf("Vous avez choisi:  %s",hotel[position-1]);
 strcpy(selhot,hotel[position-1]);
 selnuite=prix_nuitee[position-1];
 gotoxy(15,38);printf("                                                             ");
 gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
 getch();

}
if ((position==7) && (getch()==13))
{

    int position=1;
    int keypressed=0;
    int maxoption=5;
    int choix=0;
	char hotel[100][100]={"Sura Hagia Sophia","Yasmak Sultan","Tomtom Suites","InterContinental Istanbul","Sumengen"};
	float prix_nuitee[]={140,180,222,320,390};
	
while(keypressed!=13)

{

	system("cls");
	printf("\n\n");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  H\x93TEL ISTANBUL   \t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t    \xBA  #  \xBA         H\x93tel              \xBA   Tarif nuit\x82""e x1 Adulte  \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t%.3f\n",hotel[0],prix_nuitee[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t\t%.3f\n",hotel[1],prix_nuitee[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t\t%.3f\n",hotel[2],prix_nuitee[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t%.3f\n",hotel[3],prix_nuitee[3]);
	gotoxy(12,17);curseur(5,position);printf("5\t\t%s\t\t\t%.3f\n",hotel[4],prix_nuitee[4]);
	gotoxy(12,18);curseur(6,position);printf("   \n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir un h\x93""tel");


    keypressed=getch();
	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}
}
gotoxy(20,30);printf("Vous avez choisi:  %s",hotel[position-1]);
 strcpy(selhot,hotel[position-1]);
 selnuite=prix_nuitee[position-1];
 gotoxy(15,38);printf("                                                             ");
 gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
 getch();

}

{
	int position=1;
    int keypressed=0;
    int maxoption=4;
    int choix=0;
 	char pension[5][20]={"Petit-d\x82jeuner","\xAB Pension","Pension Compl\x8Ate","All inclusive"};
 	float prix_pension[]={40,70,100,130};

    while(keypressed!=13)
{
	system("cls");
	printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xBA\t  TYPE DE PENSION    \t   \xBA\n");
	printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
	printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n\n\n\n");
	printf("\n\n\n");
	gotoxy(12,10);printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	gotoxy(12,11);printf("\xBA  #     \xBA\t    Pension        \xBA     Tarif x1 Adulte    \xBA\n");
	gotoxy(12,12);printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	gotoxy(12,13);curseur(1,position);printf("1\t\t%s\t\t\t%.3f\t\t\t\n",pension[0],prix_pension[0]);
	gotoxy(12,14);curseur(2,position);printf("2\t\t%s\t\t\t%.3f\t\t\t\n",pension[1],prix_pension[1]);
	gotoxy(12,15);curseur(3,position);printf("3\t\t%s\t\t%.3f\t\t\t\n",pension[2],prix_pension[2]);
	gotoxy(12,16);curseur(4,position);printf("4\t\t%s\t\t\t%.3f\t\t\t\n",pension[3],prix_pension[3]);
	gotoxy(12,17);curseur(6,position);printf("\n");
	gotoxy(15,38);printf("Utilisez les fl\x8A""ches HAUT et BAS pour choisir une pension");

	keypressed=getch();
	if(keypressed == 80 && position <maxoption)
	{position++;}
	else if (keypressed== 72 && position !=1){position--;}
	else {position =position;}

}
gotoxy(20,30);printf("Vous avez choisi:  %s",pension[position-1]);
strcpy(selpension,pension[position-1]);
selpensionprix=prix_pension[position-1];
gotoxy(15,38);printf("                                                             ");
gotoxy(20,38);printf("Appuyer sur une touche pour continuer ...");
getch();
system("cls");
}

printf("\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
printf("\t\t\t\xBA\t  DETAILS PERSONNELS \t   \xBA\n");
printf("\t\t\t\xBA\t\t\t\t   \xBA\n");
printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

gotoxy(8,6);printf("Nom:");
gotoxy(18,5);printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
gotoxy(18,6);printf("\t\xB3\t\t   \xB3\n");
gotoxy(18,7);printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

gotoxy(18,8);printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
gotoxy(8,9);printf("Pr\x82nom:");
gotoxy(18,9);printf("\t\xB3\t\t   \xB3\n");
gotoxy(18,10);printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

gotoxy(18,11);printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
gotoxy(8,12);printf("Tel:");
gotoxy(18,12);printf("\t\xB3\t\t   \xB3\n");
gotoxy(18,13);printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

gotoxy(18,14);printf("\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
gotoxy(8,15);printf("E-Mail:");
gotoxy(18,15);printf("\t\xB3\t\t   \xB3\n");
gotoxy(18,16);printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

gotoxy(20,38);printf("Plus qu'un etape avant la finalisation de votre reservation\n");

gotoxy(28,6);scanf("%s",&nom);
gotoxy(28,9);scanf("%s",&prenom);
gotoxy(28,12);scanf("%s",&tel);
gotoxy(28,15);scanf("%s",&mail);

gotoxy(10,26);printf("Vous paierez votre sejour dans la devise du pays ou est situe l'etablissement.\n");
gotoxy(10,27);printf("Le montant affiche (en TND) est donne \x85 titre indicatif et calcule selon\n");
gotoxy(10,28);printf("le taux de change en vigueur ce jour.\n");
getch();
system("cls");

total+=adulte*(selvol+(nuite*(selnuite+(haute_saison*15)+selpensionprix)));
total+=enfant*((0.75*selvol)+((nuite*((selnuite+haute_saison*15)/2))+selpensionprix));


printf("\n\n\n\n\n\n\n\n\n\n\n\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4");
gotoxy(22,18);
printf("Voulez vous confirmer votre reservation?\n \t Tapez O pour recevoir votre confirmation ou N pour revenir au menu destination\n\n\n\n\n\n\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4");
if (toupper(getch())=='N'){
total=0;
goto menu_destination ;

}
system("cls");
    
/***sauvegarder reservation ***/
	CHAR path[MAX_PATH]; 
    HRESULT result = SHGetFolderPath(NULL, CSIDL_DESKTOP | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT, path);
    //get desktop path
	FILE *f;
	f=fopen(strcat(path,"\\voucher.doc"),"w");
	fprintf(f,"\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	fprintf(f,"\t\n\t\t\t\xAE\xAE\xAE CONFIRMATION VOUCHER \xAF\xAF\xAF\t\t\t\xDB\xDC\xDF\xDF\xDB\n\t\t\t  \xF Booking N\xF8:%d \xF \t\t\t\xDB\xDF\xDC\n\t\t\t\t\t\t\t\t\t\xDC\xDC\xDB\xDF\xDB\n",rand);
	fprintf(f,"\t\t\t\t\t\t\t\t\t%d",rand);
	fprintf(f,"\t\n\n\n\tDear %s %s;\n",nom,prenom);
	fprintf(f,"\tYour reservation is:\n");
	fprintf(f,"\t\n \t\xF9 CONFIRMED \xF9 \t\t\t\t\t\t\t\n\n\tGreetings from  %s stuff!!!\n\n",selhot);
	fprintf(f,"\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	fprintf(f,"\t  Arrival      Departure   ");
	fprintf(f,"\n\t  %d/%d/%d     %d/%d/%d    \n",d1,m1,y1,d2,m2,y2);
	fprintf(f,"\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n");
    fprintf(f,"\t\n\t *Nights:%d\t *Adults:%d\t *Children:%d\t *Rooms:%d\t \n\n\t *Total:%.3f TND\n\n\t\n",nuite,adulte,enfant,enfant+adulte,total);
    fprintf(f,"\tYou will find a printable format of your voucher on your computer desktop.\n\n");
    fprintf(f,"\t\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE HOTEL TERMS AND CONDITIONS \xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\xFE\n\t\xAF ELIGIBLE AGE FOR CHECK-IN:\n\tYou must be at least 18 years of age to check-in and register for a room.\n\t\xAF CHECK-IN AND CHECK-OUT TIME:\n\tCheck-in time is from 3:00pm and check-out time is by 11:00am.\n\tA valid government-issued identification or passport is required at check-in.\n\n\n");
	fprintf(f,"\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	fclose(f);

/***** consulter reservation ****/
char text[100000];
f=fopen(path,"r");
while (fgets(text,sizeof(text),f))
printf("%s",text);
fclose(f);
getch();
Exit:
getch();
system("cls");
printf("\n\n**** Merci de votre confiance et bon s\x82""jour ****\n");
printf("   ___  __  __  ___  _____   ______  _______ \n");
printf("  / _ |/ / / / / _ \\/ __/ | / / __ \\/  _/ _ \\\n");
printf(" / __ / /_/ / / , _/ _/ | |/ / /_/ // // , _/\n");
printf("/_/ |_\\____/ /_/|_/___/ |___/\\____/___/_/ |_| \n");
printf("                                             ");
}

int curseur(int posreel,int poscur){
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);

	if(posreel==poscur){
	SetConsoleTextAttribute(H,7*16+1);
	printf("=>");}
	else {
    SetConsoleTextAttribute(H,1*16+7);
	printf("  ");}
}

void gotoxy(short  x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int gregoriantojd(int d, int m, int y){	
	return (y*367)-7*(y+(m+9)/12)/4+(275*m)/9+d+172101;
	}

int leap(int y){
return y%4 == 0 && y%100 != 0 || y%400 == 0;
}

int validerdate(int d,int m,int y){

	//int m_1[12][2]={31,28,31,30,31,30,31,31,30,31,30,31};
	/*int mois[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };*/
    if(d <1 || d > mois[leap(y)][m]) return -1;
	//if (leap==0) {gotoxy(16,11);printf("%s a %d jours\n",moisalpha[m-1],mois[leap][m]);}
    if(m < 1 || m >12) return 0;
}

int dayOfWeek(int d, int m, int y) {
    return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
}

void Color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}


