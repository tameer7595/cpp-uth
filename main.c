#include <stdio.h>

#include "c_encapsulation_defs.h"

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

int main()
{
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
    Box_dtor(&largeBox);
    return 0;
}

