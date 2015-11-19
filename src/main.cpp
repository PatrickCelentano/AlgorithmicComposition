#include "Base.hpp"
#include "Form.hpp"
#include "Harmony.hpp"
#include "Defines.hpp"
#include "Composer.hpp"
#include "MarkovChain.hpp"
#include "OutcomeSet.hpp"

#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	Line line;
	Progression progression;
	Scale scale(Pitch(C,NATURAL,4),HARMONIC_MINOR);
	Key key(Pitch(C,NATURAL,4),HARMONIC_MINOR);
	
	std::vector<vector<int>*> progs;
	
	vector<int>* one = new vector<int>;
	vector<int>* two = new vector<int>;
	vector<int>* three = new vector<int>;
	vector<int>* four = new vector<int>;
	vector<int>* five = new vector<int>;
	vector<int>* six = new vector<int>;
	vector<int>* seven = new vector<int>;
	
	one->push_back(4);
	one->push_back(5);
	one->push_back(7);
	two->push_back(6);
	two->push_back(4);
	two->push_back(6);
	three->push_back(6);
	three->push_back(4);
	four->push_back(5);
	four->push_back(1);
	four->push_back(2);
	five->push_back(6);
	six->push_back(2);
	six->push_back(5);
	six->push_back(3);
	six->push_back(4);
	seven->push_back(1);
	seven->push_back(3);
	seven->push_back(6);
	
	progs.push_back(one);
	progs.push_back(two);
	progs.push_back(three);
	progs.push_back(four);
	progs.push_back(five);
	progs.push_back(six);
	progs.push_back(seven);
	
	/*
	for(int i = 0; i < 7; i++)
	{
		std::cout << i << ": ";
		vector<int> possible = *progs[i];
		std::cout << possible.size() << std::endl;
	}
	*/
	
	int degree = 0;
	for(unsigned int i = 1; i < 30; i++)
	{
		vector<int> possible = *progs[degree];
		int chosen = rand()%possible.size();
		int nextDegree = possible[chosen]-1;
		
		line.add(Note(scale.getDegree(degree),					Count(1,8)));
		line.add(Note(scale.getDegree((degree+nextDegree)/2),	Count(1,8)));
		
		progression.add(Chord(key.getFunction(degree)-Interval(PERFECT,8),Count(1,4)));
		
		degree = nextDegree;
	}
	//Composer::writeSimpleMelody(rand());
	Composer::writeToLilyPond(line,progression);
	return 0;
}










/*
	Scale scale(Pitch(C,NATURAL,4),MAJOR);
	
	for(unsigned int i = 1; i < 20; i++)
	{
		std::cout << (scale.getDegree(i) - scale.getDegree(1)).toString() << std::endl;
	}
	Composer::writeSimpleMelody(rand());
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
			std::cout << pitches[j].toString() << " - " << pitches[i].toString() << " = " << interval.toString() << std::endl;
		}
	}
*/
/*
	srand(time(NULL));
	
	Line melody1;
	Line melody2;
	
	Scale scale(Pitch(C,NATURAL,4),MAJOR);
	melody1.addNote(Note(scale.getDegree(1),Count(1,4)));
	int curDegree = 1;
	
	for(int i = 0; i < 20; i++)
	{
		melody1.addNote(Note(scale.getDegree(curDegree),Count(1,4)));
		curDegree = curDegree + rand()%5 - 3;
	}
	
	for(int i = 0; i < 20; i++)
	{
		melody2.addNote(Note(melody1.getNote(i).getPitch()-Interval(MAJOR,3),Count(1,4)));
	}
	
	Composer::writeToLilyPond(melody2,melody1);
	
	OutcomeSet<Pitch> outcomes;
	outcomes.addOutcome(Pitch(C,NATURAL,4),2);
	outcomes.addOutcome(Pitch(B,NATURAL,4),5);
	outcomes.addOutcome(Pitch(A,NATURAL,4),3);
	
	for(unsigned int i = 0; i < 20; i++)
	{
		for(unsigned int i = 0; i < 5; i++)
		{
			std::cout << outcomes.getOutcome(rand()).toString() << " ";
		}
		std::cout << std::endl;
	}
	*/

