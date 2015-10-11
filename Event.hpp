#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "Count.hpp"
#include "Pitch.hpp"

struct Event
{
	Count length;
};
struct Note : Event
{
	Pitch pitch;
};
struct Rest : Event
{
	
};
struct EventFrame
{
	Event events[];
};
/*
EventFrame operator+(const EventFrame &a, const Count &b)
{
	return EventFrame
}
*/

#endif