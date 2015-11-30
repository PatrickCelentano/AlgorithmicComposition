#include "Harmony.hpp"

// Gets a Pitch from the Sonority
Pitch Sonority::get(int i) const
{
	return pitchesByDegree[i];
}

// Gets if this "Chord" is actually a rest
bool Sonority::isRest() const
{
	return pitchesByDegree.size() == 0;
}

// Gets the number of Pitches in this Sonority
unsigned int Sonority::size() const
{
	return pitchesByDegree.size();
}

// Gets the inversion (ROOT, FIRST_INVERSION, etc)
int Sonority::getInversion() const
{
	int inversion = 0;
	Pitch lowest = pitchesByHeight[0];
	for(unsigned int i = 0; i < pitchesByDegree.size(); i++)
	{
		if(pitchesByDegree[i] == lowest)
		{
			lowest = pitchesByDegree[i];
			inversion = i;
		}
	}
	return inversion;
}

// Gets the quality of this Sonority (MAJOR, MINOR, POWER, etc)
int Sonority::getType() const
{
	return type;
}

// Gets the difference between the highest and lowest Pitch.
Interval Sonority::getSpan() const
{
	return pitchesByHeight[pitchesByHeight.size()] - pitchesByHeight[0];
}

// Gets the ASCII representation of this Sonority
std::string Sonority::toString() const
{
	switch(type)
	{
		case MAJOR:			return root.toString()+"M";
		case MINOR:			return root.toString()+"m";
		case DIMINISHED:	return root.toString()+"o";
		case AUGMENTED:		return root.toString()+"+";
		case POWER:			return root.toString()+"(no 3)";
	}
	return "ERROR!";
}

// The default constructor
Sonority::Sonority(): type(MAJOR), root(Pitch()), pitchesByHeight(), pitchesByDegree()
{
	pitchesByHeight.push_back(root);
	pitchesByHeight.push_back(root+Interval(MAJOR,3));
	pitchesByHeight.push_back(root+Interval(PERFECT,5));
	
	pitchesByDegree.push_back(root);
	pitchesByDegree.push_back(root+Interval(MAJOR,3));
	pitchesByDegree.push_back(root+Interval(PERFECT,5));
}

// A constructor just taking a pitch, and type
Sonority::Sonority(const Pitch& p, int t): type(t), root(p), pitchesByHeight(), pitchesByDegree()
{
	switch(type)
	{
		case MAJOR:
			pitchesByHeight.push_back(root);
			pitchesByHeight.push_back(root+Interval(MAJOR,3));
			pitchesByHeight.push_back(root+Interval(PERFECT,5));
			
			pitchesByDegree.push_back(root);
			pitchesByDegree.push_back(root+Interval(MAJOR,3));
			pitchesByDegree.push_back(root+Interval(PERFECT,5));
			
			break;
			
		case MINOR:			
			pitchesByHeight.push_back(root);
			pitchesByHeight.push_back(root+Interval(MINOR,3));
			pitchesByHeight.push_back(root+Interval(PERFECT,5));
			
			pitchesByDegree.push_back(root);
			pitchesByDegree.push_back(root+Interval(MINOR,3));
			pitchesByDegree.push_back(root+Interval(PERFECT,5));
			break;
				
		case DIMINISHED:			
			pitchesByHeight.push_back(root);
			pitchesByHeight.push_back(root+Interval(MINOR,3));
			pitchesByHeight.push_back(root+Interval(DIMINISHED,5));
			
			pitchesByDegree.push_back(root);
			pitchesByDegree.push_back(root+Interval(MINOR,3));
			pitchesByDegree.push_back(root+Interval(DIMINISHED,5));
			break;
				
		case AUGMENTED:			
			pitchesByHeight.push_back(root);
			pitchesByHeight.push_back(root+Interval(MAJOR,3));
			pitchesByHeight.push_back(root+Interval(AUGMENTED,5));
			
			pitchesByDegree.push_back(root);
			pitchesByDegree.push_back(root+Interval(MAJOR,3));
			pitchesByDegree.push_back(root+Interval(AUGMENTED,5));
			break;
	}
	
}

