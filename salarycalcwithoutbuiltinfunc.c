#include <stdio.h>
float calculate_total_salary(float base_salary, int experience_years) {
float bonus = 0.0;
for (int i = 0; i < experience_years; i++) {
bonus += 1000;
}
return base_salary + bonus;
}
int main() {
float base_salary = 3000.0;
int experience_years = 5;
float total_salary = calculate_total_salary(base_salary, experience_years);
printf("Total Salary: %.2f\n", total_salary);
return 0;
}