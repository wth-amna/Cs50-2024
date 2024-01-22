#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float avgLetter(int letters, int words);
float avgSent(int sent, int words);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index

    float L = avgLetter(letters, words);
    float S = avgSent(sentences, words);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    // Print the grade level

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_letters(string text)
{
    int count = 0;
    // Return the number of letters in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    // Return the number of words in text
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    // Return the number of sentences in text
    return count;
}

float avgLetter(int letters, int words)
{
    float averageLetter = (letters / (float) words) * 100;
    return averageLetter;
}

float avgSent(int sent, int words)
{
    float averageSent = (sent / (float) words) * 100;
    return averageSent;
}
