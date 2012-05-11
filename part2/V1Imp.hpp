#ifndef V1IMP_HPP
#define V1IMP_HPP

#include "Imp.hpp"
#include "ShapeType.hpp"
#include "V1System.hpp"
//#include "V1Facade.h"
#include <vector>
#include <string>
#include <algorithm>

class V1Imp : public Imp
{
public:
	V1Imp();
	int OpenModel(std::string);
	int GetNumberOfElements(int);
	double getXLoc(int, int);
	double getYLoc(int, int);
	double getLength(int, int);
	double getDiameter(int, int);
	double getOperation(int, int);
	unsigned getNumSegments(int, int);
	std::vector<ShapeType> getSegments(int, int);
	std::vector<std::pair<ShapeType, int> > getList(int);
	std::vector<std::pair<double, double> > getVertexes(int, int);
private:
	//V1Facade *facade;
};
#endif
