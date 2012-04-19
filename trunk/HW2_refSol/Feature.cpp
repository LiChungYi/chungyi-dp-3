#include "Feature.hpp"
#include "xbug.hpp"

Feature::Feature(int modelNo, int featureIndex, Imp *impFeature):
    model_no(modelNo),
    feature_index(featureIndex),
    imp(impFeature)
{}

SlotFeature::SlotFeature(int modelNo, int featureIndex, Imp *impFeature):
    Feature(modelNo, featureIndex, impFeature)
{}

ShapeType SlotFeature::featureType()
{
    return SLOT;
}
double SlotFeature::getXLoc()
{
    return imp->getXLoc(model_no, feature_index);
}
double SlotFeature::getYLoc()
{
    return imp->getYLoc(model_no, feature_index);
}
double SlotFeature::getLength()
{
    return imp->getLength(model_no, feature_index);
}


HoleFeature::HoleFeature(int modelNo, int featureIndex, Imp *impFeature):
    Feature(modelNo, featureIndex, impFeature)
{}

ShapeType HoleFeature::featureType()
{
    return HOLE;
}
double HoleFeature::getXLoc()
{
    return imp->getXLoc(model_no, feature_index);
}
double HoleFeature::getYLoc()
{
    return imp->getYLoc(model_no, feature_index);
}
double HoleFeature::getDiameter()
{
    return imp->getDiameter(model_no, feature_index);
}


CutoutFeature::CutoutFeature(int modelNo, int featureIndex, Imp *impFeature):
    Feature(modelNo, featureIndex, impFeature)
{}

ShapeType CutoutFeature::featureType()
{
    return CUTOUT;
}
double CutoutFeature::getXLoc()
{
    return imp->getXLoc(model_no, feature_index);
}
double CutoutFeature::getYLoc()
{
    return imp->getYLoc(model_no, feature_index);
}
double CutoutFeature::getOperations()
{
    return imp->getOperation(model_no, feature_index);
}


IrregularFeature::IrregularFeature(int modelNo, int featureIndex, Imp *impFeature):
    Feature(modelNo, featureIndex, impFeature)
{}

ShapeType IrregularFeature::featureType()
{
    return IRREGULAR;
}
double IrregularFeature::getXLoc()
{
    return imp->getXLoc(model_no, feature_index);
}
double IrregularFeature::getYLoc()
{
    return imp->getYLoc(model_no, feature_index);
}
unsigned IrregularFeature::getNumSegments()
{
    return imp->getNumSegments(model_no, feature_index);
}
std::vector<ShapeType> IrregularFeature::getSegments()
{
    return imp->getSegments(model_no, feature_index);
}


SpecialFeature::SpecialFeature(int modelNo, int featureIndex, Imp *impFeature):
    Feature(modelNo, featureIndex, impFeature)
{}

ShapeType SpecialFeature::featureType()
{
    return SPECIAL;
}
double SpecialFeature::getXLoc()
{
    return imp->getXLoc(model_no, feature_index);
}
double SpecialFeature::getYLoc()
{
    return imp->getYLoc(model_no, feature_index);
}
