#include <iostream>
#include"ConnectFourAbstract.h"
#include"Cell.h"
#include "ConnectFourDiag.h"
#include"ConnectFourPlus.h"
#include "ConnectFourPlusUndo.h"
using namespace std;
using namespace bengiSpace;
int main(int argc, char** argv) {
    char oyunModu;
    ConnectFourPlus myPlusObject;
    ConnectFourDiag myDiagObject;
    ConnectFourPlusUndo myUndoObject;
    do {
        cout << "oyun modunu seçiniz:";
        cin>>oyunModu;
        cin.ignore(400, '\n');
    } while (!((oyunModu == 'D' || oyunModu == 'd') || (oyunModu == 'P' || oyunModu == 'p') || (oyunModu == 'U' || oyunModu == 'u')));



    if (oyunModu == 'D' || oyunModu == 'd') {
        myDiagObject.playGame();
    }
    if (oyunModu == 'P' || oyunModu == 'p') {
        myPlusObject.playGame();
    }
    if (oyunModu == 'U' || oyunModu == 'u') {
        myUndoObject.playGame();
    }

    return 0;
}

