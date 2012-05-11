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

double V1GetXforTriangle(int modelNum, int featureID){
	CADDB * _CADDB = CADDB::getInstance() ;
	double x1 = _CADDB->getDoubleAttributes(featureID).at(0) ;
	double x2 = _CADDB->getDoubleAttributes(featureID).at(2) ;
	double x3 = _CADDB->getDoubleAttributes(featureID).at(4) ;
	double centroid_x = (x1 + x2 + x3)/3 ;
	return centroid_x ;
}

double V1GetYforTriangle(int modelNum, int featureID){
	CADDB * _CADDB = CADDB::getInstance() ;
	double y1 = _CADDB->getDoubleAttributes(featureID).at(1) ;
	double y2 = _CADDB->getDoubleAttributes(featureID).at(3) ;
	double y3 = _CADDB->getDoubleAttributes(featureID).at(5) ;
	double centroid_y = (y1 + y2 + y3)/3 ;
	return centroid_y ;
}

std::vector<std::pair<double, double> > V1GetVertexesforTriangle(int modelNum, int featureID){
	CADDB * _CADDB = CADDB::getInstance() ;
	std::vector<std::pair<double, double> > vertex ;

	double x1 = _CADDB->getDoubleAttributes(featureID).at(0) ;
	double y1 = _CADDB->getDoubleAttributes(featureID).at(1) ;
	vertex.push_back(std::make_pair(x1, y1)) ;

	double x2 = _CADDB->getDoubleAttributes(featureID).at(2) ;
	double y2 = _CADDB->getDoubleAttributes(featureID).at(3) ;
	vertex.push_back(std::make_pair(x2, y2)) ;

	double x3 = _CADDB->getDoubleAttributes(featureID).at(4) ;
	double y3 = _CADDB->getDoubleAttributes(featureID).at(5) ;
	vertex.push_back(std::make_pair(x3, y3)) ;

	return vertex ;
}
