#include "V2System.hpp"
#include "CADDB.hpp"
#include "xbug.hpp"

OOGModel::OOGModel(std::string _model_name){
	CADDB* _CADDB = CADDB::getInstance();
	
	model_no = _CADDB->getModelNum(_model_name);
	if( model_no == 0){
		throw xbug("OOGModel: "+_model_name+": Model not exists.");
	}
	num_elements = _CADDB->getNumElements(model_no);

	// create object for each feature
	std::vector< std::pair<ShapeType, int> > f = _CADDB->getFeature(model_no);
	for(int i=0;i<num_elements;++i){
		
		int feature_id = f.at(i).second;
		switch(f.at(i).first){
			case SLOT:
				features.push_back(new OOGSlot(model_no, feature_id));
				break;
			case HOLE:
				features.push_back(new OOGHole(model_no, feature_id));
				break;
			case CUTOUT:
				features.push_back(new OOGCutout(model_no, feature_id));
				break;
			case IRREGULAR:
				features.push_back(new OOGIrregular(model_no, feature_id));
				break;
			case SPECIAL:
				features.push_back(new OOGSpecial(model_no, feature_id));
				break;
		}
	}
}


double OOGSlot::getX(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double OOGSlot::getY(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
double OOGSlot::getLength(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(2);
}


double OOGHole::getX(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double OOGHole::getY(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
double OOGHole::getDiameter(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(2);
}


double OOGCutout::getX(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double OOGCutout::getY(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
double OOGCutout::getOperations(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(2);
}


double OOGIrregular::getX(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double OOGIrregular::getY(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
unsigned OOGIrregular::getNumSegments(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getUnsignedAttributes(featureID);
}
std::vector<ShapeType> OOGIrregular::getSegments(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getShapeTypeAttributes(featureID);
}


double OOGSpecial::getX(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(0);
}
double OOGSpecial::getY(){
	CADDB* _CADDB = CADDB::getInstance();
	return _CADDB->getDoubleAttributes(featureID).at(1);
}
