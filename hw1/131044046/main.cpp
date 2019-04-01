//BENGI YORUKOGLU
//131044046
//C++ HOMEWORK 1
#include <iostream>
using namespace std;
//Bu fonksiyon tahtanın güncel halini bastırmayı saglıyor
void printBoard(char *board, int size);
//Girilen sutunu,size'ı ve blgisyarla mı yoksa karsilikli mi oynanacagini
//belirten harfi parametre olarak alir.Eger sutun ve size da bir sıkıntı yoksa 
//hareket edebilecegi bir alansa oyun sırasında olan X tahtaya yerlestirilir.
int movPlayerX(char *array, char sutun, int size, char harf);
//Girilen sutunu,size'ı ve blgisyarla mı yoksa karsilikli mi oynanacagini
//belirten harfi parametre olarak alir.Eger sutun ve size da bir sıkıntı yoksa 
//hareket edebilecegi bir alansa oyun sırasında olan X tahtaya yerlestirilir.
int movPlayerO(char *array, char sutun, int size, char harf);
//Bu fonksiyon girilen sutunun ve size'ın gecerli olup olmadigina bakar.
//Gecerli ve oynanabilecek bir pozisyonsa fonksiyon 1,gecersiz ise 0 dondurur.
int isValid(char sutun, int size, char harf);
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Yatay sırada
//ard arda bulunan O sayisini return eder.
int yatayKontrolO(char *array, char sutun, int size, char harf);
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Yatay sırada
//ard arda bulunan X sayisini return eder.
int yatayKontrolX(char *array, char sutun, int size);
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Dikey sırada
//ard arda bulunan X sayisini return eder.
int dikeyKontrolX(char* array, char sutun, int size);
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Dikey sırada
//ard arda bulunan O sayisini return eder.
int dikeyKontrolO(char* array, char sutun, int size, char harf);
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Carpraz sırada
//ard arda bulunan O sayisini return eder.
int caprazKontrollerO(char *array, int satir, char sutun, int size, char harf);
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Carpraz sırada
//ard arda bulunan X sayisini return eder.
int caprazKontrollerX(char *array, int satir, char sutun, int size);
//Hamle yapilmak istenen sutun girildiginde tas bos bulunan satira konur.
//Yerlestirildigi satiri hesaplayan fonksiyon
int satirHesapla(char *array, char sutun, int size);
int movPlayerComputer(char *array, char sutun, int size, int satir, char harf);

