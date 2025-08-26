#include <stdio.h>
#include <string.h>

int main() {
    int b[100], b1[200], n = 0, i, j, k, i1, z, s[20];
    int f[8] = {0,1,1,1,1,1,1,0}; // Flag sequence: 01111110
    char bs[200], ch = 'y';

    do {
        i1 = z = n = 0;

        printf("\nEnter the bit string (use space between bytes): ");
        fgets(bs, sizeof(bs), stdin);

        // Remove newline if present
        bs[strcspn(bs, "\n")] = '\0';

        // Convert string to bits (ignore spaces)
        for (i = 0; bs[i] != '\0'; i++) {
            if (bs[i] != ' ')
                b[n++] = bs[i] - '0';
        }

        // Find positions where stuffing is needed
        for (i = 0; i < n; i++) {
            if (b[i] == 1) {
                i1++;
                if (i1 == 5) {  // after 5 consecutive 1s
                    s[z++] = i + 1; // stuffing position
                    i1 = 0;
                }
            } else {
                i1 = 0;
            }
        }

        j = 0;
        int j1 = 0;
        for (i = 0; i < z; i++) {
            while (j < s[i])
                b1[j1++] = b[j++];
            b1[j1++] = 0; // stuffed zero
        }
        while (j < n)
            b1[j1++] = b[j++];

        // Print result
        printf("\nAfter stuffing:\n");

        // Print starting flag
        for (k = 0; k < 8; k++)
            printf("%d", f[k]);
        printf(" ");

        // Print stuffed data
        for (k = 0; k < j1; k++)
            printf("%d", b1[k]);
        printf(" ");

        // Print ending flag
        for (k = 0; k < 8; k++)
            printf("%d", f[k]);
        printf("\n");

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &ch);
        getchar(); // consume newline

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
