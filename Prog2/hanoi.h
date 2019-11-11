#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int conta;

void hanoi(int n, int A, int B, int C, ofstream& fout, int mossa){
    //A = sorgente
    //B = destinazione
    //C = appoggio

    if(n==1){
            conta++;
            if(mossa==conta)
            {
                fout<<A<<" "<<B<<endl;
            }
        cout << " Sposta un disco da " << A << " in " << B << endl;
        return;
    }
    hanoi(n-1, A, C, B,fout,mossa);
    hanoi(1, A, B, C,fout,mossa);
    hanoi(n-1, C, B, A,fout,mossa);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	int mossa;
	int passi;
	for (int task = 0; task < 100; task++)
	{
		fin >> n;
		fin >> mossa;
		conta=0;
		hanoi(n, 1, 3, 2, fout, mossa);
	}
	fin.close();
	fout.close();
}