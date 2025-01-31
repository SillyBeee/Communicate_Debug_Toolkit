#ifndef T_ENGINEER_CPP
#define T_ENGINEER_CPP

#include "T_Engineer.h"

T_Engineer::T_Engineer(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("工程操控数据总览");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);
}

T_Engineer::~T_Engineer(){

}



#endif // T_ENGINEER_CPP
