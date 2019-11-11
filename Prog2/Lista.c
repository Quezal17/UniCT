#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;
/*
- Lista doppiamente linkata: head, tail, next e prev
- Coda: head, tail
    °Struttura dati di tipo FIFO(First-In-First-Out)
    °inserimento in coda
    °eliminazione in testa
    °stampa testa -> coda
- Pila: top
    °Struttura dati di tipo LIFO(Last-In-First-Out)
    °inserimento in testa (push)
    °estrazione in testa (pop)
    °stampa testa -> coda
*/
template<class H> class Nodo {
private:
    H* key;
    Nodo<H>* next;
    Nodo<H>* prev;
public:
    Nodo()
    {
        this->key=new H();
        next=NULL;
        prev=NULL;
    }
    Nodo(H key)
    {
        this->key=new H(key);
        next=NULL;
        prev=NULL;
    }

    H getKey(){return *key;}
    void setKey(H key){this->key=new H(key);}

    Nodo<H>* getNext(){return next;}
    void setNext(Nodo<H>* x){next=x;}

    Nodo<H>* getPrev(){return prev;}
    void setPrev(Nodo<H>* x){prev=x;}
};

template<class F> class Lista{
private:
    Nodo<F>* head;
    Nodo<F>* trailer;
    Nodo<F>* current;
    int n;

    void _inserisci(F x,Nodo<F>* e)
    {
        Nodo<F>* node=new Nodo<F>(x);
        Nodo<F>* prev=e->getPrev();

        prev->setNext(node);
        node->setPrev(prev);
        node->setNext(e);
        e->setPrev(node);
        n++;
    }

    Nodo<F>* _ricerca(F x)
    {
        Nodo<F>* s1=head->getNext();
        while(s1!=trailer)
        {
            if(s1->getKey()==x)
                return s1;
            s1=s1->getNext();
        }
        return NULL;
    }

    int _cancella(F x)
    {
        Nodo<F>* tmp=_ricerca(x);

        if(!tmp)
        {
            return 0;
        }
        Nodo<F>* prev=tmp->getPrev();
        Nodo<F>* next=tmp->getNext();

        prev->setNext(next);
        next->setPrev(prev);
        n--;
        return 1;
    }

public:
    Lista()
    {
        n=0;
        head=new Nodo<F>();
        trailer=new Nodo<F>();
        head->setNext(trailer);
        trailer->setPrev(head);
    }

    int getSize(){return n;}

    Lista<F>* inserimento(F x)
    {
        _inserisci(x,head->getNext());
        return this;
    }
	
    Lista<F>* inserimentoCoda(F x)
    {
        _inserisci(x,trailer);
        return this;
    }

    void ricerca(F x)
    {
        if(_ricerca(x)!=NULL)
            cout<<"Elemento presente!"<<endl;
        else
            cout<<"Elemento non presente!"<<endl;
    }

    Lista<F>* cancellazione(F x)
    {
        if(_cancella(x)==0)
            cout<<"Elemento non presente!"<<endl;
        return this;
    }

    F somma()
    {

        Nodo<F>* s1=head->getNext();
        F somma=s1->getKey();
        while(s1!=trailer)
        {
            s1=s1->getNext();
            somma+=s1->getKey();
        }
        return somma;
    }

    void reset(){current=head->getNext();}

    F* next()
    {
        if(current && current!=trailer)
        {
            Nodo<F>* tmp=current;
            current=current->getNext();
            return new F(tmp->getKey());
        }
        return NULL;
    }
	
    int has_next()
    {
        return (current!=NULL && current!=trailer);
    }
	
    void stampa()
    {
        Nodo<F>* s1=head->getNext();
        while(s1!=trailer)
        {
            cout<<s1->getKey()<<" ";
            s1=s1->getNext();
        }
        cout<<endl;
    }
};

template<class G> ofstream& operator<<(ofstream& fout,const Lista<G>& l1)
{
    Lista<G> l=l1;
    l.reset();
    while(G* i=l.next())
    {
        fout<<*i<<" ";
    }
    return fout;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string tipo="";
    int n=0;

    for(int task=0;task<3;task++)
    {
    fin>>tipo;
    fin>>n;

    if(tipo=="int")
    {
        Lista<int>* l=new Lista<int>();
        int s;
        for(int i=0;i<n;i++)
        {
            fin>>s;
           l->inserimentoCoda(s);
        }
        l->stampa();
        fout<<*l<<endl;
    }
    else if(tipo=="double")
        {
           Lista<double>* l=new Lista<double>();
            double s;
            for(int i=0;i<n;i++)
            {
                fin>>s;
                l->inserimentoCoda(s);
            }
            l->stampa();
            fout<<*l<<endl;
        }
        else if(tipo=="float")
        {
            Lista<float>* l=new Lista<float>();
            float s;
            for(int i=0;i<n;i++)
            {
                fin>>s;
                l->inserimentoCoda(s);
            }
            l->stampa();
            fout<<*l<<endl;
        }
    }
    fin.close();
    fout.close();
}