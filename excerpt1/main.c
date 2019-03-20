#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>

void initptable () {
  struct proc *p;

  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    p->sz  = 0;
    p->state = UNUSED;
    p->pid  = 0;
    p->parent = NULL;
    p->killed = 0;
    p->name[0] = 0;
  }
}

void loadptable() {
  // NYI
}

int main (int argc, const char * argv[]) {

  printf("UNUSED=%d\n",UNUSED);
  printf("RUNNABLE=%d\n",RUNNABLE);
  printf("RUNNING=%d\n",RUNNING);
  printf("SLEEPING=%d\n",SLEEPING);
  initptable();
  loadptable();
  swtchLimit = 5;
  printf("Scheduler simulation very simple right now\n");
  scheduler();
  return 0;

}
