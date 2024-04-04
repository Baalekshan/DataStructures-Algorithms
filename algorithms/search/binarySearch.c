#include <stdio.h>
int main() {
    int a[50], i, n, upper, lower, mid, val, found, att = 0;
    printf("Enter array size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        a[i] = 2 * i;
    printf("\nElements in Sorted Order:\n");
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\nEnter element to locate: ");
    scanf("%d", &val);
    upper = n;
    lower = 0;
    found = -1;
    while (lower <= upper) {
        mid = (upper + lower) / 2;
        att++;
        if (a[mid] == val) {
            printf("Found at index %d in %d attempts", mid, att);
            found = 1;
            break;
        } else if (a[mid] > val) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    if (found == -1)
        printf("Element not found");
    return 0;
}
