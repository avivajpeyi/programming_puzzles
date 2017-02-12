// Chain of Fools 

/*
Many of you have heard the story of Turing’s bicycle: Seems the sprocket on the crank of the bicycle
had a broken prong. Also his chain had one link that was bent. When the bent link on the chain came
to hook up with the broken prong, the chain would fall off and Turing would stop and put the chain
back on. But Turing, being who he was, could predict just when this was going to happen — meaning
he would know how many pedal strokes it would be — and so would hop off his bike just before it
happened and gently move the pedals by hand as the undesired coupling passed. Then he’d be merrily
(we imagine) on his way. (A picture of the sprocket-chain set up is shown below.)
Your job here is to calculate the number of revolutions required in such a situation as Turing’s: You’ll
be given the number of prongs on the front sprocket, the number of links on the chain, the location of
the broken prong and the location of the bent link in the chain. The top prong is at location 0, then
the next one forward on the sprocket is location 1 and so on until prong numbered s − 1. (See the
diagram. Notice that prong s − 1 is the next prong that moves to the top of the sprocket as Turing
pedals.) Location of the links is similar: The link at the top of the sprocket is location 0 and so on
forward until c − 1. The chain falls off when broken prong and bent link are both at location 0.


Input
Input for each test case will be one line of the form s c p l, where s is the number of prongs on the front
sprocket (1 < s < 100) , c is the number of links in the chain (200 > c > s), p is the initial position of
the broken prong, and l is the initial position of the bent link. The line 0 0 0 0 will follow the last line
of input.
Broken prong and bent link will never both start at position 0.


Output
For each test case output a single one line as follows:
Case n: r m/s
if it requires r m/s revolutions to first fail, or
Case n: Never
if this can never happen.
Note that the denominator of the fraction will always be the number of prongs on the sprocket; the
fraction will not necessarily be in lowest terms. Always print the values of r and m, even if 0

Sample Input
40 71 32 23
20 40 4 24
40 71 8 33
20 40 3 17
0 0 0 0

Sample Output
Case 1: 1 8/40
Case 2: 0 16/20
Case 3: 25 32/40
Case 4: Never


*/




//2011 ECNA

#include <iostream>
using namespace std;

const bool DEBUG=false;

#define IFD if (DEBUG)

int s, c, p, l; //s = size of chain ring
                //c = length of chain
               //p = location of broken prong
               //l = location of broken link

void step(int &tooth, int & link){
  tooth = (tooth + 1) % s;
  link = (link + 1) % c;
}

int main() {
  int tooth, link, steps, CASES=1;

  cin>>s>>c>>p>>l;
  while(s>0){
    tooth = p; link = l;
    steps = 0;
    //move one step forward until tooth==link==0 OR
    //  get back to original position
IFD cout<<tooth<<' '<<link<<' '<<steps<<endl;
    step(tooth, link);
    steps++;
    while (((tooth>0)||(link>0)) && ((tooth!=p)||(link!=l)))
    {
IFD cout<<tooth<<' '<<link<<' '<<steps<<endl;
      step(tooth, link);
      steps++;
    }

    cout<<"Case "<<CASES++<<":";
    if ((tooth==0) && (link==0))    //chain fell off
    {
      cout <<" "<<steps/s;
      cout<<" "<<steps%s<<'/'<<s;
      cout<<endl;
    }
    else
      cout<<" Never"<<endl;

IFD cout<<steps<<endl;

    cin>>s>>c>>p>>l;
  }

  return 0;
}
