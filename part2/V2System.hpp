#ifndef V2SYSTEM_HPP
#define V2SYSTEM_HPP

#include "ShapeType.hpp"
#include <vector>
#include <string>

/** 
 * @defgroup V2Group V2 System group.
 * @{
 */

/**
 *@brief V2 type feature.
 * ABC of features use OO method.
 */
class OOGFeature{
protected:
	int modelNum;
	int featureID;
public:
	virtual ShapeType myType() = 0;
	virtual double getX() = 0;
	virtual double getY() = 0;
};

class OOGSlot: public OOGFeature{
public:
	OOGSlot(int modelnum, int featureid){
		modelNum = modelnum;
		featureID = featureid;
	}
	ShapeType myType(){
		return SLOT;
	}
	double getX();
	double getY();
	double getLength();
};

class OOGHole: public OOGFeature{
public:
	OOGHole(int modelnum, int featureid){
		modelNum = modelnum;
		featureID = featureid;
	}
	ShapeType myType(){
		return HOLE;
	}
	double getX();
	double getY();
	double getDiameter();
};

class OOGCutout: public OOGFeature{
public:
	OOGCutout(int modelnum, int featureid){
		modelNum = modelnum;
		featureID = featureid;
	}
	ShapeType myType(){
		return CUTOUT;
	}
	double getX();
	double getY();
	double getOperations();
};

class OOGIrregular: public OOGFeature{
public:
	OOGIrregular(int modelnum, int featureid){
		modelNum = modelnum;
		featureID = featureid;
	}
	ShapeType myType(){
		return IRREGULAR;
	}
	double getX();
	double getY();
	unsigned getNumSegments();
	std::vector<ShapeType> getSegments();
};

class OOGSpecial: public OOGFeature{
public:
	OOGSpecial(int modelnum, int featureid){
		modelNum = modelnum;
		featureID = featureid;
	}
	ShapeType myType(){
		return SPECIAL;
	}
	double getX();
	double getY();
};

class OOGTriangle: public OOGFeature{
public:
	OOGTriangle(int modelnum, int featureid){
		modelNum = modelnum;
		featureID = featureid;
	}
	ShapeType myType(){
		return TRIANGLE;
	}
	double getX();
	double getY();
	std::vector<std::pair<double, double> > getVertexes();
};

/**
 * @brief V2 model
 */
class OOGModel{
private:
	std::vector<OOGFeature *> features;
	int num_elements;
	int model_no;
public:
	OOGModel(std::string _model_name);
	int getModelNum(){
		return model_no;
	}
	int getNumElements(){
		return num_elements;
	}
	OOGFeature* getElement(int index){
		if( index < num_elements){
			return features.at(index);
		}else{
			return NULL;
		}
	}
};

/** @}*/ //end of v2group
#endif
