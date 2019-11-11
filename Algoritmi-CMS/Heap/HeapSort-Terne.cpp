#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

template<class T>
class Terna{
private:
    T a, b, c;
public:
    Terna(T x,T y,T z) : a(x), b(y), c(z){}

    T getA(){return a;}
    T getB(){return b;}
    T getC(){return c;}
};

template<class H>
class MaxHeap{
private:
    H** A;
    int len,heapsize,count;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1)|1;}
    int parent(int i){return i >> 1;}

    bool compara(H* x,H* y){return (x->getA()>y->getA()) || (x->getA()==y->getA() && x->getB()>y->getB()) || (x->getA()==y->getA() && x->getB()==y->getB() && x->getC()>y->getC());}
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
            fout << " " << "("<< A[i]->getA() << " " << A[i]->getB() << " " << A[i]->getC() << ")";
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
            Terna<int>** v=new Terna<int>*[N+1];
            int a,b,c;
            string temp1,temp2,temp3;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2 >> temp3;
                a=atoi(temp1.substr(1).c_str());
                b=atoi(temp2.c_str());
                c=atoi(temp3.substr(0,temp3.length()-1).c_str());
                v[i]=new Terna<int>(a,b,c);
            }
            MaxHeap<Terna<int> >* h=new MaxHeap<Terna<int> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }

        if(tipo=="double")
        {
            Terna<double>** v=new Terna<double>*[N+1];
            double a,b,c;
            string temp1,temp2,temp3;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2 >> temp3;
                a=atof(temp1.substr(1).c_str());
                b=atof(temp2.c_str());
                c=atof(temp3.substr(0,temp3.length()-1).c_str());
                v[i]=new Terna<double>(a,b,c);
            }
            MaxHeap<Terna<double> >* h=new MaxHeap<Terna<double> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }

        if(tipo=="bool")
        {
            Terna<bool>** v=new Terna<bool>*[N+1];
            bool a,b,c;
            string temp1,temp2,temp3;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2 >> temp3;
                a=atoi(temp1.substr(1).c_str());
                b=atoi(temp2.c_str());
                c=atoi(temp3.substr(0,temp3.length()-1).c_str());
                v[i]=new Terna<bool>(a,b,c);
            }
            MaxHeap<Terna<bool> >* h=new MaxHeap<Terna<bool> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }

        if(tipo=="char")
        {
            Terna<char>** v=new Terna<char>*[N+1];
            char a,b,c;
            string temp1,temp2,temp3;
            for(int i=1;i<=N;i++)
            {
                fin >> temp1 >> temp2 >> temp3;
                a=temp1[1];
                b=temp2[0];
                c=temp3[0];
                v[i]=new Terna<char>(a,b,c);
            }
            MaxHeap<Terna<char> >* h=new MaxHeap<Terna<char> >(v,N);
            h->heapsort();
            fout << h->getCount();
            h->stampa(fout);
        }
    }
}
