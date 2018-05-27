#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    
      int firstOutOfOrder, location;
      int temp;
      for (firstOutOfOrder = 1; firstOutOfOrder < size;firstOutOfOrder++){
               compare_count++;
               temp = firstOutOfOrder;
               location = firstOutOfOrder;
         do
         {
                move_count++;
               data[location] = data[location - 1];
               
               location--;
               compare_count++;
         }
         while (location > 0 && data[location - 1] > data[temp]);
               swap(location,temp);
               compare_count++;
            }
}   //end insertionSort

