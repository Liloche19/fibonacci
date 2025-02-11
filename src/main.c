#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned long *allocate_mem(int size)
{
    unsigned long *array;
    int i = 0;

    array = malloc(sizeof(unsigned long) * (size + 1));
    while (i <= size){
        array[i] = 0;
        i++;
    }
    return array;
}

unsigned long fibonacci(int nb, unsigned long *array)
{
    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    if (array[nb] == 0)
        array[nb] = fibonacci(nb - 1, array) + fibonacci(nb - 2, array);
    return array[nb];
}

int main(int argc, char **argv)
{
    int nb;
    unsigned long *array;
    unsigned long res;

    if (argc != 2){
        write(2, "Invalid number of parameters !\n", 32);
        return 84;
    }
    nb = atoi(argv[1]);
    if (nb < 0){
        write(2, "Invalid number !\n", 18);
        return 84;
    }
    array = allocate_mem(nb);
    res = fibonacci(nb, array);
    printf("Fibonnaci (%d) = %lu\n", nb, res);
    free(array);
    return 0;
}
