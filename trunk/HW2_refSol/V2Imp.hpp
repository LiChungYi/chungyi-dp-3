#ifndef V2IMP_HPP
#define V2IMP_HPP

#include "Imp.hpp"
#include "ShapeType.hpp"
#include "V2System.hpp"
#include <vector>
#include <string>

class V2Imp : public Imp
{
	public:
		int OpenModel(std::string) ;
		int GetNumberOfElements(int) ;
		double getXLoc(int, int) ;
		double getYLoc(int, int) ;
		double getLength(int, int) ;
		double getDiameter(int, int) ;
		double getOperation(int, int) ;
		unsigned getNumSegments(int, int) ;
		std::vector<ShapeType> getSegments(int, int) ;
		std::vector<std::pair<ShapeType, int> > getList(int) ;
	private:
		OOGModel *oog;
};

#endif