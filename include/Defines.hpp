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

// Chord types
// Note: these values are actually
// significant, as subtraction, etc.
// are used to speed up calculation.
#define DRONE 4
#define POWER 5

// Scale Degrees
// Note: these values are actually
// significant, as subtraction, etc.
// are used to speed up calculation.
#define TONIC 0
#define SUPERTONIC 1
#define MEDIANT 2
#define SUBDOMINANT 3
#define DOMINANT 4
#define SUBMEDIANT 5
#define LEADING_TONE 6

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
#define DOUBLE_HARMONIC 10

// Scale Degrees
// Note: these values are actually
// significant, and represent octaves
// that have some significance
#define LOWEST_OCTAVE -1
#define DEFAULT_OCTAVE 4
#define HIGHEST_OCTAVE 9


// Inversions
// Note: these values are actually
// significant, and represent octaves
// that have some significance
#define ROOT_POSITION 0
#define FIRST_INVERSION 1
#define SECOND_INVERSION 2
#define THIRD_INVERSION 3

// Base classes
class Interval;
class Pitch;
class Count;
class Note;

// Harmony classes
class Interval;
class Pitch;
class Count;
class Note;

// Base classes
class Sonority;
class Chord;
class Function;
class Scale;
class Key;

#endif