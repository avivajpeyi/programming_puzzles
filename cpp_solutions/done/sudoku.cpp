// Sudoku Solver for last spaces

/*
 
 There is a zero present in place of some calues for a sudoku. Can you replace the zeros with correct values? 
 
 Input
 The first line of input will contain a positive integer indicating the number of test cases to follow. Each
 test case will be a nearly completed Sudoku grid consisting of 9 lines, each containing 9 characters from
 the set of digits 0 through 9. There will be exactly five 0’s in each test case, indicating the five unfilled
 boxes.
 
 
 Output
 Output for each test case should be either
 Could not complete this grid.
 if it is impossible to complete the grid according to the rules of the game, or the completed grid, in the
 form given below. (There are no blank spaces in the output.) If there is a way to complete the grid, it
 will be unique. Separate test cases with a blank line.
 
 */


#include <iostream>
using namespace std;

int grid[9][9];
bool rows[9][10], cols[9][10], sqs[9][10];
int r[5], c[5];
bool ok;

bool getInput()
{
	for(int i=0; i<9; i++)
		for(int j=1; j<=9; j++)
			rows[i][j] = false;
	int ihole=0;
	bool rowsOk = true;
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			char ch;
			cin >> ch;
			int digit = ch-'0';
			grid[i][j] = digit;
			if (digit == 0) {
				r[ihole] = i;
				c[ihole] = j;
				ihole++;
			}
			else if (rows[i][digit])
				rowsOk = false;
			else
				rows[i][digit] = true;
		}
	}
	return rowsOk;
}

bool checkCols()
{
	for(int i=0; i<9; i++)
		for(int j=1; j<=9; j++)
			cols[i][j] = false;
	for(int j=0; j<9; j++) {
		for(int i=0; i<9; i++) {
			int digit = grid[i][j];
			if (digit > 0) {
				if (cols[j][digit])
					return false;
				else
					cols[j][digit] = true;
			}
		}
	}
	return true;
}

bool checkSqs()
{
	for(int i=0; i<9; i++)
		for(int j=1; j<=9; j++)
			sqs[i][j] = false;
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			int digit = grid[i][j];
			if (digit > 0) {
				int k = 3*(i/3) + (j/3);
				if (sqs[k][digit])
					return false;
				else
					sqs[k][digit] = true;
			}
		}
	}
	return true;
}

bool okPlace(int ihole, int val)
{
	int row = r[ihole];
	int col = c[ihole];
	int sq = 3*(row/3) + (col/3);
	if (!rows[row][val] && !cols[col][val] && !sqs[sq][val]) {
		grid[row][col] = val;
		return true;
	}
	else
		return false;
}

void printGrid()
{
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++)
			cout << grid[i][j];
		cout << endl;
	}
}

int main()
{
	int ncases;
	cin >> ncases;
	for(int icase=1; icase<=ncases; icase++) {
		bool found = false;
		ok = getInput();
		if (ok)
			ok = checkCols();
		if (ok)
			ok = checkSqs();
		if (ok) {
			for(int i1=1; i1<=9; i1++) {
				if (okPlace(0, i1))
				for(int i2=1; i2<=9; i2++) {
					if (okPlace(1, i2))
					for(int i3=1; i3<=9; i3++) {
						if (okPlace(2, i3))
					 	for(int i4=1; i4<=9; i4++) {
					 		if (okPlace(3, i4))
					 		for(int i5=1; i5<=9; i5++) {
					 			if (okPlace(4, i5)) {
									found = true;
									break;
								}
							}
							if (found) break;
						}
						if (found) break;
					}
					if (found) break;
				}
				if (found) break;
			}
		}
		if (ok && found)
			printGrid();
		else
			cout << "Could not complete this grid." << endl;
		if (icase < ncases)
			cout << endl;
	}
	return 0;
}
