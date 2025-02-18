#include <stdio.h>
void format_username(char *username) {
char formatted[100];
int j = 0;
for (int i = 0; username[i] != '\0'; i++) {
if (username[i] != ' ') {
if (username[i] >= 'A' && username[i] <= 'Z') {
formatted[j++] = username[i] + ('a' - 'A');
} else {
formatted[j++] = username[i];
}
}
}
formatted[j] = '\0';
for (int k = 0; k <= j; k++) {
username[k] = formatted[k];
}
}
int main() {
char username[100] = "John Doe";
format_username(username);
printf("Formatted Username: %s\n", username);
return 0;
}