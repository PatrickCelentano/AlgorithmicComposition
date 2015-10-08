#ifndef __PITCH_HPP__
#define __PITCH_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Interval.hpp"

#define C 0
#define D 1
#define E 2
#define F 3
#define G 4
#define A 5
#define B 6

#define DOUBLE_FLAT (-2)
#define FLAT (-1)
#define NATURAL 0
#define SHARP 1
#define DOUBLE_SHARP 2

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