#include <iostream>
using namespace std;
/* Component (interface) */
class Widget { // 1. "lowest common denom"
public: virtual void draw() = 0;
};
/* ConcreteComponent, Core class*/
class TextField : public Widget {
private:
	int width, height;
public:
	TextField(int w, int h){ width = w; height = h; }
	void draw() { cout << "TextField: " << width << ", " << height << '\n'; }
};
/* Decorator (interface), 2nd level base class*/
class Decorator : public Widget {
private:
	Widget* wid; // reference to Widget, "has a" relationship
public:
	Decorator(Widget* w){ wid = w; }
	void draw() { wid->draw(); } // Delegation
	~Decorator() { delete wid; }

};
/* ConcreteDecorator */
class BorderDecorator : public Decorator {
public:
	BorderDecorator(Widget* w) : Decorator(w) { }
	void draw() { Decorator::draw(); cout << " BorderDecorator" << '\n'; }
};
/* ConcreteDecoderB */
class ScrollDecorator : public Decorator {
public:
	ScrollDecorator(Widget* w) : Decorator(w) { }

// 7. Delegate to base class and add extra stuff
	void draw() {
		Decorator::draw(); cout << " ScrollDecorator" << '\n';
	}
};
int main() { // 8. Client has the responsibility to compose desired configurations
	Widget* aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator(new TextField(80, 24))));
	aWidget->draw();
	return 0;
}
