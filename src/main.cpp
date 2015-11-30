#include "Base.hpp"
#include "Form.hpp"
#include "Harmony.hpp"
#include "Defines.hpp"
#include "Engraver.hpp"
#include "MarkovChain.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


MarkovChain<int>* initHarmonyMarkovChain();
vector<int>* generateProgression(MarkovChain<int>*, unsigned int);
vector<int>* generateMelody(vector<int>*);

int main(int argc, char* argv[])
{
	// All of our lovely variables.
	Line line;
	Progression progression;
	Key key(Pitch(C,NATURAL,4),		MAJOR);
	Scale scale(Pitch(C,NATURAL,4),	MAJOR);
	
	// Set the random seed.
	srand(time(NULL));
	
	// Initializes the "random" compositional elements.
	MarkovChain<int>* chain		= initHarmonyMarkovChain();
	vector<int>* harmony		= generateProgression(chain,1000);
	vector<int>* melody			= generateMelody(harmony);
	
	int lastNote = TONIC;
	// Take the generated harmony and melody and put them in the given key.
	for(unsigned int i = 0; i < melody->size()-1; i++)
	{
		if(i%2 ==0)
		{
			line.add(Note(scale.getDegree((*melody)[i],lastNote),	Count(3,16)));
		}
		else
		{
			line.add(Note(scale.getDegree((*melody)[i],lastNote),	Count(1,16)));
		}
			lastNote = (*melody)[i];
	}
	for(unsigned int i = 0; i < harmony->size()-1; i++)
	{
		if(i%2 ==0)
		{
			progression.add(Chord(key.getFunction((*harmony)[i]),	Count(1,4)));
		}
		else
		{
			progression.add(Chord(key.getFunction((*harmony)[i]),	Count(1,4)));
		}
	}
	
	// Use the Engraver class to write to a LilyPond file.
	Engraver::writeToLilyPond(line,progression);
	
	// It's only polite to free memory.
	delete chain;
	delete harmony;
	delete melody;
	
	return 0;
}

MarkovChain<int>* initHarmonyMarkovChain()
{
	MarkovChain<int>* harmony = new MarkovChain<int>(1);
	
	harmony->addOutcome(TONIC,1.0f,SUBDOMINANT);
	harmony->addOutcome(TONIC,1.0f,DOMINANT);
	harmony->addOutcome(TONIC,1.0f,LEADING_TONE);
	
	harmony->addOutcome(SUPERTONIC,1.0f,SUBMEDIANT);
	harmony->addOutcome(SUPERTONIC,1.0f,SUBDOMINANT);
	
	harmony->addOutcome(MEDIANT,1.0f,SUBMEDIANT);
	harmony->addOutcome(MEDIANT,1.0f,SUBDOMINANT);
	
	harmony->addOutcome(SUBDOMINANT,1.0f,DOMINANT);
	harmony->addOutcome(SUBDOMINANT,1.0f,TONIC);
	harmony->addOutcome(SUBDOMINANT,1.0f,SUPERTONIC);
	
	harmony->addOutcome(DOMINANT,1.0f,TONIC);
	harmony->addOutcome(DOMINANT,1.0f,SUBMEDIANT);
	
	harmony->addOutcome(SUBMEDIANT,1.0f,SUPERTONIC);
	harmony->addOutcome(SUBMEDIANT,1.0f,DOMINANT);
	harmony->addOutcome(SUBMEDIANT,1.0f,MEDIANT);
	harmony->addOutcome(SUBMEDIANT,1.0f,SUBDOMINANT);
	
	harmony->addOutcome(LEADING_TONE,1.0f,TONIC);
	harmony->addOutcome(LEADING_TONE,1.0f,MEDIANT);
	harmony->addOutcome(LEADING_TONE,1.0f,SUBMEDIANT);
	
	return harmony;
}

vector<int>* generateProgression(MarkovChain<int>* markovChain, unsigned int length)
{
	vector<int>* toReturn = new vector<int>();
	
	int currentFunction = TONIC;
	for(unsigned int i = 0; i < length; i++)
	{
		toReturn->push_back(currentFunction);
		currentFunction = markovChain->getOutcome(currentFunction,rand());
	}
	
	return toReturn;
}

vector<int>* generateMelody(vector<int>* harmony)
{	
	vector<int> pitches;
	vector<int>* toReturn = new vector<int>();
	
	int curPitch = TONIC;
	
	// Simply use the generated functional harmony to generate
	// actual chords and a very simple melody.
	for(unsigned int i = 0; i < harmony->size()-1; i++)
	{
		int curFunction = (*harmony)[i];
		int random = rand()%3;
		
		if(random == 0)
		{
			curPitch = curFunction;
		}
		else if(random == 1)
		{
			curPitch = curFunction+2;
		}
		else if(random == 2)
		{
			curPitch = curFunction+4;
		}
		
		if(pitches.size() > 0)
		{
			if(curPitch-pitches[pitches.size()-1] < -7)
			{
				curPitch += 7;
			}
			else if(curPitch-pitches[pitches.size()-1] > 7)
			{
				curPitch -= 7;
			}
		}
		
		pitches.push_back(curPitch);
	}
	for(unsigned int i = 0; i < pitches.size()-1; i++)
	{
		toReturn->push_back(pitches[i]);
		if(i < pitches.size()-1)
		{
			toReturn->push_back((pitches[i]+pitches[i+1])/2);
		}
	}
	
	return toReturn;
}












































/*
int distToRoot	= (curPitch-curFunction+7777)%7;
int distToThird	= (curPitch-curFunction+7777+2)%7;
int distToFifth	= (curPitch-curFunction+7777+5)%7;

if(distToRoot <= distToThird && distToRoot <= distToFifth)
	curPitch = curFunction;

if(distToThird <= distToRoot && distToThird <= distToFifth)
	curPitch = (curFunction+2)&7;

if(distToFifth <= distToRoot && distToFifth <= distToThird)
	curPitch = (curFunction+4)%7;

toReturn->push_back(curPitch);

cout << "Function: " << curFunction << " Pitch: " << curPitch << endl;

int newPitch;

curFunction = (*harmony)[i+1];
distToRoot	= (curPitch-curFunction+7777)%7;
distToThird	= (curPitch-curFunction+7777+2)%7;
distToFifth	= (curPitch-curFunction+7777+5)%7;

if(distToRoot <= distToThird && distToRoot <= distToFifth)
	newPitch = curFunction;

if(distToThird <= distToRoot && distToThird <= distToFifth)
	newPitch = (curFunction+2)&7;

if(distToFifth <= distToRoot && distToFifth <= distToThird)
	newPitch = (curFunction+4)%7;

toReturn->push_back((curPitch+newPitch)/2);

cout << "Function: " << curFunction << " Pitch: " << (curPitch+newPitch)/2 << endl;
*/









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