#ifndef LIST_H
#define LIST_H

typedef int tListData;

typedef struct tList {
   int uid;
   tListData data;
   int level;
   struct tList *left;
   struct tList *right;
} tList;

typedef tList* pList;

pList listCreate();
int listAdd(pList list, int uid, tListData data);
void listDel(pList list, int uid);
pList listSearch(pList list, int uid);
void listSwap(pList from, pList to);
void listSkew(pList list);
void listSplit(pList list);
void listPrint(pList list);

#endif // LIST_H
