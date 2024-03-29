#include "types.h"
#include "user.h"

int PScheduler(void);

int main(int argc, char *argv[]) {

    printf(1, "\n This program tests the correctness of your lab 2\n");
    PScheduler();

    return 0;
}
  
    
int PScheduler(void){

  int pid, status;
  int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i <  3; i++) {
    pid = fork();
        if (pid > 0 ) {
            continue;
        } else if (pid == 0) {

            setpriority(30-10*i);

            for (j=0;j<40000;j++) {
                for(k=0;k<50000;k++) {
                    asm("nop");
                }
            }
            printf(1, "\n Child #%d finished. It started with priority %d, and finished with priority %d\n", getpid(), 30-10*i, setpriority(-1000));
            exit(0);    
        } else {
            printf(2," \n Error \n");   
        }
    }

    if(pid > 0) {
        for (i = 0; i <  3; i++) {
            wait(&status);
        }
        printf(1,"\n if processes with highest priority finished first then its correct \n");
        exit(0);
    }
            
    return 0;
}
