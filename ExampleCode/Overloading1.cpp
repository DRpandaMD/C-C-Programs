/*
 * Overloading1.cpp
 *
 *  Created on: May 4, 2015
 *      Author: michaelzarate
 */




#include <iostream>
using namespace std;
//The assignment operator is used to copy the values from one object to another already
//existing object.
class assign
{
private:
 int value;
public:
 assign(int in = 0) {
 value = in;
 }
 int getValue(){return value;}
 assign& operator= (const assign &obj);
};
assign& assign::operator= (const assign &obj)
{
 // do the copy
 value = obj.value;
 cout << "assignment overloaded" << endl;
 // return the existing object
 return *this;
}
int main()
{
assign a(5);
assign b;
cout<<endl <<"initilaizing object b"<<endl;
b = a;
cout <<endl <<"initilaizing object c"<<endl;
assign c = a;
cout << c.getValue()<<endl;
cout<<endl;
}

