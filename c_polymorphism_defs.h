//
// Created by tameer on 9/20/19.
//

#ifndef C_POLYMORPHISM_TRANSLATOR_C_POLYMORPHISM_DEFS_H
#define C_POLYMORPHISM_TRANSLATOR_C_POLYMORPHISM_DEFS_H
int next_id;

static int getId() { return next_id++; }

void printFunc(const char *fname) {
    printf("%-60s | ", fname);
}
/******************** Text Formater ***************************/
/* virtual table for A*/
typedef struct VTableTextFormatter {
    void (*TextFormaterDtor)();

    void (*print)(const char *);

} VTableTextFormatter;

typedef struct TextFormater {
    void *vptr; /* pointer to a struct VTableA that act like a virtual table in cpp*/
} TextFormater;
void TextFormaterDtor();
void print(const char *);

/************************ DefaultTextFormatter **********************/



typedef struct DefaultTextFormatter {
    TextFormater base;
    int id;
} DefaultTextFormatter;

typedef struct VTableDefaultTextFormatter {
    void (*DefaultTextFormatter_dtor)(DefaultTextFormatter* const this);
    void (*printdtft)(const char* const);

} VTableDefaultTextFormatter;

void DefaultTextFormatter_ctor(DefaultTextFormatter* const this); /*constructor*/

DefaultTextFormatter *const DefaultTextFormatter_copy(DefaultTextFormatter* const this, DefaultTextFormatter *const); /*copy constructor*/

DefaultTextFormatter *const operatorA(DefaultTextFormatter* const this, DefaultTextFormatter *const); /*operator=*/

void DefaultTextFormatter_dtor(DefaultTextFormatter* const this); /*destructor*/

void printdtft(const char *const text); /*name mangling dtf => DefaultTextFormatter */

DefaultTextFormatter *generateFormatterArray();


/*************************************** PrePostFixer Defs *************************************/

typedef struct VTablePrePostFixer {

    void (*printppf)();
    void (*printppf_lc)();
    void (*PrePostFixer_dtor)();
} VTablePrePostFixer;

typedef struct PrePostFixer
{
    DefaultTextFormatter base;
    const char* pre;
    const char* post;
}PrePostFixer;
void printppf_c(PrePostFixer* const this,const char* const);
void PrePostFixer_ctorcc(PrePostFixer* const this,const char* prefix, const char* postfix);
void PrePostFixer_dtor(PrePostFixer* const this);
void printppf_lc(PrePostFixer* const this,long num, char symbol );


/*************************************** PrePostDollarFixer Defs *************************************/

typedef struct {
    void (*printppdf_lc)();
    void (*PrePostDollarFixer_dtor)();
} VTablePrePostDollarFixer;

const char DEFAULT_SYMBOL;
typedef struct {
    PrePostFixer base;
}PrePostDollarFixer;

void PrePostDollarFixer_ctor_cc(PrePostDollarFixer* const this,const char* prefix, const char* postfix);
void PrePostDollarFixer_cpy(PrePostDollarFixer* const this, const PrePostDollarFixer* const other);
void PrePostDollarFixer_dtor(PrePostDollarFixer* const this);

void printppdf_ic(PrePostDollarFixer* const this,int num, char symbol) ;
void printppdf_lc(PrePostDollarFixer* const this,long num, char symbol) ;
void printppdf_dc(PrePostDollarFixer* const this,double num, char symbol) ;

/************************************* PrePostHashFixer Defs *************************************/

typedef struct {
    void (*printpphf_lc)();
    void (*PrePostHashFixer_dtor)();
} VTablePrePostHashFixer;


typedef struct{
    PrePostDollarFixer base ;
    int precision;
}PrePostHashFixer;

void PrePostHashFixer_ctor_c(PrePostHashFixer* const this ,int prc);/*default value prc = 4*/
void PrePostHashFixer_dtor(PrePostHashFixer* const this );

void printpphf_ic(PrePostHashFixer* const this ,int num, char symbol);/*default value    symbol = #*/
void printpphf_lc(PrePostHashFixer* const this ,long num, char symbol);/*default value   symbol = #*/
void printpphf_dc(PrePostHashFixer* const this ,double num, char symbol);/*default value symbol = #*/

/************************************** PrePostFloatDollarFixer ******************************************/
typedef struct {
    void (*PrePostFloatDollarFixer_dtor)();
} VTablePrePostFloatDollarFixer;

typedef  struct {
    PrePostDollarFixer base;
}PrePostFloatDollarFixer;

void PrePostFloatDollarFixer_ctor_cc(PrePostFloatDollarFixer* const this ,const char* prefix, const char* postfix);
void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this);
void printppfdf_f(PrePostFloatDollarFixer* const this,float num);
void printppfdf_fc(PrePostFloatDollarFixer* const this,float num, char symbol);




#endif //C_POLYMORPHISM_TRANSLATOR_C_POLYMORPHISM_DEFS_H
