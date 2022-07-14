#include <stdio.h>
#include <stdlib.h>

void Heapify(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while(j <= f){
        if(j < f){
            if(vet[j] < vet[j + 1]){//Pai tem 2 filhos? Quem é o maior?
                j = j + 1;
            }
        }
        if(aux <vet[j]){//Filho maior que o pai?
            vet[i] = vet[j];//Filho se torna o pai.
            i = j;
            j = 2 *i + 1;
        }//Continuará repetindo o processo.
        else{
            j = f + 1;
        }
    }
    vet[i] = aux;//O antigo pai ocupa o lugar do último filho analisado.
}

void heapSort(int *vet, int N){
    int i, aux;
    for(i=(N - 1)/2; i >= 0; i--){//Criação do heap a partir dos dados do vetor
        Heapify(vet, i, N-1);
    }

    for(i = N - 1;i >= 1; i--){
        aux = vet[0];
        vet [0] = vet [i];//Pega o maior elemento do heap. Coloca na sua posição correspondente no array.
        vet [i] = aux;
        Heapify(vet,0, i - 1);//Reconstrução do heap
    }
}

int main(void)
{
    int vet[] = {1,3,4,5,2};//Criação do vetor
    int n = sizeof(vet) / sizeof(vet[0]);//n adota o tamanho atual do vetor

    heapSort(vet, n);//Será feita a ordenação do heap e todos os elementos do vetor vet.

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);//Imprimindo o vetor ordenado com HeapSort.
    }

    return 0;
}
