/* file : process.i */
  
/* name of module to use*/
%include <std_string.i>
using std::string;
%module process
%{ 
    /* Every thing in this file is being copied in  
     wrapper file. We include the C header file necessary 
     to compile the interface */
    #include "process.h" 

    extern sem_t* sem;
 
%} 
  
/* explicitly list functions and variables to be interfaced */
extern sem_t* sem;
void set(void* ptr, string in);
string get(void* ptr);
void clean(int key, void* ptr);
void* setup(int key); 
