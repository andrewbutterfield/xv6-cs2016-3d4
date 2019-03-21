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

struct acts {
  struct action *next;
  struct action actions[MAXACT];
};

int initact(struct acts *a){
  initaction(a->actions);
  a->next = a->actions;
  return 0;
}

struct acts pactions[NPROC];

int initpactions() {
  struct acts *a;

  for(a = pactions; a < &pactions[NPROC]; a++) {
    initact(a);
  }
  return 1;
}

// if action is EXIT, return 0, otherwise one.
int readaction(struct acts *p, int l_a){
  char l_types[10];
  enum actiontype l_atype;
  int l_tgtp; // target process index
  int rc;
  int arc;

  l_atype=999; l_tgtp=999;
  p->next = &p->actions[l_a];

  // CPU | WAIT | WAKE 2 | FORK 4 | KILL 0 | EXIT
  rc = scanf("%s",l_types);
  printf("rc=%d, types=%s\n",rc,l_types);
  arc=1;
  if (strcmp(l_types,"CPU")==0) {
    l_atype = CPU; l_tgtp = -1;
  } else if (strcmp(l_types,"WAIT")==0) {
    l_atype = WAIT; l_tgtp = -1;
  } else if (strcmp(l_types,"WAKE")==0) {
    l_atype = WAKE;
    rc = scanf("%d",&l_tgtp);
  } else if (strcmp(l_types,"FORK")==0) {
    l_atype = FORK;
    rc = scanf("%d",&l_tgtp);
  } else if (strcmp(l_types,"KILL")==0) {
    l_atype = KILL;
    rc = scanf("%d",&l_tgtp);
  } else if (strcmp(l_types,"EXIT")==0) {
    l_atype = EXIT; l_tgtp = -1; arc=0;
  }
  printf("atype=%d, p=%d\n",l_atype,l_tgtp);
  p->next->atype = l_atype;
  p->next->tgtp = l_tgtp;

  return arc;
}

int readactions(){

  int l_p; // pactions index
  char stuff[6];

  int rc;
  struct acts *p;
  int l_a; // actions index
  struct action *a;

  l_p=999;

  // ACT 3
  rc = scanf( "%s %d", stuff, &l_p);
  printf("rc=%d, stuff=%s, p=%d\n",rc,stuff,l_p);
  p = &pactions[l_p];
  l_a=0;
  while(readaction(p,l_a)){
    printf("Action %d read!\n",l_a);
    l_a++;
  }
  p->next = p->actions;
  for(a = p->actions; a < &p->actions[MAXACT]; a++) {
    printf("Action '%d', proc:%d\n",a->atype,a->tgtp);
  }



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
