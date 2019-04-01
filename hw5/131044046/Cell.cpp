
#include "Cell.h"
namespace bengiSpace{
Cell::Cell() {

}
Cell::Cell(char sutun, int satir, char Information) {
    setPosition(sutun);
    setRow(satir);
    setInformation(Information);
}
}