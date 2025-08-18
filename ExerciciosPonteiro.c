// Exercício 3: função para trocar valores apontados (passagem por referência)
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Exercício 1: declarar um inteiro, um ponteiro para ele e alterar via ponteiro
void exercicio1(void) {
    int valor = 10;          // inteiro
    int *p = &valor;         // ponteiro para o inteiro

    printf("Exercício 1\n");
    printf("Valor inicial: %d\n", valor);

    *p = 42; // altera o valor do inteiro usando o ponteiro

    printf("Valor alterado via ponteiro: %d\n\n", valor);
}

// Exercício 2: array de 5 inteiros e aritmética de ponteiros
void exercicio2(void) {
    int v[5] = {10, 20, 30, 40, 50};
    int *p = v; // v decai para &v[0]

    printf("Exercício 2\n");
    for (int i = 0; i < 5; i++) {
        // *(p + i) acessa o i-ésimo elemento via aritmética de ponteiros
        printf("Elemento %d: %d\n", i, *(p + i));
    }
    printf("\n");
}

// Exercício 3: demonstrar a troca usando dois ponteiros para inteiros
void exercicio3(void) {
    int a = 7, b = 13;
    printf("Exercício 3\n");
    printf("Antes da troca: a = %d, b = %d\n", a, b);

    swap(&a, &b); // passa os endereços (ponteiros) para trocar por referência

    printf("Depois da troca: a = %d, b = %d\n\n", a, b);
}

int main(void) {
    exercicio1();
    exercicio2();
    exercicio3();
    return 0;
}

