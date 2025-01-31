#ifndef T_SENTIAL_CPP
#define T_SENTIAL_CPP

#include "T_Sential.h"
T_Sential::T_Sential(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("哨兵&英雄数据总览");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);
}

T_Sential::~T_Sential(){

}




#endif // T_SENTIAL_CPP