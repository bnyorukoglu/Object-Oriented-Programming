#include <iostream>
#include"ConnectFour.h"
using namespace std;
int isValid(char sutun, ConnectFour &obje);
char konumGiriniz(ConnectFour &obje);

typedef struct {
    string boardName;
    char secenek;
} multiple;

int main(int argc, char** argv) {
    char oyunModu;
    char tempSecenek = ' ';
    string fileName = "";
    multiple multipArray[5];
    do {
        cout << "oyun modunu seçiniz(S-M):";
        cin>>oyunModu;
        cin.ignore(400, '\n');
    } while (!((oyunModu == 'S' || oyunModu == 's') || (oyunModu == 'M' || oyunModu == 'm')));

    if (oyunModu == 'M' || oyunModu == 'm') {

        for (int i = 0; i < 5; ++i) {

            cout << "Obje" << i + 1 << endl;
            cout << "Board Name:";
            cin>>fileName;
            multipArray[i].boardName = fileName;
            do {
                cout << "player|computer:";
                cin>>tempSecenek;

            } while (!((tempSecenek == 'P' || tempSecenek == 'p') || (tempSecenek == 'C' || tempSecenek == 'c')));
            multipArray[i].secenek = tempSecenek;
        }
    }
    if (oyunModu == 'S' || oyunModu == 's') {

        for (int i = 0; i < 5; i++) {
            multipArray[i].boardName = "";
            multipArray[i].secenek = 'P';
        }
    }
    ConnectFour Obje(fileName, tempSecenek);
    ConnectFour Obje1(multipArray[0].boardName, multipArray[0].secenek);
    ConnectFour Obje2(multipArray[1].boardName, multipArray[1].secenek);
    ConnectFour Obje3(multipArray[2].boardName, multipArray[2].secenek);
    ConnectFour Obje4(multipArray[3].boardName, multipArray[3].secenek);
    ConnectFour Obje5(multipArray[4].boardName, multipArray[4].secenek);

    char sutun;
    int ikiOyun = 2;

    if (oyunModu == 'M' || oyunModu == 'm') {
        do {
            int objeSec;
            do {
                cout << "Obje seçiniz:";
                cin>>objeSec;
                if (cin.fail()) {
                    cin.ignore();
                    cin.clear();
                }
                cin.ignore(400, '\n');
            } while (!(objeSec == 1 || objeSec == 2 || objeSec == 3 || objeSec == 4 || objeSec == 5));
            if (objeSec == 1) {
                if (Obje1.getPlayKontrol() < 4 && Obje1.getPlayKontrol2() < 4 && Obje1.getPlayKontrol3() < 4 && Obje1.getDoluluk() < Obje1.getHeight() * Obje1.getWidth()) {

                    if (Obje1.getOyunSecimi() == 'P') {
                        ikiOyun = 2;
                        while (ikiOyun > 0) {
                            Obje1.displayBoard();

                            sutun = konumGiriniz(Obje1);

                            if (Obje1.getPlayKontrol() < 4 && Obje1.getPlayKontrol2() < 4 && Obje1.getPlayKontrol3() < 4
                                    && Obje1.getDoluluk() < Obje1.getHeight() * Obje1.getWidth()) {
                                Obje1.play(sutun);
                            }
                            --ikiOyun;
                        }
                        if (Obje1 == Obje2)
                            cout << " 1. obje  2. obje ile eşittir " << endl;
                        else
                            cout << " 1. obje  2. obje ile eşit değildir " << endl;
                    } else {
                        Obje1.displayBoard();

                        sutun = konumGiriniz(Obje1);

                        Obje1.play(sutun);
                        if (Obje1.getPlayKontrol() < 4 && Obje1.getPlayKontrol2() < 4 && Obje1.getPlayKontrol3() < 4
                                && Obje1.getDoluluk() < Obje1.getHeight() * Obje1.getWidth())
                            Obje1.play();
                        if (Obje1 == Obje2)
                            cout << " 1. obje  2. obje ile eşittir " << endl;
                        else
                            cout << " 1. obje  2. obje ile eşit değildir " << endl;
                    }

                } else {
                    cerr << "1. oyun bitti başka obje seçiniz." << endl;
                }

            }
            if (objeSec == 2) {

                if (Obje2.getPlayKontrol() < 4 && Obje2.getPlayKontrol2() < 4 && Obje2.getPlayKontrol3() < 4 && Obje2.getDoluluk() < Obje2.getHeight() * Obje2.getWidth()) {

                    if (Obje2.getOyunSecimi() == 'P') {
                        ikiOyun = 2;
                        while (ikiOyun > 0) {
                            Obje2.displayBoard();
                            sutun = konumGiriniz(Obje2);

                            if (Obje2.getPlayKontrol() < 4 && Obje2.getPlayKontrol2() < 4 && Obje2.getPlayKontrol3() < 4
                                    && Obje2.getDoluluk() < Obje2.getHeight() * Obje2.getWidth()) {
                                Obje2.play(sutun);
                            }

                            --ikiOyun;
                        }
                        if (Obje2 == Obje1)
                            cout << "  2. obje 1. obje ile eşittir " << endl;
                        else
                            cout << " 2. obje 1. obje ile eşit değildir " << endl;
                    } else {
                        Obje2.displayBoard();
                        sutun = konumGiriniz(Obje2);

                        Obje2.play(sutun);
                        if (Obje2.getPlayKontrol() < 4 && Obje2.getPlayKontrol2() < 4 && Obje2.getPlayKontrol3() < 4
                                && Obje2.getDoluluk() < Obje2.getHeight() * Obje2.getWidth())
                            Obje2.play();
                        if (Obje2 == Obje1)
                            cout << "  2. obje 1. obje ile eşittir " << endl;
                        else
                            cout << " 2. obje 1. obje ile eşit değildir " << endl;
                    }

                } else {
                    cerr << "2. oyun bitti başka obje seçiniz." << endl;
                }
            }
            if (objeSec == 3) {
                if (Obje3.getPlayKontrol() < 4 && Obje3.getPlayKontrol2() < 4 && Obje3.getPlayKontrol3() < 4 && Obje3.getDoluluk() < Obje3.getHeight() * Obje3.getWidth()) {

                    if (Obje3.getOyunSecimi() == 'P') {
                        ikiOyun = 2;
                        while (ikiOyun > 0) {
                            Obje3.displayBoard();
                            sutun = konumGiriniz(Obje3);
                            if (Obje3.getPlayKontrol() < 4 && Obje3.getPlayKontrol2() < 4 && Obje3.getPlayKontrol3() < 4
                                    && Obje3.getDoluluk() < Obje3.getHeight() * Obje3.getWidth()) {
                                Obje3.play(sutun);
                            }
                            --ikiOyun;
                        }
                    } else {
                        Obje3.displayBoard();
                        sutun = konumGiriniz(Obje3);

                        Obje3.play(sutun);
                        if (Obje3.getPlayKontrol() < 4 && Obje3.getPlayKontrol2() < 4 && Obje3.getPlayKontrol3() < 4
                                && Obje3.getDoluluk() < Obje3.getHeight() * Obje3.getWidth())
                            Obje3.play();
                    }

                } else {
                    cerr << "3. oyun bitti başka obje seçiniz." << endl;
                }
            }
            if (objeSec == 4) {

                if (Obje4.getPlayKontrol() < 4 && Obje4.getPlayKontrol2() < 4 && Obje4.getPlayKontrol3() < 4 && Obje4.getDoluluk() < Obje4.getHeight() * Obje4.getWidth()) {

                    if (Obje4.getOyunSecimi() == 'P') {
                        ikiOyun = 2;
                        while (ikiOyun > 0) {
                            Obje4.displayBoard();
                            sutun = konumGiriniz(Obje4);

                            if (Obje4.getPlayKontrol() < 4 && Obje4.getPlayKontrol2() < 4 && Obje4.getPlayKontrol3() < 4
                                    && Obje4.getDoluluk() < Obje4.getHeight() * Obje4.getWidth()) {
                                Obje4.play(sutun);
                            }
                            --ikiOyun;
                        }
                    } else {
                        Obje4.displayBoard();
                        sutun = konumGiriniz(Obje4);

                        Obje4.play(sutun);
                        if (Obje4.getPlayKontrol() < 4 && Obje4.getPlayKontrol2() < 4 && Obje4.getPlayKontrol3() < 4
                                && Obje4.getDoluluk() < Obje4.getHeight() * Obje4.getWidth())
                            Obje4.play();
                    }

                } else {
                    cerr << "4. oyun bitti başka obje seçiniz." << endl;
                }
            }
            if (objeSec == 5) {

                if (Obje5.getPlayKontrol() < 4 && Obje5.getPlayKontrol2() < 4 && Obje5.getPlayKontrol3() < 4 && Obje5.getDoluluk() < Obje5.getHeight() * Obje5.getWidth()) {

                    if (Obje5.getOyunSecimi() == 'P') {
                        ikiOyun = 2;
                        while (ikiOyun > 0) {
                            Obje5.displayBoard();
                            sutun = konumGiriniz(Obje5);
                            if (Obje5.getPlayKontrol() < 4 && Obje5.getPlayKontrol2() < 4 && Obje5.getPlayKontrol3() < 4
                                    && Obje5.getDoluluk() < Obje5.getHeight() * Obje5.getWidth()) {
                                Obje5.play(sutun);
                            }
                            --ikiOyun;
                        }
                    } else {
                        Obje5.displayBoard();
                        sutun = konumGiriniz(Obje5);

                        Obje5.play(sutun);
                        if (Obje5.getPlayKontrol() < 4 && Obje5.getPlayKontrol2() < 4 && Obje5.getPlayKontrol3() < 4
                                && Obje5.getDoluluk() < Obje5.getHeight() * Obje5.getWidth())
                            Obje5.play();
                    }


                } else {
                    cerr << "5. oyun bitti başka obje seçiniz." << endl;
                }
            }
        } while ((Obje1.getPlayKontrol() < 4 && Obje1.getPlayKontrol2() < 4 && Obje1.getPlayKontrol3() < 4 && Obje1.getDoluluk() < Obje1.getHeight() * Obje1.getWidth()) ||
                (Obje2.getPlayKontrol() < 4 && Obje2.getPlayKontrol2() < 4 && Obje2.getPlayKontrol3() < 4 && Obje2.getDoluluk() < Obje2.getHeight() * Obje2.getWidth()) ||
                (Obje3.getPlayKontrol() < 4 && Obje3.getPlayKontrol2() < 4 && Obje3.getPlayKontrol3() < 4 && Obje3.getDoluluk() < Obje3.getHeight() * Obje3.getWidth()) ||
                (Obje4.getPlayKontrol() < 4 && Obje4.getPlayKontrol2() < 4 && Obje4.getPlayKontrol3() < 4 && Obje4.getDoluluk() < Obje4.getHeight() * Obje4.getWidth()) ||
                (Obje5.getPlayKontrol() < 4 && Obje5.getPlayKontrol2() < 4 && Obje5.getPlayKontrol3() < 4 && Obje5.getDoluluk() < Obje5.getHeight() * Obje5.getWidth()));

        cout << "Bütün objelerin oyunları sonlandı !!" << endl;
    } else if (oyunModu == 'S' || oyunModu == 's') {
        Obje.playGame();
    }
    return 0;
}

