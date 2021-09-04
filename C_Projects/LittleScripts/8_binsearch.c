# include <stdio.h>

// binary search
int binsearch(int x, int v[], int n);

// test 
int main()
{
    int array[10] = {1, 12, 34, 56, 78, 97, 121, 153, 165, 200};
    
    int index = binsearch(97, array, 10);

    printf("%d", index);

    return 0;
}

// binary search
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}