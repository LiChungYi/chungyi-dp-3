#include "CADDB.hpp"
#include <fstream>
#include <algorithm>
#include "xbug.hpp"

using namespace std;

CADDB* CADDB::instance = 0;

CADDB::CADDB(){}

CADDB* CADDB::getInstance(){
	if (instance == 0) {
		instance = new CADDB();
		instance->createLookUpTable();
	}
	return instance;
}

// Parameter
//    feature_string: the string of some ShapeType
// Return Value
//    ShapeType of feature_string
ShapeType get_shapetype_by_string(const std::string feature_string){
	static std::map<std::string, ShapeType> map_table;
	static int first_time = 1;
	if( first_time == 1){
		first_time = 0;
                map_table["SLOT"]      = SLOT;
                map_table["HOLE"]      = HOLE;
                map_table["CUTOUT"]    = CUTOUT;
                map_table["IRREGULAR"] = IRREGULAR;
                map_table["SPECIAL"]   = SPECIAL;
	}
	return map_table[feature_string];	
}

#define npos -1
// Parameter 
//    &line: the input string
// Remark
//    delete the character after '#' and delete the space in the front and in the back of line;
void deal_string_mark_space(std::string &line){
	int mark_pos = line.find("#");
	if( mark_pos != npos ){
		line.erase(mark_pos);
	}
	int non_space_pos = line.find_first_not_of(" ");
	line.erase(0, non_space_pos);
	non_space_pos = line.find_last_not_of(" ")+1;
	if( non_space_pos != line.length()){
		line.erase(non_space_pos);
	}
}

// Parameter
//    line: the input string
//    &split_strings: the vector of strings splited from the line
// Remark
//    split line by space(' ') and store to split_strings
void split_string_by_space(const std::string line, std::vector<std::string> &split_strings){
	int non_space_pos = 0;
	int space_pos = line.find_first_of(" ");
	while( space_pos != npos){
		split_strings.push_back(line.substr(non_space_pos, space_pos-non_space_pos));
		non_space_pos = line.find_first_not_of(" ", space_pos);
		space_pos = line.find_first_of(" ", non_space_pos);
	}
	split_strings.push_back(line.substr(non_space_pos));
}


void CADDB::createLookUpTable(){
	
	ifstream inModel("CAD.txt");
	if(inModel.bad()){
		throw xbug("CAD.txt: No such file.");
	}
	
	std::string line;
	while( getline(inModel, line)){
		deal_string_mark_space(line);
		
		if(!line.empty()){

			// split the input line and check the item size
			std::vector<std::string> split_strings;
			split_string_by_space(line, split_strings);	
			if( split_strings.size() < 3){
				throw xbug("CAD.txt: Wrong format. 1");
			}
			
			// get information from split_strings and re-check the item size
			int model_no = atoi(split_strings.at(1).data());
			int num_feature = atoi(split_strings.at(2).data());
			if( split_strings.size() != (3 + (num_feature<<1))){
				throw xbug("CAD.txt: Wrong format. 2");
			}
			mNameNum[split_strings.at(0)] = model_no;
			mNumElements[model_no] = num_feature;
			
			// get information from each pair of <ShapeType, int> and check ShapeType
			for(int i=0,j=3;i<num_feature;++i,j+=2){
				ShapeType shape_type = get_shapetype_by_string(split_strings.at(j));
				if( shape_type == NONE){
					throw xbug("CAD.txt: Wrong format. 3");
				}
				int feature_id = atoi(split_strings.at(j+1).data());
				models[model_no].push_back(make_pair(shape_type, feature_id));
				shapetypes[feature_id] = shape_type;
			}
		}
	}
	inModel.close();

	ifstream inFeature("CAD-Features.txt");
	if(inFeature.bad()){
		throw xbug("CAD-Features.txt: No such file.");
	}

	while( getline(inFeature, line)){		
		deal_string_mark_space(line);
		
		if(!line.empty()){
			
			// split the input line and check the item size
			std::vector<std::string> split_strings;
			split_string_by_space(line, split_strings);
			int split_strings_size = split_strings.size();
			if( split_strings_size < 1){
				throw xbug("CAD-Features.txt: Wrong format. 1");
			}
			
			// get information from split_strings and re-check the item size
			int feature_id = atoi(split_strings.at(0).data());		
			ShapeType shape_type = shapetypes[feature_id];
			const int shapetype_size[] = {4,4,4,4,3};
			if( shape_type == IRREGULAR){
				if( split_strings_size < 4){
					throw xbug("CAD-Features.txt: Wrong format. 2");
				}
			}else if( split_strings_size != shapetype_size[int(shape_type)]){
				throw xbug("CAD-Features.txt: Wrong format. 3");
			}
			
			// get information for each feature and check ShapeType
			std::vector<double> attr;
			for(int i=1;i<3;++i){
				attr.push_back(atof(split_strings.at(i).data()));
			}
			switch(shape_type){
				case SLOT:			
				case HOLE:			
				case CUTOUT:
					attr.push_back(atof(split_strings.at(3).data()));
					break;
				case IRREGULAR:
					unsigned num = (unsigned)atoi(split_strings.at(3).data());
					unsignedAttributes[feature_id] = num;
					if( split_strings_size != (4+num)){
						throw xbug("CAD-Features.txt: Wrong format. 4");
					}
					std::vector<ShapeType> sattr;
					for(int i=4,j=0;j<num;++i,++j){
						ShapeType inner_shape_type = get_shapetype_by_string(split_strings.at(i));
						if( inner_shape_type == NONE ){
							throw xbug("CAD-Features.txt: Wrong format. 5");
						}
						sattr.push_back(inner_shape_type);
					}
					shapetypeAttributes[feature_id] = sattr;
					break;
			}
			doubleAttributes[feature_id] = attr;
		}
	}
	inFeature.close();
}

