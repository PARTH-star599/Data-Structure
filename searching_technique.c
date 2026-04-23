#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key, choice, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n--- SEARCH MENU ---\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to search: ");
    scanf("%d", &key);

    switch(choice) {
        case 1:
            index = linearSearch(arr, n, key);
            if(index != -1)
                printf("Element found at index %d\n", index);
            else
                printf("Element not found\n");
            break;

        case 2:
            index = binarySearch(arr, n, key);
            if(index != -1)
                printf("Element found at index %d\n", index);
            else
                printf("Element not found\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}