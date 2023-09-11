
#include "libft.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define STR_INT_MAX "2147483647"
#define STR_INT_MIN "-2147483648"
#define RANDOM_TESTS 1
#define RANDOM_TESTS_NB 100000

int _ok = 1;
int * const ok = &_ok;

void fail(){
	*ok = 0;
}

int are_overlapping(const char *a, const char *b) {
  return (a + strlen(a) == b + strlen(b));
}

int memequal(const void *s1, const void *s2, size_t n){
	return memcmp(s1,s2,n) == 0;
}

int random_int() {
    int random_sign = (rand() % 2 == 0) ? 1 : -1;
    int random_positive = rand();

    return random_positive * random_sign;
}

int assert_ft_strlen(char *s, int len){
	int result = ft_strlen(s);
	printf("-> Testing \"%s\" :: Expecting %d got %d ::",s,len,result);
	if(len == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_strlen(void){
	printf(BOLDBLUE "Testing ft_strlen...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_ft_strlen("Hello",5);
	result = result && assert_ft_strlen("Hello World",11);
	result = result && assert_ft_strlen("",0);
	result = result && assert_ft_strlen("Hello\0World",5);
	result = result && assert_ft_strlen("4",1);
	result = result && assert_ft_strlen("hellohellohellohellohellohellohellohellohello",45);
	result = result && assert_ft_strlen("you did it !",12);
	if(result){
		printf(BOLDGREEN "ft_strlen seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strlen is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

void test_ft_memset(){
	printf(BOLDBLUE "Testing ft_memset...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	char buffer[20];
	int result = 1;

	// test case 1: filling buffer with 'A'
	ft_memset(buffer, 'A', sizeof(buffer));
	printf("-> Test 1 : %s\n", memequal(buffer, "AAAAAAAAAAAAAAAAAAAA", sizeof(buffer)) ? GREEN "OK" RESET : RED "FAIL" RESET);
	result = result && memequal(buffer, "AAAAAAAAAAAAAAAAAAAA", sizeof(buffer));

	// test case 2: filling buffer with 'B' from index 5 to 10
	ft_memset(buffer + 5, 'B', 5);
	printf("-> Test 2 : %s\n", memequal(buffer, "AAAAABBBBBAAAAAAAAAA", sizeof(buffer)) ? GREEN "OK" RESET : RED "FAIL" RESET);
	result = result && memequal(buffer, "AAAAABBBBBAAAAAAAAAA", sizeof(buffer));

	// test case 3: filling buffer with 'C' from index 0 to 10
	ft_memset(buffer, 'C', 10);
	printf("-> Test 3 : %s\n", memequal(buffer, "CCCCCCCCCCAAAAAAAAAA", sizeof(buffer)) ? GREEN "OK" RESET : RED "FAIL" RESET);
	result = result && memequal(buffer, "CCCCCCCCCCAAAAAAAAAA", sizeof(buffer));

	// test case 4: filling buffer with zeros
	ft_memset(buffer, 0, sizeof(buffer));
	printf("-> Test 4 : %s\n", memequal(buffer, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" , sizeof(buffer)) ? GREEN "OK" RESET : RED "FAIL" RESET);
	result = result && memequal(buffer, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" , sizeof(buffer));
	if(result){
		printf(BOLDGREEN "ft_memset seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_memset is not OK !\n" RESET);
		fail();
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_isalpha(int c){
	int result = ft_isalpha(c)? 1 : 0;
	int expected = isalpha(c) ? 1 : 0;
	printf("-> Testing ASCII %d :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_isalpha(){
	printf(BOLDBLUE "Testing ft_isalpha...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = 0; i < 128; i++){
		result = result && assert_ft_isalpha(i);
	}
	if(result){
		printf(BOLDGREEN "ft_isalpha seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_isalpha is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_isdigit(int c){
	int result = ft_isdigit(c)? 1 : 0;
	int expected = isdigit(c) ? 1 : 0;
	printf("-> Testing ASCII %d :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_isdigit(){
	printf(BOLDBLUE "Testing ft_isdigit...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = 0; i < 128; i++){
		result = result && assert_ft_isdigit(i);
	}
	if(result){
		printf(BOLDGREEN "ft_isdigit seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_isdigit is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}


int assert_ft_isalnum(int c){
	int result = ft_isalnum(c)? 1 : 0;
	int expected = isalnum(c) ? 1 : 0;
	printf("-> Testing ASCII %d :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_isalnum(){
	printf(BOLDBLUE "Testing ft_isalnum...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = 0; i < 128; i++){
		result = result && assert_ft_isalnum(i);
	}
	if(result){
		printf(BOLDGREEN "ft_isalnum seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_isalnum is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_isascii(int c){
	int result = ft_isascii(c)? 1 : 0;
	int expected = isascii(c) ? 1 : 0;
	printf("-> Testing if %d is ASCII :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_isascii(){
	printf(BOLDBLUE "Testing ft_isascii...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = -127; i < 250; i++){
		result = result && assert_ft_isascii(i);
	}
	result = result && assert_ft_isascii(INT_MAX);
	result = result && assert_ft_isascii(INT_MIN);
	if(result){
		printf(BOLDGREEN "ft_isascii seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_isascii is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_isprint(int c){
	int result = ft_isprint(c)? 1 : 0;
	int expected = isprint(c) ? 1 : 0;
	printf("-> Testing if %d is printable :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_isprint(){
	printf(BOLDBLUE "Testing ft_isprint...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = -1; i < 256; i++){
		result = result && assert_ft_isprint(i);
	}
	if(result){
		printf(BOLDGREEN "ft_isprint seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_isprint is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_toupper(int c){
	int result = ft_toupper(c);
	int expected = toupper(c);
	printf("-> Testing ASCII %d :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_toupper(){
	printf(BOLDBLUE "Testing ft_toupper...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = 0; i < 128; i++){
		result = result && assert_ft_toupper(i);
	}
	if(result){
		printf(BOLDGREEN "ft_toupper seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_toupper is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_tolower(int c){
	int result = ft_tolower(c);
	int expected = tolower(c);
	printf("-> Testing ASCII %d :: Expecting %d got %d ::",c,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_tolower(){
	printf(BOLDBLUE "Testing ft_tolower...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	for (int i = 0; i < 128; i++){
		result = result && assert_ft_tolower(i);
	}
	if(result){
		printf(BOLDGREEN "ft_tolower seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_tolower is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_memcmp(const void *s1, const void *s2, size_t n){
	int expected = memcmp(s1,s2,n);
	int result = ft_memcmp(s1,s2,n);
	printf("-> Testing two buffers :: Expecting %d got %d ::",expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_memcmp(){
	printf(BOLDBLUE "Testing ft_memcmp...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_ft_memcmp("Hello","Hello",5);
	result = result && assert_ft_memcmp("Hello","Hello World",5);
	result = result && assert_ft_memcmp("","Hello",0);
	result = result && assert_ft_memcmp("Hello","",0);
	result = result && assert_ft_memcmp("","",0);
	//test edge cases
	result = result && assert_ft_memcmp("Hello\0World","Hello\0World",12);
	result = result && assert_ft_memcmp("Hello\0World","Hello",12);
	result = result && assert_ft_memcmp("Hello","Hello\0World",12);
	//test with numbers
	result = result && assert_ft_memcmp("1","1",1);
	result = result && assert_ft_memcmp("1","2",1);
	result = result && assert_ft_memcmp("2","1",1);
	result = result && assert_ft_memcmp("123456789","123456789",9);
	result = result && assert_ft_memcmp("123456789","123456788",9);
	result = result && assert_ft_memcmp("123456788","123456789",9);
	//test with string that have equal beginnings
	result = result && assert_ft_memcmp("Hello World","Hello",5);
	result = result && assert_ft_memcmp("Hello","Hello World",5);
	result = result && assert_ft_memcmp("Hello World","Hello World",11);
	result = result && assert_ft_memcmp("Hello World","Hello World!",11);
	result = result && assert_ft_memcmp("Hexlo World","Hello World!",11);
	result = result && assert_ft_memcmp("Hello World!","Hello World",11);
	//test with long strings
	result = result && assert_ft_memcmp("HelloWorldIamhere !!!! \n here i goooooo","HelloWorldIamhere !!!! \n here i goooooo",45);
	result = result && assert_ft_memcmp("HelloWorldIamhere !!!! \n here i goooooo","HelloWorldIamhere !!!! \n here i gooooo",45);
	result = result && assert_ft_memcmp("HelloWorldIamhere !!!! \n here i goooooo","HellocorldIamhere !!!! \n here i gooooo",45);
	// test with completely different strings
	result = result && assert_ft_memcmp("deeeWorldIamhere !!!! \n here i goooooo","HellocorldIamhere !!!! \n here i gooooo",45);
	if(result){
		printf(BOLDGREEN "ft_memcmp seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_memcmp is not OK !\n" RESET);
		fail();
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_strdup(char *s){
	char *result = ft_strdup(s);
	char *expected = strdup(s);
	int result_bool = 1;
	int overlap = are_overlapping(result, s);
	printf("-> Testing \"%s\" :: Expecting \"%s\" got \"%s\" :: Overlap? %s ::",s,expected,result,overlap? "YES" : "NO");
	result_bool = result_bool && strcmp(result,expected) == 0;
	result_bool = result_bool && !overlap;
	if(!overlap){
		free(result);
	}
	free(expected);
	if(result_bool){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	if(overlap){
		printf(RED " !!!FAIL!!!\n" RESET);
		printf(RED "The string generated and the original string are in the same memory location or overlapping !!\n" RESET);
		fail();
		return 0;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

void test_ft_strdup(){
	printf(BOLDBLUE "Testing ft_strdup...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_ft_strdup("Hello");
	result = result && assert_ft_strdup("Hello World");
	result = result && assert_ft_strdup("");
	result = result && assert_ft_strdup("Hello\0World");
	result = result && assert_ft_strdup("4");
	result = result && assert_ft_strdup("hellohellohellohellohellohellohellohellohello");
	result = result && assert_ft_strdup("you did it !");
	if(result){
		printf(BOLDGREEN "ft_strdup seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strdup is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_atoi(const char *nptr){
	int result = ft_atoi(nptr);
	int expected = atoi(nptr);
	printf("-> Testing \"%s\" :: Expecting %d got %d ::",nptr,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}
	printf(RED " !!!FAIL!!!\n" RESET);
	fail();
	return 0;
}

int silent_assert_ft_atoi(const char *nptr){
	int result = ft_atoi(nptr);
	int expected = atoi(nptr);
	if(expected == result){
		return 1;
	}
	fail();
	return 0;
}

char *itoa(int n){
	char *result = malloc(12);
	sprintf(result,"%d",n);
	return result;
}

int random_test_ft_atoi(size_t number_of_test){
	int r = 1;
	int d;
	char *str;
	srand(time(NULL));
	printf("-> Testing ft_atoi with %zu random numbers \n",number_of_test);
	for (size_t i = 0; i < number_of_test; i++){
		d = random_int();
		str = itoa(d);
		r = r && silent_assert_ft_atoi(str);
		if(!r){
			printf(RED "--> FAIL on %d\n" RESET,d);
			free(str);
			break;
		}
		free(str);
	}
	if (r){
		printf(GREEN "-> RANDOM TESTS : OK !\n" RESET);
	}else{
		printf(RED "-> RANDOM TEST : FAILED !!! \n" RESET);
	}
	return r;
}

void test_ft_atoi(){
	int result = 1;
	printf(BOLDBLUE "Testing ft_atoi...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	result = result && assert_ft_atoi("");
	result = result && assert_ft_atoi("0");
	result = result && assert_ft_atoi("1");
	result = result && assert_ft_atoi("2");
	result = result && assert_ft_atoi("3");
	result = result && assert_ft_atoi("4");
	result = result && assert_ft_atoi("5");
	result = result && assert_ft_atoi("6");
	result = result && assert_ft_atoi("7");
	result = result && assert_ft_atoi("8");
	result = result && assert_ft_atoi("9");
	result = result && assert_ft_atoi("443");
	result = result && assert_ft_atoi("-443");
	result = result && assert_ft_atoi("   443");
	result = result && assert_ft_atoi("  	443   ");
	result = result && assert_ft_atoi("   443   123");
	result = result && assert_ft_atoi("		 -443   123   ");
	result = result && assert_ft_atoi("		 -443");
	result = result && assert_ft_atoi("		 -443   ");
	result = result && assert_ft_atoi("		 -443   123");
	result = result && assert_ft_atoi("		 443abcd123");
	result = result && assert_ft_atoi("--443abcd123");
	result = result && assert_ft_atoi("++443abcd123");
	result = result && assert_ft_atoi("2147483647");
	result = result && assert_ft_atoi("-2147483648");
	result = result && assert_ft_atoi("  2147483647");
	result = result && assert_ft_atoi("  -2147483648");
	result = result && assert_ft_atoi("1000");
	result = result && assert_ft_atoi("-1000");
	result = result && assert_ft_atoi("10003000");
	result = result && assert_ft_atoi("-10003000");
	if (RANDOM_TESTS) result = result && random_test_ft_atoi(RANDOM_TESTS_NB);
	if(result){
		printf(BOLDGREEN "ft_atoi seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_atoi is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_strchr(const char *s, int c){
	char *result = ft_strchr(s,c);
	char *expected = strchr(s,c);
	printf("-> Testing finding %c in \"%s\" :: Expecting \"%p\" got \"%p\" ::",c,s,expected,result);
	if(result == expected){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strchr(){
	printf(BOLDBLUE "Testing ft_strchr...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_strchr("Hello",'H');
	result = result && assert_strchr("Hello",'e');
	result = result && assert_strchr("Hello",'l');
	result = result && assert_strchr("Hello",'o');
	result = result && assert_strchr("Hello",' ');
	result = result && assert_strchr("Hello",'W');
	result = result && assert_strchr("Hello",'r');
	result = result && assert_strchr("Hello",'d');
	result = result && assert_strchr("Hello",'!');
	result = result && assert_strchr("Hello",'4');
	result = result && assert_strchr("Hello",' ');
	if (result){
		printf(BOLDGREEN "ft_strchr seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strchr is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_strrchr(const char *s, int c){
	char *result = ft_strrchr(s,c);
	char *expected = strrchr(s,c);
	printf("-> Testing finding %c in \"%s\" :: Expecting \"%p\" got \"%p\" ::",c,s,expected,result);
	if(result == expected){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strrchr(){
	printf(BOLDBLUE "Testing ft_strrchr...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_strrchr("Hello",'H');
	result = result && assert_strrchr("Hello",'e');
	result = result && assert_strrchr("Hello",'l');
	result = result && assert_strrchr("oHeololo",'o');
	result = result && assert_strrchr("Hello",' ');
	result = result && assert_strrchr("Hello",'W');
	result = result && assert_strrchr("Hello",'r');
	result = result && assert_strrchr("Hello worlddd",'d');
	result = result && assert_strrchr("Hello",'!');
	result = result && assert_strrchr("Hello",'4');
	result = result && assert_strrchr("Hello",' ');
	if (result){
		printf(BOLDGREEN "ft_strrchr seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strrchr is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}


int assert_ft_bzero(void *s, size_t n){
	ft_bzero(s,n);
	unsigned char *ptr = (unsigned char *)s;
	printf("Testing if zeroed %ld bytes at the address %p ::",n,s);
	for (size_t i = 0; i < n; i++){
		if(ptr[i] != 0){
			printf(RED " !!!FAIL!!!\n" RESET);
			fail();
			return 0;
		}
	}
	printf(GREEN " OK !\n" RESET);
	return 1;
}

void test_ft_bzero(){
	printf(BOLDBLUE "Testing ft_bzero...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	char buffer[20] = "Hello World";
	char buffer2[20] = "";
	char large_buffer[256] = "Fk9UucSPW7zHZxB4OZbZe3lXJ4OBLfKnJASLfCqz19AZZaQ0fpWCoF12vuPZndzlswLY0qFdyyEVU5Htsa8KdW1aTb2cHXnLlFdjIGDSsF6qHrkCKhrBfVKfeHknzCZz7zteZctJ9C0QfowQ2KeGvpT8bNbD1KRnm7MlNzqoB0emT4jLGl7ieKjd8D561kVLvnCPhBHzeBOOufrYiFMzlxHTAWB1wHm4QBoSOvNbaWQaZExVDslAs9F6hrbMRJl";
	char large_buffer2[256] = "hzoIu81ZJZo63xWBpMItsj3K2z64r6eItieFP3whkfcTJKS3QMNo9qDnhfsIVGykTMrhYttwvzHVhKraGyqZALNaFnL4ewrULop0tqAcBQ2UdHATehymuktb7erhIZub2Pn79q66DSzTfmKAf0kBIXBRC8DHdNnxzfcay5fzmj7FPzX6B7R9H4NRg1TYzGw7yLMrOGatDMbM4KHS3Rjpoc8UxYiuMjTP2vAUOXYObTy4Qru4naRfa6r78jCM90A";
	large_buffer2[255] = 'X';
	result = result && assert_ft_bzero(buffer,20);
	result = result && assert_ft_bzero(buffer2,20);
	result = result && assert_ft_bzero(large_buffer,256);
	result = result && assert_ft_bzero(large_buffer2,256);
	if(result){
		printf(BOLDGREEN "ft_bzero seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_bzero is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_strncmp(const char *s1, const char *s2, size_t n){
	int expected = strncmp(s1,s2,n);
	int result = ft_strncmp(s1,s2,n);
	printf("-> Testing %s vs %s for %zu characters :: Expecting %d got %d ::",s1,s2,n,expected,result);
	if(expected == result){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strncmp(){
	printf(BOLDBLUE "Testing ft_strncmp...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_ft_strncmp("Hello","Hello",5);
	result = result && assert_ft_strncmp("Helld","Hello",5);
	result = result && assert_ft_strncmp("Hellon","HelloN",5);
	result = result && assert_ft_strncmp("Hellon","Hellod",5);
	result = result && assert_ft_strncmp("Hellon","HelloN",6);
	result = result && assert_ft_strncmp("Hellon","Hellod",6);
	result = result && assert_ft_strncmp("Hello","Hello World",5);
	result = result && assert_ft_strncmp("","Hello",0);
	result = result && assert_ft_strncmp("Hello","",0);
	result = result && assert_ft_strncmp("","Hello",4);
	result = result && assert_ft_strncmp("","Hello",5);
	result = result && assert_ft_strncmp("","Hello",1);
	result = result && assert_ft_strncmp("ve","Hello",0);
	result = result && assert_ft_strncmp("Hello","",0);
	result = result && assert_ft_strncmp("Hel","Hello",4);
	result = result && assert_ft_strncmp("d","Hello",5);
	result = result && assert_ft_strncmp("Hello","Hello",1);
	result = result && assert_ft_strncmp("Hello","",4);
	result = result && assert_ft_strncmp("Hello","",5);
	result = result && assert_ft_strncmp("Hello","",1);
	result = result && assert_ft_strncmp("Hello\0Worlx","Hello\0Worlx",12);
	result = result && assert_ft_strncmp("Hello\0dorlx","Hello\0vorlx",12);
	result = result && assert_ft_strncmp("Hello dorlx","Hello\0dorlx",12);
	result = result && assert_ft_strncmp("Hello dorlx","Hello\0dorlx",5);
	result = result && assert_ft_strncmp("Hello dorlx","Hello\0dorlx",6);
	result = result && assert_ft_strncmp("", "", 0);
	result = result && assert_ft_strncmp("Hello", "Hello", 0);
	result = result && assert_ft_strncmp("hELLo", "hello", 5);
	result = result && assert_ft_strncmp("Hello World","Hello World",50);
	result = result && assert_ft_strncmp("Hello World","Hello World!",50);
	result = result && assert_ft_strncmp("The weather is  not great","The weather is great",5);
	result = result && assert_ft_strncmp("The weather is great","The weather is  not great",5);
	result = result && assert_ft_strncmp("The weather is great","The weather is great",2);
	if(result){
		printf(BOLDGREEN "ft_strncmp seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strncmp is not OK !\n" RESET);
		fail();
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

void test_ft_memcpy(){
	printf(BOLDBLUE "Testing ft_memcpy...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	char *src="testing memcpy ./..*";
	char buffer[20];
	char buffer2[20];
	bzero((void *)buffer,20);
	bzero((void *)buffer2,20);
	int result_bool = 1;
	void *result = ft_memcpy(buffer,src,20);
	void *expected = memcpy(buffer2,src,20);
	result_bool = result_bool && memequal(buffer,buffer2,20);
	printf("-> Test 1 : %s\n", result_bool ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!result_bool) {fail();return;}
	src = "Hello World";
	result = ft_memcpy(buffer,src,0);
	expected = memcpy(buffer2,src,0);
	result_bool = result_bool && memequal(buffer,buffer2,20);
	printf("-> Test 2 : %s\n", result_bool ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!result_bool) {fail();return;}
	src = "The good old rabbit";
	result = ft_memcpy(buffer,src,3);
	expected = memcpy(buffer2,src,3);
	result_bool = result_bool && memequal(buffer,buffer2,20);
	printf("-> Test 3 : %s\n", result_bool ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!result_bool) {fail();return;}
	src = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	result = ft_memcpy(buffer,src,15);
	expected = memcpy(buffer2,src,15);
	result_bool = result_bool && memequal(buffer,buffer2,20);
	printf("-> Test 4 : %s\n", result_bool ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!result_bool) {fail();return;}
	src = "Hello World";
	bzero((void *)buffer,20);
	result = ft_memcpy(buffer,src,20);
	bzero((void *)buffer,20);
	expected = memcpy(buffer,src,20);
	result_bool = result_bool && (result == expected);
	printf("-> Test 5 : %s\n", result_bool ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!result_bool) {fail();return;}
	if(result_bool){
		printf(BOLDGREEN "ft_memcpy seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_memcpy is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);	
}

int assert_ft_memchr(const void *s, int c, size_t n){
	void *result = ft_memchr(s,c,n);
	void *expected = memchr(s,c,n);
	printf("-> Testing finding %c in \"%s\" :: Expecting \"%p\" got \"%p\" ::",c,(char *)s,expected,result);
	if(result == expected){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_memchr(){
	printf(BOLDBLUE "Testing ft_memchr...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_ft_memchr("Hello",'H',5);
	result = result && assert_ft_memchr("Hello",'e',5);
	result = result && assert_ft_memchr("Hello",'l',5);
	result = result && assert_ft_memchr("Hello",'o',5);
	result = result && assert_ft_memchr("Hello",' ',5);
	result = result && assert_ft_memchr("Hello",'W',5);
	result = result && assert_ft_memchr("Hello",'r',5);
	result = result && assert_ft_memchr("Hellodd",'d',5);
	result = result && assert_ft_memchr("Hello",'!',5);
	result = result && assert_ft_memchr("Hellov",'4',5);
	result = result && assert_ft_memchr("Hello",'c',0);
	result = result && assert_ft_memchr("Helloq",'l',1);
	result = result && assert_ft_memchr("Hello",'l',2);
	result = result && assert_ft_memchr("Hello",'l',3);
	result = result && assert_ft_memchr("Hello",'l',4);
	result = result && assert_ft_memchr("Hell\0wooorld",'o',12);
	result = result && assert_ft_memchr("Hell\0wooorld",'o',6);
	if (result){
		printf(BOLDGREEN "ft_memchr seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_memchr is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}


void test_ft_strlcpy(){
	int r = 1;
	char buffer1[5];
	char buffer2[10] = "Green";
	printf(BOLDBLUE "Testing ft_strlcpy...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	//basic tests
	printf("-> Test 1 :: :: ");
	size_t ret = ft_strlcpy(buffer1,"Hello World",sizeof(buffer1));
	r = r && (ret == 11);
	r = r && (strcmp(buffer1,"Hell") == 0);
	r = r && (buffer1[4] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 2 :: :: ");
	ret = ft_strlcpy(buffer1,"Wor",sizeof(buffer1));
	r = r && (ret == 3);
	r = r && (strcmp(buffer1,"Wor") == 0);
	r = r && (buffer1[3] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	//test with size 0
	printf("-> Test 3 :: :: ");
	ret = ft_strlcpy(buffer1,"Hello World",0);
	r = r && (ret == 11);
	r = r && (strcmp(buffer1,"Wor") == 0);
	r = r && (buffer1[3] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	//test with empty src
	printf("-> Test 4 :: :: ");
	ret = ft_strlcpy(buffer1,"",sizeof(buffer1));
	r = r && (ret == 0);
	r = r && (strcmp(buffer1,"") == 0);
	r = r && (buffer1[0] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	strcpy(buffer1,"Hey");
	//test with empty src and size 0
	printf("-> Test 5 :: :: ");
	ret = ft_strlcpy(buffer1,"",0);
	r = r && (ret == 0);
	r = r && (strcmp(buffer1,"Hey") == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	//test with string larger than size
	printf("-> Test 6 :: :: ");
	ret = ft_strlcpy(buffer1,"Hello World",sizeof(buffer1));
	r = r && (ret == 11);
	r = r && (strcmp(buffer1,"Hell") == 0);
	r = r && (buffer1[4] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	//test with offsets
	printf("-> Test 7 :: :: ");
	ret = ft_strlcpy((buffer1 + 1),"Hello World",sizeof(buffer1) - 1);
	r = r && (ret == 11);
	r = r && (strcmp(buffer1,"HHel") == 0);
	r = r && (buffer1[4] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 8 :: :: ");
	ret = ft_strlcpy((buffer2 + 2),"Hello World",sizeof(buffer2) - 2);
	r = r && (ret == 11);
	r = r && (strcmp(buffer2,"GrHello W") == 0);
	r = r && (buffer2[9] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	//test with size smaller than src
	printf("-> Test 9 :: :: ");
	ret = ft_strlcpy(buffer1,"Hello World",3);
	r = r && (ret == 11);
	r = r && (strcmp(buffer1,"He") == 0);
	r = r && (buffer1[2] == '\0');
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	if(r){
		printf(BOLDGREEN "ft_strlcpy seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strlcpy is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}


void test_ft_calloc(){
	printf(BOLDBLUE "Testing ft_calloc...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	printf("-> Test 0 :: :: ");
	char *p = (char *)ft_calloc(0,1);
	free(p);
	printf("%s\n",  GREEN "OK" RESET);
	printf("-> Test 1 :: :: ");
	char *ptr = (char *)ft_calloc(10,sizeof(char));
	r = r && (ptr != NULL);
	for (size_t i = 0; i < 10; i++){
		r = r && (ptr[i] == 0);
	}
	free(ptr);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 2 :: :: ");
	int *ptr2 = (int *)ft_calloc(10,sizeof(int));
	r = r && (ptr2 != NULL);
	for (size_t i = 0; i < 10; i++){
		r = r && (ptr2[i] == 0);
	}
	free(ptr2);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 3 :: :: ");
	unsigned long *ptr3 = (unsigned long *)ft_calloc(10,sizeof(unsigned long));
	r = r && (ptr3 != NULL);
	for (size_t i = 0; i < 10; i++){
		r = r && (ptr3[i] == 0);
	}
	for (size_t i = 0; i < 10; i++){
		ptr3[i] = 1;
	}
	for (size_t i = 0; i < 10; i++){
		r = r && (ptr3[i] == 1);
	}
	free(ptr3);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	if(r){
		printf(BOLDGREEN "ft_calloc seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_calloc is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

void test_ft_memmove()
{
	printf(BOLDBLUE "Testing ft_memmove...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	char buffer1[23] = "Hello World! Greetings";
	printf("-> Test 1 :: :: ");
	char *ptr = (char *)ft_memmove(buffer1,buffer1 + 6,17);
	r = r && (ptr == buffer1);
	r = r && (memcmp(buffer1,"World! Greetings",17) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 2 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1 + 6,buffer1,5);
	r = r && (ptr == buffer1 + 6);
	r = r && (memcmp(buffer1,"Hello Hello! Greetings",23) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 3 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1 + 6,buffer1,0);
	r = r && (ptr == buffer1 + 6);
	r = r && (strcmp(buffer1,"Hello World! Greetings") == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 4 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1,buffer1 + 6,0);
	r = r && (ptr == buffer1);
	r = r && (strcmp(buffer1,"Hello World! Greetings") == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 5 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1,buffer1 + 6,6);
	r = r && (ptr == buffer1);
	r = r && (memcmp(buffer1,"World!World! Greetings",23) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	//test with overlap
	printf("-> Test 6 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	char buffer2[23] = "Hello World! Greetings";
	ptr = (char *)ft_memmove(buffer1 + 6,buffer1,12);
	memmove(buffer2 + 6,buffer2,12);
	r = r && (ptr == buffer1 + 6);
	r = r && (memcmp(buffer1,buffer2,23) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 7 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	strcpy(buffer2,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1,buffer1 + 6,12);
	memmove(buffer2,buffer2 + 6,12);
	r = r && (ptr == buffer1);
	r = r && (memcmp(buffer1,buffer2,23) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 8 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	strcpy(buffer2,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1,buffer2 + 2,5);
	memmove(buffer2,buffer2 + 2,5);
	r = r && (ptr == buffer1);
	r = r && (memcmp(buffer1,buffer2,23) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	printf("-> Test 9 :: :: ");
	strcpy(buffer1,"Hello World! Greetings");
	strcpy(buffer2,"Hello World! Greetings");
	ptr = (char *)ft_memmove(buffer1+5,buffer2 + 2,5);
	memmove(buffer2+5,buffer2 + 2,5);
	r = r && (ptr == buffer1+5);
	r = r && (memcmp(buffer1,buffer2,23) == 0);
	printf("%s\n", r ? GREEN "OK" RESET : RED "FAIL" RESET);
	if(!r) {fail();return;}
	if(r){
		printf(BOLDGREEN "ft_memmove seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_memmove is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}
//--------------------------------------------------------------------------------------
// remove if you on a mac(TODO)
// stolen from https://opensource.apple.com/source/Libc/Libc-1158.30.7/string/FreeBSD/strnstr.c.auto.html
char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
// stolen from https://opensource.apple.com/source/Libc/Libc-262/string/strlcat.c.auto.html
size_t	strlcat(char * __restrict dst, const char * __restrict src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}
//--------------------------------------------------------------------------------------

int assert_ft_strnstr(const char *s1, const char *s2, size_t n){
	char *result = ft_strnstr(s1,s2,n);
	char *expected = strnstr(s1,s2,n);
	printf("-> Testing finding \"%s\" in \"%s\" for %zu characters :: Expecting \"%p\" got \"%p\" ::",s2,s1,n,expected,result);
	if(result == expected){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strnstr(){
	printf(BOLDBLUE "Testing ft_strnstr...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int result = 1;
	result = result && assert_ft_strnstr("Hello World","Hello",5);
	result = result && assert_ft_strnstr("Hello World","Hello",0);
	result = result && assert_ft_strnstr("Hello World","World",5);
	result = result && assert_ft_strnstr("Hello World","Hello",6);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",0);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",3);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",4);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",5);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",6);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",7);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",8);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",9);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",10);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",11);
	result = result && assert_ft_strnstr("Foo Bar Baz","Bar",12);
	result = result && assert_ft_strnstr("Foo Bar Baz","car",12);
	result = result && assert_ft_strnstr("Foo Bar Baz","car",5);
	result = result && assert_ft_strnstr("Hello World","Hello",33);
	result = result && assert_ft_strnstr("Hello World World","World",17);
	result = result && assert_ft_strnstr("Hello World World","World",11);
	result = result && assert_ft_strnstr("Hello World World","World",10);
	result = result && assert_ft_strnstr("", "test", 4);
    result = result && assert_ft_strnstr("test", "", 4);
    result = result && assert_ft_strnstr("", "", 0);
    result = result && assert_ft_strnstr("Hello $%%@ World", "$%%@", 15);
    result = result && assert_ft_strnstr("Hello \\n World", "\\n", 15);
	result = result && assert_ft_strnstr("Hello", "Hello", 5);
    result = result && assert_ft_strnstr("Hello", "Hello", 10);
	result = result && assert_ft_strnstr("Hello", "Hello World", 5);
    result = result && assert_ft_strnstr("World", "Hello World", 5);



	if(result){
		printf(BOLDGREEN "ft_strnstr seems OK !\n" RESET);
	}else{
		printf(BOLDRED "ft_strnstr is not OK !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_strlcat(char *dst, const char *src, size_t size){
	int r = 1;
	char *dst2 = memcpy(malloc(size),dst,size == 0 ? 1 : size);
	printf("-> Testing ft_strlcat(\"%s\",\"%s\",%zu) :: ",dst,src,size);
	size_t ret_result = ft_strlcat(dst,src,size);
	size_t ret_expected = strlcat(dst2,src,size);
	printf("Expecting \"%s\" got \"%s\" :: Returns Expected %zu got %zu ::",dst2,dst,ret_expected,ret_result);
	r = r && (ret_result == ret_expected);
	r = r && (strcmp(dst,dst2) == 0);
	r = r && memequal(dst,dst2,size);
	free(dst2);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strlcat(){
	printf(BOLDBLUE "Testing ft_strlcat...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	char buffer1[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	strcpy(buffer1,"Hello");
	r = r && assert_ft_strlcat(buffer1," World",20);
	r = r && assert_ft_strlcat(buffer1," World",20);
	r = r && assert_ft_strlcat(buffer1," World",20);
	r = r && assert_ft_strlcat(buffer1," World",20);
	buffer1[0] = '\0';
	r = r && assert_ft_strlcat(buffer1,"",20);
	r = r && assert_ft_strlcat(buffer1,"Hello",20);
	r = r && assert_ft_strlcat(buffer1,"",20);
	buffer1[0] = '\0';
	r = r && assert_ft_strlcat(buffer1,"The only way is up is a song made my tiesto",20);
	r = r && assert_ft_strlcat(buffer1,"The only way is up is a song made my tiesto",20);
	buffer1[0] = '\0';
	r = r && assert_ft_strlcat(buffer1,"The only way is up is",20);
	buffer1[0] = '\0';
	r = r && assert_ft_strlcat(buffer1,"The only way is up i",20);
	buffer1[0] = '\0';
	r = r && assert_ft_strlcat(buffer1,"The only way is up ",20);
	buffer1[0] = '\0';
	//r = r && assert_ft_strlcat(buffer1,"The only way is up",0);
	buffer1[0] = '\0';
	r = r && assert_ft_strlcat(buffer1,"",0);
	r = r && assert_ft_strlcat(buffer1,"Fly high !",0);
	r = r && assert_ft_strlcat(buffer1,"",0);
	if(r)
		printf(BOLDGREEN "ft_strlcat seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_strlcat is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_substr(char const *s, unsigned int start, size_t len, const char *expected){
	char * result = ft_substr(s,start,len);
	int r = 1;
	r = r && (strcmp(result,expected) == 0);
	r = r && (!are_overlapping(s,result));
	printf("-> Testing ft_substr(\"%s\", %d, %zu), expecting \"%s\" got \"%s\" , overlap ? %s :: ",s,start,len,expected,result, are_overlapping(s,result)? "YES" : "NO");
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	} 
}

void test_ft_substr(){
	printf(BOLDBLUE "Testing ft_substr...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	r = r && assert_ft_substr("Hello world",0,5,"Hello");
	r = r && assert_ft_substr("Hello World",6,5,"World");
	r = r && assert_ft_substr("Hello World",3,4,"lo W");
	r = r && assert_ft_substr("WelWo World",3,5,"Wo Wo");
	r = r && assert_ft_substr("Hello World",6,30,"World");
	r = r && assert_ft_substr("",0,40,"");
	r = r && assert_ft_substr("",0,0,"");
	r = r && assert_ft_substr("Hello world",0,0,"");
	r = r && assert_ft_substr("Hello world",6,0,"");
	r = r && assert_ft_substr("Hello World",6,1,"W");
	r = r && assert_ft_substr("Hello World",11,30,"");
	if(r)
		printf(BOLDGREEN "ft_substr seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_substr is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);

}

int assert_ft_strjoin(char const *s1, char const *s2, const char *expected){
	char *result = ft_strjoin(s1,s2);
	int overlap = are_overlapping(s1, result);
	overlap = overlap || are_overlapping(s2,result);
	int r = 1;
	printf("-> Testing ft_strjoin(\"%s\",\"%s\") Expected \"%s\" got \"%s\" overlap? %s :: ",s1,s2,expected,result,overlap ? "YES" : "NO");
	r = r && !overlap;
	r = r && (strcmp(result,expected)==0);
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
	
}

void test_ft_strjoin(){
	printf(BOLDBLUE "Testing ft_strjoin...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	r = r && assert_ft_strjoin("Hello ","World","Hello World");
	r = r && assert_ft_strjoin("Hello ","","Hello ");
	r = r && assert_ft_strjoin("","World","World");
	r = r && assert_ft_strjoin("","","");
	r = r && assert_ft_strjoin("Hel\0lo ","World","HelWorld");
	r = r && assert_ft_strjoin("Hello ","Wor\0ld","Hello Wor");
	r = r && assert_ft_strjoin("Hello","Hello","HelloHello");
	r = r && assert_ft_strjoin("abcdefghijklmnopqrstuvwxyz","0123456789","abcdefghijklmnopqrstuvwxyz0123456789");
	if(r)
		printf(BOLDGREEN "ft_strjoin seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_strjoin is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}


int assert_ft_strtrim(char const *s1, char const *set, char *expected){
	int r = 1;
	char *result = ft_strtrim(s1,set);
	int overlap = are_overlapping(s1,result);
	printf("-> Testing ft_strtrim(\"%s\",\"%s\") Expected \"%s\" got \"%s\" overlap? %s :: ",s1,set,expected,result,overlap ? "YES" : "NO");
	r = r && !overlap;
	r = r && (strcmp(result,expected)==0);
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strtrim(){
	int r = 1;
	printf(BOLDBLUE "Testing ft_strtrim...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	r = r && assert_ft_strtrim("Hello World!","Hlo!","e Wrd");
	r = r && assert_ft_strtrim("Greetings!","Green","tigs!");
	r = r && assert_ft_strtrim("Greetings!","Greentigs!","");
	r = r && assert_ft_strtrim("Greetings!","","Greetings!");
	r = r && assert_ft_strtrim("","abcdefhgklm","");
	r = r && assert_ft_strtrim("Hello World, is this it? or not/not yet"," ,?/","HelloWorldisthisitornotnotyet");
	r = r && assert_ft_strtrim("Hello World","Hd","ello Worl");
	r = r && assert_ft_strtrim("Hello World!","9abc","Hello World!");
	if(r)
		printf(BOLDGREEN "ft_strtrim seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_strtrim is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);

}

int assert_ft_split(char const *s, char c, char **expected){
	char **result = ft_split(s,c);
	int r = 1;
	size_t i = 0;
	printf("-> Testing ft_split(\"%s\",'%c') :: ",s,c);
	for (; expected[i] != NULL; i++){
		if(result[i] == NULL)
			{r = 0;break;}
		r = r && (strcmp(result[i],expected[i]) == 0);
		if(r==0)break;
	}
	r = r && (result[i] == NULL);
	printf("Expecting [");
	for (size_t j = 0; expected[j] != NULL; j++){
		printf("\"%s\"",expected[j]);
		if(expected[j+1] != NULL)
			printf(",");
	}
	printf("] got [");
	for (size_t j = 0; result[j] != NULL; j++){
		printf("\"%s\"",result[j]);
		if(result[j+1] != NULL)
			printf(",");
	}
	printf("] :: ");
	for (size_t j = 0; result[j] != NULL; j++){
		free(result[j]);
	}
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_split(){
	printf(BOLDBLUE "Testing ft_split...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	char *strs1[] = {"Hello","World!","How","are","you","doing","today?",NULL};
	r = r && assert_ft_split("Hello World! How are you doing today?",' ',strs1);
	char *strs2[] = {NULL};
	r = r && assert_ft_split("",' ',strs2);
	r = r && assert_ft_split("  ",' ',strs2);
	r = r && assert_ft_split(" ",' ',strs2);
	char *strs3[] = {"Hello World! How are you doing today?",NULL};
	r = r && assert_ft_split("Hello World! How are you doing today?",'+',strs3);
	char *strs4[] = {"Hello","World!","How","are","you","doing","today",NULL};
	r = r && assert_ft_split("Hello World! How are you doing today ",' ',strs4);
	r = r && assert_ft_split(" Hello World! How are you doing today ",' ',strs4);
	r = r && assert_ft_split(" Hello World!    How   are   you   doing             today ",' ',strs4);
	r = r && assert_ft_split("         Hello World! How are you doing today ",' ',strs4);
	r = r && assert_ft_split("Hello World! How are you doing today         ",' ',strs4);
	r = r && assert_ft_split("Hello+World!+How+are+you+doing+today",'+',strs4);
	char *strs5[] = {"Hello",NULL};
	r = r && assert_ft_split("Hello",' ',strs5);
	r = r && assert_ft_split(" Hello",' ',strs5);
	r = r && assert_ft_split("Hello ",' ',strs5);
	if(r)
		printf(BOLDGREEN "ft_split seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_split is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_itoa(int d, char *expected){
	char *result = ft_itoa(d);
	int r = 1;
	printf("-> Testing ft_itoa(%d) :: ",d);
	r = r && (strcmp(result,expected) == 0);
	printf("Expecting \"%s\" got \"%s\" :: ",expected,result);
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

int random_test_ft_itoa(size_t number_of_tests){
	int r = 1;
	int d;
	srand(time(NULL));
	printf("\n-> Testing ft_itoa with %zu random numbers \n",number_of_tests);
	for (size_t i = 0; i < number_of_tests; i++){
		d = random_int();
		char *expected = itoa(d);
		char *result = ft_itoa(d);
		r = r && (strcmp(result,expected) == 0);
		if(!r){
			printf(RED "Test number %zu FAILED expected \"%s\" got \"%s\" \n" RESET,i,expected,result);
			free(result);
			free(expected);
			fail();
			break;
		}
		free(result);
		free(expected);
	}
	if (r){
		printf(GREEN "-> RANDOM TESTS : OK !\n" RESET);
	}else{
		printf(RED "-> RANDOM TEST : FAILED !!! \n" RESET);
	}
	printf("\n");
	return r;
}

void test_ft_itoa(){
	printf(BOLDBLUE "Testing ft_itoa...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	r = r && assert_ft_itoa(0,"0");
	r = r && assert_ft_itoa(1,"1");
	r = r && assert_ft_itoa(-1,"-1");
	r = r && assert_ft_itoa(2,"2");
	r = r && assert_ft_itoa(-2,"-2");
	r = r && assert_ft_itoa(3,"3");
	r = r && assert_ft_itoa(-3,"-3");
	r = r && assert_ft_itoa(4,"4");
	r = r && assert_ft_itoa(-4,"-4");
	r = r && assert_ft_itoa(5,"5");
	r = r && assert_ft_itoa(-5,"-5");
	r = r && assert_ft_itoa(6,"6");
	r = r && assert_ft_itoa(-6,"-6");
	r = r && assert_ft_itoa(7,"7");
	r = r && assert_ft_itoa(-7,"-7");
	r = r && assert_ft_itoa(8,"8");
	r = r && assert_ft_itoa(-8,"-8");
	r = r && assert_ft_itoa(9,"9");
	r = r && assert_ft_itoa(-9,"-9");
	r = r && assert_ft_itoa(10,"10");
	r = r && assert_ft_itoa(-10,"-10");
	r = r && assert_ft_itoa(100,"100");
	r = r && assert_ft_itoa(-100,"-100");
	r = r && assert_ft_itoa(1000,"1000");
	r = r && assert_ft_itoa(-1000,"-1000");
	r = r && assert_ft_itoa(10000,"10000");
	r = r && assert_ft_itoa(-10000,"-10000");
	r = r && assert_ft_itoa(100000,"100000");
	r = r && assert_ft_itoa(-100000,"-100000");
	r = r && assert_ft_itoa(1000000,"1000000");
	r = r && assert_ft_itoa(-1000000,"-1000000");
	r = r && assert_ft_itoa(10000000,"10000000");
	r = r && assert_ft_itoa(-10000000,"-10000000");
	r = r && assert_ft_itoa(100000000,"100000000");
	r = r && assert_ft_itoa(-100000000,"-100000000");
	r = r && assert_ft_itoa(1000000000,"1000000000");
	r = r && assert_ft_itoa(-1000000000,"-1000000000");
	r = r && assert_ft_itoa(2100000047,"2100000047");
	r = r && assert_ft_itoa(-2100000047,"-2100000047");
	r = r && assert_ft_itoa(123456789,"123456789");
	r = r && assert_ft_itoa(-123456789,"-123456789");
	r = r && assert_ft_itoa(INT_MAX,STR_INT_MAX);
	r = r && assert_ft_itoa(INT_MIN,STR_INT_MIN);
	if (RANDOM_TESTS) r = r && random_test_ft_itoa(RANDOM_TESTS_NB);
	if(r)
		printf(BOLDGREEN "ft_itoa seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_itoa is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}

char map_to_upper(unsigned int i, char c){
	(void)(i);
	return toupper(c);
}
char map_to_lower(unsigned int i, char c){
	(void)(i);
	return tolower(c);
}
char is_even(unsigned int i, char c){
	(void)(c);
	return i % 2 == 0 ? 'Y' : 'N';
}
char is_odd(unsigned int i, char c){
	(void)(c);
	return i % 2 == 1 ? 'Y' : 'N';
}
char is_vowel(unsigned int i, char c){
	(void)(i);
	return strchr("aeiouyAEIOUY",c) != NULL ? 'Y' : 'N';
}
char is_consonant(unsigned int i, char c){
	(void)(i);
	return strchr("bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ",c) != NULL ? 'Y' : 'N';
}
char is_digit(unsigned int i, char c){
	(void)(i);
	return strchr("0123456789",c) != NULL ? 'Y' : 'N';
}
char ret_char(unsigned int i, char c){
	(void)(i);
	return c;
}
char ret_index(unsigned int i, char c){
	(void)(c);
	return i + '0';
}

int assert_ft_strmapi(char const *s, char (*f)(unsigned int, char), char *expected){
	char *result = ft_strmapi(s,f);
	int r = 1;
	printf("-> Testing ft_strmapi(\"%s\",f) :: ",s);
	r = r && (strcmp(result,expected) == 0);
	printf("Expecting \"%s\" got \"%s\" :: ",expected,result);
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_strmapi(){
	int r = 1;
	printf(BOLDBLUE "Testing ft_strmapi...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	r = r && assert_ft_strmapi("Hello",&map_to_upper,"HELLO");
	r = r && assert_ft_strmapi("Hello",&map_to_lower,"hello");
	r = r && assert_ft_strmapi("Hello",&is_even,"YNYNY");
	r = r && assert_ft_strmapi("Hello",&is_odd,"NYNYN");
	r = r && assert_ft_strmapi("Hello",&is_vowel,"NYNNY");
	r = r && assert_ft_strmapi("Hello",&is_consonant,"YNYYN");
	r = r && assert_ft_strmapi("Hello",&is_digit,"NNNNN");
	r = r && assert_ft_strmapi("Hello123",&is_digit,"NNNNNYYY");
	r = r && assert_ft_strmapi("",&is_digit,"");
	r = r && assert_ft_strmapi("Hello World!",&ret_char,"Hello World!");
	r = r && assert_ft_strmapi("Hello", &ret_index, "01234");
	if(r)
		printf(BOLDGREEN "ft_strmapi seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_strmapi is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}

void _upper(unsigned int i, char *c){
	(void)(i);
	*c = toupper(*c);
}
void _lower(unsigned int i, char *c){
	(void)(i);
	*c = tolower(*c);
}
void _even(unsigned int i, char *c){
	*c = i % 2 == 0 ? 'Y' : 'N';
}
void _odd(unsigned int i, char *c){
	*c = i % 2 == 1 ? 'Y' : 'N';
}
void _vowel(unsigned int i, char *c){
	(void)(i);
	*c = strchr("aeiouyAEIOUY",*c) != NULL ? 'Y' : 'N';
}
void _consonant(unsigned int i, char *c){
	(void)(i);
	*c = strchr("bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ",*c) != NULL ? 'Y' : 'N';
}
void _digit(unsigned int i, char *c){
	(void)(i);
	*c = strchr("0123456789",*c) != NULL ? 'Y' : 'N';
}
void _nothing(unsigned int i, char *c){
	(void)(i);
	(void)(c);
}
void _one(unsigned int i, char *c){
	(void)(i);
	*c = '1';
}

int assert_ft_striteri(char *s, void (*f)(unsigned int, char*),char *expected){
	char *result = strdup(s);
	ft_striteri(result,f);
	int r = 1;
	printf("-> Testing ft_striteri(\"%s\",f) :: ",s);
	r = r && (strcmp(result,expected) == 0);
	printf("Expecting \"%s\" got \"%s\" :: ",expected,result);
	free(result);
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

void test_ft_striteri(){
	int r = 1;
	printf(BOLDBLUE "Testing ft_striteri...\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	r = r && assert_ft_striteri("Hello",&_upper,"HELLO");
	r = r && assert_ft_striteri("Hello",&_lower,"hello");
	r = r && assert_ft_striteri("Hello",&_even,"YNYNY");
	r = r && assert_ft_striteri("Hello",&_odd,"NYNYN");
	r = r && assert_ft_striteri("Hello",&_vowel,"NYNNY");
	r = r && assert_ft_striteri("Hello",&_consonant,"YNYYN");
	r = r && assert_ft_striteri("Hello",&_digit,"NNNNN");
	r = r && assert_ft_striteri("Hello123",&_digit,"NNNNNYYY");
	r = r && assert_ft_striteri("",&_digit,"");
	r = r && assert_ft_striteri("Hello World!",&_nothing,"Hello World!");
	r = r && assert_ft_striteri("Hello",&_one,"11111");
	if(r)
		printf(BOLDGREEN "ft_striteri seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_striteri is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}

void test_ft_putchar_fd(){
	printf(BOLDBLUE "Testing ft_putchar_fd\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('H',fd);
	ft_putchar_fd('e',fd);
	ft_putchar_fd('l',fd);
	ft_putchar_fd('l',fd);
	ft_putchar_fd('o',fd);
	ft_putchar_fd(' ',fd);
	ft_putchar_fd('W',fd);
	ft_putchar_fd('o',fd);
	ft_putchar_fd('r',fd);
	ft_putchar_fd('l',fd);
	ft_putchar_fd('d',fd);
	ft_putchar_fd('!',fd);
	ft_putchar_fd('\0',fd);
	close(fd);
	fd = open("./tmp.txt", O_RDONLY);
	char *result = (char *)malloc(13);
	read(fd,result,13);
	close(fd);
	printf("-> Testing ft_putchar_fd, writing \"Hello World!\" to ./tmp.txt :: ");
	r = r && (strcmp(result,"Hello World!") == 0);
	free(result);
	remove("./tmp.txt");
	if(r){
		printf(GREEN " OK !\n" RESET);
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
	}
}

void test_ft_putstr_fd(){
	printf(BOLDBLUE "Testing ft_putstr_fd\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("Hello World!",fd);
	close(fd);
	fd = open("./tmp.txt", O_RDONLY);
	char *result = (char *)malloc(12);
	read(fd,result,12);
	close(fd);
	printf("-> Testing ft_putstr_fd, writing \"Hello World!\" to ./tmp.txt :: ");
	r = r && (memcmp(result,"Hello World!",12) == 0);
	free(result);
	remove("./tmp.txt");
	if(r){
		printf(GREEN " OK !\n" RESET);
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

void test_ft_putendl_fd(){
	printf(BOLDBLUE "Testing ft_putendl_fd\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	int r = 1;
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("Hello World!",fd);
	close(fd);
	fd = open("./tmp.txt", O_RDONLY);
	char *result = (char *)malloc(13);
	read(fd,result,13);
	close(fd);
	printf("-> Testing ft_putendl_fd, writing \"Hello World!\" to ./tmp.txt :: ");
	r = r && (memcmp(result,"Hello World!\n",13) == 0);
	free(result);
	remove("./tmp.txt");
	if(r){
		printf(GREEN " OK !\n" RESET);
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
	}
	printf(BOLDBLUE "---------------------\n" RESET);
}

int assert_ft_putnbr_fd(int n ,char *expected){
	int r = 1;
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(n,fd);
	ft_putchar_fd('\0',fd);
	close(fd);
	fd = open("./tmp.txt", O_RDONLY);
	char *result = (char *)malloc(strlen(expected) + 1);
	read(fd,result,strlen(expected) + 1);
	close(fd);
	printf("-> Testing ft_putnbr_fd(%d), expecting \"%s\" got \"%s\" :: ",n,expected,result);
	r = r && (memequal(result,expected,strlen(expected) + 1));
	free(result);
	remove("./tmp.txt");
	if(r){
		printf(GREEN " OK !\n" RESET);
		return 1;
	}else{
		printf(RED " !!!FAIL!!!\n" RESET);
		fail();
		return 0;
	}
}

int silent_assert_ft_putnbr_fd(int n, char *expected){
	int r = 1;
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(n,fd);
	ft_putchar_fd('\0',fd);
	close(fd);
	fd = open("./tmp.txt", O_RDONLY);
	char *result = (char *)malloc(strlen(expected) + 1);
	read(fd,result,strlen(expected) + 1);
	close(fd);
	r = r && (memequal(result,expected,strlen(expected) + 1));
	free(result);
	remove("./tmp.txt");
	if(!r)
		fail();
	return r;
}


int random_test_ft_putnbr_fd(size_t number_of_tests){
	int r = 1;
	int n;
	srand(time(NULL));
	printf("\n-> Testing ft_putnbr_fd with %zu random numbers \n",number_of_tests);
	for (size_t i = 0; i < number_of_tests; i++){
		n = random_int();
		char *expected = itoa(n);
		r = r && silent_assert_ft_putnbr_fd(n,expected);
		if(!r){
			printf(RED "Test number %zu FAILED expected \"%s\" got \"%d\" \n" RESET,i,expected,n);
			free(expected);
			fail();
			break;
		}
		free(expected);
	}
	if (r){
		printf(GREEN "-> RANDOM TESTS : OK !\n" RESET);
	}else{
		printf(RED "-> RANDOM TEST : FAILED !!! \n" RESET);
	}
	printf("\n");
	return r;
}


void test_ft_putnbr_fd(){
	int r = 1;
	printf(BOLDBLUE "Testing ft_putnbr_fd\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	r = r && assert_ft_putnbr_fd(0,"0");
	r = r && assert_ft_putnbr_fd(1,"1");
	r = r && assert_ft_putnbr_fd(-1,"-1");
	r = r && assert_ft_putnbr_fd(2,"2");
	r = r && assert_ft_putnbr_fd(-2,"-2");
	r = r && assert_ft_putnbr_fd(3,"3");
	r = r && assert_ft_putnbr_fd(-3,"-3");
	r = r && assert_ft_putnbr_fd(4,"4");
	r = r && assert_ft_putnbr_fd(-4,"-4");
	r = r && assert_ft_putnbr_fd(5,"5");
	r = r && assert_ft_putnbr_fd(-5,"-5");
	r = r && assert_ft_putnbr_fd(6,"6");
	r = r && assert_ft_putnbr_fd(-6,"-6");
	r = r && assert_ft_putnbr_fd(7,"7");
	r = r && assert_ft_putnbr_fd(-7,"-7");
	r = r && assert_ft_putnbr_fd(8,"8");
	r = r && assert_ft_putnbr_fd(-8,"-8");
	r = r && assert_ft_putnbr_fd(9,"9");
	r = r && assert_ft_putnbr_fd(-9,"-9");
	r = r && assert_ft_putnbr_fd(10,"10");
	r = r && assert_ft_putnbr_fd(-10,"-10");
	r = r && assert_ft_putnbr_fd(100,"100");
	r = r && assert_ft_putnbr_fd(-100,"-100");
	r = r && assert_ft_putnbr_fd(1000,"1000");
	r = r && assert_ft_putnbr_fd(-1000,"-1000");
	r = r && assert_ft_putnbr_fd(10000,"10000");
	r = r && assert_ft_putnbr_fd(-10000,"-10000");
	r = r && assert_ft_putnbr_fd(100000,"100000");
	r = r && assert_ft_putnbr_fd(-100000,"-100000");
	r = r && assert_ft_putnbr_fd(1000000,"1000000");
	r = r && assert_ft_putnbr_fd(-1000000,"-1000000");
	r = r && assert_ft_putnbr_fd(10000000,"10000000");
	r = r && assert_ft_putnbr_fd(-10000000,"-10000000");
	r = r && assert_ft_putnbr_fd(100000000,"100000000");
	r = r && assert_ft_putnbr_fd(-100000000,"-100000000");
	r = r && assert_ft_putnbr_fd(1000000000,"1000000000");
	r = r && assert_ft_putnbr_fd(-1000000000,"-1000000000");
	r = r && assert_ft_putnbr_fd(2100000047,"2100000047");
	r = r && assert_ft_putnbr_fd(-2100000047,"-2100000047");
	r = r && assert_ft_putnbr_fd(123456789,"123456789");
	r = r && assert_ft_putnbr_fd(-123456789,"-123456789");
	r = r && assert_ft_putnbr_fd(INT_MAX,STR_INT_MAX);
	r = r && assert_ft_putnbr_fd(INT_MIN,STR_INT_MIN);
	if (RANDOM_TESTS) r = r && random_test_ft_putnbr_fd(RANDOM_TESTS_NB);
	if(r)
		printf(BOLDGREEN "ft_putnbr_fd seems OK !\n" RESET);
	else
		printf(BOLDRED "ft_putnbr_fd is not OK !\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
}



	

int main()
{
/*
	//PART1
 	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	test_ft_calloc();
	test_ft_strdup();
*/


/*
	//PART2
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_striteri();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
*/
	
	printf(BOLDBLUE "\n\n---------------------\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);
	if(_ok){
		printf(BOLDGREEN "All tests passed !\n" RESET);
	}else{
		printf(BOLDRED "Some tests failed !\n" RESET);
	}
	printf(BOLDBLUE "---------------------\n" RESET);
	printf(BOLDBLUE "---------------------\n" RESET);

}