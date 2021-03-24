/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

/*
 * Diselesaikan oleh Nur Ahmad Khatim
 * -- tanggal 24 Maret 2021
 * Struktur Data 2021
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    char data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value);
void stack_pop(Stack *stack);
char stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

char stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int palindrom(Stack *stack1, Stack *stack2, int length) {
	int it;
	StackNode *temp1 = stack1->_top;
	StackNode *temp2 = stack2->_top;
	for (it = 0; it < length / 2; it++) {
		if (temp1->data != temp2->data) {
			return 0;
		}
		temp1->next;
		temp2->next;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack1, myStack2;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack1);
    stack_init(&myStack2);

    char kata[100];
    
    scanf("%s", kata);
    int i, j, n = strlen(kata);
    for(i = 0, j = n - 1; i < n / 2; i++, j--) {
    	stack_push(&myStack1, kata[i]);
    	stack_push(&myStack2, kata[j]);
	}
	if (palindrom(&myStack1, &myStack2, n)) {
		printf("palindrom\n");
	}
	else {
		printf("bukan palindrom\n");
	}
    return 0;
}
