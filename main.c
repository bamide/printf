#include <limits.h>
#include <stdio.h>

#define F_MINUS 1
#define F_PLUS  2
#define F_ZERO  4
#define F_HASH  8
#define F_SPACE 16

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Parameter.
 *
 * Return: Flags.
 */
int get_flags(const char *format, int *i)
{
    int j, curr_i;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    /* Loop through the format string to find flags */
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        /* Check for each flag character */
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[curr_i] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        /* If the character is not a flag, exit the loop */
        if (FLAGS_CH[j] == 0)
        {
            break;
        }
    }

    /* Update the parameter with the current index */
    *i = curr_i - 1;

    return (flags);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned int ui;
    void *addr;
    int i, flags;

    printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    printf("Negative:[%d]\n", -762534);
    printf("Unsigned:[%u]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Character:[%c]\n", 'H');
    printf("String:[%s]\n", "I am a string !");
    printf("Address:[%p]\n", addr);
    printf("Percent:[%%]\n");
    printf("Len:[%d]\n", printf("Percent:[%%]\n"));

    /* Call the get_flags() method */
    i = 0;
    flags = get_flags("Example format string with flags: %+-#10d", &i);
    printf("Calculated flags: %d\n", flags);

    return (0);
}


