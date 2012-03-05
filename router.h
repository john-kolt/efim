#ifndef ROUTER_H
#define ROUTER_H

#include <string.h>

typedef char* tUID;
typedef char* tData;

int routerConnect();
int routerDisconnect();
int routerLoadConfig(char *fileName);
int routerSend(tUID toUid, tData data);
void *routerOnReceive(tUID fromUid, tData data);

#endif // ROUTER_H
