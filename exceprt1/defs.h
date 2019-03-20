struct context;
struct proc;
struct spinlock;


// mp.c
extern int      ismp;
void            mpinit(void);

// proc.c
int             cpuid(void);
struct cpu*     mycpu(void);
struct proc*    myproc();
void            scheduler(void) __attribute__((noreturn));

// swtch.S
void            swtch(struct context**, struct context*);

// spinlock.c
void            acquire(struct spinlock*);
void            release(struct spinlock*);


// vm.c
void            switchuvm(struct proc*);
void            switchkvm(void);
