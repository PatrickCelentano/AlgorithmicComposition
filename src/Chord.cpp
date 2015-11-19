#include "Harmony.hpp"

// A simple getter for Sonority.
Sonority Chord::getSonority() const
{
	return sonority;
}

// A simple getter for length.
Count Chord::getLength() const
{
	return length;
}

// Is this Chord a rest?
bool Chord::isRest() const
{
	return sonority.isRest();
}

// Returns a basic string representing
// this Chord (like, "C4M 1/4")
std::string Chord::toString() const
{
	return sonority.toString() + " " + length.toString();
}

// An asignment operator.
Chord& Chord::operator=(const Chord &a)
{
	sonority = a.getSonority();
	length = a.getLength();
	checkRep();
	return *this;
}

// There isn't anything we need
// to make sure this is a valid
// class... yet... (?)
void Chord::checkRep() const
{
	
}

// Adds a given interval to a Chord
Chord operator+(const Chord &a, const Interval &b)
{
	return Chord(a.getSonority()+b,a.getLength());
}

// Subtracts a given interval from a Chord
Chord operator-(const Chord &a, const Interval &b)
{
	return Chord(a.getSonority()-b,a.getLength());
}


/*
// Adds a given interval to a Chord
Chord operator+=(const Chord &a, const Interval &b)
{
	return Chord(a.getSonority()+b,a.getLength());
}

// Subtracts a given interval from a Chord
Chord operator-=(const Chord &a, const Interval &b)
{
	return Chord(a.getSonority()-b,a.getLength());
}

// Augmentation
Chord operator*(const Chord &a, int scalar)
{
	return Chord(a.getSonority(),a.getLength()*scalar);
}

// Diminution
Chord operator/(const Chord &a, int scalar)
{
	return Chord(a.getSonority(),a.getLength()/scalar);
}

// A straightforward equality operator for Chord
bool operator==(const Chord &a, const Chord &b)
{
	return	a.getSonority() == b.getSonority() &&
			a.getLength() == b.getLength();
}
*/