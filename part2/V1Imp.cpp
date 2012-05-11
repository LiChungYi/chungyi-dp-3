#include "V1Imp.hpp"
#include "V1System.hpp"
#include "xbug.hpp"

V1Imp::V1Imp()
{

}

int V1Imp::OpenModel(std::string modelName)
{
	return V1OpenModel(modelName) ;
}

int V1Imp::GetNumberOfElements(int modelNum)
{
	return V1GetNumberOfElements(modelNum) ;
}

double V1Imp::getXLoc(int modelNum, int elemNum)
{
	int featureID = V1GetID(modelNum, elemNum);
	switch(V1GetType(modelNum, elemNum))
	{
		case SLOT:
			return V1GetXforSlot(modelNum, featureID);	
			break;
		case HOLE:
			return V1GetXforHole(modelNum, featureID);	
			break;
		case CUTOUT:
			return V1GetXforCutout(modelNum, featureID);	
			break;
		case IRREGULAR:
			return V1GetXforIrregular(modelNum, featureID);
			break;
        	case SPECIAL:
			return V1GetXforSpecial(modelNum, featureID);
			break;
		case TRIANGLE:
			return V1GetXforTriangle(modelNum, featureID); 
			break;
		default:
			return 0;
	}	
}

double V1Imp::getYLoc(int modelNum, int elemNum)
{
	int featureID = V1GetID(modelNum, elemNum);
	switch(V1GetType(modelNum, elemNum))
	{
		case SLOT:
			return V1GetYforSlot(modelNum, featureID);	
			break;
		case HOLE:
			return V1GetYforHole(modelNum, featureID);	
			break;
		case CUTOUT:
			return V1GetYforCutout(modelNum, featureID);	
			break;
		case IRREGULAR:
	  		return V1GetYforIrregular(modelNum, featureID);
			break;
	        case SPECIAL:
        		return V1GetYforSpecial(modelNum, featureID);
			break;
		case TRIANGLE:
			return V1GetYforTriangle(modelNum, featureID);
			break;
		default:
			return 0;
	}
}

double V1Imp::getLength(int modelNum, int elemNum)
{
	if(V1GetType(modelNum, elemNum) == SLOT)
		return V1GetLengthforSlot(modelNum, V1GetID(modelNum, elemNum));
	else
	{
		throw xbug("Type Error");
	}
}

double V1Imp::getDiameter(int modelNum, int elemNum)
{
	if(V1GetType(modelNum, elemNum) == HOLE)
		return V1GetDiameterforHole(modelNum, V1GetID(modelNum, elemNum));
	else
	{
		throw xbug("Type Error");
	}
}

double V1Imp::getOperation(int modelNum, int elemNum)
{
	if(V1GetType(modelNum, elemNum) == CUTOUT)
		return V1GetOperationsforCutout(modelNum, V1GetID(modelNum, elemNum));
	else
	{
		throw xbug("Type Error");
	}
}

unsigned V1Imp::getNumSegments(int modelNum, int elemNum)
{
	if(V1GetType(modelNum, elemNum) == IRREGULAR)
		return V1GetNumSegmentsforIrregular(modelNum, V1GetID(modelNum, elemNum));
	else
	{
		throw xbug("Type Error");
	}
}

std::vector<ShapeType> V1Imp::getSegments(int modelNum, int elemNum)
{
	if(V1GetType(modelNum, elemNum) == IRREGULAR)
		return V1GetSegmentsforIrregular(modelNum, V1GetID(modelNum, elemNum));
	else
	{
		throw xbug("Type Error");
	}
}

std::vector<std::pair<ShapeType, int> > V1Imp::getList(int modelNum) 
{
	/** Return list of features of model */
	std::vector<std::pair<ShapeType, int> > list;	/* Use vector with pair<ShapeType, int> in it */
	int n = V1GetNumberOfElements(modelNum);  /* Get the number of features */
	for(int i=0; i<n; i++)
	{
		std::pair<ShapeType, int> listelem(V1GetType(modelNum, i), i);  /* Produce a pair */
		list.push_back(listelem);	/* Add it to vector list */
	}
	return list;
}

std::vector<std::pair<double, double> > V1Imp::getVertexes(int modelNum, int elemNum){
	if(V1GetType(modelNum, elemNum) == TRIANGLE)
		return V1GetVertexesforTriangle(modelNum, V1GetID(modelNum, elemNum));
	else
		throw xbug("Type Error");
}
