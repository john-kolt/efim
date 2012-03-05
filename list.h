#ifndef LIST_H
#define LIST_H

typedef int tListData;

typedef struct tList {
   int uid;
   tListData data;
   struct tList *left;
   struct tList *right;
} tList;

typedef tList* pList;

pList listCreate();
int listAdd(pList list, int uid, tListData data);
int listDel(pList list, int uid);
tListData listSearch(pList list, int uid);

#endif // LIST_H
