#include <math.h>

int min(int a, int b) {
    if (a <= b) {
	return a;
    }

    return b;
}

int num_digits(int n) {
    if (n == 0) {
        return 1;
    } else {
        return floor(log10(n)) + 1;
    }
}
