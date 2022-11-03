 #include <stdio.h>  
      
    void insert(int a[], int n) /* function to sort an aay with insertion sort */  
    {  
        int i, j, temp;  
        for (i = 1; i < n; i++) {  
            temp = a[i];  
            j = i - 1;  
      
            while(j>=0 && temp <= a[j])  /* Move the elements greater than temp to one position ahead from their current position*/  
            {    
                a[j+1] = a[j];     
                j = j-1;    
            }    
            a[j+1] = temp;    
        }  
    }  
      
    void printArr(int a[], int n) /* function to print the array */  
    {  
        int i;  
        for (i = 0; i < n; i++)  
            printf("%d ", a[i]);  
    }  
      
    int main()  
    {  
        int a[] = { 12, 31, 25, 8, 32, 17 };  
        int n = sizeof(a) / sizeof(a[0]);  
        printf("Before sorting array elements are - \n");  
        printArr(a, n);  
        insert(a, n);  
        printf("\nAfter sorting array elements are - \n");    
        printArr(a, n);  
      
        return 0;  
    }    



#include <stdio.h>  
  
void selection(int arr[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray  
    {  
        small = i; //minimum element in unsorted array  
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
            small = j;  
// Swap the minimum element with the first element  
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main()  
{  
    int a[] = { 12, 31, 25, 8, 32, 17 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    selection(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}
