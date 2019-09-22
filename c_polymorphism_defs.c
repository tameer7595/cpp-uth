//
// Created by tameer on 9/20/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "c_polymorphism_defs.h"


/************************************ DefaultTextFormatter ********************************/
next_id = 0;
void DefaultTextFormatter_ctor(DefaultTextFormatter* const this)

{
    this->id = (getId());
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
void DefaultTextFormatter_dtor(DefaultTextFormatter* const this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}

DefaultTextFormatter* const DefaultTextFormatter_copy(DefaultTextFormatter* const this,DefaultTextFormatter* const other){
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

DefaultTextFormatter* const operatorA(DefaultTextFormatter* const this,DefaultTextFormatter* const other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}

void printdtft(const char* const  text)
{
    printFunc("[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter* arr = malloc(sizeof(DefaultTextFormatter)*3);
    return arr;
}


/*************************************** PrePostFixer *************************************/


void PrePostFixer_ctorcc(PrePostFixer* const this,const char* prefix, const char* postfix){
    DefaultTextFormatter_ctor(&this->base);
    this->pre = prefix;
    this->post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void PrePostFixer_dtor(PrePostFixer* const this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void printppf_c(PrePostFixer* const this,const char* const text)
{
    printFunc("[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}
/* there are some function that defined  as inline */
void

printppf_lc(PrePostFixer* const this,long num, char symbol ){
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol) {
        printFunc("[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    }
    else{
        printFunc("[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }
}

/**************************************** PrePostDollarFixer ***********************************/
const char DEFAULT_SYMBOL = '$';


void PrePostDollarFixer_ctor_cc(PrePostDollarFixer* const this,const char* prefix, const char* postfix){
    PrePostFixer_ctorcc(&this->base,prefix, postfix);
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n",this->base.pre, this->base.post);
}

void PrePostDollarFixer_cpy(PrePostDollarFixer* const this, const PrePostDollarFixer* const other){
    PrePostDollarFixer_cpy(this,other);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->base.pre, this->base.post);
}

void PrePostDollarFixer_dtor(PrePostDollarFixer* const this){

    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->base.pre,  this->base.post);

}

void printppdf_ic(PrePostDollarFixer* const this,int num, char symbol){
    printFunc("[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    printppdf_lc(this,(long)num, symbol);
}

void printppdf_lc(PrePostDollarFixer* const this,long num, char symbol){
    printFunc("[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol) {
        /*put a PrePostFixer::print_num(long,char) inline func */
        printFunc("[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->base.pre, symbol, num, this->base.post);
    }else{
        /*put a PrePostFixer::print_num(long) inline func */
        printFunc("[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->base.pre, num, this->base.post);
    }
}

void printppdf_dc(PrePostDollarFixer* const this,double num, char symbol){
    printFunc("[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%F%s\n", this->base.pre, symbol, num, this->base.post);

}
/************************************* PrePostHashFixer *************************************/

void PrePostHashFixer_ctor_c(PrePostHashFixer* const this ,int prc){
    PrePostDollarFixer_ctor_cc(&this->base,"===> ", " <===");
    this->precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->base.base.pre,this->base.base.post, this->precision);
    printFunc("[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*F]%s\n", this->base.base.pre,'#', this->precision, 9999.9999, this->base.base.post);
}

void PrePostHashFixer_dtor(PrePostHashFixer* const this ){
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->base.base.pre, this->base.base.post);
}

void printpphf_ic(PrePostHashFixer* const this ,int num, char symbol){
    printFunc("[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printFunc("[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*F]%s\n", this->base.base.pre, symbol, this->precision, (double)num,this->base.base.post);

}

void printpphf_lc(PrePostHashFixer* const this ,long num, char symbol){
    printFunc("[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printFunc("[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*F]%s\n", this->base.base.pre, symbol, this->precision, (double)num,this->base.base.post);
}

/************************************** PrePostFloatDollarFixer ******************************************/

void PrePostFloatDollarFixer_ctor_cc(PrePostFloatDollarFixer* const this ,const char* prefix, const char* postfix){
    PrePostDollarFixer_ctor_cc(&this->base,prefix, postfix);
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->base.base.pre, this->base.base.post);

}
void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this){
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->base.base.pre, this->base.base.post);
}

void printppfdf_f(PrePostFloatDollarFixer* const this,float num){
    printFunc("[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    printFunc("[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2F%s\n",this->base.base.pre, '@', num, this->base.base.post);
}

void printppfdf_fc(PrePostFloatDollarFixer* const this,float num, char symbol){
    printFunc("[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2F%s\n",this->base.base.pre, symbol, num, this->base.base.post);
}

