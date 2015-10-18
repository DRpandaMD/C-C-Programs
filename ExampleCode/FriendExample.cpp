/*
 * FriendExample.cpp
 *
 *  Created on: May 4, 2015
 *      Author: michaelzarate
 */

#include <iostream>
using namespace std;

//friend function
class data {
	int x,y;

public:
	data(int a, int b) : x(a), y(b) {}
	void getData()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	friend data setSquares(data);
};
data setSquares(data d)
{
//function setSquares can access the private (and protected) members of class data
//because it is declared a friend of that class
 d.x = d.x*d.x;
 d.y = d.y*d.y;
 return d;
}
int main () {
 data obd(4,5);
 cout << "Initial values"<<endl;
 obd.getData();
 cout << "Modified values"<<endl;
 (setSquares(obd)).getData();
}




