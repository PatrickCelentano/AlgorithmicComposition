#include "Pitch.hpp"
#include "Interval.hpp"
#include <iostream>

using namespace std;

int main()
{
	Pitch a(F,FLAT,4);
	cout << a.getASCII() << endl << endl;
	
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
	
	return 0;
}