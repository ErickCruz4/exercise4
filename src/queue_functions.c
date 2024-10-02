#include "queue_functions.h"

#include <errno.h>

/**
 * @brief Writes an array of integers to a message queue
 * @param msgid Message queue identifier
 */
void write_message_queue(int msgid) {
  message_t msg;
  msg.mtype = 1;

  for (int i = 0; i < ARRAY_SIZE; ++i) {
    msg.mdata[i % MSG_SIZE] = i + 1;
    if (i % MSG_SIZE == MSG_SIZE - 1) {
      if (msgsnd(msgid, &msg, sizeof(msg.mdata), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
      }
    }
  }
  if (msgsnd(msgid, &msg, sizeof(msg.mdata), 0) == -1) {
    perror("msgsnd failed");
    exit(1);
  }
}

/**
 * @brief Reads integers from a message queue and computes their sum
 * @param msgid Message queue identifier
 * @return The computed sum of integers
 */
long long read_message_queue(int msgid) {
  message_t msg;
  long long sum = 0;

  while (1) {
    if (msgrcv(msgid, &msg, sizeof(msg.mdata), 1, IPC_NOWAIT) == -1) {
      if (errno == ENOMSG) {
        break;
      } else {
        perror("msgrcv failed");
        exit(1);
      }
    }
    for (int i = 0; i < MSG_SIZE; ++i) {
      sum += msg.mdata[i];
    }
  }
  return sum;
}
