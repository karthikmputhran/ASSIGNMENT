#include <stdio.h>
void bubble_sort(float prices[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (prices[j] > prices[j + 1]) {
float temp = prices[j];
prices[j] = prices[j + 1];
prices[j + 1] = temp;
}
}
}
}
int main() {
float prices[] = {19.99, 5.49, 15.00, 25.00};
int n = sizeof(prices) / sizeof(prices[0]);
bubble_sort(prices, n);
printf("Sorted Prices: ");
for (int i = 0; i < n; i++) {
printf("%.2f ", prices[i]);
}
printf("\n");
return 0;
}