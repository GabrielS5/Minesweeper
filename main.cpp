
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int joculContinua=1;
struct MineSweeper{
int coloane;
int linii;
int numarMine;
int terenMinat[40][40];
int alegeriJucator[40][40];
char interfata[40][40];
char numeJucator[25];
float scorJucator;
int tipDeJoc;
};
struct scor{
int numere[40];
char nume[40][25];
};

void afisareScoruri(scor scoruri,int optiune)
{for(int i=0;i<30;i++)
cout<<endl;
    for(int i=optiune*10;i<optiune*10+10;i++)
           if(scoruri.numere[i]>0)
           {if(i<optiune*10+9)
            cout<<i%10+1<<" -  Scor "<<scoruri.numere[i]<<" - "<<scoruri.nume[i]<<endl;
           else
            cout<<i%10+1<<"-  Scor "<<scoruri.numere[i]<<" - "<<scoruri.nume[i]<<endl;}}

void sortare(int v[11],char w[11][25])
{int numarAux,minim;
char sirAux[25];
for(int i=0;i<11;i++)
{for(int j=i;j<11;j++)
{if((v[i]>v[j] && v[j]>0) || v[i]==0)
  {numarAux=v[i];
  v[i]=v[j];
  v[j]=numarAux;
  strcpy(sirAux,w[i]);
  strcpy(w[i],w[j]);
  strcpy(w[j],sirAux);}}}}

void sortareScor(scor &scoruri,MineSweeper Mine,int setscor)
    {int v[11],k=0;
    char w[11][25];
    v[10]=Mine.scorJucator;
    strcpy(w[10],Mine.numeJucator);
    for(int i=setscor*10;i<setscor*10+10;i++)
    {v[k]=scoruri.numere[i];
    strcpy(w[k],scoruri.nume[i]);
    k++;}
    sortare(v,w);
    k=0;
    for(int i=setscor*10;i<setscor*10+10;i++)
    {scoruri.numere[i]=v[k];
    strcpy(scoruri.nume[i],w[k]);
    k++;}
    }


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
      {initializareCelulaTablou(celulaTablou[linia][coloana],texturi[20],laturapatrat,poLatime,poInaltime);
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
celulaTablou.setTexture(&texturi[18]);
celulaTablou.setTextureRect(sf::IntRect(0, 0, 500, 250));
celulaTablou.setPosition((laturaPatrat*Mine.coloane)/2-75,(laturaPatrat*Mine.linii)/2-37);
celulaTablou.setOutlineColor(sf::Color::Red);
celulaTablou.setOutlineThickness(-2);}

