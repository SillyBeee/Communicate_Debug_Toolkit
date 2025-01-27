#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent){
    ui.setupUi(this);
    this->setWindowTitle("Communicate Debug TookKit");
}

Widget::~Widget(){
    
}

