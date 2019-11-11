#include<fstream>
#include<iostream>
#include<cmath>

using namespace std;

 void selectionSort(int* v, int dim){
    int minimo,temp;
    for(int i=0;i<dim-1;i++)
    {
        minimo=i;
        for(int j=i+1;j<dim;j++)
        {
            if(v[j]<v[minimo])
                minimo=j;
        }
        temp=v[minimo];
        v[minimo]=v[i];
        v[i]=temp;
    }
 }

int numCoins(int* A, int N, int R, int* coins){
    int* restTable = new int[R+1];
    restTable[0] = 0;
    for(int i = 1; i <= R; i++) restTable[i] = R+1;

    for(int i = 1; i <= R; i++){
         for(int j = 0; j < N; j++){
             if(i >= A[j]){
                int tmp = restTable[i];
                restTable[i] = min(restTable[i - A[j]] + 1, restTable[i]);
                if(restTable[i] != tmp) coins[i] = A[j];
             }
         }
    }
    return restTable[R];
}

void printCoins(ostream& out, int* coins, int R){
    int usedCoins[R];
    int j = 0;
    while(R > 0){
        usedCoins[j++] = coins[R];
        R -= coins[R];
    }
    selectionSort(usedCoins, j);
    for(int i = 0; i < j; i++) out << usedCoins[i] << " ";
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int R = 0, N = 0;
    for(int i = 0; i < DIM; i++){
        in >> R >> N;
        int A[N] = {0};
        for(int j = 0; j < N; j++) in >> A[j];
        int coins[R+1];
        out << numCoins(A, N, R, coins) << " ";
        printCoins(out, coins, R);
        out << endl;
    }
    return 0;
}
