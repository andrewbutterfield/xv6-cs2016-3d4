#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

void swtch(struct context **old, struct context *new){

   printf("Switching to running process %d,%d\n",(int)(c->proc),timeout);
   p->state = RUNNABLE;

   if(!timeout--) {
     printf("timeout!" );
     exit(0);
   }

}
