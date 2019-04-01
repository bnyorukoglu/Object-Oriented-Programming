#include "ConnectFour.h"

int ConnectFour::livingCell = 0;
int ConnectFour::doluluk = 0;

ConnectFour::ConnectFour() {

    setWidth(5);
    setHeight(5);

    gameBoard = new Cell*[getHeight()];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[getWidth()];

    for (int i = 0; i < getHeight(); ++i) {
        for (int m = 0; m < getWidth(); ++m) {
            gameBoard[i][m].setInformation(' ');
        }
    }
    setTas('X');
    playKontrol = 0;
    playKontrol2 = 0;
    playKontrol3 = 0;
    doluluk = 0;
}

ConnectFour::ConnectFour(int w, int h) {
    setWidth(w);
    setHeight(h);
    int m;
    gameBoard = new Cell*[getHeight()];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[getWidth()];

    for (int i = 0; i < getHeight(); ++i) {
        for (m = 0; m < getWidth(); ++m) {
            gameBoard[i][m].setInformation(' ');
        }
    }
    setTas('X');
    playKontrol = 0;
    playKontrol2 = 0;
    playKontrol3 = 0;
    doluluk = 0;
}

ConnectFour::ConnectFour(const ConnectFour &gelen) {

    width = gelen.width;
    height = gelen.height;

    gameBoard = new Cell*[getHeight()];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[getWidth()];

    for (int i = 0; i < height; ++i) {
        for (int m = 0; m < width; ++m) {
            gameBoard[i][m].setInformation(gelen.gameBoard[i][m].getInformation());
        }
    }
    setTas('X');
    playKontrol = 0;
    playKontrol2 = 0;
    playKontrol3 = 0;
    doluluk = 0;
}

ConnectFour::ConnectFour(const string& boardName) {

    satirSutunBul(boardName);
    gameBoard = new Cell*[getHeight()];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[getWidth()];
    readFileAndFill(boardName);
}

ConnectFour::ConnectFour(const string& file, char secenek) {

    oyunSecimi = secenek;
    setTas('X');
    playKontrol = 0;
    playKontrol2 = 0;
    playKontrol3 = 0;
    doluluk = 0;
    satirSutunBul(file);
    gameBoard = new Cell*[height];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[width];
    readFileAndFill(file);
}

ConnectFour::Cell::Cell() {

}

ConnectFour::Cell::Cell(char sutun, int satir, char Information) {
    setPosition(sutun);
    setRow(satir);
    setInformation(Information);
}

ConnectFour::~ConnectFour() {
    for (int i = 0; i < height; ++i) {
        delete [] gameBoard[i];
    }
    delete [] gameBoard;
}

ConnectFour& ConnectFour::operator=(const ConnectFour &otherSide) {

    height = otherSide.height;
    width = otherSide.width;
    for (int i = 0; i < height; ++i) {
        delete [] gameBoard[i];
    }
    delete [] gameBoard;

    gameBoard = new Cell*[height];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[width];

    for (int i = 0; i < height; ++i) {
        for (int m = 0; m < width; ++m) {
            gameBoard[i][m].setInformation(otherSide.gameBoard[i][m].getInformation());
        }
    }
    return *this;
}

istream & operator>>(istream & inputStream, ConnectFour::Cell &gelen) {
    cout << "Taş:";
    inputStream >> gelen.cellInformation;
    cout << endl;
    cout << "Position:";
    inputStream >> gelen.position;
    cout << endl;
    cout << "Row:";
    inputStream >> gelen.row;

    return inputStream;
}

ostream & operator<<(ostream & outputStream, const ConnectFour::Cell &gelen) {


    outputStream << gelen.cellInformation << endl;
    outputStream << gelen.position << endl;
    outputStream << gelen.row << endl;

    return outputStream;
}

bool ConnectFour::Cell::operator==(const Cell & gelenObj)const {

    return (gelenObj.row == row && gelenObj.position == position && gelenObj.cellInformation == cellInformation);
}

void ConnectFour::Cell::operator++() {
    if (durum == 'e')
        durum = '1';
    else if (durum == '1')
        durum = '2';
    else if (durum == '2')
        durum = '2';
    else if (durum == 'c')
        durum = 'e';
}

void ConnectFour::Cell::operator++(int yokSay) {
    if (durum == 'e')
        durum = '1';
    else if (durum == '1')
        durum = '2';
    else if (durum == '2')
        durum = '2';
    else if (durum == 'c')
        durum = 'e';
}

void ConnectFour::Cell::operator--() {
    if (durum == 'e')
        durum = '1';
    else if (durum == '1')
        durum = '2';
    else if (durum == '2')
        durum = '2';
    else if (durum == 'c')
        durum = 'e';

}

void ConnectFour::Cell::operator--(int yokSay) {
    if (durum == 'e')
        durum = '1';
    else if (durum == '1')
        durum = '2';
    else if (durum == '2')
        durum = '2';
    else if (durum == 'c')
        durum = 'e';
}

bool ConnectFour::operator==(const ConnectFour & gelenObj) const {
    return (gelenObj.height == height && gelenObj.width == width && gelenObj.oyunSecimi == oyunSecimi);
}

