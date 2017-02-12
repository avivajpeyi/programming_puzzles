
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point{ double x =0, y=0;};


void printPoint(point temp)
{
    cout << "(" << temp.x << "," << temp.y << ")";
}

void printCase(point bestPoint, int shortestDistance, int caseNum)
{
    cout << "Case " << ++caseNum << ": ";
    printPoint(bestPoint);
    cout << " " << shortestDistance << endl;
}




int main()
{
    
    //Input for each test case will be a series of integers on one or more lines. The first integer, n (1 ≤ n ≤1000), indicates the number of mob members. There follow n pairs of integers indicating the location (intersection) of each member. The location coordinates are both between 0 and 106, inclusive. Morethan one member may be at the same intersection. A line containing 0 will follow the last test case.
    
    int n, caseNum = 0;
    
    
    // getting data for each case
    while (cin >>n)
    {
    vector <point> peoplePositions;
    
    // getting data for all the locations of the people
    for(int i = 0; i < n; i++)
    {
        point temp;
        cin >> temp.x >> temp.y;
        peoplePositions.push_back(temp);
    }
    
        point bestPoint, averagePoint;
        int shortestDistance = 0;
        
        
        
     
    // calculating the average position
    {
        for(int i = 0; i < n; i++)
        {
        averagePoint.x += peoplePositions[i].x;
        averagePoint.y += peoplePositions[i].y;
        }
        
        averagePoint.x  = round(averagePoint.x/n);
        averagePoint.y  = round(averagePoint.y/n);
    }
        
        
        
        
        printCase(bestPoint,shortestDistance,caseNum);
    }
    
    
    
    
    
    
    
    return 0; 
}
