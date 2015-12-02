#include "Base.hpp"
#include "Form.hpp"
#include "Rhythm.hpp"
#include "Harmony.hpp"
#include "Defines.hpp"
#include "Engraver.hpp"
#include "MarkovChain.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

MarkovChain<int>* initHarmonyMarkovChain();
Line* generateMelody(Scale, Rhythm*, Progression*);
Progression* generateProgression(Key, Rhythm*, MarkovChain<int>*);
Rhythm* generateRhythm(unsigned int, unsigned int,unsigned int, unsigned int);

/*
Rhythm* generateRhythm(unsigned int, unsigned int, unsigned int);
Rhythm* generateHarmonicRhythm(unsigned int, unsigned int, unsigned int);
*/

int main(int argc, char* argv[])
{
	// Piece-wide variables
	unsigned int upper = 3;
	unsigned int lower = 4;
	unsigned int measures = 40;
	Key key(Pitch(E,NATURAL,4),		MAJOR);
	Scale scale(Pitch(E,NATURAL,4),	MAJOR);
		
	// Set the random seed.
	srand(time(NULL));
	
	// Initializes the "random" compositional elements.
	MarkovChain<int>* chain			= initHarmonyMarkovChain();
	Rhythm* harmonicRhythm			= generateRhythm(upper,lower,measures,4);
	Rhythm* melodicRhythm			= generateRhythm(upper,lower,measures,4);
	Progression* progression		= generateProgression(key,harmonicRhythm,chain);
	Line* melody					= generateMelody(scale,melodicRhythm,progression);
	
	// Use the Engraver class to write to a LilyPond file.
	Engraver::writeToLilyPond(upper,lower,melody,progression);
	
	// It's only polite to free memory.
	delete chain;
	delete harmonicRhythm;
	delete melodicRhythm;
	delete progression;
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

Line* generateMelody(Scale scale, Rhythm* rhythm, Progression* progression)
{
	Line* line = new Line();	
	Count count;
	
	for(unsigned int i = 0; i < rhythm->size(); i++)
	{
		int options = progression->get(count).getSonority().size();
		line->add(Note(progression->get(count).getSonority().get(rand()%options),(*rhythm)[i]));
		count = count + (*rhythm)[i];
	}
	
	return line;
}

Progression* generateProgression(Key key, Rhythm* rhythm, MarkovChain<int>* markovChain)
{
	Progression* progression	= new Progression();
	vector<int>* functions		= new vector<int>();
	
	int currentFunction = TONIC;
	for(unsigned int i = 0; i < rhythm->size(); i++)
	{
		functions->push_back(currentFunction);
		progression->add(Chord(key.getFunction(currentFunction),(*rhythm)[i]));
		currentFunction = markovChain->getOutcome(currentFunction,rand());
	}
	return progression;
}

Rhythm* generateRhythm(unsigned int upper, unsigned int lower, unsigned int measures, unsigned int speed)
{
	Count basicBeat;
	unsigned int beatSubdivision;
	unsigned int beatsPerMeasure;
	Rhythm* toReturn = new Rhythm();
	
	switch(lower)
	{
		case 2:
			basicBeat = Count(1,2);
			beatSubdivision = 2;
			beatsPerMeasure = upper;
			break;
		case 4:
			basicBeat = Count(1,4);
			beatSubdivision = 2;
			beatsPerMeasure = upper;
			break;
		case 8:
			basicBeat = Count(3,8);
			beatSubdivision = 3;
			beatsPerMeasure = upper/3;
			break;
		default:
			cerr << "Error: Main: Unrecognized time siignature." << endl;
			break;
	}
	
	for(unsigned int i = 0; i < measures; i++)
	{
		unsigned int speed1 = rand()%speed;
		
		if(speed1 == 0)
		{
			(*toReturn) += basicBeat*beatsPerMeasure;
		}
		else
		{
			for(unsigned int j = 0; j < beatsPerMeasure; j++)
			{
				unsigned int speed2 = rand()%speed;
				if(speed2 > 1)
				{
					int subdivision = beatSubdivision*(pow(2,speed2-2));
					cout << subdivision << endl;
					for(unsigned int k = 0; k < subdivision; k++)
					{
						(*toReturn) += basicBeat/subdivision;
					}
				}
				else
				{
					(*toReturn) += basicBeat;
				}
			}
		}
	}
	
	return toReturn;
}












/*
vector<Count>* generateRhythm(unsigned int a, unsigned int b, unsigned int length)
{
	vector<Count>* toReturn = new vector<Count>();
	
	Count basicBeat;
	Count smallPartBeat;
	Count largePartBeat;
	
	if(b == 8)
	{
		basicBeat		= Count(3,8);
		smallPartBeat	= Count(1,8);
		largePartBeat	= Count(1,4);
		a /= 3;
	}
	else if(b == 4)
	{
		basicBeat		= Count(1,4);
		smallPartBeat	= Count(1,8);
		largePartBeat	= Count(3,8);
	}
	
	for(unsigned int i = 0; i < length; i++)
	{
		// Create all the notes somewhat evenly;
		for(unsigned int j = 0; j < a; j++)
		{
			// Adds single-beat fragments.
			unsigned int random = rand()%5;
			switch(random)
			{
				case 0:
						toReturn->push_back(smallPartBeat);
						toReturn->push_back(largePartBeat);
						break;
				case 1:
						toReturn->push_back(largePartBeat);
						toReturn->push_back(smallPartBeat);
						break;
				case 2:
				case 3:
				case 4:
						toReturn->push_back(basicBeat);
						break;
			}
		}
	}
	
	return toReturn;
}

vector<Count>* generateHarmonicRhythm(unsigned int a, unsigned int b, unsigned int length)
{
	vector<Count>* toReturn = new vector<Count>();
	
	Count basicBeat;
	Count smallPartBeat;
	Count largePartBeat;
	
	std::cout << a << b << endl;
	if(b == 8)
	{
		basicBeat		= Count(6,8);
		smallPartBeat	= Count(3,8);
		largePartBeat	= Count(3,8);
		a /= 3;
	}
	else if(b == 4)
	{
		basicBeat		= Count(4,4);
		smallPartBeat	= Count(1,2);
		largePartBeat	= Count(1,2);
	}
	
	for(unsigned int i = 0; i < length; i++)
	{
		for(unsigned int j = 0; j < a; j++)
		{
			// Adds single-beat fragments.
			unsigned int random = rand()%5;
			switch(random)
			{
				case 0:
						toReturn->push_back(smallPartBeat);
						toReturn->push_back(largePartBeat);
						break;
				case 4:
						toReturn->push_back(basicBeat);
						break;
			}
		}
	}
	
	return toReturn;
}
*/
/*
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
	*/