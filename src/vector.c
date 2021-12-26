#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int allocation;
    int current_size;
} vector;

vector *construct_vector(int *starting_values, int allocate)
{
    vector *v = (vector *)malloc(sizeof(vector));

    v->allocation = allocate;

    if (starting_values == NULL)
    {
        v->array = (int *)malloc(sizeof(int));
        v->current_size = 0;
    }
    else
    {
        for (int i = 0; i < allocate; i++)
        {
            push_value(v, starting_values[i]);
        }
    }

    return v;
}

void push_value(vector *v, int value)
{
    if (v->current_size + 1 > v->allocation)
    {
        vector *new_vector = construct_vector(v->array, v->allocation + 1);
        free(v);

        v = new_vector;
        free(new_vector);
    }

    v->array++;
    v->array = &value;
    v->current_size++;
}

void print_values(vector *v)
{
    int string_len = (v->current_size * 2) + 2;

    char *vector_string = (char *)malloc(string_len * sizeof(char));

    vector_string[0] = "[";
    vector_string[string_len - 1] = "]\n";

    for (int i = 1; i < string_len - 2; i += 2)
    {
        vector_string[i] = v->array[i];
        vector_string[i + 2] = ",";
    }

    printf("%d element vector: %s", v->current_size, vector_string);
}
