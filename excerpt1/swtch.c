#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

uint swtchLimit = 100 ;

void swtch(struct context **old, struct context *new){

   printf("Switching to running process %d,%d\n",(int)(c->proc),swtchLimit);
   p->state = SLEEPING;

   if(!swtchLimit--) {
     printf("switch-limit reached!\n" );
     exit(0);
   }

}
