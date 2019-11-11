#include <iostream>
#include <fstream>

using namespace std;

template<class H>
class MinHeap{
private:
    H** A;
    int len;
    int heapsize;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1) | 1;}
    int parent(int i){return i >> 1;}
    bool compare(H* a, H* b){return (*a)>(*b);}
    void scambia(int a, int b){
        H* temp= A[a];
        A[a]=A[b];
        A[b]=temp;
    }

    void check(int i)
    {
        while(i>1 && compare(A[parent(i)],A[i]))
        {
            scambia(i,parent(i));
            i=parent(i);
        }
    }

public:

    MinHeap(int N)
    {
        len=N+1;
        heapsize=0;
        A=new H*[len];
    }

    void enqueue(H x)
    {
        A[++heapsize]=new H(x);
        check(heapsize);
    }

    void stampa(ofstream& fout)
    {
        for(int i=1;i<=heapsize;i++)
            fout << *A[i] << " ";
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
            int numero;
            MinHeap<int>* h=new MinHeap<int>(N);
            for(int i=0;i<N;i++)
            {
                fin >> numero;
                h->enqueue(numero);
            }

            h->stampa(fout);
        }

        if(tipo=="double")
        {
            double numero;
            MinHeap<double>* h=new MinHeap<double>(N);
            for(int i=0;i<N;i++)
            {
                fin >> numero;
                h->enqueue(numero);
            }

            h->stampa(fout);
        }
        if(tipo=="bool")
        {
            bool numero;
            MinHeap<bool>* h=new MinHeap<bool>(N);
            for(int i=0;i<N;i++)
            {
                fin >> numero;
                h->enqueue(numero);
            }

            h->stampa(fout);
        }
        if(tipo=="char")
        {
            char lettera;
            MinHeap<char>* h=new MinHeap<char>(N);
            for(int i=0;i<N;i++)
            {
                fin >> lettera;
                h->enqueue(lettera);
            }

            h->stampa(fout);
        }
    }

    return 0;
}