int main(int argc, char const *argv[]) {
    //size'ı en fazla 20*20 olacak sekilde belirledigim tek boyutlu array
    char table[400];
    int size, flag = 1, satir = 0;
    char sutun, oyuncuSecimi, secim = 'a';
    int kontrol = 0, kontrol1 = 0, kontrol2 = 0;
    int kazanmaKontrol = 0, kazanmaKontrol2 = 0, kazanmaKontrol3 = 0;
    cout << "Oyun alanının boyutunu giriniz: ";
    cin>>size;
    //Eger size yerine gecersiz bir sey girilirse(harf gibi) hata vermesini
    //sagliyor
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Oyun alanının boyutunu tekrar giriniz: ";
        cin>>size;
    } 
    //girilen size'in saayi degerinin 4 ile 20 arasında olup olmadigina bakar
    //Eger bu aralikta degilse tekrar size ister
    while (size < 3 || size > 20 || size%2!=0) {
        cout << "Oyun alanının boyutunu tekrar giriniz: ";
        cin>>size;
	    while (cin.fail()) {
	        cin.clear();
	        cin.ignore();
	        cout << "Oyun alanının boyutunu tekrar giriniz: ";
	        cin>>size;
	    } 
    }
    cout << "Bilgisar ile oynamak icin : C" << endl;
    cout << "Karşılıklı oynamak için   : P" << endl;
    cout << "Oyun türü seçimi: ";
    cin>>oyuncuSecimi;
   //Eger kucuk a veya kucuk z varsa buyuk harfe cevirir kontrollerin
    //daha kolay yapilabilmesi icin
    if (oyuncuSecimi >= 'a' && oyuncuSecimi <= 'z') {
        oyuncuSecimi = oyuncuSecimi - 32;
    } //istenen karakter haricinde bir secim yaildiysa hata verir ve tekrar ister
    while (!(oyuncuSecimi == 'C' || oyuncuSecimi == 'P')) {
        cout << "Yanlış oyun seçimi tekrar seçim yapınız!" << endl;
        cout << "Bilgisar ile oynamak icin : C" << endl;
        cout << "Karşılıklı oynamak için   : P" << endl;
        cout << "Oyun türü seçimi: ";
        cin>>oyuncuSecimi;

        if (oyuncuSecimi >= 'a' && oyuncuSecimi <= 'z') {
            oyuncuSecimi = oyuncuSecimi - 32;
        }
    }
    for (int i = 0; i < size * size; ++i) {
        table[i] = ' ';
    }
    printBoard(table, size);
    //Buradaki do whileda oyun baslar ve kazanmaKontrol,kazanmaKontrol2,kazanma
    //kontrol3 4ten kucuk oldukca devam eder.yani herhangi istenen bir sekilde
    //yan yana 4 saglanmadikca hicbir oyuncu kazanamaz ve hamle istenir.
    do {
        switch (oyuncuSecimi) {
            case 'C'://Bilgisayar ile oynamak istiyorsak
                if (flag == 1) {//buradaki flag karsilikli oynamayi saglar.
                //X iken 1 ,sira O'ya gectiginde 0 olur
                    //oyuncu oyun alani disinda bir sutun girdiginde tekrar
                    //tekrar soracak
                    do {
                        cout << "Oyuncu X için sütun konumunu girin:";
                        cin>>sutun;
                        if (sutun >= 'A' && sutun <= 'Z') {
                            sutun = sutun + 32;
                        }
                        satir = satirHesapla(table, sutun, size);
                        kontrol1 = movPlayerX(table, sutun, size, oyuncuSecimi);
                        kazanmaKontrol = yatayKontrolX(table, sutun, size);
                        kazanmaKontrol2 = dikeyKontrolX(table, sutun, size);
                        kazanmaKontrol3 = caprazKontrollerX(table, satir, sutun, size);
                    } while (kontrol1 == 0);//yanlis hamle yaparsa dongu tekrar 
		    //doner

                    flag = 0;
                } else if (flag == 0) {//buradaki flag karsilikli oynamayi saglar.
                //X iken 1 ,sira O'ya gectiginde 0 olur
                    do {
                        satir = satirHesapla(table, sutun, size);
                        kontrol2 = movPlayerComputer(table, sutun, size, satir, oyuncuSecimi);

                        for (char sutunDolas = 'a'; sutunDolas < size+97; ++sutunDolas) {
                            kontrol = yatayKontrolO(table, sutunDolas, size, secim);
                            if (kontrol > kazanmaKontrol) {
                                kazanmaKontrol = kontrol;
                            }
                        }
                        for (char sutunDolas = 'a'; sutunDolas < size+97; ++sutunDolas) {
                            kontrol = dikeyKontrolO(table, sutunDolas, size, secim);
                            if (kontrol > kazanmaKontrol2) {
                                kazanmaKontrol2 = kontrol;
                            }
                        }

                        for (int satirDolas = 0; satirDolas < size; ++satirDolas) {
                            for (char sutunDolas = 'a'; sutunDolas < size+97; ++sutunDolas) {
                                kontrol = caprazKontrollerO(table, satirDolas, sutunDolas, size, secim);
                                if (kontrol > kazanmaKontrol3) {
                                    kazanmaKontrol3 = kontrol;
                                }
                            }
                        }
                    } while (kontrol2 == 0);//yanlis hamle yaparsa dongu tekrar
                      //doner
                    flag = 1;
                }
                break;

            case 'P':
                if (flag == 1) {//buradaki flag karsilikli oynamayi saglar.
                //X iken 1 ,sira O'ya gectiginde 0 olur
                    //oyuncu oyun alani disinda bir sutun girdiginde tekrar
                    //tekrar soracak
                    do {
                        cout << "Oyuncu X için sütun konumunu girin:";
                        cin>>sutun;
                        if (sutun >= 'A' && sutun <= 'Z') {
                            sutun = sutun + 32;
                        }
                        satir = satirHesapla(table, sutun, size);
                        kontrol1 = movPlayerX(table, sutun, size, oyuncuSecimi);
                        kazanmaKontrol = yatayKontrolX(table, sutun, size);
                        kazanmaKontrol2 = dikeyKontrolX(table, sutun, size);
                        kazanmaKontrol3 = caprazKontrollerX(table, satir, sutun, size);
                    } while (kontrol1 == 0);//yanlis hamle yaparsa dongu
		    //tekrar doner

                    flag = 0;
                } else if (flag == 0) {//buradaki flag karsilikli oynamayi saglar.
                //X iken 1 ,sira O'ya gectiginde 0 olur
                    do {
                        cout << "Oyuncu O için sütun konumunu girin:";
                        cin>>sutun;
                        //sutun harfi buyuk girilirse kucuk harfe cevirir
                        if (sutun >= 'A' && sutun <= 'Z') {
                            sutun = sutun + 32;
                        }
                        satir = satirHesapla(table, sutun, size);
                        kontrol2 = movPlayerO(table, sutun, size, oyuncuSecimi);

                        kazanmaKontrol = yatayKontrolO(table, sutun, size, oyuncuSecimi);
                        kazanmaKontrol2 = dikeyKontrolO(table, sutun, size, oyuncuSecimi);
                        kazanmaKontrol3 = caprazKontrollerO(table, satir, sutun, size, oyuncuSecimi);
                    } while (kontrol2 == 0);//yanlis hamle yaparsa dongu tekrar
		     //doner
                    flag = 1;
                }
                break;
        }
    } while (kazanmaKontrol < 4 && kazanmaKontrol2 < 4 && kazanmaKontrol3 < 4);
    return 1;
}
//Bu fonksiyon tahtanın güncel halini bastırmayı saglıyor
void printBoard(char *board, int size) {

    int i = size, m;
    int sutun, satir;
    char bas;
    cout << " ";
    for (int a = 0; a < size; ++a) {
        bas = 'a' + a;
        cout << bas << " ";
    }
    cout << endl;
    for (satir = size; satir > 0; --satir) {
        cout << "|";
        for (sutun = 0; sutun < size; ++sutun) {
            m = (size * (size - satir) + sutun);
            cout << *board;
            ++(board);
            if ((m + 1) % size != 0) {
                cout << " ";
            }
        }
        cout << "|";
        cout << endl;
        --i;
    }
}
//Bu fonksiyon girilen sutunun ve size'ın gecerli olup olmadigina bakar.
//Gecerli ve oynanabilecek bir pozisyonsa fonksiyon 1,gecersiz ise 0 dondurur.
int isValid(char sutun, int size, char harf) {
    if (size < 4 || size > 20) {
        if (harf != 'a')
            cerr << "4 ile 20 arasında çift bir sayı giriniz!" << endl;
        return 0;
    }
    if (size % 2 == 1) {
        if (harf != 'a')
            cerr << "Oyun alanının boyutu 4,6,8,10,12,14,16,18,20 bu sayılardan biri olmalıdır" << endl;
        return 0;
    }
    if (size == 4) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 6) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 8) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f'
                || sutun == 'g' || sutun == 'h' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' || sutun == 'G' || sutun == 'H')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 10) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'g' || sutun == 'h' ||
                sutun == 'i' || sutun == 'j' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' || sutun == 'G' || sutun == 'H' || sutun == 'I' || sutun == 'J')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 12) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'g' || sutun == 'h' ||
                sutun == 'i' || sutun == 'j' || sutun == 'k' || sutun == 'l' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' || sutun == 'G' || sutun == 'H' || sutun == 'I' ||
                sutun == 'J' || sutun == 'K' || sutun == 'L')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 14) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'g' || sutun == 'h' || sutun == 'i' || sutun == 'j' || sutun == 'k'
                || sutun == 'l' || sutun == 'm' || sutun == 'n' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' || sutun == 'G' || sutun == 'H' || sutun == 'I' ||
                sutun == 'J' || sutun == 'K' || sutun == 'L' || sutun == 'M' || sutun == 'N')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 16) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'g' || sutun == 'h' || sutun == 'i' || sutun == 'j' || sutun == 'k'
                || sutun == 'l' || sutun == 'm' || sutun == 'n' || sutun == 'o' || sutun == 'p' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' ||
                sutun == 'G' || sutun == 'H' || sutun == 'I' || sutun == 'J' || sutun == 'K' || sutun == 'L' || sutun == 'M' || sutun == 'N' || sutun == 'O' || sutun == 'P')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 18) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'g' || sutun == 'h' || sutun == 'i' || sutun == 'j' || sutun == 'k'
                || sutun == 'l' || sutun == 'm' || sutun == 'n' || sutun == 'o' || sutun == 'p' || sutun == 'r' || sutun == 's' || sutun == 'A' || sutun == 'B' || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' ||
                sutun == 'G' || sutun == 'H' || sutun == 'I' || sutun == 'J' || sutun == 'K' || sutun == 'L' || sutun == 'M' || sutun == 'N' || sutun == 'O' || sutun == 'P' || sutun == 'R' || sutun == 'S')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    } else if (size == 20) {
        if (!(sutun == 'a' || sutun == 'b' || sutun == 'c' || sutun == 'd' || sutun == 'e' || sutun == 'f' || sutun == 'g' || sutun == 'h' || sutun == 'i' || sutun == 'j' || sutun == 'k'
                || sutun == 'l' || sutun == 'm' || sutun == 'n' || sutun == 'o' || sutun == 'p' || sutun == 'r' || sutun == 's' || sutun == 't' || sutun == 'u' || sutun == 'A' || sutun == 'B'
                || sutun == 'C' || sutun == 'D' || sutun == 'E' || sutun == 'F' || sutun == 'G' || sutun == 'H' || sutun == 'I' || sutun == 'J' || sutun == 'K' || sutun == 'L' || sutun == 'M' || sutun == 'N'
                || sutun == 'O' || sutun == 'P' || sutun == 'R' || sutun == 'S' || sutun == 'T' || sutun == 'U')) {
            if (harf != 'a')
                cerr << "Sütun bilgisi yanlış girildi" << endl;
            return 0;
        }
    }
    return 1;
}
//Girilen sutunu,size'ı ve blgisyarla mı yoksa karsilikli mi oynanacagini
//belirten harfi parametre olarak alir.Eger sutun ve size da bir sıkıntı yoksa 
//hareket edebilecegi bir alansa oyun sırasında olan X tahtaya yerlestirilir.
int movPlayerX(char *array, char sutun, int size, char harf) {

    int satir = size + 1, i = size;
    int gidecegi = 0;
    int tut = sutun;
    tut -= 97;//a=0,b=1,c=2...girilen sutunun degerini bulmamızı saglar

    if (isValid(sutun, size, harf)) {
        while (i >= 1) {//BU while dongüsü sutun girildiginde ilk bos bulunan
	//satiri bulmamizi saglar 
            if (array[tut] == ' ') {
                satir = satir - 1;
            }
            tut += size;
            --i;
        }//sutun girildikten sonra gitmesi istenen konum belirlenir.
	//alttaki formul gidilmek istenen konumun arraydeki yerini gosterir
        gidecegi = (size * (size - satir) + (sutun - 97));
        if (array[gidecegi] == ' ') {//gidilmek istenen yer bos ise X konur
            array[gidecegi] = 'X';
            printBoard(array, size);
            return 1;
        } else {//gidilmek istenen yer dolu ise hata verir
            cout << "Girdiğiniz alan dolu baska bir sütun giriniz!" << endl;
            return 0;
        }
    }
    return 0;
}
//Girilen sutunu,size'ı ve blgisyarla mı yoksa karsilikli mi oynanacagini
//belirten harfi parametre olarak alir.Eger sutun ve size da bir sıkıntı yoksa 
//hareket edebilecegi bir alansa oyun sırasında olan O tahtaya yerlestirilir.
int movPlayerO(char *array, char sutun, int size, char harf) {
    int satir = size + 1, i = size;
    int gidecegi = 0;
    int tut = sutun;
    tut -= 97;//a=0,b=1,c=2...girilen sutunun degerini bulmamızı saglar

    if (isValid(sutun, size, harf)) {
        while (i >= 1) {//BU while dongüsü sutun girildiginde ilk bos bulunan
	//satiri bulmamizi saglar 
            if (array[tut] == ' ') {
                satir = satir - 1;
            }
            tut += size;
            --i;
        }//sutun girildikten sonra gitmesi istenen konum belirlenir.
	//alttaki formul gidilmek istenen konumun arraydeki yerini gosterir
        gidecegi = (size * (size - satir) + (sutun - 97));
        if (array[gidecegi] == ' ') {
            array[gidecegi] = 'O';
            printBoard(array, size);
            return 1;
        } else {//gidilmek istenen yer dolu ise hata verir.
	    //Buradaki a benim kendi belirledigim bir harf.
	    //Computera karsi oynandiginda parametreye a geliyor ve asagidaki
	    //masajin engellenmesi saglaniyor.
            if (harf != 'a')
                cout << "Girdiğiniz alan dolu baska bir sütun giriniz!" << endl;
            return 0;
        }
    }
    return 0;
}
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Yatay sırada
//ard arda bulunan X sayisini return eder.
int yatayKontrolX(char *array, char sutun, int size) {

    int satirKontrol, toplamBuldum = 0, buldum = 0, basla, i = size, a = 0;
    int satir = size;
    int flag = 0;
    int tut = sutun;
    int dortTas[4];
    int dortTasSize = 4;
    tut -= 97;

    while (i >= 1) {//satir sayisini bulan while dongusu
        if (array[tut] == ' ') {
            satir = satir - 1;
        }
        tut += size;//array tek boyutlu oldugu icin size kadar arttiriyoruz
        --i;
    } //sutun girildikten sonra gitmesi istenen konum belirlenir.
    //alttaki formul gidilmek istenen konumun arraydeki yerini gosterir
    satirKontrol = ((size) * size) - satir*size;
    for (basla = satirKontrol; basla < satirKontrol + size && flag == 0; ++basla) {
        if (array[basla] == 'X') {
            dortTas[a] = basla;
            if (a < dortTasSize) {
                a = a + 1;
            }
            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            if (buldum == 4) {//4 tane Xin bulundugu yerlerdeki 
		//X ler kucuk x e donusturulur.
                cout << "Oyuncu X kazandı" << endl;
                for (int m = 0; m < 4; ++m) {
                    array[dortTas[m]] = 'x';
                }
                cout << "KAZANMA DURUMU" << endl;
                printBoard(array, size);
                flag = 1;
            }
        } else {
            buldum = 0;
            a = 0;
        }
    }
    return toplamBuldum;
}
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Yatay sırada
//ard arda bulunan O sayisini return eder.
int yatayKontrolO(char *array, char sutun, int size, char harf) {

    int satirKontrol, buldum = 0, basla, i = size, a = 0;
    int satir = size;
    int toplamBuldum = 0;
    int flag = 0;
    int tut = sutun;
    int dortTas[4];
    int dortTasSize = 4;
    tut -= 97;

    while (i >= 1) {
        if (array[tut] == ' ') {
            satir = satir - 1;
        }
        tut += size;
        --i;
    }//sutun girildikten sonra gitmesi istenen konum belirlenir.
    //alttaki formul gidilmek istenen konumun arraydeki yerini gosterir
    satirKontrol = ((size) * size) - satir*size;
    for (basla = satirKontrol; basla < satirKontrol + size && flag == 0; ++basla) {

        if (array[basla] == 'O') {
            dortTas[a] = basla;
            if (a < dortTasSize) {
                a = a + 1;
            }
            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            if (buldum == 4) {
                for (int m = 0; m < 4; ++m) {//4 tane Xin bulundugu yerlerdeki 
		//O lar kucuk o'ya donusturulur.
                    array[dortTas[m]] = 'o';
                }
                if (harf == 'a') {
                    cout << "Bilgisayar oyunu kazandı" << endl;
                } else {
                    cout << "Oyuncu O kazandı" << endl;
                }
                cout << "KAZANMA DURUMU" << endl;
                printBoard(array, size);
                flag = 1;
            }
        } else {
            a = 0;
            buldum = 0;
        }
    }
    return toplamBuldum;
}
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Dikey sırada
//ard arda bulunan X sayisini return eder.
int dikeyKontrolX(char* array, char sutun, int size) {

    int buldum = 0, flag = 0;
    int tut = sutun;
    tut = tut - 97;
    int toplamBuldum = 0;
    int i = size, a = 0;
    int dortTas[4];
    int dortTasSize = 4;
    while (i > 0 && flag == 0) {

        if (array[tut] == 'X') {
            dortTas[a] = tut;
            if (a < dortTasSize) {
                ++a;
            }
            buldum = buldum + 1;

            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            if (buldum == 4) {//4 tane Xin bulundugu yerlerdeki 
		//X ler kucuk x e donusturulur.
                cout << "Oyuncu X kazandı" << endl;
                for (int m = 0; m < 4; ++m) {
                    array[dortTas[m]] = 'x';
                }
                cout << "KAZANMA DURUMU" << endl;
                printBoard(array, size);
                flag = 1;
            }
        } else {
            buldum = 0;
            a = 0;
        }
        tut = tut + size;
        i = i - 1;
    }
    return toplamBuldum;
}

