#ifndef CADDB_HPP
#define CADDB_HPP

#include <string>
#include <vector>
#include <map>
#include "ShapeType.hpp"

/** 
 * @defgroup DBGroup DataBase group.
 * @{
 */

/**
 *
 *@brief CAD database.
 *
 * CADDB is a Singleton instance to parse the CAD database (textfiles)
 * In our design a DB could consist of several models. In real world,
 * MicroStation.
 *
 */

class CADDB {
private:
	CADDB(); ///< A fake constructor.
	static CADDB* instance;  ///< Point of database.
	std::map<std::string, int> mNameNum;
	std::map<int, int> mNumElements;
	std::map<int, std::vector<std::pair<ShapeType, int> > > models;
	std::map<int, ShapeType> shapetypes;

	// store all attribute of features
	std::map<int, std::vector<double> > doubleAttributes;
	std::map<int, unsigned> unsignedAttributes;
	std::map<int, std::vector<ShapeType> > shapetypeAttributes;

	void createLookUpTable();///< Setup all member above.
public:
	static CADDB* getInstance();
	
	/** 
	 * @param mName the name of model
	 *    
	 * @return the number of model, return 0 if mName not exists
	 */
	int getModelNum(std::string mName){
		return mNameNum[mName];
	}

	/** 
	 * @param mNum the number of model
	 *    
	 * @return number of model's features, return 0 if mNum not exists
	 */
	int getNumElements(int mNum){
		return mNumElements[mNum];
	}
	/** 
	 * @param modelNum the number of model
	 *    
	 * @return the vector of model's features, return empty vector if modelNum not exists
	 */
	std::vector<std::pair<ShapeType, int> > getFeature(int modelNum){
		return models[modelNum];
	}
	/** 
	 * @param featureID the ID of feature
	 *    
	 * @return the vector of double attribute of the feature, return empty vector if featureID not exists
	 */ 
	std::vector<double> getDoubleAttributes(int featureID){
		return doubleAttributes[featureID];
	}
	/** 
	 * @param featureID the ID of feature
	 *    
	 * @return the unsigned attribute of the feature, return 0 if featureID not exists
	 */ 
	unsigned getUnsignedAttributes(int featureID){
		return unsignedAttributes[featureID];
	}
	/** 
	 * @param featureID the ID of feature
	 *    
	 * @return the vector of ShapeType attribute of the feature, return empty vector if featureID not exists
	 */ 
	std::vector<ShapeType> getShapeTypeAttributes(int featureID){
		return shapetypeAttributes[featureID];
	}
};

/** @} */ // end of DBgroup
#endif /* CADDB_HPP */
