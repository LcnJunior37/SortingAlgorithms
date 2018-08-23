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

void bubble_sort ( int vetor [ ] ,  int indice ) 
{
    int a,b, auxiliar;
    for ( a = indice - 1 ; a > 0; a-- ) 
	{
        for ( b=0; b < a; b++ ) 
		{
            if ( vetor [ b ] > vetor [ b + 1 ] ) 
			{
            	auxiliar = vetor [ b ];
            	vetor [ b ] = vetor[ b+1 ];
            	vetor[ b+1 ] = auxiliar;
            }
        }
    }
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
void gT(double vetor, int n ) // parte 1
{
	int i;
	FILE *arq;
	
	arq= fopen("TempoGasto.dat", "a"); // criando , abrindo "w" é escreva no arquivo	
	
//	fprintf(arq," %d   \n " ,n);
	
	 fprintf(arq,"\n%f ",vetor);
	
	fclose(arq); // fechando
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
    
    
    bubble_sort(vet,n);
    
      tempoFinal = clock();

    double tempoGasto = (tempoFinal-tempoInicial) * 1000.0/CLOCKS_PER_SEC;
    vetTempo[i] = tempoGasto;
   printf("Tempo em segundos: %f", tempoGasto);
   	printf("Nome do arquivo pra salvar: ");
	scanf("%s",&noS);
   g(vet,n,a,noS);
   gT(tempoGasto ,11);
}
	
   
}
