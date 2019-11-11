#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

template<class H>
class MinHeap{
private:
    H** A;
    int len;
    int heapsize;
    int count;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1) | 1;}
    int parent(int i){return i >> 1;}

    bool compara(H* a, H* b){return (*a)<(*b);}

    void scambia(int a, int b)
    {
        H* temp=A[a];
        A[a]=A[b];
        A[b]=temp;
    }

    void check(int i)
    {
        while(i>1 && compara(A[i],A[parent(i)]))
        {
            scambia(i,parent(i));
            i=parent(i);
        }
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

public:
    MinHeap(int size){
        len=size+1;
        heapsize=0;
        count=0;
        A=new H*[len];
    }

    void enqueue(H val)
    {
        A[++heapsize]=new H(val);
        check(heapsize);
    }

    void extract()
    {
        scambia(1,heapsize--);
        heapify(1);
    }

    void stampa(ofstream& fout)
    {
        for(int i=1;i<=heapsize;i++)
            fout << *A[i] << " ";
        fout << endl;
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
        MinHeap<int> *h=new MinHeap<int>(N);
        string valore;
        int numero;

        for(int j=0;j<N;j++)
        {
            fin >> valore;
            if(valore=="extract")
            {
                h->extract();
            }else{
                numero=atoi(valore.substr(2).c_str());
                h->enqueue(numero);
            }
        }
        fout << h->getCount() << " ";
        h->stampa(fout);
    }

    if(tipo=="double")
    {
        MinHeap<double> *h=new MinHeap<double>(N);
        string valore;
        double numero;

        for(int j=0;j<N;j++)
        {
            fin >> valore;
            if(valore=="extract")
            {
                h->extract();
            }else{
                numero=atof(valore.substr(2).c_str());
                h->enqueue(numero);
            }
        }
        fout << h->getCount() << " ";
        h->stampa(fout);
    }

    if(tipo=="bool")
    {
        MinHeap<bool> *h=new MinHeap<bool>(N);
        string valore;
        bool numero;

        for(int j=0;j<N;j++)
        {
            fin >> valore;
            if(valore=="extract")
            {
                h->extract();
            }else{
                numero=atoi(valore.substr(2).c_str());
                h->enqueue(numero);
            }
        }
        fout << h->getCount() << " ";
        h->stampa(fout);
    }

    if(tipo=="char")
    {
        MinHeap<char> *h=new MinHeap<char>(N);
        string valore;

        for(int j=0;j<N;j++)
        {
            fin >> valore;
            if(valore=="extract")
            {
                h->extract();
            }else{
                h->enqueue(valore[2]);
            }
        }
        fout << h->getCount() << " ";
        h->stampa(fout);
    }


}

}
