#include <stdio.h>
int main() {
    int list[20];
    int size, i, j, temp;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    printf("Enter the list one by one:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    for (i = 1; i < size; i++) {
        temp = list[i];
        j = i - 1;
        while ((temp < list[j]) && (j >= 0)) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = temp;
    }
    printf("The sorted list is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    return 0;
}
