#include "Base.hpp"

int Interval::getQuality() const
{
	return quality;
}
int Interval::getNumber() const
{
	return (number-1+700)%7+1;
}
int Interval::getOctaves() const
{
	return (number-1)/7;
}
std::string Interval::toString() const
{
	std::string toReturn = "";
	
	switch(quality)
	{
		case DIMINISHED:	toReturn += "d";	break;
		case MINOR:			toReturn += "m";	break;
		case PERFECT:		toReturn += "P";	break;
		case MAJOR:			toReturn += "M";	break;
		case AUGMENTED:		toReturn += "A";	break;
	}
	switch(getNumber()) // Can't let the mod be negative.
	{
		case 1:			toReturn += "U";	break;
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
		itoa((number/7),buffer,10);
		return toReturn + "&" + buffer + "o";
	}
	return toReturn;
}
Interval& Interval::operator=(const Interval &a)
{
	quality = a.getQuality();
	number = a.getNumber()+getOctaves()*7;
	return *this;
}
void Interval::checkRep() const
{
	if(	quality != DIMINISHED &&
		quality != MINOR &&
		quality != PERFECT &&
		quality != MAJOR &&
		quality != AUGMENTED )
	{
		std::cerr << "This interval is invalid! (Quality)" << std::endl;
	}
}
Interval operator+(const Interval &a, const Interval &b)
{
	return Interval(a.getQuality() + b.getQuality(), a.getNumber() + b.getNumber()-1);
}
Interval operator-(const Interval &a, const Interval &b)
{
	//assert((a.getNumber() + b.getNumber()) > 0);
	return Interval(a.getQuality() - b.getQuality(), a.getNumber() - b.getNumber()-1);
}
Interval operator-(const Pitch &a, const Pitch &b)
{
	// We can't get intervals between rests!
	if(a.isRest() || b.isRest())
	{
		std::cerr << "Can't get intervals between rests!" << std::endl;
		return Interval();
	}
	
	// Plus six to avoid negative numbers coming from a modulus
	// Minus one because adding six would mess with octave logic 
	int newNumber		= (a.getClass()-b.getClass())%7+1;
	int newOctaves		= (a.getClass()-b.getClass()-1)/7 + a.getOctave()-b.getOctave();
	int newQuality		= a.getAccidental()-b.getAccidental();
	
	// Negative intervals.
	if(newNumber <= 0)
	{
		newOctaves -= newNumber/7+2;
		newNumber = (newNumber-1+700)%7+1;
	}
	
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