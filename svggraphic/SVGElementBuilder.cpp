#include "SVGElementBuilder.h"

void SVGElementBuilder::ClearObject(){
  currObject = NULL;
}

SVGElement* SVGElementBuilder::GetObject(){
  return currObject;
}

SVGElementBuilder::SVGElementBuilder(){
  SVGAttribute* temp;

  temp = new SVGx1();
  attributes.push_back(temp);

  temp = new SVGy1();
  attributes.push_back(temp);
}

void SVGElementBuilder::SetAttribute(const char* name, const char* value){
  string AttributeName(name);
  int i = attributes.size();
  SVGAttribute *setter = NULL;
  while (--i) {
    if (AttributeName == attributes[i]->name) {
      setter = attributes[i];
    }
  }
  attributes[i]->set(value, currObject)

}

SVGShapesBuilder::SVGElementBuilder(){
    SVGElementBuilder::SVGElementBuilder();
    SVGAttribute* temp;

    temp = new SVGFillColor();
    attributes.push_back(temp);

    temp = new SVGFillOpacity();
    attributes.push_back(temp);

    temp = new SVGStrokeColor();
    attributes.push_back(temp);

    temp = new SVGStrokeOpacity();
    attributes.push_back(temp);

    temp = new SVGStrokeWidth();
    attributes.push_back(temp);


}

EllipseBuilder::EllipseBuilder() {
  SVGShapesBuilder::SVGShapesBuilder();
  SVGAttribute* temp;

  temp = new SVGWidth();
  attributes.push_back(temp);

  temp = new SVGHeight();
  attributes.push_back(temp);
}

void EllipseBuilder::PrepareObject(){
  currObject = new SVGEllipse();
}

RectBuilder::RectBuilder(){
  SVGShapesBuilder::SVGShapesBuilder();
  SVGAttribute* temp;

  temp = new SVGWidth();
  attributes.push_back(temp);

  temp = new SVGHeight();
  attributes.push_back(temp);
}

void RectBuilder::PrepareObject(){
  currObject = new SVGRect();
}

CircleBuilder::CircleBuilder(){
  SVGShapesBuilder::SVGShapesBuilder();
  SVGAttribute* temp;

  temp = new SVGWidth();
  attributes.push_back(temp);

  temp = new SVGHeight();
  attributes.push_back(temp);
}

void CircleBuilder::PrepareObject(){
  currObject = new SVGCircle();
}

PolyLineBuilder::PolyLineBuilder(){
  SVGShapesBuilder::SVGShapesBuilder();
  SVGAttribute* temp;

  temp = new SVGPoints();
  attributes.push_back(temp);
}

PolyLineBuilder::PrepareObject(){
  currObject = new SVGPolyline();
}

PolygonBuilder::PolygonBuilder(){
  SVGShapesBuilder::SVGShapesBuilder();
  SVGAttribute* temp;

  temp = new SVGPoints();
  attributes.push_back(temp);
}

PolygonBuilder::PrepareObject(){
  currObject = new SVGPolygon();
}
