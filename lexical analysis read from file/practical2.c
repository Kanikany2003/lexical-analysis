#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // Include this to fix the 'exit' function issue

int is_operator(char *s1);
int is_keyword(char *str);

int main()
{
    char c, exp[1000], s1[20], s2[20];
    int i, j, k, l, error, braces = 0, uoperator_ = 0, boperator_ = 0, identifier = 0, constant_ = 0;
    FILE *f1;

    // Initialize strings
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));

    printf("Enter the string\n");
    printf("At end enter @\n");

    // Read the input string
    for (i = 0; (c = getchar()) != '@'; i++)
    {
        if (i >= sizeof(exp) - 1)
        {
            printf("Error: Input string too long\n");
            exit(1);
        }
        exp[i] = c;
    }
    exp[i] = '@'; // Mark end of input
    i = 0;

    while (exp[i] != '@')
    {
        j = 0;

        // Skip whitespaces, tabs, and semicolons
        while (exp[i] == ' ' || exp[i] == '\n' || exp[i] == '\t' || exp[i] == ';')
        {
            i++;
        }

        // Check if the character is an operator
        if (is_operator(&exp[i]))
        {
            k = 0;
            while (k < 2 && exp[i] != ';' && exp[i] != ' ' && exp[i] != '@' && exp[i] != '\n' &&
                   exp[i] != '\t' && !isalnum(exp[i]) && exp[i] != '_')
            {
                if (j >= sizeof(s1) - 1)
                {
                    printf("Error: Buffer overflow in s1\n");
                    exit(1);
                }
                s1[j] = exp[i];
                i++;
                j++;
                k++;
            }
            s1[j] = '\0';

            // Handle operators
            f1 = fopen("/Users/kanikaim-erb/Documents/sem6/CompilerDesign/operator.txt", "r");

            if (f1 == NULL)
            {
                printf("Failed to open operator.txt\n");
                exit(1); // Exit program if file not found
            }
            while (fscanf(f1, "%s", s2) != EOF)
            {
                if (strcmp(s1, s2) == 0)
                {
                    printf("\n%s is operator", s1);
                    if (strcmp(s1, "++") == 0 || strcmp(s1, "--") == 0)
                    {
                        uoperator_++;
                    }
                    else
                    {
                        boperator_++;
                    }
                    if (strcmp(s1, "(") == 0 || strcmp(s1, "{") == 0 || strcmp(s1, "[") == 0)
                    {
                        braces++;
                    }
                    if (strcmp(s1, ")") == 0 || strcmp(s1, "}") == 0 || strcmp(s1, "]") == 0)
                    {
                        braces--;
                    }
                    fclose(f1);
                    break;
                }
            }
            fclose(f1);
        }
        else
        {
            // Process other cases: keywords, constants, identifiers
            j = 0;
            while (exp[i] != ' ' && exp[i] != '@' && exp[i] != ';' && exp[i] != '"' && exp[i] != '\n' &&
                   exp[i] != '\t' && !is_operator(&exp[i]))
            {
                if (j >= sizeof(s1) - 1)
                {
                    printf("Error: Buffer overflow in s1\n");
                    exit(1);
                }
                s1[j] = exp[i];
                i++;
                j++;
            }
            s1[j] = '\0';

            // Check for keywords
            if (is_keyword(s1))
            {
                printf("\n%s is a keyword", s1);
            }
            else
            {
                // Check if it's a constant
                error = 0;
                l = strlen(s1);
                int dot_count = 0;
                for (j = 0; j < l; j++)
                {
                    if (isdigit(s1[j]) || s1[j] == '.')
                    {
                        if (s1[j] == '.')
                        {
                            dot_count++;
                        }
                    }
                    else
                    {
                        error = 1;
                        break;
                    }
                }
                if (dot_count > 1)
                {
                    printf("\n%s is constant which should not contain more than 1 decimal point", s1);
                }
                else if (!error)
                {
                    printf("\n%s is constant", s1);
                    constant_++;
                }
                else
                {
                    // Check for identifiers
                    if ((s1[0] >= '0' && s1[0] <= '9') || s1[0] == '_')
                    {
                        printf("\n%s is identifier which should not start with %c", s1, s1[0]);
                    }
                    else
                    {
                        error = 0;
                        for (j = 0; j < l; j++)
                        {
                            if (!isalnum(s1[j]) && s1[j] != '_')
                            {
                                error = 1;
                                printf("\n%s is identifier which should not contain %c", s1, s1[j]);
                                break;
                            }
                        }
                        if (!error)
                        {
                            printf("\n%s is identifier", s1);
                            identifier++;
                        }
                    }
                }
            }
        }
    }

    // Expression syntax check
    if ((identifier && boperator_ != 0) && ((identifier + constant_) == boperator_))
    {
        printf("\nError: Expression syntax error");
    }
    if (braces != 0)
    {
        printf("\nError: Brace mismatch");
    }

    return 0;
}

int is_operator(char *s1)
{
    FILE *f1;
    char s2[20]; // A buffer to store operator strings from the file
    f1 = fopen("/Users/kanikaim-erb/Documents/sem6/CompilerDesign/operator.txt", "r");
    if (f1 == NULL)
    {
        printf("Failed to open operator.txt in is_operator()\n");
        exit(1);
    }
    while (fscanf(f1, "%s", s2) != EOF)
    {
        if (strcmp(s1, s2) == 0)
        {
            fclose(f1);
            return 1;
        }
    }
    fclose(f1);
    return 0;
}

int is_keyword(char *str)
{
    // List of C keywords for comparison
    char *keywords[] = {"int", "char", "float", "const", "goto", "return", "for", "while", "if", "else", "switch", "case", "break", "continue", "default", NULL};

    for (int i = 0; keywords[i] != NULL; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return 1; // It is a keyword
        }
    }
    return 0; // It is not a keyword
}
