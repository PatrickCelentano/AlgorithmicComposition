#ifndef __NOTEFRAME_HPP__
#define __NOTEFRAME_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Interval.hpp"
#include "Pitch.hpp"
#include "Defines.hpp"

// A class representing a scale
class NoteFrame
{
	public:
		Pitch getDegree(int) const;				// Gets the given degree of a scale
		
		void repInvariant() const;				// Ensures this class is valid
		
		Scale(): pClass(C), octave(4)			// The default constructor creates a C4
			{ repInvariant(); }
		Scale(int p, int a, int o):				// A constructor taking a pitch class and an octave
			accidental(a),pClass(p), octave(o)
			{ repInvariant(); }

	private:
		Pitch pitches[];		// The pitches in the scale
};
#endif