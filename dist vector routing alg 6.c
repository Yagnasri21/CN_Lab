#include <stdio.h>

int main() {
    int i, j, nv, sn, noadj, edel[20], tdel[20][20], min;
    char sv, adver[20], ch;

    printf("\nENTER THE NUMBER OF VERTICES: ");
    scanf("%d", &nv);

    printf("\nENTER THE SOURCE VERTEX NUMBER AND NAME: ");
    scanf("%d", &sn);
    getchar(); // consume newline
    sv = getchar();

    printf("\nENTER NUMBER OF ADJACENT VERTICES TO VERTEX %c: ", sv);
    scanf("%d", &noadj);

    for (i = 0; i < noadj; i++) {
        printf("\nENTER TIME DELAY and NODE NAME: ");
        scanf("%d %c", &edel[i], &adver[i]);
    }

    for (i = 0; i < noadj; i++) {
        printf("\nENTER THE TIME DELAY FROM %c TO ALL OTHER NODES: ", adver[i]);
        for (j = 0; j < nv; j++) {
            scanf("%d", &tdel[i][j]);
        }
    }

    printf("\nDELAY VIA -- VERTEX\n");
    for (i = 0; i < nv; i++) {
        min = 1000;
        ch = '-';
        for (j = 0; j < noadj; j++) {
            if (min > (tdel[j][i] + edel[j])) {
                min = tdel[j][i] + edel[j];
                ch = adver[j];
            }
        }
        if (i != sn - 1)
            printf("\n%d %c", min, ch);
        else
            printf("\n0 -");
    }

    return 0;
}
