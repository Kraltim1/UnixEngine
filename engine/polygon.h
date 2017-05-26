#ifndef ENGINE_POLYGON_H_
#define ENGINE_POLYGON_H_

#include "view.h"

class Polygon: public View {
public:
	Polygon();
	virtual ~Polygon();

	virtual void set_points()=0;
	virtual int get_point(int i)=0;
	bool isInside(int n, int canvas_x, int canvas_y);
	bool isOutside(int n, int canvas_x, int canvas_y);
	string draw(int canvas_x, int canvas_y);

protected:
	//properties
	int sides;
	bool points_not_set;
};

#endif /* ENGINE_POLYGON_H_ */
