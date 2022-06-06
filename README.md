# Pipe-for-Process-Communication

project requirments:

1. Instead of letting the Cal Process directly reads the input file cal.in, we now let the Admin Process reads
the input commands from cal.in and send each input command to the Cal Process via a pipe. Modify your
code in admin.c(pp) and cal.c(pp) to realize this.

2. For cal.c(pp), you do need to submit the original version to allow us to test your shell script “execute”.
So, you should modify cal.c(pp) into cal-new.c(pp). In cal-new.c(pp), the input commands should be from
the pipe. Also, the Admin Process should send the command one at a time and the Cal Process should send
an acknowledgement (via a pipe) after finishing executing each command to inform the Admin to send the
next command. For termination, you can let Admin and Cal both examine the input command to make the
termination decision.

3. Note that in Step 3, you probably used “exec()” system call to run cal.exe in the child process. To make
the use of pipe easier (avoid the need of named pipe), you should change the main() function of calnew.
c(pp) into a regular function so that admin.c can call it in the child process part after fork.
For admin.c(pp), you can directly update it and only submit the updated version. Now the Admin
Process needs to read the input commands from a file and implement message passing via pipe. If you feel
comfortable, you can merge the implementation of Steps 3 and 4 together.

compile commands:

gcc -c adminNew2.c
gcc -c cal-new.c
gcc -o adminNew2 adminNew2.o cal-new.o triples.o quadratic.o sum.o -lm
./adminNew2
