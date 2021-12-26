#include <stdio.h>

#include "./vector.c"

int main()
{
    vector *v = construct_vector(NULL, 5);

    for (int i = 0; i < 5; i++) {
        push_value(v, i);
    }

    print_values(v);

    return 0;
}
