#ifndef __SVGELEMENT__
#define __SVGELEMENT__



class SVGElement {
  friend class SVGElementBuilder;
  friend class SVGAttribute;
public:
  virtual void draw(HDC hdc) = 0;
  SVGElement();
protected:
  int _x, _y;
};

class SVGShapes : public SVGElement {
public:
  SVGShapes();
protected:
  int fill_r, fill_g, fill_b, fill_a,
      stroke_r, stroke_g, stroke_b, stroke_a, stroke_width;
};

class SVGRect: public SVGShapes {
public:
  SVGRect();
  void draw(HDC hdc);
protected:
  int _w, _h ;
}

class SVGEllipse: public SVGShapes {
public:
  SVGEllipse();
  void draw(HDC hdc);
protected:
  int _w, _h ;
}

class SVGCircle: public SVGShapes {
public:
  SVGCircle();
  void draw(HDC hdc);
protected:
  int _w, _h ;
}

class SVGPolyline: public SVGShapes {
public:
  SVGPolyline();
  void draw(HDC hdc);
protected:
  vector<int> points;
}

class SVGPolygon: public SVGShapes {
public:
  SVGPolygon();
  void draw(HDC hdc);
protected:
  vector<int> points;
}





#endif
