#include <iostream>
#include <vector>
using namespace std;


// Right rotation
// Assume the array content is: 0 1 2 3 4
// ● After a right rotation it will be: 4 0 1 2 3

void printVect(vector<int> vect , int size)
{
    for(int i = 0; i< size ; i++)
    {
        cout <<vect[i];
        cout<<" ";
    }
}

void RightRotation(vector<int> &vect , int size)
{
    int rightNum = vect[vect.size() -1];
    for(int i = vect.size() -1 ; i>0;i--)
    {
        vect[i] = vect[i-1];
    }

    vect[0] = rightNum;
}


int main()
{
    vector<int>  vect = {0 ,1 ,2, 3, 4};
    
    RightRotation(vect ,vect.size() );

    printVect(vect ,vect.size() );




    return 0;
}