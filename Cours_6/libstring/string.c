#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct string_s
{
	char * data;
	int len;
}string;


string * string_init(char * str )
{
	string * ret = malloc(sizeof(struct string_s));

	ret->len = strlen(str);
	ret->data = malloc(ret->len + 1);
	memcpy(ret->data, str, ret->len + 1 );

	return ret;
}


int string_release( string * str)
{
	free(str->data);
	free(str);
	return 0;
}


int string_display( string * str)
{
	printf("%s", str->data);
	return 0;
}

int string_append(string * str, char * app)
{
	int ldata = strlen(str->data);
	int lapp = strlen(app);

	char * appended = malloc( ldata + lapp + 1);

	memcpy(appended, str->data, ldata);
	// +1 pour le \0  et on ecrase le premier
	memcpy(appended + ldata, app, lapp + 1);

	free(str->data);
	str->data = appended;
	
	return 0;
}

string * string_repeat(string * str)
{
	string * ret = string_init(str->data);
	string_append(ret, str->data);
	return ret;
}

string * string_slice(string *str, int start, int end )
{
	int len = end - start + 2;
	char * slice = malloc( len );

	slice[len -1] = '\0';

	string * ret = malloc(sizeof(struct string_s));
	ret->data = slice;
	ret->len = len - 1;

	memcpy(ret->data, str->data + start, end-start + 1);

	return ret;
}

int main(int argc, char ** argv)
{
	string * a  = string_init("coucou ");
	string_append(a, "le monde\n");
	string_display( a );

	string * b = string_repeat( a );
	string_display( b );

	string * s = string_slice(a, 0, 2);
	string_display( s );

	string_release(a);
	string_release(b);
	string_release(s);
}
