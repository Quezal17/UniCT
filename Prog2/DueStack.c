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

    Nodo<H>* _pop(Nodo<H>* tmp)
    {
        if(tmp!=NULL)
        {
            head->setNext(tmp->getNext());
        }
        return tmp;
    }
public:
    Pila()
    {
        head=new Nodo<H>();
        head->setNext(NULL);
    }

    void push(Nodo<H>* nuovo)
    {
        nuovo->setNext(head->getNext());
        head->setNext(nuovo);
    }

    Nodo<H>* pop(){return _pop(head->getNext());}

};

template<class H> class Coda{
private:
    Pila<H>* s1;
    Pila<H>* s2;
public:
    Coda()
    {
        s1=new Pila<H>();
        s2=new Pila<H>();
    }

    void travaso()
    {
        Nodo<H>* tmp=s1->pop();
        while(tmp!=NULL)
        {
            s2->push(tmp);
            tmp=s1->pop();
        }
    }

    void enqueue(H x)
    {
        Nodo<H>* nuovo=new Nodo<H>(x);
        s1->push(nuovo);
    }

    void dequeue()
    {
        Nodo<H>* tmp=s2->pop();
        if(tmp==NULL)
        {
            travaso();
            s2->pop();
        }
    }

    void stampa(ofstream& fout)
    {
        Nodo<H>* tmp=s2->pop();
        while(tmp!=NULL)
        {
            fout<<tmp->getKey()<<" ";
            tmp=s2->pop();
        }
        travaso();
        tmp=s2->pop();
        while(tmp!=NULL)
        {
            fout<<tmp->getKey()<<" ";
            tmp=s2->pop();
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