#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
void	ft_puthex(unsigned long num, int *len)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (num >= 16)
		ft_puthex(num / 16, len);
	ft_putchar(hex_digits[num % 16], len);
}
void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}
// void	ft_putnbr(int n, int *len)
// {

// 	if (n == -2147483648)
// 	{
// 		ft_putstr("-2147483648", len);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar('-', len);
// 		n = -n;
// 	}
// 	if (n > 9)
// 	{
// 		ft_putnbr(n / 10, len);
// 	}
// 	ft_putchar((n % 10) + '0', len);

// }

void	ft_putptr(void *ptr, int *len)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	ft_putstr("0x", len);
	if (address == 0)
		ft_putchar('0', len);
	else
		ft_puthex(address, len);
}

// int main()
// {
//     int number = 77935659; // Added missing semicolon
//     int len = 0;

//     // Print the hexadecimal representation
//     printf("Hexadecimal representation: 0x\n");
//     ft_puthex(number, &len);
    
//     printf("\nCharacters printed: %d\n", len);

//     return 0;
// }

int main(void)
{
    int len = 0;           // Counter for the number of characters printed.
    int x = 42;            // Example variable to take the address of.
    void *ptr1 = &x;       // Non-NULL pointer.
    void *ptr2 = NULL;     // NULL pointer.

    // Test with a valid pointer.
    ft_putstr("Pointer to x: ", &len);
    ft_putptr(ptr1, &len);
    ft_putchar('\n', &len);

    // Test with a NULL pointer.
    ft_putstr("NULL pointer: ", &len);
    ft_putptr(ptr2, &len);
    ft_putchar('\n', &len);

    // Print total number of characters printed.
    printf("Total characters printed: %d\n", len);

    return 0;
}