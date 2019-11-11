#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int minimo(int a, int b, int c)
{
    int min=a;
    if(b<min) min=b;
    if(c<min) min=c;
    return min;
}

int editLength(string a, string b, int N, int M){
    int** table = new int*[N+1];
    for(int i = 0; i <= N; i++){
        table[i] = new int[M+1];
        table[0][i] = table[i][0] = i;
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i-1] == b[j-1]) table[i][j] = table[i-1][j-1];
            else table[i][j] = minimo(table[i][j-1], table[i-1][j-1], table[i-1][j]) + 1;

    return table[N][M];
}

int main(){
    const int DIM = 1;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0; int M = 0;
    string s1 = "", s2 = "";
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> s1 >> s2;
        out << editLength(s1, s2, N, M) << endl;
    }
}
