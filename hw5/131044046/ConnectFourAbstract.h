
#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H
#include "Cell.h"
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;
namespace bengiSpace{
//start of ConnectFour class declaration   
class ConnectFourAbstract {  
    
   public:
        ConnectFourAbstract();
        ConnectFourAbstract(int width,int height);
        ConnectFourAbstract(const string & boardName);
        ConnectFourAbstract(const string& file,char secenek);
	ConnectFourAbstract(const ConnectFourAbstract &gelen);
         ~ConnectFourAbstract();
        virtual void mainfunc() = 0;
        void playGame();
        void play(char sutun);
        void play();
       
        void displayBoard();
        const void takeWidthAndHeight();

        void loadFunc(string gelenFile, int &flag);
        void saveFunc(string gelenFile, int flag);
        string dosyaIsmiBelirleme(string girdi, string komut, bool &dosyaKontrol);
        
        const void setWidth(int genislik) { width = genislik; }
        const void setHeight(int yukseklik) { height = yukseklik; }
        inline const void setHarf(char h) {harf=h;}
        inline void setSutun(char gelenSutun){ sutun=gelenSutun;}
        
        inline int getHarf()const { return harf; }
        inline int getWidth()const { return width; }
        inline int getHeight()const { return height; }
        inline char getTas()const { return oyunTasi; }
        inline const void setTas(char tas) { oyunTasi = tas; }
        inline char getOyunSecimi() const { return oyunSecimi;}
        inline int getPlayKontrol() const { return playKontrol;}
        inline int getPlayKontrol2() const { return playKontrol2;}
        inline int getPlayKontrol3() const { return playKontrol3;}
        ConnectFourAbstract& operator = (const ConnectFourAbstract &otherSide);

    protected:
        // declaration Nested class ends here
        Cell **gameBoard;
        string gelenDosya;
	int isItFullBoard();
        int width, height;
        char oyunSecimi,oyunTasi, harf,sutun;
        int playKontrol, playKontrol2, playKontrol3, satir;
        
        int satirHesapla(char sutun);
        int konulanTasinSatiriniHesapla( char sutun); 
        int isValid(char sutun);
        int movPlayerX(char sutun);
        int movPlayerO(char sutun);
        int yatayKontrolO(char sutun);
        int yatayKontrolX(char sutun);
        int dikeyKontrolX(char sutun);
        int dikeyKontrolO(char sutun);
        int caprazKontroller(int satir, char sutun, char oyuncuTasi);
        virtual int movPlayerComputer(char sutun,int satir);
        void satirSutunBul(const string& gelenFile);
        void readFileAndFill(const string& gelenFile);
}; 
// declaration ConnectFour class ends here
}
#endif /* CONNECTFOURABSTRACT_H */

