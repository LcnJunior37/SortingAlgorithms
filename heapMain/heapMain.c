#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void g(int vetor[], int n , int a,char nome[]) // parte 1
{
	int i;
	FILE *arq;
	
	arq= fopen(nome, "w"); // criando , abrindo "w" � escreva no arquivo	
	
	fprintf(arq," %d  %d \n " ,n,a);
	
	for(i=0; i<n; i++)
	 fprintf(arq,"%d ",vetor[i]);
	
	fclose(arq); // fechando
}
void gT(double vetor, int n ) // parte 1
{
	int i;
	FILE *arq;
	
	arq= fopen("TempoGasto.dat", "a"); // criando , abrindo "w" � escreva no arquivo	
	
//	fprintf(arq," %d   \n " ,n);
	
	
	 fprintf(arq,"\n%f ",vetor);
	
	fclose(arq); // fechando
}
void criaHeap(int vet[], int i, int fim)  // função recebe  o vetor seu inicio e seu fim
{
    int aux = vet[i]; // consideramos um valor auxiliar como a posição da partição i que é o pai
    int j = i*2+1; // aqui calculamos seu primeiro filho j
    while(j<=fim) // comparamos para ver se o filho é menor que o final do vetor
    {
        if(j< fim)
        {
            if (vet[j]<vet[j+1]) // comparação dos dois filhos para saber quem é o maior
            {
                j = j+1;
            }
                                   
        }
        if(aux<vet[j]) // comparamos agora o aux que é o pai com o filho para saber quem é maior
        {                                     //se o pai for menor que o filho entao
            vet[i] = vet[j];
            i=j;  // o j se torna o novo pai
            j= 2*i+1; // calcula o novo filho dele
        }
        else
        {
            j=fim+1;  // o pai continua no msm lugar
        }
    }
    vet[i] = aux;
}
  
void heapSort (int vet[], int tam)
{
    int aux,i;
    for (i=((tam-1)/2);i>=0;i--)  // cria  heap com metade do vetor
   	{
        criaHeap(vet,i,tam-1);
    }
        for (i=tam-1; i >= 0; i--)  // pega o maior elemento e coloca ultima posição do vetor(topo da arvore
        {
            aux=vet[0];
            vet[0]=vet[i];
            vet[i]=aux;
            criaHeap(vet,0,i-1); 
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
    
    
    heapSort(vet,n);
    
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
