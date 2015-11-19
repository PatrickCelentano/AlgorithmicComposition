#include "Harmony.hpp"

Pitch Key::getDegree(int d) const
{
	return scale.getDegree(d);
}

Sonority Key::getFunction(int d) const
{
	Sonority function;
	int chordType;
	//Hack-y way
	//if(getDegree(d+2) - getDegree(d) == Interval(MAJOR,3))
	if(getDegree(d+2) - getDegree(d) == Interval(MAJOR,3))
		chordType = MAJOR;
	else
		chordType = MINOR;
	function = Sonority(getDegree(d),chordType);
	return function;
}