#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 8

void selection_sort(int* vetor)
{
    int i,j, menor;
    for (i = 0; i < N - 1; i++) {
        menor = i; //marca indice do menor elemento
        for (j = i + 1; j < N; j++) { // troca se achar um novo elemento menor que o anterior
            if(vetor[j] < vetor[menor])
                menor = j;
        }

      //realiza troca
        int tmp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = tmp;
    }
}

int main()
{
    int vetor[N];
    float memoria = sizeof(vetor) / (1024.0 * 1024.0); // memoria em MB
    srand(time(NULL)); //funcao pra gerar num aleatorios a cada execucao

    //preenche o vetor com numeros aleatorios de 0 a 100
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 101;
    }
    
    // conta tempo de execucao
    printf("iniciando...\n");
    clock_t comeco = clock();
	
	  selection_sort(vetor);
	
    clock_t fim = clock();
    double tempo = (double)(fim - comeco) / CLOCKS_PER_SEC; // retorna tempo em segundos
    printf("finalizado!\n");

    printf("Tempo de execucao: %fs\n", tempo);
    printf("Memoria utilizada: %.3fmb\n", memoria);
    
    //imprimir vetor
    for (int g = 0; g < N; g++) {
        printf("%d ", vetor[g]);
    }

    return 0;
}
