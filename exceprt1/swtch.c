#include "types.h"
#include "defs.h"
// #include "param.h"
// #include "memlayout.h"
// #include "spinlock.h"
#include "proc.h"
#include <stdio.h>

void swtch(struct context **old, struct context *new){
   printf("Switching to running process\n");
}
