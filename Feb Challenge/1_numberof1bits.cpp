#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
	int res = 0;
	for (int i = 0; i < 32; i++) {
		if ((n & 1) == 1)
			res++;
		n >>= 1;
	}
	return res;
}

int main() {
	cout << hammingWeight(00000000000000000000000000001011);

	return 0;
}