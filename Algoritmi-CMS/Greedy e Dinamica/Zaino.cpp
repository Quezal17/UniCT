#include <iostream>
#include <fstream>

using namespace std;

void ordina(int *v,int dim)
{
    int max;
    for(int j=0;j<dim-1;j++)
    {
        max=j;
        for(int i=j+1;i<dim;i++)
        {
            if(v[max]<v[i]) max=i;
        }
        int temp=v[max];
        v[max]=v[j];
        v[j]=temp;
    }
}

int estraiMaxVal(int *v,int Pzaino)
{
    int MaxVal=0;
    for(int i=0;i<Pzaino;i++)
    {
        MaxVal+=v[i];
    }
    return MaxVal;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, Pzaino, max;
    int* valori;
    for(int x=0;x<100;x++)
    {
        fin >> N >> Pzaino;
        valori=new int[N];
        for(int i=0;i<N;i++)
        {
            fin >> valori[i];
        }
        ordina(valori,N);
        max=estraiMaxVal(valori,Pzaino);
        fout << max << endl;
    }
}
