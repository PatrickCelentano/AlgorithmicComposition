#ifndef __PITCH_HPP__
#define __PITCH_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Interval.hpp"
#include "Defines.hpp"

// A class representing a single pitch
class Pitch
{
	public:
		int getClass() const;					// Gets the class of this Pitch
		int getAccidental() const;				// Gets the accidental of this Pitch
		int getOctave() const;					// Gets the octave of this Pitch
		std::string getASCII() const;			// Gets the ASCII representation of this note
		std::string getLilyPond() const;		// Gets the "LilyPond" format of this note
		
		void repInvariant() const;				// Ensures this class is valid
		
		Pitch(): pClass(C), octave(4)			// The default constructor creates a C4
			{ repInvariant(); }
		Pitch(int p, int a, int o):				// A constructor taking a pitch class and an octave
			accidental(a),pClass(p), octave(o)
			{ repInvariant(); }

	private:
		int8_t pClass;			// The class of this Pitch
		int8_t accidental;		// Is this pitch sharp/flat/etc
		int8_t octave;			// The octave of this Pitch
};

Pitch operator+(const Pitch &a, const Interval &b);
Pitch operator-(const Pitch &a, const Interval &b);

#endif