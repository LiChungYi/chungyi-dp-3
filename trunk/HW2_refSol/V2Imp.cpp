#include "V2Imp.hpp"
#include "xbug.hpp"

int V2Imp::OpenModel(std::string modelName)
{
	oog = new OOGModel(modelName);
	return oog->getModelNum();
}
int V2Imp::GetNumberOfElements(int modelNum)
{
	return oog->getNumElements();
}
double V2Imp::getXLoc(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	return tmp->getX();
}
double V2Imp::getYLoc(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	return tmp->getY();
}
double V2Imp::getLength(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	if(tmp->myType() == SLOT)	/* make sure Type */
		return ((OOGSlot*)tmp)->getLength();
	else
	{
		throw xbug("Type Error");
	}
}
double V2Imp::getDiameter(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	if(tmp->myType() == HOLE)  /* make sure Type */
		return  ((OOGHole*)tmp)->getDiameter();
	else
	{
		throw xbug("Type Error");
	}
}
double V2Imp::getOperation(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	if(tmp->myType() == CUTOUT)  /* make sure Type */
		return  ((OOGCutout*)tmp)->getOperations();
	else
	{
		throw xbug("Type Error");
	}
}
unsigned V2Imp::getNumSegments(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	if(tmp->myType() == IRREGULAR)  /* make sure Type */
		return ((OOGIrregular*)tmp)->getNumSegments();
	else
	{
		throw xbug("Type Error");
	}
}
std::vector<ShapeType> V2Imp::getSegments(int modelNum, int elemNum)
{
	OOGFeature* tmp = oog->getElement(elemNum);
	if(tmp->myType() == IRREGULAR)  /* make sure Type */
		return ((OOGIrregular*)tmp)->getSegments();
	else
	{
		throw xbug("Type Error");
	}
}
std::vector<std::pair<ShapeType, int> > V2Imp::getList(int)
{
	/** Return list of features of model */
	int n = oog->getNumElements();
	std::vector<std::pair<ShapeType, int> > list;
	for(int i=0; i<n; i++)
	{
		OOGFeature* tmp = oog->getElement(i);
		std::pair<ShapeType, int> listelem(tmp->myType(), i);
		list.push_back(listelem);
	}
	return list;
}