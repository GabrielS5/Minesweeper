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





int main()
{srand(time(NULL));
int terenMinat[20][20];
initializareMatrice(terenMinat,10);
plantareMine(terenMinat,10,9);
afisare(terenMinat,9);
activareMine(terenMinat,9);
afisare(terenMinat,9);

}
