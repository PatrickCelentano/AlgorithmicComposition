#include "Form.hpp"

// Adds a Chord to this Progression, adjusting
// the restoringForce accordingly.
void Progression::add(Chord n)
{
	length += n.getLength();
	chords.push_back(n);
}

// Gets the i-th Chord.
Chord Progression::get(int i) const
{
	if(i < (int)chords.size() && i >= 0)
	{
		return Chord(chords[i]);
	}
	else
	{
		std::cerr << "Error: Progression: Out of bounds!" << std::endl;
		return Chord();
	}
}

// Gets the length of the Progression (in Counts).
Count Progression::getLength() const
{
	return length;
}

// Gets the LilyPond notation of this Progression.
std::string Progression::toLilyPond() const
{
	std::string toReturn;
	
	for(unsigned int j = 0; j < chords.size(); j++)
	{
		std::string tempLength;
		int beat            = chords[j].getLength().getBeat();
		int subdivision     = chords[j].getLength().getSubdivision();
		Sonority sonority   = chords[j].getSonority();
		
		toReturn += "<";
		
		for(unsigned int i = 0; i < sonority.size(); i++)
		{
			// The strings which represent this Chord.
			std::string pitch;
			int pClass       = sonority.get(i).getClass();
			int accidental   = sonority.get(i).getAccidental();
			int octave       = sonority.get(i).getOctave();
			
			// Gets the LilyPond notation of the pitch (or rest).
			if(pClass == REST)
			{
				pitch = "r";
			}
			else
			{
				switch(pClass)
				{
					case C:		pitch = "c";		break;
					case D:		pitch = "d";		break;
					case E:		pitch = "e";		break;
					case F:		pitch = "f";		break;
					case G:		pitch = "g";		break;
					case A:		pitch = "a";		break;
					case B:		pitch = "b";		break;
				}
				switch(accidental)
				{
					case DOUBLE_FLAT:	pitch += "eses";	break;
					case FLAT:			pitch += "es";		break;
					case NATURAL:		pitch += "";		break;
					case SHARP:			pitch += "is";		break;
					case DOUBLE_SHARP: 	pitch += "isis";	break;
				}
				/*
				for(int o = octave-3; o > 0; o--)
					pitch += "'";
				for(int o = octave-3; o < 0; o++)
					pitch += ",";
				*/
			}
			toReturn += pitch;
			toReturn += " ";
		}
		// Gets the LilyPond of the length of this Chord.
		// Undotted
		if(beat == 1)
		{
			if( subdivision == 1 ||		subdivision == 2 ||
				subdivision == 4 ||		subdivision == 8 ||
				subdivision == 16 ||	subdivision == 32 ||
				subdivision == 64 ||	subdivision == 128)
			{
				char buff[3];
				itoa(subdivision,buff,10);
				tempLength = (std::string)buff;
			}
		}
		// Dotted
		else if(beat == 3)
		{
			if( subdivision == 1 ||		subdivision == 2 ||
				subdivision == 4 ||		subdivision == 8 ||
				subdivision == 16 ||	subdivision == 32 ||
				subdivision == 64 ||	subdivision == 128)
			{
				char buff[3];
				itoa(subdivision/2,buff,10);
				tempLength = (std::string)buff + ".";
			}
		}
		// Double dotted
		else if(beat == 7)
		{
			if( subdivision == 1 ||		subdivision == 2 ||
				subdivision == 4 ||		subdivision == 8 ||
				subdivision == 16 ||	subdivision == 32 ||
				subdivision == 64 ||	subdivision == 128)
			{
				char buff[3];
				itoa(subdivision/4,buff,10);
				tempLength = (std::string)buff + "..";
			}
		}
		else if(beat == 4 && subdivision == 1)
			tempLength = "\\longa";
		else if(beat == 2 && subdivision == 1)
			tempLength = "\\breve";
		
		toReturn += ">";
		toReturn += tempLength;
		toReturn += " ";
	}
  return toReturn;
}















/*
void Progression::add(const Chord& Chord)
{
	length = Chord.getLength() + length;
	chords.push_back(Chord);
}
std::string Progression::getLilyPond() const
{
	std::string toReturn;
	for(unsigned int i = 0; i < chords.size(); i++)
	{
		toReturn += sonority.get(i).getLilyPond() + " ";
	}
	return toReturn;
}
*/
/*

std::string Count::getLilyPond() const
{
	
}
*/