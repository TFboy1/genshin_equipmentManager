#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include "Observer.h"

class Observer
{
	public:
	virtual void update() = 0;

	Observer() = default;
    ~Observer() = default;
};
#endif // SUBJECT_H
