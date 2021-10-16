// Grille Cryptograph

/*
The message is encrypted by writing down the letters that appear in the holes, row by row, then
rotating the grille 90 degrees clockwise, writing the new letters that appear, and repeating this
process two more times. Of course the holes in the grille must be chosen so that every letter in the
message will eventually appear in a hole (this is actually not that hard to arrange).
An example is shown below, where the message “Send more monkeys” is encrypted as “noeesrksdmnyemoj”,
after adding a random letter to fill out the grid


Input
The input starts with a line containing a positive integer n ≤ 10 indicating the size of the grid and
grille. The next n lines will specify the grille, using ‘.’ for a hole and ‘X’ for a non-hole. Following
this will be a line containing the encrypted message, consisting solely of lowercase alphabetic
characters. The number of characters in this line will always be n
2
.


Output
Output the decrypted text as a single string with no spaces, or the phrase “invalid grille” if
the grille is invalid.
Sample Input 1
4
XX.X
X.X.
XXXX
.XXX
noeesrksdmnyemoj

sendmoremonkeysj

Sample input 2

4
.XX.
XXXX
XXXX
.XX.
abcdefghijklmnop 

invalid grille

2
X.
XX
aybb

baby


*/

#include <iostream>
using namespace std;

const int MAXS = 50;

char grille[MAXS][MAXS];
int order[MAXS*MAXS];

void rotateGrille(int size)
{
	char tmp[MAXS][MAXS];

	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			tmp[i][j] = grille[i][j];
 for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			grille[j][size-i-1] = tmp[i][j];
}

bool buildOrder(int size)
{
    for(int i=0; i<size*size; i++)
        order[i] = -1;
	int k=0;
	for(int r=0; r<4; r++) {
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
				if (grille[i][j] == '.')
					order[i*size + j] = k++;
		rotateGrille(size);
	}
/*
cout << "k = " << k << endl;
for(int i=0; i<size*size; i++)
cout << order[i] << ' ';
cout << endl;
*/
	for(int i=0; i<size*size; i++)
		if(order[i] == -1)
			return false;
	return true;
}

int main()
{
	int n;
	string cipher;

	cin >> n;
		int gsize = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin >> grille[i][j];
				if (grille[i][j] == '.')
                    gsize++;
			}
		}
		cin >> cipher;
		if (gsize*4 == n*n && buildOrder(n)) {
			string plain = "";
			for(int i=0; i<cipher.length(); i+=n*n) {
				for(int j=0; j<n*n; j++) {
					plain += cipher[i+order[j]];
				}
			}
			cout << plain << endl;
		}
		else
			cout << "invalid grille" << endl;
return 0;
}
