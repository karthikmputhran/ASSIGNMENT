#include <stdio.h>
#include <string.h>
#include <ctype.h>
void format_username(char *username) {
char temp[100];
int j = 0;
for (int i = 0; username[i] != '\0'; i++) {
if (username[i] != ' ') {
temp[j++] = tolower(username[i]);
}
}
temp[j] = '\0';
strcpy(username, temp);
}
int main() {
char username[100] = "John Doe";
format_username(username);
printf("Formatted Username: %s\n", username);
return 0;
}