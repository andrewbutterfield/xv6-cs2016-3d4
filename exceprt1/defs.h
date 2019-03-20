struct context;
struct proc;
struct spinlock;

// proc.c
void            scheduler(void);

struct proc *p;
struct cpu *c;

// swtch.S
void            swtch(struct context**, struct context*);
