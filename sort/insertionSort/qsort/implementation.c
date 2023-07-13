#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems <= 1) {
        return;
    }

    char *pivot = (char *)base + (nitems - 1) * size;
    char *left = (char *)base;
    char *right = pivot - size;

    while (left <= right) {
        while (left <= right && compar(left, pivot) < 0) {
            left += size;
        }

        while (left <= right && compar(right, pivot) > 0) {
            right -= size;
        }

        if (left <= right) {
            char tmp[size];
            memcpy(tmp, left, size);
            memcpy(left, right, size);
            memcpy(right, tmp, size);
            left += size;
            right -= size;
        }
    }

    char tmp[size];
    memcpy(tmp, left, size);
    memcpy(left, pivot, size);
    memcpy(pivot, tmp, size);

    qsort(base, (left - (char *)base) / size, size, compar);
    qsort(left + size, nitems - ((left - (char *)base) / size) - 1, size, compar);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {3, 5, 1, 9, 8, 2, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Output: 1 2 3 4 5 6 7 8 9 
