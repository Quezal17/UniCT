#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

template<class H>
class MaxHeap{
private:
    H** A;
    int len;
    int heapsize;
    int count;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1) | 1;}
    int parent(int i){return i >> 1;}
    bool compare(H* a, H* b){return (*a)<(*b);}
    void scambia(int a, int b){
        H* temp= A[a];
        A[a]=A[b];
        A[b]=temp;
    }

    void heapify(int i)
    {
        if(i>heapsize) return;
        count++;
        int l=left(i);
        int r=right(i);
        int max=i;
        if(l<=heapsize && compare(A[max],A[l])) max=l;
        if(r<=heapsize && compare(A[max],A[r])) max=r;

        if(max==i) return;
        scambia(i,max);
        heapify(max);
    }

public:

    MaxHeap(H** v,int N): A(v), len(N+1), heapsize(N), count(0){}

    void buildMaxHeap()
    {
        for(int i=floor(heapsize/2);i>0;i--) heapify(i);
    }

    void extract(){
        scambia(1,heapsize--);
        heapify(1);
    }

    int getCount(){return count;}

};

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string tipo;
    int N;

    for(int x=0;x<100;x++)
    {
        fin >> tipo >> N;
        if(tipo=="int")
        {
            int** v=new int*[N+1];
            for(int i=1;i<=N;i++)
            {
                v[i]=new int;
                fin >> *v[i];
            }
            MaxHeap<int>* h=new MaxHeap<int>(v,N);

            h->buildMaxHeap();
            for(int i=0;i<N;i++)
            {
                h->extract();
            }
            fout<<h->getCount()<<endl;
        }

        if(tipo=="double")
        {
            double** v=new double*[N+1];
            for(int i=1;i<=N;i++)
            {
                v[i]=new double;
                fin >> *v[i];
            }
            MaxHeap<double>* h=new MaxHeap<double>(v,N);

            h->buildMaxHeap();
            for(int i=0;i<N;i++)
            {
                h->extract();
            }
            fout<<h->getCount()<<endl;
        }
        if(tipo=="bool")
        {
            bool** v=new bool*[N+1];
            for(int i=1;i<=N;i++)
            {
                v[i]=new bool;
                fin >> *v[i];
            }
            MaxHeap<bool>* h=new MaxHeap<bool>(v,N);

            h->buildMaxHeap();
            for(int i=0;i<N;i++)
            {
                h->extract();
            }
            fout<<h->getCount()<<endl;
        }
        if(tipo=="char")
        {
            char** v=new char*[N+1];
            for(int i=1;i<=N;i++)
            {
                v[i]=new char;
                fin >> *v[i];
            }
            MaxHeap<char>* h=new MaxHeap<char>(v,N);

            h->buildMaxHeap();
            for(int i=0;i<N;i++)
            {
                h->extract();
            }
            fout<<h->getCount()<<endl;
        }
    }

    return 0;
}
