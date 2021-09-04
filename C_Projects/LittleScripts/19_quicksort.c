// quick sort --- C.A.RHoare 1962


# include <stdio.h>

// swap v[i] <---> v[j]
void swap(int v[], int i, int j); 
// quick sort: ⬆
void qsort(int v[], int left, int right);


// test 
int main()
{
    int v[12] = {12, 45, -12, 78, -323, 56, 656, 9, -1, 12, 75, 23};
    qsort(v, 0, 12 - 1);
    for(int i = 0; i < 12; i++)
        printf("%d ", v[i]);
}


// swap()
void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// quick sort
// Each time you divide a subset, 
// always select the middle element of the sub-array
void qsort(int v[], int left, int right)
{
    // declaration
    int i, last;
    void swap(int v[], int i, int j);

    if(left >= right)   // number of elements < 2
        return;

    // move the divide element(v[(left + right) / 2]) to v[0]
    swap(v, left, (left + right) / 2);
    last = left;

    for(i = left + 1; i <= right; i++)
    {
        if(v[i] < v[left])
            swap(v, ++last, i);
    }

    // Restore the divide element of the sub-set
    swap(v, left, last);

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}