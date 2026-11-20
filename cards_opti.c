#include <stdio.h>
#include <string.h>


int depth = 0;
int max_depth = 0;
int calls = 0;
int verbose = 0;
int weights[5];
const char* cards[5];

int rekurs(int i, int sum, int mask) {
	int result;
	calls++;
	depth++;
	if (depth > max_depth) {
		max_depth = depth;
	}
	if (sum > 15) {
		result = 0;
	}
	else if (i == 5) {
		result = (sum == 15);
		if (verbose && sum == 15) {
			printf("Found:");
			for (int k = 0;k < 5;k++) {
				if (mask & (1 << k)) {
					printf(" %s", cards[k]);
				}
			}
			printf("\n");
		}
	}
	else {
		int skip = rekurs(i + 1, sum, mask);
		int take = rekurs(i + 1, sum + weights[i], mask | (1 << i));
		result = skip + take;
	}

	depth--;
	return result;
}

int check(const char* s) {
	if (strlen(s) != 2 && strlen(s) != 3) {
		return -1;
	}
	if (strlen(s) == 2) {
		if (!(s[1] == 'H' || s[1] == 'C' || s[1] == 'S' || s[1] == 'D')) {
			return -1;
		}
		char v = s[0];
		if (v == 'A') {
			return 1;
		}
		if (v == 'J' || v == 'Q' || v == 'K') {
			return 10;
		}
		if (v >= '2' && v <= '9') {
			return v - '0';
		}
		return -1;
	}
	if (strlen(s) == 3) {
		if (!(s[2] == 'H' || s[2] == 'C' || s[2] == 'S' || s[2] == 'D')) {
			return -1;
		}
		if (s[0] == '1' && s[1] == '0') {
			return 10;
		}
		return -1;
	}
	return -1;
}


int main(int argc, char* argv[]) {
	if (argc != 7) {
		printf("ERROR\n");
		return 1;
	}
	for (int k = 0;k < 5;k++) {
		weights[k] = check(argv[k + 1]);
		if (weights[k] == -1) {
			printf("ERROR\n");
			return 1;
		}
		cards[k] = argv[k + 1];
	}

	for (int a = 0;a < 5;a++) {
		for (int b = a + 1;b < 5;b++) {
			if (strcmp(argv[a + 1], argv[b + 1]) == 0) {
				printf("ERROR\n");
				return 1;
			}
		}
	}
	if (strcmp(argv[6], "1") == 0) {
		verbose = 1;
	}
	else if (strcmp(argv[6], "0") != 0) {
		printf("ERROR\n");
		return 1;
	}
	int res = rekurs(0, 0, 0);
	printf("RESULT: %d\n", res);
	if (verbose) {
		printf("Max depth: %d\nCalls: %d\n", max_depth, calls);
	}
	return 0;
}
