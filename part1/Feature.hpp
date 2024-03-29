#ifndef FEATURE_HPP
#define FEATURE_HPP

#include "ShapeType.hpp"
#include "Imp.hpp"
#include "xbug.hpp"
#include <vector>

class Feature 
{
protected:
    int model_no;
    int feature_index;
    Imp* imp;
public:
    Feature(int, int, Imp*);
    virtual ShapeType featureType() = 0;
    virtual double getXLoc() = 0;
    virtual double getYLoc() = 0;
};

class SlotFeature: public Feature 
{
public:
    SlotFeature(int, int, Imp*);
    virtual ShapeType featureType();
    virtual double getXLoc();
    virtual double getYLoc();
    virtual double getLength();
} ;

class HoleFeature: public Feature 
{
public:
    HoleFeature(int, int, Imp*);
    virtual ShapeType featureType();
    virtual double getXLoc();
    virtual double getYLoc();
    virtual double getDiameter();
} ;

class CutoutFeature: public Feature 
{
public:
    CutoutFeature(int, int, Imp*);
    virtual ShapeType featureType();
    virtual double getXLoc();
    virtual double getYLoc();
    virtual double getOperations();
} ;

class IrregularFeature: public Feature 
{
public:
    IrregularFeature(int, int, Imp*);
    virtual ShapeType featureType();
    virtual double getXLoc();
    virtual double getYLoc();
    virtual unsigned getNumSegments();
    virtual std::vector<ShapeType> getSegments();
} ;

class SpecialFeature: public Feature 
{
public:
    SpecialFeature(int, int, Imp*) ;
    virtual ShapeType featureType() ;
    virtual double getXLoc() ;
    virtual double getYLoc() ;
} ;
#endif