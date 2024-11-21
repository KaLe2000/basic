#include <stdio.h>
#include <stdlib.h>

int getValByIndex(int* array, int size, int index) {
    if (array != NULL && size >= index)
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

int binarySearch(int *arr, int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target){
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}