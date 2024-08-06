#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Pilha {
    int itens[MAX];
    int topo;
};

struct Fila {
    int itens[MAX];
    int frente, tras;
};

void inicializarPilha(struct Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(struct Pilha *p) {
    return p->topo == -1;
}

void empilhar(struct Pilha *p, int valor) {
    p->itens[++(p->topo)] = valor;
}

int desempilhar(struct Pilha *p) {
    return p->itens[(p->topo)--];
}

void inicializarFila(struct Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int filaVazia(struct Fila *f) {
    return f->frente == f->tras;
}

void enfileirar(struct Fila *f, int valor) {
    f->itens[f->tras++] = valor;
}

int desenfileirar(struct Fila *f) {
    return f->itens[f->frente++];
}

void inverterFila(struct Fila *f) {
    struct Pilha p;
    inicializarPilha(&p);

    while (!filaVazia(f)) {
        empilhar(&p, desenfileirar(f));
    }

    while (!pilhaVazia(&p)) {
        enfileirar(f, desempilhar(&p));
    }
}

void imprimirFila(struct Fila *f) {
    for (int i = f->frente; i < f->tras; i++) {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}

int main() {
    struct Fila f;
    inicializarFila(&f);
    enfileirar(&f, 5);
    enfileirar(&f, 4);
    enfileirar(&f, 3);
    enfileirar(&f, 2);
    enfileirar(&f, 1);

    printf("Fila original: ");
    imprimirFila(&f);

    inverterFila(&f);

    printf("Fila invertida: ");
    imprimirFila(&f);

    return 0;
}
