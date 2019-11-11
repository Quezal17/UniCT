#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Matrice{
    private:
        int righe, colonne;
    public:
        Matrice(): righe(0), colonne(0){}

        int getCol(){ return colonne; }
        int getRig(){ return righe; }
        void setCol(int c){ colonne = c; }
        void setRig(int r){ righe = r; }
};

int matrixChainOrder(Matrice* m, int N){
    int matrix[N][N];

    for(int i = 0; i < N; i++) matrix[i][i] = 0;

    for(int l = 2; l <= N; l++){
        for(int i = 0; i <= N - l; i++){
            int j = i + l - 1;
            matrix[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                    int q = matrix[i][k] + matrix[k+1][j] + (m[i].getRig() * m[k].getCol() * m[j].getCol());
                    if( q < matrix[i][j])   matrix[i][j] = q;
            }
        }
    }
    return matrix[0][N-1];
}

int main(){
    const int DIM = 3;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Matrice* m = new Matrice[N];
        for(int j = 0; j < N; j++){
            int r,c;
            string s;
            in >> s;
            r=atoi(s.substr(1,s.find('x')).c_str());
            m[j].setRig(r);
            c=atoi(s.substr(s.find('x')+1,s.length()-1-s.find('x')).c_str());
            m[j].setCol(c);
        }
        out << matrixChainOrder(m, N) << endl;
        delete[] m;
    }
    return 0;
}
