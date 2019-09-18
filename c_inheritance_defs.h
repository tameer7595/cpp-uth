

#ifndef CTRANSLATOR_C_INHERITANCE_DEFS_H
#define CTRANSLATOR_C_INHERITANCE_DEFS_H

#include <stdio.h>
#include "c_encapsulation_defs.h"
typedef enum
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct {
    char A;
}Materials;

/*
void Materials_ctor(Materials *this,Types type){
    this->type = type;
}*/

static const char* getName(Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}

typedef struct Material_t{

    Types material;
}Material_t;
const char* name(const Material_t* const this);

/*default value is OTHER*/
void Material_ctor_t(Material_t *this,Types mat );


/************************ PhysicalBox**********************************/

typedef struct PhysicalBox{
    Material_t material;
    Box base_c;
}PhysicalBox;

void PhysicalBox_ctor_ddd(PhysicalBox *this,double l, double w, double h);
void PhysicalBox_ctor_dddT(PhysicalBox *this,double l, double w, double h, Types t);
void PhysicalBox_ctor_t(PhysicalBox *this,Types t);
void PhysicalBox_dtor(PhysicalBox *this);
void printp(const PhysicalBox *const this);

/*inline Materials::Types PhysicalBox::getMaterial() const
{
    return material.material;
}*/

/*inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return !(lhs == rhs);
}
 */

/****************************WeightBox****************/

typedef struct WeightBox{
    double weight;
    Box base_c;
}WeightBox;

void WeightBox_ctor_dddd(WeightBox *this,double l, double w, double h, double wgt );
void WeightBox_cpyctor(WeightBox* this,WeightBox* const other);
void WeightBox_dtor(WeightBox* this);
void printw(const WeightBox *const this);
#endif /*CTRANSLATOR_C_INHERITANCE_DEFS_H*/


