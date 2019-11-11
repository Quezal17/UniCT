#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

template<class H> class Vector{
private:
    int n,len,current;
    H** v;
public:
    Vector()
    {
        v=new H*[100];  // 100 è un maxlen
        n=0;
        current=0;
        len=100;
    }

    Vector(int x)
    {
        len=x;
        v=new H*[x];
        n=0;
        current=0;
    }

    Vector<H>* ins(H x)
    {
        if(n==len) return this;
        v[n]=new H(x);
        n++;
        return this;
    }

    H findKey(int indice)
    {
        return *v[indice];
    }

    int findIndex(H x)
    {
        for(int i=0;i<n;i++)
        {
            if(*v[i]==x)
                return i;
        }
        return -1;
    }

    int getSize(){return n;}

    void reset(){current=0;}

    int has_next()
    {
        return current>=n?0:1;
    }

    H* next()
    {
        if(!has_next())
            return NULL;
        H* tmp=v[current];
        current++;
        return tmp;
    }

};

template<class F> class Grafo{
private:
    int m,time,len;
    Vector<F>* k;
    int** adj;
    int *color, *d, *f, *p, *r;

    _sort(int *f, int* s, int n)
    {
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0 && f[s[j]]<f[s[j+1]])
            {
                int temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                j--;
            }

        }
    }

    int** creaGrafoT()
    {
        int n=k->getSize();
        int** adj_t=new int*[n];
        for(int i=0;i<n;i++)
        {
            adj_t[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                adj_t[i][j]=adj[j][i];
            }
        }
        return adj_t;
    }
public:
    Grafo()
    {
        len=100;
        k=new Vector<F>(len);
        adj=new int*[len];
        for(int i=0;i<len;i++)
        {
            adj[i]=new int[len];
            for(int j=0;j<len;j++)
                adj[i][j]=0;
        }
        color=new int[len];
        p=new int[len];
        r=new int[len];
        d=new int[len];
        f=new int[len];
        for(int j=0;j<len;j++)
        {
            d[j]=f[j]=101;  // 101 è maxlen+1 che corrisponde a "infinito"
        }

    }
    Grafo(int l)
    {
        len=l;
        k=new Vector<F>(len);
        adj=new int*[len];
        for(int i=0;i<len;i++)
        {
            adj[i]=new int[len];
            for(int j=0;j<len;j++)
                adj[i][j]=0;
        }
        color=new int[len];
        p=new int[len];
        r=new int[len];
        d=new int[len];
        f=new int[len];
        for(int j=0;j<len;j++)
        {
            d[j]=f[j]=101;  // 101 è maxlen+1 che corrisponde a "infinito"
        }

    }

    Grafo<F>* insNodo(F x)
    {
        k->ins(x);
        return this;
    }

    Grafo<F>* insArco(F x, F y)
    {
        int i=k->findIndex(x);
        int j=k->findIndex(y);
        if(i<0 || j<0) return this;
        m++;
        adj[i][j]=1;
        // adj[j][i]=1 in caso di grafo non orientato
        return this;
    }

    int hasArco(F x, F y)
    {
        int i=k->findIndex(x);
        int j=k->findIndex(y);
        if(i<0 || j<0) return 0;
        return adj[i][j];
    }

    int hasNodo(F x)
    {
        int i=k->findIndex(x);
        if(i<0) return 0;
        return 1;
    }

    int DFSvisit(int i)
    {
        color[i]=1;
        d[i]=time++;
        if(p[i]==-1) r[i]=i;
        int has_cycle=0;
        for(int u=0;u<k->getSize();u++)
        {
            if(adj[i][u])
            {
                if(!color[u])
                {
                    p[u]=i;
                    r[u]=r[i];
                    has_cycle= DFSvisit(u) || has_cycle;
                }
                else{
                    if(color[u]==1) has_cycle=1;
                }
            }

        }
        f[i]=time++;
        color[i]=2;
        return has_cycle;
    }

    int DFS() // bianco=0 grigio=1 nero=2
    {
        int has_cycle=0;
        time=0;
        for(int i=0;i<k->getSize();i++)
        {
            color[i]=0;
            r[i]=p[i]=-1;
            d[i]=f[i]=101;
        }
        for(int i=0;i<k->getSize();i++)
        {
            if(color[i]==0)
                has_cycle=DFSvisit(i) || has_cycle;
        }
        return has_cycle;
    }

    void topological_sort()
    {
        int cycle=DFS();
        if(cycle) return;
        int n=k->getSize();
        int* s=new int[n];
        for(int i=0;i<n;i++)
            s[i]=i;
        _sort(f,s,n);
        for(int i=0;i<n;i++)
            cout<<k->findKey(s[i])<<" ";
    }

    void BFS(F x)
    {
        int i=k->findIndex(x);
        if(i<0) return;
        for(int j=0;j<k->getSize();j++)
        {
            p[j]=-1;
            d[j]=101;
            color[j]=0;
        }
        Coda<int>* q=new Coda<int>();
        q->enqueue(i);
        color[i]=1;
        d[i]=0;
        while(!q->isEmpty())
        {
            int v=q->dequeue();
            for(int u=0;u<k->getSize();u++)
            {
                if(adj[v][u])
                    if(!color[u])
                    {
                        q->enqueue(u);
                        color[u]=1;
                        d[u]=d[v]+1;
                        p[u]=v;
                    }
            }
        }
    }

    int distance(F x, F y)
    {
        int i=k->findIndex(x);
        if(i<0) return 101;
        if(d[i]!=0)
            BFS(x);
        int j=k->findIndex(y);
        return d[j];
    }

    void printPath(F x,F y)
    {
        int dist= distance(x,y);
        if(distance==101)
            return;
        int i=k->findIndex(x);
        int j=k->findIndex(y);
        Pila<int>* q=new Pila<int>();
        j=p[j];
        while(j!=i)
        {
            q->push(j);
            j=p[j];
        }
        q->push(i);
        while(q->isEmpty())
        {
            int i=q->pop();
            int c=k->findKey(i);
            cout<<c<<" -> ";
        }
        cout<<y<<endl;
    }

    void CompFortConn()
    {
        int n=k->getSize();
        DFS();
        int** adj_t=_creaGrafoT();
        int** tmp=adj;
        adj=adj_t;
        int* s=new int[n];
        for(int i=0;i<n;i++)
            s[i]=i;
        _sort(f,s,n);
        time=0;
        for(int i=0;i<n;i++)
        {
            d[i]=f[i]=101;
            p[i]=r[i]=-1;
            color[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(color[s[i]]==0)
                DFSvisit(s[i]);
        }
        adj=tmp;
        int* h=new int[n];
        for(int i=0;i<n;i++)
            h[i]=0;
        for(int i=0;i<n;i++)
        {
            if(h[r[i]]==0)
            {
                for(int j=0;j<n;j++)
                    if(r[j]==r[i])
                        cout<<k->findKey(j)<<" ";
                cout<<endl;
                h[r[i]]=1;
            }
        }
    }
};