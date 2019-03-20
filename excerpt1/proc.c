#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>

#define NCPU 1

struct cpu cpus[NCPU];
int ncpu;


// Per-CPU process scheduler.
// Each CPU calls scheduler() after setting itself up.
// Scheduler never returns.  It loops, doing:
//  - choose a process to run
//  - swtch to start running that process
//  - eventually that process transfers control
//      via swtch back to the scheduler.

// local to scheduler in xv6, but here we need them to persist outside
// xv6 runs scheduler as a "coroutine" via swtch,
// but here swtch is just a regular procedure call.
struct proc *p;
struct cpu *c = cpus;


void
scheduler(void)
{ int runnableFound; // DO NOT MODIFY/DELETE

  c->proc = 0;

  runnableFound = 1 ; // force one pass over ptable

  while(runnableFound){ // DO NOT MODIFY
    // Enable interrupts on this processor.
    // sti();
    runnableFound = 0; // DO NOT MODIFY
    // Loop over process table looking for process to run.
    // acquire(&ptable.lock);
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){

      if(p->state != RUNNABLE)
        continue;

      runnableFound = 1; // DO NOT MODIFY/DELETE/BYPASS

      // Switch to chosen process.  It is the process's job
      // to release ptable.lock and then reacquire it
      // before jumping back to us.
      c->proc = p;
      //switchuvm(p);
      p->state = RUNNING;


      swtch(c->proc);
      // p->state should not be running on return here.
      //switchkvm();
      // Process is done running for now.
      // It should have changed its p->state before coming back.
      c->proc = 0;
    }
    // release(&ptable.lock);

  }
  printf("No RUNNABLE process!\n");
}
