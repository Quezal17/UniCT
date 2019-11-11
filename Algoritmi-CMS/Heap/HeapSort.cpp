#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template<class H>
class MaxHeap{
private:
    H** A;
    int len,heapsize,count;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1)|1;}
    int parent(int i){return i >> 1;}

    bool compara(H* a,H* b){return (*a) > (*b);}
    void scambia(int a, int b)
    {
        H* temp=A[a];
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

        if(l<=heapsize && compara(A[l],A[max])) max=l;
        if(r<=heapsize && compara(A[r],A[max])) max=r;

        if(max!=i)
        {
            scambia(max,i);
            heapify(max);
        }
    }

    void buildMaxHeap()
    {
        for(int i=floor(heapsize/2);i>0;i--) heapify(i);
    }

    void extract()
    {   if(heapsize==0) return;
        scambia(1,heapsize--);
        heapify(1);
    }

public:

    MaxHeap(H** v,int dim) : A(v), len(dim+1), heapsize(dim), count(0){}

    void heapsort()
    {
        buildMaxHeap();

        for(int i=1;i<len;i++)
           extract();
    }

    int getCount(){return count;}

    void stampa(ofstream &fout)
    {
        for(int i=1;i<len;i++)
            fout << " " << *A[i];
        fout << endl;
    }
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
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
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
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
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
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
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
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }
    }
}
