#include "pch.h"
#include <iostream> 
#include <iomanip> 
using namespace std;
int main() {
	unsigned char ch = 0;
	for (ch = 0; ch < 128; ch++) {
		if (ch > 6 && ch < 11 || ch == 13) cout << setw(6) << ' ';
		else cout << setw(6) << ch;
		cout << setw(6) << dec << int(ch)
			<< setw(6) << oct << int(ch)
			<< setw(6) << hex << int(ch) << endl;
	}
	cin.get();
	return 0;
}

