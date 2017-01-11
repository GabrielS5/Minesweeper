
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int joculContinua=1;
struct MineSweeper{
int coloane;
int linii;
int numarMine;
int terenMinat[40][40];
int alegeriJucator[40][40];
char interfata[40][40];
};

void initializareInterfata(char matrice[40][40],int linii,int coloane,char caracter)
{for(int i=0;i<linii;i++)
for(int j=0;j<coloane;j++)
    matrice[i][j]=caracter;

}

void initializareMatrice(int matrice[40][40],int linii,int coloane,int elementAles)
{for(int i=0;i<linii;i++)
for(int j=0;j<coloane;j++)
    matrice[i][j]=elementAles;

}

int contineMina(MineSweeper &Mine,int coloana,int linia)
{if(Mine.terenMinat[linia][coloana]==0)
return 0;
return 1;

}

void plantareMine(MineSweeper &Mine)
{int coordonataX,coordonataY,mine=Mine.numarMine;
while(Mine.numarMine>0)
{coordonataY=rand()%Mine.linii;
coordonataX=rand()%Mine.coloane;
if(!contineMina(Mine,coordonataX,coordonataY))
{Mine.terenMinat[coordonataY][coordonataX]=-1;
Mine.numarMine--;}}
Mine.numarMine=mine;}

bool verificarePlasareMina(MineSweeper &Mine,int linia,int coloana)
{if(linia>=Mine.linii || coloana>=Mine.coloane || coloana<0 || linia<0)
   return 0;
if(Mine.terenMinat[linia][coloana]==-1)
    return 0;
return 1;

}
bool verificareNedepasireMatrice(int linia,int coloana,MineSweeper &Mine)
{if(linia>=Mine.linii || coloana>=Mine.coloane || coloana<0 || linia<0)
return 0;
return 1;
}

void activareMine(MineSweeper &Mine)
{int coloana,linia;
for(linia=0;linia<Mine.linii;linia++)
  for(coloana=0;coloana<Mine.coloane;coloana++)
   {if(Mine.terenMinat[linia][coloana]==-1)
    {if(verificarePlasareMina(Mine,linia,coloana+1))
      Mine.terenMinat[linia][coloana+1]++;
     if(verificarePlasareMina(Mine,linia,coloana-1))
      Mine.terenMinat[linia][coloana-1]++;
     if(verificarePlasareMina(Mine,linia+1,coloana))
      Mine.terenMinat[linia+1][coloana]++;
     if(verificarePlasareMina(Mine,linia-1,coloana))
      Mine.terenMinat[linia-1][coloana]++;
     if(verificarePlasareMina(Mine,linia-1,coloana+1))
      Mine.terenMinat[linia-1][coloana+1]++;
     if(verificarePlasareMina(Mine,linia+1,coloana+1))
      Mine.terenMinat[linia+1][coloana+1]++;
     if(verificarePlasareMina(Mine,linia-1,coloana-1))
      Mine.terenMinat[linia-1][coloana-1]++;
     if(verificarePlasareMina(Mine,linia+1,coloana-1))
      Mine.terenMinat[linia+1][coloana-1]++;}
}}

void creareConsecinteAlegere(MineSweeper &Mine,int linia,int coloana)
{if(Mine.alegeriJucator[linia][coloana]!=2)
{if(Mine.terenMinat[linia][coloana]>0)
    Mine.alegeriJucator[linia][coloana]=1;
if(Mine.terenMinat[linia][coloana]==0 && Mine.alegeriJucator[linia][coloana]==0)
       {Mine.alegeriJucator[linia][coloana]=1;
        if(Mine.terenMinat[linia+1][coloana+1]>=0 && verificareNedepasireMatrice(linia+1,coloana+1,Mine))
          creareConsecinteAlegere(Mine,linia+1,coloana+1);
        if(Mine.terenMinat[linia-1][coloana+1]>=0 && verificareNedepasireMatrice(linia-1,coloana+1,Mine))
          creareConsecinteAlegere(Mine,linia-1,coloana+1);
        if(Mine.terenMinat[linia+1][coloana-1]>=0 && verificareNedepasireMatrice(linia+1,coloana-1,Mine))
          creareConsecinteAlegere(Mine,linia+1,coloana-1);
        if(Mine.terenMinat[linia-1][coloana-1]>=0 && verificareNedepasireMatrice(linia-1,coloana-1,Mine))
          creareConsecinteAlegere(Mine,linia-1,coloana-1);
        if(Mine.terenMinat[linia+1][coloana]>=0 && verificareNedepasireMatrice(linia+1,coloana,Mine))
          creareConsecinteAlegere(Mine,linia+1,coloana);
        if(Mine.terenMinat[linia-1][coloana]>=0 && verificareNedepasireMatrice(linia-1,coloana,Mine))
          creareConsecinteAlegere(Mine,linia-1,coloana);
        if(Mine.terenMinat[linia][coloana+1]>=0 && verificareNedepasireMatrice(linia,coloana+1,Mine))
          creareConsecinteAlegere(Mine,linia,coloana+1);
        if(Mine.terenMinat[linia][coloana-1]>=0 && verificareNedepasireMatrice(linia,coloana-1,Mine))
          creareConsecinteAlegere(Mine,linia,coloana-1);}
          Mine.alegeriJucator[linia][coloana]=1;
          }}

