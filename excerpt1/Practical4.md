# Practical 4 - changing the **xv6** Scheduler.

This folder contains sources of a tool `sim` that simulates **xv6** from the perspective of the scheduler. That scheduler implements a round-robin policy.

Your task is to modify the scheduler to implement a simple load-balancing policy.

## Using `sim`

### Compiling `sim`

To build/re-build the simulator, simply give the command `make` (or its Windows equivalent).

### Using `sim`

The simulator requires a configuration file on standard input. These files have a format described in the file `Scheduler.md`, also in this folder. Two example files, `25CPU.txt` and `5WAIT.txt` are provided.

To run the simulator with `25CPU.txt` simply enter `./sim <25CPU.txt` at the command line. Its output is sent to standard output and so will appear in the terminal window.

The files `fun25CPU.log` and `run5WAIT.log` contain a record of the outputs expected when using `25CPU.txt` or `5WAIT.txt` respectively, with the given round-robin scheduler.


