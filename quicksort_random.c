#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

// função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo) // 2,3,7,5,4
		{
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

int main()
{
	int vet[N];
  float memoria = sizeof(vetor) / (1024.0 * 1024.0); // calcula +- o uso de memoria em mb

    // funcao pra gerar numeros aleatorios a cada execucao
    srand(time(NULL));

    // preenche o vetor com numeros aleatorios de 1 ate 100
    for (int i = 0; i < N; i++) {
        vet[i] = rand() % 101;
    }
	 
	// conta tempo de execucao
    printf("iniciando...\n");
    clock_t comeco = clock();
    
	  quick_sort(vet, 0, N - 1);
	
    clock_t fim = clock();
    double tempo = (double)(fim - comeco) / CLOCKS_PER_SEC; // retorna tempo em segundos
    printf("finalizado!\n");

    printf("Tempo de execucao: %fs\n", tempo);
    printf("Memoria utilizada: %.3fmb\n", memoria);

	// mostra o vetor ordenado
	for(int i = 0; i < N; i++)
		printf("%d ", vet[i]);
	
	return 0; 
}
