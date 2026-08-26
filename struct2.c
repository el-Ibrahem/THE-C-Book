#include <stdio.h>

// 1. Blueprint definition with both tag (Process) and typedef alias (Process)
typedef struct process {
    int pid;
    char name[32];
    
    // Nested struct for process metadata
    struct {
        int priority;
        unsigned int memory_kb;
    } resource;

    // Self-referential pointer for linking tasks
    struct Process *next; // points to next node
} Process;

int main(void) {
    // 2. Stack instance instantiation using typedef alias
    Process proc1 = {
        .pid = 1024,
        .name = "kernel_task",
        .resource = { .priority = 1, .memory_kb = 4096 },
        .next = NULL
    
    };
    
    printf("Process Name: %s (PID: %d)\n", proc1.name, proc1.pid);
    printf("Initial Memory: %u KB\n", proc1.resource.memory_kb);

    // 3. Declare struct pointer
    // 4. Bind pointer to the address of the instance
    Process *proc_p = &proc1;

    // 5. Accessing nested fields: direct (.) vs pointer (->)
    printf("Process Name: %s (PID: %d)\n", proc_p->name, proc_p->pid);
    printf("Initial Memory: %u KB\n", proc_p->resource.memory_kb);

    // 6. Modifying values directly in stack RAM through the pointer
    proc_p->resource.memory_kb = 8192;
    printf("Updated Memory: %u KB\n", proc1.resource.memory_kb);

    return 0;
}