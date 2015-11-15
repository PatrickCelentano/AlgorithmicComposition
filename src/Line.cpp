#include "Line.hpp"
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


void Line::addNote(Note n)
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
Note Line::getNote(int i) const
{
	return Note(notes[i]);
}
int Line::getRestoringForce() const
{
	return restoringForce;
}
Count Line::getLength() const
{
	return length;
}













/*

std::string Count::getLilyPond() const
{
	// Undotted
	if(beat == 1)
	{
		if( subdivision == 1 ||
			subdivision == 2 ||
			subdivision == 4 ||
			subdivision == 8 ||
			subdivision == 16 ||
			subdivision == 32 ||
			subdivision == 64 ||
			subdivision == 128)
		{
			char buff[3];
			itoa(subdivision,buff,10);
			return (std::string)buff;
		}
	}
	// Dotted
	else if(beat == 3)
	{
		if( subdivision == 1 ||
			subdivision == 2 ||
			subdivision == 4 ||
			subdivision == 8 ||
			subdivision == 16 ||
			subdivision == 32 ||
			subdivision == 64 ||
			subdivision == 128)
		{
			char buff[3];
			itoa(subdivision/2,buff,10);
			return (std::string)buff + ".";
		}
	}
	// Double dotted
	else if(beat == 7)
	{
		if( subdivision == 1 ||
			subdivision == 2 ||
			subdivision == 4 ||
			subdivision == 8 ||
			subdivision == 16 ||
			subdivision == 32 ||
			subdivision == 64 ||
			subdivision == 128)
		{
			char buff[3];
			itoa(subdivision/4,buff,10);
			return (std::string)buff + ".";
		}
	}
	else if(beat == 4 && subdivision == 1)
	{
		return "\\longa";
	}
	else if(beat == 2 && subdivision == 1)
	{
		return "\\breve";
	}
	return "";
}
std::string Pitch::getLilyPond() const
{
	std::string toReturn;
	if(pClass == REST)
	{
		toReturn += "r";
	}
	else
	{
		switch(pClass)
		{
			case C:				toReturn += "c";	break;
			case D:				toReturn += "d";	break;
			case E:				toReturn += "e";	break;
			case F:				toReturn += "f";	break;
			case G:				toReturn += "g";	break;
			case A:				toReturn += "a";	break;
			case B:				toReturn += "b";	break;
		}
		switch(accidental)
		{
			case DOUBLE_FLAT:	toReturn += "ff";	break;
			case FLAT:			toReturn += "f";	break;
			case NATURAL:		toReturn += "";		break;
			case SHARP:			toReturn += "s";	break;
			case DOUBLE_SHARP: 	toReturn += "x";	break;
		}
		for(int i = octave-4; i >= 0; i--)
		{
			toReturn += ",";
		}
		for(int i = 0; i < octave-4; i++)
		{
			toReturn += "'";
		}
	}
  return toReturn;
}
*/