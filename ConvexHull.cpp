// Matt Franchi // CPSC 2120 // Spring 2020
// Project 2 : ConvexHull.cpp
// Program Description: Finds the convex hull of a collection of points, utilizing an iterative algorithm

/**
 * ASSUMPTIONS:
 *  Points are given in increasing x-coordinate order
 *  All points are distinct
 *  No possibility of tie in slope calculation
 *  Given at least 3 points
 *
 * ENSURES:
 * Convex Hull of the given points is correctly generated
 * Points of the convex hull are printed out in clockwise order
 */

// just a skeleton - Goddard - 2020
#include <iostream>
#include <vector>
using namespace std;
#include "Cilli.h"
#include "matplotlibcpp.h"


struct Point
{
    double xx,yy;
    Point(double x,double y) : xx(x), yy(y) { }
};

double slope(Point &A, Point&B)
{
    return (A.yy-B.yy)/(A.xx-B.xx);
}

ostream & operator<<( ostream & out, const Point & P)
{
    out << "(" << P.xx << "," << P.yy << ")";
    return out;
}

void getHull(vector<Point> list )
{
    Cilli C;

    // Handles separate processing needed for first two points
    C.insertItem( 0 );
    C.insertItem( 1);
    // Handles processing for any remaining points
    for(unsigned int adder=2; adder<list.size(); adder++)
    {

        int start = C.getValAtHandle( );
        int S=start;
        int L=start;
        double minSlope = slope( list[adder], list[start] );
        double maxSlope = slope( list[adder], list[start] );

        // update S to index of point of smallest slope
        // update L to index of point of largest slope
        for(unsigned int n = 0; n < adder; n++)
        {
            double tempSlope = slope(list[n],list[adder]);
            S = tempSlope < minSlope ? n : S;
            minSlope = tempSlope < minSlope ? tempSlope : minSlope;
            L = tempSlope > maxSlope ? n : L;
            maxSlope = tempSlope > maxSlope ? tempSlope : maxSlope;
        }



        // move handle to node L
        while(C.getValAtHandle()!=L){ C.moveHandleBack(); }
        // delete nodes strictly between L and S, leaving handle at S

        C.moveHandleForward();
        int afterHandleVal = C.getValAtHandle();
        C.moveHandleBack();
        while(afterHandleVal != S)
        {
            C.moveHandleForward();
            C.moveHandleForward();
            afterHandleVal = C.getValAtHandle();
            C.moveHandleBack();
            C.deleteItem();

        }
        // add item at handle = S
        C.insertItem( adder );
        // print out answer at each stage
        C.dumpForwards();


    }

    // print out answer
    cout << "The Convex Hull is: ";
    C.moveHandleForward();
    int lastVal = C.getValAtHandle();
    C.moveHandleBack();
    for(int n = C.getValAtHandle(); n != lastVal; C.moveHandleBack(), n = C.getValAtHandle())
    {
        cout << list[n] << " ";
    }
    cout << list[lastVal];
    cout << endl;


}

int main ( )
{
    // INTRO OUTPUT
    cout << "Matt Franchi / March 6 2020 / Project 2" << endl;
    cout << "Calculates the Convex Hull of a set of 3+ points." << endl << "PROGRAM START";


    int N;
    cin >> N; 
    if(N < 3)
    {
        cout << "You need at least 3 points to generate a Convex Hull. Exiting..." << endl;
        return 1;
    }
   
    int x,y;
    vector<Point> list;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        list.emplace_back(x,y);
    }
    getHull(list );
}

