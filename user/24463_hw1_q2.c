#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int count;

    // Make some system calls
    printf(1, "Making some system calls...\n");
    for (int i = 0; i < 10; i++) {
        sleep(1);  // Example syscall
    }
    // Retrieve the syscall count
    count = getsyscallcount();
    printf(1, "Number of system calls: %d\n", count);

    exit();
}
