#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int depth = 0;
int max_depth = 0;
int calls = 0;
int verbose = 0;
double memo[100][100];

double rekurs(int r, int c) {
	double W;
	calls++;
	depth++;
	if (depth > max_depth) {
		max_depth = depth;
	}
	if (memo[r][c] >= 0) {
		W = memo[r][c];                 
	}
	else {
		if (r == 0 && c == 0) {
			W = 0;
		}
		else if (c == 0) {
			W = (80 + rekurs(r - 1, c)) / 2;
		}
		else if (c == r) {
			W = (80 + rekurs(r - 1, c - 1)) / 2;
		}
		else {
			W = (80 + rekurs(r - 1, c - 1)) / 2 + (80 + rekurs(r - 1, c)) / 2;
		}
		memo[r][c] = W;
	}
	if (verbose) {
		for (int i = 0;i < depth;i++) {
			printf("  ");
		}
		printf("W(%d, %d) = %g\n", r, c, W);
	}
	depth--;
	return W;
}

int parse_int(const char* s, int* out) {
	char* endptr;
	long val = strtol(s, &endptr, 10);
	if (endptr == s) {
		return 0;
	}
	if (*endptr != '\0') {
		return 0;
	}
	*out = (int)val;
	return 1;
}

int main(int argc, char* argv[]) {
	int r, c, h, flag;
	if (argc != 5) {
		printf("ERROR\n");
		return 1;
	}
	if (!parse_int(argv[1], &r) || !parse_int(argv[2], &c) || !parse_int(argv[3], &h) || !parse_int(argv[4], &flag)) {
		printf("ERROR\n");
		return 1;
	}
	if (h <= 0 || r >= h || r < 0 || c<0 || c > r || flag > 1 || flag < 0) {
		printf("ERROR\n");
		return 1;
	}
	if (flag == 1) {
		verbose = 1;
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			memo[i][j] = -1;
		}
	}
	clock_t t = clock();
	double res = rekurs(r, c);
	double sec = (double)(clock() - t) / CLOCKS_PER_SEC;
	printf("RESULT: %g\n", res);
	printf("Time: %f s\n", sec);
	if (verbose == 1) {
		printf("Max_depth: %d\n", max_depth);
		printf("Calls: %d\n", calls);
	}
	return 0;
}
