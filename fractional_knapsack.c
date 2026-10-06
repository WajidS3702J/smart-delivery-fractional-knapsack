#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Package {
    int id;
    float value;
    float weight;
    float ratio;
    float selected;
};

void calculateRatio(struct Package p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].weight > 0)
            p[i].ratio = p[i].value / p[i].weight;
        else
            p[i].ratio = 0;
    }
    printf("\nValue/Weight ratios calculated successfully.\n");
}

void sortPackages(struct Package p[], int n) {
    int i, j;
    struct Package temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].ratio < p[j + 1].ratio) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nPackages sorted by decreasing Value/Weight ratio.\n");
}

void displayPackages(struct Package p[], int n) {
    int i;
    printf("\n------------------------------------------------------------\n");
    printf("ID\tValue\tWeight\tValue/Weight Ratio\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", p[i].id, p[i].value, p[i].weight, p[i].ratio);
    }
    printf("------------------------------------------------------------\n");
}

void findMaximumValue(struct Package p[], int n, float capacity) {
    int i;
    float remaining = capacity;
    float totalValue = 0.0;
    float totalWeight = 0.0;

    for (i = 0; i < n; i++)
        p[i].selected = 0.0;

    for (i = 0; i < n; i++) {
        if (remaining <= 0)
            break;
        if (p[i].weight <= remaining) {
            p[i].selected = 1.0;
            remaining -= p[i].weight;
            totalWeight += p[i].weight;
            totalValue += p[i].value;
        } else {
            p[i].selected = remaining / p[i].weight;
            totalWeight += remaining;
            totalValue += p[i].value * p[i].selected;
            remaining = 0;
        }
    }

    printf("\n========== FRACTIONAL KNAPSACK RESULT ==========\n");
    printf("\nSelected Packages:\n");
    printf("------------------------------------------------------------\n");
    printf("ID\tFraction\tWeight Used\tValue Obtained\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        if (p[i].selected > 0) {
            printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", p[i].id, p[i].selected,
                   p[i].weight * p[i].selected, p[i].value * p[i].selected);
        }
    }
    printf("------------------------------------------------------------\n");
    printf("Total Weight Used : %.2f\n", totalWeight);
    printf("Maximum Value     : %.2f\n", totalValue);
    printf("Remaining Capacity: %.2f\n", remaining);
    printf("============================================================\n");
}

int main() {
    struct Package packages[MAX];
    int n = 0, choice, i;
    float capacity = 0.0;

    do {
        printf("\n\n==============================================\n");
        printf("       SMART DELIVERY PLANNING\n");
        printf("       FRACTIONAL KNAPSACK\n");
        printf("==============================================\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("----------------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1:
            printf("\nEnter number of packages: ");
            scanf("%d", &n);
            if (n <= 0 || n > MAX) {
                printf("Invalid number of packages!\n");
                n = 0;
                break;
            }
            printf("Enter vehicle capacity: ");
            scanf("%f", &capacity);
            for (i = 0; i < n; i++) {
                packages[i].id = i + 1;
                printf("\nPackage %d\n", i + 1);
                printf("Enter value/profit: ");
                scanf("%f", &packages[i].value);
                printf("Enter weight: ");
                scanf("%f", &packages[i].weight);
                packages[i].ratio = 0;
                packages[i].selected = 0;
            }
            printf("\nPackage details entered successfully.\n");
            break;

        case 2:
            if (n == 0) {
                printf("\nPlease enter package details first.\n");
            } else {
                printf("\nVehicle Capacity: %.2f\n", capacity);
                displayPackages(packages, n);
            }
            break;

        case 3:
            if (n == 0) {
                printf("\nPlease enter package details first.\n");
            } else {
                calculateRatio(packages, n);
                displayPackages(packages, n);
            }
            break;

        case 4:
            if (n == 0) {
                printf("\nPlease enter package details first.\n");
            } else {
                calculateRatio(packages, n);
                sortPackages(packages, n);
                displayPackages(packages, n);
            }
            break;

        case 5:
        case 6:
            if (n == 0) {
                printf("\nPlease enter package details first.\n");
            } else if (capacity <= 0) {
                printf("\nInvalid vehicle capacity.\n");
            } else {
                calculateRatio(packages, n);
                sortPackages(packages, n);
                findMaximumValue(packages, n, capacity);
            }
            break;

        case 7:
            printf("\nExiting program...\n");
            printf("Thank you!\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
