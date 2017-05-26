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
	string draw(int canvas_x, int canvas_y);

protected:
	//properties
	int sides;

//	int points[8] = {x,y+height, x+width/2,y, x+width,y+height, x,y+height};
//	int points[8] = {5,0,0,10,10,10,5,0};
};

#endif /* ENGINE_POLYGON_H_ */
