/**
 * Implementasi ADT Dynamic Array
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

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(
    DynamicArray *darray, unsigned index, int value)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

int dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
	if (!dArray_isEmpty(darray)) {
		unsigned it;
		if (darray->_size + 1 > darray->_capacity) {
	        darray->_capacity *= 2;
	    }
	    darray->_size++;
	    int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);
	    for (it=0; it < index; ++it)
	        newArr[it] = darray->_arr[it];
	    
	    newArr[index] = value;
	    
	    for (it=index + 1; it < darray->_size; ++it)
	        newArr[it] = darray->_arr[it - 1];
	        
	    int *oldArray = darray->_arr;
	    darray->_arr = newArr;
	    free(oldArray);
	}
}

void dArray_removeAt(DynamicArray *darray, unsigned index) {
	if (!dArray_isEmpty(darray)) {
		unsigned it;
		if (index >= darray->_size) {
			dArray_popBack(darray);
			return;
		}
		for (it=index; it < darray->_size - 1; ++it) {
			darray->_arr[it] = darray->_arr[it + 1];
		}
		darray->_size--;
	}
}


int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    // Operasi-operasi
    // myArray => [11, 14, 17, 23]
    dArray_pushBack(&myArray, 1);
    dArray_pushBack(&myArray, 2);
    dArray_pushBack(&myArray, 3);
    dArray_pushBack(&myArray, 4);
    dArray_pushBack(&myArray, 5);

    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
	}   
    printf("\n");
    
    dArray_insertAt(&myArray, 3, 10);
    dArray_insertAt(&myArray, 0, 9);
    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }
    printf("\n");
    
    dArray_removeAt(&myArray, 2);
    dArray_removeAt(&myArray, 4);
    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }
    printf("\n");
    return 0;
}
