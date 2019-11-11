#include <iostream>
#include <fstream>
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

    bool compara(H* a, H* b){return (*a)>(*b);}

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
        int max=i;
        if(l<=heapsize && compara(A[l],A[max])) max=l;
        if(r<=heapsize && compara(A[r],A[max])) max=r;

        if(max!=i)
        {
            scambia(max,i);
            heapify(max);
        }
    }

public:
    MaxHeap(int size){
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
        MaxHeap<int> *h=new MaxHeap<int>(N);
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
        MaxHeap<double> *h=new MaxHeap<double>(N);
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
        MaxHeap<bool> *h=new MaxHeap<bool>(N);
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
        MaxHeap<char> *h=new MaxHeap<char>(N);
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
