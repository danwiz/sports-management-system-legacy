#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <conio.h>
#include <dos.h>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <time.h>
#include <ctype.h>
#include <windows.h>

                        
#include "member.h"
#include "team.h"
#include "soccerteam.h"
#include "trackteam.h"
#include "netteam.h"
#include "socfiles.h"
#include "netfiles.h"
#include "trackfiles.h"
#include "socmatfiles.h"
#include "netmatfiles.h"
#include "trackmatfiles.h"
#include "memfiles.h"
#include "graphix.h"

#define ENTER		13
#define DOWNKEY	80
#define UPKEY		72

//Menus
char Main_Menu_Display();
void Main_Menu_Choice( char);
int Team_Menu_Display();
void Team_Menu_Choice( int);
int Team_MGMT_Menu_Display();
void Soc_Team_Menu_Choice(int);
void Net_Team_Menu_Choice(int);
void Track_Team_Menu_Choice(int);
int Match_Menu_Display();
void Match_Menu_Choice( int);
int Match_MGMT_Menu_Display();
void Soc_Match_Menu_Choice(int);
void Net_Match_Menu_Choice(int);
void Track_Match_Menu_Choice(int);
void Member_Menu_Choice(int);
int Member_Menu_Display();

//ADD EDIT VIEW DEL TEAM MGMT METHODS
void AddPlayerHeader();
void AddPlayer();
void EditPlayer();
void ViewPlayers();
void DelPlayer();

//ADD EDIT VIEW DEL TEAM MGMT METHODS
void AddSocTHeader();
void AddNetTHeader();
void AddTrackTHeader();
void AddTeam(int);
void EditTeam(int);
void ViewTeam(int);
void DelTeam(int);

//ADD EDIT VIEW DEL MATCH MGMT METHODS
void AddSocMHeader();
void AddNetMHeader();
void AddTrackMHeader();
void AddMatch(int);
void EditMatch(int);
void ViewMatch(int);
void DelMatch(int);

//extra
void ExitPro();
void OnTeams();
//Makes ths program unquie
//void Intro();
void Initializing();
void Credits();


//=========================
//Sports Management Main
//=========================

void main ()
{
  //Intro();
  Main_Menu_Choice(Main_Menu_Display());

}

//================================
// Main menu
//=================================
char Main_Menu_Display()
{
   char choice[7];
   int pos =1, keypress;

   GRAPHIX g;
   g.SetScreen();
   g.No();//hides the cursor

   textcolor(9);
   gotoxy(2, 22); cprintf("⁄ƒƒƒƒƒƒƒƒø");
	gotoxy(2, 23); cprintf("≥  Exit  ≥");
	gotoxy(2, 24); cprintf("¿ƒƒƒƒƒƒƒƒŸ");
	gotoxy(2, 2); cprintf("⁄ƒƒƒƒƒƒƒƒƒø");
	gotoxy(2, 3); cprintf("≥  elcome ≥");
	gotoxy(2, 4); cprintf("¿ƒƒƒƒƒƒƒƒƒŸ");
	gotoxy(69, 22); cprintf("⁄ƒƒƒƒƒƒƒƒƒø");
	gotoxy(69, 23); cprintf("≥  redits ≥");
	gotoxy(69, 24); cprintf("¿ƒƒƒƒƒƒƒƒƒŸ");


   g.MakeMenu(15,5,17,58,WHITE,LIGHTGREEN,false);
   g.display(25, 6,LIGHTBLUE,WHITE,"\20\20\20    SPORTS MANAGEMENT SYSTEM    \21\21\21");
   g.display(30,11,GREEN,WHITE," Team Management");
   g.display(30,12,GREEN,WHITE," Match Management");
   g.display(30,13,GREEN,WHITE," Player Management");
   g.display(30,14,GREEN,WHITE," Exit Program") ;
   g.display(30,16,LIGHTMAGENTA,WHITE," Enter Choice :") ; g.display(46,16,LIGHTMAGENTA,BLACK," ") ;

   g.display(25,11,WHITE,WHITE,"1. ");
   g.display(25,12,WHITE,WHITE,"2. ");
   g.display(25,13,WHITE,WHITE,"3. ");
   g.display(25,14,WHITE,WHITE,"4. ");

	textattr(015);
	gotoxy(4, 3); cprintf("W");
	gotoxy(71, 23); cprintf("C");
   gotoxy(29, 9); cprintf("");
   gotoxy(6, 23); cprintf("x");
   gotoxy(46, 16);
   do
   {
		 //_setcursortype(_NOCURSOR); //hides the cursor
       g.Go();//unhides the cursor
  	     if(pos==1)
         {
			  g.display(28,11,YELLOW,LIGHTGRAY,"\20");
		     g.display(30,11,WHITE,GREEN," TEAM MANAGEMENT ");
           g.display(48,11,YELLOW,LIGHTGRAY,"\21");

 		     g.display(28,12,BLACK,LIGHTGRAY,"   Match Management   ");
           g.display(28,13,BLACK,LIGHTGRAY,"   Player Management   ");
			  g.display(28,14,BLACK,LIGHTGRAY,"   Exit Program                       ");
           g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS SOCCER TEAM STATS & INFO                                  ");
           gotoxy(46, 16);
         }
         else
         {
	     		if(pos==2 )
	      	{
		     		g.display(28,11,BLACK,LIGHTGRAY,"   Team Management    ");

           		g.display(28,12,YELLOW,LIGHTGRAY,"\20");
 		     		g.display(30,12,WHITE,GREEN," MATCH MANAGEMENT ");
           		g.display(49,12,YELLOW,LIGHTGRAY,"\21");

               g.display(28,13,BLACK,LIGHTGRAY,"   Player Management   ");
			  		g.display(28,14,BLACK,LIGHTGRAY,"   Exit Program                    ");
           		g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS MATCH INFOMATION: THE TEAMs, MATCH TIME ETC...           ");
           		gotoxy(46, 16);

	      	}
            else
	     			if(pos==3 )
	      		{
		     			g.display(28,11,BLACK,LIGHTGRAY,"   Team Management    ");
                  g.display(28,12,BLACK,LIGHTGRAY,"   Match Management     ");

           			g.display(28,13,YELLOW,LIGHTGRAY,"\20");
 		     			g.display(30,13,WHITE,GREEN," PLAYER MANAGEMENT ");
           			g.display(50,13,YELLOW,LIGHTGRAY,"\21");

			  			g.display(28,14,BLACK,LIGHTGRAY,"   Exit Program                    ");
           			g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS PLAYER INFOMATION: NAME, ADRESSS FAUCLTY  ETC...         ");
           			gotoxy(46, 16);

	      	}
            else
            	if(pos==4)
            	{
		     			g.display(28,11,BLACK,LIGHTGRAY,"   Team Management    ");
                  g.display(28,12,BLACK,LIGHTGRAY,"   Match Management     ");
                  g.display(28,13,BLACK,LIGHTGRAY,"   Player Management   ");

                  g.display(28,14,YELLOW,LIGHTGRAY,"       \20  ");
                  g.display(37,14,WHITE,GREEN," EXIT PROGRAM ");
                  g.display(52,14,YELLOW,LIGHTGRAY,"\21");

                  g.display(1,25,BLACK,LIGHTGRAY, " EXITS THE PROGRAM                                                              ");
                  gotoxy(46, 16);
               }
         }
	      keypress=getch();       //gets the ascii value of keyboard key pressed
         if(keypress==49)        //if the first menu option is selected...
         	keypress=1;
         else
         	if(keypress==50)
            	keypress=2;
            else
            	if(keypress==51)
               	keypress=3;
                  if(keypress==52)
               		keypress=4;
               		else
               			if(keypress==119 || keypress==99 || keypress==120 || keypress==88 ||keypress==67 || keypress==87 )   //escape  sequences captical n  common w c x, keyboard 2 ascii conversions
                  		{
                  			if(keypress==119 || keypress==87 )
                     			*choice='W';
                     		else
                     			if(keypress==99||keypress==67)
                        			*choice='C';
                        		else
                        			if(keypress==120 || keypress==88)
                           			*choice='X';
                                 return choice[0];    //returns first char in the array, which is the option chosen
                  		}
               			if(keypress!=ENTER && keypress!= DOWNKEY&& keypress!=UPKEY && keypress-4>=pos)
                  			keypress=pos;

		   pos=g.lightup(keypress,pos,4);   //sends the position of the option selected so it casn be highlighted

      }while(keypress !=ENTER);

   if(pos==1)
		*choice ='1';
      else
      	if(pos==2)
				*choice ='2';
         else
         	if(pos==3)
					*choice ='3';
         	else
         		if(pos==4)
						*choice ='4';
   return choice[0];
}
//===========================================
//Menu_Choices  picks the  choice of the user
//===========================================

void Main_Menu_Choice( char menu)
{

	switch(menu)
   {
   	case '1':
      	Team_Menu_Choice(Team_Menu_Display()) ;
         //
			break;

      case '2':
         Match_Menu_Choice(Match_Menu_Display()) ;
         break;

      case '3':

      	Member_Menu_Choice(Member_Menu_Display());
         break;
      case '4':
         ExitPro();
      	//End();
         break;
      case 'C': case'c':
      	Initializing();
      	Credits();
         Main_Menu_Choice(Main_Menu_Display()) ;
         break;

      case 'W': case'w':
      	//Intro();
 	      Main_Menu_Choice(Main_Menu_Display()) ;

      case'X':   case'x':
      	//Initializing();
        	ExitPro();
         break;

      default:
      	Main_Menu_Choice(Main_Menu_Display()) ;
   }

}

//================================
//  Team Management Menu
//================================
int Team_Menu_Display()
{

  	int pos=1, keypress;

   GRAPHIX g;
	g.SetScreen();

   g.MakeMenu(15,5,17,58,WHITE,LIGHTGREEN,false);
   g.display(25, 6,LIGHTBLUE,WHITE,"\20\20\20    SPORTS MANAGEMENT SYSTEM    \21\21\21");
   g.display(30,11,GREEN,WHITE," Soccer Team Management");
   g.display(30,12,GREEN,WHITE," NetBall Team Management");
   g.display(30,13,GREEN,WHITE," Track&Field Team Management");
   g.display(30,14,GREEN,WHITE," Return To Main") ;

   g.display(30,17,LIGHTMAGENTA,WHITE," Enter Choice :") ;
   g.display(46,17,LIGHTMAGENTA,BLACK," ") ;

   g.display(25,11,WHITE,WHITE,"1. ");
   g.display(25,12,WHITE,WHITE,"2. ");
   g.display(25,13,WHITE,WHITE,"3. ");
   g.display(25,14,WHITE,WHITE,"4. ");

	gotoxy(46, 17);

   do
   {
		 //_setcursortype(_NOCURSOR); //hides the cursor
       g.Go();//unhides the cursor
  	     if(pos==1)
         {
			  g.display(28,11,YELLOW,LIGHTGRAY,"\20");
		     g.display(30,11,WHITE,GREEN," SOCCER TEAM MANAGEMENT ");
           g.display(55,11,YELLOW,LIGHTGRAY,"\21");

 		     g.display(28,12,BLACK,LIGHTGRAY,"   NetBall Team Management   ");
           g.display(28,13,BLACK,LIGHTGRAY,"   Track&Field Team Management   ");
			  g.display(28,14,BLACK,LIGHTGRAY,"   Return To Main                    ");
           g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS SOCCER TEAM STATS & INFO                                  ");
           gotoxy(46, 17);
         }
         else
         {
	     		if(pos==2 )
	      	{
		     		g.display(28,11,BLACK,LIGHTGRAY,"   Soccer Team Management    ");

           		g.display(28,12,YELLOW,LIGHTGRAY,"\20");
 		     		g.display(30,12,WHITE,GREEN," NETBALL TEAM MANAGEMENT ");
           		g.display(56,12,YELLOW,LIGHTGRAY,"\21");

               g.display(28,13,BLACK,LIGHTGRAY,"   Track&Field Team Management   ");
			  		g.display(28,14,BLACK,LIGHTGRAY,"   Return To Main                ");
           		g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS NETBALL TEAM STATS & INFO                                ");
           		gotoxy(46, 17);

	      	}
            else
            	if(pos==3 )
            	{
		     			g.display(28,11,BLACK,LIGHTGRAY,"   Soccer Team Management    ");
                  g.display(28,12,BLACK,LIGHTGRAY,"   NetBall Team Management     ");

           			g.display(28,13,YELLOW,LIGHTGRAY,"\20");
 		     			g.display(30,13,WHITE,GREEN," TRACK&FIELD TEAM MANAGEMENT ");
           			g.display(60,13,YELLOW,LIGHTGRAY,"\21");

			  			g.display(28,14,BLACK,LIGHTGRAY,"   Return To Main                 ");
           			g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS NETBALL TEAM STATS & INFO                                ");
           			gotoxy(46, 17);

	      		}
            	else
        				if(pos==4 )
	      			{
                  	g.display(28,11,BLACK,LIGHTGRAY,"   Soccer Team Management    ");
  		     				g.display(28,12,BLACK,LIGHTGRAY,"   NetBall Team Management     ");
 		     				g.display(28,13,BLACK,LIGHTGRAY,"   Track&Field Team Management    ");

           				g.display(28,14,YELLOW,LIGHTGRAY,"       \20  ");
			  				g.display(37,14,WHITE,GREEN," RETURN TO MAIN MENU ");
           				g.display(59,14,YELLOW,LIGHTGRAY,"\21");

           				g.display(1,25,BLACK,LIGHTGRAY, " RETURNS TO PREVIOUS MENU OPTIONS                                               ");
           				gotoxy(46, 17);
	      			}
         }
	      keypress=getch();       //gets the ascii value of keyboard key press
         if(keypress==49)
         	keypress=1;
         else
         	if(keypress==50)
            	keypress=2;
            else
            	if(keypress==51)
               	keypress=3;
               else
               	if(keypress==52)
               		keypress=4;

                  if(keypress!=ENTER && keypress!= DOWNKEY&& keypress!=UPKEY && keypress-4>=pos)   //
                  	keypress=pos;

		   pos=g.lightup(keypress,pos,4);

      }while(keypress !=ENTER);

   return pos;
}

