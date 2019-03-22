#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint swtchLimit = 100 ;

enum actiontype { EXIT, CPU, WAIT, WAKE, FORK, KILL } ;

void printaction(enum actiontype atype){
  switch(atype) {
    case EXIT : printf("EXIT"); break;
    case CPU  : printf("CPU"); break;
    case WAIT : printf("WAIT"); break;
    case WAKE : printf("WAKE"); break;
    case FORK : printf("FORK"); break;
    case KILL : printf("KILL"); break;
    default   : printf("????");
  }
}

struct action {
  enum actiontype atype;
  int tgtp;              // p parameter for WAKE..KILL
};

#define MAXACT 20

struct acts {
  struct action *next;
  struct action actions[MAXACT];
};

struct acts pactions[NPROC];

int initaction(struct action *a){
  a->atype = 999;
  a->tgtp = -1;
  return 0;
}

int initact(struct acts *as){

  struct action *a;
  int i;

  a = as->actions;
  for(i=0;i<MAXACT;i++){
    initaction(&a[i]);
  }
  as->next = NULL;
  return 0;
}


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
  // printf("rc=%d, types=%s\n",rc,l_types);
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
  printf(" ");printaction(l_atype);
  if(l_tgtp>=0) {printf("(%d)",l_tgtp);}
  printf("\n");
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
  // printf("rc=%d, stuff=%s, p=%d\n",rc,stuff,l_p);
  p = &pactions[l_p];
  l_a=0;
  while(readaction(p,l_a)){
    // printf("Action %d read!\n",l_a);
    l_a++;
  }
  p->next = p->actions;
  printf("Actions:\n");
  for(a = p->actions; a < &p->actions[MAXACT]; a++) {
    printaction(a->atype);
    if(a->tgtp >= 0) {printf("(%d)",a->tgtp);}
    printf("\n");
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
