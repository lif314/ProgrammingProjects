# include <stdio.h>

// Shell Sort --- D.L.Shell 1959
// Core idea:
// 先比较距离远的元素，而不是像简单的交换排序算法那样先比较相邻的元素。
// 这样可以快速减少大量无需的情况，从而减轻后续的工作。
// 被比较的元素之间的距离逐步减小，找到减小为1，这时排序成了相邻元素之间的交换。
// link: https://riptutorial.com/algorithm/example/24649/shell-sort-basic-information

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for(gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}


// test shellsort
int main()
{
    int array[] = {12, 34, 56, 212, 12, 3, 1,-232, 98};
    int len = sizeof(array) / sizeof(array[0]);
    shellsort(array, len);
    
    for(int i = 0; i < len; i++)
        printf("%d ", array[i]);

    return 0;
}