//======================================================
//Team Menu choice   picks the  choice of the user
//======================================================

void Team_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	Soc_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;          //displays create edit veiw n delteoptions 4 soccer team
      break;

      case 2:                                                //displays create edit veiw n delteoptions 4 netball team
      	Net_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 3:
      	Track_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;      //displays create edit veiw n delteoptions 4 track team
      break;

      case 4:
      	Main_Menu_Choice(Main_Menu_Display()) ;
         break;
      default:
      	Team_Menu_Choice(Team_Menu_Display()) ;

   }

}
//================================
//  Team  Managemant menu
//================================
int Team_MGMT_Menu_Display()
{

  	int pos=1, keypress;

   GRAPHIX g;
	g.SetScreen();

   g.MakeMenu(13,5,17,62,WHITE,LIGHTMAGENTA,false);

   g.display(25, 6,LIGHTRED,WHITE,"   \2\2     Team Management    \2\2     ");
   g.display(36, 7,BLUE,WHITE,"\37\37");
   g.display(48, 7,BLUE,WHITE,"\37\37");
   textcolor(2);
   g.display(25, 10,LIGHTBLUE,WHITE," Create New Team") ;
   g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Team") ;
   g.display(25, 12,LIGHTBLUE,WHITE," Display Team Infomation") ;
   g.display(25, 13,LIGHTBLUE,WHITE," Delete Team") ;
   g.display(25, 14,LIGHTBLUE,WHITE," Return To to Main Menu") ;

   textattr(14 + 128);
   gotoxy(26, 17); cprintf("Enter Choice :") ;

   textcolor(2);
   g.display(20,  10,WHITE,WHITE,"1.");
   g.display(20,  11,WHITE,WHITE,"2.");
   g.display(20,  12,WHITE,WHITE,"3.");
   g.display(20,  13,WHITE,WHITE,"4.");
   g.display(20,  14,WHITE,WHITE,"5.");

	gotoxy(46, 17);
   do
   {
		 //_setcursortype(_NOCURSOR); //hides the cursor
       g.Go();//unhides the cursor
  	     if(pos==1)
         {
            g.display(20,  11,WHITE,WHITE,"2.");
   			g.display(20,  12,WHITE,WHITE,"3.");
   			g.display(20,  13,WHITE,WHITE,"4.");
   			g.display(20,  14,WHITE,WHITE,"5.");


			  g.display(23,10,LIGHTBLUE,LIGHTGRAY,"            \20 ");
		     g.display(37,10,WHITE,LIGHTMAGENTA," CREATE A NEW TEAM ");
           g.display(57,10,LIGHTBLUE,LIGHTGRAY,"\21");
           g.display(20,10,BLUE,WHITE,"1.");

 		     g.display(23,11,LIGHTBLUE,WHITE,"   Edit An Existing Team                      ");
           g.display(23,12,LIGHTBLUE,WHITE,"   Display Team Infomation                    ");
			  g.display(23,13,LIGHTBLUE,WHITE,"   Delete Team                                ");
           g.display(23,14,LIGHTBLUE,WHITE,"   Return To Main Menu                        ") ;
           g.display(1,25,BLACK,LIGHTGRAY, " CREATES A NEW TEAM PREPARE FOR DATA ENTRY, TEAM: TITLE,COACH, ETC.            ");
           gotoxy(41, 17);
         }
         else
         {
	     		if(pos==2 )
	      	{
            	g.display(20,  10,WHITE,WHITE,"1.");
               g.display(20,  12,WHITE,WHITE,"3.");
   			   g.display(20,  13,WHITE,WHITE,"4.");
   				g.display(20,  14,WHITE,WHITE,"5.");

               g.display(23,10,LIGHTBLUE,WHITE,"   Create New Team                       ");

               g.display(23,11,LIGHTBLUE,LIGHTGRAY,"      \20 ");
               g.display(31,11,WHITE,LIGHTMAGENTA," EDIT AN EXISTING TEAM ");
               g.display(54,11,LIGHTBLUE,LIGHTGRAY,"\21");
               g.display(20,11,BLUE, WHITE,"2.");

               g.display(23,12,LIGHTBLUE,WHITE,"   Display Team Infomation             ") ;
               g.display(23,13,LIGHTBLUE,WHITE,"   Delete Team                         ") ;
               g.display(23,14,LIGHTBLUE,WHITE,"   Return To Main Menu                 ") ;
               g.display(1,25,BLACK,LIGHTGRAY, " EDITS A  TEAM'S INFO: PLAYERS, REDS CARDS, ETC.                               ");
               gotoxy(41, 17);

	      	}
            else
            {
        			if(pos==3 )
	      		{
               	g.display(20,  10,WHITE,WHITE,"1.");
               	g.display(20,  11,WHITE,WHITE,"2.");
               	g.display(20,  13,WHITE,WHITE,"4.");
   					g.display(20,  14,WHITE,WHITE,"5.");

                  g.display(23,10,LIGHTBLUE,WHITE,"   Create New Team                     ");
                  g.display(23,11,LIGHTBLUE,WHITE,"   Edit An Existing Team                   ");

                  g.display(23,12,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                  g.display(34,12,WHITE,LIGHTMAGENTA," DISPLAY TEAM INFOMATION ");
                  g.display(59,12,LIGHTBLUE,LIGHTGRAY,"\21");
                  g.display(20,12,BLUE,WHITE,"3.");

                  g.display(23,13,LIGHTBLUE,WHITE,"   Delete Team                          ") ;
                  g.display(23,14,LIGHTBLUE,WHITE,"   Return To to Main Menu               ") ;
                  g.display(2,25,BLACK,LIGHTGRAY, " PERMANENTLY DELETES A TEAM: ALL THE TEAM's INFO IS DESTROYED                    ");
                  gotoxy(41, 17);




	      		}
               else
               	if(pos==4 )
	      			{

                  	g.display(20,  10,WHITE,WHITE,"1.");
                  	g.display(20,  11,WHITE,WHITE,"2.");
   						g.display(20,  12,WHITE,WHITE,"3.");
   						g.display(20,  14,WHITE,WHITE,"5.");

                     g.display(25, 10,LIGHTBLUE,WHITE," Create New Team                       ") ;
                     g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Team                 ") ;
                     g.display(25, 12,LIGHTBLUE,WHITE," Display Team Infomation               ") ;

                     g.display(23,13,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                     g.display(34,13,WHITE,LIGHTMAGENTA," DELETE A TEAM ");
                     g.display(50,13,LIGHTBLUE,LIGHTGRAY,"\21");
                     g.display(20,13,BLUE,WHITE,"4.");

                     g.display(23,14,LIGHTBLUE,WHITE,"   Return To to Main Menu              ") ;
                  	g.display(2,25,BLACK,LIGHTGRAY, " PERMANENTLY DELETES A TEAM: ALL THE TEAM's INFO IS DESTROYED                    ");
                  	gotoxy(41, 17);

	      		   }
                  else
                  	if(pos==5)
                  	{

                        g.display(20,  10,WHITE,WHITE,"1.");
   							g.display(20,  11,WHITE,WHITE,"2.");
   							g.display(20,  12,WHITE,WHITE,"3.");
   							g.display(20,  13,WHITE,WHITE,"4.");

                        g.display(25, 10,LIGHTBLUE,WHITE," Create New Team                       ") ;
   							g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Team                 ") ;
   							g.display(25, 12,LIGHTBLUE,WHITE," Display Team Infomation               ") ;
                        g.display(25, 13,LIGHTBLUE,WHITE," Delete Team                           ") ;

                        g.display(23,14,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                        g.display(34,14,WHITE,LIGHTMAGENTA," RETURN TO MAIN MENU ");
                        g.display(56,14,LIGHTBLUE,LIGHTGRAY,"\21");
                        g.display(20,14,BLUE,WHITE, "5.");

                        g.display(2,25,BLACK,LIGHTGRAY, " EXITS THIS MENU.....RETURN YOU TO THE MAIN MENU                               ");

           					gotoxy(41, 17);


                  	}


            }
         }
	      keypress=getch();
         if(keypress==49)
         	keypress=1;
         else
         	if(keypress==50)
            	keypress=2;
            else
            	if(keypress==51)
               	keypress=3;
               else
               	if(keypress==52)
               		keypress=4;
               	else
                  	if(keypress==53)
               			keypress=5;
               		else
               	if(keypress!=ENTER && keypress!= DOWNKEY&& keypress!=UPKEY && keypress-5>=pos)
                  	keypress=pos;

		   pos=g.lightup(keypress,pos,5);

      }while(keypress !=ENTER);

   return pos;
}
//======================================================
//soccer Team Menu choice   picks the  choice of the user
//======================================================
void Soc_Team_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddTeam(1);
      	Soc_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 2:
         EditTeam(1);
      	Soc_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 3:
         ViewTeam(1);
      	Soc_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 4:
      	DelTeam(1);
      	Soc_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 5:
      	Team_Menu_Choice(Team_Menu_Display()) ;
         break;
      default:
      	Soc_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;

   }

}

//======================================================
//NetBall Team Menu choice   picks the  choice of the user
//======================================================
void Net_Team_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddTeam(2);
      	Net_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 2:
      	EditTeam(2);
      	Net_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 3:
      	ViewTeam(2);
      	Net_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 4:
      	DelTeam(2);
      	Net_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 5:
      	Team_Menu_Choice(Team_Menu_Display()) ;
         break;
      default:
      	Net_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;

   }

}

//======================================================
//track Team Menu choice   picks the  choice of the user
//======================================================
void Track_Team_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddTeam(3);
      	Track_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 2:
         EditTeam(3);
      	Track_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 3:
      	ViewTeam(3);
      	Track_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 4:
      	DelTeam(3);
      	Track_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;
      break;

      case 5:
      	Team_Menu_Choice(Team_Menu_Display()) ;
         break;
      default:
      	Track_Team_Menu_Choice(Team_MGMT_Menu_Display()) ;

   }

}

//================================
//  Match Management Menu
//================================
int Match_Menu_Display()
{

  	int pos=1, keypress;

   GRAPHIX g;
	g.SetScreen();

   g.MakeMenu(15,5,17,58,WHITE,LIGHTGREEN,false);
   g.display(25, 6,LIGHTBLUE,WHITE,"\20\20\20    MATCH MANAGEMENT SYSTEM    \21\21\21");
   g.display(30,11,GREEN,WHITE," Soccer Match Management");
   g.display(30,12,GREEN,WHITE," NetBall Match Management");
   g.display(30,13,GREEN,WHITE," Track&Field Match Management");
   g.display(30,14,GREEN,WHITE," Return To Main") ;

   g.display(30,17,LIGHTMAGENTA,WHITE," Enter Choice :") ;
   g.display(46,17,LIGHTMAGENTA,BLACK," ") ;

   g.display(25,11,WHITE,WHITE,"1. ");
   g.display(25,12,WHITE,WHITE,"2. ");
   g.display(25,13,WHITE,WHITE,"3. ");
   g.display(25,14,WHITE,WHITE,"4. ");

	gotoxy(46, 17);

   do
   {
		 //_setcursortype(_NOCURSOR); //hides the cursor
       g.Go();//unhides the cursor
  	     if(pos==1)
         {
			  g.display(28,11,YELLOW,LIGHTGRAY,"\20");
		     g.display(30,11,WHITE,GREEN," SOCCER MATCH MANAGEMENT ");
           g.display(56,11,YELLOW,LIGHTGRAY,"\21");

 		     g.display(28,12,BLACK,LIGHTGRAY,"   NetBall Match Management   ");
           g.display(28,13,BLACK,LIGHTGRAY,"   Track&Field Match Management   ");
			  g.display(28,14,BLACK,LIGHTGRAY,"   Return To Main                    ");
           g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS SOCCER MATCHES STATS & INFO                               ");
           gotoxy(46, 17);
         }
         else
         {
	     		if(pos==2 )
	      	{
		     		g.display(28,11,BLACK,LIGHTGRAY,"   Soccer Match Management    ");

           		g.display(28,12,YELLOW,LIGHTGRAY,"\20");
 		     		g.display(30,12,WHITE,GREEN," NETBALL MATCH MANAGEMENT ");
           		g.display(57,12,YELLOW,LIGHTGRAY,"\21");

               g.display(28,13,BLACK,LIGHTGRAY,"   Track&Field Match Management   ");
			  		g.display(28,14,BLACK,LIGHTGRAY,"   Return To Main                ");
           		g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS NETBALL MATCHES STATS & INFO                             ");
           		gotoxy(46, 17);

	      	}
            else
            	if(pos==3 )
            	{
		     			g.display(28,11,BLACK,LIGHTGRAY,"   Soccer Match Management    ");
                  g.display(28,12,BLACK,LIGHTGRAY,"   NetBall Match Management     ");

           			g.display(28,13,YELLOW,LIGHTGRAY,"\20");
 		     			g.display(30,13,WHITE,GREEN," TRACK&FIELD MATCH MANAGEMENT ");
           			g.display(61,13,YELLOW,LIGHTGRAY,"\21");

			  			g.display(28,14,BLACK,LIGHTGRAY,"   Return To Main                 ");
           			g.display(1,25,BLACK,LIGHTGRAY, " ADDS,EDITS & DISPLAYS TRACK MATCHES STATS & INFO                               ");
           			gotoxy(46, 17);

	      		}
            	else
        				if(pos==4 )
	      			{
                  	g.display(28,11,BLACK,LIGHTGRAY,"   Soccer Match Management    ");
  		     				g.display(28,12,BLACK,LIGHTGRAY,"   NetBall Match Management     ");
 		     				g.display(28,13,BLACK,LIGHTGRAY,"   Track&Field Match Management    ");

           				g.display(28,14,YELLOW,LIGHTGRAY,"       \20  ");
			  				g.display(37,14,WHITE,GREEN," RETURN TO MAIN MENU ");
           				g.display(59,14,YELLOW,LIGHTGRAY,"\21");

           				g.display(1,25,BLACK,LIGHTGRAY, " RETURNS TO PREVIOUS MENU OPTIONS                                               ");
           				gotoxy(46, 17);
	      			}
         }
	      keypress=getch();       //gets the ascii value of keyboard key press
         if(keypress==49)
         	keypress=1;
         else
         	if(keypress==50)
            	keypress=2;
            else
            	if(keypress==51)
               	keypress=3;
               else
               	if(keypress==52)
               		keypress=4;

                  if(keypress!=ENTER && keypress!= DOWNKEY&& keypress!=UPKEY && keypress-4>=pos)   //
                  	keypress=pos;

		   pos=g.lightup(keypress,pos,4);

      }while(keypress !=ENTER);

   return pos;
}

