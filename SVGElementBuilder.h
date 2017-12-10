#ifndef __SVGELEMENTBUILDER__
#define __SVGELEMENTBUILDER__

#include <string>

class SVGAttribute {
public:
  SVGAttribute();
  char* getName() {
    return name.cstring();
  }
  void set (char* value, SVGElement* in) = 0 ;
protected:
  string name;
};


/*

The value read from the SVG by RapidXML is returned as a char array,
given in as a char*

Your task is to take that array, turn the number into int and set
it to the object

*/
class SVGx1 : public SVGAttribute {
public:
  SVGx1();
  void set (char* value, SVGElement* in);
  /*
  set the value to the _x elemnt of in
  */
}

class SVGy1 : public SVGAttribute {
public:
  SVGy1();
  void set (char* value, SVGElement* in);
  /*
  set the value to the _y element of in
  */
}

class SVGFillColor : public SVGAttribute {
public:
  SVGFillColor();
  void set (char* value, SVGElement* in);
  /*
  The input is of the form rgb(x,y,z)
  set in->fill_r = x; in->fill_g = y; fill_b = z;
  */
}

class SVGStrokeColor : public SVGAttribute {
public:
  SVGStrokeColor();
  void set (char* value, SVGElement* in);
  /*
  The input is of the form rgb(x,y,z)
  set in->fill_r = x; in->fill_g = y; in->fill_b = =z;
  */
}

class SVGStrokeWidth : public SVGAttribute {
public:
  SVGx1();
  void set (char* value, SVGElement* in);
  /*
    set in->stroke_width = value;
  */
}

class SVGFillOpacity : public SVGAttribute {
public:
  SVGFillOpacity();
  void set (char* value, SVGElement* in);
  /*
    set in->fill_a = (value * 256) + 1 (turn it to int)
  */
}

class SVGStrokeOpacity : public SVGAttribute {
public:
  SVGStrokeOpacity();
  void set (char* value, SVGElement* in);
  /*
    set in->stroke_a = (value * 256) + 1 (turn it to int)
  */
}

class SVGWidth : public SVGAttribute {
public:
  SVGWidth();
  void set (char* value, SVGElement* in);
  /*
  set in->_w = value;
  */
}

class SVGHeight : public SVGAttribute {
public:
  SVGHeight();
  void set (char* value, SVGElement* in);
  /*
  set in->_h = value;
  */
}
class SVGPoints : public SVGAttribute {
public:
  SVGPoints();
  void set(char* value, SVGElement* in);
  /*
  The input point list will be like this x1,y1 x2,y2 ...
  separate them and push into the vector so that it looks
  like this: {x1,y1,x2,y2,..}
  */
}

#endif
