#include "Rhythm.hpp"

unsigned int Rhythm::size() const
{
	return lengths.size();
}

Count Rhythm::length() const
{
	return totalLength;
}

Count Rhythm::operator[](unsigned int i) const
{
	return lengths[i];
}

Rhythm Rhythm::operator+(const Count &c)
{
	// Create a new rhythm that's copied from this one
	Rhythm newRhythm;
	newRhythm.totalLength	= this->totalLength;
	newRhythm.lengths		= this->lengths;
	
	// Add the new count
	newRhythm	+= c;
	totalLength	+= c;
	
	return newRhythm;
}

Rhythm& Rhythm::operator+=(const Count &c)
{
	// Add the new count
	lengths.push_back(c);
	totalLength += c;
	
	return *this;
}

Rhythm Rhythm::operator+(const Rhythm &r)
{
	// Create a new rhythm that's copied from this one
	Rhythm newRhythm;
	newRhythm.totalLength	= this->totalLength;
	newRhythm.lengths		= this->lengths;
	
	// Go through the other rhythm, and add it to the new one
	for(unsigned int i = 0; i < r.size(); i++)
	{
		newRhythm	+= r[i];
		totalLength	+= r[i];
	}
	
	return newRhythm;
}

Rhythm& Rhythm::operator+=(const Rhythm &r)
{
	// Go through the other rhythm, and add it to this
	for(unsigned int i = 0; i < size(); i++)
	{
		*this += r[i];
	}
	
	return *this;
}