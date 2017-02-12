// Ive got your back gammon

/*

A friend of yours is working on an AI program to play backgammon, and she has a small problem. At
the end of the game, each player’s 15 pieces are moved onto a set of 6 board positions called points,
numbered 1 through 6. The pieces can be distributed in any manner across these points: all 15 could
be on point 3; 5 could be on point 6, 2 on point 5, 3 on point 4 and 5 on point 2; etc. Your friend
wants to store all these possible configurations (of which there are 15504) into a linear array, but she
needs a mapping from configuration to array location. It seems logical that the configuration with all 15
pieces on point 1 should correspond to array location 0, and the configuration of all 15 pieces on point
6 should correspond to the last array location. It’s the ones in between that are giving her problems.
That’s why she has come to you.
You decide to specify a configuration by listing the number of pieces on each point, starting with
point 6. For example, the two configurations described above could be represented by (0, 0, 0, 15, 0, 0)
and (5, 2, 3, 0, 5, 0). Then you can order the configurations in lexicographic ordering, starting with
(0,0,0,0,0,15), then (0, 0, 0, 0, 1, 14),(0, 0, 0, 0, 2, 13), . . . ,(0, 0, 0, 0, 14, 1),(0, 0, 0, 0, 15, 0),(0, 0, 0, 1, 0, 14),
(0, 0, 0, 1, 1, 13), etc., ending with (15, 0, 0, 0, 0, 0). Now all you need is a way to map these orderings to
array indices. Literally, that’s all you need, because that’s what this problem is all about.


Input
Each test case will consist of one line, starting with a single character, either ‘m’ or ‘u’. If it is an ‘m’
it will be followed by a configuration and you must determine what array index it gets mapped to. If
it is a ‘u’ then it will be followed by an integer array index i, 0 ≤ i < 15504, and you must determine
what configuration gets mapped to it. A line containing the single character ‘e’ will end input.



Output
For each test case, output the requested answer – either an array index or a configuration. Follow the
format in the examples below.

Sample Input
m 0 0 0 0 0 15
u 15503
e

Sample Output
Case 1: 0
Case 2: 15 0 0 0 0 0
*/


#include <iostream>
using namespace std;

struct config {
	int p[6];
} list[15504];

int start[17];

int main()
{
	int count=0;
	for(int m=0; m<=15; m++) {
		start[m] = count;
	for(int l=0; l<=15-m; l++) {
	for(int k=0; k<=15-m-l; k++) {
	for(int j=0; j<=15-m-l-k; j++) {
	for(int i=0; i<=15-m-l-k-j; i++) {
		list[count].p[0] = m;
		list[count].p[1] = l;
		list[count].p[2] = k;
		list[count].p[3] = j;
		list[count].p[4] = i;
		list[count].p[5] = 15-i-j-k-l-m;
		count++;
	}}}}}

	char ch;
	cin >> ch;
	int icase=0;
	while (ch != 'e') {
		cout << "Case " << ++icase << ": ";
		if (ch == 'm') {
			int p[6];
			for(int i=0; i<6; i++)
				cin >> p[i];
			int index=start[p[0]];
			for(int j=1; j<6; j++) {
				while(list[index].p[j] != p[j])
					index++;
			}
			cout << index << endl;
		}
		else {
			int n;
			cin >> n;
			cout << list[n].p[0];
			for(int i=1; i<6; i++)
				cout << ' ' << list[n].p[i];
			cout << endl;
		}

		cin >> ch;
	}
}
