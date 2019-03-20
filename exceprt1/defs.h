struct context;
struct proc;
struct spinlock;

// proc.c

struct proc *p;
struct cpu *c;
uint timeout ;
void scheduler(void);

// swtch.S
void            swtch(struct context**, struct context*);
