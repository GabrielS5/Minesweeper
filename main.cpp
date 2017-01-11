
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct MineSweeper{
int coloaneLinii;
int numarMine;
int terenMinat[40][40];
int alegeriJucator[40][40];
char interfata[40][40];
};


void startJoc(MineSweeper &Mine)
{int alegere;
    cout<<"Alege tipul de joc  1-Clasic  2-Intermediar  3-Avansat  4-Custom  ";
cin>>alegere;
if(alegere==1)
{Mine.numarMine=10;
Mine.coloaneLinii=9;
}
else
if(alegere==2)
{Mine.numarMine=40;
Mine.coloaneLinii=16;
}
else
if(alegere==3)
{Mine.numarMine=99;
Mine.coloaneLinii=22;
}
else
{cout<<endl<<"Numar coloane si linii (max 25) ";
    cin>>Mine.coloaneLinii;
 cout<<endl<<"Numar mine (max "<<Mine.coloaneLinii*Mine.coloaneLinii<<") ";
 cin>>Mine.numarMine;
 if(Mine.numarMine>Mine.coloaneLinii*Mine.coloaneLinii)
Mine.numarMine=Mine.coloaneLinii*Mine.coloaneLinii-1;
}

}
void initializareInterfata(char matrice[40][40],int n,char c)
{for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
    matrice[i][j]=c;

}

void initializareMatrice(int matrice[40][40],int coloaneLinii,int elementAles)
{for(int i=0;i<coloaneLinii;i++)
for(int j=0;j<coloaneLinii;j++)
    matrice[i][j]=elementAles;

}
void afisare(int matrice[40][40],int coloaneLinii)
{cout<<endl;
    for(int i=0;i<coloaneLinii;i++)
{for(int j=0;j<coloaneLinii;j++)
    cout<<matrice[i][j]<<" ";
    cout<<endl;}

}

int contineMina(MineSweeper &Mine,int x,int y)
{if(Mine.terenMinat[y][x]==0)
return 0;
return 1;

}

void plantareMine(MineSweeper &Mine)
{int coordonataX,coordonataY,mine=Mine.numarMine;
while(Mine.numarMine>0)
{coordonataX=rand()%Mine.coloaneLinii;
coordonataY=rand()%Mine.coloaneLinii;
if(!contineMina(Mine,coordonataX,coordonataY))
{Mine.terenMinat[coordonataY][coordonataX]=-1;
Mine.numarMine--;}}
Mine.numarMine=mine;}

bool verificarePlasareMina(MineSweeper &Mine,int y,int x)
{if(x>=Mine.coloaneLinii || y>=Mine.coloaneLinii || x<0 || y<0)
return 0;
if(Mine.terenMinat[y][x]==-1)
    return 0;
return 1;

}
bool verificareNedepasireMatrice(int y,int x,MineSweeper &Mine)
{if(x>=Mine.coloaneLinii || y>=Mine.coloaneLinii || x<0 || y<0)
return 0;
return 1;
}

void activareMine(MineSweeper &Mine)
{int x,y;
for(y=0;y<Mine.coloaneLinii;y++)
for(x=0;x<Mine.coloaneLinii;x++)
{if(Mine.terenMinat[y][x]==-1)
{if(verificarePlasareMina(Mine,y,x+1))
Mine.terenMinat[y][x+1]++;
if(verificarePlasareMina(Mine,y,x-1))
Mine.terenMinat[y][x-1]++;
if(verificarePlasareMina(Mine,y+1,x))
Mine.terenMinat[y+1][x]++;
if(verificarePlasareMina(Mine,y-1,x))
Mine.terenMinat[y-1][x]++;
if(verificarePlasareMina(Mine,y-1,x+1))
Mine.terenMinat[y-1][x+1]++;
if(verificarePlasareMina(Mine,y+1,x+1))
Mine.terenMinat[y+1][x+1]++;
if(verificarePlasareMina(Mine,y-1,x-1))
Mine.terenMinat[y-1][x-1]++;
if(verificarePlasareMina(Mine,y+1,x-1))
Mine.terenMinat[y+1][x-1]++;}
}

}
void initializareInterfata(MineSweeper &Mine)
{
    for(int i=0;i<Mine.coloaneLinii;i++)
for(int j=0;j<Mine.coloaneLinii;j++)
    Mine.interfata[i][j]='N';

}

