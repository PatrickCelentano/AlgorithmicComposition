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
			std::cout << n.getPitch().getASCII() << " " << fromLast.getNumber() << std::endl;
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