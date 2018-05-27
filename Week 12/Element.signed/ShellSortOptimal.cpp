#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{

    int h = 1;
    while (h < size) h = 3*h + 1;

    for (h = (h-1)/3; h >= 1; h = (h-1)/3)
    {

        for (int i = h; i < size; i++)
        {
            Element tmp = data[i];  
            int j = i;

            while ((j >= h) && (tmp < data[j-h]))
            {
                data[j] = data[j-h];
                move_count++;
                compare_count++;
                j -= h;
            }

            if (j >= h) compare_count++;
            if (i != j)
            {
                data[j] = tmp;
                move_count++;
            }
        }
    }
}
