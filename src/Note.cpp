#include "Note.hpp"

Pitch Note::getPitch() const
{
	return pitch;
}
Count Note::getLength() const
{
	return length;
}
bool Note::isRest() const
{
	return pitch.isRest();
}
std::string Note::getASCII() const
{
	return pitch.getASCII() + length.getASCII();
}
std::string Note::getLilyPond() const
{
	return pitch.getLilyPond() + length.getLilyPond();
}
void Note::checkRep() const
{
	
}