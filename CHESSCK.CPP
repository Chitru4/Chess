#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

void main()                         /*chess made by chitraksh kumar
		      pawn,horse,king,rook,bishop,queen(all) functioning
					1761 lines total 
					4086 lines compiled*/
{
 clrscr();
 int y,q=0,move,mover,movest,movend,d=1,cond,cond1,imp1,imp2,mt,mp,check,bishx,bishy,bishix,bishiy,prex,prey;
 int col1=15,col2=0,colm,mate,cmate;
 char t,yo,piece,jj,color;
 char x[9][9]={
		{'7','r','h','b','k','q','b','h','r'},
		{'6','p','p','p','p','p','p','p','p'},
		{'5',' ',' ',' ',' ',' ',' ',' ',' '},
		{'4',' ',' ',' ',' ',' ',' ',' ',' '},
		{'3',' ',' ',' ',' ',' ',' ',' ',' '},
		{'2',' ',' ',' ',' ',' ',' ',' ',' '},
		{'1','P','P','P','P','P','P','P','P'},
		{'0','R','H','B','K','Q','B','H','R'},
		{'Û','0','1','2','3','4','5','6','7'}
	      };
 textcolor(BLUE);
 cprintf("Enter the color of the board u want:");
 cout<<endl;
 textcolor(BLACK);
 textbackground(WHITE);
 cprintf("b-BLACK");
 cout<<endl;
 textcolor(GREEN);
 textbackground(BLACK);
 cprintf("g-GREEN");
 cout<<endl;
 textcolor(6);
 textbackground(BLACK);
 cprintf("r-BROWN");
 cout<<endl;
 textcolor(15);
  textbackground(BLACK);
 cprintf("t-RANDOM");
 cout<<endl;
 cin>>color;
 switch(color)
 {
  case 'g':
  {
   colm=10;
   col1=0;
   col2=14;
   break;
  }

  case 'b':
  {
   colm=0;
   col1=8;
   col2=15;
   break;
  }

  case 'r':
  {
   colm=6;
   col1=0;
   col2=15;
  }

  case 't':
  {
   randomize();
   colm=rand()%14;
   col1=0;
   col2=15;
  }
 }

 do
 {
 clrscr();
 textbackground(BLACK);
 for(int r=0;r<9;r++)
 {
   q=r+1;
   for(int i=0;i<9;i++)            //for adding colors alternatively
   {
   textbackground(BLACK);
   if(isdigit(x[r][i]))
      textcolor(BLUE);

     if((q+2)%2==0)
     {
       textbackground(WHITE);
       if(islower(x[r][i]))
       {
	 textcolor(col2);
       }
       else if(isupper(x[r][i]))
       {
	 textcolor(col1);
       }
       else if(isdigit(x[r][i]))
       {
	 textcolor(BLUE);
	 textbackground(BLACK);
       }
       t=x[r][i];
       cprintf(" %c ",t);
       q++;
     }
     else
     {
       textbackground(colm);
       if(islower(x[r][i]) && i>0)
       {
	 textcolor(col2);
       }
       else if(isupper(x[r][i]) && i>0)
       {
	 textcolor(col1);
       }
       else if(isdigit(x[r][i]))
       {
	 textcolor(BLUE);
	 textbackground(BLACK);
       }
       t=x[r][i];
       cprintf(" %c ",t);
       q++;
     }
   if(x[r][i]=='k')
   {
     bishx=i;
     bishy=r;
   }
   if(x[r][i]=='K')
   {
    bishix=i;
    bishiy=r;
   }
  }
 cout<<endl;
 }
  textcolor(WHITE);
  textbackground(BLACK);
  if(d%2!=0)                                    //d is the total no. of moves
   cout<<"WHITE'S TURN"<<endl;
  else
   cout<<"BLACK'S TURN"<<endl;

  jj='a';

   if(cond==0)
      cout<<"ILLEGAL MOVE , PLAY AGAIN"<<endl;

    cond=0;
					      //condition for check
  if(x[mover][movend]=='H' && (x[mover+2][movend+1]=='k' || x[mover+2][movend-1]=='k' || x[mover+1][movend+2]=='k' || x[mover+1][movend-2]=='k' || x[mover-2][movend+1]=='k' || x[mover-2][movend-1]=='k' || x[mover-1][movend+2]=='k' || x[mover-1][movend-2]=='k'))
  {
    jj='H';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
  }
  else if(x[mover][movend]=='h' && (x[mover+2][movend+1]=='K' || x[mover+2][movend-1]=='K' || x[mover+1][movend+2]=='K' || x[mover+1][movend-2]=='K' || x[mover-2][movend+1]=='K' || x[mover-2][movend-1]=='K' || x[mover-1][movend+2]=='K' || x[mover-1][movend-2]=='K'))
  {
    jj='h';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
  }

  if(x[mover][movend]=='P' && x[mover-1][movend+1]=='k' || x[mover-1][movend-1]=='k')
  {
    jj='H';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
  }
  else if(x[mover][movend]=='p' && x[mover+1][movend+1]=='K' || x[mover+1][movend-1]=='K')
  {
    jj='h';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
  }

  if(x[mover][movend]=='B')
  {
    imp1=abs(bishy-mover);
    imp2=abs(bishx-movend);
    mt=mover;
    mp=movend;
    if(imp1==imp2)
    {
    if(bishy>mt && bishx>mp)
     {
      for(;mt<bishy && mp<bishx;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	 cond=1;
      }
     }
     else if(bishy<mt && bishx<mp)
     {
      for(;bishy<mt && bishx<mp;)
      {
       if(isalpha(x[mt][mp]) && (mt!=mover && mp!=movend))
       {
	 cond=0;
	 break;
       }
       else
	 cond=1;
      mp--;
      mt--;
      }
     }
     else if(bishy<mt && bishx>mp)
     {
      for(;mt>bishy && mp<bishx;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	 cond=1;
      mp++;
      mt--;
      }
     }
     else if(bishy>mt && bishx<mp)
     {
      for(;mt<bishy && mp>bishx;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]))
	 cond=1;
      mp--;
      mt++;
      }
     }
   }
   if(cond==1)
   {
    jj='B';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
   }
  }

  if(x[mover][movend]=='b')
  {
    imp1=abs(bishiy-mover);
    imp2=abs(bishix-movend);
    mt=mover;
    mp=movend;
    if(imp1==imp2)
    {
    if(bishiy>mt && bishix>mp)
     {
      for(;mt<bishiy && mp<bishix;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]))
	 cond=1;
      }
     }
     else if(bishiy<mt && bishix<mp)
     {
      for(;bishiy<mt && mp>bishix;)
      {
       if(isalpha(x[mt][mp]) && mt!=mover && mp!=movend)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	 cond=1;
      mp--;
      mt--;
      }
     }
     else if(bishiy<mt && bishix>mp)
     {
      for(;mt>bishiy && mp<bishix;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	 cond=1;
      mp++;
      mt--;
      }
     }
     else if(bishiy>mt && bishix<mp)
     {
      for(;mt<bishiy && mp>bishix;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	 cond=1;
      mp--;
      mt++;
      }
     }
   }
   if(cond==1)
   {
    jj='b';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
   }
  }

  if(x[mover][movend]=='R')
  {
    if(mover==bishy && bishx>movend)
    {
      for(int ma=movend;ma<bishx;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=movend)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(mover==bishy && bishx<movend)
    {
      for(int ma=bishx;ma<movend;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=bishx)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(bishx==movend && mover<bishy)
    {
      for(int ma=mover;ma<bishy;ma++)
      {
	if(isalpha(x[ma][bishx]) && ma!=mover)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movend==bishx && mover>bishy)
    {
      for(int ma=bishy;ma<mover;ma++)
      {
	if(isalpha(x[ma][movend]) && ma!=bishy)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	 cond=1;
	}
      }
    }
   if(cond==1)
   {
    jj='R';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
   }

  }

  if(x[mover][movend]=='r')
  {
    if(mover==bishiy && bishix>movend)
    {
      for(int ma=movend;ma<bishix;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=movend)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(mover==bishiy && bishix<movend)
    {
      for(int ma=bishix;ma<movend;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=bishix)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(bishix==movend && mover<bishiy)
    {
      for(int ma=mover;ma<bishiy;ma++)
      {
	if(isalpha(x[ma][bishix]) && ma!=mover)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movend==bishix && mover>bishiy)
    {
      for(int ma=bishiy;ma<mover;ma++)
      {
	if(isalpha(x[ma][movend]) && ma!=bishiy)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	 cond=1;
	}
      }
    }
    if(cond==1)
    {
      jj='r';
      cout<<"CHECK"<<endl;
      prex=movend;
      prey=mover;
    }
  }

  if(x[mover][movend]=='Q')
  {
    imp1=abs(bishy-mover);
    imp2=abs(bishx-movend);
    mt=mover;
    mp=movend;
    if(imp1==imp2)
    {
    if(bishy>mt && bishx>mp)
     {
      for(;mt<bishy && mp<bishx;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	 cond=1;
      }
     }
     else if(bishy<mt && bishx<mp)
     {
      for(;bishy<mt && mp>bishx;)
      {
       if(isalpha(x[mt][mp]) && mt!=mover && mp!=movend)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]))
	 cond=1;
      mp--;
      mt--;
      }
     }
     else if(bishy<mt && bishx>mp)
     {
      for(;mt>bishy && mp<bishx;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	 cond=1;
      mp++;
      mt--;
      }
     }
     else if(bishy>mt && bishx<mp)
     {
      for(;mt<bishy && mp>bishx;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	 cond=1;
      mp--;
      mt++;
      }
     }
   }
   if(cond==1)
   {
    jj='B';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
   }
   cond=0;
   if(mover==bishy && bishx>movend)
    {
      for(int ma=movend;ma<bishx;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=movend)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(mover==bishy && bishx<movend)
    {
      for(int ma=bishx;ma<movend;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=bishx)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(bishx==movend && mover<bishy)
    {
      for(int ma=mover;ma<bishy;ma++)
      {
	if(isalpha(x[ma][bishx]) && ma!=mover)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movend==bishx && mover>bishy)
    {
      for(int ma=bishy;ma<mover;ma++)
      {
	if(isalpha(x[ma][movend]) && ma!=bishy)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[bishy][bishx]) || x[bishy][bishx]==' ')
	{
	 cond=1;
	}
      }
    }
   if(cond==1)
   {
    jj='R';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
   }
  }
  if(x[mover][movend]=='q')
  {
    imp1=abs(bishiy-mover);
    imp2=abs(bishix-movend);
    mt=mover;
    mp=movend;
    if(imp1==imp2)
    {
    if(bishiy>mt && bishix>mp)
     {
      for(;mt<bishiy && mp<bishix;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]))
	 cond=1;
      }
     }
     else if(bishiy<mt && bishix<mp)
     {
      for(;bishiy<mt && mp>bishix;)
      {
       if(isalpha(x[mt][mp]) && mt!=mover && mp!=movend)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	 cond=1;
      mp--;
      mt--;
      }
     }
     else if(bishiy<mt && bishix>mp)
     {
      for(;mt>bishiy && mp<bishix;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	 cond=1;
      mp++;
      mt--;
      }
     }
     else if(bishiy>mt && bishix<mp)
     {
      for(;mt<bishiy && mp>bishix;)
      {
       if(isalpha(x[mt][mp]) && mp!=movend && mt!=mover)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	 cond=1;
      mp--;
      mt++;
      }
     }
   }
   if(cond==1)
   {
    jj='b';
    cout<<"CHECK"<<endl;
    prex=movend;
    prey=mover;
   }
   cond=0;
   if(mover==bishiy && bishix>movend)
    {
      for(int ma=movend;ma<bishix;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=movend)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(mover==bishiy && bishix<movend)
    {
      for(int ma=bishix;ma<movend;ma++)
      {
	if(isalpha(x[mover][ma]) && ma!=bishix)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(bishix==movend && mover<bishiy)
    {
      for(int ma=mover;ma<bishiy;ma++)
      {
	if(isalpha(x[ma][bishix]) && ma!=mover)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movend==bishix && mover>bishiy)
    {
      for(int ma=bishiy;ma<mover;ma++)
      {
	if(isalpha(x[ma][movend]) && ma!=bishiy)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[bishiy][bishix]) || x[bishiy][bishix]==' ')
	{
	 cond=1;
	}
      }
    }
    if(cond==1)
    {
      jj='r';
      cout<<"CHECK"<<endl;
      prex=movend;
      prey=mover;
    }
  }                                          //all the check cases end here


  cond=0;

  //coordinates
  cout<<"enter coordinates of piece to be moved"<<endl;
  cout<<"x:";
  cin>>movest;
  cout<<"y:";
  cin>>move;
  move=move-7;
  move=abs(move);
  movest+=1;

  cout<<"enter new coordinates of piece"<<endl;
  cout<<"x:";
  cin>>movend;
  cout<<"y:";
  cin>>mover;
  mover=mover-7;
  mover=abs(mover);
  movend+=1;

  cond=0;

  //checkmate condition
  if(jj=='h' && x[move][movest]=='K' || isupper(x[move][movest]) && mover==prey && movend==prex)
    cond=1;

  else if(jj=='h')                            //for horse
  {
    cond=0;
    break;
  }

  if(jj=='H' && x[move][movest]=='k' || islower(x[move][movest]) && mover==prey && movend==prex)
    cond=1;


  else if(jj=='H')
  {
    cond=0;
    break;
  }

  if(jj=='b' && (x[move][movest]=='K' || (isupper(x[move][movest]) && mover==prey && movend==prex)))
    cond=1;

  if(jj=='b')
  {                                                //for bishop
    mt=prey;
    mp=prex;
    if(bishiy>mt && bishix>mp)
     {
      for(;mt<bishiy && mp<bishix;mp++ && mt++)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='K' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      }
     }
     if(bishiy<mt && bishix<mp)
     {
      for(;bishiy<mt && mp>bishix;)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='K' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      mp--;
      mt--;
      }
     }
     if(bishiy<mt && bishix>mp)
     {
      for(;mt>bishiy && mp<bishix;)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='K' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      mp++;
      mt--;
      }
     }
     if(bishiy>mt && bishix<mp)
     {
      for(;mt<bishiy && mp>bishix;)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='K' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      mp--;
      mt++;
      }
     }
   }


  else if(jj=='b' && cond!=0)
  {
    cond=0;
      break;
  }

  if(jj=='B' && (x[move][movest]=='k' || (islower(x[move][movest]) && mover==prey && movend==prex)))
    cond=1;

  if(jj=='B')
   {
    mt=prey;
    mp=prex;
    if(bishy>mt && bishx>mp)
     {
      for(;mt<bishy && mp<bishx;mp++ && mt++)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='k' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      }
     }
     else if(bishy<mt && bishx<mp)
     {
      for(;bishy<mt && mp>bishx;)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='k' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      mp--;
      mt--;
      }
     }
     else if(bishy<mt && bishx>mp)
     {
      for(;mt>bishy && mp<bishx;)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='k' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      mp++;
      mt--;
      }
     }
     else if(bishy>mt && bishx<mp)
     {
      for(;mt<bishy && mp>bishx;)
      {
       if(mt==mover && mp==movend)
	 cond=1;
       if(x[move][movest]=='k' && mt==mover && mp==movend)
       {
	 cond=0;
	 break;
       }
      mp--;
      mt++;
      }
     }
   }


  if(jj=='B' && cond!=1)
  {
    cond=0;
      break;
  }
					    //for rook
  if(jj=='R' && x[move][movest]=='k' || islower(x[move][movest]) && mover==prey && movend==prex)
    cond=1;

  if(jj=='R')
  {
  if(mover==bishy && bishx>prex)
    {
      for(int ma=prex;ma<bishx;ma++)
      {
      if(movend==ma)
	  cond=1;
      if(x[move][movest]=='k' && movend==ma)
      {
	cond=0;
	break;
      }
      }
    }
    else if(mover==bishy && bishx<prex)
    {
      for(int ma=bishx;ma<prex;ma++)
      {
	if(movend==ma)
	  cond=1;
       if(x[move][movest]=='k' && movend==ma)
      {
	cond=0;
	break;
      }
    }
    }
    else if(bishx==movend && prey<bishy)
    {
      for(int ma=prey;ma<bishy;ma++)
      {
       if(mover==ma)
	  cond=1;
       if(x[move][movest]=='k' && mover==ma)
      {
	cond=0;
	break;
      }
      }
    }
    else if(movend==bishx && prey>bishy)
    {
      for(int ma=bishy;ma<prey;ma++)
      {
	 if(mover==ma)
	 cond=1;
	 if(x[move][movest]=='k' && mover==ma)
      {
	cond=0;
	break;
      }
	}
      }
    }

  else if(jj=='R' && cond!=1)
  {
    cond=0;
      break;
  }

  if(jj=='r' && x[move][movest]=='K' || isupper(x[move][movest]) && mover==prey && movend==prex)
    cond=1;

  if(jj=='r')
  {
  if(mover==bishy && bishx>prex)
    {
      for(int ma=prex;ma<bishx;ma++)
      {
	 if(movend==ma)
	  cond=1;
      if(x[move][movest]=='K' && movend==ma)
      {
	cond=0;
	break;
      }
      }
    }
    else if(mover==bishy && bishx<prex)
    {
      for(int ma=bishx;ma<prex;ma++)
      {
       if(movend==ma)
	  cond=1;
       if(x[move][movest]=='K' && movend==ma)
      {
	cond=0;
	break;
      }
      }
    }
    else if(bishx==movend && prey<bishy)
    {
      for(int ma=prey;ma<bishy;ma++)
      {
       if(mover==ma)
	  cond=1;
       if(x[move][movest]=='K' && mover==ma)
      {
	cond=0;
	break;
      }
      }
    }
    else if(movend==bishx && prey>bishy)
    {
      for(int ma=bishy;ma<prey;ma++)
      {
       if(mover==ma)
	 cond=1;
	if(x[move][movest]=='K' && mover==ma)
      {
	cond=0;
	break;
      }
	}
      }
    }

  else if(jj=='r' && cond!=1)
  {
    cond=0;
      break;
  }

  switch(x[move][movest])
  {
					 //for pawn
    case 'P':
    if(x[mover][movend]==' ' && movend==movest && mover==move-1)
      cond=1;
    else if(isalpha(x[mover][movend]) && mover==move-1 && movend==movest-1 || movend==movest+1)
      cond=1;
    if(mover<move-1 || isupper(x[mover][movend]))
      cond=0;
    if(move==6 && mover==4 && movest==movend)
      cond=1;
    break;

    case 'p':
    if(x[mover][movend]==' ' && movend==movest && mover==move+1)
      cond=1;
    else if(isalpha(x[mover][movend]) && mover==move+1 && movend==movest-1 || movend==movest+1)
      cond=1;
    if(mover>move+1 || islower(x[mover][movend]))
      cond=0;
    if(move==1 && mover==3 && movest==movend)
      cond=1;
    break;

    case 'q':                             //for queen
    int condition1=0,condition2=0;
    imp1=abs(mover-move);
    imp2=abs(movend-movest);
    mt=move;
    mp=movest;
    if(imp1==imp2)
    {
     if(mover>mt && movend>mp)
     {
      for(;mt<mover && mp<movend;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 condition1=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      }
     }
     else if(mover<mt && movend<mp)
     {
      for(;mover<mt && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mt!=move && mp!=movest)
       {
	 condition1=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      mp--;
      mt--;
      }
     }
     else if(mover<mt && movend>mp)
     {
      for(;mt>mover && mp<movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 condition1=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      mp++;
      mt--;
      }
     }
     else if(mover>mt && movend<mp)
     {
      for(;mt<mover && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 condition1=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      mp--;
      mt++;
      }
     }
    }

    else if(move==mover && movend>movest)
    {
      for(int ma=movest;ma<movend;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movest)
	{
	  condition2=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }
    else if(move==mover && movend<movest)
    {
      for(int ma=movend;ma<movest;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movend)
	{
	  condition2=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }
    else if(movend==movest && move<mover)
    {
      for(int ma=move;ma<mover;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=move)
	{
	  condition2=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }
    else if(movest==movend && move>mover)
    {
      for(int ma=mover;ma<move;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=mover)
	{
	  condition2=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }

    if(condition1==1 || condition2==1)
      cond=1;
    break;

    case 'Q':
    imp1=abs(mover-move);
    imp2=abs(movend-movest);
    mt=move;
    mp=movest;
    if(imp1==imp2)
    {
     if(mover>mt && movend>mp)
     {
      for(;mt<mover && mp<movend;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 condition1=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      }
     }
     else if(mover<mt && movend<mp)
     {
      for(;mover<mt && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mt!=move && mp!=movest)
       {
	 condition1=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      mp--;
      mt--;
      }
     }
     else if(mover<mt && movend>mp)
     {
      for(;mt>mover && mp<movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 condition1=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      mp++;
      mt--;
      }
     }
     else if(mover>mt && movend<mp)
     {
      for(;mt<mover && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 condition1=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 condition1=1;
      mp--;
      mt++;
      }
     }
    }

    else if(move==mover && movend>movest)
    {
      for(int ma=movest;ma<movend;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movest)
	{
	  condition2=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }
    else if(move==mover && movend<movest)
    {
      for(int ma=movend;ma<movest;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movend)
	{
	  condition2=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }
    else if(movend==movest && move<mover)
    {
      for(int ma=move;ma<mover;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=move)
	{
	  condition2=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }
    else if(movest==movend && move>mover)
    {
      for(int ma=mover;ma<move;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=mover)
	{
	  condition2=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  condition2=1;
	}
      }
    }

    if(condition1==1 || condition2==1)
      cond=1;
    break;
					    //for king
    case 'k':
    if(mover==move+1 || mover==move-1 || movend==movest+1 || movend==movest-1)
      cond=1;
      else if(mover==move+1 && movend==movest-1 || mover==move-1 && movend==movest+1)
    cond=1;
      if(islower(x[mover][movend]))
	cond=0;
       //for castling
      if(mover==0 && movend==2 && x[0][1]=='r' && x[0][2]==' ' && x[0][3]==' ')
      {
	x[mover][movend]='k';
	x[move][movest]=' ';
	x[0][1]=' ';
	x[0][3]='r';
	d++;
      }
      if(mover==0 && movend==6 && x[0][8]=='r' && x[0][7]==' ' && x[0][6]==' ' && x[0][5]==' ')
      {
	x[mover][movend]='k';
	x[move][movest]=' ';
	x[0][8]=' ';
	x[0][5]='r';
	x[0][7]=' ';
	d++;
      }
    break;

    case 'K':
     if(mover==move+1 || mover==move-1 || movend==movest+1 || movend==movest-1)
      cond=1;
     else if(mover==move+1 && movend==movest-1 || mover==move-1 && movend==movest+1)
      cond=1;
      if(isupper(x[mover][movend]))
       cond=0;
       //for castling
     if(mover==7 && movend==2 && x[7][1]=='R' && x[7][2]==' ' && x[7][3]==' ')
      {
	x[mover][movend]='K';
	x[move][movest]=' ';
	x[7][1]=' ';
	x[7][3]='R';
	d++;
      }
      if(mover==7 && movend==6 && x[7][8]=='R' && x[7][7]==' ' && x[7][6]==' ' && x[7][5]==' ')
      {
	x[mover][movend]='K';
	x[move][movest]=' ';
	x[7][8]=' ';
	x[7][5]='R';
	x[7][7]=' ';
	d++;
      }
    break;
				  //for bishop
    case 'b':
    int mt,mp;
    imp1=abs(mover-move);
    imp2=abs(movend-movest);
    mt=move;
    mp=movest;
    if(imp1==imp2)
    {
     if(mover>mt && movend>mp)
     {
      for(;mt<mover && mp<movend;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      }
     }
     else if(mover<mt && movend<mp)
     {
      for(;mover<mt && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mt!=move && mp!=movest)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      mp--;
      mt--;
      }
     }
     else if(mover<mt && movend>mp)
     {
      for(;mt>mover && mp<movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      mp++;
      mt--;
      }
     }
     else if(mover>mt && movend<mp)
     {
      for(;mt<mover && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 cond=0;
	 break;
       }
       else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      mp--;
      mt++;
      }
     }
    }
    break;

    case 'B':
    mt=move;
    mp=movest;
    imp1=abs(mover-move);
    imp2=abs(movend-movest);
    if(imp1==imp2)
    {
     if(mover>mt && movend>mp)
     {
      for(;mt<mover && mp<movend;mp++ && mt++)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      }
     }
     else if(mover<mt && movend<mp)
     {
      for(;mover<mt && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mt!=move && mp!=movest)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      mp--;
      mt--;
      }
     }
     else if(mover<mt && movend>mp)
     {
      for(;mt>mover && mp<movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      mp++;
      mt--;
      }
     }
     else if(mover>mt && movend<mp)
     {
      for(;mt<mover && mp>movend;)
      {
       if(isalpha(x[mt][mp]) && mp!=movest && mt!=move)
       {
	 cond=0;
	 break;
       }
       else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	 cond=1;
      mp--;
      mt++;
      }
     }
    }
    break;
					      //for horse
    case 'h':
    if(mover==move+1 && movend==movest-2 || mover==move+1 && movend==movest+2 || mover==move+2 && movend==movest-1 || mover==move+2 && movend==movest+1 || mover==move-1 && movend==movest+2 || mover==move-1 && movend==movest-2 || mover==move-2 && movend==movest-1 || mover==move-2 && movend==movest+1)
     cond=1;
    if(islower(x[mover][movend]))
      cond=0;
    break;

    case 'H':
    if(mover==move-1 && movend==movest+2 || mover==move-1 && movend==movest-2 || mover==move-2 && movend==movest-1 || mover==move-2 && movend==movest+1 || mover==move+1 && movend==movest-2 || mover==move+1 && movend==movest+2 || mover==move+2 && movend==movest-1 || mover==move+2 && movend==movest+1)
     cond=1;
    if(isupper(x[mover][movend]))
      cond=0;
    break;

    case 'r':                                 //for rook
    if(move==mover && movend>movest)
    {
      for(int ma=movest;ma<movend;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movest)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(move==mover && movend<movest)
    {
      for(int ma=movend;ma<movest;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movend)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movend==movest && move<mover)
    {
      for(int ma=move;ma<mover;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=move)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movest==movend && move>mover)
    {
      for(int ma=mover;ma<move;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=mover)
	{
	  cond=0;
	  break;
	}
	else if(isupper(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    break;

    case 'R':
    if(move==mover && movend>movest)
    {
      for(int ma=movest;ma<movend;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movest)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(move==mover && movend<movest)
    {
      for(int ma=movend;ma<movest;ma++)
      {
	if(isalpha(x[move][ma]) && ma!=movend)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movend==movest && move<mover)
    {
      for(int ma=move;ma<mover;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=move)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	  cond=1;
	}
      }
    }
    else if(movest==movend && move>mover)
    {
      for(int ma=mover;ma<move;ma++)
      {
	if(isalpha(x[ma][movest]) && ma!=mover)
	{
	  cond=0;
	  break;
	}
	else if(islower(x[mover][movend]) || x[mover][movend]==' ')
	{
	 cond=1;
	}
      }
    }
    break;
  }

  //the main conditions, if cond==1 the conditions would work
  if(d%2==0 && isupper(x[move][movest]) && cond==1)
  {
   yo=x[mover][movend];
   x[mover][movend]=x[move][movest];
   x[move][movest]=' ';
   d++;
  }
  else if(d%2==0 && islower(x[move][movest]) && cond==1)
  {
   cout<<"illegal move";
  }
  else if(d%2!=0 && islower(x[move][movest]) && cond==1)
  {
   yo=x[mover][movend];
   x[mover][movend]=x[move][movest];
   x[move][movest]=' ';
   d++;
  }
  else if(d%2!=0 && isupper(x[move][movest]) && cond==1)
  {
   cout<<"illegal move";
  }
  if(cond==1)
  {
   if(x[move][movest]=='p' && mover==7)
     x[mover][movend]='q';
   if(x[move][movest]=='P' && mover==0)
	 x[mover][movend]='Q';
   delay(150);                           //sound effect
   sound(130);
   delay(100);
    sound(200);
    nosound();
  }
 }while(yo!='K' && yo!='k');            //checkmate
 cout<<"CHECKMATE"<<endl;
 if(d%2!=0)
  cout<<"BLACK WINS!!!"<<endl;
 else
  cout<<"WHITE WINS!!!"<<endl;
 cout<<"GAME OVER";
 getch();
}