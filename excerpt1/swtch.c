#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

uint swtchLimit = 100 ;

enum actiontype { EXIT, CPU, WAIT, WAKE, FORK, KILL } ;

struct action {
  enum actiontype atype;
  int tgtp;              // p parameter for WAKE..KILL
};

int initaction(struct action *a){
  a->atype = EXIT;
  a->tgtp = -1;
  return 0;
}

#define MAXACT 30

struct act {
  struct action *next;
  struct action actions[MAXACT];
};

int initact(struct act *a){
  initaction(a->actions);
  a->next = a->actions;
  return 0;
}

struct act pactions[NPROC];

int initpactions() {
  struct act *a;

  for(a = pactions; a < &pactions[NPROC]; a++) {
    initact(a);
  }
  return 1;
}


int readactions(){
  // ACT 3 CPU CPU CPU CPU EXIT
  return 0;
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
     //strcpy(p->name,l_name);
  }
  return rc;
}





void swtch(struct proc *p){

   printf("Switching to running process %d,%d\n",(int)p,swtchLimit);
   p->state = RUNNABLE;

   if(!swtchLimit--) {
     printf("switch-limit reached!\n" );
     exit(0);
   }

}
