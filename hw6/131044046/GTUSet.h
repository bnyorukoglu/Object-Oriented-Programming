#ifndef GTUSET_H
#define GTUSET_H
#include "GTUSetBase.h"
#include "Exception.h"
#include "GTUSetBase.cpp"
#include <memory>

namespace bengiSpace{
    
template< typename T >
struct array_deleter {

    void operator()(T const * p) {
        delete[] p;
    }
};

template <class T>
class GTUSet : public GTUSetBase<T> {
public:

    GTUSet();
    virtual bool empty() const override;
    virtual unsigned int size() const override;
    virtual unsigned int max_size() const override;
    virtual void insert(const T& val) throw (Exception) override;
    virtual void erase(const T& position) override;
    virtual void clear() override;
    virtual typename GTUSetBase<T>::GTUIterator find(const T& val) override;
    virtual unsigned int count(const T& val) const override;
    virtual typename GTUSetBase<T>::GTUIterator begin() override;
    virtual typename GTUSetBase<T>::GTUIterator end() override;
protected:
    
    shared_ptr<T> mySet;
    int max;
    int used;
};
}
#endif /* GTUSET_H */

