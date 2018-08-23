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
void ler(FILE *p ,int vet[], int n){
	int i ;
	for(i = 0;i<n;i++){
		fscanf(p,"%d",&vet[i]);
		//printf(" %d ",vet[i]);
		
	}
	fclose(p);
	
}
void listar(int vet[],int n){
	int i;
	for(i = 0 ; i<n;i++){
		printf("%d", vet[i]);
		
	}
	
	
}
int separaVetor(int vet[], int inicio, int fim)
{
	int aux, i;
	int cont = inicio - 1;
	
	for(i=inicio;i<fim;i++)
	{
		if(vet[i]<=vet[fim])
		{
			cont++;
			aux = vet[i];
			vet[i] = vet[cont];
			vet[cont] = aux;
			
		}
	}
	aux = vet[cont+1];
	vet[cont+1] = vet[fim];
	vet[fim] = aux;
	
	return cont+1;
}

void merge(int vet[], int inicio, int fim)
{
	int pivo;
	
	if (inicio<fim)
	{
		pivo = separaVetor(vet,inicio,fim);
		merge(vet,inicio,pivo-1);
		merge(vet,pivo+1,fim);
	}
}
void salvaT(float tem){
	FILE *t ;
     t = fopen("TempoMerge.dat","w");
     fprintf(t,"%f",tem);
     fclose(t);
}
int main(){
	clock_t tempoInicial, tempoFinal;
   
   
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
    
    merge(vet,0,n);   
    tempoFinal = clock();

    double tempoGasto = (tempoFinal-tempoInicial) * 1000.0/CLOCKS_PER_SEC;
    vetTempo[i] = tempoGasto;
   printf("Tempo em segundos: %f", tempoGasto);
   	printf("\nNome do arquivo pra salvar: ");
   	gT(tempoGasto );
	scanf("%s",&noS);
   g(vet,n,a,noS);
}

   
}