bool ConnectFour::operator!=(const ConnectFour & gelenObj) const {
    return (!(gelenObj.height == height && gelenObj.width == width && gelenObj.oyunSecimi == oyunSecimi));
}

int ConnectFour::isItFullBoard() {

    int sayi = 0;
    for (int i = 0; i < getHeight(); ++i) {
        for (int m = 0; m < getWidth(); ++m) {
            if (gameBoard[i][m].getInformation() == 'X' || gameBoard[i][m].getInformation() == 'O'
                    || gameBoard[i][m].getInformation() == ' ')
                sayi++;
        }
    }
    return sayi;
}

void ConnectFour::readFileAndFill(const string& gelenFile) {

    int z = 0;
    string karakter;
    fstream myinput;

    myinput.open(&gelenFile[0]);
    if (myinput) {

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                gameBoard[i][j].setInformation(' ');
            }
        }
        for (int i = 0; i < getHeight(); ++i) {

            getline(myinput, karakter);
            int size = karakter.size();
            for (int m = 0; m < size; ++m) {
                gameBoard[i][z].setInformation(karakter[m]);
                ++z;
            }
            z = 0;
        }

    }
    myinput.close();
}

void ConnectFour::satirSutunBul(const string& gelenFile) {
    int sayac = 0;
    int satir = 0;
    int sutun = 0;
    string karakter;
    fstream input;

    input.open(&gelenFile[0]);
    if (input) {
        do {
            getline(input, karakter);
            if (karakter.size() > 0) {
                satir++;
                int size = karakter.size();
                if (size >= sutun) {
                    sutun = karakter.size();
                }

            } else if (sayac == 0) {
                cerr << "bos dosya girdiniz.";
                exit(0);
            }
            sayac++;

        } while (karakter.size() > 0);
    }
    setWidth(sutun);
    setHeight(satir);

    input.close();
}