int isValid(char sutun, ConnectFour &obje) {
    int sayac = 0;
    char i = 'a';
    int k = 0;
    while (k < obje.getWidth()) {
        if (sutun == i)
            sayac++;
        ++k;
        ++i;
    }
    if (sayac == 0) {
        cerr << "Girdiginiz sutun hatali" << endl;
        return 1;
    } else
        return 0;
}

char konumGiriniz(ConnectFour &obje) {
    char sutun;
    bool dosyaKontrol = true, kontrol = true;
    string dosyaBelirleme, girdi;
    int girdiSize, spaceCount = 0;
    int flag = 0;

    do {
        cout << "Konum giriniz:";
        getline(cin, girdi);

        girdiSize = girdi.size();
        if (girdiSize == 0) {
            exit(0);
        }
        if (obje.getTas() == 'X') {
            flag = 1;
        } else {
            flag = 0;
        }
        for (int i = 0; girdi[i] == ' '; ++i) {
            spaceCount = spaceCount + 1;
        }
        if (girdiSize == 1) {

            sutun = girdi[0];
            if (sutun >= 'A' && sutun <= 'Z') {
                sutun = sutun + 32;
            }
            kontrol = isValid(sutun, obje);

        } else if (girdi.substr(spaceCount, 5).compare("LOAD ") == 0) {

            dosyaBelirleme = obje.dosyaIsmiBelirleme(girdi, "LOAD", dosyaKontrol);
            if (dosyaKontrol) {
                obje.loadFunc(dosyaBelirleme, flag);
            }
        } else if (girdi.substr(spaceCount, 5).compare("SAVE ") == 0) {

            dosyaBelirleme = obje.dosyaIsmiBelirleme(girdi, "SAVE", dosyaKontrol);
            if (dosyaKontrol) {
                obje.saveFunc(dosyaBelirleme, flag);
            }
        } else {
            cerr << "yanlış komut girdiniz tekrar giriniz" << endl;
        }
    } while (kontrol);
    return sutun;
}