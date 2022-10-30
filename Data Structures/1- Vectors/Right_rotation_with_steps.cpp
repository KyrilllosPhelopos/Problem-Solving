#include <iostream>
#include <vector>
using namespace std;


//Right rotation with steps
// ● This one applies the right rotation times time
// ● Assume array content is: 0 1 2 3 4
// ● right_rotate(2) ⇒ it will be: 3 4 0 1 2

void printVect(vector<int> vect , int size)
{
    for(int i = 0; i< size ; i++)
    {
        cout <<vect[i];
        cout<<" ";
    }
}

void right_rotate(vector<int> &vect , int size , int times)
{
    for (int j = 0; j <=times ; j++)
    {
        int rightNum = vect[size -1];
        for(int i = size-1 ; i>0 ;i--)
        {
            vect[i] = vect[i-1];
        }

        vect[0] = rightNum;
    }
    
}


int main()
{
    vector<int>  vect = {0 ,1 ,2, 3, 4};
    
    right_rotate(vect ,vect.size() , 0);

    printVect(vect ,vect.size() );




    return 0;
}