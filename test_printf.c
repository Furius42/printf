#include <stdio.h>

int	main(int argc, char* argv[])
{
	int ret;
	int num;
	char* str;

	num = (long int)&argc;
	str = argv[1];
	ret = printf("you wrote %s it's address is: %p\n now using bitoa code address is: 0x%s", str, num, ft_bitoa(num, 16));
	printf("Printf len is %i\n", ret);

}
