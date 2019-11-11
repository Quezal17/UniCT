#include <fstream>
#include <iostream>

using namespace std;

int* countingSort(int* A, int N, int* k)
{
    int max=A[0];
    int min=A[0];
    for(int i=1;i<N;i++)
    {
        if(max<A[i]) max=A[i];
        if(min>A[i]) min=A[i];
    }
    *k=max-min+1;
    int* C=new int[*k];
    for(int i=0;i<*k;i++) C[i]=0;

    for(int i=0;i<N;i++) C[A[i]-min]++;
    for(int i=1;i<*k;i++) C[i]+=C[i-1];

    int B[N];
    for(int i=N-1;i>=0;i--) B[(C[A[i]-min]--)-1]=A[i];

    for(int i=0;i<N;i++) A[i]=B[i];

    return C;
}


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    int k;
    for(int x=0;x<100;x++)
    {
        fin >> N;
        int v[N];
        for(int i=0;i<N;i++)
            fin >> v[i];
        int* c=countingSort(v,N,&k);

        for(int i=0;i<k;i++) fout << c[i] << " ";
        for(int i=0;i<N;i++) fout << v[i] << " ";
        fout << endl;

    }
}
