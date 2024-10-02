#include "memory_resources.h"

/**
 * @brief Writes an array of integers to shared memory
 * @param shm_ptr Pointer to the shared memory segment
 */
void write_shared_memory(int *shm_ptr) {
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    shm_ptr[i] = i + 1;
  }
}

/**
 * @brief Reads integers from shared memory and computes their sum
 * @param shm_ptr Pointer to the shared memory segment
 * @return The computed sum of integers
 */
long long read_shared_memory(int *shm_ptr) {
  long long sum = 0;
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    sum += shm_ptr[i];
  }
  return sum;
}
