#include "GTUSet.h"
#include "GTUIterator.h"
namespace bengiSpace {

    template<class T>
    GTUSet<T>::GTUSet() {

        used = 0;
        max = 9999999;
        mySet.reset(new T[max], array_deleter<T>());

    }

    template<class T>
    typename GTUSetBase<T>::GTUIterator GTUSet<T>::begin() {

        return typename GTUSetBase<T>::GTUIterator(mySet);

    }

    template<class T>
    bool GTUSet<T>::empty() const {
        if (used == 0) {

            return 1;
        } else
            return 0;
    }

    template<class T>
    unsigned int GTUSet<T>::size() const {

        return used;

    }

    template<class T>
    unsigned int GTUSet<T>::max_size() const {

        int max = 999999;
        return max;
    }

    template<class T>
    void GTUSet<T>::insert(const T& val) throw (Exception) {
        
         for (int i = 0; i < used; ++i) {
           

                if (mySet.get()[i]== val) {

                    throw Exception("the value you want to add already exist !!!");
                }
            
        }
        
        
        mySet.get()[used] = val;
        
        used++;

        for (int i = 1; i < used; ++i) {
            for (int j = 0; j < used - 1; ++j) {

                if (mySet.get()[j] > mySet.get()[i]) {

                    T temp = mySet.get()[j];
                    mySet.get()[j] = mySet.get()[i];
                    mySet.get()[i] = temp;
                }
            }
        }
    }

    template<class T>
    void GTUSet<T>::erase(const T& position) {
        shared_ptr<T> temp;
        temp.reset(new T[max], array_deleter<T>());
        int sayac = 0;
        int buldum = 0;

        for (int i = 0; i < used; ++i) {
            sayac++;
            if (mySet.get()[i] == position)
                buldum = sayac;
        }

        for (int i = 0; i != buldum; ++i) {

            temp.get()[i] = mySet.get()[i];
        }

        for (int i = buldum - 1; i < used; ++i) {
            temp.get()[i] = mySet.get()[i + 1];
        }
        --used;
        mySet = temp;
       
    }

    template<class T>
    void GTUSet<T>::clear() {

        mySet.reset(new T[max], array_deleter<T>());
        used = 0;

    }

    template<class T>
    typename GTUSetBase<T>::GTUIterator GTUSet<T>::find(const T& val) {
        for (int i = 0; i < used; ++i) {

            if (mySet.get()[i] == val)
                return typename GTUSetBase<T>::GTUIterator(&mySet.get()[i]);
        }

    }

    template<class T>
    unsigned int GTUSet<T>::count(const T& val) const {
        for (int i = 0; i < used; ++i) {

            if (mySet.get()[i] == val)
                return true;
        }

        return false;
    }

    template<class T>
    typename GTUSetBase<T>::GTUIterator GTUSet<T>::end() {

        return typename GTUSetBase<T>::GTUIterator(&mySet.get()[used]);

    }



}