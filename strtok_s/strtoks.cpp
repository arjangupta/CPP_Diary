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
	if (str == NULL || strmax == NULL || delim == NULL || ptr == NULL)
	{
		std::cout << "debug1\n";
		return NULL;
	}
	else if (*strmax != sizeof(str)) //will not work, sizeof is being called on ptr
	{
		std::cout << "debug2 - " << sizeof(str) << std::endl;
		return NULL;
	}
	else
	{
		char *restrict newStr = strtok_r(str, delim, ptr);
		*strmax = sizeof(newStr);
		return newStr;
	}
	std::cout << "debug3\n";
	return NULL;
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
	size_t maxstr = 11;
	x2 = strtok_sa(s3, &maxstr, "-", &sp2);

	printf("%s\n", x2);

	char s4[] = "this string is 23 long";
	char s5[] = "abc";

	printf("%lu and %lu and %lu\n", sizeof(s3), sizeof(s4), sizeof(s5));

	return 0;
} 


