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

template<class H> class Pila{
private:
    Nodo<H>* head;

    void _pop(Nodo<H>* tmp)
    {
        if(tmp!=NULL)
        {
            head->setNext(tmp->getNext());
        }
    }
public:
    Pila()
    {
        head=new Nodo<H>();
        head->setNext(NULL);
    }

    void push(H x)
    {
        Nodo<H>* nuovo=new Nodo<H>(x);
        nuovo->setNext(head->getNext());
        head->setNext(nuovo);
    }

    void pop(){_pop(head->getNext());}

    void stampa(ofstream& fout)
    {
        Nodo<H>* tmp=head;
        while(tmp->getNext()!=NULL)
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
        Pila<int>* c=new Pila<int>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="pop")
            {
                c->pop();
            }else{
                int val=atoi(operaz.substr(1).c_str());
                c->push(val);
                }
        }
        c->stampa(fout);
    }

    if(tipo=="double")
    {
        Pila<double>* c=new Pila<double>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="pop")
            {
                c->pop();
            }else{
                double val=atof(operaz.substr(1).c_str());
                c->push(val);
                }
        }
        c->stampa(fout);
    }

    if(tipo=="bool")
    {
        Pila<bool>* c=new Pila<bool>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="pop")
            {
                c->pop();
            }else{
                bool val=atoi(operaz.substr(1).c_str());
                c->push(val);
                }
        }
        c->stampa(fout);
    }

    if(tipo=="char")
    {
        Pila<char>* c=new Pila<char>();
        for(int i=0;i<n;i++)
        {
            fin>>operaz;
            if(operaz=="pop")
            {
                c->pop();
            }else{
                char val=operaz[operaz.length()-1];
                c->push(val);
                }
        }
        c->stampa(fout);
    }
}

fin.close();
fout.close();
}