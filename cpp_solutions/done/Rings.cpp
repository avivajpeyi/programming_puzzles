/*

 RINGS
 
determine the expected number of rings given the outline of a
tree. Dee has decided to model a cross section of a tree on a two dimenional grid, with the interior
of the tree represented by a closed polygon of grid squares. Given this set of squares, she assigns
rings from the outer parts of the tree to the inner as follows: calling the non-tree grid squares “ring
0”, each ring n is made up of all those grid squares that have at least one ring (n − 1) square as a
neighbor (where neighboring squares are those that share an edge).

Most of Dee’s models have been drawn on graph paper, and she has come to you to write a program
to do this automatically for her. This way she’ll use less paper and save some . . . well, you know.
Input
The input will start with a line containing two positive integers n m specifying the number of rows
and columns in the tree grid, where n, m ≤ 100. After this will be n rows containing m characters
each. These characters will be either ‘T’ indicating a tree grid square, or ‘.’.


Output
Output a grid with the ring numbers. If the number of rings is less than 10, use two characters for
each grid square; otherwise use three characters for each grid square. Right justify all ring numbers
in the grid squares, and use ‘.’ to fill in the remaining characters.
If a row or column does not contain a ring number it should still be output, filled entirely with ‘.’s.



Sample Input 1
6 6
.TT...
TTTT..
TTTTT.
TTTTT.
TTTTTT
..T...

Sample Output 1
...1.1......
.1.2.2.1....
.1.2.3.2.1..
.1.2.3.2.1..
.1.1.2.1.1.1
.....1......



Sample Input 2
3 4
TT..
TT..
....

Samp Out:
.1.1....
.1.1....
........
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;

int tree[maxn][maxn];
char temp[maxn][maxn];

void ptm(int r, int c, int id)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (id)
                cout << temp[i][j] << ' ';
            else
                cout << tree[i][j] << ' ';
        }
        cout << endl;
    }
}

void mark(int tr, int tc, int r, int c) {
    if ((tr-1)<0 || (tr+1)==r) {
        tree[tr][tc] = 1;
        return;
    }
    if ((tc-1)<0 || (tc+1)==c) {
        tree[tr][tc] = 1;
        return;
    }
    // up, down, left, right
    if (temp[tr-1][tc] == '.' || temp[tr+1][tc] == '.' || temp[tr][tc-1] == '.' || temp[tr][tc+1] == '.')
        tree[tr][tc] = 1;
    else {
        int up = tree[tr-1][tc];
        int left = tree[tr][tc-1];
        if (up || left) {
            if (up <= left)
                tree[tr][tc] = up+1;
            else
                tree[tr][tc] = left+1;
        }
    }
    return;
}

int main()
{
    int r, c;
    while (cin >> r >> c) {
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> temp[i][j];
            }
        }
        //ptm(r, c, 1);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (temp[i][j] == 'T')
                    mark(i, j, r, c);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (tree[i][j] > 1) {
                    int tosort[4];
                    tosort[0] = tree[i-1][j];
                    tosort[1] = tree[i+1][j];
                    tosort[2] = tree[i][j-1];
                    tosort[3] = tree[i][j+1];
                    sort(tosort, tosort+4);
                    tree[i][j] = tosort[0]+1;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (tree[i][j])
                    cout << '.' << tree[i][j];
                else
                    cout << "..";
            }
            cout << endl;
        }
    }
    return 0;
}
