/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

import javafx.util.Pair;

public class GTUMap<K, V> extends GTUSet<javafx.util.Pair<K, V>> {


    /**
     *
     * GTUMap one parameter constructor
     *
     * @param gosterge Pair tipinde kume
     */
    public GTUMap(Class<Pair<K, V>[]> gosterge) {
        super(gosterge);
    }

    /**
     * find methodu aranan degerin indexini dondurur
     *
     * @param val bulunmak istenen deger
     * @return kümede bulunmak istenen degerin indexini dondurur
     */
    @Override
    public GTUIterator<Pair<K, V>> find(Object val) {

        GTUSetInt.GTUIterator<Pair<K, V>> findIndex = null;
        for (int i = 0; i < used; ++i) {
            if (mySet[i].getKey() == val) {
                findIndex = new GTUSetInt.GTUIterator<>(mySet,i);
            }
        }
        return findIndex;

    }

    /**
     * erase methodu silinmek istenen degeri kümeden siler
     *
     * @param position silinmek istenen deger
     *
     *
     */
    @Override
    public void erase(Object position) {
        Pair<K, V>[] temp = (Pair<K, V>[]) new Object[max];
        int sayac = 0;
        int buldum = 0;

        for (int i = 0; i < used; ++i) {
            sayac++;
            if (mySet[i].getValue() == position) {
                buldum = sayac;
            }
        }

        for (int i = 0; i != buldum; ++i) {

            temp[i] = mySet[i];
        }

        for (int i = buldum - 1; i < used; ++i) {
            temp[i] = mySet[i + 1];
        }
        --used;
        mySet = temp;
    }

    /**
     * at methodu girilen key degerinin karşılıgındaki valuesunu verir
     *
     * @param k mapin key degeri
     * @return key degerinin karsiligindaki valuedur
     */
    public V at(K k) {
        Pair<K, V> pair1;
        for (int i = 0; i < used; ++i) {
            pair1 = (Pair) mySet[i];
            if (k.equals(pair1.getKey())) {
                return pair1.getValue();
            }
        }
        return null;
    }

    public GTUMap<K, V> intersection(GTUMap<K, V> gelen) throws Exception {
        GTUMap<K, V> kesisim;
        kesisim = new GTUMap(Pair[].class);
        for (int i = 0; i < size(); ++i) {
            for (int j = 0; j < gelen.size(); ++j) {
                if (mySet[i].getKey() == gelen.mySet[j].getKey()) {
                    kesisim.insert(mySet[i]);
                }
            }
        }
        return kesisim;
    }
}
