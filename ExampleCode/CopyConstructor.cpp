/*
 * CopyConstructor.cpp
 *
 *  Created on: May 4, 2015
 *      Author: michaelzarate
 */



#include <iostream>
using namespace std;
//The assignment operator is used to copy the values from one object to another already
//existing object.
//A copy constructor is a special constructor that initializes a new object from an existing
//object.
class assign
{
private:
 int value;
public:
 assign(int in = 0) {
 value = in;
 }
 // Copy constructor
 assign(const assign &obc) {
 value = obc.value;
 cout << "copy constructor called"<<endl;
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
cout<<endl;
}

