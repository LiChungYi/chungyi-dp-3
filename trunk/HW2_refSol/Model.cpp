#include "Model.hpp"
#include "V1System.hpp"
#include "V2System.hpp"
#include "xbug.hpp"
#include <iostream>

Model::Model(std::string modelName, Imp* imp)
{
	model_name = modelName ;
	model_no = imp->OpenModel(model_name) ;
	if( model_no == 0){
			throw xbug("Model: Model "+model_name+" not exists.");
	}
    std::vector< std::pair<ShapeType, int> > list = imp->getList(model_no);

	for(std::vector< std::pair<ShapeType, int> >::iterator iter = list.begin(); iter != list.end(); iter++)
    {
		Feature* f ;
		switch(iter->first)
		{
			case SLOT:
				f = new SlotFeature(model_no, iter->second, imp) ;
				break;
			case HOLE:
				f = new HoleFeature(model_no, iter->second, imp) ;
				break;
			case CUTOUT:
				f = new CutoutFeature(model_no, iter->second, imp) ;
				break;
			case IRREGULAR:
				f = new IrregularFeature(model_no, iter->second, imp) ;
				break;
			case SPECIAL:
				f = new SpecialFeature(model_no, iter->second, imp) ;
				break;
		}
		features.push_back(f) ;
	}
}

int Model::getNumElements() 
{
	return features.size() ;
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
	if( index < features.size()) {
		return features[index] ;
	}
	else {
		return NULL ;
	}
}

void Model::setFeature(int index, Feature * f) 
{
	if( index < features.size()) {
		features[index] = f ;
	}
}