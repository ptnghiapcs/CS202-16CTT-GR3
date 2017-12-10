#ifndef __SVGXMLREADER__
#define __SVGXMLREADER__

#include "svggraphic/SVGElement.h"
#include "svggraphic/SVGElementBuilder.h"
#include "rapidxml/rapidxml.hpp"
#include <string>
#include <vector>
#include <fstream>

using namespace rapidxml;
using namespace std;

struct BuilderMap {
	string builderName;
	SVGElementBuilder* builder;
};

class SVGXMLReader {
private:
	xml_document<> doc;
	xml_node<> * node;
	vector<char> xml_copy;
	
	vector<BuilderMap> builders;
public:
	SVGXMLReader();
	~SVGXMLReader();

	bool AddBuilder(const char*, SVGElementBuilder*);
	bool OpenFile(const char*);
	SVGElement* ReadNextElement();
};

#endif