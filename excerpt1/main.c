#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>

void initptable () {
  struct proc *p;

  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    p->state = RUNNABLE;
  }
}


int main (int argc, const char * argv[]) {

  initptable();
  swtchLimit = 5;
  printf("Scheduler simulation NYI\n...running scheduler anyway\nHold on!\n");
  scheduler();
  return 0;

}
