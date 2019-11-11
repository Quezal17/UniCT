/*
    Viene considerata una tabella con numero di righe = all'ultimo tempo di fine e colonne = al numero di attività. L'algoritmo considera le righe come lo scorrere del tempo per le attività
    mentre le colonne come le attività stesse. Il passo consiste nel considerare la cella precedente se il tempo è minore del tempo di fine dell'attività analizzata correntemente, altrimenti
    viene considerato il massimo trà la cella precedente a sinistra e la cella di riga corrispondente al tempo di inizio dell'attività precedente + la durata dell'attività corrente.
*/
#include<fstream>
#include<iostream>
#include<cstdlib>

using namespace std;

class Activity{
    private:
        int inizio;
        int fine;
        int durata;
    public:
        Activity(int i, int f):inizio(i), fine(f), durata(f-i){}

        int getInizio(){return inizio;}
        int getFine(){return fine;}
        int getDurata(){return durata;}
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

int soluzione(Activity** A, int N){
    selectionSort(A, N);

    int tempoMax = A[N-1]->getFine()+1;
    int** table = new int*[tempoMax];
    for(int i = 0; i < tempoMax; i++) table[i] = new int[N+1];
    for(int i = 0; i < tempoMax; i++) table[i][0] = 0;
    for(int i = 0; i <= N; i++) table[0][i] = 0;

    for( int i = 1; i < tempoMax; i++)
        for(int j = 1; j <= N; j++)
            if(i < A[j-1]->getFine()) table[i][j] = table[i][j-1];
            else table[i][j] = max(table[i][j-1], table[A[j-1]->getInizio()][j-1] + A[j-1]->getDurata());

    return table[tempoMax - 1][N];
}

int main(){
    const int DIM = 3;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Activity** A = new Activity*[N];
        for(int j = 0; j < N; j++){
            int a, b;
            string s1, s2;
            in >> s1 >> s2;
            a=atoi(s1.substr(1).c_str());
            b=atoi(s2.substr(0,s2.length()-1).c_str());
            A[j] = new Activity(a, b);
        }
        out << soluzione(A, N) << endl;
    }
    return 0;
}
