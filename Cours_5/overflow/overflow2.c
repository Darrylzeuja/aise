/*
   gcc -m32 -fno-stack-protector -o overflow2 overflow2.c
   */

#include <stdio.h>
#include <stdlib.h>

void shell() {
	system("/bin/sh");
}

void sup() {
	printf("You can do better than that...\n");
}

int main()
{ 
	int var;
	void (*func)()=sup;
	char buf[128];
	fgets(buf,133,stdin);
	func();
	return 0;
}
