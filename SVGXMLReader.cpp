#include "SVGXMLReader.h"

SVGXMLReader::SVGXMLReader() : node(NULL) {}

void deleteBuilder(BuilderMap& map) {
	delete map.builder;
}

#include <algorithm> 	// for for_each
SVGXMLReader::~SVGXMLReader() {
	// delete all builders
	for_each(builders.begin(), builders.end(), deleteBuilder);
}


bool SVGXMLReader::AddBuilder(const char* name, SVGElementBuilder* b) {
	int i = builders.size();
	string builderName(name);
	while (--i >= 0) {
		if (builderName == builders[i].builderName)
			return false;
	}
	BuilderMap m = {builderName, b};
	builders.push_back(m);
    return true;
}

bool SVGXMLReader::OpenFile(const char* fileName) {
	string input_xml;
	string line;
	ifstream in(fileName);

	if (!in)
		return false;				// không mở được file

	// đọc toàn bộ nội dung file vào string input_xml
	while(getline(in,line))
		input_xml += line;

	in.close();

	// copy from input_xml to xml_copy
	//copy(input_xml.begin(), input_xml.end(), xml_copy.begin());
    xml_copy = vector<char> (input_xml.begin(), input_xml.end());

	xml_copy.push_back('\0');	// thêm kí tự kết thúc chuỗi

	// dùng doc để dọc trên xml_copy

	doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

	// lấy thẻ svg đầu tiên, gán vào node
	node = doc.first_node("svg");

	if (node == NULL)
		return false;

	// node->first_node() lấy thẻ (tag) con đầu tiên của svg

	node = node->first_node();

	if (node == NULL)
		return false;


	return true;
}

SVGElement* SVGXMLReader::ReadNextElement() {
	if (node == NULL)
		return NULL;

	// get node name
	string nodeName(node->name());

	// check if there is some builder that can work with this node

	int i = builders.size();
	SVGElementBuilder* builder = NULL;

	while (--i >= 0) {
		if (nodeName == builders[i].builderName) {
			// found a builder
			builder = builders[i].builder;
			break;
		}
	}

	if (builder == NULL) {
		// can't handle this node
		// skip
		node = node->next_sibling();
		// try next node (recursive)
		return ReadNextElement();
	}

	SVGElement* result = NULL;

	// create object
	builder->PrepareObject();

	// start reading attributes and set values
	for (xml_attribute<> *attr = node->first_attribute(); attr ; attr = attr->next_attribute())
	{
		builder->SetAttribute(attr->name(), attr->value());
	}

	// get object
	result = builder->GetObject();

	// now clear the object from the builder
	// the builder will now take no responsiblity for the object lifetime
	builder->ClearObject();

	// sau khi duyệt xong tag hiện tại, đi đến tag tiếp theo ngang cấp
	// bằng node->next_sibling()
	node = node->next_sibling();

	return result;
}