void incarcareInterfata(MineSweeper &Mine)
{for(int linia=0;linia<Mine.linii;linia++)
for(int coloana=0;coloana<Mine.coloane;coloana++)
{if(Mine.alegeriJucator[linia][coloana]==0)
Mine.interfata[linia][coloana]='N';
else
if(Mine.alegeriJucator[linia][coloana]==2)
Mine.interfata[linia][coloana]='F';
else
if(Mine.terenMinat[linia][coloana]==0)
Mine.interfata[linia][coloana]='G';
else
if(Mine.terenMinat[linia][coloana]==-1)
Mine.interfata[linia][coloana]='B';
else
Mine.interfata[linia][coloana]=Mine.terenMinat[linia][coloana]+48;
}}

void initializareCelulaTablou(sf::RectangleShape &celulaTablou,sf::Texture &texturi,int laturapatrat,int poLatime,int poInaltime)
{celulaTablou.setFillColor (sf::Color::White);
 celulaTablou.setTexture(&texturi);
 celulaTablou.setTextureRect(sf::IntRect(0, 0, 250, 250));
 celulaTablou.setSize(sf::Vector2f(laturapatrat, laturapatrat));
 celulaTablou.setOutlineColor(sf::Color::Black);
 celulaTablou.setOutlineThickness(-2);
 celulaTablou.setPosition(poLatime,poInaltime);}

 void plasareTexturaPeCelulaTablou(sf::RectangleShape &celulaTablou,sf::Texture &texturi)
 {celulaTablou.setTexture(&texturi);
  celulaTablou.setTextureRect(sf::IntRect(0, 0, 250, 250));}

int updateGrafica(MineSweeper &Mine,sf::RectangleShape celulaTablou[40][40],sf::Texture texturi[21])
{int linia,coloana,poInaltime=0,poLatime=0,laturapatrat=30;
    for(linia=0;linia<Mine.linii;linia++)
    {for(coloana=0;coloana<Mine.coloane;coloana++)
      {initializareCelulaTablou(celulaTablou[linia][coloana],texturi[19],laturapatrat,poLatime,poInaltime);
       if(Mine.interfata[linia][coloana]=='N')
       celulaTablou[linia][coloana].setFillColor (sf::Color(139,213,123));
       else if(Mine.interfata[linia][coloana]=='B')
          plasareTexturaPeCelulaTablou(celulaTablou[linia][coloana],texturi[9]);
       else if(Mine.interfata[linia][coloana]=='F')
          plasareTexturaPeCelulaTablou(celulaTablou[linia][coloana],texturi[0]);
       else
          plasareTexturaPeCelulaTablou(celulaTablou[linia][coloana],texturi[Mine.interfata[linia][coloana]-48]);
       poLatime=poLatime+laturapatrat;}
    poLatime=0;
    poInaltime=poInaltime+laturapatrat;}
return laturapatrat;
}

int verificareVictorie(MineSweeper &Mine)
{int spatiiPosibile=0;
for(int linie=0;linie<Mine.linii;linie++)
 for(int coloana=0;coloana<Mine.coloane;coloana++)
    if(Mine.interfata[linie][coloana]=='N' || Mine.interfata[linie][coloana]=='F')
      spatiiPosibile++;
    if(spatiiPosibile==Mine.numarMine)
      return 1;
return 0;}

