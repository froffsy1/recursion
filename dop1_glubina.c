#include <stdio.h>

long long depth = 0;
char* prev = NULL;

void f0(void) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	f0();
	depth--;
}

void f1(int a) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	f1(a+1);
	depth--;
}

void f2(int a,int b) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	f2(a+1,b+1);
	depth--;
}

void f5(int a, int b, int c, int d, int e) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	f5(a + 1, b + 1, c + 1, d + 1, e + 1);
	depth--;
}


void fd(double a) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	fd(a+1.0);
	depth--;
}

void fc(char a) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	fc(a + 1);
	depth--;
}

void fl(long long a) {
	char local;
	depth++;
	if (depth >= 2 && depth <= 4) {
		fprintf(stderr, "frame: %lld bytes\n", (long long)(prev - &local));
	}
	fprintf(stderr, "%lld\n", depth);
	prev = &local;
	fl(a + 1);
	depth--;
}

int main(void) {
	int flag;
	scanf_s("%d", &flag);
	switch (flag) {
	case 1:
		f0();
		break;
	case 2:
		f1(0);
		break;
	case 3:
		f2(0,0);
		break;
	case 4:
		f5(0,0,0,0,0);
		break;
	case 5:
		fd(0.0);
		break;
	case 6:
		fc(0);
		break;
	case 7:
		fl(0);
		break;
	}

	return 0;
}
