
//  CuckooHash
//
//  Created by Avi on 9/12/16.
//  Copyright © 2016 AVI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>// for memset
#include <cstdlib>// for abs fct.
using namespace std;




class Hash
{
public:

//////// Data members
  int tableLength;
  vector<int> table;

/////// constructor + Destructor


  //default constructor
  Hash() : tableLength(0) {};

  // parameterized constructor
   Hash(int size)
  {
    tableLength = size;
    for (int i = 0; i < tableLength; i++)
      table.push_back(0);
  }

  // Destructor
  //~Hash();

//////// Functions

  // Returns the location that a given key should be placed
  int hash( int itemKey )
  {
    return itemKey % tableLength;
  }

  // Adds an item and if successfully adds, returns true
  bool insertItem( int newItem )
  {
    hashValue = hash(newItem);

    if (table[hashValue]!=0) //if the place the item is too be inserted is already full
      return false;

    table
    return true;

  }

  // removes item and Returns the removed item
  int removeItem( int keyToRemoveFrom );

  void printTable();


};


int main()
{

  // INPUT DATA
  int NumCases = 0;
  int tablesSizes[2]; //sizes for two tables
  int numberItems;    //number of input Items
  int items[1000]; // each items for a specific case

  cin >> tablesSizes[0] >> tablesSizes[1] >> numberItems;
  while ( tablesSizes[0] != 0 && tablesSizes[1] != 0 && numberItems != 0)
  {
    cout << "Case " << ++cases << ":" << endl;

    //Getting the item data for a case
    for (int i = 0; i < numberItems; i++)
    {
      cin items[i];
    }



    cin >> tablesSizes[0] >> tablesSizes[1] >> numberItems;
  }

  for (int i =0; i < numberItems; i++)
  {
    cin >> cases[i];
  }

  cout << " I have gotten the following data:";

  cout << "size of T1 and T2" <<  tablesSizes[0] <<  tablesSizes[1] << endl;
  for (int i =0; i < numberItems; i++)
  {
    cout << cases[i];
  }


  return 0;
}
