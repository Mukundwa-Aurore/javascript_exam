#include <stdio.h>

// Function prototypes
void printSquare();
void printHalfSquare();
void printRightAngledPascalsTriangle(int height);

int main() {
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Print 4*4 square of stars\n");
        printf("2. Print 4*4 half square\n");
        printf("3. Print right-angled Pascal's triangle of height\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printSquare();
                break;
            case 2:
                printHalfSquare();
                break;
            case 3:
                printRightAngledPascalsTriangle(4); // Right-angled Pascal's triangle of height 4
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to print 4*4 square of stars
void printSquare(int i,int j) {
    for ( i = 0; i < 4; i++) {
        for ( j = 0; j < 4; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print 4*4 half square
void printHalfSquare(int i,int j) {
    for ( i = 0; i < 4; i++) {
        for ( j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print right-angled Pascal's triangle of given height
void printRightAngledPascalsTriangle(int height) {
    int coef = 1;
    int i;
	int j;
    for ( i = 0; i < height; i++) {
        for ( j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;
            printf("%d ", coef);
        }
        printf("\n");
    }
}

