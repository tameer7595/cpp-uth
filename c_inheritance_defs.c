

#include "c_inheritance_defs.h"
const char* getName(Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}

const char *name(const Material_t *const this) {
    return getName(this->material);
}

/*default value is OTHER*/
void Material_ctor_t(Material_t* const this, Types mat) {
    this->material = mat;
    printf("Material created, set to %s\n", name(this));
}

void PhysicalBox_ctor_ddd(PhysicalBox* const this, double l, double w, double h) {
    Box_ctor_ddd(&this->base_c, l, w, h);


}

void PhysicalBox_ctor_dddT(PhysicalBox* const this, double l, double w, double h, Types t) {

    Box_ctor_ddd(&this->base_c, l, w, h);
    Material_ctor_t(&this->material,t);
    printp(this);
}

void PhysicalBox_ctor_t(PhysicalBox* const this, Types t) {
    this->base_c.length = this->base_c.width =this->base_c.height = 1;
    printBB(&this->base_c);
    Material_ctor_t(&this->material,t);
    printp(this);
}

void PhysicalBox_dtor(PhysicalBox* const this) {
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->base_c.length, this->base_c.width, this->base_c.height,name(&this->material));
    Box_dtor(&this->base_c);
}

void printp(const PhysicalBox *const this) {
    printf("PhysicalBox, made of %s; ", name(&this->material));
    printBB(&this->base_c);
}

/***************************WeightBox***************************/
/*constructor*/
void WeightBox_ctor_dddd(WeightBox* const this, double l, double w, double h, double wgt) {
    Box_ctor_ddd(&this->base_c, l, w, h);
    this->weight = wgt;
    printw(this);
}

/*copy constructor*/
void WeightBox_cpyctor(WeightBox* const this,WeightBox* const other){
    this->base_c.length = this->base_c.width =this->base_c.height = 1;
    printBB(&this->base_c);
    this->weight=other->weight;
    printw(this);

}

void WeightBox_dtor(WeightBox* const this)
{
    printf("Destructing WeightBox; ");
    printw(this);
    Box_dtor(&this->base_c);
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