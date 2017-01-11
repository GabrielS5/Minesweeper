
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
            while (win.isOpen())
    {win.clear();
        for(int i=0;i<Mine.coloaneLinii;i++)
        for(int j=0;j<Mine.coloaneLinii;j++)
        win.draw(rectangle[i][j]);
        if(victorie || minaLovita)
            win.draw(rectangle[39][39]);
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
rectangle[39][39].setSize(sf::Vector2f(150, 75));
rectangle[39][39].setFillColor (sf::Color::White);
     rectangle[39][39].setTexture(&texturi[17]);
rectangle[39][39].setTextureRect(sf::IntRect(0, 0, 500, 250));
rectangle[39][39].setPosition(marime*Mine.coloaneLinii/2-75,marime*Mine.coloaneLinii/2-37);
rectangle[39][39].setOutlineColor(sf::Color::Red);
rectangle[39][39].setOutlineThickness(-2);
 initializareMatrice(Mine.alegeriJucator,Mine.coloaneLinii,1);}
 else
if(tastaApasata==2)
{if(Mine.alegeriJucator[linia][coloana]==0)
  Mine.alegeriJucator[linia][coloana]=2;}
  else
    creareConsecinteAlegere(Mine,linia,coloana);
    incarcareInterfata(Mine);
    if(verificareVictorie(Mine))
{victorie=1;
rectangle[39][39].setSize(sf::Vector2f(150, 75));
rectangle[39][39].setFillColor (sf::Color::White);
     rectangle[39][39].setTexture(&texturi[16]);
rectangle[39][39].setTextureRect(sf::IntRect(0, 0, 500, 250));
rectangle[39][39].setPosition(marime*Mine.coloaneLinii/2-75,marime*Mine.coloaneLinii/2-37);
rectangle[39][39].setOutlineColor(sf::Color::Red);
rectangle[39][39].setOutlineThickness(-2);
initializareMatrice(Mine.alegeriJucator,Mine.coloaneLinii,1);
}

updateGrafica(Mine,rectangle,texturi);
tastaApasata=0;
}}
}}

void meniuJocSFML(MineSweeper &Mine,sf::Texture texturi[20])
{int latime=650,urmator=0,numar=-1,inaltime=300,patrate=4,tastaApasata=0,coloana,linia,terminat=0,tastatura=0;
   Mine.coloaneLinii=0;
   Mine.numarMine=0;
    sf::RenderWindow win(sf::VideoMode(latime, inaltime), "Meniu");
sf::RectangleShape rectangle[5];
for(int i=0;i<4;i++)
{rectangle[i].setSize(sf::Vector2f(100, 50));
rectangle[i].setFillColor (sf::Color::White);
 rectangle[i].setTexture(&texturi[i+10]);
rectangle[i].setTextureRect(sf::IntRect(0, 0, 500, 250));
rectangle[i].setPosition(50+150*i,100);}

            while (win.isOpen())
    {win.clear();
    for(int i=0;i<patrate;i++)
        win.draw(rectangle[i]);
        win.display();
        sf::Event eveniment;
        if(terminat || urmator>1)
            win.close();
        while (win.pollEvent(eveniment))
        {
            if (eveniment.type == sf::Event::Closed )
            {win.close();}
            if(tastatura)
            {if (eveniment.type == sf::Event::KeyPressed)
{   if (eveniment.key.code == sf::Keyboard::Numpad1)
    numar=1;
    if (eveniment.key.code == sf::Keyboard::Numpad2)
    numar=2;
    if (eveniment.key.code == sf::Keyboard::Numpad3)
    numar=3;
    if (eveniment.key.code == sf::Keyboard::Numpad4)
    numar=4;
    if (eveniment.key.code == sf::Keyboard::Numpad5)
    numar=5;
    if (eveniment.key.code == sf::Keyboard::Numpad6)
    numar=6;
    if (eveniment.key.code == sf::Keyboard::Numpad7)
    numar=7;
    if (eveniment.key.code == sf::Keyboard::Numpad8)
    numar=8;
    if (eveniment.key.code == sf::Keyboard::Numpad9)
    numar=9;
    if (eveniment.key.code == sf::Keyboard::Numpad0)
    numar=0;
    if (eveniment.key.code == sf::Keyboard::E)
    {urmator++;
    rectangle[0].setFillColor (sf::Color::White);
 rectangle[0].setTexture(&texturi[15]);
rectangle[0].setTextureRect(sf::IntRect(0, 0, 500, 250));}}}
           if (eveniment.type == sf::Event::MouseButtonPressed && tastatura==0)
{if (eveniment.mouseButton.button == sf::Mouse::Left)
    {coloana=eveniment.mouseButton.x;
    linia=eveniment.mouseButton.y;
    tastaApasata=1;
    }}}
    if(numar>-1)
    {if(urmator==0)
    {Mine.coloaneLinii=Mine.coloaneLinii*10+numar;
     numar=-1;}
     else if(urmator==1)
     {Mine.numarMine=Mine.numarMine*10+numar;
     numar=-1;
     }}
    if(tastaApasata)
    {
    if(linia>100 && linia<150)
    {if(coloana>50 && coloana<150)
    {Mine.numarMine=10;
Mine.coloaneLinii=9;
        terminat=1;
    }
    if(coloana>200 && coloana<300)
    {Mine.numarMine=40;
Mine.coloaneLinii=16;
        terminat=1;
    }
        if(coloana>350 && coloana<450)
        {Mine.numarMine=99;
Mine.coloaneLinii=22;
            terminat=1;
        }
        if(coloana>500 && coloana<600)
        {patrate=1;
        rectangle[0].setFillColor (sf::Color::White);
 rectangle[0].setTexture(&texturi[14]);
rectangle[0].setTextureRect(sf::IntRect(0, 0, 500, 250));
tastatura=1;


        }   }
        tastaApasata=0;
    }
    }


}


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
    texturi[10].loadFromFile("Texturi\\Clasic.jpg");
    texturi[11].loadFromFile("Texturi\\Mediu.jpg");
    texturi[12].loadFromFile("Texturi\\Expert.jpg");
    texturi[13].loadFromFile("Texturi\\Custom.jpg");
    texturi[14].loadFromFile("Texturi\\ColLinii.jpg");
    texturi[15].loadFromFile("Texturi\\NrMine.jpg");
    texturi[16].loadFromFile("Texturi\\Victorie.jpg");
    texturi[17].loadFromFile("Texturi\\Infrangere.jpg");
}


int main()
{MineSweeper Mine;
sf::RectangleShape rectangle[40][40];
sf::Texture texturi[20];
srand(time(NULL));
incarcareTexturi(texturi);
meniuJocSFML(Mine,texturi);
initializareMatrice(Mine.alegeriJucator,Mine.coloaneLinii,0);
initializareMatrice(Mine.terenMinat,Mine.coloaneLinii,0);
initializareInterfata(Mine.interfata,Mine.coloaneLinii,'N');
plantareMine(Mine);
activareMine(Mine);
minesweeper(Mine,rectangle,texturi);
    return 0;
}
