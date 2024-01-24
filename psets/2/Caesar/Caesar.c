#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digit(string s);
char rotate(char plaintext, int key);

int main(int argc, string argv[])
{
    // Make sure the program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    only_digit(argv[1]);
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    string plaintext = get_string("plain text: ");

    // Initialize an array to store the encrypted characters
    char ciphertext[strlen(plaintext) + 1]; // +1 for the null terminator

    // Encrypt and store each character in the ciphertext array
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = rotate(plaintext[i], key);
        ciphertext[i] = c;
    }

    // Add the null terminator to make it a valid C string
    ciphertext[strlen(plaintext)] = '\0';

    // Print the resulting ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool only_digit(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return true;
}

// rotates that char by keys positions
char rotate(char character, int key)
{
    if (isalpha(character))
    {
        if (isupper(character))
        {
            char encipher = character - 'A';
            char c = (encipher + key) % 26;
            c = c + 'A';
            character = c;
            return character;
        }
        else if (islower(character))
        {
            char encipher = character - 'a';
            char c = (encipher + key) % 26;
            c = c + 'a';
            character = c;
            return character;
        }
    }

    return character;
}
