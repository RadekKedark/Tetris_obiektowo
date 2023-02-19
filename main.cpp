#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

class Figura
{
public:
    int x,y,o,a,b,c,d,e,f,g,h,i;
    int tablica[3][3];
    Figura(int x=5, int y=5, int o=1, int a=1, int b=1, int c=1, int d=0, int e=0, int f=0, int g=0, int h=0, int i=0)
    {
        this ->x=x;
        this ->y=y;
        this ->o=o;
        this ->a=a;
        this ->b=b;
        this ->c=c;
        this ->d=d;
        this ->e=e;
        this ->f=f;
        this ->g=g;
        this ->h=h;
        this ->i=i;
    }

     void ustaw_punkt (int x=5, int y=5, int o=1, int a=1, int b=1, int c=1, int d=0, int e=0, int f=0, int g=0, int h=0, int i=0)
    {
        this ->x=x;
        this ->y=y;
        this ->o=o;
        this ->a=a;
        this ->b=b;
        this ->c=c;
        this ->d=d;
        this ->e=e;
        this ->f=f;
        this ->g=g;
        this ->h=h;
        this ->i=i;
    }

     void rysuj(int mapa_tab[][30])
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(tablica[i][j]==1)
                {
                    mapa_tab[x+i][y+j]=1;
                    gotoxy(x+i,y+j);
                    cout<<"I"<<endl;
                }
            }
        }
    Sleep(100);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(tablica[i][j]==1)
                {
                    gotoxy(x+i,y+j);
                    cout<<" "<<endl;
                }
            }
        }
    }


         void przypisanie_wartosci_obiektu(int mapa_tab[][30])
    {
        if(o==1)
        {
        tablica[0][0]=a;
        tablica[0][1]=b;
        tablica[0][2]=c;
        tablica[1][0]=d;
        tablica[1][1]=e;
        tablica[1][2]=f;
        tablica[2][0]=g;
        tablica[2][1]=h;
        tablica[2][2]=i;
        }
        if(o==2)
        {
        tablica[0][0]=g;
        tablica[0][1]=d;
        tablica[0][2]=a;
        tablica[1][0]=h;
        tablica[1][1]=e;
        tablica[1][2]=b;
        tablica[2][0]=i;
        tablica[2][1]=f;
        tablica[2][2]=c;
        }
        if(o==3)
        {
        tablica[0][0]=i;
        tablica[0][1]=h;
        tablica[0][2]=g;
        tablica[1][0]=f;
        tablica[1][1]=e;
        tablica[1][2]=d;
        tablica[2][0]=c;
        tablica[2][1]=b;
        tablica[2][2]=a;
        }
        if(o==4)
        {
        tablica[0][0]=c;
        tablica[0][1]=f;
        tablica[0][2]=i;
        tablica[1][0]=b;
        tablica[1][1]=e;
        tablica[1][2]=h;
        tablica[2][0]=a;
        tablica[2][1]=d;
        tablica[2][2]=g;
        }

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(tablica[i][j]==1)
                {
                    mapa_tab[x+i][y+j]=1;
                }
                else
                {
                    mapa_tab[x+i][y+j]=0;
                }
            }
        }
    }



    void obrot()
    {
        if (o==4)
        {
            o=1;
        }
        else o++;
    }


    void przesun_lewo()
    {
        x--;
    }
    void przesun_prawo()
    {
        x++;
    }
    void przesun_wdol()
    {
        y++;
    }
    void przesun_wdol_3x()
    {
        y++;
        y++;
        y++;
    }
};

class Gra
{
private:
    Figura I;
    Figura L;
    Figura LP;
    Figura II;
    Figura BL;
    Figura BLP;
    Figura _L;
    bool zmiana_obiektu = true;
    int mapa_tablica[30][30];
    int plansza_gry[30][30];
    int obr=0;
    int p=0;
    int e=0;
    int l=0;
    int koniec=0;
    int czas = clock();
    int czas2=czas+600;
    int punkty=0;
    int linia=0;

public:
    Figura*wsk;
    int numer_obiektu=2;
    Gra()
    {
        for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
                {
                mapa_tablica[i][j]=0;
                }
            }

