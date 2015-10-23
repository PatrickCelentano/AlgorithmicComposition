#include "Base.hpp"
#include "Line.hpp"
#include "Defines.hpp"
#include <iostream>

using namespace std;

int main()
{
	
	Note a(Pitch(C,NATURAL,4),Count(1,4));
	Note b(Pitch(B,NATURAL,4),Count(1,4));
	Note c(Pitch(REST),Count(1,4));
	Note d(Pitch(D,NATURAL,5),Count(1,4));
	
	Line melody;
	melody.add(a);
	melody.add(b);
	melody.add(c);
	melody.add(d);
	
	cout << melody.getLilyPond();
	
	return 0;
}




	//Pitch a(C,NATURAL,4);
	//Count b = Count(1,2);

	/*
	cout << b.getASCII() << endl;
	cout << (b/3+b/2).getASCII() << endl;
	*/
	
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