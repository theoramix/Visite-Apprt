#include "rectangle.h"


//STRUCTURES

void drawRectangleHB(float x, float y, float z, float h, float l){

    glBegin(GL_TRIANGLES);
    glVertex3f(x,y,z);
    glVertex3f(x+h,y,z);
    glVertex3f(x,y,z+l);
    glVertex3f(x+h,y,z+l);
    glVertex3f(x+h,y,z);
    glVertex3f(x,y,z+l);
    glEnd();
}

void drawRectangleV1(float x, float y, float z, float h, float l){

    glBegin(GL_TRIANGLES);
    glVertex3f(x,y,z);
    glVertex3f(x,y+l,z);
    glVertex3f(x,y,z+h);
    glVertex3f(x,y+l,z+h);
    glVertex3f(x,y+l,z);
    glVertex3f(x,y,z+h);
    glEnd();
}

void drawRectangleV2(float x, float y, float z, float h, float l){

    glBegin(GL_TRIANGLES);
    glVertex3f(x,y,z);
    glVertex3f(x,y+h,z);
    glVertex3f(x+l,y,z);
    glVertex3f(x+l,y+h,z);
    glVertex3f(x,y+h,z);
    glVertex3f(x+l,y,z);
    glEnd();
}

void drawSol(){
    glColor3f(0,0.5,0);
    drawRectangleHB(-10,-0.001,-10,20,20);
}

void drawMurs1(){
    glColor3f(1,1,1);
    drawRectangleHB(0,0,0,5,3);
    glColor3f(0,0,0);
    drawRectangleHB(0,3,0,5,3);
    glColor3f(0.7,0.5,0);  
    drawRectangleV2(0,0,0,3,3);
    drawRectangleV2(4,0,0,3,1);
    drawRectangleV2(0,0,0,1.5,5);
    drawRectangleV2(0,2,0,1,5);
    glColor3f(0.6,0.5,0); 
    drawRectangleV1(5,0,0,3,3);
    glColor3f(0.8,0.5,0); 
    drawRectangleV2(0,0,3,3,3);
    drawRectangleV2(4,0,3,3,1);
    drawRectangleV2(0,2,3,1,5);
}

void drawMurs2(){
    glColor3f(1,1,1);
    drawRectangleHB(-3,0,3,3,-5);
    glColor3f(0,0,0);
    drawRectangleHB(-3,3,3,3,-5);
    glColor3f(0.7,0.5,0);
    drawRectangleV1(0,0,-2,3,3);
    drawRectangleV1(0,2,0,3,1);
    drawRectangleV1(0,0,2,1,3);
    glColor3f(0.8,0.5,0);
    drawRectangleV2(0,0,-2,3,-3);
    drawRectangleV2(0,0,3,3,-3);
    glColor3f(0.6,0.5,0);
    drawRectangleV1(-3,0,-2,3,3);
    drawRectangleV1(-3,0,-2,5,1.5);
    drawRectangleV1(-3,2,-2,5,1);
    drawRectangleV1(-3,0,2,1,3);
}

// MEUBLES

void drawTable(){
    //Support
    glColor3f(0.5,0,0.5);
    drawRectangleHB(1.5,1,1,1.8,1.5);
    drawRectangleHB(1.5,0.8,1,1.8,1.5);
    drawRectangleV1(1.5,0.8,1,1.5,0.2);
    drawRectangleV1(3.3,0.8,1,1.5,0.2);
    drawRectangleV2(1.5,0.8,1,0.2,1.8);
    drawRectangleV2(1.5,0.8,2.5,0.2,1.8);

    //Pieds
    glColor3f(0,0,0);
    drawRectangleV1(1.5,0,1.1,0.1,0.8);
    drawRectangleV1(3.3,0,1.1,0.1,0.8);
    drawRectangleV1(3.3,0,2.3,0.1,0.8);
    drawRectangleV1(1.5,0,2.3,0.1,0.8);

}

void drawArmoire(){
    glColor3f(0.5,0,0.5);
    drawRectangleHB(4.3,0,0.5,0.699,2);
    drawRectangleHB(4.3,2.5,0.5,0.699,2);
    drawRectangleV1(4.3,0,0.5,2,2.5);
    drawRectangleV1(5,0,0.5,2,2.5);
    drawRectangleV2(4.3,0,0.5,2.5,0.699);
    drawRectangleV2(4.3,0,2.5,2.5,0.699);
}

void drawLit(){
    glColor3f(0.5,0.5,0.5);
    drawRectangleHB(-2.3,0.5,-2,1.5,2.5);
    drawRectangleHB(-2.3,0,-2,1.5,2.5);
    drawRectangleV1(-2.3,0,-2,2.5,0.5);
    drawRectangleV1(-0.8,0,-2,2.5,0.5);
    drawRectangleV2(-2.3,0,0.5,0.5,1.5);
    glColor3f(0.3,0,0.5);
    drawRectangleHB(-2.3,0.5111,-2,1.5,2.5);
    drawRectangleV1(-2.30001,0.2,-2,2.5,0.3);
    drawRectangleV1(-0.79999,0.2,-2,2.5,0.3);
}

void drawCommode(){
    glColor3f(0.5,0.5,0.5);
    drawRectangleHB(-2.9,0.001,-2,0.5,0.4);
    drawRectangleV1(-2.9,0,-2,0.4,0.4);
    drawRectangleV1(-2.4,0,-2,0.4,0.4);    
    drawRectangleHB(-2.9,0.4,-2,0.5,0.4);
    glColor3f(0.3,0.3,0.3);
    drawRectangleV2(-2.9,0,-2,0.4,0.5);
}

void drawCommode2(){

    glColor3f(0.5,0.5,0.5);
    drawRectangleHB(-0.7,0.001,-2,0.5,0.4);
    drawRectangleHB(-0.7,0.4,-2,0.5,0.4);
    drawRectangleV1(-0.7,0,-2,0.4,0.4);
    drawRectangleV1(-0.2,0,-2,0.4,0.4); 
    glColor3f(0.3,0.3,0.3);
    drawRectangleV2(-0.7,0,-2,0.4,0.5);
}

void drawConsole(){
    glColor3f(0.5,0.5,0.5);
    drawRectangleHB(-2.7,0.5,2.3,2,0.6);
    drawRectangleHB(-2.7,0.001,2.3,2,0.6);
    drawRectangleV1(-2.7,0,2.3,0.6,0.6);
    drawRectangleV1(-0.7,0,2.3,0.6,0.6);
}

void drawMeuble(){
    glColor3f(0.5,0.5,0.5);
    drawRectangleV1(0.01,0,0,0.8,0.8);
    drawRectangleV1(0.8,0,0,0.8,0.8);
    drawRectangleV2(0,0,0,0.8,0.8);
    drawRectangleV2(0,0,0.8,0.8,0.8);
    drawRectangleHB(0,0.8,0,0.8,0.8);
}