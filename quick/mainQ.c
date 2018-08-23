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
		
	}
	fclose(p);
	
}
void listar(int vet[],int n){
	int i;
	for(i = 0 ; i<n;i++){
		printf("%d", vet[i]);
		
	}
	
	
}
void quickSort(int *vetor, int inicio, int fim)
{
   int i, j, meio, aux;

   i = inicio;
   j = fim;
   meio = vetor[(inicio + fim) / 2];

   do
   {
      while(vetor[i] < meio)
         i++;
      while(vetor[j] > meio)
         j--;
      if(i <= j)
      {
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i++;
         j--;
      }
   }while(i <= j);

   if(inicio < j)
      quickSort(vetor, inicio, j);
   if(i < fim)
      quickSort(vetor, i, fim);
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
    
    quickSort(vet,0,n);    
    tempoFinal = clock();

    double tempoGasto = (tempoFinal-tempoInicial) * 1000.0/CLOCKS_PER_SEC;
    vetTempo[i] = tempoGasto;
   printf("Tempo em segundos: %f", tempoGasto);
   	printf("Nome do arquivo pra salvar: ");
	scanf("%s",&noS);
	gT(tempoGasto );
   g(vet,n,a,noS);
   g(vet,n,a,noS);
}
	
   
}