void creareConsecinteAlegere(MineSweeper &Mine,int y,int x)
{if(Mine.alegeriJucator[y][x]!=2)
{if(Mine.terenMinat[y][x]>0)
    Mine.alegeriJucator[y][x]=1;
if(Mine.terenMinat[y][x]==0 && Mine.alegeriJucator[y][x]==0)
       {Mine.alegeriJucator[y][x]=1;
        if(Mine.terenMinat[y+1][x+1]>=0 && verificareNedepasireMatrice(y+1,x+1,Mine))
          creareConsecinteAlegere(Mine,y+1,x+1);
        if(Mine.terenMinat[y-1][x+1]>=0 && verificareNedepasireMatrice(y-1,x+1,Mine))
          creareConsecinteAlegere(Mine,y-1,x+1);
        if(Mine.terenMinat[y+1][x-1]>=0 && verificareNedepasireMatrice(y+1,x-1,Mine))
          creareConsecinteAlegere(Mine,y+1,x-1);
        if(Mine.terenMinat[y-1][x-1]>=0 && verificareNedepasireMatrice(y-1,x-1,Mine))
          creareConsecinteAlegere(Mine,y-1,x-1);
        if(Mine.terenMinat[y+1][x]>=0 && verificareNedepasireMatrice(y+1,x,Mine))
          creareConsecinteAlegere(Mine,y+1,x);
        if(Mine.terenMinat[y-1][x]>=0 && verificareNedepasireMatrice(y-1,x,Mine))
          creareConsecinteAlegere(Mine,y-1,x);
        if(Mine.terenMinat[y][x+1]>=0 && verificareNedepasireMatrice(y,x+1,Mine))
          creareConsecinteAlegere(Mine,y,x+1);
        if(Mine.terenMinat[y][x-1]>=0 && verificareNedepasireMatrice(y,x-1,Mine))
          creareConsecinteAlegere(Mine,y,x-1);}
          Mine.alegeriJucator[y][x]=1;
          }}

void incarcareInterfata(MineSweeper &Mine)
{for(int i=0;i<Mine.coloaneLinii;i++)
for(int j=0;j<Mine.coloaneLinii;j++)
{if(Mine.alegeriJucator[i][j]==0)
Mine.interfata[i][j]='N';
else
if(Mine.alegeriJucator[i][j]==2)
Mine.interfata[i][j]='F';
else
if(Mine.terenMinat[i][j]==0)
Mine.interfata[i][j]='G';
else
if(Mine.terenMinat[i][j]==-1)
Mine.interfata[i][j]='B';
else
Mine.interfata[i][j]=Mine.terenMinat[i][j]+48;
}}

int updateGrafica(MineSweeper &Mine,sf::RectangleShape rectangle[40][40],sf::Texture texturi[20])
{int i,j,poInaltime=0,poLatime=0,laturapatrat=30;
    for(i=0;i<Mine.coloaneLinii;i++)
    {for(j=0;j<Mine.coloaneLinii;j++)
{rectangle[i][j].setSize(sf::Vector2f(laturapatrat, laturapatrat));
rectangle[i][j].setOutlineColor(sf::Color::Black);
rectangle[i][j].setOutlineThickness(-2);
if(Mine.interfata[j][i]=='N')
 {rectangle[i][j].setFillColor (sf::Color(139,213,123));
}
 else
    if(Mine.interfata[j][i]=='G')
 rectangle[i][j].setFillColor (sf::Color::White);
 else
    if(Mine.interfata[j][i]=='B')
 {rectangle[i][j].setFillColor (sf::Color::White);
     rectangle[i][j].setTexture(&texturi[9]);
rectangle[i][j].setTextureRect(sf::IntRect(0, 0, 250, 250));}
 else
    if(Mine.interfata[j][i]=='F')
{rectangle[i][j].setFillColor (sf::Color::White);
    rectangle[i][j].setTexture(&texturi[0]);
rectangle[i][j].setTextureRect(sf::IntRect(0, 0, 250, 250));
}
 else
    {rectangle[i][j].setFillColor (sf::Color::White);
     rectangle[i][j].setTexture(&texturi[Mine.interfata[j][i]-48]);
rectangle[i][j].setTextureRect(sf::IntRect(0, 0, 250, 250));
 }
rectangle[i][j].setPosition(poInaltime,poLatime);
poLatime=poLatime+laturapatrat;
}
poLatime=0;
poInaltime=poInaltime+laturapatrat;
}
return laturapatrat;
}


void afisareInterfata(MineSweeper &Mine)
{for(int i=-2;i<Mine.coloaneLinii+1;i++)
{if(i>=0 && i<Mine.coloaneLinii)
    cout<<endl<<(i+1)%10<<'|';
    else
        cout<<endl<<"  ";
    for(int j=0;j<Mine.coloaneLinii;j++)
{if(i==-2)
cout<<(j+1)%10<<" ";
else
    if(i==-1)
cout<<"--";
else
    if(i==Mine.coloaneLinii)
    cout<<"--";
else
{if(Mine.interfata[i][j]=='N')
cout<<"  ";
else
{if(Mine.interfata[i][j]=='G')
cout<<"- ";
else
 if(Mine.interfata[i][j]=='B')
cout<<"X ";
else
cout<<Mine.interfata[i][j]<<" ";
}}}
if(i>=0 && i<Mine.coloaneLinii)
cout<<"|";
}}

int verificareVictorie(MineSweeper &Mine)
{int spatiiPosibile=0;
    for(int i=0;i<Mine.coloaneLinii;i++)
for(int j=0;j<Mine.coloaneLinii;j++)
    if(Mine.interfata[i][j]=='N' || Mine.interfata[i][j]=='F')
    spatiiPosibile++;
if(spatiiPosibile==Mine.numarMine)
    return 1;
return 0;

}

void indepartareSteag(MineSweeper &Mine,int y,int x)
{if(Mine.alegeriJucator[y][x]==2)
Mine.alegeriJucator[y][x]=1;

}

