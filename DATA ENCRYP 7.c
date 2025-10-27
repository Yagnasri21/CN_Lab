#include<stdio.h>
#include <string.h>
#include <math.h>

// Function to perform modular exponentiation: (base^exp) % mod
int modular_exponentiation(unsigned int base, unsigned int exp, unsigned int mod) {
    unsigned long int result = 1;
    for (int i = 1; i <= exp; i++) {
        result = (result * base) % mod;
    }
    return (unsigned int) result;
}

void main() {
    char message[100];
    unsigned int plaintext[100], ciphertext[100];
    unsigned int n = 253;      // Modulus (product of two primes: p * q)
    unsigned int e = 13;       // Public exponent
    unsigned int d = 17;       // Private exponent
    int i;


    // Input plaintext
    printf("Enter the plain text: ");
    fgets(message, sizeof(message), stdin);

    // Strip newline
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }


    // Convert characters to ASCII integers
    for (i = 0; i < strlen(message); i++) {
        plaintext[i] = (unsigned int) message[i];
    }

    // Encrypt each character using RSA encryption: ct = pt^e mod n
    printf("\nEncrypted Cipher Text (Numeric): ");
	 for (i = 0; i < strlen(message); i++) {
        ciphertext[i] = modular_exponentiation(plaintext[i], e, n);
        printf("%d ", ciphertext[i]);
    }

    // Print original plain text
    printf("\nOriginal Plain Text: ");
    for (i = 0; i < strlen(message); i++) {
        printf("%c", plaintext[i]);
    }

    // Decrypt each character using RSA decryption: pt = ct^d mod n
    printf("\nDecrypted Plain Text: ");
    for (i = 0; i < strlen(message); i++) {
        plaintext[i] = modular_exponentiation(ciphertext[i], d, n);
        printf("%c", plaintext[i]);
    }
}
