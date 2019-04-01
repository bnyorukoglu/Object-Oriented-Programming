

#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H

#include "ConnectFourAbstract.h"
namespace bengiSpace{
class ConnectFourPlus : public ConnectFourAbstract {
   
public:
    ConnectFourPlus();
    ConnectFourPlus(const ConnectFourPlus &gelen);
    ConnectFourPlus& operator = (const ConnectFourPlus &otherSide);
protected:

    virtual void mainfunc() override;
    
};
}
#endif /* CONNECTFOURPLUS_H */

