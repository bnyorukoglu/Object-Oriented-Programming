#ifndef CELL_H
#define CELL_H
using namespace std;
namespace bengiSpace{
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
                        
                private:
			char position;
			int row;  
                        char cellInformation;
                        char durum;
                        
	}; 
}
#endif /* CELL_H */

