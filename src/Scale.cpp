#include "Harmony.hpp"

Pitch Scale::getDegree(int d) const
{	
	Pitch pitch = ascending[(d+7777)%7];
	return Pitch(pitch.getClass(),
				pitch.getAccidental(),
				pitch.getOctave()+(d)/7);
}
Pitch Scale::getDegree(int d, int p) const
{
	Pitch pitch;
	if(p <= d)
	{
		pitch = ascending[(d+7777)%7];
	}
	else
	{
		pitch = descending[(d+7777)%7];
	}
	return Pitch(pitch.getClass(),
				pitch.getAccidental(),
				pitch.getOctave()+(d-1)/7);
}
int Scale::getNumDegrees() const
{
	return ascending.size();
}
std::string Scale::toString() const
{
	switch(scaleType)
	{
		case MAJOR:				return getDegree(0).toString() + " major";
		case NATURAL_MINOR:		return getDegree(0).toString() + " natural minor";
		case HARMONIC_MINOR:	return getDegree(0).toString() + " harmonic minor";
		case MELODIC_MINOR:		return getDegree(0).toString() + " melodic minor";
		case DOUBLE_HARMONIC:	return getDegree(0).toString() + " double harmonic";
	}
	return "ERROR";
}
Scale::Scale() : scaleType(MAJOR)
{
	Pitch root;
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
}
Scale::Scale(Pitch root, int st): scaleType(st)
{
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
			
		case DOUBLE_HARMONIC:
			ascending.push_back(root);
			ascending.push_back(root + Interval(MINOR,2));
			ascending.push_back(root + Interval(MAJOR,3));
			ascending.push_back(root + Interval(PERFECT,4));
			ascending.push_back(root + Interval(PERFECT,5));
			ascending.push_back(root + Interval(MINOR,6));
			ascending.push_back(root + Interval(MAJOR,7));
			
			descending.push_back(root);
			descending.push_back(root + Interval(MINOR,2));
			descending.push_back(root + Interval(MAJOR,3));
			descending.push_back(root + Interval(PERFECT,4));
			descending.push_back(root + Interval(PERFECT,5));
			descending.push_back(root + Interval(MINOR,6));
			descending.push_back(root + Interval(MAJOR,7));
			break;
	}
}

void Scale::checkRep() const
{
	
}