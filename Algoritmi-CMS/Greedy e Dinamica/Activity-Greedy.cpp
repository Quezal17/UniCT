#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Activity{
    private:
        int inizio;
        int fine;
    public:
        Activity(int i, int f) : inizio(i), fine(f){}
        int getInizio(){ return inizio;}
        int getFine(){ return fine; }
};

void selectionSort(Activity** A, int N)
{
    int min;
    for(int i=0;i<N-1;i++)
    {
        min=i;
        for(int j=i+1;j<N;j++)
        {
            if(A[j]->getFine()<A[min]->getFine())
                min=j;
        }
        Activity* temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}

int maxActivities(Activity** A, int N){
    selectionSort(A, N);
    int count = 1, end = A[0]->getFine();
    for(int i = 1; i < N; i++){
        if(A[i]->getInizio() >= end){
            count++;
            end = A[i]->getFine();
        }
    }
    return count;
}

int main(){
    const int DIM = 3;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Activity** V = new Activity*[N];
        for(int j = 0; j < N; j++){
            string tmp1, tmp2;
            in >> tmp1 >> tmp2;
            int a, b;
            a=atoi(tmp1.substr(1).c_str());
            b=atoi(tmp2.substr(0,tmp2.length()-1).c_str());
            V[j] = new Activity(a, b);
        }

        out << maxActivities(V, N) << endl;

        delete[] V;
    }
return 0;
}
