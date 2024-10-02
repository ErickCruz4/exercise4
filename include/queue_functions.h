#ifndef QUEUE_FUNCTIONS_H
#define QUEUE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define ARRAY_SIZE 1000000
#define MSG_SIZE 256
#define MSG_KEY 5678

typedef struct {
  long mtype;
  int mdata[MSG_SIZE];
} message_t;

void write_message_queue(int msgid);
long long read_message_queue(int msgid);

#endif  // QUEUE_FUNCTIONS_H
