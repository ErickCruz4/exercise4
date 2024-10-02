#ifndef MEMORY_RESOURCES_H
#define MEMORY_RESOURCES_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define ARRAY_SIZE 1000000
#define SHM_KEY 1234

void write_shared_memory(int *shm_ptr);
long long read_shared_memory(int *shm_ptr);

#endif  // MEMORY_RESOURCES_H
