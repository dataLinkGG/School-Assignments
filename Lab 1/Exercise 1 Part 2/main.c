#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num)
{
    if (num == 1) {
        return false;
    }
    for (int i = 2; i<=num/2-1; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes(int a,int b)
{
    for (int i = a; i <= b; i++) {
        if (is_prime(i)) {
            printf("%d ",i);
        }
    }
}

int main(int argc, char *argv[])
{
    find_primes(atoi(argv[1]),atoi(argv[2])); // user input
    //find_primes(2,20); // defenied
    return 0;
}
