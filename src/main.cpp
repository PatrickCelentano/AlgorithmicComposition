#include "Base.hpp"
#include "Line.hpp"
#include "Harmony.hpp"
#include "Defines.hpp"
#include <iostream>

using namespace std;

void intervalsTest();
void scaleTest();

int main()
{
	return 0;
}
/*
	Line melody;
	Scale scale(Pitch(C,NATURAL,4),MAJOR);
	for(int i = scale.getNumDegrees()+10; i > 0; i--)
	{
		melody.addNote(Note(scale.getDegree(i),Count(1,4)));
	}
	cout << std::endl;
	for(int i = 1; i < 9; i++)
	{
		std::cout << melody.getNote(i).getPitch().getASCII() << " ";
	}
	*/
/*
void intervalsTest()
{
	vector<Pitch> pitches;
	pitches.push_back(Pitch(C,NATURAL,4));
	pitches.push_back(Pitch(D,NATURAL,4));
	pitches.push_back(Pitch(E,NATURAL,4));
	pitches.push_back(Pitch(F,NATURAL,4));
	pitches.push_back(Pitch(G,NATURAL,4));
	pitches.push_back(Pitch(A,NATURAL,4));
	pitches.push_back(Pitch(B,NATURAL,4));
	
	vector<Interval> intervals;
	intervals.push_back(Interval(MINOR,2));
	intervals.push_back(Interval(MAJOR,2));
	intervals.push_back(Interval(MINOR,3));
	intervals.push_back(Interval(MAJOR,3));
	intervals.push_back(Interval(PERFECT,4));
	intervals.push_back(Interval(PERFECT,5));
	intervals.push_back(Interval(MINOR,6));
	intervals.push_back(Interval(MAJOR,6));
	intervals.push_back(Interval(MINOR,7));
	intervals.push_back(Interval(MAJOR,7));
	
	for(unsigned int j = 0; j < intervals.size(); j++)
	{
		for(unsigned int i = 0; i < pitches.size(); i++)
		{
			Interval interval1 = intervals[j];
			Pitch pitch = pitches[i] + interval1;
			Interval interval2 = pitch - pitches[i];
			std::cout << pitches[i].getASCII() << " to " << pitch.getASCII() << ":\t" << interval1.getASCII() << "\tvs. " << interval2.getASCII() << std::endl;
		}
		std::cout << std::endl;
	}
}
void scaleTest()
{
	Scale scale(Pitch(C,NATURAL,4),MELODIC_MINOR);
	std::string i;
	int lastDeg = 1;
	
	while(i != "quit")
	{
		int newDeg = 0;
		std::cin >> i;
		if(i == "1") newDeg = 1;
		if(i == "2") newDeg = 2;
		if(i == "3") newDeg = 3;
		if(i == "4") newDeg = 4;
		if(i == "5") newDeg = 5;
		if(i == "6") newDeg = 6;
		if(i == "7") newDeg = 7;
		if(i == "8") newDeg = 8;
		if(i == "9") newDeg = 9;
		if(i == "0") newDeg = 10;
		Pitch pitch = scale.getDegree(newDeg,lastDeg);
		std::cout << pitch.getASCII() << std::endl;
	}
}
*/

