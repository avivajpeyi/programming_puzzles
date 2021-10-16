// Twindows,cc
// 2009 ecna
// problem H - Windows
//
// simple stack search

include <iostream>
using namespace std;

const int MAX = 1001;

struct win{
  int ULrow, ULcol, LRrow, LRcol;
};

win Stack[MAX];
int tos;

void PUSH(win A){
  tos++;
  Stack[tos] = A;
}

// for debugging
void PrintStack(){
  for(int i=0;i<=tos;i++)
   cout<< Stack[i].ULrow<<','<<Stack[i].ULcol<<' '<<Stack[i].LRrow<<','<<Stack[i].LRcol<<endl;
  cout<<endl;
}

int main(){
  win X;
  int n, R, C, top;
  int CaseNo=1;
  bool Done;

  cin>>n;       //get # of windows
  while(n>0){
    tos = -1;
    for(int i=0;i<n;i++){    // get n windows
      cin>>X.ULrow>>X.ULcol>>R>>C;
      X.LRrow = X.ULrow + C - 1;
      X.LRcol = X.ULcol + R - 1;
      PUSH(X); 
    }

    cout<<"Desktop "<<CaseNo++<<":"<<endl;

    cin>>n;      // get n querries
    for(int i=0;i<n;i++){
      cin>>R>>C;
      Done = false;
      top = tos;
      while(top>-1 && !Done){
        if(R<Stack[top].ULrow || R>Stack[top].LRrow ||
           C<Stack[top].ULcol || C>Stack[top].LRcol)
          top--;
        else
          Done = true;         //  found window
      }
      if(Done)  //Stack[top] is the window
        cout<<"window "<< top+1<<endl;
      else    
        cout<<"background"<<endl;
    }

    cin>>n;
  }

  return 0;
}

