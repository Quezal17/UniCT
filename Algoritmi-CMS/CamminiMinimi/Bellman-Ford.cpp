#include <iostream>
#include <fstream>
#include<string>
#include<cstdlib>
#include<climits>

using namespace std;

template<class H>
class Grafo{
private:
    H* nodi;
    H** pesi;
    int dim;

    int findIndex(H key)
    {
        int index=-1;
        int i=0;
        while(i<dim && nodi[i]!=key)
            i++;
        if(i<dim)
            index=i;
        return index;
    }

    void relax(int index1, int index2, H* dist)
    {
        if(dist[index2]>dist[index1]+pesi[index1][index2])
            dist[index2]=dist[index1]+pesi[index1][index2];
    }


public:
    Grafo(H* v, int n)
    {
        nodi=v;
        dim=n;

        pesi=new H*[dim];
        for(int i=0;i<dim;i++)
            pesi[i]=new H[dim];

        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                pesi[i][j]=INT_MAX;
    }

    void AddEdge(H key1, H key2, H peso)
    {
        int index1=findIndex(key1);
        int index2=findIndex(key2);

        if(index1<0 || index2<0)
            return;
        pesi[index1][index2]=peso;
    }

    void bellman_ford(H sorg,H dest,ofstream& fout)
    {
        H dist[dim];
        for(int i=0;i<dim;i++)
            dist[i]=INT_MAX;
        dist[findIndex(sorg)]=0;

        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                for(int k=0;k<dim;k++)
                    relax(j,k,dist);

        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                if(dist[j]>dist[i]+pesi[i][j])
                {
                    fout<<"undef."<<endl;
                    return;
                }

        if(dist[findIndex(dest)]==INT_MAX)
            fout<<"inf."<<endl;
        else
            fout<<dist[findIndex(dest)]<<endl;
    }
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int num_nodi, num_archi;

    string tipo,s1,s2,s3;

    for (int z = 0; z < 100; z++)
    {
        fin >> num_nodi >> num_archi >> tipo;

            double* keys=new double[num_nodi];

            for (int i = 0; i < num_nodi; i++)
                fin >> keys[i];

            Grafo<double> *grafo = new Grafo<double>(keys, num_nodi);

            for (int i = 0; i < num_archi; i++)
            {
                fin >> s1 >> s2 >> s3;
                double key1=atof(s1.substr(1).c_str());
                double key2=atof(s2.c_str());
                double peso=atof(s3.substr(0,s3.length()-1).c_str());
                grafo->AddEdge(key1, key2, peso);
            }

            double sorg,dest;
            fin >> sorg;
            fin >> dest;

            grafo->bellman_ford(sorg,dest,fout);
    }

}