//======================================================
//Team Menu choice   picks the  choice of the user
//======================================================

void Match_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	Soc_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 2:
      	Net_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 3:
      	Track_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 4:
      	Main_Menu_Choice(Main_Menu_Display()) ;
         break;
      default:
      	Match_Menu_Choice(Match_Menu_Display()) ;

   }

}
//================================
//  Team  Managemant menu
//================================
int Match_MGMT_Menu_Display()
{

  	int pos=1, keypress;

   GRAPHIX g;
	g.SetScreen();

   g.MakeMenu(13,5,17,62,WHITE,LIGHTMAGENTA,false);

   g.display(25, 6,LIGHTRED,WHITE,"   \3\3    Match Management   \3\3     ");
   g.display(36, 7,BLUE,WHITE,"\37\37");
   g.display(48, 7,BLUE,WHITE,"\37\37");
   textcolor(2);
   g.display(25, 10,LIGHTBLUE,WHITE," Create New Match Entry") ;
   g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Match") ;
   g.display(25, 12,LIGHTBLUE,WHITE," Display Match Infomation") ;
   g.display(25, 13,LIGHTBLUE,WHITE," Delete Match") ;
   g.display(25, 14,LIGHTBLUE,WHITE," Return To Previous Menu ") ;

   textattr(14 + 128);
   gotoxy(26, 17); cprintf("Enter Choice :") ;

   textcolor(2);
   g.display(20,  10,WHITE,WHITE,"1.");
   g.display(20,  11,WHITE,WHITE,"2.");
   g.display(20,  12,WHITE,WHITE,"3.");
   g.display(20,  13,WHITE,WHITE,"4.");
   g.display(20,  14,WHITE,WHITE,"5.");

	gotoxy(46, 17);
   do
   {
		 //_setcursortype(_NOCURSOR); //hides the cursor
       g.Go();//unhides the cursor
  	     if(pos==1)
         {
            g.display(20,  11,WHITE,WHITE,"2.");
   			g.display(20,  12,WHITE,WHITE,"3.");
   			g.display(20,  13,WHITE,WHITE,"4.");
   			g.display(20,  14,WHITE,WHITE,"5.");


			  g.display(23,10,LIGHTBLUE,LIGHTGRAY,"            \20 ");
		     g.display(37,10,WHITE,LIGHTMAGENTA," CREATE A NEW MATCH ENTRY ");
           g.display(64,10,LIGHTBLUE,LIGHTGRAY,"\21");
           g.display(20,10,BLUE,WHITE,"1.");

 		     g.display(23,11,LIGHTBLUE,WHITE,"   Edit An Existing Match                      ");
           g.display(23,12,LIGHTBLUE,WHITE,"   Display Match Infomation                    ");
			  g.display(23,13,LIGHTBLUE,WHITE,"   Delete Match                                ");
           g.display(23,14,LIGHTBLUE,WHITE,"   Return To Previous Menu                     ") ;
           g.display(1,25,BLACK,LIGHTGRAY, " CREATES A NEW MATCH ENTRY PREPARE MATCH DATA:TEAMS,LOCTAION, MATCHTIME ETC... ");
           gotoxy(41, 17);
         }
         else
         {
	     		if(pos==2 )
	      	{
            	g.display(20,  10,WHITE,WHITE,"1.");
               g.display(20,  12,WHITE,WHITE,"3.");
   			   g.display(20,  13,WHITE,WHITE,"4.");
   				g.display(20,  14,WHITE,WHITE,"5.");

               g.display(23,10,LIGHTBLUE,WHITE,"   Create New Match Entry                       ");

               g.display(23,11,LIGHTBLUE,LIGHTGRAY,"      \20 ");
               g.display(31,11,WHITE,LIGHTMAGENTA," EDIT AN EXISTING MATCH ");
               g.display(55,11,LIGHTBLUE,LIGHTGRAY,"\21");
               g.display(20,11,BLUE, WHITE,"2.");

               g.display(23,12,LIGHTBLUE,WHITE,"   Display Match Infomation             ") ;
               g.display(23,13,LIGHTBLUE,WHITE,"   Delete Match                         ") ;
               g.display(23,14,LIGHTBLUE,WHITE,"   RReturn To Previous Menu             ") ;
               g.display(1,25,BLACK,LIGHTGRAY, " EDITS A  MATCH INFO: TEAMS, LOCATION, RESULTS, ETC...                         ");
               gotoxy(41, 17);

	      	}
            else
            {
        			if(pos==3 )
	      		{
               	g.display(20,  10,WHITE,WHITE,"1.");
               	g.display(20,  11,WHITE,WHITE,"2.");
               	g.display(20,  13,WHITE,WHITE,"4.");
   					g.display(20,  14,WHITE,WHITE,"5.");

                  g.display(23,10,LIGHTBLUE,WHITE,"   Create New Match Entry                    ");
                  g.display(23,11,LIGHTBLUE,WHITE,"   Edit An Existing Match                   ");

                  g.display(23,12,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                  g.display(34,12,WHITE,LIGHTMAGENTA," DISPLAY MATCH INFOMATION ");
                  g.display(61,12,LIGHTBLUE,LIGHTGRAY,"\21");
                  g.display(20,12,BLUE,WHITE,"3.");

                  g.display(23,13,LIGHTBLUE,WHITE,"   Delete Match                         ") ;
                  g.display(23,14,LIGHTBLUE,WHITE,"   Return To Previous Menu              ") ;
                  g.display(2,25,BLACK,LIGHTGRAY, " DISPLAYS MATCH INFOMATION: MATCH STATS INCLUDING SCORES & MVP                 ");
                  gotoxy(41, 17);




	      		}
               else
               	if(pos==4 )
	      			{

                  	g.display(20,  10,WHITE,WHITE,"1.");
                  	g.display(20,  11,WHITE,WHITE,"2.");
   						g.display(20,  12,WHITE,WHITE,"3.");
   						g.display(20,  14,WHITE,WHITE,"5.");

                     g.display(25, 10,LIGHTBLUE,WHITE," Create New Match Entry                 ") ;
                     g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Match                 ") ;
                     g.display(25, 12,LIGHTBLUE,WHITE," Display Match Infomation               ") ;

                     g.display(23,13,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                     g.display(34,13,WHITE,LIGHTMAGENTA," DELETE A MATCH ");
                     g.display(51,13,LIGHTBLUE,LIGHTGRAY,"\21");
                     g.display(20,13,BLUE,WHITE,"4.");

                     g.display(23,14,LIGHTBLUE,WHITE,"   Return To Previous Menu               ") ;
                  	g.display(2,25,BLACK,LIGHTGRAY, " PERMANENTLY DELETES A TEAM: ALL THE TEAM's INFO IS DESTROYED                    ");
                  	gotoxy(41, 17);

	      		   }
                  else
                  	if(pos==5)
                  	{

                        g.display(20,  10,WHITE,WHITE,"1.");
   							g.display(20,  11,WHITE,WHITE,"2.");
   							g.display(20,  12,WHITE,WHITE,"3.");
   							g.display(20,  13,WHITE,WHITE,"4.");

                        g.display(25, 10,LIGHTBLUE,WHITE," Create New Match Entry                ") ;
   							g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Match                ") ;
   							g.display(25, 12,LIGHTBLUE,WHITE," Display Match Infomation              ") ;
                        g.display(25, 13,LIGHTBLUE,WHITE," Delete Match                          ") ;

                        g.display(23,14,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                        g.display(34,14,WHITE,LIGHTMAGENTA," RETURN TO PREVIOUS MENU ");
                        g.display(59,14,LIGHTBLUE,LIGHTGRAY,"\21");
                        g.display(20,14,BLUE,WHITE, "5.");
                                                                                                                                        
                        g.display(2,25,BLACK,LIGHTGRAY, " EXITS THIS MENU.....RETURN YOU TO THE PREVIOUS MENU                           ");

           					gotoxy(41, 17);


                  	}


            }
         }
	      keypress=getch();
         if(keypress==49)
         	keypress=1;
         else
         	if(keypress==50)
            	keypress=2;
            else
            	if(keypress==51)
               	keypress=3;
               else
               	if(keypress==52)
               		keypress=4;
               	else
                  	if(keypress==53)
               			keypress=5;
               		else
               	if(keypress!=ENTER && keypress!= DOWNKEY&& keypress!=UPKEY && keypress-5>=pos)
                  	keypress=pos;

		   pos=g.lightup(keypress,pos,5);

      }while(keypress !=ENTER);

   return pos;
}
//======================================================
//soccer match Menu choice   picks the  choice of the user
//======================================================
void Soc_Match_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddMatch(1);
      	Soc_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 2:
      	AddMatch(1);
      	Soc_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 3:
      	AddMatch(1);
      	Soc_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 4:
      	AddMatch(1);
      	Soc_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 5:
      	Match_Menu_Choice(Match_Menu_Display()) ;
         break;
      default:
      	Soc_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;

   }

}

//======================================================
//NetBall match Menu choice   picks the  choice of the user
//======================================================
void Net_Match_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddMatch(2);
      	Net_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 2:
      	EditMatch(2);
      	Net_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 3:
      	ViewMatch(2);
      	Net_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 4:
      	DelMatch(2);
      	Net_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 5:
      	Match_Menu_Choice(Match_Menu_Display()) ;
         break;
      default:
      	Net_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;

   }

}

