#include <iostream>
#include <vector>
using namespace std;


// Deleting a position


// ● It returns the deleted value
// ● Remove this element from the array
// ● Assume array is: 4 0 1 2 3
// ● pop(2)
// ○ Return value 1
// ○ New array: 4 0 2 3

void printVect(vector<int> vect , int size)
{
    for(int i = 0; i< size ; i++)
    {
        cout <<vect[i];
        cout<<" ";
    }
}

int pop(vector<int> &vect , int size , int idx)
{
    int num = vect[idx];
    for(int i = idx ; i <size ;i++)
    {
        vect[i] = vect[i+ 1];
    }
    vect.pop_back();
    return num;
}


int main()
{
    vector<int>  vect = {0 ,1 ,2, 3, 4};
    
    pop(vect ,vect.size() , 2 );

    printVect(vect ,vect.size() );

    return 0;
}