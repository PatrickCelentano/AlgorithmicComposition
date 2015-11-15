#ifndef __LINE_HPP__
#define __RHYTHM_HPP__

#include <string>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <vector>
#include "Defines.hpp"
#include "Base.hpp"

// An MxM Rhythm is a collection of Counts which represent the
// lengths of notes and rests in succession. Using Rhythm[] gets
// these lengths. In addition, the starts of all events are stored.
class Rhythm
{
	public:
		const Count& getLength() const;
		
		void addCount(const Count&);
		
		Count& operator[](int index);
		const Count& operator[](int index) const;
		
	private:
		Count length;						// The total length of the rhythm
		std::vector<Count> starts;			// The starts of all Events
		std::vector<Count> lengths;			// The lenghths of all Events
};

// Represents a node on a RhythmTree. Nodes have a given length,
// and are subdivided via their children. These children may be
// evenly balanced, or "swung" in any number of ways.
struct RhythmNode
{
	int swing;			// How unevenly the Count is distributed
	int subdiv;			// How much this node gets divided
	int emphasis;		// +1 means the first subdivided note is emphasized, 
						// -1 means the last is, so on and so forth
	Count length;						// The length of this node
	RhythmNode* parent;					// The parent of this node
	std::vector<RhythmNode*> children;	// The children of this node
};

// A class used to create rhythms for scratch (given certain parameters)
class RhythmTree
{
	Rhythm getRhythm() const;	// Gets the created rhythm
	
	
	
	RhythmNode* source;
	
	private:
		void subdivideParent(RhythmNode);
		
		Count length;
		int swing[];		// Usually, swing decreases at lower levels
		int subdiv[];		// The number of subdivisions per level
};

#endif