// Max Parties Attended w/ vectors

/*
 
  Emma has just graduated high school and it is the custom for the new graduates to throw parties for
 themselves and invite everyone in school to attend. Naturally, Emma wishes to attend as many parties
 as possible. This is not such a problem on a weekday since usually there are only two or three parties
 in the evening. But, Saturdays are packed! Typically some parties start at 8 AM (breakfast is served)
 while others might end at midnight (much to the annoyance of the neighbors). Emma naturally wants
 to know how many parties she can attend.
 Each party has a starting and stopping time, which are on the hour. These are listed via a 24-hour
 clock. For example, a party might start at 10 AM (10) and end at 2 PM (14). The earliest a party can
 start is 8 AM (8) and the latest it can end is midnight (24). In order not to be rude, Emma stays at
 each party at least one half hour and will consider traveling time between parties to be instantaneous.
 If there are times during the day when there are no parties to attend, she’ll simply go home and rest.
 
 Input
 There will be multiple test cases. Each test case starts with a line containing an integer p (≤ 100)
 indicating the number of parties on the given day. (A value of p = 0 indicates end of input.) The
 following p lines are each of the form s e, both integers where 8 ≤ s < e ≤ 24, indicating a party that
 starts at time s and ends at time e. Note there may be multiple parties with the same starting and
 ending time.
 
 Output
 For each input set output a line of the form
 On day d Emma can attend as many as n parties.
 where you determine the value of n and d is the number of the test case starting at 1.
 
 
 Sample Input
 8
 12 13
 13 14
 12 13
 9 10
 9 10
 12 13
 12 14
 9 11
 
 3
 14 15
 14 15
 14 15
 0
 
 Sample Output
 On day 1 Emma can attend as many as 7 parties.
 On day 2 Emma can attend as many as 2 parties.
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct party{
    int start;
    int end;
};

// not used 
bool partyCompare(party lhs, party rhs){
    return lhs.start < rhs.start;
}

// compares two parties by duration
// used by sort function from algorithm library 
bool compareByDuration(party lhs, party rhs){
    return (lhs.end - lhs.start) < (rhs.end - rhs.start);
}

// vector that holds party elements
vector<party> myvector;
//array that holds hours in a day
//each hour inside can have 0,1, or 2 parties
int timeSlots[24];

// just displays the vector of party structs
void print()
{
    for (std::vector<party>::iterator it1 = myvector.begin() ; it1 != myvector.end(); ++it1)
        std::cout << (*it1).start << "   "<<(*it1).end<<endl;
}


int main(){
    int day=0, partiesAttended = 0;
    int startParty, noParties;
	party p;
	std::vector<party>::iterator it;// declare an iterator
    
	cin >> noParties;
       
    while(noParties > 0){
        day++;
        
        myvector.clear();// reset the vector for a new day
        memset(timeSlots,0,sizeof(int)*24);// reset to 0 the array timeSlots
		
        partiesAttended = 0;
        
        while (noParties > 0) {
            cin >> p.start;
            cin >> p.end;
            myvector.push_back(p);
            noParties--;
        }// end while -- populate vector with parties
        
        //print(); // print the vector
        
		// sort increasingly the vector by duration of party
		std::sort(myvector.begin(), myvector.end(), compareByDuration);
        
		// cout<< endl <<"After sort by party-length: ";
        // print(); // print the vector
        
        // count how many parties I can attend every hours 
		// it is a max of 2 parties/hour
        for (it = myvector.begin() ; it != myvector.end(); ++it){
            for (int i = (*it).start; i < (*it).end ; ++i) {
                if (timeSlots[i] < 2) {
                    timeSlots[i]++;
                    partiesAttended++;
                    break;
                }
            }
        }

        cout << "On day " << day << " Emma can attend as many as "
			<< partiesAttended << " parties." << endl;
    
        cin >> noParties;
     }//end while
        
    return 0;
}