int indepartareSteag(MineSweeper &Mine,int linia,int coloana,int tastaApasata)
{if(Mine.alegeriJucator[linia][coloana]==2)
{Mine.alegeriJucator[linia][coloana]=2-tastaApasata;
return 1;}
return 0;}

void afisareVictorie(MineSweeper Mine,sf::RectangleShape &celulaTablou,sf::Texture texturi[21],int laturaPatrat)
{celulaTablou.setSize(sf::Vector2f(150, 75));
celulaTablou.setFillColor (sf::Color::White);
celulaTablou.setTexture(&texturi[17]);
celulaTablou.setTextureRect(sf::IntRect(0, 0, 500, 250));
celulaTablou.setPosition((laturaPatrat*Mine.coloane)/2-75,(laturaPatrat*Mine.linii)/2-37);
celulaTablou.setOutlineColor(sf::Color::Red);
celulaTablou.setOutlineThickness(-2);}

void afisareInfrangere(MineSweeper Mine,sf::RectangleShape &celulaTablou,sf::Texture texturi[21],int laturaPatrat)
{celulaTablou.setSize(sf::Vector2f(150, 75));
celulaTablou.setFillColor (sf::Color::White);
celulaTablou.setTexture(&texturi[18]);
celulaTablou.setTextureRect(sf::IntRect(0, 0, 500, 250));
celulaTablou.setPosition((laturaPatrat*Mine.coloane)/2-75,(laturaPatrat*Mine.linii)/2-37);
celulaTablou.setOutlineColor(sf::Color::Red);
celulaTablou.setOutlineThickness(-2);}

void interactiuneCuJucatorulTastatura(int &linia,int &coloana,sf::RectangleShape celulaTablou[40][40],sf::Event eveniment,int &tastaApasata)
{ if (eveniment.type == sf::Event::KeyPressed)
       {if (eveniment.key.code == sf::Keyboard::Left)
          {celulaTablou[linia][coloana].setOutlineColor(sf::Color::Black);
           coloana--;
           celulaTablou[linia][coloana].setOutlineColor(sf::Color::Red);}
        if (eveniment.key.code == sf::Keyboard::Up)
          {celulaTablou[linia][coloana].setOutlineColor(sf::Color::Black);
           linia--;
           celulaTablou[linia][coloana].setOutlineColor(sf::Color::Red);}
        if (eveniment.key.code == sf::Keyboard::Down)
          {celulaTablou[linia][coloana].setOutlineColor(sf::Color::Black);
           linia++;
           celulaTablou[linia][coloana].setOutlineColor(sf::Color::Red);}
        if (eveniment.key.code == sf::Keyboard::Right)
          {celulaTablou[linia][coloana].setOutlineColor(sf::Color::Black);
           coloana++;
           celulaTablou[linia][coloana].setOutlineColor(sf::Color::Red);}
        if (eveniment.key.code == sf::Keyboard::Return)
          {tastaApasata=1;}
        if (eveniment.key.code == sf::Keyboard::F || eveniment.key.code == sf::Keyboard::RShift)
          {tastaApasata=2;}}
        }
int interactiuneCuJucatorulMouse(int &coordonataEcranX,int &coordonataEcranY,sf::Event eveniment,int &tastaApasata)
{if (eveniment.type == sf::Event::MouseButtonPressed)
        {if (eveniment.mouseButton.button == sf::Mouse::Right)
          {coordonataEcranX=eveniment.mouseButton.x;
           coordonataEcranY=eveniment.mouseButton.y;
           tastaApasata=2;}
         if (eveniment.mouseButton.button == sf::Mouse::Left)
          {coordonataEcranX=eveniment.mouseButton.x;
           coordonataEcranY=eveniment.mouseButton.y;
           tastaApasata=1;}
           return 1;}
           return 0;}


