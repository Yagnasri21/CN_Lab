#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main() {
  char encoded[100],decoded[500];
  int i=0,j=0,n;
  printf("ENTER THE STUFFED DATA:");
  fgets(encoded,sizeof(encoded),stdin);
  //remove newline from fgets
  encoded[strcspn(encoded,"\n")]='\0';
  n = strlen(encoded);
  while (i<n) {
    if (encoded[i] == '$') {
      i++;// move past '$'
      //read count (can be 2 digts,e.g.05,12,etc.)
      int count = 0,k;
      while (isdigit(encoded[i])) {
        count = count * 10 + (encoded[i] - '0');
        i++;
      }

      char bit = encoded[i];
      i++;

      for(k = 0;k < count;k++) {
        decoded[j++] = bit;
      }
    }else {
            // normal character, just copy
            decoded[j++] = encoded[i++];
        }
    }


    decoded[j]= '\0';

    printf("\nDECODED BIT STRING: %s\n",decoded);
    return 0;

  }


