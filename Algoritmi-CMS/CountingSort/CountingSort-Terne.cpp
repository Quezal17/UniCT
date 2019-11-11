#include<fstream>
#include<sstream>

using namespace std;

class Terna{
    private:
        int a;
        double b;
        double c;
    public:
        Terna(int val1, double val2, double val3): a(val1), b(val2), c(val3){}

        int getA() {return a;}
        double getB() {return b;}
        double getC() {return c;}
};

int* countingSort(Terna** A, int N, int& k){
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

    Terna** B = new Terna*[N];
    for(int i = N-1; i >= 0; i--) B[(C[A[i]->getA() - min]--) - 1] = A[i];

    for(int i = 0; i < N; i++) A[i] = B[i];
    return C;
}

void print(ostream& out, int* C, int k, Terna** A, int N){
    for(int i = 0; i < k; i++) out << C[i] << " ";
    for(int i = 0; i < N; i++) out << "(" <<((double) A[i]->getA())/10 << " " << A[i]->getB() << " " << A[i]->getC() << ") ";
    out << endl;
}
int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Terna** A = new Terna*[N];
        for(int j = 0; j < N; j++){
            double a, b, c;
            string tmp1, tmp2, tmp3;
            in >> tmp1 >> tmp2 >> tmp3;
            stringstream(tmp1.substr(1)) >> a;
            stringstream(tmp2) >> b;
            stringstream(tmp3.substr(0, tmp3.length()-1)) >> c;
            A[j] = new Terna(a * 10 + 0.5, b, c);
        }
        int k;
        int* C = countingSort(A, N, k);
        print(out, C, k, A, N);
    }
    return 0;
}