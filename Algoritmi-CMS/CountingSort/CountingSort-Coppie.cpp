#include<fstream>
#include<sstream>

using namespace std;

class Coppia{
    private:
        int a;
        double b;
    public:
        Coppia(int val1, double val2): a(val1), b(val2){}

        int getA() {return a;}
        double getB() {return b;}
};

int* countingSort(Coppia** A, int N, int& k){
    int max = A[0]->getA();
    int min = A[0]->getA();
    for(int i = 0; i < N; i++){
        if(A[i]->getA() > max) max = A[i]->getA();
        if(A[i]->getA() < min) min = A[i]->getA();
    }
    k = max - min + 1;
    int* C = new int[k];
    for(int i = 0; i < k; i++) C[i] = 0;
    for(int i = 0; i < N; i++) C[A[i]->getA() - min]++;
    for(int i = 1; i < k; i++) C[i] += C[i-1];

    Coppia** B = new Coppia*[N];
    for(int i = N-1; i >= 0; i--) B[(C[A[i]->getA() - min]--) - 1] = A[i];

    for(int i = 0; i < N; i++) A[i] = B[i];
    return C;
}

void print(ostream& out, int* C, int k, Coppia** A, int N){
    for(int i = 0; i < k; i++) out << C[i] << " ";
    for(int i = 0; i < N; i++) out << "(" <<((double) A[i]->getA())/10 << " " << A[i]->getB() << ") ";
    out << endl;                        //(istruzione esattamente sopra) ricordarsi di convertire uno dei due membri in double e dopo effettuare la divisione
}
int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Coppia** A = new Coppia*[N];
        for(int j = 0; j < N; j++){
            double a, b;
            string tmp1, tmp2;
            in >> tmp1 >> tmp2;
            stringstream(tmp1.substr(1)) >> a;
            stringstream(tmp2.substr(0, tmp2.length()-1)) >> b;
            A[j] = new Coppia(a * 10 + 0.5, b);                     //ricordare + 0.5 per effettuare una corretta conversione che altrimenti avverrebbe per difetto.
        }
        int k;
        int* C = countingSort(A, N, k);
        print(out, C, k, A, N);
    }
    return 0;
}