#include "Base.hpp"

// A simple getter for the quality
// of the Interval (MAJOR, MINOR, etc.)
int Interval::getQuality() const
{
	return quality;
}

// A getter for the number of the interval
int Interval::getNumber() const
{
	return number%7+1;
}

// A getter for the number of octaves in the interval
int Interval::getOctaves() const
{
	return number/7;
}

// Gets if this interval is consonant
bool Interval::isConsonant() const
{
	switch(getNumber())
	{
		case 1:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case PERFECT:		return true;
				case AUGMENTED:		return false;
			}
		case 2:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case MINOR:			return false;
				case MAJOR:			return false;
				case AUGMENTED:		return false;
			}
		case 3:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case MINOR:			return true;
				case MAJOR:			return true;
				case AUGMENTED:		return false;
			}
		case 4:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case PERFECT:		return false;
				case AUGMENTED:		return false;
			}
		case 5:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case PERFECT:		return true;
				case AUGMENTED:		return false;
			}
		case 6:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case MINOR:			return true;
				case MAJOR:			return true;
				case AUGMENTED:		return false;
			}
		case 7:
			switch(getQuality())
			{
				case DIMINISHED:	return false;
				case MINOR:			return false;
				case MAJOR:			return false;
				case AUGMENTED:		return false;
			}
	}
	std::cerr << "Error: Interval: Impossible case!" << std::endl;
	return false;
}

// Returns a nicely-formatted string
// representing this Interval.
std::string Interval::toString() const
{
	std::string toReturn;
	
	switch(quality)
	{
		case DIMINISHED:	toReturn += "d";	break;
		case MINOR:			toReturn += "m";	break;
		case PERFECT:		toReturn += "P";	break;
		case MAJOR:			toReturn += "M";	break;
		case AUGMENTED:		toReturn += "A";	break;
	}
	switch(getNumber())
	{
		case 1:	
			if(getOctaves() == 0)
				toReturn += "U";
			else
				toReturn += "8";
											break;
		case 2:			toReturn += "2";	break;
		case 3:			toReturn += "3";	break;
		case 4:			toReturn += "4";	break;
		case 5: 		toReturn += "5";	break;
		case 6: 		toReturn += "6";	break;
		case 7: 		toReturn += "7";	break;
	}
	if(getOctaves() != 0)
	{
		char buffer[2];
		itoa(((number-1)/7),buffer,10);
		return toReturn + "&" + buffer + "o";
	}
	return toReturn;
}

// A straightforward assignment operator
Interval& Interval::operator=(const Interval &a)
{
	quality = a.getQuality();
	number = a.getNumber()+getOctaves()*7;
	return *this;
}

// Ensures that this instance is valid
void Interval::checkRep() const
{
	if(	quality != DIMINISHED &&
		quality != MINOR &&
		quality != PERFECT &&
		quality != MAJOR &&
		quality != AUGMENTED )
	{
		std::cerr << "Error: Interval: (Quality)" << std::endl;
	}
	if(number < 0)
	{
		std::cerr << "Error: Interval: Negative number!" << std::endl;
	}
}

// Interval addition
Interval operator+(const Interval &a, const Interval &b)
{
	return Interval(a.getQuality() + b.getQuality(), a.getNumber() + b.getNumber()-1);
}

// Interval subtraction
Interval operator-(const Interval &a, const Interval &b)
{
	//assert((a.getNumber() + b.getNumber()) > 0);
	return Interval(a.getQuality() - b.getQuality(), a.getNumber() - b.getNumber()-1);
}

