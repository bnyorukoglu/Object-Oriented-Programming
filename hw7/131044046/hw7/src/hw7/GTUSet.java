package hw7;

import java.lang.reflect.Array;

public class GTUSet<T> implements GTUSetInt<T> {

    protected T[] mySet;
    protected int used;
    protected int max;

    public GTUSet() {
        used = 0;
        max = 999999;
        mySet = (T[]) new Object[max];
    }

    /**
     * GTUSet one parameter constructor
     *
     * @param gosterge GTUSet tipinde kume
     *
     */
    public GTUSet(Class<T[]> gosterge) {
        used = 0;
        max = 999999;
        mySet = gosterge.cast(Array.newInstance(gosterge.getComponentType(), max));
    }

    /**
     * empty methodu kumenin bos olup olmadigini gösterir.
     *
     * @return Bos ise true , dolu ise false dondurur
     */
    @Override
    public boolean empty() {

        if (used == 0) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * size methodu kullanilan alani dondurur
     *
     * @return used kullanilan alani gosterir
     */
    @Override
    public int size() {
        return used;
    }

    /**
     * maxsize fonksiyonu kumenin maximum dolma kapassitesini dondrur
     *
     * @return max kumenin alabilecegi maximum sayi
     */
    @Override
    public int maxsize() {
        return max;
    }

    /**
     * insert methodu eklenmek istenen degeri kumeye ekler
     *
     * @param val eklenmek istenen deger
     */
    @Override
    public void insert(T val) throws Exception {

        if (used >= max) {

            T[] tempArray = (T[]) new Object[used];

            for (int i = 0; i < used; i++) {
                tempArray[i] = mySet[i];
            }

            max = max * 2;

            mySet = null;

            T[] mySet = (T[]) new Object[max];

            for (int i = 0; i < used; i++) {

                mySet[i] = tempArray[i];
            }

        }

        for (int i = 0; i < used; ++i) {

            if (mySet[i] == val) {

                throw new Exception("the value you want to add already exist !!!");
            }

        }

        mySet[used] = val;

        used++;

        for (int i = 1; i < used; ++i) {
            for (int j = 0; j < used - 1; ++j) {

                if (mySet[j].equals(mySet[i])) {
                    T temp = mySet[j];
                    mySet[j] = mySet[i];
                    mySet[i] = temp;
                }
            }
        }
    }

    /**
     * erase methodu silinmek istenen degeri kumeden siler
     *
     * @param position silinmek istenen deger
     */
    @Override
    public void erase(Object position) {

        T[] temp = (T[]) new Object[max];
        int sayac = 0;
        int buldum = 0;

        for (int i = 0; i < used; ++i) {
            sayac++;
            if (mySet[i] == position) {
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
     * clear methodu kumeyi tamamen siler
     *
     */
    @Override
    public void clear() {

        used = 0;
        mySet = null;
    }

    /**
     * count methodu aranmak istenen degerin kumede olup olmadigini gosterir
     *
     * @param val aranmak istenen deger
     * @return aranmak istenen deger kumede var mi yok mu
     */
    @Override
    public int count(T val) {
        for (int i = 0; i < used; ++i) {

            if (mySet[i] == val) {
                return 1;
            }
        }

        return 0;
    }

    /**
     * find methodu girilen elemanin bulundugu addresi dondurur aranan degerin
     * konumunu iterator olarak dondurur
     *
     * @param val aranmak istenen deger
     * @return findIndex bulunan konumu iterator olarak gosterir
     */
    @Override
    public GTUSetInt.GTUIterator<T> find(Object val) {
        GTUSetInt.GTUIterator<T> findIndex = null;
        for (int i = 0; i < used; ++i) {
            if (mySet[i] == val) {
                findIndex = new GTUSetInt.GTUIterator<>(mySet,i);
            }
        }
        return findIndex;
    }

    /**
     * begin methodu kumenin baslangicin konumunu return eder
     *
     * @return beginIndex setin baslangic konumunu gosterir
     */
    @Override
    public GTUSetInt.GTUIterator<T> begin() {
        GTUSetInt.GTUIterator<T> beginIndex;
        beginIndex = new GTUSetInt.GTUIterator<>(mySet,0);
        return beginIndex;
    }

    /**
     * end methodu kumenin son konumunu return eder
     *
     * @return endIndex kumenin son elemaninin konumunu gosterir
     */
    @Override
    public GTUSetInt.GTUIterator<T> end() {
        GTUSetInt.GTUIterator<T> endIndex;
        endIndex = new GTUSetInt.GTUIterator<>(mySet,size()-1);
        return endIndex;
    }

    /**
     *
     * @param gelen
     * @return
     * @throws Exception
     */
 
    @Override
    public GTUSet<T> intersection(GTUSet<T> gelen) throws Exception {

        GTUSet<T> kesisim = new GTUSet<>();

        for (int i = 0; i < size(); ++i) {
            for (int j = 0; j < gelen.size(); ++j) {
                if (mySet[i] == gelen.mySet[j]) {
                    kesisim.insert(mySet[i]);
                }
            }
        }
        return kesisim;
    }
}
