#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
return (*(float *)a - *(float *)b);
}
void sort_prices(float prices[], int n) {
qsort(prices, n, sizeof(float), compare);
}
int main() {
float prices[] = {19.99, 5.49, 15.00, 25.00};
int n = sizeof(prices) / sizeof(prices[0]);
sort_prices(prices, n);
printf("Sorted Prices: ");
for (int i = 0; i < n; i++) {
printf("%.2f ", prices[i]);
}
printf("\n");
return 0;
}