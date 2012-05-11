#include "Model.hpp"
#include "V1System.hpp"
#include "V2System.hpp"
#include "xbug.hpp"
#include <iostream>

Model::Model(std::string modelName, Imp* imp)
{
	model_name = modelName;
	model_no = imp->OpenModel(model_name);
	if( model_no == 0){
			throw xbug("Model: Model "+model_name+" not exists.");
	}
    std::vector< std::pair<ShapeType, int> > list = imp->getList(model_no);

	Factory* factory = Factory::getInstance();
	for(std::vector< std::pair<ShapeType, int> >::iterator iter = list.begin(); iter != list.end(); iter++)
    {
		Feature* f = factory->generate(iter, model_no, imp);
		features.push_back(f) ;
	}
}

int Model::getNumElements() 
{
	return (int)features.size() ;
}
	
std::string Model::getModelName() 
{
	return model_name ;
}

int Model::getModelNum() 
{
	return model_no ;
}

Feature* Model::getFeature(int index) 
{
	if( index < (int)features.size()) {
		return features[index] ;
	}
	return NULL ;
}

void Model::setFeature(int index, Feature * f) 
{
	if( index < (int)features.size()) {
		features[index] = f ;
	}
}
