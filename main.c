#include <stdio.h>

#include "c_encapsulation_defs.h"
#include "c_inheritance_defs.h"

extern  const char* message;
extern const char* getName(Types type);
static int thisfuncalled = 0;
static int thatfuncalled = 0;
static Box box99;
static Box box88;
static Box largeBox;

void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n");

    if(!thisfuncalled) {
        thisfuncalled = 1;
        Box_ctor_ddd(&box99, 99, 99, 99);

    }
        operatorMA(&box99, 10);


}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");

    if(!thatfuncalled) {
        thatfuncalled = 1;
        Box_ctor_ddd(&box88, 88, 88, 88);
    }
        operatorMA(&box88, 10);

}

void doBoxes()
{
    Box b1;
    Box b2;
    Box b3;
    Box b4;
    printf("\n--- Start doBoxes() ---\n\n");

    Box_ctor_d(&b1,3);
    Box_ctor_ddd(&b2,4,5,6);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);


    operatorMA(&b1,1.5);

    operatorMA(&b2,0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    b3 = b2;
    /*b4 = operatorM_dB(3,&b2);*/
    b4 = b2;
    operatorMA(&b4,3);


    printf("b3 %s b4\n", operator_equals(&b3,&b4) ? "equals" : "does not equal");


    b3 = *(operatorMA(&b3,1.5));
    b4 = *(operatorMA(&b4,0.5));;
    printf("Now, b3 %s b4\n",operator_equals(&b3,&b4)? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    Box_dtor(&b4);
    Box_dtor(&b3);
    Box_dtor(&b2);
    Box_dtor(&b1);
}

void doShelves()
{
    Box aBox;
    Box newbox;
    Shelf aShelf;
    printf("\n--- start doShelves() ---\n\n");

    Box_ctor_d(&aBox,5);

    printSB(&aShelf);
    setBox(&aShelf,1, &largeBox);
    setBox(&aShelf,0, &aBox);

    printSB(&aShelf);
    message = "This is the total volume on the shelf:";
    printSB(&aShelf);
    message = "Shelf's volume:";
    printSB(&aShelf);


    Box_ctor_ddd(&newbox,2, 4, 6);
    setBox(&aShelf,2, &newbox);


    printSB(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    Box_dtor(&aBox);
    Box_dtor(&newbox);
    Shelf_dtor(&aShelf);
}

void phaseone(){
    Box_ctor_ddd(&largeBox,10,20,30);
    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");
    if(thisfuncalled)
        Box_dtor(&box99);
    if(thatfuncalled)
        Box_dtor(&box88);
    Box_dtor(&largeBox);}

void doMaterials()
{
    /*Material_t mat1;*/
    Material_t mat2;
    Materials mat;
    struct MatTest { Materials mat; Material_t mat_t; };
    printf("\n--- Start doMaterials() ---\n\n");


    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest));

    Material_ctor_t(&mat2,METAL);

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox_ctor_dddT(&pb1,8, 6, 4,PLASTIC);
    PhysicalBox_ctor_t(&pb2,WOOD);
    PhysicalBox_ctor_dddT(&pb3,7, 7, 7,OTHER);
    printf("\npb4 is copy-constructed from pb1\n");
    pb4 = pb1;
    printp(&pb4);
    printp(&pb1);
    printf("pb4 %s pb1\n", (operator_equals((Box* const )&pb1 ,(Box* const )&pb4)) && (pb1.material.material == pb4.material.material)? "equals" : "does not equal");
    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    printp(&pb4);
    printp(&pb3);
    printf("pb4 %s pb3\n",(operator_equals((Box* const )&pb4 ,(Box* const )&pb3)) && (pb4.material.material == pb3.material.material)? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    PhysicalBox_dtor(&pb4);
    PhysicalBox_dtor(&pb3);
    PhysicalBox_dtor(&pb2);
    PhysicalBox_dtor(&pb1);
}

void doWeightBox()
{
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox_ctor_dddd(&pw1,8, 6, 4, 25);
    WeightBox_ctor_dddd(&pw2,1, 2, 3,0);
    WeightBox_ctor_dddd(&pw3,10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    /*pw4 = pw1;*/
    WeightBox_cpyctor(&pw4,&pw1);
    printw(&pw4);
    printw(&pw1);
    printf("pw4 %s pw1\n", ((const Box* const)&pw1 == (const Box* const)&pw4) && (pw1.weight == pw4.weight)?  "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");

    operatorA(&pw4,&pw3);
    printw(&pw4);
    printw(&pw3);
    printf("pw4 %s pw3\n",((const Box* const)&pw4 == (const Box* const)&pw3) && (pw4.weight == pw3.weight)? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    WeightBox_dtor(&pw4);
    WeightBox_dtor(&pw3);
    WeightBox_dtor(&pw2);
    WeightBox_dtor(&pw1);
}


int main()
{
    printf("\n--- Start phase1() ---\n\n");

    phaseone();

    printf("\n--- End phase1() ---\n\n");

    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

    return 0;
}

