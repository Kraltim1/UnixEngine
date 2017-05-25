#ifndef ENGINE_TEXT_H_
#define ENGINE_TEXT_H_

#include "view.h"

class Text: public View {
public:
	Text();
	virtual ~Text();

	// Functions
	string get_text();
	string draw(int canvas_x, int canvas_y);
};

#endif /* ENGINE_TEXT_H_ */
