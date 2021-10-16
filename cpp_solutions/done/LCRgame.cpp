// LCR game

/*
 LCR is a simple game for three or more players. Each player starts with three chips and the object is to
 be the last person to have any chips. Starting with Player 1, each person rolls a set of three dice. Each
 die has six faces, one face with an L, one with a C, one with an R and three with a dot. For each L
 rolled, the player must pass a chip to the player on their left (Player 2 is considered to be to the left of
 Player 1); for each R rolled, the player passes a chip to the player on their right; and for each C rolled,
 the player puts a chip in a central pile which belongs to no player. No action is taken for any dot that
 is rolled. Play continues until only one player has any chips left. In addition, the following rules apply:
 1. A player with no chips is not out of the game, since they may later gain chips based on other
 players’ rolls.
 2. A player with only 1 or 2 chips left only rolls 1 or 2 dice, respectively. A player with no chips left
 does not roll but just passes the dice to the next player.
 Your job is to simulate this game given a sequence of dice rolls.
 Input
 Input will consist of multiple test cases. Each test case will consist of one line containing an integer n
 (indicating the number of players in the game) and a string (specifying the dice rolls). There will be at
 most 10 players in any game, and the string will consist only of the characters ‘L’, ‘C’, ‘R’ and ‘.’. In
 some test cases, there may be more dice rolls than are needed (i.e., some player wins the game before
 you use all the dice rolls). If there are not enough dice rolls left to complete a turn (for example, only
 two dice rolls are left for a player with 3 or more chips) then those dice rolls should be ignored. A value
 of n = 0 will indicate end of input.
 Output
 For each test case, output the phrase “Game i:” on a single line (where i is the case number starting
 at 1) followed by a description of the state of the game. This desciption will consist of n+1 lines of the
 form
 Player 1:c1
 Player 2:c2
 ...
 Player n:cn
 Center:ct
 where c1, c2 ... cn are the number of chips each player has at the time the simulation ended (either
 because some player has won or there are no more remaining dice rolls) and ct is the number of chips
 in the center pile. In addition, if some player has won, you should append the string “(W)” after their
 chip count; otherwise you should append the string “(*)” after the chip count of the player who is the
 next to roll. The only blank on any line should come before the game number or the player number.
 Use a single blank line to separate test cases.
 
 Sample Input
 
 3 LR.CCR.L.RLLLCLR.LL..R...CLR.
 5 RL....C.L 0
 
 
 Sample Output
 
 Game 1:
 Player 1:0
 Player 2:0
 Player 3:6(W)
 Center:3
 
 Game 2:
 Player 1:1
 Player 2:4
 Player 3:1
 Player 4:4(*)
 Player 5:4
 Center:1
 
 */

#include <iostream>
#include <string>
using namespace std;

const int MAXP = 10;

int players[MAXP+1];
int n;
string rolls;

void initPlayers()
{
	for(int i=0; i<n; i++)
		players[i] = 3;
	players[n] = 0;
}

int processRoll(int p, int i)
{
	int left = (p+1)%n;
	int right = (p-1);
	if (right<0)
		right += n;
	int maxr = 3;
	if (players[p] < maxr)
		maxr = players[p];
	for(int j=0; j<maxr; j++) {
		switch (rolls[i+j]) {
		case 'L' : players[left]++; players[p]--; break;
		case 'R' : players[right]++; players[p]--; break;
		case 'C' : players[n]++; players[p]--; break;
		}
	}
	int count=0;
	int winner;
	for(int j=0; j<n; j++)
		if (players[j] == 0)
			count++;
		else
			winner = (j+1);
	if (count == n-1)
		return -winner;
	else
		return i+maxr;
}

int main()
{
	int iGame=0;
	cin >> n;
	while (n > 0) {
		iGame++;
		cin >> rolls;
		initPlayers();
		int p=0, iRoll=0;
		while(iRoll >= 0 && rolls.length()-iRoll >= min(3,players[p])) {
			iRoll = processRoll(p, iRoll);
			p = (p+1)%n;
		}
		cout << "Game " << iGame << ":" << endl;
		for(int i=0; i<n; i++) {
			cout << "Player " << i+1 << ":" << players[i];
			if (i+1 == -iRoll)
				cout << "(W)";
			else if(iRoll>=0 && i==p)
				cout << "(*)";
			cout << endl;
		}
		cout << "Center:" << players[n] << endl;

		cin >> n;
		if (n>0)
			cout << endl;
	}
	return 0;
}
