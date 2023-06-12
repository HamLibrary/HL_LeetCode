#include <stdlib.h>

int **generate(int num_rows, int *return_size, int **return_column_sizes)
{
    // Shout out to vli02 for this smartness
    int *pascal_triangle = malloc(sizeof(int *) * (num_rows * (num_rows + 1) / 2));
    pascal_triangle[0] = 1;

    for (int i = 1;i < num_rows;++i)
    {
        pascal_triangle[i * (i + 1) / 2] = pascal_triangle[i * (i + 1) / 2 + i] = 1;
        for(int k = 1;k < i;++k)
        {
            pascal_triangle[(i * (i + 1) / 2) + k] = 
                pascal_triangle[((i - 1) * i / 2) + k - 1] +
                pascal_triangle[((i - 1) * i / 2) + k]; 
        }
    }

    // Converting to dumbness
    *return_size = num_rows;
    *return_column_sizes = malloc(sizeof(int ) * num_rows);
    int **pooscal_triangle = malloc(sizeof(int *) * num_rows);

    for (int i = 0;i < num_rows;++i)
    {
        return_column_sizes[0][i] = i + 1;
        pooscal_triangle[i] = malloc(sizeof(int) * (i + 1));

        for (int k = 0;k <= i;++k)
        {
            pooscal_triangle[i][k] = pascal_triangle[(i * (i + 1) / 2) + k];
        }
    }
    return pooscal_triangle;
}
