#include "types.h"
#include "defs.h"
// #include "param.h"
// #include "memlayout.h"
// #include "mmu.h"
// #include "x86.h"
// #include "spinlock.h"
#include "proc.h"
#include <stdio.h>

void initPtable () {
  struct proc *p;

  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    p->state = RUNNABLE;
  }
}


int main (int argc, const char * argv[]) {

  initPtable();
  printf("Scheduler simulation NYI\n...running scheduler anyway\nHold on!\n");
  scheduler();
  return 0;

}