void ConnectFour::mainfunc() {

    string dosyaBelirleme;
    int flag = 1, satir = 0;
    string girdi;
    int girdiSize;
    auto kontrol = 0, kontrol1 = 0, kontrol2 = 0;
    auto kazanmaKontrol = 0, kazanmaKontrol2 = 0, kazanmaKontrol3 = 0;
    bool dosyaKontrol = true;
    string bosAlan;
    int tahtaDolumu = 0;

    //Buradaki do whileda oyun baslar ve kazanmaKontrol,kazanmaKontrol2,kazanma
    //kontrol3 4ten kucuk oldukca devam eder.yani herhangi istenen bir sekilde
    //yan yana 4 saglanmadikca hicbir oyuncu kazanamaz ve hamle istenir.
    cin.ignore(200, '\n');
    do {
        int spaceCount = 0;
        switch (oyunSecimi) {
            case 'C'://Bilgisayar ile oynamak istiyorsak
                if (flag == 1) {
                    oyunTasi = 'X';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    //oyuncu oyun alani disinda bir sutun girdiginde tekrar
                    //tekrar soracak
                    do {
                        cout << "Oyuncu X için sütun konumunu girin: ";
                        getline(cin, girdi);

                        girdiSize = girdi.size();
                        spaceCount = 0;
                        for (int i = 0; girdi[i] == ' '; ++i) {
                            spaceCount = spaceCount + 1;
                        }
                        if (girdiSize == 0)
                            exit(0);
                        if (girdiSize == 1) {
                            sutun = girdi[0];
                            if (sutun >= 'A' && sutun <= 'Z') {
                                sutun = sutun + 32;
                            }

                            kontrol1 = movPlayerX(sutun);
                            if (kontrol1)
                                setLivingCell(livingCell + 1);
                            if (kontrol1 == 1) {
                                //                                tahtaDolumu += 1;
                                if (isItFullBoard() == getHeight() * getWidth()) {
                                    cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                }
                            }

                            kazanmaKontrol = yatayKontrolX(sutun);
                            kazanmaKontrol2 = dikeyKontrolX(sutun);

                            satir = satirHesapla(sutun);

                            kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                            flag = 0;
                        } else if (girdi.substr(spaceCount, 5).compare("LOAD ") == 0) {

                            dosyaBelirleme = dosyaIsmiBelirleme(girdi, "LOAD", dosyaKontrol);
                            if (dosyaKontrol) {
                                loadFunc(dosyaBelirleme, flag);
                                tahtaDolumu = 0;

                                for (int i = 0; i < getHeight(); ++i) {

                                    for (int j = 0; j < getWidth(); ++j) {

                                        if (gameBoard[i][j].getInformation() == 'X' || gameBoard[i][j].getInformation() == 'O') {
                                            tahtaDolumu = tahtaDolumu + 1;
                                        }
                                    }
                                }
                                if (flag != 1) {
                                    kontrol1 = 1;
                                }
                            }

                        } else if (girdi.substr(spaceCount, 5).compare("SAVE ") == 0) {
                            dosyaBelirleme = dosyaIsmiBelirleme(girdi, "SAVE", dosyaKontrol);
                            if (dosyaKontrol) {
                                saveFunc(dosyaBelirleme, flag);
                            }
                        } else {
                            cerr << "yanlış komut girdiniz tekrar giriniz" << endl;
                        }
                        //yanlis hamle yaparsa dongu tekrar doner
                    } while (kontrol1 == 0 || (girdiSize > 1 && flag == 1));

                } else if (flag == 0) {
                    oyunTasi = 'O';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    flag = 1;
                    do {
                        kontrol2 = movPlayerComputer(sutun, satir);
                        if (kontrol2)
                            setLivingCell(livingCell + 1);
                        cout << "LivingCell:" << livingCell << endl;
                        if (kontrol2 == 1) {
                            //                            tahtaDolumu += 1;
                            if (isItFullBoard() == getHeight() * getWidth()) {
                                cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                            }
                        }
                        //                        for (char sutunDolas = 'a'; sutunDolas < getWidth() + 97; ++sutunDolas) {
                        kontrol = yatayKontrolO(sutun);
                        if (kontrol > kazanmaKontrol) {
                            kazanmaKontrol = kontrol;
                        }
                        //                        }
                        //                        for (char sutunDolas = 'a'; sutunDolas < getWidth() + 97; ++sutunDolas) {
                        kontrol = dikeyKontrolO(sutun);
                        if (kontrol > kazanmaKontrol2) {
                            kazanmaKontrol2 = kontrol;
                        }
                        //                        }
                        //for (int satirDolas = 0; satirDolas < getWidth(); ++satirDolas) {
                        //                            for (char sutunDolas = 'a'; sutunDolas < getWidth() + 97; ++sutunDolas) {

                        satir = satirHesapla(sutun);

                        kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                        if (kontrol > kazanmaKontrol3) {
                            kazanmaKontrol3 = kontrol;
                        }
                        //                            }
                        //                        }
                        //yanlis hamle yaparsa dongu tekrar doner
                    } while (kontrol2 == 0);
                }
                break;

            case 'P':
                if (flag == 1) {
                    oyunTasi = 'X';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    //oyuncu oyun alani disinda bir sutun girdiginde tekrar
                    //tekrar soracak
                    do {

                        cout << "Oyuncu X için sütun konumunu girin:  ";
                        getline(cin, girdi);
                        girdiSize = girdi.size();

                        spaceCount = 0;
                        for (int i = 0; girdi[i] == ' '; ++i) {
                            spaceCount = spaceCount + 1;
                        }
                        if (girdiSize == 0)
                            exit(0);
                        if (girdiSize == 1) {
                            sutun = girdi[0];
                            if (sutun >= 'A' && sutun <= 'Z') {
                                sutun = sutun + 32;
                            }

                            kontrol1 = movPlayerX(sutun);
                            if (kontrol1)
                                setLivingCell(livingCell + 1);
                            if (kontrol1 == 1) {
                                //                                tahtaDolumu += 1;
                                if (isItFullBoard() == getHeight() * getWidth()) {
                                    cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                }
                            }

                            kazanmaKontrol = yatayKontrolX(sutun);
                            kazanmaKontrol2 = dikeyKontrolX(sutun);

                            satir = satirHesapla(sutun);

                            kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                            flag = 0;
                        } else if (girdi.substr(spaceCount, 5).compare("LOAD ") == 0) {

                            dosyaBelirleme = dosyaIsmiBelirleme(girdi, "LOAD", dosyaKontrol);
                            if (dosyaKontrol) {
                                loadFunc(dosyaBelirleme, flag);
                                tahtaDolumu = 0;

                                for (int i = 0; i < getHeight(); ++i) {

                                    for (int j = 0; j < getWidth(); ++j) {

                                        if (gameBoard[i][j].getInformation() == 'X' || gameBoard[i][j].getInformation() == 'O') {
                                            tahtaDolumu = tahtaDolumu + 1;
                                        }
                                    }
                                }
                                if (flag != 1) {
                                    kontrol1 = 1;
                                }
                            }
                        } else if (girdi.substr(spaceCount, 5).compare("SAVE ") == 0) {

                            dosyaBelirleme = dosyaIsmiBelirleme(girdi, "SAVE", dosyaKontrol);

                            if (dosyaKontrol) {
                                saveFunc(dosyaBelirleme, flag);
                            }
                        } else {
                            cerr << "yanlış komut girdiniz tekrar giriniz" << endl;
                        }
                    } while (kontrol1 == 0 || (girdiSize > 1 && flag == 1)); //yanlis hamle yaparsa dongu
                    //tekrar doner 

                } else if (flag == 0) {
                    oyunTasi = 'O';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    do {
                        cout << "Oyuncu O için sütun konumunu girin:  ";

                        getline(cin, girdi);
                        girdiSize = girdi.length();
                        spaceCount = 0;
                        for (int i = 0; girdi[i] == ' '; ++i) {
                            spaceCount = spaceCount + 1;
                        }
                        if (girdiSize == 0)
                            exit(0);
                        if (girdiSize == 1) {
                            sutun = girdi[0];
                            //sutun harfi buyuk girilirse kucuk harfe cevirir
                            if (sutun >= 'A' && sutun <= 'Z') {
                                sutun = sutun + 32;
                            }

                            kontrol2 = movPlayerO(sutun);
                            if (kontrol2)
                                setLivingCell(livingCell + 1);
                            cout << "LivingCell:" << livingCell << endl;
                            if (kontrol2 == 1) {
                                //                                tahtaDolumu += 1;
                                if (isItFullBoard() == getHeight() * getWidth()) {
                                    cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                }
                            }

                            kazanmaKontrol = yatayKontrolO(sutun);
                            kazanmaKontrol2 = dikeyKontrolO(sutun);
                            satir = satirHesapla(sutun);

                            kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                            flag = 1;
                        } else if (girdi.substr(spaceCount, 5).compare("LOAD ") == 0) {

                            dosyaBelirleme = dosyaIsmiBelirleme(girdi, "LOAD", dosyaKontrol);
                            if (dosyaKontrol) {
                                loadFunc(dosyaBelirleme, flag);
                                tahtaDolumu = 0;

                                for (int i = 0; i < getHeight(); ++i) {

                                    for (int j = 0; j < getWidth(); ++j) {

                                        if (gameBoard[i][j].getInformation() == 'X' || gameBoard[i][j].getInformation() == 'O') {
                                            tahtaDolumu = tahtaDolumu + 1;
                                        }
                                    }
                                }
                                if (flag != 0) {
                                    kontrol2 = 1;
                                }
                            }
                        } else if (girdi.substr(spaceCount, 5).compare("SAVE ") == 0) {
                            dosyaBelirleme = dosyaIsmiBelirleme(girdi, "SAVE", dosyaKontrol);
                            if (dosyaKontrol)
                                saveFunc(dosyaBelirleme, flag);
                        } else {
                            cerr << "yanlış komut girdiniz tekrar giriniz" << endl;
                        }
                    } while (kontrol2 == 0 || (girdiSize > 1 && flag == 0)); //yanlis hamle yaparsa dongu tekrar doner	
                }
                break;
        }
    } while (kazanmaKontrol < 4 && kazanmaKontrol2 < 4 && kazanmaKontrol3 < 4 && isItFullBoard() < getWidth() * getHeight());
    cout << "LivingCell:" << livingCell << endl;
}

