#include <stdio.h>

#define MAX 10

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < r2; i++) {
        for(int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n--- MENU ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            if(r1 == r2 && c1 == c2) {
                for(int i = 0; i < r1; i++) {
                    for(int j = 0; j < c1; j++) {
                        result[i][j] = a[i][j] + b[i][j];
                    }
                }
                printf("Result of Addition:\n");
                for(int i = 0; i < r1; i++) {
                    for(int j = 0; j < c1; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Addition not possible (different sizes).\n");
            }
            break;

        case 2: 
            if(r1 == r2 && c1 == c2) {
                for(int i = 0; i < r1; i++) {
                    for(int j = 0; j < c1; j++) {
                        result[i][j] = a[i][j] - b[i][j];
                    }
                }
                printf("Result of Subtraction:\n");
                for(int i = 0; i < r1; i++) {
                    for(int j = 0; j < c1; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Subtraction not possible (different sizes).\n");
            }
            break;

        case 3: 
            if(c1 == r2) {
                for(int i = 0; i < r1; i++) {
                    for(int j = 0; j < c2; j++) {
                        result[i][j] = 0;
                        for(int k = 0; k < c1; k++) {
                            result[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
                printf("Result of Multiplication:\n");
                for(int i = 0; i < r1; i++) {
                    for(int j = 0; j < c2; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("Multiplication not possible.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
