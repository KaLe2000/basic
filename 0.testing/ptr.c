#include <stdio.h>
#include <stdlib.h>

void pointerSimpleFunc(int *pArray, int size);
void pointerLinkSimpleFunc(int **pArray, int *size);

int main() {
   int* pSimpleArray = NULL;
   int size = 10;

   // pointerSimpleFunc(pSimpleArray, size);

   int* pLinkArray = NULL;
   int* pLinkSize = NULL;
   pointerLinkSimpleFunc(pLinkArray, pLinkSize);
   
   for (int i = 0; i < pLinkSize; ++i)
   {
      printf("pLinkArray[%d] = %d\n", i, *(pLinkArray + i));
   }

   free(pLinkArray);
   free(pLinkSize);

   return 0;
}

/*формируем и наполняем динамический массив*/
void pointerSimpleFunc(int *pArray, int size) {
   pArray = (int*) malloc(size * sizeof(int));
   int capacity = 2;

   for (int i = 0; i < size; ++i)
   {
      if (i >= capacity)
      {
         capacity *= 2;
         pArray = (int*) realloc(pArray, capacity * sizeof(int));
      }

      *(pArray + i) = i + 1;
   }

   printf("Allocated memory is %ld byte for %d elements.\n", capacity * sizeof(int), capacity);

   for (int i = 0; i < size; ++i)
   {
      printf("Key %d, Val %d, MemoryAddr %p\n", i, *(pArray + i), pArray + i);
   }

   free(pArray);
}

/*формируем и наполняем динамический массив*/
void pointerLinkSimpleFunc(int ** pArray, int *size) {
   int capacity = 2;
   int *innerArr = NULL;
   int innerSize = 10;

   innerArr = (int*) malloc(innerSize * sizeof(int));

   for (int i = size; i > 0; --i)
   {
      *(innerArr + i) = i + 1;
   }

   *pArray = innerArr;
   *size = innerSize;
}