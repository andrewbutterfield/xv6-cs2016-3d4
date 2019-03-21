struct proc;

// proc.c

struct proc *p;
struct cpu *c;
void scheduler(void);

// swtch.S
void swtch(struct proc *p);
uint swtchLimit ;

int initpactions();
int readactions();
