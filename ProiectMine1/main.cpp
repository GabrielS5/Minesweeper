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
{if(matrice[x][y]==0)
return 0;
return 1;

}

void plantareMine(int terenMinat[20][20],int numarMine,int coloaneLinii)
{int coordonataX,coordonataY;
while(numarMine>0)
{coordonataX=rand()%coloaneLinii;
coordonataY=rand()%coloaneLinii;
if(!contineMina(terenMinat,coordonataX,coordonataY))
{terenMinat[coordonataX][coordonataY]=-1;
numarMine--;}}}

int main()
{srand(time(NULL));
int terenMinat[20][20];
initializareMatrice(terenMinat,10);
plantareMine(terenMinat,10,9);
afisare(terenMinat,9);

}
