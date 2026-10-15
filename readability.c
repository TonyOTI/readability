#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string word);

int main(void)
{
    string text = get_string("Text? ");

    float letters = 0;
    float words = 1;
    float sentences = 0;
//DETERMINING WHAT IS A LETTER, WORD, SENTENCE
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
// FORMULA FOR GRADE LEVEL
    float l = (letters / words * 100);
    float s = (sentences / words * 100);

    int index = round(0.0588 * l - 0.296 * s - 15.8);
//PRINTING THE ANSWER
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}