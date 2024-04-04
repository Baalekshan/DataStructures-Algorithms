#include<stdio.h>
int qsort[25];
void sort(int low, int high);
void sort(int low, int high) {
    int temp;
    if (low < high) {
        int i = low + 1;
        int j = high;
        int t = qsort[low];
        while (1) {
            while (qsort[i] < t)
                i++;
            while (qsort[j] > t)
                j--;
            if (i < j) {
                temp = qsort[i];
                qsort[i] = qsort[j];
                qsort[j] = temp;
                i++;
                j--;
            } else
                break;
        }
        qsort[low] = qsort[j];
        qsort[j] = t;
        sort(low, j - 1);
        sort(j + 1, high);
    } else
        return;
}
int main() {
    int n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter elements to be sorted:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &qsort[i]);                                 
    sort(1, n);
    printf("\nSORTED ELEMENTS: ");
    for (int i = 1; i <= n; i++)
        printf("%d\t", qsort[i]);
    return 0;
}
