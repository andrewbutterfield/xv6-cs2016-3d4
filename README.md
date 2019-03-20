# Overview

This repository, `xv6-cs2016-3d4` is a reworking of parts of MIT's `xv6-public` to provide coursework opportunites for students taking the concurrency and operating-systems module,
offered to 2nd-year computer science \(CS2016) and 3rd-year computer engineering (3D4) undergraduate students, at *Trinity College, the University of Dublin*.

## Rationale

The **xv6** environment and source code is suitable for a module on OSes that is based entirely on these sources. However given the background and experience of CS2016/3D4 students, and the fact that the module also looks at concurrency programming using *pthreads*, and concurrency modellings using *Promela/SPIN*, it is not practical to get the students to use the full **xv6** development environment in the relevant timeframe.

Here we are taking excerpts from **xv6** that allow the students to explore some aspects of OS algorithms
in a simpler setting, and make it easier to automatically script and observe behaviours.

## Acknowledgment
The file `README` (as distinct from this file `README.md`) is unchanged from the xv6-public repo. We are very grateful to the teaching staff at MIT for developing and sharing this resource.

## Excerpt 1 - the Scheduler

The xv6 scheduler is very simple: run down the process table and select the first runnable process.

The plan is to be able to enhance it to be a little smarter.