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
  if(pq->size==0){
    return NULL;
  }
  return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
  // Primero se verifica si el arreglo está lleno
  if(pq->size == pq->capac){
    int nuevaCapacidad= (pq->capac*2)+1;
    pq->heapArray=(heapElem *)realloc(pq->heapArray,nuevaCapacidad* sizeof(heapElem));
    pq->capac=nuevaCapacidad;
  }
  
  heapElem nuevo;
  nuevo.data=data;
  nuevo.priority=priority;

  int posicion=pq->size;
  pq->heapArray[posicion]=nuevo;
  pq->size++;

  int nuevaPosicion=(posicion-1)/2;

  while(posicion>0 && (pq->heapArray[posicion].priority > pq->heapArray[nuevaPosicion].priority)){
    heapElem aux=pq->heapArray[posicion];
    pq->heapArray[posicion]=pq->heapArray[nuevaPosicion];
    pq->heapArray[nuevaPosicion]=aux;

    posicion=nuevaPosicion;
    nuevaPosicion=(posicion-1)/2;
  }
}

void heap_pop(Heap* pq){
  // Primero verificamos
  if(pq->size==0){
    return;
  }

  pq->heapArray[0]=pq->heapArray[pq->size-1];
  pq->size--;
  int i=0;

  while(1){
    int izquierda=(2*i)+1;
    int derecha=(2*i)+2;
    int actual=i;

    heapElem aux=pq->heapArray[i];

    if(actual==i){
      break;
    }

    
    if(izquierda<pq->size && pq->heapArray[izquierda].priority > pq->heapArray[actual].priority){
      actual=izquierda;
      
    }

    if(derecha< pq->size && pq->heapArray[derecha].priority > pq->heapArray[actual].priority){
      actual=derecha;
    }


    pq->heapArray[i]=pq->heapArray[actual];
    pq->heapArray[actual]=aux;

    actual=i;





    
  }
  
}

Heap* createHeap(){
  Heap *nuevoHeap=(Heap *)malloc(sizeof(Heap));
  nuevoHeap->heapArray=(heapElem *)malloc(3 * sizeof(heapElem));
  nuevoHeap->size=0;
  nuevoHeap->capac=3;
  
  return nuevoHeap;
}
