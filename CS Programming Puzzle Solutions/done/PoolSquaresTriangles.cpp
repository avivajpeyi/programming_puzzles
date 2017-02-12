// Pool squares + triangles

/*
imagine other pool-like games where you have a cue ball and x numbered balls. You’d like to be
able to rack up the x numbered balls in a triangle, and have all x+ 1 balls perfectly fill a square m-by-m
tray. For what values of x is this possible? In this problem you’ll be given an lower bound a and upper
bound b, and asked how many numbers within this range have the above property.



Input
Input for each test case will one line containin two integers a b, where 0 < a < b ≤ 109
. The line 0 0
will follow the last test case.


Output
For each test case one line of output as follows:
Case n: k
if there are k integers x such that a < x + 1 < b, x balls can be racked up in a triangle, and x + 1 balls
fill a square tray.


Sample Input
15 17
14 16
1 20
0 0

Sample Output
Case 1: 1
Case 2: 0
Case 3: 2
*/



#include <math.h>
#include <iostream>
using namespace std; 

bool sqrCheck(int n)
{
    float temp = sqrt(n);
    if(temp*temp == (float)n) return(true);
    else return (false);
}


bool triangleCheck(int x)
{
    // condition for triangular num: x = (n^2 + n)/2

    bool test = false;
   
   for (int i = 1; i < x; i ++)
   { 
        test = ( ((i * (i + 1)) / 2)  == x);
        if (test) return test;    
    }
        
    return test;
}





// check if x+1 is perfect
// check if x is triangel num
int main()
{


int n, x[100];
int a, b;

int caseCount = 1;


while( cin >> a )
{
cin >> b;

if ( a == 0 && b == 0) break;

int numSol = 0;

for(int i = a+1; i < b; i++)
{ 
    if (sqrCheck(i) and triangleCheck(i-1))
        numSol ++;
   
}

cout << "Case " << caseCount++ <<": " << numSol << endl;

}





return 0; 
}