void ConnectFour::displayBoard() {
    int i, m;
    char bas;
    cout << endl;
    cout << " ";
    for (int a = 0; a < getWidth(); ++a) {
        bas = 'a' + a;
        cout << bas << " ";
    }
    cout << endl;
    for (i = 0; i < getHeight(); ++i) {
        for (m = 0; m < getWidth(); ++m) {
            cout << " " << gameBoard[i][m].getInformation();

        }
        cout << endl;
    }
}

//const void ConnectFour::takeWidthAndHeight() {
//    int gecici;
//
//    //GENİSLİK ALMA VE KONTROL
//    cout << "En giriniz: ";
//    cin>>gecici;
//    setWidth(gecici);
//    //cin ile kullanıcıdan bilgi alındıktan sonra enter'a basınca gelen new line karakterini yok say
//    cin.ignore(200, '\n');
//    //Eger size yerine gecersiz bir sey girilirse(harf gibi) hata vermesini
//    //sagliyor
//    while (cin.fail()) {
//        cin.clear();
//        cin.ignore();
//        cout << "Yanlis girdiniz.Eni tekrar giriniz: ";
//        cin>>gecici;
//        setWidth(gecici);
//    }
//
//    //girilen size'in saayi degerinin 4 ile 20 arasında olup olmadigina bakar
//    //Eger bu aralikta degilse tekrar size ister
//    while (gecici < 3) {
//        cout << "4'ten kücük bir sayi girdiniz.Oyun alanının enini tekrar giriniz: ";
//        cin>>gecici;
//        while (cin.fail()) {
//            cin.clear();
//            cin.ignore();
//            cout << "Eni tekrar giriniz: ";
//            cin>>gecici;
//            setWidth(gecici);
//        }
//    }
//    //YUKSEKLIK ALMA VE KONTROL
//
//    cout << "Yükseklik giriniz: ";
//    cin>>gecici;
//    setHeight(gecici);
//
//    //cin ile kullanıcıdan bilgi alındıktan sonra enter'a basınca gelen new line karakterini yok say
//    cin.ignore(200, '\n');
//    //Eger size yerine gecersiz bir sey girilirse(harf gibi) hata vermesini
//    //sagliyor
//    while (cin.fail()) {
//        cin.clear();
//        cin.ignore();
//        cout << "Yanlis girdiniz.Yüksekligi tekrar giriniz: ";
//        cin>>gecici;
//        setHeight(gecici);
//    }
//
//    //girilen size'in saayi degerinin 4 ile 20 arasında olup olmadigina bakar
//    //Eger bu aralikta degilse tekrar size ister
//    while (gecici < 3) {
//        cout << "4'ten kücük bir sayi girdiniz.Yüksekligi tekrar giriniz:  ";
//        cin>>gecici;
//        setHeight(gecici);
//        while (cin.fail()) {
//            cin.clear();
//            cin.ignore();
//            cout << "Yuksekligi tekrar giriniz: ";
//            cin>>gecici;
//            setHeight(gecici);
//        }
//    }
//}