void afisareInfrangere(MineSweeper Mine,sf::RectangleShape &celulaTablou,sf::Texture texturi[21],int laturaPatrat)
{celulaTablou.setSize(sf::Vector2f(150, 75));
celulaTablou.setFillColor (sf::Color::White);
celulaTablou.setTexture(&texturi[19]);
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



void minesweeper(MineSweeper &Mine,sf::RectangleShape celulaTablou[40][40],sf::Texture texturi[21],scor &scoruri)
{int laturaPatrat,minaLovita=0,coordonataEcranX=0,coordonataEcranY=0,victorie=0, coloana=0,tastaApasata=0,linia=0,steagIndepartat=0;
int secunda=0;
laturaPatrat=updateGrafica(Mine,celulaTablou,texturi);

sf::RenderWindow win(sf::VideoMode(laturaPatrat*Mine.coloane,laturaPatrat*Mine.linii), "Minesweeper");
win.setFramerateLimit(60);
while (win.isOpen())
{win.clear();
if(victorie==0)
secunda++;
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
       if(victorie==1)
      {Mine.scorJucator=secunda/60;
      if(Mine.tipDeJoc==3)
        Mine.scorJucator=((Mine.linii*Mine.coloane)/Mine.numarMine/2)*Mine.scorJucator;
      cout<<endl<<endl<<"Scorul tau  "<<Mine.scorJucator;
      sortareScor(scoruri,Mine,Mine.tipDeJoc);}
}

void administrareValoriColoaneLiniiMine(MineSweeper &Mine,int mine, int coloane,int linii,int tipJoc)
{Mine.numarMine=mine;
Mine.linii=linii;
Mine.coloane=coloane;
Mine.tipDeJoc=tipJoc;}

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

void meniuJocSFML(MineSweeper &Mine,sf::Texture texturi[21],scor scoruri)
{int latime=650,meniuUrmator=0,numarIntrodus=-1,inaltime=300,nrPatrate=5,tastaApasata=0,coloana,linia,terminat=0,folosireTastatura=0;
  int coordonataEcranX=0,coordonataEcranY=0,optiuneScor=0;
    sf::RenderWindow win(sf::VideoMode(latime, inaltime), "Meniu");
sf::RectangleShape celuleMeniu[5];
for(int i=0;i<5;i++)
if(i==4)
initializareCelulaMeniu(celuleMeniu[i],texturi[i+10],50,200);
else
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
      initializareCelulaMeniu(celuleMeniu[0],texturi[15+meniuUrmator],50,100);
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
           if(optiuneScor)
           {afisareScoruri(scoruri,0);
            nrPatrate=5;}
           else
            {administrareValoriColoaneLiniiMine(Mine,10,9,9,0);
            terminat=1;}
          if(coloana>200 && coloana<300)
            if(optiuneScor)
           {afisareScoruri(scoruri,1);
            nrPatrate=5;}
           else
             {administrareValoriColoaneLiniiMine(Mine,40,16,16,1);
             terminat=1;}
          if(coloana>350 && coloana<450)
             if(optiuneScor)
           {afisareScoruri(scoruri,2);
            nrPatrate=5;}
           else
              {administrareValoriColoaneLiniiMine(Mine,99,30,16,2);
              terminat=1;}
          if(coloana>500 && coloana<600)
             if(optiuneScor)
           {afisareScoruri(scoruri,3);
            nrPatrate=5;}
           else
             {Mine.tipDeJoc=3;
             nrPatrate=1;
             initializareCelulaMeniu(celuleMeniu[0],texturi[15],50,100);
             folosireTastatura=1;}
        optiuneScor=0;
        }
        if(linia>200 && linia<250 && coloana>50 && coloana<150)
        {optiuneScor=1;
        nrPatrate=4;}
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
    texturi[14].loadFromFile("Texturi\\Scoruri.jpg");
    texturi[15].loadFromFile("Texturi\\Col.jpg");
    texturi[16].loadFromFile("Texturi\\Linii.jpg");
    texturi[17].loadFromFile("Texturi\\NrMine.jpg");
    texturi[18].loadFromFile("Texturi\\Victorie.jpg");
    texturi[19].loadFromFile("Texturi\\Infrangere.jpg");
    texturi[20].loadFromFile("Texturi\\alb.jpg");
}

int citireDinFisier(scor &scoruri)
{int i=0,j=0,k=0;
string linie;
ifstream iesire("scoruri.txt");
for(int i=0;i<40;i++)
        scoruri.numere[i]=0;
while ( getline (iesire,linie) )
    {i=0;
      while(linie[i]>=48 && linie[i]<=57)
        {scoruri.numere[j]=scoruri.numere[j]*10+linie[i]-48;
        i++;}
        i++;
        k=0;
      while(linie[i]>=64 && linie[i]<=122 || linie[i]==32)
      {scoruri.nume[j][k]=linie[i];
        i++;
        k++;}
        scoruri.nume[j][k]='\0';
        j++;
    }
    iesire.close();
    return j;}

int main()
{scor scoruri;

citireDinFisier(scoruri);
MineSweeper Mine;
Mine.scorJucator=0;
cin.get(Mine.numeJucator,24);
sf::RectangleShape celulaTablou[40][40];
sf::Texture texturi[21];
srand(time(NULL));
incarcareTexturi(texturi);

while(joculContinua)
 {Mine.linii=Mine.coloane=Mine.numarMine=0;
 meniuJocSFML(Mine,texturi,scoruri);
 initializareMatrice(Mine.alegeriJucator,Mine.linii,Mine.coloane,0);
 initializareMatrice(Mine.terenMinat,Mine.linii,Mine.coloane,0);
 initializareInterfata(Mine.interfata,Mine.linii,Mine.coloane,'N');
 plantareMine(Mine);
 activareMine(Mine);
 if(joculContinua)
  minesweeper(Mine,celulaTablou,texturi,scoruri);}
ofstream intrare("scoruri.txt");
for(int i=0;i<40;i++)
{intrare<<scoruri.numere[i]<<" ";
if(scoruri.numere[i]==0)
intrare<<endl;
else
intrare<<scoruri.nume[i]<<endl;}
intrare.close();

    return 0;
}
