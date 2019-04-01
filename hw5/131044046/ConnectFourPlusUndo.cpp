#include "ConnectFourPlusUndo.h"
namespace bengiSpace {

    ConnectFourPlusUndo::ConnectFourPlusUndo() {

    }

    ConnectFourPlusUndo::ConnectFourPlusUndo(const ConnectFourPlusUndo& gelen) {
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
    }

    ConnectFourPlusUndo& ConnectFourPlusUndo::operator=(const ConnectFourPlusUndo& otherSide) {
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

    void ConnectFourPlusUndo::mainfunc() {


        string dosyaBelirleme;
        int flag = 1, satir = 0;
        string girdi;
        int girdiSize;
        auto kontrol = 0, kontrol1 = 0, kontrol2 = 0;
        auto kazanmaKontrol = 0, kazanmaKontrol2 = 0;
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
                                saveFunc("undo.txt", flag);
                                kontrol1 = movPlayerX(sutun);

                                if (kontrol1 == 1) {
                        
                                    if (isItFullBoard() == getHeight() * getWidth()) {
                                        cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                    }
                                }


                                kazanmaKontrol = yatayKontrolX(sutun);
                                kazanmaKontrol2 = dikeyKontrolX(sutun);

                                satir = satirHesapla(sutun);

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

                            } else if (girdi.substr(spaceCount, 4).compare("UNDO") == 0) {
                                cout << "undo" << endl;
                                loadFunc("undo.txt", flag);
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
                            saveFunc("undo.txt", flag);
                            kontrol2 = movPlayerComputer(sutun, satir);

                            if (kontrol2 == 1) {
             
                                if (isItFullBoard() == getHeight() * getWidth()) {
                                    cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                }
                            }

                            kontrol = yatayKontrolO(sutun);
                            if (kontrol > kazanmaKontrol) {
                                kazanmaKontrol = kontrol;
                            }

                            kontrol = dikeyKontrolO(sutun);
                            if (kontrol > kazanmaKontrol2) {
                                kazanmaKontrol2 = kontrol;
                            }
        
                            satir = satirHesapla(sutun);

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
                                saveFunc("undo.txt", flag);
                                kontrol1 = movPlayerX(sutun);

                                if (kontrol1 == 1) {
                                    if (isItFullBoard() == getHeight() * getWidth()) {
                                        cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                    }
                                }


                                kazanmaKontrol = yatayKontrolX(sutun);
                                kazanmaKontrol2 = dikeyKontrolX(sutun);

                                satir = satirHesapla(sutun);


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
                            } else if (girdi.substr(spaceCount, 4).compare("UNDO") == 0) {
                                cout << "undo" << endl;
                                loadFunc("undo.txt", flag);
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
                                saveFunc("undo.txt", flag);
                                kontrol2 = movPlayerO(sutun);


                                if (kontrol2 == 1) {
                                    //                                tahtaDolumu += 1;
                                    if (isItFullBoard() == getHeight() * getWidth()) {
                                        cerr << "Oyun alanı tamamiyle doldu!!!" << endl;
                                    }
                                }

                                kazanmaKontrol = yatayKontrolO(sutun);
                                kazanmaKontrol2 = dikeyKontrolO(sutun);
                                satir = satirHesapla(sutun);
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
                            } else if (girdi.substr(spaceCount, 4).compare("UNDO") == 0) {
                                cout << "undo" << endl;
                                loadFunc("undo.txt", flag);
                            } else {
                                cerr << "yanlış komut girdiniz tekrar giriniz" << endl;
                            }
                        } while (kontrol2 == 0 || (girdiSize > 1 && flag == 0)); //yanlis hamle yaparsa dongu tekrar doner	
                    }
                    break;
            }
        } while (kazanmaKontrol < 4 && kazanmaKontrol2 < 4 && isItFullBoard() < getWidth() * getHeight());
    }
}