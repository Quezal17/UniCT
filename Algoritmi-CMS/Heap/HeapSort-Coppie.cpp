#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

template<class T>
class Coppia{
private:
    T a, b;
public:
    Coppia(T x,T y) : a(x), b(y){}

    T getA(){return a;}
    T getB(){return b;}
};

template<class H>
class MaxHeap{
private:
    H** A;
    int len,heapsize,count;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1)|1;}
    int parent(int i){return i >> 1;}

    bool compara(H* x,H* y){return (x->getA()>y->getA())||(x->getA()==y->getA() && x->getB()>y->getB());}
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
        for(int i=1;i< len;i++)
            fout << " " << "("<< A[i]->getA() << " " << A[i]->getB() << ")";
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
            Coppia<int>** v=new Coppia<int>*[N+1];
            int a,b;
            string temp1,temp2;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2;
                a=atoi(temp1.substr(1).c_str());
                b=atoi(temp2.substr(0,temp2.length()-1).c_str());
                v[i]=new Coppia<int>(a,b);
            }
            MaxHeap<Coppia<int> >* h=new MaxHeap<Coppia<int> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }

        if(tipo=="double")
        {
            Coppia<double>** v=new Coppia<double>*[N+1];
            double a,b;
            string temp1,temp2;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2;
                a=atof(temp1.substr(1).c_str());
                b=atof(temp2.substr(0,temp2.length()-1).c_str());
                v[i]=new Coppia<double>(a,b);
            }
            MaxHeap<Coppia<double> >* h=new MaxHeap<Coppia<double> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }

        if(tipo=="bool")
        {
            Coppia<bool>** v=new Coppia<bool>*[N+1];
            bool a,b;
            string temp1,temp2;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2;
                a=atoi(temp1.substr(1).c_str());
                b=atoi(temp2.substr(0,temp2.length()-1).c_str());
                v[i]=new Coppia<bool>(a,b);
            }
            MaxHeap<Coppia<bool> >* h=new MaxHeap<Coppia<bool> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }

        if(tipo=="char")
        {
            Coppia<char>** v=new Coppia<char>*[N+1];
            char a,b;
            string temp1,temp2;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2;
                a=temp1[1];
                b=temp2[0];
                v[i]=new Coppia<char>(a,b);
            }
            MaxHeap<Coppia<char> >* h=new MaxHeap<Coppia<char> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }
    }
}

