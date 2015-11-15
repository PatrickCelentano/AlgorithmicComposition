#include "Rhythm.hpp"
/*
const Count& Rhythm::getLength() const
{
	return length;
}
void Rhythm::addCount(const Count& count)
{
	starts.push_back(Count(length)); // Needs to copy
	lengths.push_back(Count(count)); // Needs to copy
	length += count;
}
Count& Rhythm::operator[](int index)
{
	return lengths[index];
}
const Count& Rhythm::operator[](int index) const
{
	return lengths[index];
}
void RhythmTree::subdivideParent(RhythmNode node)
{
	// To subdivide a parent, we must start by
	// taking the length of that node, and the
	// number of subdivisions, and distributing
	// the counts evenly. 
	Count roomLeft = node.length;
	
	// Gets the number of subdivisions and degree of
	// swing based on the length of the given node.
	int subdivisions	= subdivFunction(node.length);
	int emphasis		= emphasisFunction(node.length);
	int swing			= swingFunction(node.length);
	
	// Creates a bunch of children for this node,
	// based on the number of subdivisions and the
	// amount of swing for those subdivisions.
	for(int i = 0; i < subdivisions; i++)
	{
		RhythmNode* newChild = new RhythmNode();
		newChild.length = node.length/node.subdiv;
		
		
		
		node.children.add(newChild);
	}
*/