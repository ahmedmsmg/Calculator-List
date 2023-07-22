

#ifndef CALCLIST_H
#define CALCLIST_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "CalcListInterface.hpp"

class newNode {

    friend class CalcList;
    newNode* next;
    FUNCTIONS noperation;
    double ntotal;
    double noperand;
};

class CalcList: public CalcListInterface
{
private:
    newNode* head;
public:
    void add_node(const double& val);
    int counter = 0;


    CalcList();

    double total() const;
    void newOperation(const FUNCTIONS func, const double operand); 
    void removeLastOperation();
    std::string toString(unsigned short precision) const;
};
#endif