int dikeyKontrolO(char* array, char sutun, int size, char harf) {

    int buldum = 0, flag = 0;
    int tut = sutun;
    tut = tut - 97;
    int i = size;
    int toplamBuldum = 0, a = 0;
    int dortTas[4];
    int dortTasSize = 4;
    while (i > 0 && flag == 0) {
        if (array[tut] == 'O') {
            dortTas[a] = tut;
            if (a < dortTasSize) {
                ++a;
            }
            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            if (buldum == 4) {
                for (int m = 0; m < 4; ++m) {
                    array[dortTas[m]] = 'o';
                }
                if (harf == 'a') {
                    cout << "Bilgisayar oyunu kazandı" << endl;
                } else {
                    cout << "Oyuncu O kazandı" << endl;
                }
                cout << "KAZANMA DURUMU" << endl;
                printBoard(array, size);
                flag = 1;
            }
        } else {
            buldum = 0;
            a = 0;
        }
        tut = tut + size;
        i = i - 1;
    }
    return toplamBuldum;
}
//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Carpraz sırada
//ard arda bulunan X sayisini return eder.
int caprazKontrollerX(char *array, int satir, char sutun, int size) {

    int geciciSutun = sutun - 97;
    int konum = size * satir + geciciSutun;
    int geciciKonum = size * satir + geciciSutun;
    int baslangic = 0, bitis = 0;
    int eslesme1 = 0, eslesme2 = 0;
    int dortTas1[4], dortTas2[4];
    int a = 0, b = 0;
    int dortTasSize = 4;
    int dortEslesme=0;
    
    for (int i = satir, j = geciciSutun; i > 0 && j < size - 1; --i, ++j) {
        geciciKonum = geciciKonum - size + 1;
    }
    baslangic = geciciKonum;
    geciciKonum = konum;
    for (int i = satir, j = geciciSutun; i < size - 1 && j > 0; ++i, --j) {
        geciciKonum = geciciKonum + size - 1;
    }
    bitis = geciciKonum;

    for (int i = baslangic; i < bitis + 1; i = i + (size - 1)) {
        if (array[i] == 'X') {
            dortTas1[a] = i;
            if (a < dortTasSize) {
                ++a;
            }
            ++dortEslesme;
            if(dortEslesme>eslesme1)
                eslesme1=dortEslesme;
        } else {
            a = 0;
            dortEslesme=0;
        }
    }

    geciciKonum = konum;
    for (int i = satir, j = geciciSutun; i > 0 && j > 0; --i, --j) {
        geciciKonum = geciciKonum - size - 1;
    }
    baslangic = geciciKonum;
    geciciKonum = konum;

    for (int i = satir, j = geciciSutun; i < size - 1 && j < size - 1; ++i, ++j) {
        geciciKonum = geciciKonum + size + 1;
    }
    bitis = geciciKonum;
    dortEslesme=0;
    for (int i = baslangic; i < bitis + 1; i = i + (size + 1)) {
        if (array[i] == 'X') {
            dortTas2[b] = i;
            if (b < dortTasSize) {
                ++b;
            }
            ++dortEslesme;
            if(dortEslesme>eslesme2)
                eslesme2=dortEslesme;
        } else {
            b = 0;
            dortEslesme=0;
        }
    }
    if (eslesme1 > eslesme2) {
        if (eslesme1 >= 4) {
            for (int m = 0; m < 4; ++m) {//4 tane Xin bulundugu yerlerdeki 
		//X ler kucuk x e donusturulur.

                array[dortTas1[m]] = 'x';
            }
            cout << "Oyuncu X kazandı" << endl;
            cout << "KAZANMA DURUMU" << endl;
            printBoard(array, size);
        }
        return eslesme1;
    } else {

        if (eslesme2 >= 4) {
            for (int m = 0; m < 4; ++m) {

                array[dortTas2[m]] = 'x';
            }
            cout << "Oyuncu X kazandı" << endl;
            cout << "KAZANMA DURUMU" << endl;
            printBoard(array, size);
        }
        return eslesme2;
    }
}

