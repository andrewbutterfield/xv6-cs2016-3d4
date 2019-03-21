#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <string.h>

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
  int l_p; // ptable index
  uint l_sz;                     // Size of process memory (bytes)
  int l_state;        // Process state
  int l_pid;                     // Process ID
  int l_parent_p;         // Parent process ptable index
  int l_killed;                  // If non-zero, have been killed
  char l_name[17];               // Process name (debugging)
  char stuff[6];

  int rc;
  struct proc *p;

  l_p=999; l_sz=999; l_state=999; l_pid=999; l_parent_p=999; l_killed=999;


  scanf("%u",&swtchLimit);
  //while(!feof(stdin)){
    // PROC 0 10 3 1111 0 0 proc1
    rc = scanf( "%s %d %u %d %d %d %d %s"
         , stuff, &l_p, &l_sz, &l_state, &l_pid, &l_parent_p, &l_killed, l_name );
    printf("rc=%d, stuff=%s\n",rc,stuff);
    if(rc==8){
      printf( "Proc %d %u %d %d %d %d %s!\n"
            , l_p, l_sz, l_state, l_pid, l_parent_p, l_killed, l_name);
      p = &ptable.proc[l_p];
      p->sz  = l_sz;
      p->state = l_state;
      p->pid  = l_pid;
      p->parent = l_parent_p == -1 ? NULL : &ptable.proc[l_parent_p];
      p->killed = l_killed;
      strcpy(p->name,l_name);
    }
  //}
}

int main (int argc, const char * argv[]) {

  printf("UNUSED=%d\n",UNUSED);
  printf("RUNNABLE=%d\n",RUNNABLE);
  printf("RUNNING=%d\n",RUNNING);
  printf("SLEEPING=%d\n",SLEEPING);
  initptable();
  loadptable();
  printf("Scheduler simulation very simple right now\n");
  scheduler();
  return 0;

}
