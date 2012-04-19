#include <iostream>
#include "Model.hpp"
#include "xbug.hpp"
#include "V1Imp.hpp"
#include "V2Imp.hpp"
#include <map>
#include <algorithm>

using namespace std;

// compare method by x location of feature
bool compare_feature_by_x(Feature *x, Feature *y){
	return (x->getXLoc() < y->getXLoc());
}

void expertSystem(Model &md){
	int num = md.getNumElements();
	std::vector<Feature *> a;
	for(int i=0;i<num;++i){
		a.push_back(md.getFeature(i));
	}
	std::sort(a.begin(), a.end(), compare_feature_by_x);
	for(int i=0;i<num;++i){
		md.setFeature(i, a.at(i));
	}
}

// Parameter
//    shape_type: the input ShapeType
// Return Value
//    the string of shape_type
std::string getShape(ShapeType shape_type){
	static std::map<ShapeType, std::string> map_table;
	static int first_time = 1;
	if( first_time == 1){
		first_time = 0;
		map_table[SLOT]      = "SLOT";
		map_table[HOLE]      = "HOLE";
		map_table[CUTOUT]    = "CUTOUT";
		map_table[IRREGULAR] = "IRREGULAR";
		map_table[SPECIAL]   = "SPECIAL";
	}
	return map_table[shape_type];;
}

void generateNCCommands(Model &md){
	for (int i=0; i< md.getNumElements(); ++i) {
		cout <<"Step"<<i+1<<". Generate:"<< md.getModelName() << ":" << md.getModelNum() << ":";

		Feature* f = md.getFeature(i);
		switch(f->featureType()) {
		case SLOT:
			cout << "SLOT->" << f->getXLoc() << ":" << f->getYLoc() << ":" << ((SlotFeature *)f)->getLength();
			break;
		case HOLE:
			cout << "HOLE->" << f->getXLoc() << ":" << f->getYLoc() << ":" << ((HoleFeature*)f)->getDiameter();
			break;
		case CUTOUT:
			cout << "CUTOUT->" << f->getXLoc() << ":" << f->getYLoc() << ":" << ((CutoutFeature*)f)->getOperations();
			break;
		case SPECIAL:
			cout << "SPECIAL->" << f->getXLoc() << ":" << f->getYLoc();
			break;
		case IRREGULAR:
			cout << "IRREGULAR->" << f->getXLoc() << ":" << f->getYLoc() << ":" << ((IrregularFeature*)f)->getNumSegments();
			vector<ShapeType> tmp = ((IrregularFeature*)f)->getSegments();
			for(int j=0; j<tmp.size(); ++j) {
				cout << ":" << getShape(tmp[j]);
			}
			break;			
		}
		cout << endl;
	}
}

int main(){
	try{
		Model md("testModel", new V1Imp);
		expertSystem(md);
		generateNCCommands(md);
	}catch(xbug xb){
		cerr << "xbug occur: "+ xb.what() << endl;
		exit(1);
	}
	return 0;
}
