#include "Base.hpp"

int Pitch::getClass() const
{
	return (int)pClass;
}
int Pitch::getAccidental() const
{
	return (int)accidental;
}
int Pitch::getOctave() const
{
	return (int)octave;
}
bool Pitch::isRest() const
{
	return pClass == REST;
}
std::string Pitch::toString() const
{
	std::string toReturn = "";
	if(pClass == REST)
	{
		toReturn += "R";
	}
	else
	{
		switch(pClass)
		{
			case C:				toReturn += "C";	break;
			case D:				toReturn += "D";	break;
			case E:				toReturn += "E";	break;
			case F:				toReturn += "F";	break;
			case G:				toReturn += "G";	break;
			case A:				toReturn += "A";	break;
			case B:				toReturn += "B";	break;
		}
		switch(accidental)
		{
			case DOUBLE_FLAT:	toReturn += "bb";	break;
			case FLAT:			toReturn += "b";	break;
			case NATURAL:		toReturn += "";		break;
			case SHARP:			toReturn += "#";	break;
			case DOUBLE_SHARP: 	toReturn += "x";	break;
		}
	}
	char buffer[2];
	itoa(octave,buffer,10);
	return toReturn + buffer;
}
Pitch& Pitch::operator=(const Pitch &p)
{
	pClass = p.getClass();
	accidental = p.getAccidental();
	octave = p.getOctave();
	checkRep();
	return *this;
}

// The default constructor creates a C4.
Pitch::Pitch(): pClass(C), accidental(NATURAL), octave(4)
{
	checkRep();
}

// The constructor by default creates a pitch in octave 4.
Pitch::Pitch(int p, int a): pClass(p), accidental(a), octave(4)
{
	checkRep();
}

// A constructor taking a pitch class and an octave.
Pitch::Pitch(int p, int a, int o): pClass(p),accidental(a),octave(o)
{
	checkRep();
}

// A copy constructor.
Pitch::Pitch(const Pitch& p): pClass(p.getClass()), accidental(p.getAccidental()), octave(p.getOctave())
{
	checkRep();
}

// Ensures that this class is valid.
void Pitch::checkRep() const
{
	if(	pClass != C &&
		pClass != D &&
		pClass != E &&
		pClass != F &&
		pClass != G &&
		pClass != A &&
		pClass != B &&
		pClass != REST)
	{
		std::cerr << "This pitch is invalid!" << std::endl;
	}
	if(	accidental != DOUBLE_FLAT &&
		accidental != FLAT &&
		accidental != NATURAL &&
		accidental != SHARP &&
		accidental != DOUBLE_SHARP)
	{
		std::cerr << "This pitch is invalid!" << std::endl;
	}
}

// Adds a given Interval to a Pitch, creating a new Pitch.
Pitch operator+(const Pitch &a, const Interval &b)
{
	// We don't need to transpose rests!
	if(a.isRest())
	{
		return a;
	}
	// Plus six to avoid negative numbers coming from a modulus
	// Minus one because adding six would mess with octave logic 
	int newPClass		= (a.getClass()+b.getNumber()+6)%7;
	int newAccidental	= a.getAccidental();
	int newOctave		= (a.getClass()+b.getNumber()-7)/7 + a.getOctave() + b.getOctaves();
	
	switch(b.getNumber())
	{
		// The cases for unisons
		case 1:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			break;
			
		// The cases for seconds
		case 2:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == E || a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for thirds	
		case 3:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == D || a.getClass() == E || a.getClass() == A || a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for fourths
		case 4:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == F)
			{
				newAccidental--;
			}
			break;
			
		// The cases for fifths
		case 5:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for sixths
		case 6:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() == E || a.getClass() == A || a.getClass() == B)
			{
				newAccidental++;
			}
			break;

		// The cases for sevenths
		case 7:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental -= 2;	break;
				case MINOR:			newAccidental -= 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental += 1;	break;
			}
			if(a.getClass() != C && a.getClass() != F)
			{
				newAccidental++;
			}
	}
	return Pitch(newPClass,newAccidental,newOctave);
}


// Subtracts a given Interval from a Pitch, creating a new Pitch.
Pitch operator-(const Pitch &a, const Interval &b)
{
	// We don't need to transpose rests!
	if(a.isRest())
	{
		return a;
	}
	// Plus six to avoid negative numbers coming from a modulus
	// Minus one because adding six would mess with octave logic 
	int newPClass		= (a.getClass()+8-b.getNumber())%7;
	int newAccidental	= a.getAccidental();
	int newOctave		= (a.getClass()-5-b.getNumber())/7 + a.getOctave() - b.getOctaves();
	
	switch(b.getNumber())
	{
		// The cases for unisons
		case 1:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			break;
			
		// The cases for seconds
		case 2:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == C || a.getClass() == F)
			{
				newAccidental--;
			}
			break;
			
		// The cases for thirds	
		case 3:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() != E && a.getClass() != A && a.getClass() != B)
			{
				newAccidental--;
			}
			break;
			
		// The cases for fourths
		case 4:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == B)
			{
				newAccidental++;
			}
			break;
			
		// The cases for fifths
		case 5:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 1;	break;
				case PERFECT:							break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == F)
			{
				newAccidental--;
			}
			break;
			
		// The cases for sixths
		case 6:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() == C || a.getClass() == G || a.getClass() == E)
			{
				newAccidental--;
			}
			break;

		// The cases for sevenths
		case 7:
			switch(b.getQuality())
			{
				case DIMINISHED:	newAccidental += 2;	break;
				case MINOR:			newAccidental += 1;	break;
				case MAJOR:								break;
				case AUGMENTED:		newAccidental -= 1;	break;
			}
			if(a.getClass() != E && a.getClass() != B)
			{
				newAccidental--;
			}
	}
	return Pitch(newPClass,newAccidental,newOctave);
}