void minesweeper(MineSweeper &Mine,sf::RectangleShape rectangle[40][40],sf::Texture texturi[20])
{int marime,minaLovita=0,x,y,actiune,victorie=0, coloana=0,tastaApasata=0,linia=0;
marime=updateGrafica(Mine,rectangle,texturi);
sf::RenderWindow win(sf::VideoMode(marime*Mine.coloaneLinii,marime*Mine.coloaneLinii), "Minesweeper");
afisareInterfata(Mine);
            while (win.isOpen())
    {win.clear();
        for(int i=0;i<Mine.coloaneLinii;i++)
        for(int j=0;j<Mine.coloaneLinii;j++)
        win.draw(rectangle[i][j]);
        win.display();
        sf::Event eveniment;
        while (win.pollEvent(eveniment))
        {
            if (eveniment.type == sf::Event::Closed)
            {win.close();}
            else
                if(minaLovita==0 && victorie==0)
        {if (eveniment.type == sf::Event::KeyPressed)
{if (eveniment.key.code == sf::Keyboard::W)
    {rectangle[coloana][linia].setOutlineColor(sf::Color::Black);
        linia--;
        rectangle[coloana][linia].setOutlineColor(sf::Color::Red);
    }
    if (eveniment.key.code == sf::Keyboard::A)
    {rectangle[coloana][linia].setOutlineColor(sf::Color::Black);
        coloana--;
        rectangle[coloana][linia].setOutlineColor(sf::Color::Red);}
    if (eveniment.key.code == sf::Keyboard::D)
    {rectangle[coloana][linia].setOutlineColor(sf::Color::Black);
    coloana++;
        rectangle[coloana][linia].setOutlineColor(sf::Color::Red);
    }
    if (eveniment.key.code == sf::Keyboard::S)
    {rectangle[coloana][linia].setOutlineColor(sf::Color::Black);
        linia++;
        rectangle[coloana][linia].setOutlineColor(sf::Color::Red);
    }
    if (eveniment.key.code == sf::Keyboard::E)
    {rectangle[coloana][linia].setFillColor (sf::Color::Green);
     tastaApasata=1;}
     if (eveniment.key.code == sf::Keyboard::F)
    {rectangle[coloana][linia].setFillColor (sf::Color::Green);
     tastaApasata=2;}}
     if (eveniment.type == sf::Event::MouseButtonPressed)
{if (eveniment.mouseButton.button == sf::Mouse::Right)
    {coloana=eveniment.mouseButton.x/marime;
    linia=eveniment.mouseButton.y/marime;
    tastaApasata=2;
    }
  if (eveniment.mouseButton.button == sf::Mouse::Left)
    {coloana=eveniment.mouseButton.x/marime;
    linia=eveniment.mouseButton.y/marime ;
    tastaApasata=1;
    }
}}


if(tastaApasata)
{indepartareSteag(Mine,linia,coloana);
if(Mine.terenMinat[linia][coloana]==-1 && tastaApasata==1)
{minaLovita=1;
 cout<<"BOOOOOOOOOOOOOOOM";
 initializareMatrice(Mine.alegeriJucator,Mine.coloaneLinii,1);}
 else
if(tastaApasata==2)
{if(Mine.alegeriJucator[linia][coloana]==0)
  Mine.alegeriJucator[linia][coloana]=2;}
  else
    creareConsecinteAlegere(Mine,linia,coloana);
    incarcareInterfata(Mine);
    if(verificareVictorie(Mine))
{cout<<endl<<"Ai castigat";
victorie=1;
initializareMatrice(Mine.alegeriJucator,Mine.coloaneLinii,1);
}

afisareInterfata(Mine);
updateGrafica(Mine,rectangle,texturi);
tastaApasata=0;
}}
}}



void incarcareTexturi(sf::Texture texturi[20])
{
    texturi[0].loadFromFile("Texturi\\Flag.jpg");
    texturi[1].loadFromFile("Texturi\\1.jpg");
    texturi[2].loadFromFile("Texturi\\2.jpg");
    texturi[3].loadFromFile("Texturi\\3.jpg");
    texturi[4].loadFromFile("Texturi\\4.jpg");
    texturi[5].loadFromFile("Texturi\\5.jpg");
    texturi[6].loadFromFile("Texturi\\6.jpg");
    texturi[7].loadFromFile("Texturi\\7.jpg");
    texturi[8].loadFromFile("Texturi\\8.jpg");
    texturi[9].loadFromFile("Texturi\\Bomba.jpg");
}


int main()
{MineSweeper Mine;
sf::RectangleShape rectangle[40][40];
sf::Texture texturi[20];
srand(time(NULL));
incarcareTexturi(texturi);
startJoc(Mine);
initializareMatrice(Mine.alegeriJucator,Mine.coloaneLinii,0);
initializareMatrice(Mine.terenMinat,Mine.coloaneLinii,0);
initializareInterfata(Mine.interfata,Mine.coloaneLinii,'N');
plantareMine(Mine);
activareMine(Mine);
minesweeper(Mine,rectangle,texturi);
    return 0;
}
