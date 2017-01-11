#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void initializareMatrice(int matrice[20][20],int coloaneLinii)
{for(int i=0;i<coloaneLinii;i++)
for(int j=0;j<coloaneLinii;j++)
    matrice[i][j]=0;

}
void afisare(int matrice[20][20],int coloaneLinii)
{cout<<endl;
    for(int i=0;i<coloaneLinii;i++)
{for(int j=0;j<coloaneLinii;j++)
    cout<<matrice[i][j]<<" ";
    cout<<endl;}

}

int contineMina(int matrice[20][20],int x,int y)
{if(matrice[y][x]==0)
return 0;
return 1;

}

void plantareMine(int terenMinat[20][20],int numarMine,int coloaneLinii)
{int coordonataX,coordonataY;
while(numarMine>0)
{coordonataX=rand()%coloaneLinii;
coordonataY=rand()%coloaneLinii;
if(!contineMina(terenMinat,coordonataX,coordonataY))
{terenMinat[coordonataY][coordonataX]=-1;
numarMine--;}}}

bool verificarePlasareMina(int terenMinat[20][20],int y,int x,int coloaneLinii)
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

void activareMine(int terenMinat[20][20],int coloaneLinii)
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
void initializareInterfata(char interfata[20][20],int coloaneLinii)
{
    for(int i=0;i<coloaneLinii;i++)
for(int j=0;j<coloaneLinii;j++)
    interfata[i][j]='G';

}

void creareConsecinteAlegere(int terenMinat[20][20],int alegeriJucator[20][20],int y,int x,int coloaneLinii)
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

void afisareInterfata(int terenMinat[20][20],int alegeriJucator[20][20],int coloaneLinii)
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
{if(alegeriJucator[i][j]==0)
cout<<"  ";
else
{if(terenMinat[i][j]==0)
cout<<"- ";
else
cout<<terenMinat[i][j]<<" ";
}}}
if(i>=0 && i<coloaneLinii)
cout<<"|";
}
}

void minesweeper(int terenMinat[20][20],int alegeriJucator[20][20],int coloaneLinii)
{int minaLovita=0,x,y;
afisareInterfata( terenMinat, alegeriJucator, coloaneLinii);
while(minaLovita==0)
{cout<<endl<<"Alege Coloana ";
cin>>y;
cout<<endl<<"Alege Linia ";
cin>>x;
if(terenMinat[y-1][x-1]==-1)
{minaLovita=1;
 cout<<"BOOOOOOOOOOOOOOOM";
}
else
{creareConsecinteAlegere(terenMinat,alegeriJucator,y-1,x-1,coloaneLinii);
afisareInterfata( terenMinat, alegeriJucator, coloaneLinii);

}}

}


int main()
{srand(time(NULL));
int terenMinat[20][20],alegeriJucator[20][20];
char interfata[20][20];
initializareMatrice(alegeriJucator,9);
initializareMatrice(terenMinat,9);
plantareMine(terenMinat,10,9);
activareMine(terenMinat,9);
minesweeper(terenMinat, alegeriJucator, 9);




}
