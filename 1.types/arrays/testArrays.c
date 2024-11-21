#include <stdio.h>
#include "arrays.c"

void testGetValByIndex() {
    int array[] = {1,2,3,4,5};
    int res = getValByIndex(array, 5, 2);

    if (res == 3)
    {
        printf("testGetValByIndex is success\n");
    } else {
        printf("testGetValByIndex is failed\n");
    }
}

void testGetIndexByVal() {
    return;
}

void testInsertElement() {
    return;
}

int main()
{
    testGetValByIndex();
    testGetIndexByVal();
    testInsertElement();
    
    return 0;
}