#ifndef MODEL_HPP
#define MODEL_HPP

#include "ShapeType.hpp"
#include "xbug.hpp"
#include "Feature.hpp"
#include "Imp.hpp"
#include "Factory.hpp"
#include <string>
#include <vector>

class Model
{
private:
	std::vector<Feature*> features ;
	std::string model_name ;
	int model_no ;
	//int num_element ;
public:
	Model(std::string model_name, Factory* factory) ;
	int getNumElements() ;
	std::string getModelName() ;
	int getModelNum() ;
	Feature * getFeature(int index) ;
	void setFeature(int index, Feature * f) ;
} ;

#endif
