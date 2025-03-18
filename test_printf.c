#include <stdio.h>

int	main(int argc, char* argv[])
{
	int ret;
	char* str;

	str = "hello";
	ret = printf("Hello this is xx%kxx\n", str);
	printf("Printf len is %i\n", ret);

}
