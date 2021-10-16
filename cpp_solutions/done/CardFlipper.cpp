// Card Flipper

/*

 
 Little Bobby Roberts (son of Big Bob, of Problem G) plays this solitaire memory game called Flipper.
 He starts with n cards, numbered 1 through n, and lays them out in a row with the cards in order
 left-to-right. (Card 1 is on the far left; card n is on the far right.) Some cards are face up and some are
 face down. Bobby then performs n − 1 flips — either right flips or left flips. In a right flip he takes the
 pile to the far right and flips it over onto the card to its immediate left. For example, if the rightmost
 pile has cards A, B, C (from top to bottom) and card D is to the immediate left, then flipping the pile
 over onto card D would result in a pile of 4 cards: C, B, A, D (from top to bottom). A left flip is
 analogous.
 The very last flip performed will result in one pile of cards — some face up, some face down. For
 example, suppose Bobby deals out 5 cards (numbered 1 through 5) with cards 1 through 3 initially face
 up and cards 4 and 5 initially face down. If Bobby performs 2 right flips, then 2 left flips, the pile will
 be (from top to bottom) a face down 2, a face up 1, a face up 4, a face down 5, and a face up 3.
 Now Bobby is very sharp and you can ask him what card is in any position and he can tell you!!! You
 will write a program that matches Bobby’s amazing feat.
 
 
 Input
 Each test case will consist of 4 lines. The first line will be a positive integer n (2 ≤ n ≤ 100) which is
 the number of cards laid out. The second line will be a string of n characters. A character U indicates
 the corresponding card is dealt face up and a character D indicates the card is face down. The third
 line is a string of n − 1 characters indicating the order of the flips Bobby performs. Each character is
 either R, indicating a right flip, or L, indicating a left flip. The fourth line is of the form m q1 q2 ... qm,
 where m is a positive integer and 1 ≤ qi ≤ n. Each qi
 is a query on a position of a card in the pile (1
 being the top card, n being the bottom card). A line containing 0 indicates end of input.
 
 
 Output
 Each test case should generate m + 1 lines of output. The first line is of the form
 Pile t
 where t is the number of the test case (starting at 1). Each of the next m lines should be of the form
 Card qi is a face up k.
 or
 Card qi is a face down k.
 accordingly, for i = 1,..,m, where k is the number of the card.
 For instance, in the above example with 5 cards, if qi = 3, then the answer would be
 Card 3 is a face up 4.
 
 
 Sample Input 5
 UUUDD
 RRLL
 5 1 2 3 4 5
 10
 UUDDUUDDUU
 LLLRRRLRL
 4 3 7 6 1 0
 
 Sample Output
 Pile 1
 Card 1 is a face down 2.
 Card 2 is a face up 1.
 Card 3 is a face up 4.
 Card 4 is a face down 5.
 Card 5 is a face up 3.
 Pile 2
 Card 3 is a face down 1.
 Card 7 is a face down 9.
 Card 6 is a face up 7.
 Card 1 is a face down 5.
 
 */

#include <iostream>
using namespace std;

const int MAX = 100;

struct card
{
	int val;
	bool up;
} cards[MAX];
int ileft, iright;

void print(int n)
{
	for(int i=0; i<n; i++) {
		cout << cards[i].val;
		if (cards[i].up)
			cout << 'U';
		else
			cout << 'D';
		cout << ' ';
	}
	cout << endl;
}

int main()
{
	int n, m;
	int ipile = 0;

	cin >> n;
	while (n > 0) {
		ipile++;
		for(int i=0; i<n; i++) {
			char ch;
			cin >> ch;
			cards[i].val = i+1;
			cards[i].up = (ch == 'U');
		}
		ileft = 0;
		iright = n-1;

		char ch;
		for(int i=0; i<n-1; i++) {
			cin >> ch;
			if (ch == 'L') {
				for(int j=0; j<=ileft/2; j++) { 
					card c = cards[j];
					cards[j] = cards[ileft-j];
					cards[ileft-j] = c;
				}
				for(int j=0; j<=ileft; j++)
					cards[j].up = !cards[j].up;
				ileft++;
			}
			else {
				int k=n-1;
				int j=iright;
				while (j < k) {
					card c = cards[j];
					cards[j] = cards[k];
					cards[k] = c;
					j++;
					k--;
				}
				for(int j=iright; j<n; j++)
					cards[j].up = !cards[j].up;
				iright--;
			}
		}
		if (ch == 'L') {
			int k=n-1;
			int j=iright;
			while (j < k) {
				card c = cards[j];
				cards[j] = cards[k];
				cards[k] = c;
				j++;
				k--;
			}
		}
		else {
			for(int j=0; j<=ileft/2; j++) {
				card c = cards[j];
				cards[j] = cards[ileft-j];
				cards[ileft-j] = c;
			}
			for(int j=0; j<=(n-1)/2; j++) {
				card c = cards[j];
				cards[j] = cards[n-1-j];
				cards[n-1-j] = c;
			}
		}

		cout << "Pile " << ipile << endl;
		cin >> m;
		for(int i=0; i<m; i++) {
			int index;
			cin >> index;
			cout << "Card " << index << " is a face ";
			if (cards[index-1].up)
				cout << "up ";
			else
				cout << "down ";
			cout << cards[index-1].val << "." << endl;
		}

		cin >> n;
	}

}
