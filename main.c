/*  This program is a sorting algorithm which is created by using the idea:
    "Every array is a combination of already sorted arrays which are in ascending order or descending order"

    Now using this idea I just sliced those sub arrays, made them in ascending order and performed merge sort on them.
*/    

#include<stdio.h>
#include<malloc.h>

void arr_rev(int arr[] , int i , int j)// Reversing the array.
{
    int temp;
    while(i<j)
    {
        temp = arr[i];
        arr[i++] = arr[j];
        arr[j--] = temp;
    }
}

void merge_sort(int arr[], int l2, int r2)// Merge sorting the two arrays
{
    int i, j, k;
    int n1 = l2;
    int n2 = r2-l2+1;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[i];
    for (j = 0; j < n2; j++)
        R[j] = arr[l2 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = 0; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void insertSorted(int arr[], int key, int n)// Inserts the element in corrext sorted position
{
    int i;
    for(i = n - 1; (i >= 0 && arr[i] > key) ; i--)
        arr[i + 1] = arr[i];
 
    arr[i + 1] = key;
}
 
int main(void)
{
    int n,i,j,l1=0,l2,r1=0,r2;
    int *arr;
    
    scanf("%d",&n);//Size of array
    
    arr = malloc(n*sizeof(int));//Initalization of array
    for(i=0;i<n;++i)
        scanf("%d",arr+i);
    
    printf("Array Before Sorting: ");//Printing the array before being sorted
    for(i=0;i<n;++i)
        printf("%d ",arr[i]);
    
    while(arr[r1]<arr[r1+1] && r1<n-1)//First Ascending ordered array
        ++r1;
    l2=r1+1;
    
    while(l2<n-2)//Finding other possible arrays
    {
        r2=l2+1;//Second element of the other array
        if(arr[l2]<arr[l2+1])//Deciding if the array being sliced is in ascending order or descending order
        {
            while(r2<n-1 && arr[r2]<arr[r2+1])//Slicing ascending ordered array
                ++r2;
        }
        else
        {
            while(r2<n-1 && arr[r2]>=arr[r2+1])//Descending ordered array
                ++r2;
            arr_rev(arr , l2 , r2);
        }
        merge_sort(arr , l2 , r2);//Performing merger sort
        r1=r2;//end of new sorted array
        l2=r2+1;//beginning of the next array
    }
    
    while(l2<n)//inserting the leftover elements
    {
        insertSorted(arr , arr[l2] , l2);
        ++l2;
    }
    
    printf("\n Array After Sorting: ");//Printing the array after being sorted
    for(i=0;i<n;++i)
        printf("%d ",arr[i]);
    
    return 0;
}
