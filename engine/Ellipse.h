#ifndef ENGINE_ELLIPSE_H_
#define ENGINE_ELLIPSE_H_

#include "view.h"

class Ellipse: public View {
public:
	Ellipse();
	bool checkFunction(int x,int y,int a,int b);
	void Ellipse::plot(Canvas *canvas);

	void setAValue(int m_a);
	void setBValue(int m_b);

	virtual ~Ellipse();
private:
	int a;
	int b;
};

#endif /* ENGINE_ELLIPSE_H_ */
