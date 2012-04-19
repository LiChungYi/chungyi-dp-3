#ifndef CADDB_HPP
#define CADDB_HPP

#include <string>
#include <vector>
#include <map>
#include "ShapeType.hpp"

class CADDB {
private:
	CADDB();
	static CADDB* instance;
	std::map<std::string, int> mNameNum;
	std::map<int, int> mNumElements;
	std::map<int, std::vector<std::pair<ShapeType, int> > > models;
	std::map<int, ShapeType> shapetypes;

	// store all attribute of features
	std::map<int, std::vector<double> > doubleAttributes;
	std::map<int, unsigned> unsignedAttributes;
	std::map<int, std::vector<ShapeType> > shapetypeAttributes;

	// setup all member above
	void createLookUpTable();
public:
	static CADDB* getInstance();
	
	// Parameter
	//    mName: the name of model
	// Return Value
	//    the number of model, return 0 if mName not exists
	int getModelNum(std::string mName){
		return mNameNum[mName];
	}

	// Parameter
	//    mNum: the number of model
	// Return Value
	//    number of model's features, return 0 if mNum not exists
	int getNumElements(int mNum){
		return mNumElements[mNum];
	}

	// Parameter
	//    mNum: the number of model
	// Return Value
	//    the vector of model's features, return empty vector if modelNum not exists
	std::vector<std::pair<ShapeType, int> > getFeature(int modelNum){
		return models[modelNum];
	}

	// Parameter
	//    featureID: the ID of feature
	// Return Value
	//    the vector of double attribute of the feature, return empty vector if featureID not exists
	std::vector<double> getDoubleAttributes(int featureID){
		return doubleAttributes[featureID];
	}

	// Parameter
	//    featureID: the ID of feature
	// Return Value
	//    the unsigned attribute of the feature, return 0 if featureID not exists
	unsigned getUnsignedAttributes(int featureID){
		return unsignedAttributes[featureID];
	}

	// Parameter
	//    featureID: the ID of feature
	// Return Value
	//    the vector of ShapeType attribute of the feature, return empty vector if featureID not exists
	std::vector<ShapeType> getShapeTypeAttributes(int featureID){
		return shapetypeAttributes[featureID];
	}
};
#endif /* CADDB_HPP */
