#include <stdio.h>
#include <string.h>

int main() {
    char stuffed[200];
    int destuffed[200];
    int i, j = 0, count = 0, n;

    printf("Enter the stuffed data frame: ");
    scanf("%s", stuffed);

    n = strlen(stuffed);

    // Skip the starting and ending flag (first 8 bits and last 8 bits)
    for (i = 8; i < n - 8; i++) {
        if (stuffed[i] == '1') {
            destuffed[j++] = 1;
            count++;
            if (count == 5) {
                // skip stuffed '0'
                i++;
                count = 0;
            }
        } else {
            destuffed[j++] = 0;
            count = 0;
        }
    }

    printf("\nDestuffed Data: ");
    for (i = 0; i < j; i++)
        printf("%d", destuffed[i]);

    printf("\n");
    return 0;
}
