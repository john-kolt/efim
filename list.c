#include "list.h"

pList listCreate()
{
    pList result = malloc(sizeof(tList));
    if(result != 0)
    {
        result->uid = 0;
        result->data = 0;
        result->level = 0;
        result->left = result->right = 0;
    }
    return result;
}


/// BUGGS
int listAdd(pList list, int uid, tListData data)
{
    if(uid < list->uid && list->left == 0)
    {
        pList newItem = listCreate();
        newItem->uid = uid;
        newItem->data = data;
        list->left = newItem;
        list->level += 1;
        return 1;
    }
    if(uid > list->uid && list->right == 0)
    {
        pList newItem = listCreate();
        newItem->uid = uid;
        newItem->data = data;
        list->right = newItem;
        list->level += 1;
        return 1;
    }
    if(list->level!=0)
    {
        int result = 0;
        if(uid < list->uid)
            result = listAdd(list->left, uid, data);
        else if(uid > list->uid)
            result = listAdd(list->right, uid, data);
        else if(uid == list->uid)
            result = 0;
        listSkew(list);
        listSplit(list);
        return result;
    }
}

void listDel(pList list, int uid)
{
    pList deleted = 0;
    pList last = 0;
    if(list->level!=0)
    {
        last = list;
        if(uid < list->uid)
            listDel(list->left, uid);
        else
        {
            deleted = list;
            listDel(list->right, uid);
        }
    }
    if(list == last && deleted != 0 && uid == deleted->uid)
    {
        deleted->uid = list->uid;
        deleted = 0;
        list = list->right;
        free(last);
    }
    else if (list->left->level < list->level-1 || list->right->level < list->level-1)
    {
        list->level -= 1;
        if(list->right->level > list->level)
            list->right->level = list->level;
        listSkew(list);
        listSkew(list->right);
        listSkew(list->right->right);
        listSplit(list);
        listSplit(list->right);
    }
}


void listSwap(pList from, pList to)
{
    pList tmp = to;
    to = from;
    from = tmp;
}

void listSkew(pList list)
{
   pList l = list->left;
   if(list->level == l->level)
   {
       listSwap(list, l);
       l->left = list->right;
       list->right = l;
   }
}

void listSplit(pList list)
{
    pList r = list->right;
    if(list->level == r->right->level)
    {
        listSwap(list, r);
        r->right = list->left;
        list->left = r;
        list->level += 1;
    }
}

pList listSearch(pList list, int uid)
{
    if(list->level==0)
        return 0;
    else
    {
        pList result = 0;
        if(uid < list->uid)
            result = listSearch(list->left, uid);
        else if(uid > list->uid)
            result = listSearch(list->right, uid);
        else if(uid == list->uid)
            result = list;
        return result;
    }
}


void listPrint(pList list)
{
    fprintf("%d ", list->uid);
    if(list->left!=0)
        listPrint(list->left);
    if(list->right!=0)
        listPrint(list->right);
    puts("");
}
