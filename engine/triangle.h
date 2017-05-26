#ifndef ENGINE_TRIANGLE_H_
#define ENGINE_TRIANGLE_H_

#include "polygon.h"

class Triangle: public Polygon {
public:
	Triangle();
	virtual ~Triangle();

	void set_points();
	int get_point(int i);

	int * points = new int[8]();
};

#endif /* ENGINE_TRIANGLE_H_ */
