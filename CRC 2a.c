#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, m, n, cl;
    char a[10], b[100], c[200];  // increased size of c for safety

    printf("\nENTER POLYNOMIAL: ");
    scanf("%s", a);

    printf("\nENTER THE FRAME: ");
    scanf("%s", b);

    m = strlen(a);
    n = strlen(b);

    // Remove leading zeros in polynomial
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

    cl = m + n - 1;

    // Copy the original frame to c[]
    for (i = 0; i < n; i++)
        c[i] = b[i];

    // Add (m-1) zeros at the end of frame
    for (i = n; i < cl; i++)
        c[i] = '0';
    c[cl] = '\0';  // null terminate

    // Perform division (XOR operation)
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

    // Copy original data back into c[]
    for (i = 0; i < n; i++)
        c[i] = b[i];

    printf("\nTHE MESSAGE IS: %s\n", c);

    return 0;
}
