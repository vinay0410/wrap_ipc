#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <mutex>
#include <vector>
#include <thread>
#include <semaphore.h>
#include <fcntl.h>    
#include <unistd.h>
#include <unordered_map>


using namespace std;

#define SHM_KEY 1234
#define SNAME "/mysem"
#define MAX 100000

//extern const vector<string> data_to_write;
//sem_t *sem;
//std::mutex shm_mutex; 

void set(void* ptr, string in);
string get(void* ptr);
void clean(int key, void* ptr);
void* setup(int key);