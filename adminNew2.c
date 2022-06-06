

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(){
    char command[20];
    int M, a, b;
    FILE *fp;

    //fp = fopen("cal.in", "r");
    //fscanf(fp, "%d", &M);
    //int i;
    //for(i = 0; i < M; i++){
    //fscanf(fp, "%s %d %d", command, &a, &b);

        int fd1[2];
        int fd2[2];// fd[0] read , fd[1] write
        pipe(fd1);
        pipe(fd2);// create 2 pipes,
        int pid = fork();

        if (pid==0) { //this is child process 

            int signal = 1;
            int commandNum;
            int a1, b1;
            close(fd1[1]); // close parent write 
            close(fd2[0]);// close parent read
            //char str2[20];
            //int n2 =1;

            while(1) {
            
            if (read(fd1[0], &commandNum ,sizeof(int))<=0)
                break ;// read the commandNumber so can call function later
                // if no input , will break  
            
            if (read(fd1[0], &a1 ,sizeof(int))<=0)
                break ; // read the first integer of the line.
                //if no number input , will break

            if (read(fd1[0], &b1, sizeof(int))<=0)
                break;// read the second integer of the line
                // if no input , will break
            
            printf(" ");
            cal(commandNum, a1, b1); 
            write(fd2[1], &signal, sizeof(int));// child write a number to tell parent to continue. 
            
            printf("\nChild Received info from parent process\nParent may continue\n");
            
            }
            close (fd1[0]);// close child read
            close(fd2[1]); // close child write
                  
        }

        else { 
            // this is parent process 
            //int command;
            //int signal; 
            //wait(NULL);
            close(fd1[0]);// close child process reading 
            close(fd2[1]);// close child process writing
            
            fp = fopen("cal.in", "r");
            fscanf(fp, "%d", &M);
            int commandNum,signal;
            //int a1, b1,
            int i;
            for(i = 0; i < M; i++){
                fscanf(fp, "%s %d %d", command, &a, &b);
                if (strcmp(command,"quadratic") == 0) // match the function name and find the function number
                    commandNum = 1;
                else if (strcmp(command,"triples") == 0)
                    commandNum = 2;
                else 
                    commandNum = 3; 
                //int n = strlen(command);
                write(fd1[1], &commandNum, sizeof(int)); // write the commandNum to tell child
                write(fd1[1], &a, sizeof(int));// write the second integer 
                write(fd1[1], &b, sizeof(int));// write the third integer 
                
                if (read(fd2[0], &signal, sizeof(int))<=0)
                    break;// read the child process 
                //close(fd[2][0]); // close parent read 
                //close(fd[0][1]); // close parent write 
                //wait(NULL);
                
            }

    return 0;


}
}
