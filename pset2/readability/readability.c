#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Get text input
    string text = get_string("Text: ");

    // store number of letters
    int letter = count_letters(text);

    // store number of words
    int word = count_words(text);

    // store number of sentences
    int sentence = count_sentences(text);

    // Coleman-Liau index is computed using the formula: 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text
    float grade = 0.0588 * (100 * (float) letter / (float) word) - 0.296 * (100 * (float) sentence / (float) word) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}

int count_letters(string text)
{
    // Compute and return no of letters
    int letter_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            letter_count += 1;
        }
        if (islower(text[i]))
        {
            letter_count += 1;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    // Compute and return no of words
    int word_count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            word_count += 1;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    // Compute and return no of sentences
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}
