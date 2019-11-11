//InsertionSort
int insertionSort(int *v,int dim)
{
    int nswap=0;
    for(int i=1;i<dim;i++)
    {
        int j=i-1;
        while(j>=0 && v[j]>v[j+1])
        {
            int temp=v[j];
            v[j]=v[j+1];
            v[j+1]=temp;

            nswap++;
            j--;
        }
    }
    return nswap;
}

//SelectionSort (stabile)
int findMin(int *v,int i,int dim)
{ 
	int pos=i;
    for(int j=i+1;j<dim;j++)
    {
        if(v[j]<v[pos])
            pos=j;
    }
    int minimo=v[pos];
    for(int j=pos-1;j>=i;j--)
        v[j+1]=v[j];
    return minimo;
}
void selectionSort(int *v,int dim)
{
    int minimo;
    for(int i=0;i<dim-1;i++)
    {
        minimo=findMin(v,i,dim);
        v[i]=minimo;
    }
}
//(non stabile)
int selectionSort(int *v,int dim)
{
    int minimo,temp;
    int somma=0;
    for(int i=0;i<dim-1;i++)
    {
        minimo=i;
        for(int j=i+1;j<dim;j++)
        {
            if(v[j]<v[minimo])
                minimo=j;
        }
        temp=v[minimo];
        v[minimo]=v[i];
        v[i]=temp;
        somma+=minimo-i;
    }
    return somma;
}

//BubbleSort
void bubblesort(int *v, int n)
{
	int i,k;
	int temp;
	for(i = 0; i<n-1; i++)
		for(k = 0; k<n-1-i; k++)
			if(v[k] > v[k+1]) 
				scambia(v,k,k+1);
}

//MergeSort (2 a sinistra, 3 a destra)
void natural_merge(int *a, int n, int *b, int m, int *c)
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<n) c[k++]=a[i++];
    while(j<m) c[k++]=b[j++];
}
void mergeSort(int *v, int n)
{
    if(n==1) return;
    int j=n/2-1;
    mergeSort(v,j+1);
    mergeSort(v+j+1,n-j-1);
    int *c=new int[n];
    natural_merge(v,j+1,v+j+1,n-j-1,c);
    for(int i=0;i<n;i++)
        v[i]=c[i];
}
//(3 a sinistra, 2 a destra)
int somma;
void merge(int *v, int inizio, int centro, int fine) {
	int *b=new int[fine+1];
	int h = inizio;
	int i = inizio;
	int j = centro+1;
	while( (h<=centro) && (j<=fine) ) {
		if( v[h] <= v[j] ) b[i] = v[h++];
		else b[i] = v[j++];
  		i++;
	}
 	if(h>centro)
  		for(int k=j; k<=fine; k++) b[i++]=v[k];
 	else
		for(int k=h; k<=centro; k++) b[i++]=v[k];
 	for(int k=inizio; k<=fine; k++) v[k]=b[k];
}
void mergeSort(int *v, int inizio, int fine)
{
	if( inizio<fine )
    {
		int centro = (inizio+fine)/2;
        somma+=v[inizio];
		mergeSort( v, inizio, centro);
		mergeSort( v, centro+1, fine);
		merge( v, inizio, centro, fine );
 	}
}

//QuickSort
int partizione(int *v,int b,int e)
{
    int i=b-1,j=e+1;
    int p=v[b];
    while(1)
    {
        do{i++;}while(v[i]<p);
        do{j--;}while(v[j]>p);
        if(i<j)
            scambia(v,i,j);
        else
            return j;
    }
}
void quickSort(int *v,int b,int e)
{
    if(b>=e)
        return;
    int j=partizione(v,b,e);
    quickSort(v,b,j);
    quickSort(v,j+1,e);
}
