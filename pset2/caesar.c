#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // yell if user doesn't give single command line argument
    if (argc != 2)
    {
        printf("You should provide a command line argument!");
        return 1;
    }

    // convert string from command line argument to integer key
    int key = atoi(argv[1]);

    // get user input
    printf("\nplaintext: ");
    string text = get_string();

    // encrypt message with caesar cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // check if its valid alphabetical character
        if (isalpha(text[i]))
        {
            // encryption for uppercase letter
            if (isupper(text[i]))
            {
                printf("%c", ((text[i] - 'A' + key) % 26) + 'A');
            }
            // encryption for lowercase letter
            else
            {
                printf("%c", ((text[i] - 'a' + key) % 26) + 'a');
            }
        }
        // otherwise, just ignore it without encryption
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}