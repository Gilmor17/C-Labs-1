#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ITEMS 5

typedef struct {
    int code;
    char name[30];
    double price;
} Item;

Item shopItems[MAX_ITEMS] = {
    {1, "Apple", 0.50},
    {2, "Banana", 0.30},
    {3, "Milk", 1.20},
    {4, "Bread", 1.50},
    {5, "Eggs", 2.00}
};

double cartTotal = 0.0;

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add items to shopping cart\n");
    printf("2. Show current total\n");
    printf("3. Check out\n");
    printf("4. Cancel session\n");
    printf("q. Quit\n");
}

void addItem() {
    int code, quantity;
    printf("Available items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d - %s - $%.2f\n", shopItems[i].code, shopItems[i].name, shopItems[i].price);
    }
    printf("Enter item code and quantity: ");
    if (scanf("%d %d", &code, &quantity) != 2 || quantity < 1) {
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (shopItems[i].code == code) {
            cartTotal += shopItems[i].price * quantity;
            printf("Added %d x %s to cart.\n", quantity, shopItems[i].name);
            return;
        }
    }
    printf("Invalid item code.\n");
}

void showTotal() {
    printf("Current total: $%.2f\n", cartTotal);
}

void checkOut() {
    char confirm;
    printf("Are you sure you want to check out? (y/n): ");
    scanf(" %c", &confirm);
    if (tolower(confirm) == 'y') {
        printf("Final total: $%.2f\n", cartTotal);
        cartTotal = 0.0;
        printf("New session started.\n");
    }
}

void cancelSession() {
    char confirm;
    printf("Are you sure you want to cancel the session? (y/n): ");
    scanf(" %c", &confirm);
    if (tolower(confirm) == 'y') {
        cartTotal = 0.0;
        printf("Session canceled. Starting a new session.\n");
    }
}

int main() {
    char choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': addItem(); break;
            case '2': showTotal(); break;
            case '3': checkOut(); break;
            case '4': cancelSession(); break;
            case 'q': printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}