//======================================================
//track Team Menu choice   picks the  choice of the user
//======================================================
void Track_Match_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddMatch(3);
      	Track_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 2:
      	EditMatch(3);
      	Track_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 3:
      	ViewMatch(3);
      	Track_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 4:
      	DelMatch(3);
      	Track_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;
      break;

      case 5:
      	Match_Menu_Choice(Match_Menu_Display()) ;
      break;
      default:
      	Track_Match_Menu_Choice(Match_MGMT_Menu_Display()) ;

   }

}
//================================
//  Team  Managemant menu
//================================
int Member_Menu_Display()
{

  	int pos=1, keypress;

   GRAPHIX g;
	g.SetScreen();

   g.MakeMenu(13,5,17,62,WHITE,LIGHTMAGENTA,false);

   g.display(25, 6,LIGHTRED,WHITE,"   \1\1    Member Management   \1\1     ");
   g.display(36, 7,BLUE,WHITE,"\38\38");
   g.display(48, 7,BLUE,WHITE,"\38\38");
   textcolor(2);
   g.display(25, 10,LIGHTBLUE,WHITE," Create Member") ;
   g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Member") ;
   g.display(25, 12,LIGHTBLUE,WHITE," Display Member Infomation") ;
   g.display(25, 13,LIGHTBLUE,WHITE," Delete Member") ;
   g.display(25, 14,LIGHTBLUE,WHITE," Return To to Main Menu") ;

   textattr(14 + 128);
   gotoxy(26, 17); cprintf("Enter Choice :") ;

   textcolor(2);
   g.display(20,  10,WHITE,WHITE,"1.");
   g.display(20,  11,WHITE,WHITE,"2.");
   g.display(20,  12,WHITE,WHITE,"3.");
   g.display(20,  13,WHITE,WHITE,"4.");
   g.display(20,  14,WHITE,WHITE,"5.");

	gotoxy(46, 17);
   do
   {
		 //_setcursortype(_NOCURSOR); //hides the cursor
       g.Go();//unhides the cursor
  	     if(pos==1)
         {
            g.display(20,  11,WHITE,WHITE,"2.");
   			g.display(20,  12,WHITE,WHITE,"3.");
   			g.display(20,  13,WHITE,WHITE,"4.");
   			g.display(20,  14,WHITE,WHITE,"5.");


			  g.display(23,10,LIGHTBLUE,LIGHTGRAY,"            \20 ");
		     g.display(37,10,WHITE,LIGHTMAGENTA," CREATE A NEW MEMBER ");
           g.display(58,10,LIGHTBLUE,LIGHTGRAY,"\21");
           g.display(20,10,BLUE,WHITE,"1.");

 		     g.display(23,11,LIGHTBLUE,WHITE,"   Edit An Existing Player                    ");
           g.display(23,12,LIGHTBLUE,WHITE,"   Display Player Infomation                  ");
			  g.display(23,13,LIGHTBLUE,WHITE,"   Delete Player                              ");
           g.display(23,14,LIGHTBLUE,WHITE,"   Return To Main Menu                        ") ;
           g.display(1,25,BLACK,LIGHTGRAY, " CREATES A NEW MEMBER PREPARE FOR DATA ENTRY, MEMBER: NAME,ADDRESS, ETC...     ");
           gotoxy(41, 17);
         }
         else
         {
	     		if(pos==2 )
	      	{
            	g.display(20,  10,WHITE,WHITE,"1.");
               g.display(20,  12,WHITE,WHITE,"3.");
   			   g.display(20,  13,WHITE,WHITE,"4.");
   				g.display(20,  14,WHITE,WHITE,"5.");

               g.display(23,10,LIGHTBLUE,WHITE,"   Create New Player                       ");

               g.display(23,11,LIGHTBLUE,LIGHTGRAY,"      \20 ");
               g.display(31,11,WHITE,LIGHTMAGENTA," EDIT AN EXISTING PLAYER ");
               g.display(57,11,LIGHTBLUE,LIGHTGRAY,"\21");
               g.display(20,11,BLUE, WHITE,"2.");

               g.display(23,12,LIGHTBLUE,WHITE,"   Display Player Infomation             ") ;
               g.display(23,13,LIGHTBLUE,WHITE,"   Delete Player                         ") ;
               g.display(23,14,LIGHTBLUE,WHITE,"   Return To Main Menu                 ") ;
               g.display(1,25,BLACK,LIGHTGRAY, " DELETES A PLAYER: ALL THE PLAYER'S INFO IS DESTROYED                             ");
               gotoxy(41, 17);

	      	}
            else
            {
        			if(pos==3 )
	      		{
               	g.display(20,  10,WHITE,WHITE,"1.");
               	g.display(20,  11,WHITE,WHITE,"2.");
               	g.display(20,  13,WHITE,WHITE,"4.");
   					g.display(20,  14,WHITE,WHITE,"5.");

                  g.display(23,10,LIGHTBLUE,WHITE,"   Create New Player                     ");
                  g.display(23,11,LIGHTBLUE,WHITE,"   Edit An Existing Player                   ");

                  g.display(23,12,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                  g.display(34,12,WHITE,LIGHTMAGENTA," DISPLAY PLAYER INFOMATION ");
                  g.display(62,12,LIGHTBLUE,LIGHTGRAY,"\21");
                  g.display(20,12,BLUE,WHITE,"3.");

                  g.display(23,13,LIGHTBLUE,WHITE,"   Delete Player                          ") ;
                  g.display(23,14,LIGHTBLUE,WHITE,"   Return To to Main Menu               ") ;
                  g.display(2,25,BLACK,LIGHTGRAY,     " SHOWS A PLAYER: ALL THE PLAYER'S INFO IS DESTROYED                              ");
                  gotoxy(41, 17);




	      		}
               else
               	if(pos==4 )
	      			{

                  	g.display(20,  10,WHITE,WHITE,"1.");
                  	g.display(20,  11,WHITE,WHITE,"2.");
   						g.display(20,  12,WHITE,WHITE,"3.");
   						g.display(20,  14,WHITE,WHITE,"5.");

                     g.display(25, 10,LIGHTBLUE,WHITE," Create New Player                       ") ;
                     g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Player                 ") ;
                     g.display(25, 12,LIGHTBLUE,WHITE," Display Player Infomation               ") ;

                     g.display(23,13,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                     g.display(34,13,WHITE,LIGHTMAGENTA," DELETE A PLAYER ");
                     g.display(52,13,LIGHTBLUE,LIGHTGRAY,"\21");
                     g.display(20,13,BLUE,WHITE,"4.");

                     g.display(23,14,LIGHTBLUE,WHITE,"   Return To to Main Menu              ") ;
                  	g.display(2,25,BLACK,LIGHTGRAY, " PERMANENTLY DELETES A PLAYER: ALL THE PLAYER'S INFO IS DESTROYED                 ");
                  	gotoxy(41, 17);

	      		   }
                  else
                  	if(pos==5)
                  	{

                        g.display(20,  10,WHITE,WHITE,"1.");
   							g.display(20,  11,WHITE,WHITE,"2.");
   							g.display(20,  12,WHITE,WHITE,"3.");
   							g.display(20,  13,WHITE,WHITE,"4.");

                        g.display(25, 10,LIGHTBLUE,WHITE," Create New Player                       ") ;
   							g.display(25, 11,LIGHTBLUE,WHITE," Edit An Existing Player                 ") ;
   							g.display(25, 12,LIGHTBLUE,WHITE," Display Player Infomation               ") ;
                        g.display(25, 13,LIGHTBLUE,WHITE," Delete Player                           ") ;

                        g.display(23,14,LIGHTBLUE,LIGHTGRAY,"         \20 ");
                        g.display(34,14,WHITE,LIGHTMAGENTA," RETURN TO MAIN MENU ");
                        g.display(56,14,LIGHTBLUE,LIGHTGRAY,"\21");
                        g.display(20,14,BLUE,WHITE, "5.");

                        g.display(2,25,BLACK,LIGHTGRAY, " EXITS THIS MENU.....RETURN YOU TO THE MAIN MENU                               ");

           					gotoxy(41, 17);


                  	}


            }
         }
	      keypress=getch();
         if(keypress==49)
         	keypress=1;
         else
         	if(keypress==50)
            	keypress=2;
            else
            	if(keypress==51)
               	keypress=3;
               else
               	if(keypress==52)
               		keypress=4;
               	else
                  	if(keypress==53)
               			keypress=5;
               		else
               	if(keypress!=ENTER && keypress!= DOWNKEY&& keypress!=UPKEY && keypress-5>=pos)
                  	keypress=pos;

		   pos=g.lightup(keypress,pos,5);

      }while(keypress !=ENTER);

   return pos;
}
//======================================================
//soccer Member Menu choice   picks the  choice of the user
//======================================================
void Member_Menu_Choice( int menu)
{
   GRAPHIX g;

	g.SetScreen();

	switch(menu)
   {
   	case 1:
      	AddPlayer();
      	Member_Menu_Choice(Member_Menu_Display()) ;
      break;

      case 2:
         EditPlayer();
      	Member_Menu_Choice(Member_Menu_Display()) ;
      break;

      case 3:
         ViewPlayers();
      	Member_Menu_Choice(Member_Menu_Display()) ;
      break;

      case 4:
      	DelPlayer();
      	Member_Menu_Choice(Member_Menu_Display()) ;
      break;

      case 5:
         Main_Menu_Choice(Main_Menu_Display()) ;
         break;
      default:
      	Member_Menu_Choice(Member_Menu_Display()) ;

   }

}

//=============================
//Create Players Header
//============================
void AddPlayerHeader()
 {
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW PLAYER");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");
 }
//=============================
//Create Players Header
//============================
void AddPlayer()
{
   GRAPHIX g;
   memfiles read;
   member player;

   int id;
   char address[50],name[30],dob[11],faculty[25];
   bool id_already_exist;

   do
    {
      AddPlayerHeader(); //displays a header
      _setcursortype(_NORMALCURSOR); //unhides the cursor
      cout<<endl<<endl<<"Enter Player's ID number : ";
      fflush(stdin);
      cin>>id; //accepts users input

      id_already_exist = read.SearchFile(id); //searches the user file for this ID number

      if(id_already_exist) //if it already exists
        MessageBox(NULL,TEXT("That user ID already exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      else if(id < 1) //if it is less than or equal to zero
		  MessageBox(NULL,TEXT("ID number must greater than Zeor(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

    }while(id_already_exist || id < 1);

    cout<<endl<<"Enter Player's Name :";
    gets(name);    //accepts the user input
    cout<<endl<<"Enter Player's Date of Birth i.e. dd/mm/yy :";
    cin>>dob;    //accepts the user input
    cout<<endl<<"Enter Player's Faculty :";
    cin>>faculty;
    cout<<endl<<"Enter Player's Address :";
    gets(address); //accepts the user input


    _setcursortype(_NOCURSOR); //hides the cursor
    player.setMemberID(id);	//sets the user id
    player.setName(name); //sets the user first name and last name
    player.setDOB(dob);
    player.setFaculty(faculty);
    player.setAddress(address);  //sets the user address
        //sets the user phone number

    if(read.WriteToFile(id,player)) //writes the new record to the fileclrscr();
     {
       g.display(25,23,YELLOW,BLACK,"Database updated successfully....");

       if( (MessageBox(NULL,TEXT("Do you want add another Player?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
         AddPlayer(); //calls the procedure to create Player
     }

 }
//===========================
// Edits existing players
//===========================
void EditPlayer()
{
   GRAPHIX g;
   memfiles mread;
   member player;

   int id;
   char address[50],name[20],dob[9],faculty[25];
   bool id_already_exist;

    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
    g.display(30,4,YELLOW,BLACK, "EDITING AN EXISTING PLAYER");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");

   _setcursortype(_NORMALCURSOR); //unhides the cursor
   cout<<endl<<endl<<"Enter Player's ID number :";
   cin>>id; //accepts users input

   if(mread.SearchFile(id)) //if the id number could not be found
   {
   	player= mread.ReadFromFile(id); //reads the user record into the class
      g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
      g.display(25,11,WHITE,BLACK,"HERE IS THE PLAYER INFORMATION");
      g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
      player.show(); //show the information that can be edited

    	cout<<endl<<endl<<"Enter Player's Name :";
    	gets(address);    //accepts the user input
    	cout<<endl<<"Enter Player's Date of Birth i.e. dd/mm/yy :";
    	cin>>dob;    //accepts the user input
    	cout<<endl<<"Enter Player's Faculty :";
    	cin>>faculty;
    	cout<<endl<<"Enter Player's Address :";
    	gets(address); //accepts the user input


    	_setcursortype(_NOCURSOR); //hides the cursor
    	player.setMemberID(id);	//sets the user id
    	player.setName(name); //sets the user first name and last name
    	player.setDOB(dob);
    	player.setFaculty(faculty);
    	player.setAddress(address);  //sets the user address
        //sets the user phone number

    if(mread.WriteToFile(id,player)) //writes the new record to the fileclrscr();
     {
       g.display(25,23,YELLOW,BLACK,"Database updated successfully....");

       if( (MessageBox(NULL,TEXT("Do you want edit another Player?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
         EditPlayer(); //calls the procedure to create Player
     }
     else
     {
      g.display(1,23,WHITE,BLACK, "Problem Updating Player!!");
      getch();
     }
   }
   else
   {
      g.display(1,23,WHITE,BLACK, "That Player Doesn't Exist");
      getch();
   }
 }
 //=====================
 //VIEW Players
 //=====================
void ViewPlayers()
{
   GRAPHIX g;
   memfiles mread;


   g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
   g.display(30,4,YELLOW,BLACK, "VIEW MEMBER DATA");
   g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");
   mread.ReadAllFromFile(); //reads the user record into the class

  getch();

}

//=============================
//Delete member Methom
//============================
void DelPlayer()
{
   GRAPHIX g;
   int id;
   member player,mblank;
   memfiles mread;


   g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
   g.display(30,4,YELLOW,BLACK, "DELETE MEMBER DATA");
   g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO PERMANENTLY DELETE PLAYER INFOMATION                            ");
   g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");

   cout<<endl<<endl<<"Enter Player's ID number : ";
   fflush(stdin);
   cin>>id; //accepts users input

   if(mread.SearchFile(id)) //if the id number could not be found
   {
   	player= mread.ReadFromFile(id); //reads the user record into the class
      g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
   	g.display(25,11,WHITE,BLACK,"HERE IS THE PLAYER INFORMATION");
   	g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");

      player.show(); //show the information that can be edited
      if( (MessageBox(NULL,TEXT("Are sure you want to delete This Player?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      if(mread.WriteToFile(player.getMemberID(),mblank))
            	MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
               	else
                  	MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


         _setcursortype(_NOCURSOR); //hides the cursor
         g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
   }
   else
   	g.display(1,10,WHITE,BLACK, "Member Doesn't Exist!!");
   getch();

}

//=============================
//Create SOCcer Header
//============================
void AddSocTHeader()
{
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                      ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW SOCCER TEAM");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");
   return;
}
//=============================
//Create Soccer teams Header
//============================
void AddNetTHeader()
{
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                      ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW NETBALL TEAM");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");

}
//=============================
//Create TRACK TEAM Header
//============================
void AddTrackTHeader()
{
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                      ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW TRACK TEAM TEAM");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");
}
//=============================
//Create TEAM Methom
//============================
void AddTeam(int teamType)
{
   GRAPHIX g;
	memfiles mread;
   member player;
   socfiles sread,swrite;
   netfiles nread,nwrite;
   trackfiles tread,twrite;
   netTeam newNet;
   trackTeam newTrack;
   soccerTeam newSoc;

   char title[50],coach[30],captain[30];
   int temp,code,size,squad_size,num_wins,num_losses,members[22];
   int num_rplayers,num_red_cards,num_yel_cards,goals_scored,goals_conceed;
   int p_scored, p_conceed, g_medal, s_medal,b_medal,num_app;
   float sb_time;

   bool id_already_exist;

   do
   {
      if(teamType==1)
      {
			AddSocTHeader(); //displays a header
         _setcursortype(_NORMALCURSOR); //unhides the cursor
      	cout<<endl<<endl<<"Enter The Soccer Team's ID Number :  ";
      	cin>>code; //accepts users input

      	id_already_exist = sread.SearchFile(code); //searches the user file for this ID number

      	if(id_already_exist) //if it already exists
        		MessageBox(NULL,TEXT("That Team Already Exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      	else
         	if(code < 1) //if it is less than or equal to zero
		  			MessageBox(NULL,TEXT("ID number must greater than Zero(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

      }
      else
      	if(teamType==2)
         {
				AddNetTHeader(); //displays a header
         	_setcursortype(_NORMALCURSOR); //unhides the cursor
      		cout<<endl<<endl<<"Enter The NetBall Team's ID Number :  ";
      		cin>>code; //accepts users input

      		id_already_exist = nread.SearchFile(code); //searches the user file for this ID number

      		if(id_already_exist) //if it already exists
        			MessageBox(NULL,TEXT("That Team Already Exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      		else
         		if(code < 1) //if it is less than or equal to zero
		  				MessageBox(NULL,TEXT("ID number must greater than Zero(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

         }
      	else
         	if(teamType==3)
            {
					AddTrackTHeader(); //displays a header
               _setcursortype(_NORMALCURSOR); //unhides the cursor
      			cout<<endl<<endl<<"Enter The Track & Field Team's ID Number :  ";
      			cin>>code; //accepts users input

      			id_already_exist = tread.SearchFile(code); //searches the user file for this ID number

      			if(id_already_exist) //if it already exists
        				MessageBox(NULL,TEXT("That Team Already Exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      			else
         			if(code < 1) //if it is less than or equal to zero
		  					MessageBox(NULL,TEXT("ID number must greater than Zero(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

            }

    }while(id_already_exist || code < 1);

    cout<<endl<<"Enter Team's Title : ";
    gets(title);    //accepts the user input
    do
    {
    	cout<<endl<<"Enter The Team's Size :  ";
    	cin>>size;    //accepts the user input
      if(size>22)
      	MessageBox(NULL,TEXT("The Maximum Team Size is 22"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
    }while(size>22);
    do
    {
    	cout<<endl<<"Enter The Team's Squad Size :  ";
    	cin>>squad_size;
      if(size>22)
      	MessageBox(NULL,TEXT("The Squad Size Can't Be Greater Than The Team Size"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

    }while(squad_size>size);
    cout<<endl<<"Enter Team's Coach :  ";
    gets(coach); //accepts the user input
    cout<<endl<<"Enter Team's Captain :  ";
    gets(captain); //accepts the user input
    cout<<endl<<"Enter Number of Wins :  ";
    cin>>num_wins;
    cout<<endl<<"Enter Number of Losses :  ";
    cin>>num_losses;

    for(int i=0; i<size-1;i++)
    {
    	cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
      do
      {
      	cout<<endl<<"Enter ID of Team Player Number  "<<(i+1)<<" :  ";
      	cin>>temp;
      	if(!mread.SearchFile(temp)) //if it doesn't exists
        		if( (MessageBox(NULL,TEXT("That Player Doesn't Exist!\nDo You Want To Create Player now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
         	{
            	AddPlayer(); //calls the procedure to add a player to database
                if(teamType==1)
							AddSocTHeader(); //displays a header
                else
                	if(teamType==2)
							AddNetTHeader(); //displays a header
                  else
                  	if(teamType==3)
							AddTrackTHeader(); //displays a header
               cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
            }
      }while(mread.SearchFile(temp)== false);

      members[i]=temp;
    }

    if(teamType==1)     //if the chosen for creation was soccer ask for thw added info
    {
    	cout<<endl<<"Enter Number of Red Cards Given To This Team :  ";
    	cin>>num_red_cards;
      cout<<endl<<"Enter Number of Yellow Cards Given To This Team :  ";
    	cin>>num_yel_cards;
      cout<<endl<<"Enter Number of Reserve Player :  ";
    	cin>>num_rplayers;
      cout<<endl<<"Enter Number of Goals Scored :  ";
    	cin>>goals_scored;
      cout<<endl<<"Enter Number of Goals Conceeded :  ";
    	cin>>goals_conceed;
      soccerTeam newSoc(code,size,size,num_wins, num_losses, title,coach,captain,teamType,members,num_rplayers,num_red_cards,num_yel_cards,goals_scored,goals_conceed);
      if(swrite.WriteToFile(newSoc.getTeamCode(),newSoc)) //writes the new sOCCERteam to file to the file
     	{
       	g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
       	if( (MessageBox(NULL,TEXT("Do you want add Soccer Team?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   AddTeam(1); //calls the procedure to create Player
     	}
      else
      	g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");

    }
    else
    	if(teamType==2)
      {
      	cout<<endl<<"Enter Number of Points Scored :  ";
    		cin>>p_scored;
      	cout<<endl<<"Enter Number of Point Scored Against :  ";
    		cin>>p_conceed;
         netTeam newNet(code,size,size,num_wins, num_losses, title,coach,captain,teamType,members,p_scored,p_conceed);
      	if(nwrite.WriteToFile(newNet.getTeamCode(),newNet)) //writes the new sOCCERteam to file to the file
     		{
       		g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
       		if( (MessageBox(NULL,TEXT("Do you want add NetBall Team?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   	AddTeam(2); //calls the procedure to create Player
     		}
      	else
      		g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
      }
      else
      	if(teamType==3)
         {
         	cout<<endl<<"Enter the Number of Gold Medals :  ";
    			cin>>g_medal;
      		cout<<endl<<"Enter the Number of Silver Medals :  ";
    			cin>>s_medal;
            cout<<endl<<"Enter the Number of Bronze Medals :  ";
    			cin>>b_medal;
            cout<<endl<<"Enter the Number Appearances :  ";
    			cin>>num_app;
            cout<<endl<<"Enter the Seasons Best Time :  ";
    			cin>>sb_time;
         	trackTeam newTrack(code,size,size,num_wins, num_losses, title,coach,captain,teamType,members,g_medal, s_medal,b_medal,num_app,sb_time);
      		if(twrite.WriteToFile(newTrack.getTeamCode(),newTrack)) //writes the new sOCCERteam to file to the file
     			{
       			g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
       			if( (MessageBox(NULL,TEXT("Do you want add Track Team?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   		AddTeam(3); //calls the procedure to create Player
     			}
      		else
      			g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
         }

 }
//=============================
//Edit Team
//============================
void EditTeam(int teamType)
{
    GRAPHIX g;


	memfiles mread;
   member player;
   socfiles sread,swrite;
   netfiles nread,nwrite;
   trackfiles tread,twrite;
   netTeam newNet;
   trackTeam newTrack;
   soccerTeam newSoc;

   char title[50],coach[30],captain[30];
   int temp,code,size,squad_size,num_wins,num_losses,members[22];
   int num_rplayers,num_red_cards,num_yel_cards,goals_scored,goals_conceed;
   int p_scored, p_conceed, g_medal, s_medal,b_medal,num_app;
   float sb_time;

    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
    g.display(30,4,YELLOW,BLACK, "EDIT TEAM DATA");
    g.display(1,5,WHITE,BLACK,"________________________________________________________________________________");

    if(teamType==1)
    {
    	cout<<endl<<endl<<"Enter The ID Number of Soccer Team Yo Want to Edit  :  ";
      cin>>code; //accepts users input
      if(sread.SearchFile(code)) //searches the user file for this ID number
      {
      	newSoc=sread.ReadFromFile(code);
         g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
      	g.display(25,11,WHITE,BLACK,"HERE IS THE SOCCER TEAM'S INFORMATION");
      	g.display(1,11+16,WHITE,BLACK, "________________________________________________________________________________");
         newSoc.show();

         cout<<endl<<endl<<"Enter Team's Title : ";
    		gets(title);    //accepts the user input
    		do
    		{
    			cout<<endl<<"Enter The Team's Size :  ";
    			cin>>size;    //accepts the user input
      		if(size>22)
      		MessageBox(NULL,TEXT("The Maximum Team Size is 22"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
   		 }while(size>22);
    		do
    		{
    			cout<<endl<<"Enter The Team's Squad Size :  ";
    			cin>>squad_size;
      		if(size>22)
      			MessageBox(NULL,TEXT("The Squad Size Can't Be Greater Than The Team Size"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

    		}while(squad_size>size);
    		cout<<endl<<"Enter Team's Coach :  ";
    		gets(coach); //accepts the user input
    		cout<<endl<<"Enter Team's Captain :  ";
    		gets(captain); //accepts the user input
    		cout<<endl<<"Enter Number of Wins :  ";
    		cin>>num_wins;
    		cout<<endl<<"Enter Number of Losses :  ";
    		cin>>num_losses;

    		for(int i=0; i<size-1;i++)
    		{
    			cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
      		do
      		{
      			cout<<endl<<"Enter ID of Team Player Number  "<<(i+1)<<" :  ";
      			cin>>temp;
      			if(!mread.SearchFile(temp)) //if it doesn't exists
        				if( (MessageBox(NULL,TEXT("That Player Doesn't Exist!\nDo You Want To Create Player now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            			AddPlayer(); //calls the procedure to add a player to database
      		}while(mread.SearchFile(temp)== false);
				members[i]=temp;
         }
      	cout<<endl<<"Enter Number of Red Cards Given To This Team :  ";
    		cin>>num_red_cards;
      	cout<<endl<<"Enter Number of Yellow Cards Given To This Team :  ";
    		cin>>num_yel_cards;
      	cout<<endl<<"Enter Number of Reserve Player :  ";
    		cin>>num_rplayers;
      	cout<<endl<<"Enter Number of Goals Scored :  ";
    		cin>>goals_scored;
      	cout<<endl<<"Enter Number of Goals Conceeded :  ";
    		cin>>goals_conceed;

         newSoc.setTeamCode(code);
   		newSoc.setTeamSize(size);
   		newSoc.setSquadSize(squad_size);
   		newSoc.setNumWins(num_wins);
   		newSoc.setNumLosses(num_losses);

   		newSoc.setTitle(title);
   		newSoc.setCoach(coach);
   		newSoc.setCaptain(captain);
   		newSoc.setMembers(members);
         newSoc.setRPlayers(num_rplayers);
         newSoc.setRedCards(num_red_cards);
         newSoc.setYelCards(num_yel_cards);
         newSoc.setGoalScored(goals_scored);
         newSoc.setGoalCon(goals_conceed);
         if(swrite.WriteToFile(newSoc.getTeamCode(),newSoc)) //writes the new sOCCERteam to file to the file
				g.display(25,23,YELLOW,BLACK,"Soccer Database updated successfully....");
       			if( (MessageBox(NULL,TEXT("Do you want Edit another soccer Team?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   		EditTeam(1); //calls the procedure to create Player

		}
    	else
    		g.display(25,23,YELLOW,BLACK,"That Soccer Team  Doesn't Exist");
      getch();
 	}
 	else
 		if(teamType==2)
    	{
    		cout<<endl<<endl<<"Enter The ID Number of Netball Team Yo Want to Edit  :  ";
      	cin>>code; //accepts users input
      	if(sread.SearchFile(code)) //searches the user file for this ID number
      	{
      		newNet=nread.ReadFromFile(code);
	         g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
	      	g.display(25,11,WHITE,BLACK,"HERE IS THE NETBALL TEAM'S INFORMATION");
   	   	g.display(1,11+13,WHITE,BLACK, "________________________________________________________________________________");
      	   newNet.show();

            cout<<endl<<endl<<"Enter Team's Title : ";
            gets(title);    //accepts the user input
    			do
    			{
    				cout<<endl<<"Enter The Team's Size :  ";
    				cin>>size;    //accepts the user input
      			if(size>22)
      			MessageBox(NULL,TEXT("The Maximum Team Size is 22"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
   		 	}while(size>22);
    			do
    			{
    				cout<<endl<<"Enter The Team's Squad Size :  ";
    				cin>>squad_size;
      			if(size>22)
      				MessageBox(NULL,TEXT("The Squad Size Can't Be Greater Than The Team Size"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

    			}while(squad_size>size);
    			cout<<endl<<"Enter Team's Coach :  ";
    			gets(coach); //accepts the user input
    			cout<<endl<<"Enter Team's Captain :  ";
    			gets(captain); //accepts the user input
    			cout<<endl<<"Enter Number of Wins :  ";
    			cin>>num_wins;
    			cout<<endl<<"Enter Number of Losses :  ";
    			cin>>num_losses;

    			for(int i=0; i<size-1;i++)
    			{
    				cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
      			do
      			{
      				cout<<endl<<"Enter ID of Team Player Number  "<<(i+1)<<" :  ";
      				cin>>temp;
      				if(!mread.SearchFile(temp)) //if it doesn't exists
        					if( (MessageBox(NULL,TEXT("That Player Doesn't Exist!\nDo You Want To Create Player now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            				AddPlayer(); //calls the procedure to add a player to database
                  g.SetScreen();
               	cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
      			}while(mread.SearchFile(temp)== false);
					members[i]=temp;
         	}
				cout<<endl<<"Enter Number of Points Scored :  ";
    			cin>>p_scored;
      		cout<<endl<<"Enter Number of Point Scored Against :  ";
    			cin>>p_conceed;

         	newNet.setTeamCode(code);
   			newNet.setTeamSize(size);
   			newNet.setSquadSize(squad_size);
   			newNet.setNumWins(num_wins);
   			newNet.setNumLosses(num_losses);

   			newNet.setTitle(title);
   			newNet.setCoach(coach);
   			newNet.setCaptain(captain);
   			newNet.setMembers(members);
         	newNet.setPScored(p_scored);
   			newNet.setPConceed(p_conceed);
         	if(nwrite.WriteToFile(newNet.getTeamCode(),newNet)) //writes the new Netballteam to file to the file
         	{
         		g.display(25,23,YELLOW,BLACK,"Netball Database updated successfully....");
            	if( (MessageBox(NULL,TEXT("Do you want Edit another Netball Team?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            		EditTeam(2); //calls the procedure to create Player
         	}
         	else
         		g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
    	}
      else
      	g.display(25,23,YELLOW,BLACK,"Netball That Team Doesn't Exist");
      getch();
    }
    else
    if(teamType==3)
    {
    	cout<<endl<<endl<<"Enter The ID Number of Track Team Yo Want to Edit  :  ";
      cin>>code; //accepts users input
      if(tread.SearchFile(code)) //searches the user file for this ID number
      {
      	newTrack=tread.ReadFromFile(code);
         g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
      	g.display(25,11,WHITE,BLACK,"HERE IS THE TRACK & FIELD TEAM'S INFORMATION");
      	g.display(1,11+18,WHITE,BLACK, "________________________________________________________________________________");
         newTrack.show();

         cout<<endl<<endl<<"Enter Team's Title : ";
    		gets(title);    //accepts the user input
    		do
    		{
    			cout<<endl<<"Enter The Team's Size :  ";
    			cin>>size;    //accepts the user input
      		if(size>22)
      		MessageBox(NULL,TEXT("The Maximum Team Size is 22"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
   		 }while(size>22);
    		do
    		{
    			cout<<endl<<"Enter The Team's Squad Size :  ";
    			cin>>squad_size;
      		if(size>22)
      			MessageBox(NULL,TEXT("The Squad Size Can't Be Greater Than The Team Size"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

    		}while(squad_size>size);
    		cout<<endl<<"Enter Team's Coach :  ";
    		gets(coach); //accepts the user input
    		cout<<endl<<"Enter Team's Captain :  ";
    		gets(captain); //accepts the user input
    		cout<<endl<<"Enter Number of Wins :  ";
    		cin>>num_wins;
    		cout<<endl<<"Enter Number of Losses :  ";
    		cin>>num_losses;

    		for(int i=0; i<size-1;i++)
    		{
    			cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
      		do
      		{
      			cout<<endl<<"Enter ID of Team Player Number  "<<(i+1)<<" :  ";
      			cin>>temp;
      			if(!mread.SearchFile(temp)) //if it doesn't exists
        				if( (MessageBox(NULL,TEXT("That Player Doesn't Exist!\nDo You Want To Create Player now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            			AddPlayer(); //calls the procedure to add a player to database
               cout<<endl<<"Enter The ID Numbers of the "<<size<<" Players  :";
      		}while(mread.SearchFile(temp)== false);
				members[i]=temp;
         }
         cout<<endl<<"Enter the Number of Gold Medals :  ";
         cin>>g_medal;
         cout<<endl<<"Enter the Number of Silver Medals :  ";
         cin>>s_medal;
         cout<<endl<<"Enter the Number of Bronze Medals :  ";
         cin>>b_medal;
         cout<<endl<<"Enter the Number Appearances :  ";
         cin>>num_app;
         cout<<endl<<"Enter the Seasons Best Time :  ";
         cin>>sb_time;

         newTrack.setTeamCode(code);
   		newTrack.setTeamSize(size);
   		newTrack.setSquadSize(squad_size);
   		newTrack.setNumWins(num_wins);
   		newTrack.setNumLosses(num_losses);

   		newTrack.setTitle(title);
   		newTrack.setCoach(coach);
   		newTrack.setCaptain(captain);
   		newTrack.setMembers(members);
         newTrack.setGMedals(g_medal);
   		newTrack.setSMedals(s_medal);
   		newTrack.setBMedals(b_medal);
   		newTrack.setApperances(num_app);
   		newTrack.setSTime(sb_time);
         if(twrite.WriteToFile(newTrack.getTeamCode(),newTrack)) //writes the new Trackteam to file to the file
         {
       			g.display(25,23,YELLOW,BLACK,"Track Database updated successfully....");
       			if( (MessageBox(NULL,TEXT("Do you want Edit another Track Team?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   		EditTeam(3); //calls the procedure to create Player
         }
         else
         	g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
    	}
      else
      	g.display(25,23,YELLOW,BLACK,"That Track Team Doesn't Exist");
      getch();
    }

 }
//=============================
//View TEAM Methom
//============================
void ViewTeam(int teamType)
{
   GRAPHIX g;
   int id;
   socfiles sread,swrite;
   netfiles nread,nwrite;
   trackfiles tread,twrite;
   netTeam newNet;
   trackTeam newTrack;
   soccerTeam newSoc;

   g.SetScreen();
   g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
   g.display(30,4,YELLOW,BLACK, "VIEW TEAM DATA");
   g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO VIEW EXISTING TEAMS INFOMATION                                ");
   g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");

      if(teamType==1)
      {
      	if( (MessageBox(NULL,TEXT("Do Want View Infomation\n All Soccer Teams?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      	{
            g.display(1,25,BLACK,BLACK, "                                                                               ");
            g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
            g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            cout<<endl;
          	sread.ReadAllFromFile();
         }
         else
         {
         	_setcursortype(_NORMALCURSOR); //unhides the cursor
         	cout<<endl<<endl<<"Enter The Soccer Team's ID Number :  ";
         	cin>>id; //accepts users input

         	if(sread.SearchFile(id)) //if the team doesn't exists
         	{
               g.display(1,25,BLACK,BLACK, "                                                                               ");
            	g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
					g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            	cout<<endl;
         		newSoc=sread.ReadFromFile(id);
            	newSoc.show();
         	}
         	else
         		if( (MessageBox(NULL,TEXT("That Team Doesn't Exist!\nDo You Want To Create Team Now now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      	      		AddTeam(1);
         }
      }
      else
      	if(teamType==2)
         {
				if( (MessageBox(NULL,TEXT("Do Want View Infomation\n All Soccer Teams?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      		{
               g.display(1,25,BLACK,BLACK, "                                                                               ");
            	g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
            	g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            	cout<<endl;
          		nread.ReadAllFromFile();
         	}
            else
            {
         		_setcursortype(_NORMALCURSOR); //unhides the cursor
      			cout<<endl<<endl<<"Enter The NetBall Team's ID Number :  ";
      			cin>>id; //accepts users input

      			if(nread.SearchFile(id)) //if the team doesn't exists
            	{
                  g.display(1,25,BLACK,BLACK, "                                                                               ");
            		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            		g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
						g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            		cout<<endl;
             		newNet=nread.ReadFromFile(id);
               	newNet.show();
            	}
            	else
            		if( (MessageBox(NULL,TEXT("That Team Doesn't Exist!\nDo You Want To Create Team Now now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
                  	AddTeam(2);
            }
         }
      	else
         	if(teamType==3)
            {
					if( (MessageBox(NULL,TEXT("Do Want View Infomation\n All Soccer Teams?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      			{
                  g.display(1,25,BLACK,BLACK, "                                                                               ");
            		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            		g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
            		g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            		cout<<endl;
          			tread.ReadAllFromFile();
         		}
               else
               {
               	_setcursortype(_NORMALCURSOR); //unhides the cursor
      				cout<<endl<<endl<<"Enter The Track & Field Team's ID Number :  ";
      				cin>>id; //accepts users input

      				if(tread.SearchFile(id)) //if the team doesn't exists
         			{
                     g.display(1,25,BLACK,BLACK, "                                                                               ");
                  	g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            			g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
							g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            			cout<<endl;
         				newTrack=tread.ReadFromFile(id);
            			newTrack.show();
         			}
         			else
         				if( (MessageBox(NULL,TEXT("That Team Doesn't Exist!\nDo You Want To Create Team Now now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            				AddTeam(3);
            	}
      		}

}

//=============================
//Delete TEAM Methom
//============================
void DelTeam(int teamType)
{
   GRAPHIX g;
   int id;
   soccerTeam newSoc,sblank;
   netTeam newNet,nblank;
   trackTeam newTrack,tblank;

   socfiles sread;
   netfiles nread;
   trackfiles tread;

   g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
   g.display(30,4,YELLOW,BLACK, "DELETE TEAM DATA");
   g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO PERMANENTLY DELETE TEAM INFOMATION                            ");
   g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");

      if(teamType==1)
      {
         _setcursortype(_NORMALCURSOR); //unhides the cursor
         cout<<endl<<endl<<"Enter The Soccer Team's ID Number :  ";
         fflush(stdin);
         cin>>id; //accepts users input
         cout<<endl<<endl<<endl;

    		if(!sread.SearchFile(id)) //if the id number could not be found
    		{
         	MessageBox(NULL,TEXT("That ID number could not be found..."),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
         	g.SetScreen(); //clears the screen and sets the background color to black
         	return;
    		}
 	 		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
	 		g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
    		cout<<endl;
         newSoc=sread.ReadFromFile(id); //reads the user record into the class
    		newSoc.show(); //show the information that can be edited
    		if( (MessageBox(NULL,TEXT("Are sure you want to delete This Team?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      		if(sread.WriteToFile(newSoc.getTeamCode(),sblank))
	      		MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
       		else
         		MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


    		_setcursortype(_NOCURSOR); //hides the cursor
    		g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
    		getch();

    		g.SetScreen();

      }
      else
      	if(teamType==2)
         {
         	_setcursortype(_NORMALCURSOR); //unhides the cursor
         	cout<<endl<<endl<<"Enter The Netball Team's ID Number :  ";
         	cin>>id; //accepts users input
         	cout<<endl<<endl<<endl;

    			if(!nread.SearchFile(id)) //if the id number could not be found
    			{
         		MessageBox(NULL,TEXT("That ID number could not be found..."),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
         		g.SetScreen(); //clears the screen and sets the background color to black
         		return;
    			}
 	 			g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
	 			g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
    			cout<<endl;
         	newNet=nread.ReadFromFile(id); //reads the user record into the class
    			newNet.show(); //show the information that can be edited
    			if( (MessageBox(NULL,TEXT("Are sure you want to delete This Team?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      			if(nread.WriteToFile(newNet.getTeamCode(),nblank))
	      			MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
       			else
         			MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


    			_setcursortype(_NOCURSOR); //hides the cursor
    			g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
    			getch();

    			g.SetScreen();
         }
      	else
         	if(teamType==3)
            {
               _setcursortype(_NORMALCURSOR); //unhides the cursor
      			cout<<endl<<endl<<"Enter The Track & Field Team's ID Number :  ";
      			cin>>id; //accepts users input

         		cout<<endl<<endl<<endl;

    				if(!tread.SearchFile(id)) //if the id number could not be found
    				{
         			MessageBox(NULL,TEXT("That ID number could not be found..."),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
         			g.SetScreen(); //clears the screen and sets the background color to black
         			return;
    				}
 	 				g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         		g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
	 				g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
    				cout<<endl;
         		newTrack=tread.ReadFromFile(id); //reads the user record into the class
    				newTrack.show(); //show the information that can be edited
    				if( (MessageBox(NULL,TEXT("Are sure you want to delete This Team?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      				if(tread.WriteToFile(newTrack.getTeamCode(),tblank))
	      				MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
       				else
         				MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


    				_setcursortype(_NOCURSOR); //hides the cursor
    				g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
    				getch();

    				g.SetScreen();
            }

}
//=============================
//Create SOCcer Header
//============================
void AddSocMHeader()
{
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                      ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW SOCCER Match to Database ");
    g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO ADD A NEW SOCCER MATCH TO SPORTS SYSTEM                       ");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");
   return;
}
//=============================
//Create Soccer Matchs Header
//============================
void AddNetMHeader()
{
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                      ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW NETBALL MATCH \6\6");
    g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO ADD A NEW NETBALL MATCH TO SPORTS SYSTEM                      ");
    g.display(1,5,WHITE,BLACK, "________________________________________________________________________________");
   return;
}
//=============================
//Create TRACK Match Header
//============================
void AddTrackMHeader()
{
    GRAPHIX g;
    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                      ");
    g.display(30,4,YELLOW,BLACK, "ADDING A NEW TRACK  MATCH \30\30");
    g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO ADD A NEW SOCCER MATCH TO SPORTS SYSTEM                       ");
    g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");
   return;
}
//=============================
//Create Match Methom
//============================
void AddMatch(int MatchType)
{
   GRAPHIX g;
	memfiles mread;
   member player;
   socmatfiles sread,swrite;
   netmatfiles nread,nwrite;
   trackmatfiles tread,twrite;
   netmatch newNet;
   trackmatch newTrack;
   socmatch newSoc;

   char  officials[100], location[40],time[10],date[11],team1[25],team2[25],winner[25],loser[25],mvp[30];
   int id,corners,throws,penalties,fpasses,fstarts;
   string race_title;
   float ftime;
   bool draw,id_already_exist;

   ofstream matches("Print_Match_Info.txt", ios::out);

   do
   {
      if(MatchType==1)
      {
			AddSocMHeader(); //displays a header
         _setcursortype(_NORMALCURSOR); //unhides the cursor
      	cout<<endl<<endl<<"Enter The Soccer Match's ID Number :  ";
      	cin>>id; //accepts users input

      	id_already_exist = sread.SearchFile(id); //searches the user file for this ID number

      	if(id_already_exist) //if it already exists
        		MessageBox(NULL,TEXT("That Match Already Exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      	else
         	if(id < 1) //if it is less than or equal to zero
		  			MessageBox(NULL,TEXT("ID number must greater than Zero(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

      }
      else
      	if(MatchType==2)
         {
				AddNetMHeader(); //displays a header
         	_setcursortype(_NORMALCURSOR); //unhides the cursor
      		cout<<endl<<endl<<"Enter The NetBall Match's ID Number :  ";
      		cin>>id; //accepts users input

      		id_already_exist = nread.SearchFile(id); //searches the user file for this ID number

      		if(id_already_exist) //if it already exists
        			MessageBox(NULL,TEXT("That Match Already Exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      		else
         		if(id < 1) //if it is less than or equal to zero
		  				MessageBox(NULL,TEXT("ID number must greater than Zero(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

         }
      	else
         	if(MatchType==3)
            {
					AddTrackTHeader(); //displays a header
               _setcursortype(_NORMALCURSOR); //unhides the cursor
      			cout<<endl<<endl<<"Enter The Track & Field Match's ID Number :  ";
      			cin>>id; //accepts users input

      			id_already_exist = tread.SearchFile(id); //searches the user file for this ID number

      			if(id_already_exist) //if it already exists
        				MessageBox(NULL,TEXT("That Match Already Exist"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message

      			else
         			if(id < 1) //if it is less than or equal to zero
		  					MessageBox(NULL,TEXT("ID number must greater than Zero(0)"),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message    }while(id_already_exist || id < 1);

            }

    }while(id_already_exist || id < 1);

    cout<<endl<<"Enter Match Officials i.e P.Prendagas, T.Withmoore :  ";
    gets(officials);    //accepts the user input
    cout<<endl<<"Enter Match Location i.e National Stadium :  ";
    gets(location);
    cout<<endl<<"Enter The Match Time i.e 3pm :  ";
    gets(time);
    cout<<endl<<"Enter The Match Date i.e dd/mm/yy :  ";
    gets(date);
    cout<<endl<<"Enter The Name of First Team:  ";
    gets(team1);
    cout<<endl<<"Enter The Name of Second Team:  ";
    gets(team2);
    if( (MessageBox(NULL,TEXT("Did Match End in a Draw?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    	draw=true;
    else
    {
    	if( (MessageBox(NULL,TEXT("Did First Team Win This Contest?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    	{
         strcpy(winner,team1);
         strcpy(loser,team2);
    	}
    	else
    	{
      	strcpy(winner,team2);
         strcpy(loser,team1);
    	}
    }
    cout<<endl<<"Enter The Name of the Match MVP:  ";
    gets(mvp);

    if(MatchType==1)     //if the chosen for creation was soccer ask for thw added info
    {
    	cout<<endl<<"Enter Number of Penalties Given This Match :  ";
    	cin>>penalties;
      cout<<endl<<"Enter Number of Corners Won This Match :  ";
    	cin>>corners;
      cout<<endl<<"Enter Number of Throws Given This Match :  ";
    	cin>>throws;
      socmatch newSocMat(id,officials,location,time,date,team1,team2,winner,loser,mvp,draw,penalties,corners,throws);
      if(swrite.WriteToFile(newSocMat.getid(),newSocMat)) //writes the new socmatch to file to the file
     	{
       	g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
       	if( (MessageBox(NULL,TEXT("Do you want add Soccer Match?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   AddMatch(1); //calls the procedure to create Player
     	}
      else
      	g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
      if(matches)
      {
      	matches<<"Match ID          : S"<<newSocMat.getid()<<endl;
         matches<<"Match Competitors :  "<<newSocMat.getTeam1().data()<<"  vs  "<<newSocMat.getTeam2().data()<<endl;
         matches<<"Match Location    :  "<<newSocMat.getLocation().data()<<endl;
         matches<<"Match Date        :  "<<newSocMat.getTime().data()<<"     "<<newSocMat.getDate().data()<<endl;
         matches<<"Match Officials   :  "<<newSocMat.getOfficials().data()<<endl;
         matches<<"Match Statistics     "<<endl;
         matches<<"Match MVP         :  "<<newSocMat.getMVP().data()<<endl;
         matches<<"Penalties         :  "<<newSocMat.getPKicks()<<endl;
         matches<<"Throws            :  "<<newSocMat.getThrows()<<endl;
         matches<<"Corners           :  "<<newSocMat.getCorners()<<endl;
         matches<<"Match Winner      :  "<<newSocMat.getWinner().data()<<endl<<endl<<endl<<endl;
      }

    }
    else
    	if(MatchType==2)
      {
    		cout<<endl<<"Enter Number of Penalties Given This Match :  ";
    		cin>>penalties;
      	cout<<endl<<"Enter Number of Free Passes Won This Match :  ";
    		cin>>fpasses;
         netmatch newNetMat(id,officials,location,time,date,team1,team2,winner,loser,mvp,draw,penalties,fpasses);
      	if(nwrite.WriteToFile(newNetMat.getid(),newNetMat)) //writes the new socmatch to file to the file
     		{
       		g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
       		if( (MessageBox(NULL,TEXT("Do you want add NetBall Match?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   	AddMatch(2); //calls the procedure to create Player
     		}
      	else
      		g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");

        if(matches)
        {
        		matches<<"Match ID          : N"<<newNetMat.getid()<<endl;
            matches<<"Match Competitors :  "<<newNetMat.getTeam1().data()<<"  vs  "<<newNetMat.getTeam2().data()<<endl;
            matches<<"Match Location    :  "<<newNetMat.getLocation().data()<<endl;
            matches<<"Match Date        :  "<<newNetMat.getTime().data()<<"     "<<newTrack.getDate().data()<<endl;
            matches<<"Match Officials   :  "<<newNetMat.getOfficials().data()<<endl;
            matches<<"Match Statistics     "<<endl;
            matches<<"Match MVP         :  "<<newNetMat.getMVP().data()<<endl;
            matches<<"Penalties         :  "<<newNetMat.getPenalties()<<endl;
            matches<<"Free Passes       :  "<<newNetMat.getFPasses()<<endl;
            matches<<"Match Winner      :  "<<newNetMat.getWinner().data()<<endl<<endl<<endl<<endl;
        }
      }
      else
      	if(MatchType==3)
         {
         	cout<<endl<<"Enter the Race Title i.e 100Meter Sprint :  ";
    			cin>>race_title;
      		cout<<endl<<"Enter the Number False Starts :  ";
    			cin>>fstarts;
            cout<<endl<<"Enter the Race fastest Time :  ";
    			cin>>ftime;
         	trackmatch newTrackMat(id,officials,location,time,date,team1,team2,winner,loser,mvp,draw,race_title,fstarts,ftime);
      		if(twrite.WriteToFile(newTrackMat.getid(),newTrackMat)) //writes the new socmatch to file to the file
     			{
       			g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
       			if( (MessageBox(NULL,TEXT("Do you want add Track Match?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   		AddMatch(3); //calls the procedure to create Player
     			}
      		else
      			g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");


            if(matches)
    			{
    				matches<<"Match ID          : T"<<newTrackMat.getid()<<endl;
               matches<<"Match Competitors :  "<<newTrackMat.getTeam1().data()<<"  vs  "<<newTrackMat.getTeam2().data()<<endl;
               matches<<"Race Title        :  "<<newTrackMat.getTitle().data()<<endl;
               matches<<"Match Location    :  "<<newTrackMat.getLocation().data()<<endl;
               matches<<"Match Date        :  "<<newTrackMat.getTime().data()<<"     "<<newTrackMat.getDate().data()<<endl;
               matches<<"Match Officials   :  "<<newTrackMat.getOfficials().data()<<endl;
               matches<<"Match Statistics     "<<endl;
               matches<<"Match MVP         :  "<<newTrackMat.getMVP().data()<<endl;
               matches<<"False Starts      :  "<<newTrackMat.getFStarts()<<endl;
               matches<<"Fastest Time      :  "<<newTrackMat.getFTime()<<endl;
               matches<<"Match Winner      :  "<<newTrackMat.getWinner().data()<<endl<<endl<<endl<<endl;

    			}
         }
 }
//=============================
//Edit Match
//============================
void EditMatch(int MatchType)
{
	GRAPHIX g;

	memfiles mread;
   member player;
   socmatfiles sread,swrite;
   netmatfiles nread,nwrite;
   trackmatfiles tread,twrite;
   netmatch newNet;
   trackmatch newTrack;
   socmatch newSoc;

	char  officials[100],location[40],time[10],date[11],team1[25],team2[25],winner[25],loser[25],mvp[30];
   int id,penalties,corners,throws,fpasses,fstarts;
   string race_title;
   float ftime;
   bool draw;

    g.SetScreen();
    g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
    g.display(30,4,YELLOW,BLACK, "EDIT MATCH DATA");
    g.display(1,5,WHITE,BLACK,"________________________________________________________________________________");

    if(MatchType==1)
    {
    	cout<<endl<<endl<<"Enter The ID Number of Soccer Match Yo Want to Edit  :  ";
      cin>>id; //accepts users input
      if(sread.SearchFile(id)) //searches the user file for this ID number
      {
      	g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
         g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
         cout<<endl;
         newSoc = sread.ReadFromFile(id);
         newSoc.show();//display infomation so it can edited
			cout<<endl<<"Enter Match Officials i.e P.Prendagas, T.Withmoore :  ";
    		gets(officials);    //accepts the user input
    		cout<<endl<<"Enter Match Location i.e National Stadium :  ";
    		gets(location);
    		cout<<endl<<"Enter The Match Time i.e 3pm :  ";
    		gets(time);
    		cout<<endl<<"Enter The Match Date i.e dd/mm/yy :  ";
    		gets(date);
    		cout<<endl<<"Enter The Name of First Team:  ";
    		gets(team1);
    		cout<<endl<<"Enter The Name of Second Team:  ";
    		gets(team2);
    		if( (MessageBox(NULL,TEXT("Did Match End in a Draw?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    			draw=true;
    		else
    		{
    			if( (MessageBox(NULL,TEXT("Did First Team Win This Contest?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    			{
         		strcpy(winner,team1);
         		strcpy(loser,team2);
    			}
    			else
    			{
            	strcpy(winner,team2);
         		strcpy(loser,team1);
    			}
       }
       cout<<endl<<"Enter The Name of the Match MVP:  ";
       gets(mvp);
       cout<<endl<<"Enter Number of Penalties Given This Match :  ";
       cin>>penalties;
       cout<<endl<<"Enter Number of Corners Won This Match :  ";
       cin>>corners;
       cout<<endl<<"Enter Number of Throws Given This Match :  ";
       cin>>throws;

       newSoc.setOfficials(officials);
       newSoc.setLocation(location);
       newSoc.setTime(time);
       newSoc.setDate(date);
       newSoc.setTeam1(team1);
       newSoc.setTeam2(team2);
       newSoc.setWinner(winner);
       newSoc.setLoser(loser);
       newSoc.setMVP(mvp);
       newSoc.setDStatus(draw);
       newSoc.setPKicks(penalties);
       newSoc.setThrows(throws);
       newSoc.setCorners(corners);
         if(swrite.WriteToFile(newSoc.getid(),newSoc)) //writes the new socmatch to file to the file
				g.display(25,23,YELLOW,BLACK,"Soccer Database updated successfully....");
       			if( (MessageBox(NULL,TEXT("Do you want Edit another Soccer Match?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
			   		EditMatch(1); //calls the procedure to create Player

		}
    	else
    		g.display(25,23,YELLOW,BLACK,"Soccer Match Doesn't Exist");
 	}
 	else
 		if(MatchType==2)
    	{
    		cout<<endl<<endl<<"Enter The ID Number of NetBall Match Yo Want to Edit  :  ";
      	cin>>id; //accepts users input
      	if(sread.SearchFile(id)) //searches the user file for this ID number
      	{
            //g.display(25,1,WHITE,BLACK, "                                                                               ");
      		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
         	g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
         	cout<<endl;
         	newNet = nread.ReadFromFile(id);
         	newNet.show();//display infomation so it can edited
				cout<<endl<<"Enter Match Officials i.e P.Prendagas, T.Withmoore :  ";
    			gets(officials);    //accepts the user input
    			cout<<endl<<"Enter Match Location i.e National Stadium :  ";
    			gets(location);
    			cout<<endl<<"Enter The Match Time i.e 3pm :  ";
    			gets(time);
    			cout<<endl<<"Enter The Match Date i.e dd/mm/yy :  ";
    			gets(date);
    			cout<<endl<<"Enter The Name of First Team:  ";
    			gets(team1);
    			cout<<endl<<"Enter The Name of Second Team:  ";
    			gets(team2);
    			if( (MessageBox(NULL,TEXT("Did Match End in a Draw?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    				draw=true;
    			else
    			{
    				if( (MessageBox(NULL,TEXT("Did First Team Win This Contest?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    				{
         			strcpy(winner,team1);
         			strcpy(loser,team2);
    				}
    				else
    				{
         			strcpy(winner,team2);
         			strcpy(loser,team1);
    				}
       		}
       		cout<<endl<<"Enter The Name of the Match MVP:  ";
       		gets(mvp);
    			cout<<endl<<"Enter Number of Penalties Given This Match :  ";
    			cin>>penalties;
      		cout<<endl<<"Enter Number of Free Passes Won This Match :  ";
    			cin>>fpasses;

       		newNet.setOfficials(officials);
       		newNet.setLocation(location);
       		newNet.setTime(time);
            newNet.setDate(date);
       		newNet.setTeam1(team1);
       		newNet.setTeam2(team2);
       		newNet.setWinner(winner);
       		newNet.setLoser(loser);
       		newNet.setMVP(mvp);
       		newNet.setDStatus(draw);
       		newNet.setPenalties(penalties);
       		newNet.setFPasses(fpasses);

       		if(nwrite.WriteToFile(newNet.getid(),newNet)) //writes the new NetballMatch to file to the file
         	{
         		g.display(25,23,YELLOW,BLACK,"Netball Database updated successfully....");
            	if( (MessageBox(NULL,TEXT("Do you want Edit another NetBall Match?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            		EditMatch(2); //calls the procedure to create Player
         	}
         	else
         		g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
    	}
      else
      	g.display(25,23,YELLOW,BLACK,"NetBall Match Doesn't Exist");

    }
    else
    	if(MatchType==3)
    	{
    		cout<<endl<<endl<<"Enter The ID Number of Track Match Yo Want to Edit  :  ";
      	cin>>id; //accepts users input
      	if(tread.SearchFile(id)) //searches the user file for this ID number
      	{
      		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
         	g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
         	cout<<endl;
         	newTrack = tread.ReadFromFile(id);
         	newTrack.show();//display infomation so it can edited
				cout<<endl<<"Enter Match Officials i.e P.Prendagas, T.Withmoore :  ";
    			gets(officials);    //accepts the user input
    			cout<<endl<<"Enter Match Location i.e National Stadium :  ";
    			gets(location);
    			cout<<endl<<"Enter The Match Time i.e 3pm :  ";
    			gets(time);
    			cout<<endl<<"Enter The Match Date i.e dd/mm/yy :  ";
    			gets(date);
    			cout<<endl<<"Enter The Name of First Team:  ";
    			gets(team1);
    			cout<<endl<<"Enter The Name of Second Team:  ";
    			gets(team2);
    			if( (MessageBox(NULL,TEXT("Did Match End in a Draw?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    				draw=true;
    			else
    			{
    				if( (MessageBox(NULL,TEXT("Did First Team Win This Contest?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
    				{
         			strcpy(winner,team1);
         			strcpy(loser,team2);
    				}
    				else
    				{
         			strcpy(winner,team1);
         			strcpy(loser,team2);
    				}
       		}
       		cout<<endl<<"Enter The Name of the Match MVP:  ";
       		gets(mvp);
         	cout<<endl<<"Enter the Race Title i.e 100Meter Sprint :  ";
    			cin>>race_title;
      		cout<<endl<<"Enter the Number False Starts :  ";
    			cin>>fstarts;
            cout<<endl<<"Enter the Race fastest Time :  ";
    			cin>>ftime;

       		newTrack.setOfficials(officials);
       		newTrack.setLocation(location);
       		newTrack.setTime(time);
            newTrack.setDate(date);
       		newTrack.setTeam1(team1);
       		newTrack.setTeam2(team2);
       		newTrack.setWinner(winner);
       		newTrack.setLoser(loser);
       		newTrack.setMVP(mvp);
       		newTrack.setDStatus(draw);
       		newTrack.setTitle(race_title);
       		newTrack.setFStarts(fstarts);
            newTrack.setFTime(ftime);

       		if(twrite.WriteToFile(newTrack.getid(),newTrack)) //writes the new NetballMatch to file to the file
         	{
         		g.display(25,23,YELLOW,BLACK,"Netball Database updated successfully....");
            	if( (MessageBox(NULL,TEXT("Do you want Edit another NetBall Match?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            		EditMatch(2); //calls the procedure to create Player
         	}
         	else
         		g.display(25,23,YELLOW,BLACK,"Problem Updating Database....");
    	}
      else
      	g.display(25,23,YELLOW,BLACK,"NetBall Match Doesn't Exist");

    }

 }
//=============================
//View Match Methom
//============================
void ViewMatch(int MatchType)
{
   GRAPHIX g;
   int id;
   socmatfiles sread,swrite;
   netmatfiles nread,nwrite;
   trackmatfiles tread,twrite;
   netmatch newNet;
   trackmatch newTrack;
   socmatch newSoc;

   g.SetScreen();
   g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
   g.display(30,4,YELLOW,BLACK, "VIEW MATCH DATA STATISTICS:  ");
   g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");

      if(MatchType==1)
      {
			if( (MessageBox(NULL,TEXT("Do Want View Infomation\n All Soccer Matches?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      	{
            g.display(1,25,BLACK,BLACK, "                                                                               ");
            g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
            g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            cout<<endl;
          	sread.ReadAllFromFile();
         }
         else
         {
         	_setcursortype(_NORMALCURSOR); //unhides the cursor
         	cout<<endl<<endl<<"Enter The Soccer Match's ID Number :  ";
         	cin>>id; //accepts users input

         	if(sread.SearchFile(id)) //if the Match doesn't exists
         	{
               g.display(1,25,BLACK,BLACK, "                                                                               ");
					g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         		g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
         		g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
         		newSoc=sread.ReadFromFile(id);
            	newSoc.show();
         	}
         	else
         		if( (MessageBox(NULL,TEXT("That Match Doesn't Exist!\nDo You Want To Create Match Now now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            		AddMatch(1);
      	}
      }
      else
      	if(MatchType==2)
         {
				if( (MessageBox(NULL,TEXT("Do You Want View Infomation on \n All NetBall Matches?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      		{
               g.display(1,25,BLACK,BLACK, "                                                                               ");
            	g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
            	g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            	cout<<endl;
          		nread.ReadAllFromFile();
         	}
            else
            {
         		_setcursortype(_NORMALCURSOR); //unhides the cursor
      			cout<<endl<<endl<<"Enter The NetBall Match's ID Number :  ";
      			cin>>id; //accepts users input

      			if(nread.SearchFile(id)) //if the Match doesn't exists
            	{
                  g.display(1,25,BLACK,BLACK, "                                                                               ");
						g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         			g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
         			g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
             		newNet=nread.ReadFromFile(id);
               	newNet.show();
            	}
            	else
            		if( (MessageBox(NULL,TEXT("That Match Doesn't Exist!\nDo You Want To Create Match Now now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
                  	AddMatch(2);
            }
         }
      	else
         	if(MatchType==3)
            {
					if( (MessageBox(NULL,TEXT("Do You Want View Infomation On\n All Track Matches?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
      			{
                  g.display(1,25,BLACK,BLACK, "                                                                               ");
            		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
            		g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
            		g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
            		cout<<endl;
          			tread.ReadAllFromFile();
         		}
               else
               {
               	_setcursortype(_NORMALCURSOR); //unhides the cursor
      				cout<<endl<<endl<<"Enter The Track & Field Match's ID Number :  ";
      				cin>>id; //accepts users input

      				if(tread.SearchFile(id)) //if the Match doesn't exists
         			{
                     g.display(1,25,BLACK,BLACK, "                                                                               ");
               		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         				g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
         				g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
         				newTrack=tread.ReadFromFile(id);
            			newTrack.show();
         			}
         			else
         				if( (MessageBox(NULL,TEXT("That Match Doesn't Exist!\nDo You Want To Create Match Now now?"),TEXT("Finish"),MB_YESNO | MB_ICONQUESTION)) == IDYES)
            				AddMatch(3);
               }
            }


}

//=============================
//Delete Match Methom
//============================
void DelMatch(int MatchType)
{
   GRAPHIX g;
   int id;
   socmatch newSoc,sblank;
   netmatch newNet,nblank;
   trackmatch newTrack,tblank;

   socmatfiles sread;
   netmatfiles nread;
   trackmatfiles tread;

   g.display(1,1,YELLOW,BLUE,      " SPORTS MANAGEMENT SYSTEM                                                       ");
   g.display(30,4,YELLOW,BLACK, "DELETE Match DATA");
   g.display(1,25,BLACK,LIGHTGRAY, " THIS IS USED TO PERMANENTLY DELETE Match INFOMATION                            ");
   g.display(1,5,WHITE,BLACK,      "________________________________________________________________________________");

      if(MatchType==1)
      {
         _setcursortype(_NORMALCURSOR); //unhides the cursor
         cout<<endl<<endl<<"Enter The Soccer Match's ID Number :  ";
         fflush(stdin);
         cin>>id; //accepts users input
         cout<<endl<<endl<<endl;

    		if(!sread.SearchFile(id)) //if the id number could not be found
    		{
         	MessageBox(NULL,TEXT("That ID number could not be found..."),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
         	g.SetScreen(); //clears the screen and sets the background color to black
         	return;
    		}
 	 		g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
	 		g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
         g.display(1,25,WHITE,BLACK, "                                                                                ");
    		cout<<endl;
         newSoc=sread.ReadFromFile(id); //reads the user record into the class
    		newSoc.show(); //show the information that can be edited
    		if( (MessageBox(NULL,TEXT("Are sure you want to delete This Match?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      		if(sread.WriteToFile(newSoc.getid(),sblank))
	      		MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
       		else
         		MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


    		_setcursortype(_NOCURSOR); //hides the cursor
    		g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
    		getch();

    		g.SetScreen();

      }
      else
      	if(MatchType==2)
         {
         	_setcursortype(_NORMALCURSOR); //unhides the cursor
         	cout<<endl<<endl<<"Enter The NetBall Match's ID Number :  ";
         	cin>>id; //accepts users input
         	cout<<endl<<endl<<endl;

    			if(!nread.SearchFile(id)) //if the id number could not be found
    			{
         		MessageBox(NULL,TEXT("That ID number could not be found..."),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
         		g.SetScreen(); //clears the screen and sets the background color to black
         		return;
    			}
 	 			g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         	g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
	 			g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
    			cout<<endl;
         	newNet=nread.ReadFromFile(id); //reads the user record into the class
    			newNet.show(); //show the information that can be edited
    			if( (MessageBox(NULL,TEXT("Are sure you want to delete This Match?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      			if(nread.WriteToFile(newNet.getid(),nblank))
	      			MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
       			else
         			MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


    			_setcursortype(_NOCURSOR); //hides the cursor
    			g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
    			getch();

    			g.SetScreen();
         }
      	else
         	if(MatchType==3)
            {
               _setcursortype(_NORMALCURSOR); //unhides the cursor
      			cout<<endl<<endl<<"Enter The Track & Field Match's ID Number :  ";
      			cin>>id; //accepts users input

         		cout<<endl<<endl<<endl;

    				if(!tread.SearchFile(id)) //if the id number could not be found
    				{
         			MessageBox(NULL,TEXT("That ID number could not be found..."),TEXT("Sorry"),MB_ICONWARNING);//this displays a message box with an error message
         			g.SetScreen(); //clears the screen and sets the background color to black
         			return;
    				}
 	 				g.display(1,10,WHITE,BLACK, "________________________________________________________________________________");
         		g.display(25,11,WHITE,BLACK,"HERE IS THE USER INFORMATION");
	 				g.display(1,13,WHITE,BLACK, "________________________________________________________________________________");
    				cout<<endl;
         		newTrack=tread.ReadFromFile(id); //reads the user record into the class
    				newTrack.show(); //show the information that can be edited
    				if( (MessageBox(NULL,TEXT("Are sure you want to delete This Match?"),TEXT("Delete"),MB_YESNO | MB_ICONQUESTION) == IDYES))
      				if(tread.WriteToFile(newTrack.getid(),tblank))
	      				MessageBox(NULL,TEXT("Recorded deleted"),TEXT("Delete"),MB_ICONINFORMATION);
       				else
         				MessageBox(NULL,TEXT("Recorded could not be deleted at this time"),TEXT("Delete"),MB_ICONERROR);


    				_setcursortype(_NOCURSOR); //hides the cursor
    				g.display(25,23,YELLOW,BLACK,"Database updated successfully....");
    				getch();

    				g.SetScreen();
            }



}

//=====================================
// List Player on More than one team
//======================================

void OnTeams()
{
   GRAPHIX g;
    bool playsoc;
    bool playnet;
    bool playtrack;

   member player;
   netTeam newNet;
   trackTeam newTrack;
   soccerTeam newSoc;

   ofstream matches("Print_Players_On_Teams.txt", ios::app);
   ifstream sfile("soccerTeam.txt",ios::in | ios::binary);//creats and opens a file in read/write mode
   ifstream nfile("netTeam.txt",ios::in | ios::binary);
   ifstream tfile("trackTeam.txt",ios::in | ios::binary);
   ifstream mfile("trackTeam.txt",ios::in | ios::binary);

   //go thru the memmber file then check to c if each id exist on soc,net n track teams
   if(mfile)
   {
   	mfile.read(reinterpret_cast<char*>(&player), sizeof(member)); //read the first record
   	while(!mfile.eof())
   	{

         if(sfile)
         {
      		sfile.read(reinterpret_cast<char*>(&newSoc), sizeof(soccerTeam)); //read the first record
   			while(!sfile.eof())
   			{
      			if(newSoc.memberExist(player.getMemberID()))
         			playsoc=true;

      			sfile.read(reinterpret_cast<char*>(&newSoc), sizeof(soccerTeam));
      		}
         }

         if(nfile)
         {
      		nfile.read(reinterpret_cast<char*>(&newNet), sizeof(netTeam)); //read the first record
   			while(!nfile.eof())
   			{
      			if(newNet.memberExist(player.getMemberID()))
         			playnet=true;

      			nfile.read(reinterpret_cast<char*>(&newNet), sizeof(netTeam));
      		}
         }

         if(tfile)
         {
      		tfile.read(reinterpret_cast<char*>(&newTrack), sizeof(trackTeam)); //read the first record
   			while(!nfile.eof())
   			{
      			if(newTrack.memberExist(player.getMemberID()))
         			playtrack=true;

      			tfile.read(reinterpret_cast<char*>(&newTrack), sizeof(trackTeam));
            }
         }

      	if(playsoc && playnet && playtrack)
      	{
      		if(matches)
         	{
         		matches<<"Player ID          : M"<<player.getMemberID()<<endl;
            	matches<<"PLayer Name        :  "<<player.getName().data()<<endl;
            	matches<<"Teams              :  "<<newSoc.getTitle().data()<<"  and  "<<newNet.getTitle().data()<<"  and  "<<newTrack.getTitle().data()<<endl<<endl<<endl<<endl;

         	}

      	}
      	else
      		if(playsoc && playnet)
      		{
      			if(matches)
         		{
         			matches<<"Player ID          : M"<<player.getMemberID()<<endl;
            		matches<<"PLayer Name        :  "<<player.getName().data()<<endl;
            		matches<<"Teams              :  "<<newSoc.getTitle().data()<<"  and  "<<newNet.getTitle().data()<<endl<<endl<<endl<<endl;

         		}

      		}
      		else
      			if(playsoc && playtrack)
         		{
         			if(matches)
         			{
         				matches<<"Player ID          : M"<<player.getMemberID()<<endl;
            			matches<<"PLayer Name        :  "<<player.getName().data()<<endl;
            			matches<<"Teams              :  "<<newSoc.getTitle().data()<<"  and  "<<newTrack.getTitle().data()<<endl<<endl<<endl<<endl;

         			}
         		}
         		else
         			if(playnet && playtrack)
            		{
         				if(matches)
         				{
         					matches<<"Player ID          : M"<<player.getMemberID()<<endl;
            				matches<<"PLayer Name        :  "<<player.getName().data()<<endl;
            				matches<<"Teams              :  "<<newNet.getTitle().data()<<"  and  "<<newTrack.getTitle().data()<<endl<<endl<<endl<<endl;

         				}

                  }
			mfile.read(reinterpret_cast<char*>(&player), sizeof(member)); //read the first record
   	}

   }

}
//===============================================
// Displays Graphics for Initializing of method
//===============================================
void Initializing()
{
   clrscr();

    int lo, di, c1,c2;

    time_t t;
    srand((unsigned) time(&t)); //seed from time to crearte a truly random number

    do
    {
    	c1 = 1 + rand() % 15;
    	c2 = 1 + rand() % 15;
    }while(c1==8);

    textcolor(LIGHTCYAN);
    gotoxy(1, 25); cprintf("Press Any Key To Skip This Srceen");
    gotoxy(1, 1); cprintf("Press Any Key To Skip This Srceen");
    gotoxy(47, 25); cprintf("Press Any Key To Skip This Srceen");
    gotoxy(47, 1); cprintf("Press Any Key To Skip This Srceen");

    for(lo=28; lo<=53; lo++)
    {
     textcolor(8);
     gotoxy(lo,14);cprintf("€€");
    }

    for(lo=0, di=28; lo<=100; lo+=15, di+=4)
    {
      if(kbhit())
            {
             	getch();
             	break;
            }
      _setcursortype(_NOCURSOR);
      textcolor(c2);
     	gotoxy(28,12);cprintf("Initializing Module....");
      textcolor(c1);
      if(lo>=90)
      	lo=100;
     	gotoxy(28,13);cprintf("%d%", lo);
     	gotoxy(di-2,14);cprintf("€€€€€");
      sleep(1);

    }
}
//==========================================
// Credits     displays info on programmers
//============================= ===
void Credits()
{
   GRAPHIX g;

	clrscr();
	textcolor(14);
	gotoxy(20, 17); cprintf("rogrammers:");
   textcolor(13);


	textcolor(9);
	gotoxy(19, 17); cprintf("P");

   gotoxy(32, 7); cprintf("                   .-`` `} ");
   gotoxy(32, 8); cprintf("           _./)   /      }");
   gotoxy(32, 9); cprintf("         .`o   \ |       }");
   gotoxy(32, 10);cprintf("   Da    `.___.``.\    {`");
   gotoxy(32, 11);cprintf("  Pesky  /`\_/  , `.    }");
   gotoxy(32, 12);cprintf("         \=` .-`   _`\  {");
   gotoxy(32, 13);cprintf(" Squirrel ```;/      `,}");
   gotoxy(32, 14);cprintf("             _\       ; }");
   gotoxy(32, 15);cprintf("           /__`;-..`--`");

   gotoxy(31, 19);cprintf("With God as Our Guide We Seek The Best and the Highest");

   g.Con_MSG(51,25);
	getch();

}
void ExitPro()
{
    GRAPHIX g;

     g.SetScreen();      //procedure to clear the screen
     g.No(); //hides cursor
     g.display(1,1,YELLOW,BLUE, " SPORTS MANAGEMENT SYSTEM v1.5                                                  ");

     OnTeams();
	  g.display(10,6,LIGHTGRAY,BLACK,"Thank you for using this product");
	  g.display(10,8,LIGHTGRAY,BLACK,"Open File \'Print_Match_Info \' To Print Match Info i.e: MVP's");
     g.display(10,9,LIGHTGRAY,BLACK,"Open File \'Print_Players_On_Teams \' To Print Players ");
     g.display(10,10,LIGHTGRAY,BLACK,"that play more than one sport...");
     g.Con_MSG(51,25);
     getch();
     exit(0);   //exits the program
}