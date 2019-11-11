#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

template<class H> class Nodo {
private:
    H* key;
    Nodo<H>* next;
public:
    Nodo()
    {
        this->key=new H();
        next=NULL;
    }
    Nodo(H key)
    {
        this->key=new H(key);
        next=NULL;
    }

    H getKey(){return *key;}
    void setKey(H key){this->key=new H(key);}

    Nodo<H>* getNext(){return next;}
    void setNext(Nodo<H>* x){next=x;}
};

template<class H> class Coda{
private:
    Nodo<H>* head;
    Nodo<H>* tail;

    void _dequeue(Nodo<H>* tmp)
    {
        if(tmp!=tail)
        {
            head->setNext(tmp->getNext());
        }
    }
public:
    Coda()
    {
        head=new Nodo<H>();
        tail=new Nodo<H>();
        head->setNext(tail);
    }

    void enqueue(H x)
    {
        Nodo<H>* nuovo=new Nodo<H>(x);
        Nodo<H>* tmp=head;
        while(tmp->getNext()!=tail)
        {
            tmp=tmp->getNext();
        }
        tmp->setNext(nuovo);
        nuovo->setNext(tail);
    }

    void dequeue(){_dequeue(head->getNext());}

    void stampa(ofstream& fout)
    {
        Nodo<H>* tmp=head;
        while(tmp->getNext()!=tail)
        {
            tmp=tmp->getNext();
            fout<<tmp->getKey()<<" ";
        }
        fout<<endl;
    }

};

int main(){
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
string operaz,tipo;

for(int task=0;task<100;task++)
{
    fin>>tipo;
    fin>>n;

    if(tipo=="int")
    {
        Coda<int>* c=new Coda<int>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="dequeue")
            {
                c->dequeue();
            }else{
                int val=atoi(operaz.substr(1).c_str());
                c->enqueue(val);
                }
        }
        c->stampa(fout);
    }

    if(tipo=="double")
    {
        Coda<double>* c=new Coda<double>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="dequeue")
            {
                c->dequeue();
            }else{
                double val=atof(operaz.substr(1).c_str());
                c->enqueue(val);
                }
        }
        c->stampa(fout);
    }

    if(tipo=="bool")
    {
        Coda<bool>* c=new Coda<bool>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="dequeue")
            {
                c->dequeue();
            }else{
                bool val=atoi(operaz.substr(1).c_str());
                c->enqueue(val);
                }
        }
        c->stampa(fout);
    }

    if(tipo=="char")
    {
        Coda<char>* c=new Coda<char>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="dequeue")
            {
                c->dequeue();
            }else{
                char val=operaz[operaz.length()-1];
                c->enqueue(val);
                }
        }
        c->stampa(fout);
    }
}

fin.close();
fout.close();
}