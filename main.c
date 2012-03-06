#include "main.h"

int main(void)
{
    printf("Hello World!\n");
    pList list = listCreate();
    list->uid = rand()%256;
    for(int i=0; i<10; i++)
        listAdd(list, rand()%256, 0);
    listPrint(list);
    return 0;
}

