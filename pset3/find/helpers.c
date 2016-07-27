/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
*/
bool search(int value, int values[], int n)
{
   int s = 0;
  int e = n - 1; 
  int mid = (s + e) / 2;

  while (s <= e)
 {
    if (values[mid] == value)
      return true;
    else if (value < values[mid])
        {
          e = mid - 1;
          mid = (s + e) / 2;
          // TODO
        }
    else if (value > values[mid])
        {
          s = mid + 1;
          mid = (s + e) / 2;
          // TODO
        }
      else 
        break;
  }
  return false;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int i,j;
    for(i =0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(values[i]>values[j])
            {
                int t=values[j];
                values[j]=values[i];
                values[i]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%i\n",values[i]);
    }
    return;
}