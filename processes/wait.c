#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    printf("My pid=%u\n", getpid());

    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }
   
    if (fork_rv == 0)
    {
        // this means we are in the child process
        printf("CHILD: pid=%u\n", getpid());

        printf("working");
        for (int i=0; i<5; ++i)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }

        printf(" and done!\n");
        return 0;
    }

    // we are in the parent here
    printf("PARENT: pid=%u\n", getpid());
    printf("waiting on child %u...", fork_rv);
    fflush(stdout);

    pid_t wait_rv = wait(NULL);
    if (wait_rv == -1)
    {
        perror("wait");
        exit(0);
    }

    printf(" child %u is done!\n", wait_rv);

    return 0;
}
