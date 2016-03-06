 //
// Created by Omar Shaikh on 2/23/16.
//

#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H
/** Header file for the class Triangle. */

#include <vector>
#include <cmath>
#include <iostream>
#include "triangle_interface.h"


using namespace std;

template<class itemType>
class Triangle : virtual public triangleInterface<itemType> {

    /*TODO - Write your code here*/
private:
    itemType s1,s2,s3;
public:
    Triangle(){
        s1=(itemType)1;
        s2=(itemType)1;
        s3=(itemType)1;
    }
    Triangle(const itemType &a,const itemType &b,const itemType &c){
        s1=a;
        s2=b;
        s3=c;
    }
    /** Sets or modifies the sides of this triangle. Ensures that the new sides form a triangle. */
    virtual void setSides(itemType newSide1, itemType newSide2, itemType newSide3) {
        s1=newSide1;
        s2=newSide2;
        s3=newSide3;

    }

    /** Gets the three sides of this triangle.
     * @return A vector containing the values of the sides. */
    virtual std::vector<itemType> getSides()const{
        vector<itemType> sides;
        sides.reserve(3);
        sides.push_back(s1);
        sides.push_back(s2);
        sides.push_back(s3);
        return sides;
    }

    /** Computes the area of this triangle. @return This triangle's area. */
    virtual itemType getArea()const{
        itemType area,s;
        s=(s1+s2+s3)/2;
        area=(itemType)sqrt(s*(s-s1)*(s-s2)*(s-s3));
        return area;
    }

    /** Computes the perimeter of this triangle. @return This triangle's perimeter. */
    virtual itemType getPerimeter()const{
        itemType p=s1+s2+s3;
        return p;
    }

    /** @return True if this triangle is a right triangle. */
    virtual bool isRightTriangle()const{
        double a[3]{0.0,0.0,0.0};
        double s;
        a[0]=(double)s1;
        a[1]=(double)s2;
        a[2]=(double)s3;
        for (int i = 0; i < 2; i++) {

            if(a[i]>a[i+1]){
                s=a[i+1];
                a[i+1]=a[i];
                a[i]=s;
            }
        }

        return ((a[2] * a[2]) == (a[0] * a[0] + a[1] * a[1]));
    }

    /** @return True if this triangle is an equilateral triangle. */
    virtual bool isEquilateral()const{
        return (s1==s2 &&s2==s3);
    }

    /** @return True if this triangle is an isosceles triangle. */
    virtual bool isIsosceles()const{
        return (s1==s2 || s2==s3 || s1==s3);
    }
};


#endif //HW3_TRIANGLE_H
