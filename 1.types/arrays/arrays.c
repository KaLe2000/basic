#include <stdio.h>
#include <stdlib.h>

int getValByIndex(int* array, int index) {
    if (array != NULL && (sizeof(array[0]) / sizeof(int)) >= index)
    {
        return array[index];
    }

    return -1;
}

int getIndexByVal(int* array, int size, int value) {
    if (array != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
            if (array[i] == value)
            {
                return i;
            }
        }
    }

    return -1;
}

void insertElement(int **array, int *size, int index, int value) {
    if (index < 0 || index > *size) {
        printf("Invalid index\n");
        return;
    }

    *array = realloc(*array, (*size + 1) * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = *size; i > index; i--) {
        (*array)[i] = (*array)[i - 1];
    }

    (*array)[index] = value;
    (*size)++;
}


int main()
{
    return 0;
}