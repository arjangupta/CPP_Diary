/* 
 * Author: Arjan Gupta
 * Purpose: Write a strtok wrapper called strtok_s
 */

//#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <iostream>

#define PLAYING_AROUND false

/* restrict does not natively exist in C++, but
 * this program will be later translated to C.
 */
#define restrict __restrict__

/*
 * This function tries to imitate what the standard strtok_s would do.
 * strtok_s - http://en.cppreference.com/w/c/string/byte/strtok
 *
 * CURRENT PRE-CONDITION: str MUST be a null-terminated string.
 */
char *
strtok_sa (char *restrict str, size_t *restrict strmax, const char *restrict delim, char **restrict ptr)
{
	char *endTok;
	static size_t __strmax;

	if (str != NULL)
	{
		__strmax = 0;
	}

	if (__strmax == 0)
	{
		if (*strmax == 0 || *strmax > SIZE_MAX)
		{
			std::cout << "debug(-3)" << std::endl;
			return NULL;
		}
		__strmax = *strmax;
	} 
	else if (__strmax != *strmax)
	{
		std::cout << "debug(-2), __strmax: " << __strmax << std::endl;
		return NULL;
	}

	if (strmax == NULL || delim == NULL || ptr == NULL)
	{
		std::cout << "debug(-1)" << std::endl;
		return NULL;
	}

	if (str == NULL)
	{
		if (*ptr == NULL)
		{
			std::cout << "debug0" << std::endl;
			return NULL;
		} else {
			str = *ptr;
		}
	}

	if (*str == '\0')
	{
		*ptr = str;
		std::cout << "debug1" << std::endl;
		return NULL;
	}

	if (*strmax < strspn (str, delim))
	{
		std::cout << "debug2" << std::endl;
		return NULL;
	} else {
		*strmax = *strmax - strspn (str, delim);
		__strmax = *strmax;
	}

	str += strspn (str, delim); //accept

	if (*str == '\0')
	{
		*ptr = str;
		std::cout << "debug3" << std::endl;
		return NULL;
	}

	if (*strmax < strcspn (str, delim))
	{
		std::cout << "debug4" << std::endl;
		return NULL;
	} else {
		*strmax = *strmax - strcspn (str, delim);
		__strmax = *strmax;
	}

	endTok = str + strcspn (str, delim); //reject

	if (*endTok == '\0')
	{
		*ptr = endTok;
		std::cout << "debug5 - " << str << std::endl;
		return str;
	}

	*endTok = '\0';
	*ptr = endTok + 1;
	__strmax = *strmax;
	std::cout << "debug6 - " << str << std::endl;
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

#endif //PLAYING_AROUND

	char s6[] = "abc&xyz&def&pqr";
	char *saveptr = NULL, *x3 = NULL;
	size_t maxsz = 3 + 1 + 3 + 1 + 3 + 1 + 3;
	x3 = strtok_sa(s6, &maxsz, "&", &saveptr);	// x3 = "abc", saveptr = "xyz&def&pqr"
	std::cout << "First call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);	// x3 = "xyz", saveptr = "def&pqr"
	std::cout << "Second call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);	// x3 = "def", saveptr = "pqr"
	//std::cout << "Third call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);	// x3 = "pqr", saveptr = NULL
	//std::cout << "Fourth call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);

	std::cout << "\nNEXT TEST\n\n";

	char s7[] = "& && ";
	saveptr = NULL;
	x3 = NULL;
	const char dlmtr[2] = "&";
	maxsz = 3 + 1 + 3 + 1 + 3 + 1 + 3;
	x3 = strtok_sa(s7, &maxsz, dlmtr, &saveptr);	// x3 = "abc", saveptr = "xyz&def&pqr"
	std::cout << "First call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);	// x3 = "xyz", saveptr = "def&pqr"
	std::cout << "Second call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);	// x3 = "def", saveptr = "pqr"
	//std::cout << "Third call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);	// x3 = "pqr", saveptr = NULL
	//std::cout << "Fourth call, x3: " << x3 << ", saveptr: " << saveptr << ", maxsz:" << maxsz << std::endl;
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);
	x3 = strtok_sa(NULL, &maxsz, "&", &saveptr);

	/*char *x4 = NULL;
	std::cout << x4 << std::endl;*/

	std::cout << "\nEND.\n\n";

	return 0;
} 


