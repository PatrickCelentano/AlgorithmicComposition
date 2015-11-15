#include "Harmony.hpp"

Pitch Scale::getDegree(int d) const
{
	Pitch pitch = ascending[(d+700-1)%7];
	return Pitch(pitch.getClass(),
				pitch.getAccidental(),
				pitch.getOctave()+(d-1)/7);
}
Pitch Scale::getDegree(int d, int p) const
{
	Pitch pitch;
	if(p <= d)
	{
		pitch = ascending[(d+700-1)%7];
	}
	else
	{
		pitch = descending[(d+700-1)%7];
	}
	return Pitch(pitch.getClass(),
				pitch.getAccidental(),
				pitch.getOctave()+(d-1)/7);
}
int Scale::getNumDegrees() const
{
	return ascending.size();
}
Scale::Scale()
{
	
}
Scale::Scale(Pitch root, int scaleType)
{
	root = Pitch(root.getClass(),root.getAccidental(),4);
	switch(scaleType)
	{
		case MAJOR:
			ascending.push_back(root);
			ascending.push_back(root + Interval(MAJOR,2));
			ascending.push_back(root + Interval(MAJOR,3));
			ascending.push_back(root + Interval(PERFECT,4));
			ascending.push_back(root + Interval(PERFECT,5));
			ascending.push_back(root + Interval(MAJOR,6));
			ascending.push_back(root + Interval(MAJOR,7));
			
			descending.push_back(root);
			descending.push_back(root + Interval(MAJOR,2));
			descending.push_back(root + Interval(MAJOR,3));
			descending.push_back(root + Interval(PERFECT,4));
			descending.push_back(root + Interval(PERFECT,5));
			descending.push_back(root + Interval(MAJOR,6));
			descending.push_back(root + Interval(MAJOR,7));
			break;
			
		case NATURAL_MINOR:
			ascending.push_back(root);
			ascending.push_back(root + Interval(MAJOR,2));
			ascending.push_back(root + Interval(MINOR,3));
			ascending.push_back(root + Interval(PERFECT,4));
			ascending.push_back(root + Interval(PERFECT,5));
			ascending.push_back(root + Interval(MINOR,6));
			ascending.push_back(root + Interval(MINOR,7));
			
			descending.push_back(root);
			descending.push_back(root + Interval(MAJOR,2));
			descending.push_back(root + Interval(MINOR,3));
			descending.push_back(root + Interval(PERFECT,4));
			descending.push_back(root + Interval(PERFECT,5));
			descending.push_back(root + Interval(MINOR,6));
			descending.push_back(root + Interval(MINOR,7));
			break;
			
		case HARMONIC_MINOR:
			ascending.push_back(root);
			ascending.push_back(root + Interval(MAJOR,2));
			ascending.push_back(root + Interval(MINOR,3));
			ascending.push_back(root + Interval(PERFECT,4));
			ascending.push_back(root + Interval(PERFECT,5));
			ascending.push_back(root + Interval(MINOR,6));
			ascending.push_back(root + Interval(MAJOR,7));
			
			descending.push_back(root);
			descending.push_back(root + Interval(MAJOR,2));
			descending.push_back(root + Interval(MINOR,3));
			descending.push_back(root + Interval(PERFECT,4));
			descending.push_back(root + Interval(PERFECT,5));
			descending.push_back(root + Interval(MINOR,6));
			descending.push_back(root + Interval(MAJOR,7));
			break;
		
		case MELODIC_MINOR:
			ascending.push_back(root);
			ascending.push_back(root + Interval(MAJOR,2));
			ascending.push_back(root + Interval(MINOR,3));
			ascending.push_back(root + Interval(PERFECT,4));
			ascending.push_back(root + Interval(PERFECT,5));
			ascending.push_back(root + Interval(MAJOR,6));
			ascending.push_back(root + Interval(MAJOR,7));
			
			descending.push_back(root);
			descending.push_back(root + Interval(MAJOR,2));
			descending.push_back(root + Interval(MINOR,3));
			descending.push_back(root + Interval(PERFECT,4));
			descending.push_back(root + Interval(PERFECT,5));
			descending.push_back(root + Interval(MINOR,6));
			descending.push_back(root + Interval(MINOR,7));
			break;
	}
	
}
std::string Scale::getString() const
{
	return "";
}

void Scale::checkRep() const
{
	
}