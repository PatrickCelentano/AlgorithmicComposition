#include "Scale.hpp"
/*
int Interval::getQuality() const
{
	return quality;
}
int Interval::getNumber() const
{
	return (number-1)%7+1;
}
int Interval::getOctaves() const
{
	return (number-1)/7;
}
std::string Interval::getASCII() const
{
	std::string toReturn = "";
	
	
	switch((number - 1)%8 + 1)
	{
		case 1:			toReturn += "1";	break;
		case 2:			toReturn += "2";	break;
		case 3:			toReturn += "3";	break;
		case 4:			toReturn += "4";	break;
		case 5: 		toReturn += "5";	break;
		case 6: 		toReturn += "6";	break;
		case 7: 		toReturn += "7";	break;
		case 8:			toReturn += "8";	break;
	}
	switch(quality)
	{
		case DIMINISHED:	toReturn += "d";	break;
		case MINOR:			toReturn += "m";	break;
		case PERFECT:		toReturn += "P";	break;
		case MAJOR:			toReturn += "M";	break;
		case AUGMENTED:		toReturn += "A";	break;
	}
	if(number > 8)
	{

		char buffer[2];
		itoa((number/7),buffer,10);
		return toReturn + buffer + "o";
	}
	return toReturn;
}



Scale(int p, int a, int o):				// A constructor taking a pitch class and an octave
			accidental(a),pClass(p), octave(o)
			{ repInvariant(); }
*/