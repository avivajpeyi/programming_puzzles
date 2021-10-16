// Pool Balls Arrangments

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	int icase = 0;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		icase++;
		int rows =sqrt(2*a);
		long n = (rows*(rows+1))/2+1;
		while (n<= a) {
			n += ++rows;
		}
		int count = 0;
		while (n < b) {
			int sqroot = sqrt(n);
			if (sqroot*sqroot == n)
				count++;
			n += ++rows;
		}
		cout << "Case " << icase << ": " << count << endl;
		cin >> a >> b;
	}
}
		
