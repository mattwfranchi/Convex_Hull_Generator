//
// Created by Matt on 2/28/2020.
//

#ifndef A2_CILLI_H
#define A2_CILLI_H

#include <iostream>
#include <cstdio>
#include <cmath>

struct CNode {
    int val;
    CNode *forward;
    CNode *behind;

    CNode(int v) : val(v), forward(nullptr), behind(nullptr) {}

    CNode(int v, CNode *f, CNode *b) : val(v), forward(f), behind(b) {}

};


class Cilli {
private:
    CNode *handle;

public:
    /** part one **/
    Cilli();

    void insertItem(int v);

    void dumpForwards() const;

    void dumpBackwards() const;

    /** part two **/
    ~Cilli();

    void moveHandleForward();

    void moveHandleBack();

    int getValAtHandle() const;

    void deleteItem();


};


#endif //A2_CILLI_H
