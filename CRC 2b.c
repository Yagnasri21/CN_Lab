#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, m, n, cl;
    char a[10], c[200];  // increased size of c for safety

    printf("\nENTER POLYNOMIAL: ");
    scanf("%s", a);

    printf("\nENTER THE CRC FRAME: ");
    scanf("%s", c);

    m = strlen(a);
    cl = strlen(c);

    // Eliminate first zeros in polynomial
    for (i = 0; i < m; i++) {
        if (a[i] == '1') {
            m = m - i;
            break;
        }
    }

    // Adjust the polynomial
    for (k = 0; k < m; k++)
        a[k] = a[k + i];
    a[m] = '\0';

    n = cl - m + 1;

    // Perform division (XOR with polynomial)
    for (i = 0; i < n; i++) {
        if (c[i] == '1') {
            for (j = i, k = 0; k < m; k++, j++) {
                if (c[j] == a[k])
                    c[j] = '0';
                else
                    c[j] = '1';
            }
        }
    }

    // Check for error
    for (i = 0; i < cl; i++) {
        if (c[i] == '1') {
            printf("\nTHERE IS SOME ERROR IN MESSAGE.\n");
            return 0;
        }
    }

    printf("\nMESSAGE IS CORRECT.\n");

    return 0;
}
