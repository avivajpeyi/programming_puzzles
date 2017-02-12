//Create jolly.cpp which contains:
// pb. 10038


/*
A sequence of n > 0 integers is called a jolly jumper
if the absolute values of the difference between successive elements
take on all the values 1 through n − 1. For instance, 1 4 2 3 is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies that any sequence of a single integer is a jolly jumper.

You are to write a program to determine whether or not each of a number of sequences is a jolly jumper.

Input: Each line of input contains an integer n ≤ 3000 followed by n integers representing the sequence.

Output: For each line of input, generate a line of output saying ‘Jolly’ or ‘Not jolly’.

Sample Input: 4 1 4 2 3 5 1 4 2 -1 6

Sample Output: Jolly Not jolly

*/
bool checkIfJolly(int len, int num[])
{
  bool isJolly = false;


  for ( int i = 0; i < n - 1; i++ )
  {
    if ( diff[ i ] == 0 || diff[ i ] >= n )
      isJolly = false;
  }
  	isJolly = true;

  if ( isJolly )
  	cout << "Jolly\n";
  else
  	cout << "Not jolly\n";



  return isJolly;
}

#include <iostream>
using namespace std; int main()
{
int n, a[100];

int diff[100];

while( cin >> n )
{
for(int i = 0; i < n; ++i)
cin >> a[i];

for(int i = 0; i < n; ++i)
cout <<a[i]<<"\t";

cout << endl;

// real solution:

// finding diff bw successive elements
for ( int j = 1; j < n; j++ )
	diff[ j - 1 ] = fabs( a[ j - 1 ] - a[ j ] );

int len = a[0];


// checking if jolly
bool isJolly = isItJolly(len, a[100]);


}
return 0;
}
