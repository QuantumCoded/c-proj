#include "msgbox.h"
#include "msgqueue.h"

void add_message(MSGQUEUE* msgqueue, char* message) {
    if (msgqueue->count == MSGBOX_LINES) {
        for (int i = 1; i < MSGBOX_LINES; i++) {
            msgqueue->messages[i - 1] = msgqueue->messages[i];
        }
    }

    msgqueue->messages[MSGBOX_LINES - 1] = message;

    if (msgqueue->count < MSGBOX_LINES) {
        msgqueue->count++;
    }
}
