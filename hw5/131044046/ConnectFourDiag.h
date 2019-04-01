
#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H

#include "ConnectFourAbstract.h"
namespace bengiSpace {

    class ConnectFourDiag : public ConnectFourAbstract {
    public:
        ConnectFourDiag();
        ConnectFourDiag(const ConnectFourDiag &gelen);
        ConnectFourDiag& operator=(const ConnectFourDiag &otherSide);
    protected:
        virtual void mainfunc() override;
        virtual int movPlayerComputer(char sutun, int satir) override;
    };

}

#endif /* CONNECTFOURDIAG_H */

