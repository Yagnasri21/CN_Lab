#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void charc(void);

int main() {
    int choice;

    while (1) {
        printf("\n\n1. Character Stuffing");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            charc();
        } else if (choice == 2) {
            exit(0);
        } else {
            printf("\nInvalid option... Please re-enter.\n");
        }
    }

    return 0;
}

void charc(void) {
    char c[50], d[100], t[50];
    int i, m, j, k;

    printf("Enter the number of characters: ");
    scanf("%d", &m);

    printf("Enter the characters: ");
    for (i = 0; i < m; i++) {
        scanf(" %c", &c[i]); // space before %c skips newline
    }

    printf("\nOriginal data: ");
    for (i = 0; i < m; i++) {
        printf("%c", c[i]);
    }

    // Stuffing
    j = 0;
    // Start flag
    d[j++] = 'd';
    d[j++] = 'l';
    d[j++] = 'e';
    d[j++] = 's';
    d[j++] = 't';
    d[j++] = 'x';

    for (i = 0; i < m; i++) {
        if (c[i] == 'd' && c[i+1] == 'l' && c[i+2] == 'e') {
            d[j++] = 'd';
            d[j++] = 'l';
            d[j++] = 'e';
        }
        d[j++] = c[i];
    }

    // End flag
    d[j++] = 'd';
    d[j++] = 'l';
    d[j++] = 'e';
    d[j++] = 's';
    d[j++] = 't';
    d[j++] = 'x';

    printf("\nTransmitted data: ");
    for (i = 0; i < j; i++) {
        printf("%c", d[i]);
    }

    // Destuffing
    k = 0;
    for (i = 6; i < j - 6; i++) {
        if (d[i] == 'd' && d[i+1] == 'l' && d[i+2] == 'e' &&
            d[i+3] == 'd' && d[i+4] == 'l' && d[i+5] == 'e') {
            i += 3; // skip extra dle
        }
        t[k++] = d[i];
    }

    printf("\nReceived data: ");
    for (i = 0; i < k; i++) {
        printf("%c", t[i]);
    }
    printf("\n");
}