// A constructor taking pitch, type, and inversion
Sonority::Sonority(const Pitch& p, int t, int i): type(t), root(p), pitchesByHeight(), pitchesByDegree()
{
	switch(type)
	{
		case MAJOR:
			switch(i)
			{
				case 0:
					pitchesByHeight.push_back(root);
					pitchesByHeight.push_back(root+Interval(MAJOR,3));
					pitchesByHeight.push_back(root+Interval(PERFECT,5));
					
					pitchesByDegree.push_back(root);
					pitchesByDegree.push_back(root+Interval(MAJOR,3));
					pitchesByDegree.push_back(root+Interval(PERFECT,5));
					
					break;
				
				case 1:
					pitchesByHeight.push_back(root+Interval(MINOR,3));
					pitchesByHeight.push_back(root+Interval(MINOR,6));
					pitchesByHeight.push_back(root);
					
					pitchesByDegree.push_back(root);
					pitchesByDegree.push_back(root+Interval(MAJOR,3));
					pitchesByDegree.push_back(root+Interval(PERFECT,5));
					
					break;
					
				case 2:
					pitchesByHeight.push_back(root+Interval(PERFECT,8));
					pitchesByHeight.push_back(root+Interval(PERFECT,4));
					pitchesByHeight.push_back(root+Interval(MAJOR,3));
					
					pitchesByDegree.push_back(root);
					pitchesByDegree.push_back(root+Interval(MAJOR,3));
					pitchesByDegree.push_back(root+Interval(PERFECT,5));
					
					break;
			}
			break;
			
		case MINOR:
			switch(i)
			{
				case 0:
					pitchesByHeight.push_back(root);
					pitchesByHeight.push_back(root+Interval(MINOR,3));
					pitchesByHeight.push_back(root+Interval(PERFECT,5));
					
					pitchesByDegree.push_back(root);
					pitchesByDegree.push_back(root+Interval(MINOR,3));
					pitchesByDegree.push_back(root+Interval(PERFECT,5));
					
					break;
				
				case 1:
					pitchesByHeight.push_back(root+Interval(MAJOR,3));
					pitchesByHeight.push_back(root+Interval(MAJOR,6));
					pitchesByHeight.push_back(root);
					
					pitchesByDegree.push_back(root);
					pitchesByDegree.push_back(root+Interval(MINOR,3));
					pitchesByDegree.push_back(root+Interval(PERFECT,5));
					
					break;
					
				case 2:
					pitchesByHeight.push_back(root+Interval(PERFECT,8));
					pitchesByHeight.push_back(root+Interval(PERFECT,4));
					pitchesByHeight.push_back(root+Interval(MINOR,3));
					
					pitchesByDegree.push_back(root);
					pitchesByDegree.push_back(root+Interval(MINOR,3));
					pitchesByDegree.push_back(root+Interval(PERFECT,5));
					
					break;
			}					
			break;
	}
}

// A constructor taking pitches directly.
Sonority::Sonority(std::vector<Pitch> p)
{
	
}

// Adds a given Interval to a Pitch, creating a new Pitch.
Sonority operator+(const Sonority &a, const Interval &b)
{
	for(unsigned int i = 0; i < a.pitchesByDegree.size(); i++)
	{
		//a.pitchesByDegree[i] += b;
		//a.pitchesByHeight[i] += b;
	}
	return a;
}
	
// Adds a given Interval to a Pitch, creating a new Pitch.
Sonority operator-(const Sonority &a, const Interval &b)
{
	for(unsigned int i = 0; i < a.pitchesByDegree.size(); i++)
	{
		//a.pitchesByDegree[i] -= b;
		//a.pitchesByHeight[i] -= b;
	}
	return a;
}

// Adds a given Interval to a Pitch, creating a new Pitch.
Sonority operator+=(const Sonority &a, const Interval &b)
{for(unsigned int i = 0; i < a.pitchesByDegree.size(); i++)
	{
		//a.pitchesByDegree[i] += b;
		//a.pitchesByHeight[i] += b;
	}
	return a;
}
	
// Adds a given Interval to a Pitch, creating a new Pitch.
Sonority operator-=(const Sonority &a, const Interval &b)
{
	for(unsigned int i = 0; i < a.pitchesByDegree.size(); i++)
	{
		//a.pitchesByDegree[i] -= b;
		//a.pitchesByHeight[i] -= b;
	}
	return a;
}