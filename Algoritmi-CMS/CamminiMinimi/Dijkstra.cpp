#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

template<class N>
class Nodi{
    private:
        N* v;
        int maxSize;
        int n;
    public:
        Nodi(int m): maxSize(m){
            v = new N[maxSize];
            n = 0;
        }

        void addNodi(N x){
            if(n < maxSize) v[n++] = x;
        }

        N findNodo(int index){
            if(index >= 0 && index < maxSize)
                return v[index];
        }

        int findIndex(N x){
            for(int i = 0; i < maxSize; i++)
                if(v[i] == x) return i;
            return -1;
        }
};

template<class N>
class Graph{
    private:
        int nNodi;
        int nArchi;
        int** matrix;
        int* dist;
        bool* visitati;
        Nodi<N>* nodi;

        int findMin(){
            int nodo;
            int min = 101;
            for(int i = 0; i < nNodi; i++)
                if(!visitati[i] && dist[i] < min){
                    min = dist[i];
                    nodo = i;
                }
            return nodo;
        }

        void dijkstra(int start){
            for(int i = 0; i < nNodi; i++){
                dist[i] = 101;
                visitati[i] = false;
            }
            dist[start] = 0;

            for(int i = 0; i < nNodi; i++){
                int nodo = findMin();
                visitati[nodo] = true;
                for(int j = 0; j < nNodi; j++)
                    if(!visitati[j] && matrix[nodo][j] != 101 && dist[j] > dist[nodo] + matrix[nodo][j])
                        dist[j] = dist[nodo] + matrix[nodo][j];
            }
        }

    public:
        Graph(int n){
            nNodi = n;
            nArchi = 0;
            dist = new int[nNodi];
            visitati = new bool[nNodi];
            matrix = new int*[nNodi];
            for(int i = 0; i < nNodi; i++){
                matrix[i] = new int[nNodi];
                for(int j = 0; j < nNodi; j++)
                    matrix[i][j] = 101;
            }
            nodi = new Nodi<N>(nNodi);
        }

        void addNodo(N x){
            nodi->addNodi(x);
        }

        void addArco(N x, N y, int w){
            int i = nodi->findIndex(x);
            int j = nodi->findIndex(y);
            if(i < 0 || j < 0) return;
            matrix[i][j] = w;
            nArchi++;
        }

        void distanza(N x, N y, ofstream& out){
            int i = nodi->findIndex(x);
            int j = nodi->findIndex(y);
            if(i < 0 || j < 0) return;
            dijkstra(i);
            if(dist[j] != 101)
                out << dist[j];
            else
                out << "inf.";
            out << endl;
        }
};

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N, M;
    string type;
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> type;
        if(type == "int"){
            Graph<int>* G = new Graph<int>(N);
            for(int j = 0; j < N; j++){
                int nodo;
                in >> nodo;
                G->addNodo(nodo);
            }
            for(int j = 0; j < M; j++){
                int a, b;
                int w;
                string s1, s2;
                in >> s1 >> b >> s2;
                a=atoi(s1.substr(1).c_str());
                w=atoi(s2.substr(0, s2.length()-1).c_str());
                G->addArco(a, b, w);
            }
            int a, b;
            in >> a >> b;
            G->distanza(a, b,out);
        }
        if(type == "double"){
            Graph<double>* G = new Graph<double>(N);
            for(int j = 0; j < N; j++){
                double nodo;
                in >> nodo;
                G->addNodo(nodo/10);
            }
            for(int j = 0; j < M; j++){
                double a, b;
                int w;
                string s1, s2;
                in >> s1 >> b >> s2;
                a=atof(s1.substr(1).c_str());
                w=atof(s2.substr(0, s2.length()-1).c_str());
                G->addArco(a, b, w);
            }
            double a, b;
            in >> a >> b;
            G->distanza(a, b,out);
        }
    }
    return 0;
}
