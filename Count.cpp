#include "Count.hpp"

int Count::getBeat() const
{
	return beat;
}
int Count::getSubdivision() const
{
	return subdivision;
}
std::string Count::getASCII() const
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
void Count::repInvariant() const
{
	if(subdivision <= 0 || beat < 0)
	{
		std::cerr << "This count is invalid!" << std::endl;
	}
	
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
	{
		std::cerr << "This count is invalid!" << std::endl;
	}	
}
Count::Count(): beat(0), subdivision(1)
{
	repInvariant();
}
Count::Count(int b): beat(b), subdivision(1)
{
	repInvariant();
}
Count::Count(int b, int s): beat(b), subdivision(s)
{
	reduce();
	repInvariant();
}
void Count::reduce()
{
	// A basic algorithm for getting
	// the greatest common divisor.
	int a = subdivision;
	int b = beat;
	int c;
	
	while(a != 0)
	{
		c = a;
		a = b%a;
		b = c;
	}
		
	// Divides the numbers by their gcd
	subdivision /= b;
    beat /= b;
}
Count operator+(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() +
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}
Count operator-(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() -
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}
Count operator*(const Count &a, int scalar)
{
	return Count(	a.getBeat()*scalar, a.getSubdivision());
}
Count operator/(const Count &a, int scalar)
{
	return Count(	a.getBeat(), a.getSubdivision()*scalar);
}
bool operator==(const Count &a, const Count &b)
{
	return(	a.getBeat() == b.getBeat() &&
			a.getSubdivision() == b.getSubdivision() );
}
bool operator>(const Count &a, const Count &b)
{
	return( (float)a.getBeat()/a.getSubdivision() >
			(float)b.getBeat()/b.getSubdivision() );
}
bool operator<(const Count &a, const Count &b)
{
	return( (float)a.getBeat()/a.getSubdivision() <
			(float)b.getBeat()/b.getSubdivision() );
}
bool operator>=(const Count &a, const Count &b)
{
	return(	(float)a.getBeat()/a.getSubdivision() >=
			(float)b.getBeat()/b.getSubdivision() );
}
bool operator<=(const Count &a, const Count &b)
{
	return( (float)a.getBeat()/a.getSubdivision() <=
			(float)b.getBeat()/b.getSubdivision() );
}