//Bu fonksiyon hamleler yapildikca tüm tahtayi kontrol eder.Carpraz sırada
//ard arda bulunan O sayisini return eder.
int caprazKontrollerO(char *array, int satir, char sutun, int size, char harf) {

    int geciciSutun = sutun - 97;
    int konum = size * satir + geciciSutun;
    int geciciKonum = size * satir + geciciSutun;
    int baslangic = 0, bitis = 0;
    int eslesme1 = 0, eslesme2 = 0;
    int dortTas1[4], dortTas2[4];
    int a = 0, b = 0;
    int dortTasSize = 4;
    int dortEslesme=0;
    for (int i = satir, j = geciciSutun; i > 0 && j < size - 1; --i, ++j) {
        geciciKonum = geciciKonum - size + 1;
    }
    baslangic = geciciKonum;
    geciciKonum = konum;
    for (int i = satir, j = geciciSutun; i < size - 1 && j > 0; ++i, --j) {
        geciciKonum = geciciKonum + size - 1;
    }
    bitis = geciciKonum;

    for (int i = baslangic; i < bitis + 1; i = i + (size - 1)) {
        if (array[i] == 'O') {
            dortTas1[a] = i;
            if (a < dortTasSize) {
                ++a;
            }
            ++dortEslesme;
            if(dortEslesme>eslesme1)
                eslesme1=dortEslesme;
        } else {
            a = 0;
            dortEslesme=0;
        }
    }
    geciciKonum = konum;
    for (int i = satir, j = geciciSutun; i > 0 && j > 0; --i, --j) {
        geciciKonum = geciciKonum - size - 1;
    }
    baslangic = geciciKonum;
    geciciKonum = konum;

    for (int i = satir, j = geciciSutun; i < size - 1 && j < size - 1; ++i, ++j) {
        geciciKonum = geciciKonum + size + 1;
    }
    bitis = geciciKonum;
    dortEslesme=0;
    for (int i = baslangic; i < bitis + 1; i = i + (size + 1)) {
        if (array[i] == 'O') {
            dortTas2[b] = i;
            if (b < dortTasSize) {
                ++b;
            }
            ++dortEslesme;
            if(dortEslesme>eslesme2)
                eslesme2=dortEslesme;
        } else {
            b = 0;
            dortEslesme=0;
        }
    }
    if (eslesme1 > eslesme2) {
        if (eslesme1 >= 4) {
            for (int m = 0; m < 4; ++m) {
                array[dortTas1[m]] = 'o';
            }
            if (harf == 'a') {
                cout << "Bilgisayar oyunu kazandı" << endl;
            } else {
                cout << "Oyuncu O kazandı" << endl;
            }
            cout << "KAZANMA DURUMU" << endl;
            printBoard(array, size);
        }
        return eslesme1;
    } else {
        if (eslesme2 >= 4) {
            for (int m = 0; m < 4; ++m) {
                array[dortTas2[m]] = 'o';
            }
            if (harf == 'a') {
                cout << "Bilgisayar oyunu kazandı" << endl;
            } else {
                cout << "Oyuncu O kazandı" << endl;
            }
            cout << "KAZANMA DURUMU" << endl;
            printBoard(array, size);
        }
        return eslesme2;
    }
}
//Hamle yapilmak istenen sutun girildiginde tas bos bulunan satira konur.
//Yerlestirildigi satiri hesaplayan fonksiyon
int satirHesapla(char *array, char sutun, int size) {

    int satir = 0;
    int i = 0;
    int tut = sutun;
    tut -= 97;
    while (i < size) {
        if (array[tut] == ' ') {
            satir = satir + 1;
        }
        tut += size;
        ++i;
    }
    satir = satir - 1;
    return satir;
}
//Bu fonksiyonun amaci bilgisayara hamle yaptirabilmektir
//cesitli durumlari ele alip mutlaka bir önceki haamlenin yakinlarina bir hamle
//yapmasi saglanmistir.
int movPlayerComputer(char *array, char sutun, int size, int satir, char harf) {

    harf = 'a';
    int yataySayi;
    int dikeySayi;
    int caprazSayi;
    int sayiyaCevir = sutun - 97;
    int boslukAlan = (size - 1) - sayiyaCevir;
    int bilgisayarHamle = 0;
    int hamle = 0;

    yataySayi = yatayKontrolX(array, sutun, size);
    dikeySayi = dikeyKontrolX(array, sutun, size);
    caprazSayi = caprazKontrollerX(array, satir, sutun, size);
    do {
        if (boslukAlan == 0) {
            hamle = 1;
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(array, sutun - hamle, size, harf);
                if (hamle == size) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        } else if (yataySayi == 2 || yataySayi == 3) {
            bilgisayarHamle = movPlayerO(array, sutun + 1, size, harf);
            hamle = -size;
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(array, sutun + hamle, size, harf);
                if (hamle == size) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        } else if (dikeySayi == 2 || dikeySayi == 3) {
            bilgisayarHamle = movPlayerO(array, sutun, size, harf);
            hamle = size;
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(array, sutun - hamle, size, harf);
                if (hamle == -size) {
                    bilgisayarHamle = 1;
                }
                --hamle;
            }
        } else if (caprazSayi == 2 || caprazSayi == 3) {
            bilgisayarHamle = movPlayerO(array, sutun - 1, size, harf);
            hamle = -size;
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(array, sutun + hamle, size, harf);
                if (hamle == size) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        } else {
            hamle = -size;
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(array, sutun + hamle, size, harf);
                if (hamle == size) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        }
    } while (bilgisayarHamle == 0);
    return 1;
}
