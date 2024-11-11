#include <stdio.h>
#include <stdlib.h>

// Енамы для управления свичом
typedef enum {CMD_AVERAGE = 1, CMD_SUM = 2} CommandType;

// Объявление функций (не обязательно, если функции идут перед main)
void averageSum(int* nums, int size);
void sumNums(int* nums, int size);

// Аргументы argc - кол-во переданных параметров в argv, argv - символьный массив (в ascii, для int/float atoi/atof)
int main(int argc, char const *argv[]) {
   // объявление указателя на файл
   FILE *filePointerNumbers;
   // объявление указателя на числовой массив
   int *nums = NULL;
   // объявление типа int
   int insert, sum=0, size=0, capacity = 2;

   // выделение памяти в указатель nums размером capacity умноженное на объём типа данных
   // каст int на malloc тк. возвращает void
   nums = (int *) malloc(capacity * sizeof(int));

   // если память не выделилась
   if (nums == NULL)
   {
      perror("Memory alloc");

      return EXIT_FAILURE;
   }

   filePointerNumbers = fopen("insert.txt", "r");

   // если файл не прочитался (нет прав, нет файла)
   if (filePointerNumbers == NULL)
   {
      perror("File read");
      free(nums);

      return EXIT_FAILURE;
   }

   // читаем построчно файл, записывая значение в память insert
   while(fscanf(filePointerNumbers, "%d", &insert) == 1 || insert != 0) {
      printf("insertion is %d\n", insert);

      // если число итераций достигло объема выделенной памяти, то увеличиваем объём выделенной памяти
      if (size >= capacity)
      {
         capacity *= 2;
         nums = (int *) realloc(nums, capacity * sizeof(int));
      }

      // если память не выделилась
      if (nums == NULL)
      {
         perror("Memory realloc");
         fclose(filePointerNumbers);

         return EXIT_FAILURE;
      }

      // записываем вводимое значение в память через арифметику указателей
      *(nums + size) = insert;
      size++;
   }

   // освобождаем память от файла
   fclose(filePointerNumbers);

   // свич по переданному аргументу, atoi для перевода ascii символа в int
   switch(atoi(argv[1])) {
      case CMD_AVERAGE:
         averageSum(nums, size);
         break;
      case CMD_SUM:
         sumNums(nums, size);
         break;
      default:
         perror("No such command.");
         free(nums);
         return EXIT_FAILURE;
   }

   // освобождаем память nums
   free(nums);

   return EXIT_SUCCESS;
}

// подсчитываем сумму значений массива и выводим среднее
void averageSum(int* nums, int size) {
   int sum = 0;

   for (int i = 0; i < size; ++i)
   {
      sum += *(nums + i);
   }

   printf("AVG is %d", sum / size);
}

// подсчитываем сумму значений и выводим
void sumNums(int* nums, int size) {
   int sum = 0;

   for (int i = 0; i < size; ++i)
   {
      sum += *(nums + i);
   }

   printf("SUM is %d", sum);
}
