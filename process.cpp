#include "process.h"

sem_t* sem;
unordered_map<int, void*> virtual_memory_mapping;

//const vector<string> data_to_write{"abcde", "fghij", "klmno", "pqrst", "uvwxy"};

void* setup(int key) {

    unordered_map<int, void*>::iterator it = virtual_memory_mapping.find(key);

    if (it != virtual_memory_mapping.end())
        return it->second;

    sem = sem_open(SNAME, O_CREAT, 0777, 1);
    int shmid = shmget(SHM_KEY,1024,0666|IPC_CREAT);

    if (shmid == -1)
        return NULL;

    void* ptr = shmat(shmid,(void*)0,0);
    virtual_memory_mapping[key] = ptr;

    return ptr;
}

void set(int key, string in) {

    sem_wait(sem);

    char *str = (char*) ptr;
    strcpy(str, in.c_str());

    sem_post(sem);

}

string get (int key) {

    sem_wait(sem);

    char *str = (char*) ptr;

    if (strcmp(str, "") == 0) {
        //cout << "came hhere" << endl;
        sem_post(sem);
        return "";
    }

    string temp(str);

    sem_post(sem);

    return temp;

}

void clean(int key, void* ptr) {

    sem_close(sem);
    sem_unlink(SNAME);

    shmdt(ptr);

    int shmid = shmget(key,1024,0666|IPC_CREAT);
    shmctl(shmid,IPC_RMID,NULL);
}
