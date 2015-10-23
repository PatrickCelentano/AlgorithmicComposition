#include "Line.hpp"

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