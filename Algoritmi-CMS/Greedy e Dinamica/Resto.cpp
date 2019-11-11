#include<fstream>

using namespace std;

int numMonete(int* m, int N, int R){
    int* resti = new int[R+1];
    resti[0] = 0;
    for(int i = 1; i <= R; i++) resti[i] = R+1;

    for(int i = 1; i <= R; i++)
        for(int j = 0; j < N; j++)
            if(i >= m[j]) resti[i] = min(resti[i], resti[i-m[j]] + 1);

    return resti[R];
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int R = 0, N = 0;
    for(int i = 0; i < DIM; i++){
        in >> R >> N;
        int monete[N] = {0};
        for(int j = 0; j < N; j++) in >> monete[j];
        out << numMonete(monete, N, R) << endl;
    }
    return 0;
}
