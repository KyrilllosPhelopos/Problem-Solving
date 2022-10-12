#include <iostream>
#include <vector>
using namespace std;

//Left Rotation
// ● Example
// ● Assume the array content is: 0 1 2 3 4
// ● After a left rotation, it will be: 1 2 3 4 0

void printVect(vector<int> vect , int size)
{
    for(int i = 0; i< size ; i++)
    {
        cout <<vect[i];
        cout<<" ";
    }
}

void LeftRotation(vector<int> &vect , int size)
{
    int leftNum = vect[0];

    for(int i = 0 ; i < size -1 ;i++)
    {
        vect[i] = vect[i + 1];
    }

    vect[size -1] = leftNum;
}


int main()
{
    vector<int>  vect = {0 ,1 ,2, 3, 4};
    
    LeftRotation(vect ,vect.size() );

    printVect(vect ,vect.size() );




    return 0;
}