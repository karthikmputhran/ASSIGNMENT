#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_balance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

int validate_card_number(char *card_number) {
    return (strlen(card_number) == 16 && strspn(card_number, "0123456789") == 16);
}

int validate_upi_id(char *upi_id) {
    return (strstr(upi_id, "@") != NULL);
}

int main() {
    float current_balance = 1000.00;
    display_balance(current_balance);

    int payment_method;
    float amount;

    while (1) {
        printf("Select Payment Method:\n");
        printf("1 for Credit/Debit Card\n");
        printf("2 for UPI\n");
        printf("3 for Net Banking\n");

        printf("Select Payment Method (1-3): ");
        scanf("%d", &payment_method);

        if (payment_method < 1 || payment_method > 3) {
            printf("Invalid payment method. Please try again.\n");
            continue;
        }

        if (payment_method == 1) {
            char card_number[17];
            printf("Enter a 16-digit card number: ");
            scanf("%s", card_number);
            if (!validate_card_number(card_number)) {
                printf("Transaction Failed: Invalid card number. Please enter a valid 16-digit card number.\n");
                continue;
            }
        } else if (payment_method == 2) {
            char upi_id[50];
            printf("Enter your UPI ID (e.g., user@upi): ");
            scanf("%s", upi_id);
            if (!validate_upi_id(upi_id)) {
                printf("Transaction Failed: Invalid UPI ID. Please enter a valid UPI ID (e.g., user@upi).\n");
                continue;
            }
        } else if (payment_method == 3) {
            int bank_choice;
            printf("Select a bank:\n");
            printf("1 for SBI\n");
            printf("2 for HDFC\n");
            printf("3 for ICICI\n");
            printf("Select your bank (1-3): ");
            scanf("%d", &bank_choice);
            if (bank_choice < 1 || bank_choice > 3) {
                printf("Transaction Failed: Invalid bank selection. Please select a valid bank (1-3).\n");
                continue;
            }
        }

        printf("Enter the amount to be transferred: $");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid amount. Please enter a positive number.\n");
            continue;
        }
        if (amount > current_balance) {
            printf("Insufficient balance. Please try again.\n");
            continue;
        }

        printf("Payment Successful!\n");
        current_balance -= amount;
        display_balance(current_balance);
        break;
    }

    return 0;
}
