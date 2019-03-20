# Scheduler Enhancements

We define a simple tex-based file-format to initialise the process tables.

For each process setup, we represent its code as a sequence of actions,
each describing the overall behaviour of one instance of being in the `RUNNING` state.

The running of the scheduler is then determined by that, and continues until there is no `RUNNABLE` process,
or a pre-determined limit on the number of process switches has been reached.

The only process states we consider are `UNUSED` (0), `SLEEPING` (2), `RUNNABLE` (3), and `RUNNING` (4).

## File structure

File top-level:

    swtchLimit
    <ptable[0]>
    <pactions.0>
    ...
    <ptable[NPROC-1]>
    <pactions.NPROC-1>

Process table entry:

    <ptable[p]> = PROC p sz pstate pid parent killed name
    
Process action entry:

    <pactions.p> = ACT p n <act[0]> .. <act[n-1]>
    
Action:

    <act[i]> = CPU  // cpu-bound, stays RUNNABLE
             | WAIT // waiting, becomes SLEEPING
             | WAKE.p // wakes process p, stays RUNNABLE
             | KILL.p // kills process p, stays RUNNABLE