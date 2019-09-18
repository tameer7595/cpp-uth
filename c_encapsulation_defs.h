
#ifndef CTRANSLATOR_C_ENCAPSULATION_DEFS_H
#define CTRANSLATOR_C_ENCAPSULATION_DEFS_H


typedef enum {
    FALSE, TRUE
} bool;
typedef struct{
    double width;
    double height;
    double length;
} Box;
void Box_ctor_d(Box*this,double dim);

void Box_ctor_ddd(Box*this,double l,double w,double h);

void Box_dtor(Box*this);

/*TODO:must to provide copy*/

double getWidth(const Box *const this);

double getLength(const Box *const this);

double getHeight(const Box *const this);

double getVolumeBB(const Box *const this);

void printBB(const Box* const this);
/*TODO:must to provide OPERATOR =*/
Box* const operatorMA(Box *, double mult);

Box operatorM_Bd(Box *const box, double mult);

Box operatorM_dB(double mult, Box *const box);

bool operator_equals(Box *const lhs, Box *const rhs);

bool operator_not_equal(Box *const lhs, Box *const rhs);

/*********************************shelf***************************************/

static const char* const DEF_MSG= "The total volume held on the shelf is";

typedef struct Shelf {
    Box boxes[3];
}Shelf;
void Shelf_dtor();
void setBox(Shelf* const this,int index, const Box *const dims);

double getVolumeSB(const Shelf *const);

Box *const getBox(Shelf* const this,int index);

void printSB(const Shelf *const);

int getNumBoxes();



#endif /*CTRANSLATOR_C_ENCAPSULATION_DEFS_H*/
