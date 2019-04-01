package hw7;

import javafx.util.Pair;

public class mainTester {

    public static void main(String[] args) throws Exception {
        try {
            GTUSet<Integer> myGtuSet = new GTUSet<>(Integer[].class);
            GTUSet<Integer> sGtuSet = new GTUSet<>(Integer[].class);

            GTUSet<Integer> kesisim = new GTUSet<>(Integer[].class);

            GTUMap<Integer, Integer> firstmap = new GTUMap(Pair[].class);
            GTUMap<Integer, Integer> secondmap = new GTUMap(Pair[].class);
            GTUMap<Integer, Integer> thirdmap = new GTUMap(Pair[].class);

            GTUMap<Integer, Integer> kesisim_map = new GTUMap(Pair[].class);
            Pair<Integer, Integer> a = new Pair(1, 1);
            Pair<Integer, Integer> b = new Pair(2, 3);
            Pair<Integer, Integer> c = new Pair(4, 5);

            myGtuSet.insert(5);
            myGtuSet.insert(4);
            myGtuSet.insert(3);
            myGtuSet.insert(2);

            sGtuSet.insert(25);
            sGtuSet.insert(4);
            sGtuSet.insert(3);
            sGtuSet.insert(12);

            firstmap.insert(a);
            firstmap.insert(b);
            firstmap.insert(c);

            secondmap.insert(b);
            secondmap.insert(c);

            System.out.println("set size:    " + myGtuSet.size());
            System.out.println("set maxsize: " + myGtuSet.maxsize());

            if (myGtuSet.count(5) == 1) {
                System.out.println("5 bulundu");
            } else {
                System.out.println("5 bulunamadı");
            }

            if (myGtuSet.empty()) {
                System.out.println("Set boştur");

            } else {
                System.out.println("Set boş değildir");

            }

            GTUSetInt.GTUIterator<Integer> it_1 = sGtuSet.begin();

            System.out.println("Iterator set begin: " + it_1.next());

            GTUSetInt.GTUIterator<Integer> it_2 = myGtuSet.find(5);

            System.out.println("Iterator set find: " + it_2.next());

            GTUSetInt.GTUIterator<Integer> it_3 = myGtuSet.end();

            System.out.println("Iterator set end: " + it_3.previous());

            System.out.println("map size:    " + firstmap.size());
            System.out.println("map maxsize: " + firstmap.maxsize());

            if (firstmap.count(a) == 1) {
                System.out.println("Pair(1,1) bulundu");
            } else {
                System.out.println("Pair(1,1) bulunamadı");
            }

            if (thirdmap.empty()) {
                System.out.println("Map boştur");

            } else {
                System.out.println("Map boş değildir");

            }
            GTUSetInt.GTUIterator<Pair<Integer, Integer>> mit_1 = firstmap.begin();

            System.out.println("Iterator map begin: " + mit_1.next());

            GTUSetInt.GTUIterator<Pair<Integer, Integer>> mit_2 = firstmap.find(4);

            System.out.println("Iterator map find: " + mit_2.next());

            GTUSetInt.GTUIterator<Pair<Integer, Integer>> mit_3 = firstmap.end();

            System.out.println("Iterator map end: " + mit_3.next());

            System.out.println("Map Intersection");
            kesisim_map = firstmap.intersection(secondmap);
            GTUSetInt.GTUIterator<Pair<Integer, Integer>> kit_1 = kesisim_map.begin();

            while (kit_1.hasNext()) {
                System.out.println(kit_1.next());
            }
            System.out.println("Set Intersection");

            kesisim = myGtuSet.intersection(sGtuSet);
            GTUSetInt.GTUIterator<Integer> kit_2 = kesisim.begin();
            while (kit_2.hasNext()) {
                System.out.println(kit_2.next());
            }
        } catch (Exception e) {

            System.out.println(e);

        }

    }
}
