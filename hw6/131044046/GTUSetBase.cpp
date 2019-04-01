#include "GTUSetBase.h"
namespace bengiSpace{
template<class T>
GTUSetBase<T>::GTUSetBase() {

}

template <class T>
GTUSetBase<T>::GTUIterator::GTUIterator(shared_ptr<T>& ptr) {

    myIterator = ptr.get();

}
template <class T>
GTUSetBase<T>::GTUIterator::GTUIterator(T variable) {

    myIterator = &variable;

}

template <class T>
typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator++(int) {
    GTUIterator temp = *this;
    myIterator++;
    return temp;
}

template <class T>
typename GTUSetBase<T>::GTUIterator & GTUSetBase<T>::GTUIterator::operator--(int) {
    GTUIterator temp = *this;
    myIterator--;
    return temp;
}

template <class T>
typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator=(const GTUIterator& value) {
        this->myIterator = value;
        return *this;
}

template <class T>
typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator++() {
    myIterator++;
    return *this;
}

template <class T>
typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator--() {
  myIterator--;
    return *this;
}

template <class T>
bool GTUSetBase<T>::GTUIterator::operator==(GTUIterator right) {
    return myIterator == right.myIterator;
}



template <class T>
bool GTUSetBase<T>::GTUIterator::operator!=(GTUIterator right) {
    return myIterator != right.myIterator;
}

}