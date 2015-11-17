#ifndef __DEFINES_HPP__
#define __DEFINES_HPP__

// Pitch classes
// Note: these values are actually
// significant, as subtraction, etc.
// are used to speed up calculation.
#define C 0
#define D 1
#define E 2
#define F 3
#define G 4
#define A 5
#define B 6
#define REST 7

// Accidentals
// Note: these values are actually
// significant, as subtraction, etc.
// are used to speed up calculation.
#define DOUBLE_FLAT (-2)
#define FLAT (-1)
#define NATURAL 0
#define SHARP 1
#define DOUBLE_SHARP 2

// Qualities
// Note: these values are actually
// significant, as subtraction, etc.
// are used to speed up calculation.
#define DIMINISHED (-2)
#define MINOR (-1)
#define PERFECT 0
#define MAJOR 1
#define AUGMENTED 2

// Scale Degrees
// Note: these values are actually
// significant, as subtraction, etc.
// are used to speed up calculation.
#define TONIC 1
#define SUPERTONIC 2
#define MEDIANT 3
#define SUBDOMINANT 4
#define DOMINANT 5
#define SUBMEDIANT 6
#define LEADING_TONE 7

// Scale Types
// Note: these values are mostly
// arbitrary, though some have
// been cleverly chosen to over-
// lap with keywords like MAJOR
#define IONIAN 1
#define DORIAN 2
#define PHRYGIAN 3
#define LYDIAN 4
#define MIXOLYDIAN 5
#define AEOLIAN 6
#define NATURAL_MINOR 6
#define LOCRIAN 7
#define HARMONIC_MINOR 8
#define MELODIC_MINOR 9

// Defined classes
class Pitch;
class Interval;
class Scale;
class Count;
class Line;
struct Event;
struct Rest;
struct Note;

#endif