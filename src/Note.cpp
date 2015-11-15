#include "Base.hpp"

// A simple getter for pitch.
Pitch Note::getPitch() const
{
	return pitch;
}

// A simple getter for length.
Count Note::getLength() const
{
	return length;
}

// Is this Note a rest?
bool Note::isRest() const
{
	return pitch.isRest();
}

// Returns a basic string representing
// this Note (like, "C4 1/4")
std::string Note::toString() const
{
	return pitch.toString() + " " + length.toString();
}

// The default constructor.
Note::Note(): pitch(),length()
{
	checkRep();
}

// A constructor with arguments.
Note::Note(Pitch p, Count l):	pitch(p),length(l)
{
	checkRep();
}

// A copy constructor.
Note::Note(const Note& n): pitch(n.getPitch()), length(n.getLength())
{
	checkRep();
}

// There isn't anything we need
// to make sure this is a valid
// class... yet... (?)
void Note::checkRep() const
{
	
}