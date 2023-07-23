#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person 
{
    public :
    string name ;
    int age;
    virtual void getdata()
    {
        cin>>name>>age;
    }
    virtual void putdata()
    {
        cout<<name<<" "<<age<<endl;
    }
    
};

class Professor: public Person{
  public :
  Professor()
  {
      //totalNum++;
      cur_id = ++id;
  }
  int publications ;
  int cur_id;
  static int id;
 //static int totalNum;
  
  
  void getdata()
  {
    cin>>name;
    cin>>age;
    cin>>publications;
  
  }  
  void putdata()
  {
      cout<<this->name<<" "
      <<this->age<<" "
      <<this->publications<<" "
      <<this->cur_id<<endl; 
  };
};

//int Professor::id = 0;

class Student :public Person{
    public:
    Student()
        {
        //totalNum++;

          cur_id = ++id ;  
        }
        int marks[6];
        int cur_id;
        static int id;
        //static int totalNum;

        
        
        void getdata()
        {
            cin>>name;
            cin>>age;
            
            for(int i =0;i<6;i++)
            cin>>marks[i];
        }
        
        void putdata()
        {
            int sum =0;
            sum=marks[0]+marks[1] + marks[2]+ marks[3]+marks[4]+marks[5];
            cout<<this->name<<" "
            <<this->age<<" "
            <<sum<<" "
            <<this->cur_id<<endl;
        }
    
};
 int Professor::id=0;
int Student::id=0;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int numOfLines=0;
    int lineIdentifier;
    cin>>numOfLines;
    Person* ptr[numOfLines];
    
    for(int i =0 ;i<numOfLines;i++)
    {
        cin>>lineIdentifier;
        if(lineIdentifier ==1)
        {
            ptr[i] = new Professor;
        }
        else if(lineIdentifier == 2 )
        {
            ptr[i] = new Student;
        }
        ptr[i]->getdata();
    }
    
    for(int i =0 ;i<numOfLines;i++)
    ptr[i]->putdata();
    
    return 0;
}
