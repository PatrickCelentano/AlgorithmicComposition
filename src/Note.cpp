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

// An asignment operator.
Note& Note::operator=(const Note &a)
{
	pitch = a.getPitch();
	length = a.getLength();
	checkRep();
	return *this;
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

// Adds a given interval to a Note
Note operator+(const Note &a, const Interval &b)
{
	return Note(a.getPitch()+b,a.getLength());
}

// Subtracts a given interval from a Note
Note operator-(const Note &a, const Interval &b)
{
	return Note(a.getPitch()-b,a.getLength());
}


// Adds a given interval to a Note
Note operator+=(const Note &a, const Interval &b)
{
	return Note(a.getPitch()+b,a.getLength());
}

// Subtracts a given interval from a Note
Note operator-=(const Note &a, const Interval &b)
{
	return Note(a.getPitch()-b,a.getLength());
}

// Augmentation
Note operator*(const Note &a, int scalar)
{
	return Note(a.getPitch(),a.getLength()*scalar);
}

// Diminution
Note operator/(const Note &a, int scalar)
{
	return Note(a.getPitch(),a.getLength()/scalar);
}

// A straightforward equality operator for Note
bool operator==(const Note &a, const Note &b)
{
	return	a.getPitch() == b.getPitch() &&
			a.getLength() == b.getLength();
}