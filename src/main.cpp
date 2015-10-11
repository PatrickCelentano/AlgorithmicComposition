#include "Pitch.hpp"
#include "Interval.hpp"
#include "Count.hpp"
#include "Defines.hpp"
#include <iostream>

using namespace std;

int main()
{
	Pitch a(C,NATURAL,4);
	Count b = Count(1,2);

	cout << b.getASCII() << endl;
	cout << (b/3+b/2).getASCII() << endl;
	
	//Scale s(C,MAJOR);
	//Key k(C,MAJOR);
	
	
	//cout << a.getASCII() << endl << endl;
	
	/*
	// cout << "Plus " << Interval(PERFECT,1).getASCII() << endl;
	cout << (a+Interval(PERFECT,1)).getASCII() << endl;
	
	// cout << "Plus " << Interval(MAJOR,2).getASCII() << endl;
	cout << (a+Interval(MAJOR,2)).getASCII() << endl;
	
	// cout << "Plus " << Interval(MAJOR,3).getASCII() << endl;
	cout << (a+Interval(MAJOR,3)).getASCII() << endl;
	
	// cout << "Plus " << Interval(PERFECT,4).getASCII() << endl;
	cout << (a+Interval(PERFECT,4)).getASCII() << endl;
	
	// cout << "Plus " << Interval(PERFECT,5).getASCII() << endl;
	cout << (a+Interval(PERFECT,5)).getASCII() << endl;
	
	// cout << "Plus " << Interval(MAJOR,6).getASCII() << endl;
	cout << (a+Interval(MAJOR,6)).getASCII() << endl;
	
	// cout << "Plus " << Interval(MAJOR,7).getASCII() << endl;
	cout << (a+Interval(MAJOR,7)).getASCII() << endl;
	
	// cout << "Plus " << Interval(PERFECT,8).getASCII() << endl;
	cout << (a+Interval(PERFECT,8)).getASCII() << endl;
	*/

	/*
	// cout << "Minus " << Interval(PERFECT,1).getASCII() << endl;
	cout << (a-Interval(PERFECT,1)).getASCII() << endl;
	
	// cout << "Minus " << Interval(MINOR,2).getASCII() << endl;
	cout << (a-Interval(MINOR,2)).getASCII() << endl;
	
	// cout << "Minus " << Interval(MINOR,3).getASCII() << endl;
	cout << (a-Interval(MINOR,3)).getASCII() << endl;
	
	// cout << "Minus " << Interval(PERFECT,4).getASCII() << endl;
	cout << (a-Interval(PERFECT,4)).getASCII() << endl;
	
	// cout << "Minus " << Interval(PERFECT,5).getASCII() << endl;
	cout << (a-Interval(PERFECT,5)).getASCII() << endl;
	
	// cout << "Minus " << Interval(MINOR,6).getASCII() << endl;
	cout << (a-Interval(MINOR,6)).getASCII() << endl;
	
	// cout << "Minus " << Interval(MINOR,7).getASCII() << endl;
	cout << (a-Interval(MINOR,7)).getASCII() << endl;
	
	// cout << "Minus " << Interval(PERFECT,8).getASCII() << endl;
	cout << (a-Interval(PERFECT,8)).getASCII() << endl;
	*/
	
	return 0;
}