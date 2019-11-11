#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>

using namespace std;

template<class H> class Nodo
{
private:
    H* key;
    Nodo<H>* parent;
    Nodo<H>* left;
    Nodo<H>* right;
public:
    Nodo(H x)
    {
        key=new H(x);
        parent=NULL;
        left=NULL;
        right=NULL;
    }

    void setKey(H key){this->key=new H(key);}
    H getKey(){return *key;}

    void setParent(Nodo<H>* parent){this->parent=parent;}
    Nodo<H>* getParent(){return parent;}

    void setLeft(Nodo<H>* left){this->left=left;}
    Nodo<H>* getLeft(){return left;}

    void setRight(Nodo<H>* right){this->right=right;}
    Nodo<H>* getRight(){return right;}

};

template<class H> class Albero
{
private:
    Nodo<H>* root;

    Nodo<H>* _ricerca(H x, Nodo<H>* tmp)
    {
        while(tmp!=NULL)
        {
            if(x==tmp->getKey())
                return tmp;
            else if(x<tmp->getKey())
                        tmp=tmp->getLeft();
                else
                        tmp=tmp->getRight();
        }
        return NULL;
    }
	
	Nodo<H>* _ricercaR(H x, Nodo<H>* tmp)
    {
        if(!tmp) return NULL;
		if(tmp->getKey()==x) return tmp;
		if(x<tmp->getKey())
			return _ricercaR(x,tmp->getLeft());
		else
			return _ricercaR(x,tmp->getRight());
    }

    Nodo<H>* _minimo(Nodo<H>* x)
    {
        while(x->getLeft()!=NULL)
        {
            x=x->getLeft();
        }
        return x;
    }

    Nodo<H>* _massimo(Nodo<H>* x)
    {
        while(x->getRight()!=NULL)
        {
            x=x->getRight();
        }
        return x;
    }

    Nodo<H>* _successore(Nodo<H>* x)
    {
        if(x->getRight())
            return _minimo(x->getRight());
        Nodo<H>* p=x->getParent();
        while(p!=NULL && p->getKey()<x->getKey())
            p=p->getParent();
        return p;
    }

    Nodo<H>* _predecessore(Nodo<H>* x)
    {
        if(x->getLeft())
            return _massimo(x->getLeft());
        Nodo<H>* p=x->getParent();
        while(p!=NULL && p->getKey()>x->getKey())
            p=p->getParent();
        return p;
    }

    void _preorder(Nodo<H>* x, ofstream& fout) //padre, sinistro, destro
    {
        if(x)
        {
            fout<<x->getKey()<<" ";
            _preorder(x->getLeft(),fout);
            _preorder(x->getRight(),fout);
        }
    }

    void _inorder(Nodo<H>* x, ofstream& fout) //sinistro, padre, destro
    {
        if(x)
        {
            _inorder(x->getLeft(),fout);
            fout<<x->getKey()<<" ";
            _inorder(x->getRight(),fout);
        }
    }

    void _postorder(Nodo<H>* x, ofstream& fout) //sinistro, destro, padre
    {
        if(x)
        {
            _postorder(x->getLeft(),fout);
            _postorder(x->getRight(),fout);
            fout<<x->getKey()<<" ";
        }
    }

    int _altezza(Nodo<H>* tmp) //libreria cmath per il max
    {
        if(!tmp) return 0;
        return max(_altezza(tmp->getLeft()),_altezza(tmp->getRight()))+1;
    }

    void _canc(H x, Nodo<H>* r)
    {
        Nodo<H>* tmp=_ricerca(x,r);
        if(!tmp) return;
        Nodo<H>* p=tmp->getParent();
        if(!tmp->getLeft() || !tmp->getRight())
        {
            /* 1° caso: il nodo da eliminare è una foglia
               2° caso: il nodo da eliminare ha un solo figlio (destro o sinistro)

               In entrambi i casi si modificano i collegamenti tra il padre del nodo e il figlio
            */
            Nodo<H>* figlio=tmp->getRight();
            if(tmp->getLeft())
            {
                figlio=tmp->getLeft();
            }
            if(!p)
            {
                root=figlio;
            }
            else{
                if(tmp==p->getLeft())
                    p->setLeft(figlio);
                else
                    p->setRight(figlio);
            }
            if(figlio)
            {
                figlio->setParent(p);
            }
        }
        else{
            /* 3° caso: il nodo da eliminare ha due figli

                In questo caso la chiave del nodo da cancellare si sostituisce
                con la chiave del successore e si elimina quest'ultimo
            */
            Nodo<H>* succ=_successore(tmp);
            tmp->setKey(succ->getKey());
            _canc(succ->getKey(),tmp->getRight());
        }
    }
public:
    Albero()
    {
        root=NULL;
    }

    void ins(F val)
    {
        Nodo<H>* nuovo=new Nodo<H>(val);
        Nodo<H>* tmp=root;
        Nodo<H>* p=NULL;
        while(tmp!=NULL)
        {
            p=tmp;
            if(val<tmp->getKey())
                tmp=tmp->getLeft();
            else
                tmp=tmp->getRight();
        }
        if(p==NULL)
        {
            root=nuovo;
        }
		else{
				if(val<p->getKey())
					p->setLeft(nuovo);
				else
					p->setRight(nuovo);
				nuovo->setParent(p);
			}
    }

    void canc(H val)
    {
       _canc(val,root);
    }

    void preorder(ofstream& fout)
    {
        _preorder(root,fout);
        fout<<endl;
    }

    void inorder(ofstream& fout)
    {
        _inorder(root,fout);
        fout<<endl;
    }

    void postorder(ofstream& fout)
    {
        _postorder(root,fout);
        fout<<endl;
    }

    int altezza()
    {
        return _altezza(root);
    }

    int profondita(H x)
    {
        Nodo<H>* tmp=_ricerca(x,root);
        if(!tmp) return -1;
        int p=0;
        while(tmp!=root)
        {
            tmp=tmp->getParent();
            p++;
        }
        return p;
    }

    void natural_fill(H* x)
    {
        Nodo<H>* tmp=_minimo(root);
        int i=0;
        while(tmp!=NULL)
        {
            tmp->setKey(x[i]);
            tmp=_successore(tmp);
            i++;
        }
        return;
    }
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string tipo,ordine,operaz;
    int n,i;
    for(int task=0;task<100;task++)
    {
        fin>>tipo;
        fin>>n;
        fin>>ordine;

        if(tipo=="int")
        {
            Albero<int>* a=new Albero<int>();
            for(i=0;i<n;i++)
            {
                fin>>operaz;
                int b=atoi(operaz.substr(operaz.find(':')+1).c_str());
                if(operaz.substr(0,3)=="ins")
                    a->ins(b);
                else
                    a->canc(b);
            }
           if(ordine=="preorder")
            {
                a->preorder(fout);
            }
            else if(ordine=="inorder")
                {
                    a->inorder(fout);
                }
                else
                {
                    a->postorder(fout);
                }
                //fout<<a->altezza()<<endl;
         }

         if(tipo=="double")
        {
            Albero<double>* a=new Albero<double>();
            for(i=0;i<n;i++)
            {
                fin>>operaz;
                double b=atof(operaz.substr(operaz.find(':')+1).c_str());
                if(operaz.substr(0,3)=="ins")
                    a->ins(b);
                else
                    a->canc(b);
            }
            if(ordine=="preorder")
            {
                a->preorder(fout);
            }
            else if(ordine=="inorder")
                {
                    a->inorder(fout);
                }
                else
                {
                    a->postorder(fout);
                }
                //fout<<a->altezza()<<endl;
         }
    }

    fin.close();
    fout.close();
}

/*int main() // per il natural_fill
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string tipo;
    int n,i;
    for(int task=0;task<100;task++)
    {
        fin>>tipo;
        fin>>n;

        if(tipo=="int")
        {
            Albero<int>* a=new Albero<int>();
            int val;
            for(i=0;i<n;i++)
            {
                fin>>val;
                a->ins(val);
            }
            int* v=new int[n];
            for(i=0;i<n;i++)
            {
                fin>>v[i];
            }
            a->natural_fill(v);
            a->postorder(fout);
         }

         if(tipo=="double")
        {
            Albero<double>* a=new Albero<double>();
            double val;
            for(i=0;i<n;i++)
            {
                fin>>val;
                a->ins(val);
            }
            double* v=new double[n];
            for(i=0;i<n;i++)
            {
                fin>>v[i];
            }
            a->natural_fill(v);
            a->postorder(fout);
         }
    }

    fin.close();
    fout.close();
}*/