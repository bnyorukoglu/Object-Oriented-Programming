#ifndef GTUSETBASE_H
#define GTUSETBASE_H
#include <iostream>
#include <utility>
#include <memory>
#include "Exception.h"

using namespace std;
namespace bengiSpace{
    

template <class T>
class GTUSetBase {
public:

    class GTUIterator {
    public:
        GTUIterator(shared_ptr<T>& ptr);
        GTUIterator(T variable);
        GTUIterator(T* variable){ myIterator= variable;}
        bool operator==(GTUIterator right);
        bool operator!=(GTUIterator right);
        GTUIterator& operator--(int); // postfix it++ 
        GTUIterator& operator--(); // prefix it++ 
        GTUIterator& operator++(int); // postfix it++ 
        GTUIterator& operator++(); // prefix it++ 
        GTUIterator& operator=(const GTUIterator &value);
        inline T& operator*() { return *myIterator; }
        inline T* operator->() { return myIterator; }
    private:
        T* myIterator;
    };

    GTUSetBase();
    virtual bool empty() const = 0;
    virtual unsigned int size() const = 0;
    virtual unsigned int max_size() const = 0;
    virtual void insert(const T& val) = 0;
    virtual void erase(const T& position) = 0;
    virtual void clear() = 0;
    virtual GTUIterator find(const T& val) = 0;
    virtual unsigned int count(const T& val) const = 0;
    virtual GTUIterator begin() = 0;
    virtual GTUIterator end() = 0;
};

}
#endif /* GTUSETBASE_H */

