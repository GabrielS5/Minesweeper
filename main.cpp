#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void initializareMatrice(int matrice[40][40],int coloaneLinii)
{for(int i=0;i<coloaneLinii;i++)
for(int j=0;j<coloaneLinii;j++)
    matrice[i][j]=0;

}
void afisare(int matrice[40][40],int coloaneLinii)
{cout<<endl;
    for(int i=0;i<coloaneLinii;i++)
{for(int j=0;j<coloaneLinii;j++)
    cout<<matrice[i][j]<<" ";
    cout<<endl;}

}

int contineMina(int matrice[40][40],int x,int y)
{if(matrice[y][x]==0)
return 0;
return 1;

}

void plantareMine(int terenMinat[40][40],int numarMine,int coloaneLinii)
{int coordonataX,coordonataY;
while(numarMine>0)
{coordonataX=rand()%coloaneLinii;
coordonataY=rand()%coloaneLinii;
if(!contineMina(terenMinat,coordonataX,coordonataY))
{terenMinat[coordonataY][coordonataX]=-1;
numarMine--;}}}

bool verificarePlasareMina(int terenMinat[40][40],int y,int x,int coloaneLinii)
{if(x>=coloaneLinii || y>=coloaneLinii || x<0 || y<0)
return 0;
if(terenMinat[y][x]==-1)
    return 0;
return 1;

}
bool verificareNedepasireMatrice(int y,int x,int coloaneLinii)
{if(x>=coloaneLinii || y>=coloaneLinii || x<0 || y<0)
return 0;
return 1;
}

void activareMine(int terenMinat[40][40],int coloaneLinii)
{int x,y;
for(y=0;y<coloaneLinii;y++)
for(x=0;x<coloaneLinii;x++)
{if(terenMinat[y][x]==-1)
{if(verificarePlasareMina(terenMinat,y,x+1,coloaneLinii))
terenMinat[y][x+1]++;
if(verificarePlasareMina(terenMinat,y,x-1,coloaneLinii))
terenMinat[y][x-1]++;
if(verificarePlasareMina(terenMinat,y+1,x,coloaneLinii))
terenMinat[y+1][x]++;
if(verificarePlasareMina(terenMinat,y-1,x,coloaneLinii))
terenMinat[y-1][x]++;
if(verificarePlasareMina(terenMinat,y-1,x+1,coloaneLinii))
terenMinat[y-1][x+1]++;
if(verificarePlasareMina(terenMinat,y+1,x+1,coloaneLinii))
terenMinat[y+1][x+1]++;
if(verificarePlasareMina(terenMinat,y-1,x-1,coloaneLinii))
terenMinat[y-1][x-1]++;
if(verificarePlasareMina(terenMinat,y+1,x-1,coloaneLinii))
terenMinat[y+1][x-1]++;}
}

}
void initializareInterfata(char interfata[40][40],int coloaneLinii)
{
    for(int i=0;i<coloaneLinii;i++)
for(int j=0;j<coloaneLinii;j++)
    interfata[i][j]='N';

}

void creareConsecinteAlegere(int terenMinat[40][40],int alegeriJucator[40][40],int y,int x,int coloaneLinii)
{if(terenMinat[y][x]>0)
    alegeriJucator[y][x]=1;
if(terenMinat[y][x]==0 && alegeriJucator[y][x]==0)
       {alegeriJucator[y][x]=1;
        if(terenMinat[y+1][x+1]>=0 && verificareNedepasireMatrice(y+1,x+1,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y+1,x+1,coloaneLinii);
        if(terenMinat[y-1][x+1]>=0 && verificareNedepasireMatrice(y-1,x+1,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y-1,x+1,coloaneLinii);
        if(terenMinat[y+1][x-1]>=0 && verificareNedepasireMatrice(y+1,x-1,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y+1,x-1,coloaneLinii);
        if(terenMinat[y-1][x-1]>=0 && verificareNedepasireMatrice(y-1,x-1,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y-1,x-1,coloaneLinii);
        if(terenMinat[y+1][x]>=0 && verificareNedepasireMatrice(y+1,x,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y+1,x,coloaneLinii);
        if(terenMinat[y-1][x]>=0 && verificareNedepasireMatrice(y-1,x,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y-1,x,coloaneLinii);
        if(terenMinat[y][x+1]>=0 && verificareNedepasireMatrice(y,x+1,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y,x+1,coloaneLinii);
        if(terenMinat[y][x-1]>=0 && verificareNedepasireMatrice(y,x-1,coloaneLinii))
          creareConsecinteAlegere(terenMinat,alegeriJucator,y,x-1,coloaneLinii);}}

void incarcareInterfata(int terenMinat[40][40],int alegeriJucator[40][40],char interfata[40][40],int coloaneLinii)
{for(int i=0;i<coloaneLinii;i++)
for(int j=0;j<coloaneLinii;j++)
{if(alegeriJucator[i][j]==0)
interfata[i][j]='N';
else
if(alegeriJucator[i][j]==2)
interfata[i][j]='F';
else
if(terenMinat[i][j]==0)
interfata[i][j]='G';
else
interfata[i][j]=terenMinat[i][j]+48;
}}

void afisareInterfata(char interfata[40][40],int coloaneLinii)
{for(int i=-2;i<coloaneLinii+1;i++)
{if(i>=0 && i<coloaneLinii)
    cout<<endl<<i+1<<'|';
    else
        cout<<endl<<"  ";
    for(int j=0;j<coloaneLinii;j++)
{if(i==-2)
cout<<j+1<<" ";
else
    if(i==-1)
cout<<"--";
else
    if(i==coloaneLinii)
    cout<<"--";
else
{if(interfata[i][j]=='N')
cout<<"  ";
else
{if(interfata[i][j]=='G')
cout<<"- ";
else
cout<<interfata[i][j]<<" ";
}}}
if(i>=0 && i<coloaneLinii)
cout<<"|";
}}


void minesweeper(int terenMinat[40][40],int alegeriJucator[40][40],char interfata[40][40],int coloaneLinii)
{int minaLovita=0,x,y,actiune;
afisareInterfata( interfata, coloaneLinii);
while(minaLovita==0)
{cout<<endl<<"Alege Coloana ";
cin>>y;
cout<<endl<<"Alege Linia ";
cin>>x;
cout<<endl<<"Alege actiune: 1-Descopera  2-Pune Flag ";
cin>>actiune;
if(terenMinat[y-1][x-1]==-1)
{minaLovita=1;
 cout<<"BOOOOOOOOOOOOOOOM";
}
else
{if(actiune==1)
    creareConsecinteAlegere(terenMinat,alegeriJucator,y-1,x-1,coloaneLinii);
  if(actiune==2)
    if(alegeriJucator[y][x]==0)
  alegeriJucator[y][x]=2;

incarcareInterfata( terenMinat, alegeriJucator,interfata, coloaneLinii);

}
afisareInterfata(interfata,coloaneLinii);
}

}


int main()
{srand(time(NULL));
int terenMinat[40][40],alegeriJucator[40][40];
char interfata[40][40];
initializareMatrice(alegeriJucator,9);
initializareMatrice(terenMinat,9);
plantareMine(terenMinat,10,9);
activareMine(terenMinat,9);
minesweeper(terenMinat, alegeriJucator,interfata, 9);




}
