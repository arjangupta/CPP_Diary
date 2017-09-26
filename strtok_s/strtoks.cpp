/* 
 * Author: Arjan Gupta
 * Purpose: Write a strtok wrapper called strtok_s
 */

#include <string.h>
#include <iostream>

/* restrict does not natively exist in C++, but
 * this program will be later translated to C.
 */
#define restrict __restrict__

//precondition: str MUST be null-terminated
char *strtok_sa(char *restrict str, size_t *restrict strmax,
     const char *restrict delim, char **restrict ptr)
{
	return strtok_r(str, delim, ptr);
}

int main () 
{
	char s1[] = "-abc-=-def";
	char *sp, *x;
	x = strtok_r(s1, "-", &sp);	// x = "abc", sp = "=-def"
	x = strtok_r(NULL, "-=", &sp);	// x = "def", sp = NULL
	//x = strtok_r(NULL, "=", &sp);	// x = NULL

	printf("%s\n", x);

	char s2[] = "-abc-=-defdef";
	x = strtok(s2, "-");
	x = strtok(NULL, "-=");

	printf("%s\n", x);

	printf("%lu\n\n", strlen(x));

	char s3[] = "-abc-=-def";
	char *sp2, *x2;
	size_t maxstr = 10;
	x2 = strtok_sa(s3, &maxstr, "-", &sp2);

	printf("%s\n", x);

	return 0;
} 


