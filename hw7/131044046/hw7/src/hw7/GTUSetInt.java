/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

public interface GTUSetInt<T> {

    public class GTUIterator<T> {

        private int sayac = 0;
        private final T[] setMapArray;

        public GTUIterator(T[] gelen,int i) {
            setMapArray = gelen;
            sayac=i;
        }

        public GTUIterator(T value) {
            T[] tempArray;
            tempArray = (T[]) new Object[1];
            tempArray[0] = value;
            setMapArray = tempArray;
        }

        public boolean hasPrevious() {
            if (sayac >= 0) {
                return true;
            } else {
                return false;
            }
        }

        public boolean hasNext() {
            if (sayac < setMapArray.length && sayac >= 0 && setMapArray[sayac]!=null) {
                return true;
            } else {
                return false;
            }
        }

        public T previous() {
            int temp;
            temp = sayac--;
            return setMapArray[temp];
        }

        public T next() {
            int temp;
            temp = sayac++;
            return setMapArray[temp];

        }
    }

    /**
     * empty methodu kumenin bos olup olmadigini gösterir.
     *
     * @return Bos ise true , dolu ise false dondurur
     */
    public boolean empty();

    /**
     * size methodu kullanilan alani dondurur
     *
     * @return used kullanilan alani gosterir
     */
    public int size();

    /**
     * maxsize fonksiyonu kumenin maximum dolma kapassitesini dondrur
     *
     * @return max kumenin alabilecegi maximum sayi
     */
    public int maxsize();

    /**
     * insert methodu eklenmek istenen degeri kumeye ekler
     *
     * @param val eklenmek istenen deger
     * @throws java.lang.Exception ayni eleman eklenirse hata verir
     */
    public void insert(T val) throws Exception;

    /**
     * erase methodu silinmek istenen degeri kumeden siler
     *
     * @param position silinmek istenen deger
     */
    public void erase(Object position);

    /**
     * clear methodu kumeyi tamamen siler
     *
     */
    public void clear();

    /**
     * find methodu girilen elemanin bulundugu addresi dondurur aranan degerin
     * konumunu iterator olarak dondurur
     *
     * @param val aranmak istenen deger
     * @return findIndex bulunan konumu iterator olarak gosterir
     */
    public GTUIterator find(Object val);

    /**
     * count methodu aranmak istenen degerin kumede olup olmadigini gosterir
     *
     * @param val aranmak istenen deger
     * @return aranmak istenen deger kumede var mi yok mu
     */
    public int count(T val);

    /**
     * begin methodu kumenin baslangicin konumunu return eder
     *
     * @return beginIndex setin baslangic konumunu gosterir
     */
    public GTUIterator begin();

    /**
     * end methodu kumenin son konumunu return eder
     *
     * @return endIndex kumenin son elemaninin konumunu gosterir
     */
    public GTUIterator end();

    public GTUSet<T> intersection(GTUSet<T> gelen) throws Exception;
}