void minesweeper(MineSweeper &Mine,sf::RectangleShape celulaTablou[40][40],sf::Texture texturi[21])
{int laturaPatrat,minaLovita=0,coordonataEcranX=0,coordonataEcranY=0,victorie=0, coloana=0,tastaApasata=0,linia=0,steagIndepartat=0;
laturaPatrat=updateGrafica(Mine,celulaTablou,texturi);

sf::RenderWindow win(sf::VideoMode(laturaPatrat*Mine.coloane,laturaPatrat*Mine.linii), "Minesweeper");
win.setFramerateLimit(60);
while (win.isOpen())
{win.clear();
  for(int i=0;i<Mine.linii;i++)
   for(int j=0;j<Mine.coloane;j++)
    win.draw(celulaTablou[i][j]);
  if(victorie || minaLovita)
   win.draw(celulaTablou[39][39]);
  win.display();
  sf::Event eveniment;
while (win.pollEvent(eveniment))
  {if (eveniment.type == sf::Event::Closed)
        win.close();
        interactiuneCuJucatorulTastatura(linia,coloana,celulaTablou,eveniment,tastaApasata);
        if(interactiuneCuJucatorulMouse(coordonataEcranX,coordonataEcranY,eveniment,tastaApasata))
        {coloana=coordonataEcranX/laturaPatrat;
        linia=coordonataEcranY/laturaPatrat;}
        }
    if(tastaApasata)
      { steagIndepartat=indepartareSteag(Mine,linia,coloana,tastaApasata);
       if(Mine.terenMinat[linia][coloana]==-1 && tastaApasata==1)
         {minaLovita=1;
          afisareInfrangere(Mine,celulaTablou[39][39],texturi,laturaPatrat);
          initializareMatrice(Mine.alegeriJucator,Mine.linii,Mine.coloane,1);}
       else if(tastaApasata==2 && steagIndepartat==0)
          {if(Mine.alegeriJucator[linia][coloana]==0)
           Mine.alegeriJucator[linia][coloana]=2;}
       else if(tastaApasata==1)
           creareConsecinteAlegere(Mine,linia,coloana);
       incarcareInterfata(Mine);
       if(verificareVictorie(Mine))
           {victorie=1;
            afisareVictorie(Mine,celulaTablou[39][39],texturi,laturaPatrat);
            initializareMatrice(Mine.alegeriJucator,Mine.linii,Mine.coloane,1);}

       updateGrafica(Mine,celulaTablou,texturi);
       tastaApasata=0;}}
}

void administrareValoriColoaneLiniiMine(MineSweeper &Mine,int mine, int coloane,int linii)
{Mine.numarMine=mine;
Mine.linii=linii;
Mine.coloane=coloane;}

void initializareCelulaMeniu(sf::RectangleShape &celuleMeniu,sf::Texture &texturi,int poLatime,int poInaltime)
{celuleMeniu.setSize(sf::Vector2f(100, 50));
celuleMeniu.setFillColor (sf::Color::White);
celuleMeniu.setTexture(&texturi);
celuleMeniu.setTextureRect(sf::IntRect(0, 0, 500, 250));
celuleMeniu.setPosition(poLatime,poInaltime);}

void interactiuneCuJucatorulTastaturaMeniu(int &numarIntrodus,sf::Event eveniment,int folosireTastatura,int &tastaApasata,int &meniuUrmator)
{if(folosireTastatura)
{if (eveniment.type == sf::Event::KeyPressed)
   {if (eveniment.key.code == sf::Keyboard::Numpad1 || eveniment.key.code == sf::Keyboard::Num1)
    numarIntrodus=1;
    if (eveniment.key.code == sf::Keyboard::Numpad2 || eveniment.key.code == sf::Keyboard::Num2)
    numarIntrodus=2;
    if (eveniment.key.code == sf::Keyboard::Numpad3 || eveniment.key.code == sf::Keyboard::Num3)
    numarIntrodus=3;
    if (eveniment.key.code == sf::Keyboard::Numpad4 || eveniment.key.code == sf::Keyboard::Num4)
    numarIntrodus=4;
    if (eveniment.key.code == sf::Keyboard::Numpad5 || eveniment.key.code == sf::Keyboard::Num5)
    numarIntrodus=5;
    if (eveniment.key.code == sf::Keyboard::Numpad6 || eveniment.key.code == sf::Keyboard::Num6)
    numarIntrodus=6;
    if (eveniment.key.code == sf::Keyboard::Numpad7 || eveniment.key.code == sf::Keyboard::Num7)
    numarIntrodus=7;
    if (eveniment.key.code == sf::Keyboard::Numpad8 || eveniment.key.code == sf::Keyboard::Num8)
    numarIntrodus=8;
    if (eveniment.key.code == sf::Keyboard::Numpad9 || eveniment.key.code == sf::Keyboard::Num9)
    numarIntrodus=9;
    if (eveniment.key.code == sf::Keyboard::Numpad0 || eveniment.key.code == sf::Keyboard::Num0)
    numarIntrodus=0;
    if (eveniment.key.code == sf::Keyboard::Return)
    meniuUrmator++;

     }}}

