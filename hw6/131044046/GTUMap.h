#ifndef GTUMAP_H
#define GTUMAP_H
#include <utility>

#include "GTUSet.h"
#include "Exception.h"
namespace bengiSpace {

    template <class K, class V>
    class GTUMap : public GTUSet<pair<K, V>>
    {


        public:
        GTUMap();
        V& operator[](const K & k);

    };

}
#endif /* GTUMAP_H */

