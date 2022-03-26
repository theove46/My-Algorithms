#include <stdio.h>

int main()
{
  int array[100], n, i, j, swap, x;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d numbers:\n", n);

  for (i=0; i<n; i++)
    scanf("%d", &array[i]);

  for (i=0 ; i<n-1; i++)
  {
      x = 0;
    for (j=0 ; j<n-i-1; j++)
    {
      if (array[j] > array[j+1]) /* For decreasing order use < */
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
        x = 1;
      }
    }
    if(x == 0)
        break;
  }

  printf("Sorted list in ascending order:\n");

  for (i=0; i<n; i++)
     printf("%d ", array[i]);
     printf("\n");
  return 0;
}