int ConnectFour::isValid(char sutun) {
    int sayac = 0;
    char i = 'a';
    int k = 0;
    while (k < getWidth()) {
        if (sutun != i)
            sayac++;
        ++k;
        ++i;
    }
    if (sayac == getWidth()) {
        if (getHarf() != 'a') {
            cerr << "Girdiginiz sutun hatali.Tekrar giriniz.";
        }
        return 0;
    } else
        return 1;
}

int ConnectFour::satirHesapla(char sutun) {
    int satir = 0, i = 0;
    int tut = sutun;
    tut -= 97;
    while (i < getHeight()) {

        if (gameBoard[i][tut].getInformation() == '*' || gameBoard[i][tut].getInformation() == ' ') {
            satir = satir + 1;
        }
        ++i;
    }
    return satir;
}

int ConnectFour::konulanTasinSatiriniHesapla(char sutun) {
    int satir = 0, i = 0;
    int tut = sutun;
    tut -= 97;
    while ((gameBoard[i][tut].getInformation() == '*' || gameBoard[i][tut].getInformation() == ' ') && i < getHeight()) {
        satir = satir + 1;
        ++i;
    }
    return satir;
}

int ConnectFour::movPlayerX(char sutun) {
    int tut = sutun;
    tut -= 97; //a=0,b=1,c=2...girilen sutunun degerini bulmamızı saglar
    satir = height - 1;

    if (isValid(sutun)) {
        while (satir >= 0 && gameBoard[satir][tut].getInformation() != '*') {
            satir = satir - 1;
        }
        if (satir >= 0) {
            //gidilmek istenen yer uygun ise X konur
            gameBoard[satir][tut].setInformation('X');
            displayBoard();
            return 1;
        } else {
            //gidilmek istenen yer dolu ise hata verir
            cout << "Girdiğiniz alan dolu baska bir sütun giriniz!" << endl;
            return 0;
        }
    }
    return 0;
}

int ConnectFour::movPlayerO(char sutun) {
    int tut = sutun;
    tut -= 97; //a=0,b=1,c=2...girilen sutunun degerini bulmamızı saglar
    int satir = height - 1;

    if (isValid(sutun)) {
        while (satir >= 0 && gameBoard[satir][tut].getInformation() != '*') {
            satir = satir - 1;
        }
        if (satir >= 0) {
            //gidilmek istenen yer uygun ise O konur
            gameBoard[satir][tut].setInformation('O');
            displayBoard();
            return 1;
        } else {
            //gidilmek istenen yer dolu ise hata verir.
            //Buradaki a benim kendi belirledigim bir harf.
            //Computera karsi oynandiginda parametreye a geliyor ve asagidaki
            //masajin engellenmesi saglaniyor.
            if (getHarf() != 'a')
                cout << "Girdiğiniz alan dolu baska bir sütun giriniz!" << endl;
            return 0;
        }
    }
    return 0;
}

int ConnectFour::yatayKontrolO(char sutun) {

    int toplamBuldum = 0, buldum = 0;
    int tasKucult = 0;
    int flag = 0;
    int indeks = 0;
    int dortTas[4], dortTasSize = 4;
    int tut = sutun;
    tut -= 97;
    int satir = konulanTasinSatiriniHesapla(sutun);

    for (int i = 0; i < getWidth() && flag == 0; ++i) {

        if (gameBoard[satir][i].getInformation() == 'O') {

            dortTas[tasKucult] = i + tut;
            if (tasKucult < dortTasSize) {
                tasKucult = tasKucult + 1;
            }
            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
            if (toplamBuldum == 4) {

                for (int m = 0; m < 4; ++m) {
                    indeks = dortTas[m] - tut;
                    gameBoard[satir][indeks].setInformation('o');
                }
                if (getHarf() == 'a') {
                    cout << "Bilgisayar oyunu kazandı" << endl;
                } else {
                    cout << "Oyuncu O kazandı" << endl;
                }
                cout << "KAZANMA DURUMU" << endl;
                displayBoard();
                flag = 1;
            }
        } else {
            buldum = 0;
            tasKucult = 0;
        }
    }
    return toplamBuldum;
}

int ConnectFour::yatayKontrolX(char sutun) {

    int toplamBuldum = 0, buldum = 0;
    int tasKucult = 0;
    int flag = 0;
    int indeks = 0;
    int dortTas[4], dortTasSize = 4;
    int tut = sutun;
    tut -= 97;
    int satir = konulanTasinSatiriniHesapla(sutun);

    for (int i = 0; i < getWidth() && flag == 0; ++i) {
        if (gameBoard[satir][i].getInformation() == 'X') {

            dortTas[tasKucult] = i + tut;
            if (tasKucult < dortTasSize) {
                tasKucult = tasKucult + 1;
            }

            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
            if (toplamBuldum == 4) {
                cout << "Oyuncu X kazandı" << endl;
                for (int m = 0; m < 4; ++m) {
                    indeks = dortTas[m] - tut;
                    gameBoard[satir][indeks].setInformation('x');
                }
                cout << "KAZANMA DURUMU" << endl;
                displayBoard();
                flag = 1;
            }
        } else {
            buldum = 0;
            tasKucult = 0;
        }
    }
    return toplamBuldum;
}

