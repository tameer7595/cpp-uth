
/* Created by tameer on 9/16/19.*/

#include<stdio.h>
#include "c_encapsulation_defs.h"
const char* message = "The total volume held on the shelf is";

void Box_ctor_d(Box *this, double dim) {
    this->length = this->height = this->width = dim;
}

void Box_ctor_ddd(Box *this, double l, double w, double h) {
    this->length = l;
    this->width = w;
    this->height = h;
}

void Box_dtor(Box *this) {
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

double getWidth(const Box *const this) {
    return this->width;
}

double getLength(const Box* const this) {
    return this->length;
}

double getHeight(const Box* const this) {
    return this->height;
}

double getVolumeBB(const Box* const this) {
    return this->width * this->length * this->height;
}
void printBB(const Box* const this)
{
printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}
/*like overload operator (*=)*/
Box* const operatorMA(Box *this,double mult) {
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;
    return this;
}

/*like overload operator (*) gets Box and double*/
Box operatorM_Bd(Box* const box, double mult) {
    Box *ret;
    ret = box;
    ret = operatorMA(ret, mult);
    return *ret;
}

/*like overload operator (*) gets double and box*/
Box operatorM_dB(double mult,Box *const box) {
    return operatorM_Bd(box, mult);
}

/*like overload operator (==) gets double and box*/
bool operator_equals(Box *const lhs,Box *const rhs) {
    return getWidth(lhs) == getWidth(rhs) && getHeight(lhs) == getHeight(rhs) && getLength(lhs) == getLength(rhs);
}
/*like overload operator (!=) gets double and box*/
bool operator_not_equal(Box *const lhs,Box *const rhs) {
    return !operator_equals(lhs, rhs);
}
/********************************************** shelf****************************************/

void Shelf_dtor(){

}
void setBox(Shelf* const this,int index, const Box *const dims){
    this->boxes[index] = *dims;
}

double getVolumeSB(const Shelf *const this){
    {
        double vol = 0;
        int i;
        for (i = 0; i < 3; ++i)
            vol += getVolumeBB(&this->boxes[i]);

        return vol;
    }
}

Box *const getBox(Shelf* const this,int index){
    return &this->boxes[index];
}

void printSB(const Shelf *const this){
    printf("%s %f\n", message, getVolumeSB(this));
}


int getNumBoxes(Shelf* const this)
{
    return 3;
}



