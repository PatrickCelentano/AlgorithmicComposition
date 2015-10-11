#include "Pitch.hpp"

int Pitch::getClass() const
{
	return (int)pClass;
}
int Pitch::getAccidental() const
{
	return (int)accidental;
}
int Pitch::getOctave() const
{
	return (int)octave;
}
std::string Pitch::getASCII() const
{
	std::string toReturn = "";
	
	switch(pClass)
	{
		case C:				toReturn += "C";	break;
		case D:				toReturn += "D";	break;
		case E:				toReturn += "E";	break;
		case F:				toReturn += "F";	break;
		case G:				toReturn += "G";	break;
		case A:				toReturn += "A";	break;
		case B:				toReturn += "B";	break;
	}
	switch(accidental)
	{
		case DOUBLE_FLAT:	toReturn += "bb";	break;
		case FLAT:			toReturn += "b";	break;
		case NATURAL:		toReturn += "";		break;
		case SHARP:			toReturn += "#";	break;
		case DOUBLE_SHARP: 	toReturn += "x";	break;
	}
  char buffer[2];
  itoa(octave,buffer,10);
  return toReturn + buffer;
}
/*
std::string Pitch::getLilyPond() const
{
	return "";
}
*/
void Pitch::repInvariant() const
{
	if(	pClass != C &&
		pClass != D &&
		pClass != E &
		pClass != F &&
		pClass != G &&
		pClass != A &&
		pClass != B )
	{
		std::cerr << "This note is invalid!" << std::endl;
	}
}


// Adds a given Interval to a Pitch, creating a new Pitch.
Pitch operator+(const Pitch &a, const Interval &b)
{
	
	// Plus six to avoid negative numbers coming from a modulus
	// Minus one because adding six would mess with octave logic 
	int newPClass		= (a.getClass()+b.getNumber()+6)%7;
	int newAccidental	= a.getAccidental();
	int newOctave		= (a.getClass()+b.getNumber()-1)/7 + a.getOctave() + b.getOctaves();
	
	switch(b.getNumber())
	{
		// The cases for unisons
		case 1:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			break;
			
		// The cases for seconds
		case 2:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == E || a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for thirds	
		case 3:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == D || a.getClass() == E || a.getClass() == A || a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for fourths
		case 4:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == F)
			{
				newAccidental--;
			}
			break;
			
		// The cases for fifths
		case 5:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for sixths
		case 6:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == E || a.getClass() == A || a.getClass() == B)
			{
				newAccidental++;
			}
			break;

		// The cases for sevenths
		case 7:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() != C && a.getClass() != F)
			{
				newAccidental++;
			}
	}
	return Pitch(newPClass,newAccidental,newOctave);
}


// Subtracts a given Interval from a Pitch, creating a new Pitch.
Pitch operator-(const Pitch &a, const Interval &b)
{
	// Plus six to avoid negative numbers coming from a modulus
	// Minus one because adding six would mess with octave logic 
	int newPClass		= (a.getClass()+8-b.getNumber())%7;
	int newAccidental	= a.getAccidental();
	int newOctave		= (a.getClass()-5-b.getNumber())/7 + a.getOctave() - b.getOctaves();
	
	switch(b.getNumber())
	{
		// The cases for unisons
		case 1:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			break;
			
		// The cases for seconds
		case 2:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == C || a.getClass() == F)
			{
				newAccidental--;
			}
			break;
			
		// The cases for thirds	
		case 3:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() != E && a.getClass() != A && a.getClass() != B)
			{
				newAccidental--;
			}
			break;
			
		// The cases for fourths
		case 4:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for fifths
		case 5:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == F)
			{
				newAccidental--;
			}
			break;
			
		// The cases for sixths
		case 6:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == C || a.getClass() == G || a.getClass() == E)
			{
				newAccidental--;
			}
			break;

		// The cases for sevenths
		case 7:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() != E && a.getClass() != B)
			{
				newAccidental--;
			}
	}
	return Pitch(newPClass,newAccidental,newOctave);
}