int ConnectFour::dikeyKontrolX(char sutun) {

    int toplamBuldum = 0, buldum = 0, tasKucult = 0;
    int dortTas[4], dortTasSize = 4;
    int flag = 0, indeks = 0;
    int tut = sutun;
    tut -= 97;

    for (int i = 0; i < getHeight() && flag == 0; ++i) {

        if (gameBoard[i][tut].getInformation() == 'X') {

            dortTas[tasKucult] = i + tut;
            if (tasKucult < dortTasSize) {
                tasKucult = tasKucult + 1;
            }
            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
            if (toplamBuldum == 4) {
                cout << "Oyuncu X kazandı" << endl;
                for (int m = 0; m < 4; ++m) {
                    indeks = dortTas[m] - tut;
                    gameBoard[indeks][tut].setInformation('x');
                }
                cout << "KAZANMA DURUMU" << endl;
                displayBoard();
                flag = 1;
            }
        } else {
            buldum = 0;
            tasKucult = 0;
        }
    }
    return toplamBuldum;
}

int ConnectFour::dikeyKontrolO(char sutun) {

    int toplamBuldum = 0, buldum = 0, tasKucult = 0;
    int dortTas[4], dortTasSize = 4;
    int flag = 0, indeks = 0;
    int tut = sutun;
    tut -= 97;

    for (int i = 0; i < getHeight() && flag == 0; ++i) {
        if (gameBoard[i][tut].getInformation() == 'O') {

            dortTas[tasKucult] = i + tut;
            if (tasKucult < dortTasSize) {
                tasKucult = tasKucult + 1;
            }
            buldum = buldum + 1;
            if (buldum > toplamBuldum) {
                toplamBuldum = buldum;
            }
            //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
            if (toplamBuldum == 4) {
                for (int m = 0; m < 4; ++m) {
                    indeks = dortTas[m] - tut;
                    gameBoard[indeks][tut].setInformation('o');
                }
                if (getHarf() == 'a') {
                    cout << "Bilgisayar oyunu kazandı" << endl;
                } else {
                    cout << "Oyuncu O kazandı" << endl;
                }
                cout << "KAZANMA DURUMU" << endl;
                displayBoard();
                flag = 1;
            }
        } else {
            buldum = 0;
            tasKucult = 0;
        }
    }
    return toplamBuldum;
}

int ConnectFour::caprazKontroller(int satir, char sutun, char oyuncuTasi) {
    int sutunSayisi = sutun - 97;
    int baslangicSatir = 0, baslangicSatir2 = 0;
    int baslangicSutun = 0, baslangicSutun2 = 0;

    int bitisSatir = 0, bitisSatir2 = 0;
    int bitisSutun = 0, bitisSutun2 = 0;

    int dortEslesme = 0, eslesme1 = 0, eslesme2 = 0;

    int geciciSatir = satir;
    int geciciSutun = sutunSayisi;

    int taslariKucult = 0;
    while (geciciSatir < getHeight() && geciciSutun < getWidth()) {
        geciciSutun = geciciSutun + 1;
        geciciSatir = geciciSatir + 1;
    }
    bitisSutun = geciciSutun - 1;
    bitisSatir = geciciSatir - 1;

    geciciSatir = satir;
    geciciSutun = sutunSayisi;
    while (geciciSatir >= 0 && geciciSutun >= 0) {
        geciciSatir = geciciSatir - 1;
        geciciSutun = geciciSutun - 1;
    }
    baslangicSatir = geciciSatir + 1;
    baslangicSutun = geciciSutun + 1;

    for (int i = baslangicSatir, j = baslangicSutun; i <= bitisSatir && j <= bitisSutun; ++i, ++j) {
        if (gameBoard[i][j].getInformation() == 'X') {
            dortEslesme = dortEslesme + 1;
            if (dortEslesme > eslesme1) {

                eslesme1 = dortEslesme;
            }
        } else {
            dortEslesme = 0;
        }
    }

    dortEslesme = 0;
    geciciSatir = satir;
    geciciSutun = sutunSayisi;
    while (geciciSatir >= 0 && geciciSutun < getWidth()) {
        geciciSutun = geciciSutun + 1;
        geciciSatir = geciciSatir - 1;
    }
    baslangicSatir2 = geciciSatir + 1;
    baslangicSutun2 = geciciSutun - 1;

    geciciSatir = satir;
    geciciSutun = sutunSayisi;
    while (geciciSatir < getHeight() && geciciSutun >= 0) {
        geciciSatir = geciciSatir + 1;
        geciciSutun = geciciSutun - 1;
    }
    bitisSutun2 = geciciSutun + 1;
    bitisSatir2 = geciciSatir - 1;

    for (int i = baslangicSatir2, j = baslangicSutun2; i <= bitisSatir2 && j >= bitisSutun2; ++i, --j) {
        if (gameBoard[i][j].getInformation() == oyuncuTasi) {

            dortEslesme = dortEslesme + 1;
            if (dortEslesme > eslesme2) {

                eslesme2 = dortEslesme;
            }
        } else {
            dortEslesme = 0;
        }
    }

    if (eslesme1 > eslesme2) {
        if (eslesme1 >= 4) {
            for (int i = baslangicSatir, j = baslangicSutun; i <= bitisSatir && j <= bitisSutun; ++i, ++j) {
                if (gameBoard[i][j].getInformation() == oyuncuTasi && taslariKucult < 5) {
                    gameBoard[i][j].setInformation(oyuncuTasi + 32);
                }
            }
            cout << "Oyuncu " << oyuncuTasi << " kazandı" << endl;
            cout << "KAZANMA DURUMU" << endl;
            displayBoard();
        }
        return eslesme1;

    } else {
        if (eslesme2 >= 4) {
            for (int i = baslangicSatir2, j = baslangicSutun2; i <= bitisSatir2 && j >= bitisSutun2; ++i, --j) {
                if (gameBoard[i][j].getInformation() == oyuncuTasi && taslariKucult < 5) {
                    gameBoard[i][j].setInformation(oyuncuTasi + 32);
                }
            }
            cout << "Oyuncu " << oyuncuTasi << " kazandı" << endl;
            cout << "KAZANMA DURUMU" << endl;
            displayBoard();
        }
        return eslesme2;
    }
}

