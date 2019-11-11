#include<cstdlib>
#include<iostream>
#include<fstream>

using namespace std;

template<class H> class Vector{
private:
	int len;
	H** v;
public:
	Vector(int x)
	{
		len=x;
		v=new H*[len];		
	}
	
	void insertionSort(int* x)
	{
		for(int i=1;i<len;i++)
		{
			int j=i-1;
			while(j>=0 && v[j]>v[j+1])
			{
				H tmp=v[j];
				v[j]=v[j+1];
				v[j+1]=tmp;
				j--;
			}
		}
	}
	
	void ins(H* tmp)
	{
		insertionSort(tmp);
		for(int i=0;i<len;i++)
		{
			v[i]=new H(tmp[i]);
		}
	}
	
	H findKey(int indice)
	{
		return *v[indice];
	}
	
	int findIndex(H x)
	{
		for(int i=0;i<len;i++)
		{
			if(*v[i]==x)
				return i;
		}
		return -1;
	}
};

template<class H> class Grafo{
private:
	Vector<H>* v;
	int** adj;
	int len;
public:
	Grafo(int x)
	{
		len=x;
		v=new Vector<H>(len);
		adj=new int*[len];
		for(int i=0;i<len;i++)
		{
			adj[i]=new int[len];
			for(int j=0;j<len;j++)
			{
				adj[i][j]=0;
			}
		}
	}
	
	void insNodo(H* tmp)
	{
		v->ins(tmp);
	}
	
	void insArco(H x,H y)
	{
		int i=v->findIndex(x);
		int j=v->findIndex(y);
		if(i<0 || j<0) return;
		adj[i][j]=1;
	}
	
	void stampa(ofstream& fout)
	{
		for(int i=0;i<len;i++)
		{
			fout<<"("<<v->findKey(i);
			for(int j=0;j<len;j++)
			{
				if(adj[i][j]==1)
				{
					fout<<","<<v->findKey(j);
				}
			}
			fout<<")"<<" ";
		}
		fout<<endl;
	}
	
};



int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n,m;
	string tipo,arco;
	
	for(int task=0;task<100;task++)
	{
		fin>>n;
		fin>>m;
		fin>>tipo;
		
		if(tipo=="int")
		{
			Grafo<int>* g=new Grafo<int>(n);
			int* v=new int[n];
			for(int i=0;i<n;i++)
			{
				fin>>v[i];
			}
			g->insNodo(v);
			for(int i=0;i<m;i++)
			{
				fin>>arco;
				int x=atoi(arco.substr(1,arco.find(',')-1).c_str());
				int y=atoi(arco.substr(arco.find(',')+1,arco.find(')')-arco.find(',')+1).c_str());
				g->insArco(x,y);
			}
			g->stampa(fout);
		}
		
		if(tipo=="double")
		{
			Grafo<double>* g=new Grafo<double>(n);
			double* v=new double[n];
			for(int i=0;i<n;i++)
			{
				fin>>v[i];
			}
			g->insNodo(v);
			for(int i=0;i<m;i++)
			{
				fin>>arco;
				double x=atof(arco.substr(1,arco.find(',')-1).c_str());
				double y=atof(arco.substr(arco.find(',')+1,arco.find(')')-arco.find(',')+1).c_str());
				g->insArco(x,y);
			}
			g->stampa(fout);
		}
		
		if(tipo=="char")
		{
			Grafo<char>* g=new Grafo<char>(n);
			char* v=new char[n];
			for(int i=0;i<n;i++)
			{
				fin>>v[i];
			}
			g->insNodo(v);
			for(int i=0;i<m;i++)
			{
				fin>>arco;
				char x=arco[1];
				char y=arco[3];
				g->insArco(x,y);
			}
			g->stampa(fout);
		}
	}
	fin.close();
	fout.close();	
}