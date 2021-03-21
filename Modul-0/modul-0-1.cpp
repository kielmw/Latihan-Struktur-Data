/**
 * Implementasi ADT List (Doubly Linked List)
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
 * -- tanggal 21 Maret 2021
 * Struktur Data 2021
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} List;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void dlist_init(List *list);
bool dlist_isEmpty(List *list);
void dlist_pushFront(List *list, int value);
void dlist_pushBack(List *list, int value);
void dlist_insertAt(List *list, unsigned index, int value);
int  dlist_front(List *list);
int  dlist_back(List *list);
void dlist_popFront(List *list);
void dlist_popBack(List *list);
// void dlist_remove(List *list, int element);
// void dlist_removeAt(List *list, int index);

/* Function definition */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

bool dlist_isEmpty(List *list) {
    return (list->_head == NULL && \
            list->_tail == NULL);
}

void dlist_pushFront(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        newNode->next = list->_head;
        list->_head->prev = newNode;
        list->_head = newNode;
    }
}

void dlist_pushBack(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}

void dlist_insertAt(List *list, unsigned index, int value)
{
    if (index == 0) { 
        dlist_pushFront(list, value);
        return;
    }
    else if (index >= list->_size) {
        dlist_pushBack(list, value);
        return;
    }

    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        DListNode *temp = list->_head;

        unsigned _i = 0;
        while (_i < index - 1 && temp->next != NULL) {
            temp = temp->next;
            _i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        list->_size++;
    }
}

int dlist_front(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_head->data);
    }
    return 0;
}

int dlist_back(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_tail->data);
    }
    return 0;
}

void dlist_popFront(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp = list->_head;
        if (list->_head == list->_tail) {
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            list->_head = list->_head->next;
            list->_head->prev = NULL;
            free(temp);
        }
        list->_size--;
    }
}

void dlist_popBack(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp;
        if (list->_head == list->_tail) {
            temp = list->_head;
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            temp = list->_tail;
            list->_tail = list->_tail->prev;
            list->_tail->next = NULL;
            free(temp);
        }
        list->_size--;
    }
}

int sum = 0, index, rev[100005];

void printElement(int *elem) {
    printf("%d ", *elem);
}

void multiply2(int *elem) {
    *elem *= 2;
}

void reverseEach(int *elem) {
	*elem = rev[index];
}

void sumDigit(int *elem) {
    *elem = sum;
}

void forEachElement(List *list, void (*f)(int *)) {
	if (!dlist_isEmpty(list)) {
		DListNode *temp = list->_head;
		sum = 0, index = list->_size - 1;
		temp = list->_head;
		while(temp != NULL) {
			sum += temp->data;
			rev[index--] = temp->data;
			temp = temp->next;
		}
		index = 0;
		temp = list->_head;
		while(temp != NULL) {
			(*f)(&temp->data);
			temp = temp->next;
			index++;
		}
		free(temp);
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
    // Buat objek List
    List myList;

    // PENTING! Jangan lupa diinisialisasi
    dlist_init(&myList);

    // Gunakan operasi linked list
    dlist_pushBack(&myList, 1);
    dlist_pushBack(&myList, 2);
    dlist_pushBack(&myList, 3);
    dlist_pushBack(&myList, 4);
    dlist_pushBack(&myList, 5);
    
    // Isi List => [1, 2, 3, 4, 5]
    
    forEachElement(&myList, printElement);
    
    forEachElement(&myList, multiply2);
    forEachElement(&myList, printElement);
    
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, printElement);
    
    forEachElement(&myList, sumDigit);
    forEachElement(&myList, printElement);
    
    return 0;
}
