#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

//start of ConnectFour class declaration   
class ConnectFour {  
    
   public:
        ConnectFour();
        ConnectFour(int width,int height);
        ConnectFour(const string & boardName);
        ConnectFour(const string& file,char secenek);
	ConnectFour(const ConnectFour &gelen);
        ~ConnectFour();
        void mainfunc();
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
        void setLivingCell(int hucreler){ livingCell=hucreler;}
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
        static int getDoluluk() { return doluluk;}
        ConnectFour& operator = (const ConnectFour &otherSide);
        bool operator ==(const ConnectFour & gelenObj) const;
        bool operator !=(const ConnectFour & gelenObj) const;
   private:
        //start of Nested class declaration  
	class Cell {
		public:
                        Cell(char sutun,int satir,char Information);
                        Cell();
			//getters
			inline char getPosition()const { return position; }
                        inline char getInformation()const { return cellInformation; }
			inline int getRow()const { return row; }
			//setters
			const void setPosition(char pos) { position = pos; }
			const void setRow(int r) { row = r; }
			const void setInformation(char info) { cellInformation = info; }
                        bool operator ==(const Cell & gelenObj) const;
                        void operator ++ ();
                        void operator ++ (int yokSay);
                        void operator -- ();
                        void operator -- (int yokSay);
                        friend istream & operator >>(istream & inputStream, Cell &gelen);
                        friend ostream & operator <<(ostream & outputStream, const Cell &gelen);
                        
                private:
			char position;
			int row;  
                        char cellInformation;
                        char durum;
                        
	}; 
        // declaration Nested class ends here
        Cell **gameBoard;
        string gelenDosya;
	int isItFullBoard();
        static int livingCell;
        static int doluluk;
        int width, height;
        char oyunSecimi,oyunTasi, harf,sutun;
        int playKontrol, playKontrol2, playKontrol3, satir;
        
        friend istream & operator >>(istream & inputStream, ConnectFour::Cell &gelen);
        friend ostream & operator <<(ostream & outputStream, const ConnectFour::Cell &gelen);
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
        int movPlayerComputer(char sutun,int satir);
        void satirSutunBul(const string& gelenFile);
        void readFileAndFill(const string& gelenFile);
}; 
// declaration ConnectFour class ends here
#endif /* CONNECTFOUR_H */