//Gabriel Rafá Martins Freire 20230145310
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void selectionSort(int vetor[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (vetor[j] < vetor[min_idx])
                min_idx = j;

        temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printVetor(int arr[], int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo;
    char nomedoarquivo[100];
    int arr[1000], n = 0, escolha, i;

    // Prompt for the input file name
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomedoarquivo);

    // Open the file
    arquivo = fopen(nomedoarquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nomedoarquivo);
        return 1;
    }

    // Read the numbers from the file
    while (fscanf(arquivo, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(arquivo);

    // Ask the user which sorting algorithm to use
    printf("Escolha o algoritmo de ordenação:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("Digite sua escolha (1 ou 2): ");
    scanf("%d", &escolha);

    // Perform the sorting based on user choice
    if (escolha == 1) {
        selectionSort(arr, n);
        printf("Vetor ordenado com Selection Sort:\n");
    } else if (escolha == 2) {
        insertionSort(arr, n);
        printf("Vetor ordenado com Insertion Sort:\n");
    } else {
        printf("Escolha inválida\n");
        return 1;
    }

    // Print the sorted array
    printVetor(arr, n);

    return 0;
}
