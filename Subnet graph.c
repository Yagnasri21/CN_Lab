#include <stdio.h>
#include <string.h>

struct full {
    char dest[10];
    char line[10];
    int hops;
} f[20];

int main() {
    int nv, min, minver, i;
    char sv[10], temp;

    printf("\nEnter number of vertices: ");
    scanf("%d", &nv);

    printf("\nEnter source vertex: ");
    scanf("%s", sv);

    printf("\nEnter full table for source vertex %s:\n", sv);
    for (i = 0; i < nv; i++) {
        scanf("%s %s %d", f[i].dest, f[i].line, &f[i].hops);
    }

    printf("\nHIERARCHICAL TABLE\n\n");
    for (i = 0; i < nv;) {
        if (sv[0] == f[i].dest[0]) {
            printf("\n %s %s %d", f[i].dest, f[i].line, f[i].hops);
            i++;
        } else {
            min = 1000;
            minver = 0;
            temp = f[i].dest[0];

            while (i < nv && temp == f[i].dest[0]) {
                if (min > f[i].hops) {
                    min = f[i].hops;
                    minver = i;
                }
                i++;
            }
            printf("\n %c %s %d ", temp, f[minver].line, f[minver].hops);
        }
    }

    return 0;
}
