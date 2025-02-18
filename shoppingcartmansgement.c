#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100
#define MAX_CART_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    int product_id;
    int quantity;
} CartItem;

Product products[MAX_PRODUCTS];
CartItem cart[MAX_CART_ITEMS];
int product_count = 0;
int cart_count = 0;

void add_product() {
    if (product_count < MAX_PRODUCTS) {
        printf("Enter Product ID: ");
        scanf("%d", &products[product_count].id);
        printf("Enter Product Name: ");
        scanf(" %s", products[product_count].name);
        printf("Enter Product Price: ");
        scanf("%f", &products[product_count].price);
        product_count++;
        printf("Product added successfully!\n");
    } else {
        printf("Product limit reached!\n");
    }
}

void add_to_cart(int product_id, int quantity) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == product_id && cart_count < MAX_CART_ITEMS) {
            cart[cart_count++] = (CartItem){.product_id = product_id, .quantity = quantity};
            printf("Added %d of %s to the cart.\n", quantity, products[i].name);
            return;
        }
    }
    printf("Product not found!\n");
}

void display_cart() {
    printf("Shopping Cart Contents:\n");
    for (int i = 0; i < cart_count; i++) {
        for (int j = 0; j < product_count; j++) {
            if (cart[i].product_id == products[j].id) {
                printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                       products[j].id, products[j].name, cart[i].quantity, products[j].price);
            }
        }
    }
}

float calculate_total_cost() {
    float total = 0.0;
    for (int i = 0; i < cart_count; i++) {
        for (int j = 0; j < product_count; j++) {
            if (cart[i].product_id == products[j].id) {
                total += cart[i].quantity * products[j].price;
            }
        }
    }
    return total;
}

float apply_discount(float total, float discount_percentage) {
    return total * (1 - discount_percentage / 100);
}
