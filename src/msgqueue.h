#ifndef MSGQUEUE_H_INCLUDED
#define MSGQUEUE_H_INCLUDED

#include "msgbox.h"

typedef struct {
    char* messages[MSGBOX_LINES];
    int count;
} MSGQUEUE;

void add_message(MSGQUEUE* msgqueue, char* message);

#endif