string ConnectFour::dosyaIsmiBelirleme(string girdi, string komut, bool &dosyaKontrol) {
    string dosyaBelirleme = "";
    string txtkontrol = "";
    int arttir = 0;
    int k = girdi.find(komut) + 4;
    int dosyaIsmiBoslukKontrol = 0;

    while (girdi[k] == ' ') {
        ++k;
    }

    for (int i = k; girdi[i] != '\0'; ++i) {
        if (girdi[i] != ' ' && dosyaIsmiBoslukKontrol == 0) {
            dosyaBelirleme.push_back(girdi[i]);

        }
        if (girdi[i] == ' ') {
            ++dosyaIsmiBoslukKontrol;
        }
    }
    if (dosyaIsmiBoslukKontrol == 0) {

        for (int j = 0; dosyaBelirleme[j] != '\0'; ++j) {
            if (dosyaBelirleme[j] == '.') {
                ++arttir;
            }
        }
        //eger dosya adi iccerisinde hiç . karakteri bulamazsa veya birden fazla nokta
        //varsa hata verir
        if (arttir == 0 || arttir > 1) {
            dosyaKontrol = false;
            cerr << "Hatalı dosya ismi girdiniz1!!" << endl;
        } else {

            int m = dosyaBelirleme.find(".");

            while (dosyaBelirleme[m] != '\0') {
                if (dosyaBelirleme[m] != '\0') {
                    txtkontrol.push_back(dosyaBelirleme.at(m));
                }
                ++m;
            }

            //eger girilen dosya adi txt uzantili degilse hata verir
            if (txtkontrol != ".txt" && txtkontrol != ".TXT") {
                cerr << "Hatalı dosya ismi girdiniz2!!" << endl;
                dosyaKontrol = false;
            } else {
                dosyaKontrol = true;
            }
        }
    } else {
        cerr << "Dosya ismi ve uzantısında boşluk olamaz!" << endl;
        dosyaKontrol = false;
    }
    return dosyaBelirleme;
}

void ConnectFour::saveFunc(string gelenFile, int flag) {

    int gecis = -1;
    ofstream dosya(&gelenFile[0]);
    if (!dosya) {
        cerr << "Dosya acilamadii!" << endl;
    } else {

        dosya << getWidth() << "\n";
        dosya << getHeight() << "\n";
        dosya << flag << "\n";

        for (int i = 0; i < getHeight(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (gameBoard[i][j].getInformation() == 'X') {
                    dosya << i << "\n";
                    dosya << j << "\n";
                }
            }
        }
        dosya << gecis << "\n";
        for (int i = 0; i < getHeight(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (gameBoard[i][j].getInformation() == 'O') {
                    dosya << i << "\n";
                    dosya << j << "\n";
                }
            }
        }
        dosya << gecis << "\n";
    }

    dosya.close();
}
//terminalden LOAD komutu girildiginde oyunun kayıt olmuş halini dosyadan okuyarak
//oyunu günceller oyun save sirasında kimde kaldıysa o oyuncudan devam eder

void ConnectFour::loadFunc(string gelenFile, int &flag) {

    int size;
    int satir = 0, sutun = 0;
    ifstream dosya2(&gelenFile[0]);

    if (!dosya2) {
        cerr << "Dosya acilamadii!" << endl;
    } else {

        dosya2>>size;
        setWidth(size);
        dosya2>>size;
        setHeight(size);
        dosya2>>flag;
        if (flag == 0) {
            setTas('O');

        } else {
            setTas('X');
        }

        readFileAndFill(gelenDosya);
        do {
            dosya2>>satir;
            if (satir != -1) {
                dosya2>>sutun;
                gameBoard[satir][sutun].setInformation('X');
            }
        } while (satir != -1);
        do {
            dosya2>>satir;

            if (satir != -1) {
                dosya2>>sutun;
                gameBoard[satir][sutun].setInformation('O');
            }
        } while (satir != -1);
    }
    displayBoard();
    dosya2.close();
}

