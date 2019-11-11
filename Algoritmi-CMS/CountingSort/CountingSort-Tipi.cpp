#include <fstream>
#include <iostream>

using namespace std;

template<class H>
int* countingSort(H* A, int N, int* k)
{
    H max=A[0];
    H min=A[0];
    for(int i=1;i<N;i++)
    {
        if(max<A[i]) max=A[i];
        if(min>A[i]) min=A[i];
    }
    *k=max-min+1;
    int* C=new int[*k];
    for(int i=0;i<*k;i++) C[i]=0;

    for(int i=0;i<N;i++)
    {
        int j=A[i]-min;
        C[j]++;
    }
    for(int i=1;i<*k;i++) C[i]+=C[i-1];

    H B[N];
    for(int i=N-1;i>=0;i--)
    {
        int j=A[i]-min;
        B[(C[j]--)-1]=A[i];
    }

    for(int i=0;i<N;i++) A[i]=B[i];

    return C;
}


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string tipo;
    int N;
    int k;
    for(int x=0;x<100;x++)
    {
        fin >> tipo >> N;

        if(tipo=="int")
        {
            int v[N];
            for(int i=0;i<N;i++)
                fin >> v[i];
            int* c=countingSort(v,N,&k);

            for(int i=0;i<k;i++) fout << c[i] << " ";
            for(int i=0;i<N;i++) fout << v[i] << " ";
            fout << endl;
        }

        if(tipo=="double")
        {
            double v[N];
            for(int i=0;i<N;i++)
            {
                fin >> v[i];
                v[i]=v[i]*10;
            }

            int* c=countingSort(v,N,&k);

            for(int i=0;i<k;i++) fout << c[i] << " ";
            for(int i=0;i<N;i++) fout << (v[i]/10) << " ";
            fout << endl;
        }

        if(tipo=="bool")
        {
            bool v[N];
            for(int i=0;i<N;i++)
                fin >> v[i];
            int* c=countingSort(v,N,&k);

            for(int i=0;i<k;i++) fout << c[i] << " ";
            for(int i=0;i<N;i++) fout << v[i] << " ";
            fout << endl;
        }

        if(tipo=="char")
        {
            char v[N];
            for(int i=0;i<N;i++)
                fin >> v[i];
            int* c=countingSort(v,N,&k);

            for(int i=0;i<k;i++) fout << c[i] << " ";
            for(int i=0;i<N;i++) fout << v[i] << " ";
            fout << endl;
        }

    }
}

