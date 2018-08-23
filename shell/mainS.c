#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void g(int vetor[], int n , int a,char nome[]) // parte 1
{
	int i;
	FILE *arq;
	
	arq= fopen(nome, "w"); // criando , abrindo "w" é escreva no arquivo	
	
	fprintf(arq," %d  %d \n " ,n,a);
	
	for(i=0; i<n; i++)
	 fprintf(arq,"%d ",vetor[i]);
	
	fclose(arq); // fechando
}
void gT(double v) // parte 1
{
	int i;
	FILE *arq;
	
	arq= fopen("TempoGasto.dat", "a"); // criando , abrindo "w" é escreva no arquivo	
	
//	fprintf(arq," %d   \n " ,n);
	

	 fprintf(arq,"\n%f ",v);
	
	fclose(arq); // fechando
}
void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}
void ler(FILE *p ,int vet[], int n){
	int i ;
	for(i = 0;i<n;i++){
		fscanf(p,"%d",&vet[i]);
		
	}
	fclose(p);
	
}
void listar(int vet[],int n){
	int i;
	for(i = 0 ; i<n;i++){
		printf("%d", vet[i]);
		
	}
	
	
}
int main(){
	FILE *p ;
	int n , a,i;
	char nome[100],noS[100];
	double vetTempo[11];
	for(i = 0; i<11;i++){
	   	printf("Nome do arquivo: ");
	   	scanf("%s",&nome);
		p = fopen(nome, "r");
		fscanf(p, "%d %d", &n,&a);
		int vet[n];
		ler(p,vet,n);
		clock_t tempoInicial, tempoFinal;
	
	   
   	
   	
  
    tempoInicial = clock();
    
    shellSort(vet,n);
    
    
     tempoFinal = clock();

    double tempoGasto = (tempoFinal-tempoInicial) * 1000.0/CLOCKS_PER_SEC;
    vetTempo[i] = tempoGasto;
   printf("Tempo em segundos: %f", tempoGasto);
   	printf("Nome do arquivo pra salvar: ");
	scanf("%s",&noS);
	gT(tempoGasto );
   g(vet,n,a,noS);
}
	
}
