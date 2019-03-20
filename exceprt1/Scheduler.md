# Scheduler Enhancements

We define a simple tex-based file-format to initialise the process tables.

For each process setup, we represent its code as a sequence of actions,
each describing the overall behaviour of one instance of being in the RUNNING state.

The running of the scheduler is then determined by that, and continues until there is no RUNNABLE process.