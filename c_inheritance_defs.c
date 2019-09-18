

#include "c_inheritance_defs.h"

const char *name(const Material_t *const this) {
    return getName(this->material);
}

/*default value is OTHER*/
void Material_ctor_t(Material_t *this, Types mat) {
    this->material = mat;
    printf("Material created, set to %s\n", name(this));
}

void PhysicalBox_ctor_ddd(PhysicalBox *this, double l, double w, double h) {
    Box_ctor_ddd(&this->base_c, l, w, h);


}

void PhysicalBox_ctor_dddT(PhysicalBox *this, double l, double w, double h, Types t) {
    this->material.material = t;
    Box_ctor_ddd(&this->base_c, l, w, h);
    printBB(&this->base_c);
}

void PhysicalBox_ctor_t(PhysicalBox *this, Types t) {
    this->material.material = t;
    printBB(&this->base_c);
}

void PhysicalBox_dtor(PhysicalBox *this) {
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->base_c.length, this->base_c.width, this->base_c.height,name(&this->material));
}

void printp(const PhysicalBox *const this) {
    printf("PhysicalBox, made of %s; ", name(&this->material));
    printBB(&this->base_c);
}

/***************************WeightBox***************************/
/*constructor*/
void WeightBox_ctor_dddd(WeightBox *this, double l, double w, double h, double wgt) {
    Box_ctor_ddd(&this->base_c, l, w, h);
    this->weight = wgt;
}

/*copy constructor*/
void WeightBox_cpyctor(WeightBox* this,WeightBox* const other){
    this->weight=other->weight;
    printw(this);

}


void WeightBox_dtor(WeightBox* this)
{
    printf("Destructing WeightBox; ");
    printw(this);
}


WeightBox* const operatorA(WeightBox* this,const WeightBox* const other){
    this->weight = other->weight;
    return this;
}

void printw(const WeightBox* const this) {
    printf("WeightBox, weight: %f; ", this->weight);
    printBB(&this->base_c);
}
/*
  inline double WeightBox::getWeight() const
{
    return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
    return !(lhs == rhs);
}
*/