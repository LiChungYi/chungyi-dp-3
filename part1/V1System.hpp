#ifndef V1SYSTEM_HPP
#define V1SYSTEM_HPP

#include <string>
#include <vector>
#include "ShapeType.hpp"

int V1OpenModel(std::string modelName);
int V1GetNumberOfElements(int modelNum);
ShapeType V1GetType(int modelNum, int elemNum);
int V1GetID(int modelNum, int elemNum);

double V1GetXforSlot(int modelNum, int featureID);
double V1GetYforSlot(int modelNum, int featureID);
double V1GetLengthforSlot(int modelNum, int featureID);

double V1GetXforHole(int modelNum, int featureID);
double V1GetYforHole(int modelNum, int featureID);
double V1GetDiameterforHole(int modelNum, int featureID);

double V1GetXforCutout(int modelNum, int featureID);
double V1GetYforCutout(int modelNum, int featureID);
double V1GetOperationsforCutout(int modelNum, int featureID);

double V1GetXforIrregular(int modelNum, int featureID);
double V1GetYforIrregular(int modelNum, int featureID);
unsigned V1GetNumSegmentsforIrregular(int modelNum, int featureID);
std::vector<ShapeType> V1GetSegmentsforIrregular(int modelNum, int featureID);

double V1GetXforSpecial(int modelNum, int featureID);
double V1GetYforSpecial(int modelNum, int featureID);

#endif