/*

void intervalsTest();
void scaleTest();
*/
/*
	
	cout << std::endl;
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
			std::cout << pitches[i]toString() << " to " << pitchtoString() << ":\t" << interval1toString() << "\tvs. " << interval2toString() << std::endl;
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
		std::cout << pitchtoString() << std::endl;
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
	cout << P5toString() << endl;
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
			std::cout << pitches[j]toString() << " - " << pitches[i]toString() << " = " << intervaltoString() << std::endl;
		}
	}
	*/
	/*
	*/
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
		std::cout << scale[i]toString() << "\t- " << scale[i-1]toString() << " = " << intervaltoString() << std::endl;
	}
	*/
	

	//Pitch a(C,NATURAL,4);
	//Count b = Count(1,2);

	/*
	cout << btoString() << endl;
	cout << (b/3+b/2)toString() << endl;
	*/
	
	//Scale s(C,MAJOR);
	//Key k(C,MAJOR);
	
	
	//cout << atoString() << endl << endl;
	
	/*
	// cout << "Plus " << Interval(PERFECT,1)toString() << endl;
	cout << (a+Interval(PERFECT,1))toString() << endl;
	
	// cout << "Plus " << Interval(MAJOR,2)toString() << endl;
	cout << (a+Interval(MAJOR,2))toString() << endl;
	
	// cout << "Plus " << Interval(MAJOR,3)toString() << endl;
	cout << (a+Interval(MAJOR,3))toString() << endl;
	
	// cout << "Plus " << Interval(PERFECT,4)toString() << endl;
	cout << (a+Interval(PERFECT,4))toString() << endl;
	
	// cout << "Plus " << Interval(PERFECT,5)toString() << endl;
	cout << (a+Interval(PERFECT,5))toString() << endl;
	
	// cout << "Plus " << Interval(MAJOR,6)toString() << endl;
	cout << (a+Interval(MAJOR,6))toString() << endl;
	
	// cout << "Plus " << Interval(MAJOR,7)toString() << endl;
	cout << (a+Interval(MAJOR,7))toString() << endl;
	
	// cout << "Plus " << Interval(PERFECT,8)toString() << endl;
	cout << (a+Interval(PERFECT,8))toString() << endl;
	*/

	/*
	// cout << "Minus " << Interval(PERFECT,1)toString() << endl;
	cout << (a-Interval(PERFECT,1))toString() << endl;
	
	// cout << "Minus " << Interval(MINOR,2)toString() << endl;
	cout << (a-Interval(MINOR,2))toString() << endl;
	
	// cout << "Minus " << Interval(MINOR,3)toString() << endl;
	cout << (a-Interval(MINOR,3))toString() << endl;
	
	// cout << "Minus " << Interval(PERFECT,4)toString() << endl;
	cout << (a-Interval(PERFECT,4))toString() << endl;
	
	// cout << "Minus " << Interval(PERFECT,5)toString() << endl;
	cout << (a-Interval(PERFECT,5))toString() << endl;
	
	// cout << "Minus " << Interval(MINOR,6)toString() << endl;
	cout << (a-Interval(MINOR,6))toString() << endl;
	
	// cout << "Minus " << Interval(MINOR,7)toString() << endl;
	cout << (a-Interval(MINOR,7))toString() << endl;
	
	// cout << "Minus " << Interval(PERFECT,8)toString() << endl;
	cout << (a-Interval(PERFECT,8))toString() << endl;
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
			std::cout << pitches[i]toString() << " to " << pitchtoString() << ":\t" << interval1toString() << "\tvs. " << interval2toString() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
	*/