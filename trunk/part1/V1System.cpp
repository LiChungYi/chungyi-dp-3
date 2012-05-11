#include "V1System.hpp"
#include "CADDB.hpp"

int V1OpenModel(std::string modelName){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getModelNum(modelName);	
}
int V1GetNumberOfElements(int modelNum){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getNumElements(modelNum);
}
ShapeType V1GetType(int modelNum, int elemNum){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getFeature(modelNum).at(elemNum).first;
}
int V1GetID(int modelNum, int elemNum){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getFeature(modelNum).at(elemNum).second;
}


double V1GetXforSlot(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double V1GetYforSlot(int modelNum, int featureID){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
double V1GetLengthforSlot(int modelNum, int featureID){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(2);
}


double V1GetXforHole(int modelNum, int featureID){
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double V1GetYforHole(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
double V1GetDiameterforHole(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(2);
}


double V1GetXforCutout(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double V1GetYforCutout(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
double V1GetOperationsforCutout(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(2);
}


double V1GetXforIrregular(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double V1GetYforIrregular(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
unsigned V1GetNumSegmentsforIrregular(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getUnsignedAttributes(featureID);
}
std::vector<ShapeType> V1GetSegmentsforIrregular(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getShapeTypeAttributes(featureID);
}


double V1GetXforSpecial(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double V1GetYforSpecial(int modelNum, int featureID){	
	CADDB * _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
