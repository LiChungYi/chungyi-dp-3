#ifndef FACTORY_HPP
#define FACTORY_HPP

#include<string>

#include"Feature.hpp"
#include"Imp.hpp"
#include"ShapeType.hpp"
//#include".hpp"
class Factory{
    public:
	Factory(Imp* imp):_imp(imp){}
	int OpenModel(std::string modelName){
		return _imp->OpenModel(modelName);
	}
	std::vector<std::pair<ShapeType, int> > getList(int model_no){
		return _imp->getList(model_no);
	}
	Feature* generate(std::vector< std::pair<ShapeType, int> >:: iterator iter, int model_no){
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
		}
	}
    private:
	Imp* _imp;
};
#endif