// Pitch subtraction
Interval operator-(const Pitch &a, const Pitch &b)
{
	// We can't get intervals between rests!
	if(a.isRest() || b.isRest())
	{
		std::cerr << "Can't get intervals between rests!" << std::endl;
		return Interval();
	}
	// We always subtract the greater from the lesser!
	if(a < b)
	{
		return b - a;
	}
	
	// Plus six to avoid negative numbers coming from a modulus
	// Minus one because adding six would mess with octave logic 
	int newNumber		= (a.getClass()+7777-b.getClass())%7+1;
	int newOctaves		= (a.getClass()-b.getClass()-2)/7 + a.getOctave()-b.getOctave();
	int newQuality		= a.getAccidental()-b.getAccidental();
	
	switch(newNumber)
	{
		// The cases for unisons
		case 1:
			if(newQuality < 0)
			{
				newQuality -= 1;
			}
			else if(newQuality > 0)
			{
				newQuality += 1;
			}
			break;
			
		// The cases for seconds
		case 2:
			if(b.getClass() == E || b.getClass() == B)
				--newQuality;
			if(newQuality >= 0)
				++newQuality;
			break;
			
		// The cases for thirds	
		case 3:
			if(b.getClass() == D || b.getClass() == E ||
				b.getClass() == A || b.getClass() == B)
				--newQuality;
			if(newQuality >= 0)
				++newQuality;
			break;
			
		// The cases for fourths
		case 4:
			if(b.getClass() == F)
				++newQuality;
			if(newQuality < 0)
				--newQuality;
			else if(newQuality > 0)
				++newQuality;
			break;
			
		// The cases for fifths
		case 5:
			if(b.getClass() == B)
				--newQuality;
			if(newQuality < 0)
				--newQuality;
			else if(newQuality > 0)
				++newQuality;
			break;
			
		// The cases for sixths
		case 6:
			if(b.getClass() == E || b.getClass() == A ||
				b.getClass() == B)
				--newQuality;
			if(newQuality >= 0)
				++newQuality;
			break;

		// The cases for sevenths
		case 7:
			if(b.getClass() == D || b.getClass() == E ||
				b.getClass() == G || b.getClass() == A ||
				b.getClass() == B)
				--newQuality;
			if(newQuality >= 0)
				++newQuality;
			break;
	}
	return Interval(newQuality,newNumber,newOctaves);
}

// A straightforward equality operator for Interval (non-enharmonic)
bool operator==(const Interval &a, const Interval &b)
{
	return	a.getNumber() == b.getNumber() &&
			a.getOctaves() == b.getOctaves() &&
			a.getQuality() == b.getQuality();
}

// A straightforward greater-than operator for Interval (non-enharmonic)
bool operator>(const Interval &a, const Interval &b)
{
	return	(a.getOctaves() > b.getOctaves()) ||
			(a.getOctaves() == b.getOctaves() &&	a.getNumber() > b.getNumber()) ||
			(a.getNumber() == b.getNumber() &&		a.getQuality() > b.getQuality());
}

// A straightforward less-than operator for Interval (non-enharmonic)
bool operator<(const Interval &a, const Interval &b)
{
	return	(a.getOctaves() < b.getOctaves()) ||
			(a.getOctaves() == b.getOctaves() &&	a.getNumber() < b.getNumber()) ||
			(a.getNumber() == b.getNumber() &&		a.getQuality() < b.getQuality());
}

// A straightforward greater-than-or-equal-to operator for Interval (non-enharmonic)
bool operator>=(const Interval &a, const Interval &b)
{
	return	(a.getOctaves() >= b.getOctaves()) ||
			(a.getOctaves() == b.getOctaves() &&	a.getNumber() >= b.getNumber()) ||
			(a.getNumber() == b.getNumber() &&		a.getQuality() >= b.getQuality());
}

// A straightforward less-than-or-equal-to operator for Interval (non-enharmonic)
bool operator<=(const Interval &a, const Interval &b)
{
	return	(a.getOctaves() <= b.getOctaves()) ||
			(a.getOctaves() == b.getOctaves() &&	a.getNumber() <= b.getNumber()) ||
			(a.getNumber() == b.getNumber() &&		a.getQuality() <= b.getQuality());
}