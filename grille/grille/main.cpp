/*
 
 GRILL DECRYPTION
 
 
 Take an encrypted message and the corresponding grille and decrypt it.
 T he grille given might be invalid, i.e., the
 holes used do not allow every location in the grid to be used during the encryption process. If this is
 the case, then you must indicate that you can’t decrypt the message.
 
 
 
 Input: 
 
 The input starts with a line containing a positive integer n ≤ 10 indicating the size of the grid and
 grille.
 The next n lines will specify the grille, using ‘.’ for a hole and ‘X’ for a non-hole. 
 Following
 this will be a line containing the encrypted message, consisting solely of lowercase alphabetic
 characters. 
 The number of characters in this line will always be n*n
 
 
 Output
 Output the decrypted text as a single string with no spaces, or the phrase “invalid grille” if
 the grille is invalid.
 
 
 SAMPLE:
 
 4
 XX.X
 X.X.
 XXXX
 .XXX
 noeesrksdmnyemoj
 
 -->  sendmoremonkeysj
 
 4
 .XX.
 XXXX
 XXXX
 .XX.
 abcdefghijklmnop
 
 --> invalid grille
 
 2
 X.
 XX
 aybb
 
 --> baby
 
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;



vector<vector<char>>  grille;
vector<vector<char>>  encryptionGrid;
vector<vector<char>>  decryptedGrid;
vector<vector<bool>>  grillValidation;

string encryptedString = "";

int countOfhole = 0;



void printCharMatrix(int dimension, vector<vector<char>> M )
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            cout << M[i][j];
        }
        cout << '\n';
    }
    cout << "\n";
}





// creates a matrix of chars of the grid
void grilleGenerator( int dimension)
{
    // get the data from the user
    vector<string> grilleInputLines;
    for (int i = 0; i < dimension; i++)
    {
        string inputLine ; cin >> inputLine;
        grilleInputLines.push_back(inputLine);
    }
    cin >> encryptedString;

    
    // put data into grids
    for (int i = 0; i < dimension; i++)
    {
        vector<char> GrilleLine ;
        vector<char> EncyptedLine ;
        vector<char> DecryptedLine ;
        vector<bool> checkGrilleLine;
        for (int j = 0; j < dimension; j++)
        {
            GrilleLine.push_back(grilleInputLines[i].at(j));
            int indexOffset = i*dimension;
            EncyptedLine.push_back(encryptedString.at(j+indexOffset));
            
            
            // Checking the intputted grille for holes's
            if (GrilleLine[j]=='.')
            {
                checkGrilleLine.push_back(true);
                DecryptedLine.push_back(encryptedString[countOfhole]);
                countOfhole++;
            }
            else // if not a hole
            {
                checkGrilleLine.push_back(false);
                DecryptedLine.push_back('X');
            }

        }
        grille.push_back(GrilleLine);
        encryptionGrid.push_back(EncyptedLine);
        grillValidation.push_back(checkGrilleLine);
        decryptedGrid.push_back(DecryptedLine);
        
    }

    
//    cout << "\nGrille\n";
//    printCharMatrix(dimension, grille);
//    
//    
//    cout << "\nEncrypted Matrix\n";
//    printCharMatrix(dimension, encryptionGrid);
}


//Adds the letter from the encrypted string at every '.' encountered
void grilleCheck(int dimension)
{
    for(int i=0; i<dimension; i++)
    {
        for(int j=0; j<(dimension); j++)
        {
            if (grille[i][j] == '.')
            {
                grillValidation[i][j] = true;
                decryptedGrid[i][j] = encryptedString[countOfhole];
                countOfhole++;
                
//                cout << endl << "CURRENT DECRYPTION at "<< i <<" " << j << endl;
//                printCharMatrix(dimension, decryptedGrid);
//                
            }
        }
    }

}

//swaps the values for the double dimension matrix
void rotate(int i, int j, int x, int y)
{
    int temp = grille[i][j];
    grille[i][j] = grille[y][i];
    grille[y][i] = grille[x][y];
    grille[x][y] = grille[j][x];
    grille[j][x] = temp;
}

// checks if grid valid and updates the decrypted grid if it is
bool validGrid(int dimension)
{
    bool isValid = true;
    
    
    /*
      0 1 2
      3 4 5
      6 7 8 
     
     -->
     
      0 3 6
      1 4 7
      2 5 8
     
     */
    
    // rotating the grid and updating the decrypted grid after each rotation
    for (int rotation = 0; rotation < 3; rotation++)
    {
        for(int i=0; i<dimension/2; i++)
        {
            for(int j=0; j<(dimension+1)/2; j++)
            {
                int x = dimension-1-i;
                int y = dimension-1-j;
                rotate(i, j, x, y);
            }
        }
        
       
        // checking the grills holes and matching the encrypted grid to find decryption values
        grilleCheck(dimension);
    }
    
    // checks if the entire encrypted grid has been considered
    for(int i=0; i<dimension; i++)
        for(int j=0; j<(dimension); j++)
            isValid = grillValidation[i][j] and isValid;
    
    
    return isValid;

}


    
    
    




int main()
{
    
    // get the size of the grille
    int dimension; cin >> dimension;

    
    // fill the grille with X and .
    grilleGenerator(dimension);
    

    
    // check if valid grille
    if (validGrid(dimension))
    {
        string decryptedMessage = "";
        for (int i = 0; i < dimension; i ++)
            for (int j = 0; j < dimension; j++)
            {
                decryptedMessage+= decryptedGrid[i][j];
            }
        cout << endl << decryptedMessage << endl;
    }
    else
        cout << "\ninvalid grille" << endl;

    
    return 0;
}


