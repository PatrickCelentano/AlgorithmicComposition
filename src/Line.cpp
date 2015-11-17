#include "Form.hpp"

// Adds a note to this Line, adjusting
// the restoringForce accordingly.
void Line::add(Note n)
{
	if(notes.size() > 0)
	{
		Interval fromLast = n.getPitch() - notes[notes.size()-1].getPitch();
			//std::cout << fromLast.getASCII() << std::endl;
		// Check if this is an upward or downward interval,
		// and apply a proportional force in the other direction.
			//std::cout << n.getPitch().getASCII() << " " << fromLast.getNumber() << std::endl;
		if(fromLast.getNumber()+fromLast.getOctaves()*7 < 0)
		{
			restoringForce -= fromLast.getNumber()+1+fromLast.getOctaves()*7;
			//std::cout << restoringForce << "\t" << fromLast.getNumber()+1+fromLast.getOctaves()*7 << std::endl;
		}
		else
		{
			restoringForce += fromLast.getNumber()-1+fromLast.getOctaves()*7;
			//std::cout << restoringForce << ":\t" << fromLast.getNumber()+1+fromLast.getOctaves()*7 << std::endl;
		}
	}
	notes.push_back(n);
}

// Gets the i-th note.
Note Line::get(int i) const
{
	if(i+1 < (int)notes.size() && i >= 0)
	{
		return Note(notes[i]);
	}
	else
	{
		std::cerr << "Out of bounds!" << std::endl;
		return Note();
	}
}

// Gets the tendency of this line to resolve.
int Line::getRestoringForce() const
{
	return restoringForce;
}

// Gets the length of the line (in Counts).
Count Line::getLength() const
{
	return length;
}

// Gets the LilyPond notation of this Line.
std::string Line::toLilyPond() const
{
	std::string toReturn;
	
	for(unsigned int i = 0; i < notes.size(); i++)
	{
		// The strings which represent this note.
		std::string pitch;
		std::string length;
		int pClass = notes[i].getPitch().getClass();
		int accidental = notes[i].getPitch().getAccidental();
		int octave = notes[i].getPitch().getOctave();
		int beat = notes[i].getLength().getBeat();
		int subdivision = notes[i].getLength().getSubdivision();
		
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
			for(int o = octave-3; o > 0; o--)
				pitch += "'";
			for(int o = octave-3; o < 0; o++)
				pitch += ",";
		}
		// Gets the LilyPond of the length of this note.
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
				length = (std::string)buff;
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
				length = (std::string)buff + ".";
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
				length = (std::string)buff + "..";
			}
		}
		else if(beat == 4 && subdivision == 1)
			length = "\\longa";
		else if(beat == 2 && subdivision == 1)
			length = "\\breve";
		
		toReturn += pitch;
		toReturn += length;
		toReturn += " ";
	}
  return toReturn;
}















/*
void Line::add(const Note& note)
{
	length = note.getLength() + length;
	notes.push_back(note);
}
std::string Line::getLilyPond() const
{
	std::string toReturn;
	for(unsigned int i = 0; i < notes.size(); i++)
	{
		toReturn += notes[i].getLilyPond() + " ";
	}
	return toReturn;
}
*/
/*

std::string Count::getLilyPond() const
{
	
}
*/