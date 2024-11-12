#include <stdio.h>

// подсчитываем сумму значений массива и выводим среднее
int averageSum(int* nums, int size) {
   return sumNums(nums, size) / size;
}

// подсчитываем сумму значений и выводим
int sumNums(int* nums, int size) {
   int sum = 0;

   for (int i = 0; i < size; ++i)
   {
      sum += *(nums + i);
   }

   return sum;
}
