#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned int index, sum;
	size_t length, additional;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	length = strlen(argv[1]);
	key[0] = charset[(length ^ 59) & 63];

	for (index = 0, additional = 0; index < length; index++)
		additional += argv[1][index];
	key[1] = charset[(additional ^ 79) & 63];

	for (index = 0, sum = 1; index < length; index++)
		sum *= argv[1][index];
	key[2] = charset[(sum ^ 85) & 63];

	for (sum = argv[1][0], index = 0; index < length; index++)
		if ((char)sum <= argv[1][index])
			sum = argv[1][index];
	srand(sum ^ 14);
	key[3] = charset[rand() & 63];

	for (sum = 0, index = 0; index < length; index++)
		sum += argv[1][index] * argv[1][index];
	key[4] = charset[(sum ^ 239) & 63];

	for (sum = 0, index = 0; (char)index < argv[1][0]; index++)
		sum = rand();
	key[5] = charset[(sum ^ 229) & 63];

	printf("%s\n", key);
	return (0);
}
