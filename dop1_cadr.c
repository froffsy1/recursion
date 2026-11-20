#include <stdio.h>

char* prev = NULL;
int n = 0;

void f0(void) {
	char local;
	n++;
	if (n >= 2) printf("0 pr: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) f0();
}

void f1(int a) {
	char local;
	n++;
	if (n >= 2) printf("1 int: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) f1(a + 1);
}

void f2(int a, int b) {
	char local;
	n++;
	if (n >= 2) printf("2 int: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) f2(a + 1, b + 1);
}

void f5(int a, int b, int c, int d, int e) {
	char local;
	n++;
	if (n >= 2) printf("5 int: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) f5(a + 1, b + 1, c + 1, d + 1, e + 1);
}

void fd(double a) {
	char local;
	n++;
	if (n >= 2) printf("double: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) fd(a + 1.0);
}

void fc(char a) {
	char local;
	n++;
	if (n >= 2) printf("char: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) fc(a + 1);
}

void fl(long long a) {
	char local;
	n++;
	if (n >= 2) printf("long long: %lld\n", (long long)(prev - &local));
	prev = &local;
	if (n < 5) fl(a + 1);
}

int main(void) {
	printf("sizeof(void*) = %zu\n", sizeof(void*));
	n = 0; f0();
	n = 0; f1(0);
	n = 0; f2(0, 0);
	n = 0; f5(0, 0, 0, 0, 0);
	n = 0; fd(0.0);
	n = 0; fc(0);
	n = 0; fl(0);
	return 0;
}
