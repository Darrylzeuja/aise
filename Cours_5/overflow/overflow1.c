#include <stdlib.h>
#include <stdio.h>
/* gcc -m32 -o overflow1 overflow1.c -fno-stack-protector */
int main()
{
	int var;
	int check = 0x04030201;
	char buf[40];

	fgets(buf,45,stdin);

	printf(" [buf]: %s", buf);
	printf("[check] %p", check);

	if (check == 0xdeadbeef) {
		printf("You Win !");
		system("/bin/sh");
	}
	return 0;
}
