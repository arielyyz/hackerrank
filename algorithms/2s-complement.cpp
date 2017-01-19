#include <ctgmath>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long pos(int n) {
	if (n == 0)
		return 0;
	long long m = floor(log2(n));
	return pow(2, m - 1) * m +
			pos(n - pow(2, m)) +
			n + 1 - pow(2, m);
}

long long neg(int n) {
	if (n == 0)
		return 0;
	long long nn = abs((long long)n);
	long long range = 32ll * nn;
	return range - pos(~n);
}

int main() {
	int t;
	cin >> t;
	int a, b;
	for (int k = 0; k < t; k++) {
		cin >> a >> b;
		long long sum = 0;
		if (a < 0)
			sum += neg(a);
		else if (a > 0)
			sum -= pos(a - 1);
		if (b < 0)
			sum -= neg(b + 1);
		else
			sum += pos(b);
		cout << sum << endl;
	}
	return 0;
}
