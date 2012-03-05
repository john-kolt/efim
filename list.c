#include "list.h"

pList listCreate()
{
    pList result = malloc(sizeof(tList));
    result->uid = 0;
    result->data = 0;
    return result;
}

int listAdd(pList list, int uid, tListData data)
{
    // IN WORK
    /*if(uid == list->uid)
        return 1;
    if(uid < list->uid && uid < list->left->uid)
        listAdd(list->left);
    if(uid > list->uid && uid > list->right->uid)
        listAdd(list->right);
    if(uid < list->uid && uid > list->left->uid)*/
}

int listDel(pList list, int uid);
tListData listSearch(pList list, int uid);
