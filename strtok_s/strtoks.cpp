/* 
 * Author: Arjan Gupta
 * Purpose: Write a strtok wrapper called strtok_s
 */

#include <string.h>
#include <iostream>

/* restrict does not natively exist in C++, but
 * this program will be later translated to C.
 */
#define PLAYING_AROUND true
#define restrict __restrict__

char *
strtok_sa (char *restrict str, size_t *restrict strmax, const char *restrict delim, char **restrict ptr)
{
	char *endTok;

	if (str == NULL)
		str = *ptr;

	if (*str == '\0')
	{
		*ptr = str;
		return NULL;
	}

	str += strspn (str, delim); //accept
	if (*str == '\0')
	{
		*ptr = str;
		return NULL;
	}

	endTok = str + strcspn (str, delim); //reject
	if (*endTok == '\0')
	{
		*ptr = endTok;
		return str;
	}

	/* Terminate the token and make *SAVE_PTR point past it.  */
	*endTok = '\0';
	*ptr = endTok + 1;
	return str;
}

int main () 
{
#if PLAYING_AROUND
	char s1[] = "-abc-=-def";
	char *sp, *x;
	x = strtok_r(s1, "-", &sp);	// x = "abc", sp = "=-def"
	std::cout << x << std::endl;
	x = strtok_r(NULL, "-=", &sp);	// x = "def", sp = NULL
	std::cout << x << std::endl;
	x = strtok_r(NULL, "=", &sp);	// x = NULL

	printf("%s\n", x);

	char s2[] = "-abc-=-defdef";
	x = strtok(s2, "-");
	x = strtok(NULL, "-=");

	printf("%s\n", x);

	printf("%lu\n\n", strlen(x));

	/*
	char s3[] = "-abc-=-def";
	char *sp2, *x2;
	size_t maxstr = 11;
	x2 = strtok_sa(s3, &maxstr, "-", &sp2);

	printf("%s\n", x2);*/

	char s4[] = "this string is 23 long";
	char s5[] = "abc";

	printf("%lu and %lu\n\n", sizeof(s4), sizeof(s5));

	size_t psn1 = strspn("=-def", "-=");
	std::cout << psn1 << std::endl << std::endl;

	size_t psn2 = strcspn(s5, "d"); //this is strCspn, it rejects. different from strspn, which accepts
	std::cout << psn2 << std::endl;
	std::cout << ( *(s5 + psn2) == '\0' ) << std::endl << std::endl;

	x = strtok_r(NULL, "er", &sp);

	printf("%s\n", x);

#endif //PLAYIING_AROUND
	return 0;
} 


