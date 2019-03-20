#include "types.h"
#include "defs.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

uint swtchLimit = 100 ;

void swtch(struct proc *p){

   printf("Switching to running process %d,%d\n",(int)p,swtchLimit);
   p->state = SLEEPING;

   if(!swtchLimit--) {
     printf("switch-limit reached!\n" );
     exit(0);
   }

}
