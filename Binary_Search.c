//iterative binary search

#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x)

{
// mid= low+(high-low)/2

while (l<=r)
      {int m = l+(r-l)/2;

    //check if key(x) is the mid value
    if (arr[m]==x)
        return m;
    //if x s greater, ifnore left half

    if(arr[m]<x)
        l=m+1;

    //if x is smaller, ignore the right half

    else
        r=m-1;

}

//if the elment is not on the array
return -1;
}




//driver code

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",result);
    return 0;


}