        for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
                {
                plansza_gry[i][j]=0;
                }
            }

        for(int i=0; i<30; i++)
            {
            gotoxy(i,25);
            plansza_gry[i][25]=1;
            }
        for(int i=6; i<25; i++)
            {
            gotoxy(0,i);
            plansza_gry[0][i]=1;
            }
        for(int i=6; i<25; i++)
            {
            gotoxy(29,i);
            plansza_gry[29][i]=1;
            }
            gotoxy(40,6);
            cout<<"STEROWANIE:"<<endl;
            gotoxy(40,7);
            cout<<"LEWO - A"<<endl;
            gotoxy(40,8);
            cout<<"PRAWO - D"<<endl;
            gotoxy(40,9);
            cout<<"OBROT - S"<<endl;
            gotoxy(40,10);
            cout<<"3xDOL - X"<<endl;
    }

    int gra(int &kon)
    {
                switch(numer_obiektu)
        {
            case 1:
                wsk=&I;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,0,0,0,1,1,1,0,0,0);
                   }
                break;
            case 2:
                wsk=&L;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,1,1,1,0,0,1,0,0,0);
                   }
                break;
            case 3:
                wsk=&LP;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,0,0,0,0,0,1,1,1,1);
                   }
                break;
            case 4:
                wsk=&LP;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,0,0,0,1,1,1,1,1,1);
                   }
                break;
            case 5:
                wsk=&BL;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,1,1,1,0,0,1,0,0,1);
                   }
                break;
            case 6:
                wsk=&BLP;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,0,0,1,0,0,1,1,1,1);
                   }
                break;
            case 7:
                wsk=&BLP;
                if(zmiana_obiektu)
                   {
                    zmiana_obiektu=false;
                    wsk->ustaw_punkt(15,2,1,0,0,1,0,1,1,0,0,1);
                   }
                break;
        }

        wsk->przypisanie_wartosci_obiektu(mapa_tablica);

            if(kolizja_obrot(mapa_tablica,plansza_gry)&(obr==1))
        {
            wsk->obrot();
            wsk->obrot();
            wsk->obrot();
            wsk->przypisanie_wartosci_obiektu(mapa_tablica);
        }

            kolizja_prawo(mapa_tablica,plansza_gry);
            kolizja_lewo(mapa_tablica,plansza_gry);
            kolizja_3xwdol(mapa_tablica,plansza_gry);

            wsk->rysuj(mapa_tablica);



                 czas = clock();
                 if(czas>=czas2)
                 {
                   dodaj_y();
                   czas2=czas+1000;
                 }

        if(kolizja(mapa_tablica,plansza_gry))
        {
            kopiuj_tablice(mapa_tablica,plansza_gry);
            srand( time( NULL ) );
            numer_obiektu = (rand()%7)+1;
            zmiana_obiektu = true;
            e=0;
        }

        rysuj_plansze(plansza_gry);

        for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
                {
                mapa_tablica[i][j]=0;
                }
            }
            obr=0;
            koniec_gry(plansza_gry);
            linia=usuwanie_plansza(plansza_gry);

            if(linia!=0)
            {
            usun_plansza_gry(plansza_gry, linia);
            rysuj_plansze(plansza_gry);
            punkty++;
            }

            if(koniec==1)
            {
                okno_koncowe();
            }
            kon=koniec;
            return kon;
    }


    void krec()
    {
        wsk->obrot();
        obr=1;
    }
    void x_wlewo()
    {
        if(l!=1)
        {
        wsk->przesun_lewo();
        }
    }
    void x_wprawo()
    {
        if(p!=1)
        {
        wsk->przesun_prawo();
        }
    }

    void dodaj_y()
    {
        wsk->przesun_wdol();
    }

    void y_3wdol()
    {
        if(e!=1)
        {
        wsk->przesun_wdol_3x();
        }
    }

    bool kolizja(int mapa_tab[][30],int plansza[][30])
    {
            for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
            {
                if((mapa_tab[i][j]==plansza[i][j+1])&(plansza[i][j+1]==1))
                {
                    return true;
                }
            }
            }
    }

    bool kolizja_obrot(int mapa_tab[][30],int plansza[][30])
    {
            for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
            {
                if((mapa_tab[i][j]==plansza[i][j])&(plansza[i][j]==1))
                {
                    return true;
                }
            }
            }
    }

    void kolizja_lewo(int mapa_tab[][30],int plansza[][30])
    {
            l=0;
            for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
            {

                if((mapa_tablica[i][j]==1)&(plansza_gry[i-1][j])==1)
                {
                    l=1;
                    break;
                }
                if((mapa_tablica[i][j]==1)&(plansza_gry[i-1][j+1])==1)
                {
                    l=1;
                    break;
                }
            }
            }
    }

    void kolizja_prawo(int mapa_tab[][30],int plansza[][30])
    {
            p=0;
            for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
            {

                if((mapa_tablica[i][j]==1)&(plansza_gry[i+1][j])==1)
                {
                    p=1;
                    break;
                }
                if((mapa_tablica[i][j]==1)&(plansza_gry[i+1][j+1])==1)
                {
                    p=1;
                    break;
                }
            }
            }
    }

    void kopiuj_tablice(int mapa_tab[][30],int plansza[][30])
    {
        for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
            {
                if((mapa_tab[i][j]==1))
                {
                    plansza[i][j]=1;
                }
            }
            }
    }

    void kolizja_3xwdol(int mapa_tab[][30],int plansza[][30])
    {
            for(int i=0; i<30; i++)
            {
            for(int j=0; j<30; j++)
            {
                if((mapa_tab[i][j]==1)&(plansza[i][j+4])==1)
                {
                    e=1;
                    break;
                }
            }
            }
    }

        void koniec_gry(int plansza[][30])
    {

                for(int i=0; i<30; i++)
                {
                if((plansza[i][5])==1)
                {
                     koniec=1;
                }
                }
    }

        int usuwanie_plansza(int plansza[][30])
 {
     int y=0;
     int j=1;
     int i;
     int licz=0;

     do
     {
            do
            {
                licz=0;
                for(i=1; i<29; i++)
                {
                    if(plansza[i][j]==0)
                    {
                        y=1;
                    }
                    if(plansza[i][j]==1)
                    {
                       licz++;
                    }
                    if (licz==28)
                    {
                        y=1;
                    }
                }
            }
            while(y==0);
            y=0;
            if (licz==28)
                    {
                   break;
                    }
            else
            {
                j++;
            }


     }
            while(j!=25);

            if(licz==28)
            {
                return j;
            }
            else
            {
                return 0;
            }
 }

 void usun_plansza_gry(int plansza[][30], int &l)
 {
        for(int i=1; i<29; i++)
                {
                    plansza[i][l]=0;
                }
        Sleep(2000);
        for(int i=1; i<29; i++)
            {
            for(int j=l; j>5; j--)
            {
                    plansza[i][j]=plansza[i][j-1];
            }
            }
 }

 void rysuj_plansze(int plansza[][30])
 {
                      for(int i=0; i<30; i++)
        {
            for(int j=0; j<30; j++)
            {
                if(plansza[i][j]==1)
                {
                    gotoxy(i,j);
                    cout<<"I"<<endl;
                }
                else
                {
                    gotoxy(i,j);
                    cout<<" "<<endl;
                }
            }
        }
 }

    void okno_koncowe()
    {

        gotoxy(13,13);
        cout<<"Zdobyles "<<punkty<<" punktow"<<endl;
    }
};

int main()
{
    Gra g;
    srand( time( NULL ) );
    char dir;
    int a=1;
    do
    {

        if(kbhit())
        {
            a=getch();
        }

        if(a=='s'||a=='S')
        {
            dir=1;
        }
        if(a=='d'||a=='D')
        {
            dir=2;
        }
        if(a=='a'||a=='A')
        {
            dir=3;
        }
        if(a=='x'||a=='X')
        {
            dir=4;
        }
        switch(dir)
        {
        case 1:
            g.krec();
            a='w';
            dir=0;
            break;
        case 2:
            g.x_wprawo();
            a='w';
            dir=0;
            break;
        case 3:
            g.x_wlewo();
            a='w';
            dir=0;
            break;
        case 4:
            g.y_3wdol();
            a='w';
            dir=0;
            break;
        }
        g.gra(a);
    }
    while(a!=1);

    return 0;
}

