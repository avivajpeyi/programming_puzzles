// Max Parties Attended 

#include <iostream>
using namespace std;

const int MAXPARTIES = 200;
int start[MAXPARTIES], end[MAXPARTIES];

int bestIndex(int t, int np)
{
	int index = -1;
	int earliest = 33;
	for(int i=0; i<np; i++) {
		if (t >= start[i] && t < end[i] && end[i] < earliest) {
			index = i;
			earliest = end[i];
		}
	}
	return index;
}

int main()
{
	int p, day=0;

	cin >> p;
	while (p > 0) {
		day++;
		for(int i=0; i<p; i++) {
			int s, e;
			cin >> s >> e;
			start[i] = (s-8)*2; 
			end[i] = (e-8)*2; 
		}
		int count = 0;
		for(int i=0; i<32; i++) {
			int index = bestIndex(i, p);
			if (index >= 0) {
				count++;
				start[index] = 32;	// eliminate this party
			}
		}

		cout << "On day " << day << " Emma can attend as many as " << count << " parties." << endl;

		cin >> p;
/*
		if (p > 0)
			cout << endl;
*/
	}

	return 0;
}
