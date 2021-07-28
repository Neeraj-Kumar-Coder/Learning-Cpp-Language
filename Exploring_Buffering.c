// Here in my system buffering seems to be not present for stdout.
// So try running this program in the online compiler and you will be able to note the difference

#include <stdio.h>
#include <unistd.h>

void __attribute__((destructor)) exitPrinter(void);

void exitPrinter(void)
{
    printf("Program exited!");
}

int main(void)
{
    /*
    stdout - Stdout is usually line buffered, meaning it will not display output until it sees a newline.
             After it encounters a newline character, all the buffer gets flushed immediately.
    stderr - Stderr is usually unbuffered and will print immediately.
    */
    fprintf(stdout, "This is to stdout. ");
    fprintf(stderr, "This is to stderr. ");
    fprintf(stdout, "This is also to stdout. ");
    sleep(3);
    fprintf(stdout, "Sleep time ended");
    return 0;
}