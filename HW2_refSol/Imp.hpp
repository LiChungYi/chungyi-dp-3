#ifndef IMP_HPP
#define IMP_HPP

#include <utility>
#include <vector>
#include <string>
//#include <algorithm>
#include "ShapeType.hpp"

class Imp 
{
public:
	virtual int OpenModel(std::string) = 0;
	virtual int GetNumberOfElements(int) = 0;
	virtual double getXLoc(int, int) = 0;
	virtual double getYLoc(int, int) = 0;
	virtual double getLength(int, int) = 0;
	virtual double getDiameter(int, int) = 0;
	virtual double getOperation(int, int) = 0;
	virtual unsigned getNumSegments(int, int) = 0;
	virtual std::vector<ShapeType> getSegments(int, int) = 0;
	virtual std::vector< std::pair<ShapeType, int> > getList(int) = 0;
} ;
#endif
