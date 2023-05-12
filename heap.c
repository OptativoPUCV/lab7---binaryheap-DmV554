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
    if(pq == NULL || pq->size == 0) return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac) {
      pq->capac = pq->capac * 2 + 1;
      pq->heapArray = realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
    }

  int indiceUltimoElemento = pq->size;
  pq->heapArray[indiceUltimoElemento].data = data;
  pq->heapArray[indiceUltimoElemento].priority = priority;

  pq->size++;

  while(indiceUltimoElemento > 0 && pq->heapArray[indiceUltimoElemento].priority > pq->heapArray[(indiceUltimoElemento -1) / 2].priority) { 
  heapElem tempElemHeapArray = pq->heapArray[indiceUltimoElemento];
  pq->heapArray[indiceUltimoElemento] = pq->heapArray[(indiceUltimoElemento -1) / 2];
  pq->heapArray[(indiceUltimoElemento -1) / 2] = tempElemHeapArray;

  indiceUltimoElemento = (indiceUltimoElemento - 1) / 2;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap*heap = malloc(sizeof(Heap));
  heap->capac = 3;
  heap->size = 0;
  heap->heapArray = malloc(sizeof(heapElem) * heap->capac);
  
  return heap;
}
