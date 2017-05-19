#ifndef ENGINE_ELLIPSE_H_
#define ENGINE_ELLIPSE_H_

#include "view.h"

class Ellipse: public View {
public:
	Ellipse();
	bool checkFunction(int x,int y);
	void add_to(Canvas *canvas);

	virtual ~Ellipse();
};

#endif /* ENGINE_ELLIPSE_H_ */
