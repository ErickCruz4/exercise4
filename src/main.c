#include "memory_resources.h"
#include "queue_functions.h"

/**
 * @brief Measures the time taken for shared memory operations.
 */
void measure_time_shared_memory() {
  int shmid = shmget(SHM_KEY, ARRAY_SIZE * sizeof(int), IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget failed");
    exit(1);
  }

  int *shm_ptr = (int *)shmat(shmid, NULL, 0);
  if (shm_ptr == (int *)-1) {
    perror("shmat failed");
    exit(1);
  }

  clock_t start_time = clock();

  if (fork() == 0) {
    write_shared_memory(shm_ptr);
    exit(0);
  } else {
    wait(NULL);
    long long sum = read_shared_memory(shm_ptr);
    clock_t end_time = clock();

    printf("Shared Memory Sum: %lld\n", sum);
    printf("Time Taken: %f seconds\n",
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
  }
}

/**
 * @brief Measures the time taken for message queue operations.
 */
void measure_time_message_queue() {
  int msgid = msgget(MSG_KEY, IPC_CREAT | 0666);
  if (msgid == -1) {
    perror("msgget failed");
    exit(1);
  }

  clock_t start_time = clock();

  if (fork() == 0) {
    write_message_queue(msgid);
    exit(0);
  } else {
    wait(NULL);
    long long sum = read_message_queue(msgid);
    clock_t end_time = clock();

    printf("Message Queue Sum: %lld\n", sum);
    printf("Time Taken: %f seconds\n",
           (double)(end_time - start_time) / CLOCKS_PER_SEC);

    msgctl(msgid, IPC_RMID, NULL);
  }
}

int main() {
  printf("Shared Memory Implementation:\n");
  measure_time_shared_memory();
  printf("\nMessage Queue Implementation:\n");
  measure_time_message_queue();
  return 0;
}
