#include<stdio.h>
void qs(int arr[], int limiz, int limder){
        int izq, der, temporal, pivote;
        izq=limiz;
        der=limder;
        pivote=arr[(izq+der)/2];
        do{
                while(arr[izq]<pivote && izq<limder) izq++;
                while(arr[der]>pivote && der>limiz) der--;
                if(izq<=der){
                        temporal=arr[izq];
                        arr[izq]=arr[der];
                        arr[der]=temporal;
                        izq++;
                        der--;
                }

        }while(izq<=der);
        if(limiz<der){qs(arr,limiz,der);}
        if(limder>izq){qs(arr,izq,limder);}
}

void quicksort(int arr[], int n){
        qs(arr,0, n-1);

}
int main(){
	int i=0, N, K,j,t,s=0;
	scanf("%d%d",&N,&K);
	int C[N];
	int C2[N-K+1];
	for(i=0;i<N;i++) scanf("%d",&C[i]);

        int size=sizeof(C)/sizeof(*C);
	quicksort(C,size);
	for(i=0;i<N-K+1;i++){
		s=C[i+K-1]-C[i];
		C2[i]=s;
		s=0;
	}	
			
        size=sizeof(C2)/sizeof(*C2);

	quicksort(C2,size);
	printf("%d\n",C2[0]);
return 0;
}

