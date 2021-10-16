

// Avi
// Solution for problem E from 2009 ACM Contest

#include <iostream>
#include <cmath>

using namespace std;

int caseNum = 1;

// My Island Info
int island[100][100];
int gridHeight = 0, gridWidth = 0;
int peak = 0;
int oceanLevel = 0;
bool IslandSplit = false;

void inputInfo()
{
	   for (int i = 0; i < gridHeight; i ++){
           for (int j = 0; j < gridWidth; j ++){
               cin >> island[i][j];
               if (island[i][j] >= peak) peak = island[i][j];
           }
       }
    
     peak = 0;
     oceanLevel = 0;
     IslandSplit = false;
    
    
}

void outputInfo(bool IslandSplit)
{
    cout << "Case " << caseNum++ << ": ";
    
    if (IslandSplit) cout << "Island splits when ocean rises "<< oceanLevel<<" feet.";
    else cout << "Island never splits.";
}


void printIsland()
{
	   for (int i = 0; i < gridHeight; i ++){
           for (int j = 0; j < gridWidth; j ++){
               cout <<  island[i][j];	}
           cout << endl << "Peak is " << peak << " feet above sea level";
       }
}


void islandSplitCheck()
{
    IslandSplit = false;
    
    
    
}

void ocenLevelRises()
{
    oceanLevel++;
    for (int i = 0; i < gridHeight; i ++){
        for (int j = 0; j < gridWidth; j ++){
            island[i][j]--;}
    }
}


int main()
{
    int n, m;

    
    do
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        
        gridHeight=0;
        gridWidth=0;
        
        // INPUT INFO and reset Island
        inputInfo();
        printIsland();
        
        
        // Until entire island Submerges
        while (peak != 0 && not IslandSplit)
        {
            // let it rain
            ocenLevelRises();
            
            // check if split
            
        }
        
            
        
        
    } while (n != 0 && m != 0);
    
    
    
}