/*
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
	
	Interval M3(MAJOR,3);
	Interval m3(MINOR,3);
	
	Interval P5;
	P5 = m3 + M3;
	cout << P5.getASCII() << endl;
	*/
	
	/*
	Pitch root(C,NATURAL,4);
	Pitch third(E,NATURAL,4);
	Pitch fifth(G,NATURAL,4);
	Pitch seventh(B,NATURAL,4);
	
	vector<Pitch> pitches;
	pitches.push_back(root);
	
	pitches.push_back(third);
	pitches.push_back(fifth);
	pitches.push_back(seventh);
	
	for(unsigned int i = 0; i < pitches.size(); i++)
	{
		for(unsigned int j = 0; j < pitches.size(); j++)
		{
			Interval interval = (Pitch)pitches[j] - (Pitch)pitches[i];
			std::cout << pitches[j].getASCII() << " - " << pitches[i].getASCII() << " = " << interval.getASCII() << std::endl;
		}
	}
	*/
	/*
	Pitch root(C,NATURAL,4);
	Pitch third(E,NATURAL,4);
	Pitch fifth(G,NATURAL,4);
	Pitch seventh(B,NATURAL,3);
	
	vector<Pitch> pitches;
	pitches.push_back(root);
	
	pitches.push_back(third);
	pitches.push_back(fifth);
	pitches.push_back(seventh);
	
	for(unsigned int i = 0; i < pitches.size(); i++)
	{
		for(unsigned int j = 0; j < pitches.size(); j++)
		{
			Interval interval = (Pitch)pitches[j] - (Pitch)pitches[i];
			std::cout << pitches[j].getASCII() << " - " << pitches[i].getASCII() << " = " << interval.getASCII() << std::endl;
		}
	}*/
	/*
	vector<Pitch> scale;
	scale.push_back(Pitch(C,SHARP,4));
	
	scale.push_back(Pitch(D,DOUBLE_FLAT,4));
	scale.push_back(Pitch(D,FLAT,4));
	scale.push_back(Pitch(D,NATURAL,4));
	scale.push_back(Pitch(D,SHARP,4));
	scale.push_back(Pitch(D,DOUBLE_SHARP,4));
	
	scale.push_back(Pitch(E,DOUBLE_FLAT,4));
	scale.push_back(Pitch(E,FLAT,4));
	scale.push_back(Pitch(E,NATURAL,4));
	scale.push_back(Pitch(E,SHARP,4));
	scale.push_back(Pitch(E,DOUBLE_SHARP,4));
	
	scale.push_back(Pitch(F,DOUBLE_FLAT,4));
	scale.push_back(Pitch(F,FLAT,4));
	scale.push_back(Pitch(F,NATURAL,4));
	scale.push_back(Pitch(F,SHARP,4));
	scale.push_back(Pitch(F,DOUBLE_SHARP,4));
	
	scale.push_back(Pitch(G,DOUBLE_FLAT,4));
	scale.push_back(Pitch(G,FLAT,4));
	scale.push_back(Pitch(G,NATURAL,4));
	scale.push_back(Pitch(G,SHARP,4));
	scale.push_back(Pitch(G,DOUBLE_SHARP,4));
	
	scale.push_back(Pitch(A,DOUBLE_FLAT,4));
	scale.push_back(Pitch(A,FLAT,4));
	scale.push_back(Pitch(A,NATURAL,4));
	scale.push_back(Pitch(A,SHARP,4));
	scale.push_back(Pitch(A,DOUBLE_SHARP,4));
	
	scale.push_back(Pitch(B,DOUBLE_FLAT,4));
	scale.push_back(Pitch(B,FLAT,4));
	scale.push_back(Pitch(B,NATURAL,4));
	scale.push_back(Pitch(B,SHARP,4));
	scale.push_back(Pitch(B,DOUBLE_SHARP,4));
	
	scale.push_back(Pitch(D,NATURAL,4));
	scale.push_back(Pitch(E,FLAT,4));
	scale.push_back(Pitch(F,NATURAL,4));
	scale.push_back(Pitch(G,NATURAL,4));
	scale.push_back(Pitch(A,FLAT,4));
	scale.push_back(Pitch(B,FLAT,4));
	scale.push_back(Pitch(C,NATURAL,5));
	scale.push_back(Pitch(D,NATURAL,5));
	scale.push_back(Pitch(E,FLAT,5));
	scale.push_back(Pitch(F,NATURAL,5));
	scale.push_back(Pitch(G,NATURAL,5));
	scale.push_back(Pitch(A,FLAT,5));
	scale.push_back(Pitch(B,FLAT,5));
	scale.push_back(Pitch(C,NATURAL,6));
	
	for(unsigned int i = 1; i < scale.size(); i++)
	{
		if((i-1)%5 == 0)
			std::cout << std::endl;
		Interval interval = (Pitch)scale[i] - (Pitch)scale[i-1];
		std::cout << scale[i].getASCII() << "\t- " << scale[i-1].getASCII() << " = " << interval.getASCII() << std::endl;
	}
	*/
	

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
	/*
	vector<Pitch> pitches;
	pitches.push_back(Pitch(C,NATURAL,4));
	pitches.push_back(Pitch(D,NATURAL,4));
	pitches.push_back(Pitch(E,NATURAL,4));
	pitches.push_back(Pitch(F,NATURAL,4));
	pitches.push_back(Pitch(G,NATURAL,4));
	pitches.push_back(Pitch(A,NATURAL,4));
	pitches.push_back(Pitch(B,NATURAL,4));
	
	vector<Interval> intervals;
	intervals.push_back(Interval(MINOR,2));
	intervals.push_back(Interval(MAJOR,2));
	intervals.push_back(Interval(MINOR,3));
	intervals.push_back(Interval(MAJOR,3));
	intervals.push_back(Interval(PERFECT,4));
	intervals.push_back(Interval(PERFECT,5));
	intervals.push_back(Interval(MINOR,6));
	intervals.push_back(Interval(MAJOR,6));
	intervals.push_back(Interval(MINOR,7));
	intervals.push_back(Interval(MAJOR,7));
	
	for(unsigned int j = 0; j < intervals.size(); j++)
	{
		for(unsigned int i = 0; i < pitches.size(); i++)
		{
			Interval interval1 = intervals[j];
			Pitch pitch = pitches[i] + interval1;
			Interval interval2 = pitch - pitches[i];
			std::cout << pitches[i].getASCII() << " to " << pitch.getASCII() << ":\t" << interval1.getASCII() << "\tvs. " << interval2.getASCII() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
	*/