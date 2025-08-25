#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DList;

DList* create_list() {
    DList* list = (DList*)malloc(sizeof(DList));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

void push_front(DList* list, int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = value; n->prev = NULL; n->next = list->head;
    if (list->head) list->head->prev = n; else list->tail = n;
    list->head = n; list->size++;
}

void push_back(DList* list, int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = value; n->next = NULL; n->prev = list->tail;
    if (list->tail) list->tail->next = n; else list->head = n;
    list->tail = n; list->size++;
}

Node* find(DList* list, int value) {
    Node* cur = list->head;
    while (cur) {
        if (cur->value == value) return cur;
        cur = cur->next;
    }
    return NULL;
}

void remove_node(DList* list, Node* n) {
    if (!n) return;
    if (n->prev) n->prev->next = n->next; else list->head = n->next;
    if (n->next) n->next->prev = n->prev; else list->tail = n->prev;
    free(n); list->size--;
}

void print_list(DList* list) {
    Node* cur = list->head;
    while (cur) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    DList* lista = create_list();
    push_back(lista, 10);
    push_front(lista, 5);
    push_back(lista, 20);
    print_list(lista); 

    return 0;
}