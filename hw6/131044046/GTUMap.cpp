#include "GTUMap.h"
namespace bengiSpace{
template<class K, class V>
GTUMap<K, V>::GTUMap() {

}

template<class K, class V>
V& GTUMap<K, V>::operator[](const K& k) {
    int sayac = 0;
    for (int i = 0; i < GTUSet<pair < K, V>> ::used; ++i) {
        if (GTUSet<pair < K, V>> ::mySet.get()[i].first == k)
            sayac = 1;
        if (sayac == 1)
            return GTUSet<pair < K, V>>::mySet.get()[i].second;
    }
}
}