
//Nan's Windows Cluttered Windows Solution 

/*
 Your job is to determine which window
 (if any) gets selected when Emma clicks on a certain position of the screen.
 Emma’s screen has a resolution of 106 by 106
 . When each window opens its position is given by the
 upper-left-hand corner, its width, and its height. (Assume position (0,0) is the location of the pixel in
 the upper-left-hand corner of her desktop. So, the lower-right-hand pixel has location (999999, 999999).)
 Input
 Input for each test case is a sequence of desktop descriptions. Each description consists of a line
 containing a positive integer n, the number of windows, followed by n lines, n ≤ 100, describing
 windows in the order in which Emma opened them, followed by a line containing a positive integer m,
 the number of queries, followed by m lines, each describing a query. Each of the n window description
 lines contains four integers r, c, w, and h, where (r,c) is the row and column of the upper left pixel of
 the window, 0 ≤ r,c ≤ 999999, and w and h are the width and height of the window, in pixels, 1 ≤ w,h.
 All windows will lie entirely on the desktop (i.e., no cropping). Each of the m query description lines
 contains two integers cr and cc, the row and column number of the location (which will be on the
 desktop). The last test case is followed by a line containing 0.
 Output
 Using the format shown in the sample, for each test case, print the desktop number, beginning with 1,
 followed by m lines, one per query. The i-th line should say either “window k”, where k is the number of
 the window clicked on, or “background” if the query hit none of the windows. We assume that windows
 are numbered consecutively in the order in which Emma opened them, beginning with 1. Note that
 querying a window does not bring that window to the foreground on the screen.
 
 Sample Input
 3
 1 2 3 3
 2 3 2 2
 3 4 2 2
 4
 3 5
 1 2
 4 2
 3 3
 2
 5 10 2 10
 100 100 100 100
 2
 5 13
 100 101
 0
 
 Sample Output
 Desktop 1:
 window 3
 window 1
 background
 window 2
 Desktop 2:
 background
 window 2
 */

#include <iostream>
#include <vector>
using namespace std;

const int MAXS = 999999;

struct win {
    int strr, strc, endr, endc;
    win(int sr=0, int sc=0, int er=0, int ec=0):strr(sr), strc(sc), endr(er), endc(ec) {}
};

vector<win> wins;

int whichWin(int r, int c)
{
    for (int i = wins.size()-1; i >= 0; i--) {
	int sr = wins[i].strr, er = wins[i].endr;
	int sc = wins[i].strc, ec = wins[i].endc;
	if (r >= sr && r <= er && c >= sc && c <= ec) {
	    return i+1;
	}
    }
    return 0;
}

int main()
{
    int T;
    cin >> T;
    int cnt = 0;
    while (T != 0) {
	wins.clear();
	cout << "Desktop " << ++cnt << ':' <<  endl;
	int r, c, w, h;
	bool exceed = false;
	for (int i = 0; i < T; i++) {
	    cin >> r >> c >> w >> h;
	    int er = r + w-1, ec = c + h-1;
	    win buf(r, c, er, ec);
	    wins.push_back(buf);
	}

	int Q;
	cin >> Q;
	int cr, cc;
	for (int i = 0; i < Q; i++) {
	    cin >> cr >> cc;
	    int thisWindow = whichWin(cr, cc);
	    if (thisWindow) {
		cout << "window " << thisWindow << endl;
	    } else {
		cout << "background" << endl;
	    }
	}
	cin >> T;
    }
    return 0;
}
