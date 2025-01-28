#ifndef WIDGET_H
#define WIDGET_H

#include "UI.h"
#include <QApplication>
#include <QWidget>

class Widget : public QWidget {
    Q_OBJECT
    public:
        Widget(QWidget *parent = nullptr);
        ~Widget();
        Ui_Widget ui;  
    
        
};


#endif // WIDGET_H