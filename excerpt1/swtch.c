#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  int l_p; // pactions index
  char l_types[10];
  enum actiontype l_atype;
  int l_tgtp; // target process index
  char stuff[6];

  int rc;
  struct proc *p;

  l_p=999; l_atype=999; l_tgtp=999;

  // ACT 3
  rc = scanf( "%s %d", stuff, &l_p);
  printf("rc=%d, stuff=%s, p=%d\n",rc,stuff,l_p);
  // CPU | WAIT | WAKE 2 | FORK 4 | KILL 0 | EXIT
  rc = scanf("%s",l_types);
  printf("rc=%d, types=%s\n",rc,l_types);
  if (strcmp(l_types,"CPU")==0) {
   l_atype = CPU;
 } else if (strcmp(l_types,"WAIT")==0) {
   l_atype = WAIT;
  } else {
   l_atype = EXIT;
  }
  printf("atype=%d\n,",l_atype);

  // rc = scanf( "%s %d %u %d %d %d %d %s"
  //       , stuff, &l_p, &l_sz, &l_state, &l_pid, &l_parent_p, &l_killed, l_name );
  //  printf("rc=%d, stuff=%s\n",rc,stuff);
  //  if(rc==8){
  //    printf( "Proc %d %u %d %d %d %d %s!\n"
  //          , l_p, l_sz, l_state, l_pid, l_parent_p, l_killed, l_name);
  //    p = &ptable.proc[l_p];
  //    p->sz  = l_sz;
  //    p->state = l_state;
  //    p->pid  = l_pid;
  //    p->parent = l_parent_p == -1 ? NULL : &ptable.proc[l_parent_p];
  //    p->killed = l_killed;
  //    //strcpy(p->name,l_name);
  //   }
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
