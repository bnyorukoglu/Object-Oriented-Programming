
#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include <iostream>
#include <utility>
#include <memory>
#include "Exception.h"
using namespace std;
template <class T>

class GTUIterator {
        public:

        GTUIterator() {}
        bool operator==(GTUIterator right);
        GTUIterator operator--(int); // postfix it++ 
        GTUIterator& operator--(); // prefix it++ 
        GTUIterator operator++(int); // postfix it++ 
        GTUIterator& operator++(); // prefix it++ 
        GTUIterator& operator=(const GTUIterator &value);
        //reference operator*();
        //pointer operator->();
        private:
         shared_ptr<T> data;

};

#endif /* GTUITERATOR_H */

