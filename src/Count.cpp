#include "Base.hpp"

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
void Count::checkRep() const
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
	checkRep();
}
Count::Count(int b): beat(b), subdivision(1)
{
	checkRep();
}
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
Count::Count(const Count& c)
{
	// A basic algorithm for getting
	// the greatest common divisor.
	int x = c.getSubdivision();
	int y = c.getBeat();
	int z;
	
	while(x != 0)
	{
		z = x;
		x = y%x;
		y = z;
	}
	
	// Divides the numbers by their gcd
	subdivision = c.getSubdivision()/y;
    beat = c.getBeat()/y;
	checkRep();
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
Count operator+=(const Count &a, const Count &b)
{
	return Count(	a.getBeat()*b.getSubdivision() +
					b.getBeat()*a.getSubdivision(),
					a.getSubdivision()*b.getSubdivision());
}
Count operator-=(const Count &a, const Count &b)
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