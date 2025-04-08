#include <unistd.h>
#include <stdarg.h>
#include <string.h>

va_list    ap_c;

int    ft_printf(const char *str, ...);
int    convert(char c_char, va_list ap);
char    *ft_bitoa(long long int n, int base);

int    main()
{
    char *str = "String";
    int num = 42;
    int chars = ft_printf("Test %p string: %s\n", &num, str);
    return (0);
}

int    ft_printf(const char *str, ...)
{
    va_list    ap;
    int        len = 0;

    va_start(ap, str);
    while (str != '\0')
    {
        if (*str == '%')
        {
            len += convert(*++str, ap);
            str++;
        }
        else
            len += write(1, (const void*)str++, 1);
    }
    va_end(ap);
    return (len);
}

int    convert(char c_char, va_list ap)
{
    char    *out;
    int len = 0;

    if (c_char == 'c')
    {
        putchar(va_arg(ap, int));
        return (1);
    }
    else if (c_char == 's')
    {
        out = va_arg(ap, char *);
        return (write(1, out, strlen(out)));
    }
    else if (c_char == 'd' || c_char == 'i' || c_char == 'u')
    {
        if (c_char == 'u')
            out = ft_bitoa(va_arg(ap, unsigned int),10);
        else
            out = ft_bitoa(va_arg(ap, int), 10);
        len = write(1, out, strlen(out));
        free(out);
        return (len);
    }
    else if (c_char == 'p' || c_char == 'x' || c_char == 'X')
    {
        if (c_char == 'p')
        {
            len = write(1, "0x", 2);
            out = ft_bitoa(va_arg(ap, long long int), 16);
        }
//        else if (c_char == 'X')
//            out = ft_strupcase(ft_bitoa(va_arg(ap, long long int), 16));
        else
            out = ft_bitoa(va_arg(ap, long long int), 16);
        len += write(1, out, strlen(out));
        free(out);
        return (len);
    }
    else if (c_char == '%')
        return (write(1, &c_char, 1));
    else
    {
        write(1, &"%", 1);
        return (write(1, &c_char, 1) + 1);
    }
}

static int count(long long int n, int base)
{
    int    count;

    count = 0;
    if (n <= 0)
        count = 1;
    while (n != 0)
    {
        n /= base;
        count++;
    }
    return (count);
}

char *con(long long int n, char *str, int len, int base)
{
    unsigned long int num = 0;
    static char *chars = "0123456789abcdef";

    str[len] = '\0';
    while (--len >= 0)
    {
        str[len] = chars[(num % base)];
        num /= base;
    }
    return (str);
}

char    *ft_bitoa(long long int n, int base)
{
    char *str;
    int len = count(n, base);

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str || base > 16 || base < 2)
        return (NULL);
    else
        return (con(n, str, len, base));
}
