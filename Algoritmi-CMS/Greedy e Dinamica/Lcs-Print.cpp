#include<fstream>
#include<string>
#include<iostream>

using namespace std;

int** lcs(string a, int N, string b, int M){
    int** m = new int*[N+1];
    for( int i = 0; i <= N; i++) m[i] = new int[M+1];

    for(int i = 0; i <= N; i++)
        for( int j = 0; j <= M; j++){
            if(i == 0 || j == 0) m[i][j]=0;
            else if(a[i-1] == b[j-1]) m[i][j] = m[i-1][j-1] + 1;
            else m[i][j] = max(m[i][j-1], m[i-1][j]);
        }
    return m;
}

string print_LCS(string X, string Y, int** C, int i, int j){
   string s = "";
    while(i!=0 && j!=0){
        if(X[i-1] == Y[j-1]){
            s = X[i-1] + s;
            i--;
            j--;
        }
        else if(C[i][j-1] >= C[i-1][j]) j--;
        else i--;
    }
    return s;
}

int main(){
    const int DIM = 1;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0, M = 0;
    string s1 = "", s2 = "";
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> s1 >> s2;
        s1=print_LCS(s1, s2, lcs(s1, N, s2, M), N, M);        //si parte dalla cella del valore finale in m[N][M]
        out << s1 << endl;
    }
    return 0;
}
