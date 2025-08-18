#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *proximo;
    struct elemento *anterior;
} Elemento;

Elemento * criar_lista(void) {
    return NULL;
}

Elemento * inserirElemento(Elemento *lista, int valor) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro: Memória insuficiente\n");
        return lista;
    }
    
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    
    // Se a lista estiver vazia
    if (lista == NULL) {
        printf("Inserido: %d\n", valor);
        return novo;
    }
    
    // Inserir no início da lista
    novo->proximo = lista;
    lista->anterior = novo;
    printf("Inserido: %d\n", valor);   
    return novo;
}

void imprimir_lista(Elemento *lista) {
    Elemento *atual = lista;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberar_lista(Elemento *lista) {
    Elemento *atual = lista;
    while (atual != NULL) {
        Elemento *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Exercicio 01: Implemente uma função que retorne um elemento específico da lista utilizando a lista abaixo:

Elemento* busca(Elemento* lista, int valor) {
    Elemento* atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

/* Exercicio 02: Implemente uma função que percorra a lista encadeada e encontre o maior elemento da lista
 utilizando a lista abaixo: */

int lista_maior(Elemento *lista) {
    if (lista == NULL) return -1;
    int maior = lista->valor;
    Elemento* atual = lista->proximo;
    while (atual != NULL) {
        if (atual->valor > maior) {
            maior = atual->valor;
        }
        atual = atual->proximo;
    }
    return maior;
}

//Exercicio 03: Considerando o exemplo anterior, implemente uma função que retorne a posição do elemento buscado
int busca_posicao(Elemento *lista, int valor) {
    int pos = 0;
    Elemento* atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1;
}

//  
// Exercicio 04: Implemente uma função que insira um novo elemento no final da lista encadeada.
Elemento* lista_insere_valorFinal(Elemento *lista, int valor) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro: Memória insuficiente\n");
        return lista;
    }
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (lista == NULL) {
        return novo;
    }

    Elemento *atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;
    return lista;
}
// Exercicio 05: Considere uma lista encadeada contendo números inteiros positivos, faça uma função que retorne a quantidade de números pares dessa lista.

int quantidade_pares(Elemento *lista) {
    int cont = 0;
    Elemento *atual = lista;
    while (atual != NULL) {
        if (atual->valor % 2 == 0) {
            cont++;
        }
        atual = atual->proximo;
    }
    return cont;
}

// Exercicio 06: Considerando o exercício anterior, faça uma função que retorne a média dessa nova lista, considerando somente números pares.

float media_pares(Elemento *lista) {
    int soma = 0, cont = 0;
    Elemento *atual = lista;
    while (atual != NULL) {
        if (atual->valor % 2 == 0) {
            soma += atual->valor;
            cont++;
        }
        atual = atual->proximo;
    }
    if (cont == 0) return 0.0f;
    return (float)soma / cont;
}

int main() {
    Elemento *lista = criar_lista();
    
    lista = inserirElemento(lista, 10);
    lista = inserirElemento(lista, 20);
    lista = inserirElemento(lista, 30);

    imprimir_lista(lista);

    Elemento *encontrado = busca(lista, 20);
    if (encontrado)
        printf("Elemento 20: %d (ponteiro: %p)\n", encontrado->valor, (void*)encontrado);
    else
        printf("Elemento 20 Não encontrado (ponteiro: %p)\n", (void*)encontrado);

    int maior = lista_maior(lista);
    printf("O Maior da lista: %d\n", maior);

    int pos = busca_posicao(lista, 10);
    printf("Posição do elemento 10: %d\n", pos);

    lista = lista_insere_valorFinal(lista, 40);
    printf("Após inserir no final (ponteiro da lista): %p\n", (void*)lista);
    imprimir_lista(lista);

    int pares = quantidade_pares(lista);
    printf("Pares: %d\n", pares);

    float media = media_pares(lista);
    printf("Média dos pares: %.2f\n", media);

    liberar_lista(lista);

    return 0;
}

/*
Inserido: 10
Inserido: 20
Inserido: 30
Lista: 30 20 10
Elemento 20: 20 (ponteiro: 000001d8f8ef4990)
O Maior da lista: 30
Posição do elemento 10: 2
Após inserir no final (ponteiro da lista): 000001d8f8ef49e0
Lista: 30 20 10 40
Pares: 4
*/