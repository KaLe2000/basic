#include <stdio.h>
#include "average.c"

void testAverage() {
   int assertResult = 2;
   int testArr[] = {1,1,1,2,2,5};
   int result = averageSum(testArr, 6);

   if (result == assertResult)
   {
      printf("testAverage is successfull\n");
   } else {
      printf("testAverage is failed\n");
   }
}

void testSum() {
   int assertResult = 10;
   int testArr[] = {1,1,1,1,1,5};
   int result = sumNums(testArr, 6);

   if (result == assertResult)
   {
      printf("testSum is successfull\n");
   } else {
      printf("testSum is failed\n");
   }
}

int main() {
   testAverage();
   testSum();

   return 0;
}
