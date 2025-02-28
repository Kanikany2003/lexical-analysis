#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {"if", "else", "eof", "int", "char", "float", "const", "goto", "return", "for", "while", "do", "switch", "case", "break", "continue", "default", NULL};

int main()
{
    char s[100], n[100];
    int i, k, j;

    printf("Enter your string: ");
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0';

    for (i = 0; i < strlen(s); i++)
    {
        k = 0;
        if (s[i] == ' ')
        {
            continue;
        }

        if (isalpha(s[i]) || s[i] == '_')
        {
            while ((isalnum(s[i]) || s[i] == '_') && k < sizeof(n) - 1)
            {
                n[k] = s[i];
                k++;
                i++;
            }
            n[k] = '\0';
            i--;
            for (j = 0; keywords[j] != NULL; j++)
            {
                if (strcmp(n, keywords[j]) == 0)
                {
                    printf("\n%s is a keyword", n);
                    break;
                }
            }
            if (keywords[j] == NULL)
            {
                printf("\n%s is an identifier", n);
            }
        }
        else if (isdigit(s[i]))
        {
            while (isdigit(s[i]) && k < sizeof(n) - 1)
            {
                n[k] = s[i];
                k++;
                i++;
            }
            n[k] = '\0';
            printf("\n%s is a constant", n);
            i--;
        }
        else if (s[i] == '=' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '%' || s[i] == '*')
        {
            printf("\n%c is an operator", s[i]);
        }
        else if (s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']')
        {
            printf("\n%c is a bracket", s[i]);
        }
        else
        {
            printf("\n%c is a special symbol", s[i]);
        }
    }

    return 0;
}
