#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *nuevoHeap=(Heap *)malloc(sizeof(Heap));
  nuevoHeap->HeapArreglo=(heapElem *)malloc(2 * sizeof(heapElem));
  nuevoHeap->size=0;
  nuevoHeap->capac=3

   return NULL;
}