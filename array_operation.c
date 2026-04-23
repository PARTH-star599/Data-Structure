#include <stdio.h>

#define MAX 100

// Traverse
void traverse(int arr[], int n) {
    if(n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert
int insert(int arr[], int n, int element, int pos) {
    if(n >= MAX) {
        printf("Array is full.\n");
        return n;
    }
    if(pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return n;
    }

    for(int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;

    printf("Element inserted.\n");
    return n + 1;
}

// Delete
int delete(int arr[], int n, int pos) {
    if(n == 0) {
        printf("Array is empty.\n");
        return n;
    }
    if(pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return n;
    }

    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted.\n");
    return n - 1;
}

// Search
void search(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}

// Update
void update(int arr[], int n, int pos, int value) {
    if(pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }

    arr[pos] = value;
    printf("Element updated.\n");
}

int main() {
    int arr[MAX];
    int n, choice, element, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                traverse(arr, n);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &pos);
                n = insert(arr, n, element, pos);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(arr, n, element);
                break;

            case 5:
                printf("Enter position to update: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &element);
                update(arr, n, pos, element);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 6);

    return 0;
}