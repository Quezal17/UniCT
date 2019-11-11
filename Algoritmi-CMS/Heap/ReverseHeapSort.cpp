#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template<class H>
class MinHeap{
private:
    H** A;
    int len,heapsize,count;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1)|1;}
    int parent(int i){return i >> 1;}

    bool compara(H* a,H* b){return (*a) < (*b);}
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
        int min=i;

        if(l<=heapsize && compara(A[l],A[min])) min=l;
        if(r<=heapsize && compara(A[r],A[min])) min=r;

        if(min!=i)
        {
            scambia(min,i);
            heapify(min);
        }
    }

    void buildMinHeap()
    {
        for(int i=floor(heapsize/2);i>0;i--) heapify(i);
    }

    void extract()
    {   if(heapsize==0) return;
        scambia(1,heapsize--);
        heapify(1);
    }

public:

    MinHeap(H** v,int dim) : A(v), len(dim+1), heapsize(dim), count(0){}

    void heapsort()
    {
        buildMinHeap();

        for(int i=1;i<len;i++)
           extract();
    }

    int getCount(){return count;}

    void stampa(ofstream &fout)
    {
        for(int i=1;i< len;i++)
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
            MinHeap<int>* h=new MinHeap<int>(v,N);
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
            MinHeap<double>* h=new MinHeap<double>(v,N);
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
            MinHeap<bool>* h=new MinHeap<bool>(v,N);
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
            MinHeap<char>* h=new MinHeap<char>(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }
    }
}
