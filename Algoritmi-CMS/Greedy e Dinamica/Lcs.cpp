#include<fstream>

using namespace std;

//IMPORTANTE: fare array dinamico, altrimenti va in crash causa stack pieno.
int LCS(string X, string Y, int N, int M){
    int** C = new int*[N+1];
    for(int i = 0; i <= N; i++) C[i] = new int[M+1];
           
     for(int i = 0; i <= N; i++)
         for(int j = 0; j <= M; j++){
            if(i == 0 || j == 0) C[i][j] = 0;
            else if(X[i-1] == Y[j-1]) C[i][j] = C[i-1][j-1]+1;
            else C[i][j] = max(C[i][j-1], C[i-1][j]);
         }

    return C[N][M];
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0, M = 0;
    string s1 = "", s2 = "";
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> s1 >> s2;
        out << LCS(s1, s2, N, M) << endl;
    }
    return 0;
}
