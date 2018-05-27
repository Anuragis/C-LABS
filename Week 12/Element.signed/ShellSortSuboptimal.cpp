#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    for (int h = size/2; h >= 1; h /= 2)
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
            if (i != j) {
                data[j] = tmp;
                move_count++;
            }
        }
    }
}
