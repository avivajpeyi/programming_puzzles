// Khoa Nguyen
// CSCI-279 Problem Seminar
// ACM 2009 Problem D

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct c {
	int val;
	int face; // 1 = UP, -1 = DOWN
} Card;

void flip(vector<vector<Card> >& cards, char d) {
	int targ = 0; // index of the target pile to be moved
	int dest = 0; // index of the destination
	
	// find the pile to be moved and where it should be moved to
	if (d == 'L') {
		for (int i = 0; i < cards.size(); i++) {
			if (cards[i].size() > 0) {
				targ = i;
				dest = i + 1;
				break;
			}
		}
	}
	else if (d == 'R') {
		for (int i = cards.size() - 1; i > -1; i--) {
			if (cards[i].size() > 0) {
				targ = i;
				dest = i - 1;
				break;
			}
		}
	}

	// do the flip
	int targ_size = cards[targ].size();
	for (int i = targ_size - 1; i > -1; i--) {
		cards[targ][i].face *= -1;
		cards[dest].push_back(cards[targ][i]);
		cards[targ].pop_back();
	}
}

int main() {
	int n;
	cin >> n;

	int pile = 1;
	
	while (n != 0) {
		// get original setup
		vector<vector<Card> > cards (n);
		
		string faces;
		cin >> faces;

		for (int i = 0; i < n; i++) {
			Card tmp;
			tmp.val = i + 1;
			tmp.face = (faces[i] == 'U') ? 1 : -1;
			cards[i].push_back(tmp);
		}

		string flips;
		cin >> flips;

		
		int m;
		cin >> m;
		
		vector<int> q(m);
		for (int i = 0; i < m; i++) {
			cin >> q[i];
		}

		// flip the cards
		for (int i = 0; i < n - 1; i++) {
			char f = flips[i];
			flip(cards, f);
		}

		// find where the final pile is
		int p = 0; 
		for (int i = 0; i < n; i++) {
			if (cards[i].size() > 0) {
				p = i;
				break;
			}
		}

		cout << "Pile " << pile++ << endl;
		int top = cards[p].size();
		for (int i = 0; i < m; i++) {
			int index = top - q[i];
			string face_str = (cards[p][index].face == 1) ? "up " : "down ";
			cout << "Card " << q[i] << " is a face " << face_str
				 << cards[p][index].val << ".\n";
		}


		// get n again
		cin >> n;
	}
	
    return 0;
}
