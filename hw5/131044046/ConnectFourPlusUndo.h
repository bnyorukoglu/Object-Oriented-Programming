

#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H

#include "ConnectFourPlus.h"

namespace bengiSpace{
class ConnectFourPlusUndo : public ConnectFourPlus {

    
public:
    ConnectFourPlusUndo();
  ConnectFourPlusUndo(const ConnectFourPlusUndo &gelen);
  ConnectFourPlusUndo& operator = (const ConnectFourPlusUndo &otherSide);
protected:
    virtual void mainfunc() override;
    
};

}

#endif /* CONNECTFOURPLUSUNDO_H */