int ConnectFour::movPlayerComputer(char sutun, int satir) {

    setHarf('a');
    int yataySayi, dikeySayi, caprazSayi;
    int sayiyaCevir = sutun - 97;
    int boslukAlan = (getWidth() - 1) - sayiyaCevir;
    int bilgisayarHamle = 0, hamle = 0;

    yataySayi = yatayKontrolX(sutun);
    dikeySayi = dikeyKontrolX(sutun);
    caprazSayi = caprazKontroller(satir, sutun, 'O');
    do {
        if (boslukAlan == 0) {
            hamle = 1;
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(sutun - hamle);
                if (hamle == getWidth()) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        } else if (yataySayi == 2 || yataySayi == 3) {
            bilgisayarHamle = movPlayerO(sutun + 1);
            hamle = -getWidth();
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(sutun + hamle);
                if (hamle == getWidth()) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        } else if (dikeySayi == 2 || dikeySayi == 3) {
            bilgisayarHamle = movPlayerO(sutun);
            hamle = getWidth();
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(sutun - hamle);
                if (hamle == -getHeight()) {
                    bilgisayarHamle = 1;
                }
                --hamle;
            }
        } else if (caprazSayi == 2 || caprazSayi == 3) {
            bilgisayarHamle = movPlayerO(sutun - 1);
            hamle = -getWidth();
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(sutun + hamle);
                if (hamle == getWidth()) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        } else {
            hamle = -getWidth();
            while (bilgisayarHamle == 0) {
                bilgisayarHamle = movPlayerO(sutun + hamle);
                if (hamle == getWidth()) {
                    bilgisayarHamle = 1;
                }
                ++hamle;
            }
        }
    } while (bilgisayarHamle == 0);
    return 1;
}

void ConnectFour::playGame() {
    cout << "Board Name:";
    cin>>gelenDosya;
    satirSutunBul(gelenDosya);
    gameBoard = new Cell*[height];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[width];
    readFileAndFill(gelenDosya);

    cout << "Player | Computer:";
    cin>>oyunSecimi;
    //Eger kucuk a veya kucuk z varsa buyuk harfe cevirir kontrollerin
    //daha kolay yapilabilmesi icin
    if (oyunSecimi >= 'a' && oyunSecimi <= 'z') {
        oyunSecimi = oyunSecimi - 32;
    } //istenen karakter haricinde bir secim yaildiysa hata verir ve tekrar ister
    while (!(oyunSecimi == 'C' || oyunSecimi == 'P')) {

        cout << "Yanlış oyun seçimi tekrar seçim yapınız!" << endl;
        cout << "Bilgisar ile oynamak icin : C" << endl;
        cout << "Karşılıklı oynamak için   : P" << endl;
        cout << "Oyun türü seçimi: ";
        cin>>oyunSecimi;

        if (oyunSecimi >= 'a' && oyunSecimi <= 'z') {
            oyunSecimi = oyunSecimi - 32;
        }
    }
    displayBoard();
    mainfunc();
}

void ConnectFour::play() {
    int satir;
    satir = satirHesapla(sutun);
    movPlayerComputer(sutun, satir);
    setLivingCell(livingCell + 1);
    cout << "LivingCell:" << livingCell << endl;
    setTas('X');
}

void ConnectFour::play(char sutun) {

    int oyunSirasi = 0;
    if (getTas() == 'X') {
        while (!(movPlayerX(sutun))) {
            cout << "Konum giriniz:";
            cin>>sutun;
            while (!(isValid(sutun))) {
                cout << "Konum giriniz";
                cin>>sutun;
            }
        }
        doluluk = isItFullBoard();
        if (doluluk == getHeight() * getWidth()) {
            cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
        }
        setSutun(sutun);
        playKontrol = yatayKontrolX(sutun);
        playKontrol2 = dikeyKontrolX(sutun);
        satir = satirHesapla(sutun);
        playKontrol3 = caprazKontroller(satir, sutun, getTas());
        setTas('O');
        ++oyunSirasi;
        setLivingCell(livingCell + 1);
    } else if (getTas() == 'O' && oyunSirasi == 0 && getOyunSecimi() == 'P') {

        while (!(movPlayerO(sutun))) {
            cout << "Konum giriniz:";
            cin>>sutun;
            while (!(isValid(sutun))) {
                cout << "Konum giriniz";
                cin>>sutun;
            }
        }
        doluluk = isItFullBoard();
        if (doluluk == getHeight() * getWidth()) {
            cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
        }
        setSutun(sutun);
        playKontrol = yatayKontrolO(sutun);
        playKontrol2 = dikeyKontrolO(sutun);
        satir = satirHesapla(sutun);
        playKontrol3 = caprazKontroller(satir, sutun, getTas());
        setTas('X');
        setLivingCell(livingCell + 1);
        cout << "LivingCell:" << livingCell << endl;
    }

}
