#include "Harmony.hpp"

Pitch Key::getDegree(int d) const
{
	return scale.getDegree(d);
}

Sonority Key::getFunction(int d) const
{
	Sonority function;
	int chordType;
	//std::cout << d << ": " << getDegree(d).toString() << " ";
	//Hack-y way
	if(getDegree(d+2) - getDegree(d) == Interval(MAJOR,3) ||
			getDegree(d+4) - getDegree(d) == Interval(MAJOR,3,1))
	{
		//std::cout << "MAJOR" << std::endl;
		chordType = MAJOR;
	}
	else
	{
		// Need to ignore octaves
		if(getDegree(d+4) - getDegree(d) == Interval(PERFECT,5) ||
			getDegree(d+4) - getDegree(d) == Interval(PERFECT,5,1))
		{
			//std::cout << "MINOR" << std::endl;
			chordType = MINOR;
		}
		else
		{
			//std::cout << "DIMINISHED" << std::endl;
			chordType = DIMINISHED;
		}
	}
	function = Sonority(getDegree(d),chordType);
	return function;
}