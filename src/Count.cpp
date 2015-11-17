#include "Base.hpp"

// A basic getter for beat
int Count::getBeat() const
{
	return beat;
}

// A basic getter for subdivision
int Count::getSubdivision() const
{
	return subdivision;
}

// Returns a string representation of
// this Count that looks like: "1/4"
std::string Count::toString() const
{
	std::string toReturn = "";
	
	char buff1[3];
	char buff2[3];
	itoa(beat,buff1,10);
	itoa(subdivision,buff2,10);
	
	toReturn += buff1;
	toReturn += "/";
	toReturn += buff2;
	
	return toReturn;
}

// An asignment operator.
Count& Count::operator=(const Count &a)
{
	beat = a.getBeat();
	subdivision = a.getSubdivision();
	checkRep();
	return *this;
}

// The default constructor for Count
Count::Count(): beat(0), subdivision(1)
{
	checkRep();
}

// A constructor that takes in both beats
// and a subdivision (ie: 1 and 4)
Count::Count(int b, int s)
{
	// A basic algorithm for getting
	// the greatest common divisor.
	int x = s;
	int y = b;
	int z;
	
	while(x != 0)
	{
		z = x;
		x = y%x;
		y = z;
	}
	
	// Divides the numbers by their gcd
	subdivision = s/y;
    beat = b/y;
}

// A copy constructor for Count
Count::Count(const Count& c): beat(c.getBeat()), subdivision(c.getSubdivision())
{
	checkRep();
}

// Ensures that this class is valid
void Count::checkRep() const
{
	if(subdivision <= 0 || beat < 0)
		std::cerr << "This count is invalid!" << std::endl;
	
	int a = subdivision;
	int b = beat;
	int c;
	
	// A basic algorithm for getting
	// the greatest common divisor.
	while(a != 0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	
	if(b != 1)
		std::cerr << "This count is invalid!" << std::endl;
}

// Adds two Counts together, creating a new Count
Count operator+(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() +
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}

// Subtracts two Counts, creating a new Count
Count operator-(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() -
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}

// Adds two Counts together, creating a new Count
Count operator+=(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() +
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}

// Subtracts two Counts, creating a new Count
Count operator-=(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() -
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}

// Augmentation
Count operator*(const Count &a, int scalar)
{
	return Count(	a.getBeat()*scalar, a.getSubdivision());
}

// Diminution
Count operator/(const Count &a, int scalar)
{
	return Count(	a.getBeat(), a.getSubdivision()*scalar);
}

// A straightforward equality operator for Count
bool operator==(const Count &a, const Count &b)
{
	return(	a.getBeat() == b.getBeat() &&
			a.getSubdivision() == b.getSubdivision() );
}

// A straightforward greater-than operator for Count
bool operator>(const Count &a, const Count &b)
{
	return( (float)a.getBeat()/a.getSubdivision() >
			(float)b.getBeat()/b.getSubdivision() );
}

// A straightforward les-than operator for Count
bool operator<(const Count &a, const Count &b)
{
	return( (float)a.getBeat()/a.getSubdivision() <
			(float)b.getBeat()/b.getSubdivision() );
}

// A straightforward greater-than-or-equal operator for Count
bool operator>=(const Count &a, const Count &b)
{
	return(	(float)a.getBeat()/a.getSubdivision() >
			(float)b.getBeat()/b.getSubdivision() ) ||
			a == b;
}

// A straightforward less-than-or-equal operator for Count
bool operator<=(const Count &a, const Count &b)
{
	return( (float)a.getBeat()/a.getSubdivision() <=
			(float)b.getBeat()/b.getSubdivision() ) ||
			a == b;
}