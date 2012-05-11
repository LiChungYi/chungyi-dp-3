#ifndef FACTORY_HPP
#define FACTORY_HPP

#include<string>
#include<map>
#include<stdio.h>
#include<stdlib.h>

#include"Feature.hpp"
#include"Imp.hpp"
#include"ShapeType.hpp"
class Factory{
    private:
	static Factory* instance;
	std::map<ShapeType, Feature*> manager;
	Factory(){
		manager[SLOT] = new SlotFeature(0, 0, NULL);	
		manager[HOLE] = new HoleFeature(0, 0, NULL);	
		manager[CUTOUT] = new CutoutFeature(0, 0, NULL);	
		manager[IRREGULAR] = new IrregularFeature(0, 0, NULL);	
		manager[SPECIAL] = new SpecialFeature(0, 0, NULL);	
		manager[TRIANGLE] = new TriangleFeature(0, 0, NULL);	
	}
    public:
	static Factory* getInstance(){
		if(instance == NULL)
			instance = new Factory();
		return instance;
	}
	/*
	int OpenModel(std::string modelName){
		return _imp->OpenModel(modelName);
	}
	std::vector<std::pair<ShapeType, int> > getList(int model_no){
		return _imp->getList(model_no);
	}*/
	Feature* generate(std::vector< std::pair<ShapeType, int> >:: iterator iter, int model_no, Imp* imp){
		Feature* fOld = manager[iter->first];
		if(fOld == NULL){
			char msg[100]; 
			sprintf(msg, "(%d)", iter->first);
			throw xbug("Type " + std::string(msg) + " can't be created");
		}
		Feature* f = fOld->clone();
		f->setAttribute(model_no, iter->second, imp);
		return f;
		/*
		switch(iter->first){
			case SLOT:
				return new SlotFeature(model_no, iter->second, _imp) ;
			case HOLE:
				return new HoleFeature(model_no, iter->second, _imp) ;
			case CUTOUT:
				return new CutoutFeature(model_no, iter->second, _imp) ;
			case IRREGULAR:
				return new IrregularFeature(model_no, iter->second, _imp) ;
			case SPECIAL:
				return new SpecialFeature(model_no, iter->second, _imp) ;
			case TRIANGLE:
				return new TriangleFeature(model_no, iter->second, _imp);
			default:
				return NULL;
		}*/
	}
};
#endif
