#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct nodey {
int tempo,valueInput;
struct nodey *letit ;
};
class QueuePriority {
    private:
      nodey *nullifyIt;
    public:
      QueuePriority() {
      nullifyIt = NULL;
}
void add(int i, int jj) {
    nodey *holder, *transition;
    holder = new nodey;
    holder->valueInput = i;
    holder->tempo = jj;
    if (nullifyIt == NULL || jj < nullifyIt->tempo) {
    holder->letit= nullifyIt;
    nullifyIt = holder;
} 
else {
    transition = nullifyIt;
    while (transition->letit != NULL && transition->letit->tempo <= jj)
    transition = transition->letit;
    holder->letit = transition->letit;
    transition->letit = holder;
}
}

void view() {
  nodey *ptr;
  ptr = nullifyIt;
    if (nullifyIt == NULL)
    cout<<"Queue is empty\n";
    else {
        cout<<"Queue is :\n";
        cout<<"Priority Item\n";
        while(ptr != NULL) {
        cout<<ptr->tempo<<" "<<ptr->valueInput<<endl;
        ptr = ptr->letit;
      }
  }
}
void del() {
nodey *value;
if(nullifyIt == NULL)
cout<<"Queue Underflow\n";
else {
value = nullifyIt;
cout<<"Deleted item is: "<<value->valueInput<<endl;
nullifyIt = nullifyIt->letit;
free(value);
}
}
};
int main() {
  int c, i, p;
  QueuePriority finalUser;
  do {
      cout<<"1:add\n";
      cout<<"2:view\n";
      cout<<"3: delete\n";

      cout<<"which num 1-3 ";
      cin>>c;
      switch(c) {
          case 1:
          cout<<"Input the item value to be added in the queue : ";
          cin>>i;
          cout<<"Priority?! ";
          cin>>p;
          finalUser.add(i, p);
          break;
          case 2:
          finalUser.view();
          break;
          break;
          case 3:
          finalUser.del();
          break;




          }
      }
  while(c != 4);
  return 0;
}