void meniuJocSFML(MineSweeper &Mine,sf::Texture texturi[21])
{int latime=650,meniuUrmator=0,numarIntrodus=-1,inaltime=300,nrPatrate=4,tastaApasata=0,coloana,linia,terminat=0,folosireTastatura=0;
  int coordonataEcranX=0,coordonataEcranY=0;
    sf::RenderWindow win(sf::VideoMode(latime, inaltime), "Meniu");
sf::RectangleShape celuleMeniu[5];
for(int i=0;i<4;i++)
initializareCelulaMeniu(celuleMeniu[i],texturi[i+10],50+150*i,100);
while (win.isOpen())
{win.clear();
if(terminat || meniuUrmator>2)
    win.close();
for(int i=0;i<nrPatrate;i++)
win.draw(celuleMeniu[i]);
win.display();
sf::Event eveniment;
    while (win.pollEvent(eveniment))
    {if (eveniment.type == sf::Event::Closed )
       {win.close();
       joculContinua=0;}
      interactiuneCuJucatorulTastaturaMeniu(numarIntrodus,eveniment,folosireTastatura,tastaApasata,meniuUrmator);
     interactiuneCuJucatorulMouse(coloana,linia,eveniment,tastaApasata);
        }
    if(meniuUrmator>=0 && folosireTastatura)
      initializareCelulaMeniu(celuleMeniu[0],texturi[14+meniuUrmator],50,100);
    if(numarIntrodus>=0)
      {if(meniuUrmator==0)
        { Mine.coloane=Mine.coloane*10+numarIntrodus;
         numarIntrodus=-1;}
        else if(meniuUrmator==1)
        {Mine.linii=Mine.linii*10+numarIntrodus;
         numarIntrodus=-1;}
         else if(meniuUrmator==2)
        {Mine.numarMine=Mine.numarMine*10+numarIntrodus;
         numarIntrodus=-1;}}
    if(tastaApasata)
    {  if(linia>100 && linia<150)
         {if(coloana>50 && coloana<150)
           {administrareValoriColoaneLiniiMine(Mine,10,9,9);
            terminat=1;}
          if(coloana>200 && coloana<300)
            {administrareValoriColoaneLiniiMine(Mine,40,16,16);
             terminat=1;}
          if(coloana>350 && coloana<450)
             {administrareValoriColoaneLiniiMine(Mine,99,30,16);
              terminat=1;}
          if(coloana>500 && coloana<600)
             {nrPatrate=1;
             initializareCelulaMeniu(celuleMeniu[0],texturi[14],50,100);
             folosireTastatura=1;}}
        tastaApasata=0;
    }}}


void incarcareTexturi(sf::Texture texturi[21])
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
    texturi[14].loadFromFile("Texturi\\Col.jpg");
    texturi[15].loadFromFile("Texturi\\Linii.jpg");
    texturi[16].loadFromFile("Texturi\\NrMine.jpg");
    texturi[17].loadFromFile("Texturi\\Victorie.jpg");
    texturi[18].loadFromFile("Texturi\\Infrangere.jpg");
    texturi[19].loadFromFile("Texturi\\alb.jpg");
}


int main()
{
    MineSweeper Mine;
sf::RectangleShape celulaTablou[40][40];
sf::Texture texturi[21];
srand(time(NULL));
incarcareTexturi(texturi);
while(joculContinua)
{meniuJocSFML(Mine,texturi);
initializareMatrice(Mine.alegeriJucator,Mine.linii,Mine.coloane,0);
initializareMatrice(Mine.terenMinat,Mine.linii,Mine.coloane,0);
initializareInterfata(Mine.interfata,Mine.linii,Mine.coloane,'N');
plantareMine(Mine);
activareMine(Mine);
if(joculContinua)
minesweeper(Mine,celulaTablou,texturi);}
    return 0;
}
