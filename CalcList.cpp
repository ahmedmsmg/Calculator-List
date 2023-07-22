// Name: Ahmed Ghoneim
//Project 1: Linked List Calculator
// Instructions: 
// The calculator will be able to perform addition, subtraction, multiplication, and division. 
//The calculator will keep a running total of the operations completed, the number of operations completed, 
//and what those operations were. The calculator will also have an "undo" function for removing the last
// operation. The calculator will also be able to
// output a string of the operations completed so far with fixed precision.

#include "CalcList.hpp"

CalcList::CalcList() :CalcListInterface() {       //Constructor
	head = new newNode;
	head->noperation = ADDITION;
	head->noperand = 0.0;
	head->ntotal = 0.0;
	head->next = head;
}


void CalcList::add_node(const double& val) {  
	++counter;
	newNode* prime = new newNode; 

	prime->next = nullptr;
	prime->ntotal = 0.0;
	prime->noperand = 0.0;
	prime->noperation = ADDITION;

	if (head == nullptr) { 
		prime->ntotal = val;
		head = prime;
		head->next = prime;
	}
	else { 
		prime->next = head->next;
		prime->ntotal = head->next->ntotal;
		head->next = prime;
	}
}

double CalcList::total() const{              
	return head->next->ntotal; 
}


void CalcList::newOperation(const FUNCTIONS func, const double operand) {

	add_node(0); 
	
	switch (func) { 
	case ADDITION:
		head->next->noperation = ADDITION;
		head->next->noperand = operand;
		head->next->ntotal += operand;
		break;
	case SUBTRACTION:
		head->next->noperation = SUBTRACTION;
		head->next->noperand = operand;
		head->next->ntotal -= operand;
		break;
	case MULTIPLICATION:
		head->next->noperation = MULTIPLICATION;
		head->next->noperand = operand;
		head->next->ntotal *= operand;
		break;
	case DIVISION: 
        if (operand== 0) { 
            removeLastOperation();
            throw std::invalid_argument("Dividing by zero is impossible!");

		}
		else if (operand >= 0 && operand < 1.00) { 
		    removeLastOperation();
		}
		else {
			head->next->noperation = DIVISION;
			head->next->noperand = operand;
			head->next->ntotal /= operand;
			break; 
		}
	}
}



void CalcList::removeLastOperation() { 
	if (head == NULL) { throw ("Not Valid.");  }
	else {
		--counter; 
		newNode* prev = head->next; 
		if (prev == head) {throw std::invalid_argument("No Nodes"); } 
		else { 
			head->next = prev->next;  
		}
		delete prev; 
	}
}



std::string CalcList::toString(unsigned short precision) const {
	
	std::stringstream ss; 
	std::string to_string = ""; 
	int temp_counter = counter; 
	newNode* ptr = new newNode; 
	ptr = head->next;

	ss.precision(precision); 
	
	while(ptr->ntotal != 0){ 
		ss << temp_counter << ": "; 

		ss << std::fixed << ptr->next->ntotal; 

		if (ptr->noperation == ADDITION) {
			ss << "+";
		}
		else if (ptr->noperation == SUBTRACTION) {
			ss << "-";
		}
		else if (ptr->noperation == MULTIPLICATION) {
			ss << "*";
		}
		else if (ptr->noperation == DIVISION) {
			ss << "/";
		}
		ss << ptr->noperand;
		ss << "=";
		ss << ptr->ntotal; 
		ss << std::endl;
		
		ptr = ptr->next;
		--temp_counter;
	}
	to_string = ss.str();
	return to_string;
}
