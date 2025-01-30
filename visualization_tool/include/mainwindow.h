#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ElaWindow.h"
#include "T_BasePage.h"
#include "T_com_general.h"
#include "T_About.h"


class T_Home;
class T_Icon;
class T_ElaScreen;
class T_BaseComponents;
class T_Graphics;
class T_Navigation;
class T_Popup;
class T_Card;
class T_ListView;
class T_TableView;
class T_TreeView;
class T_About;
class T_Setting;
class ElaContentDialog;


class MainWindow : public ElaWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initWindow();
    void initContent();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    T_Com_general* general_page{nullptr};
    T_About* about_page{nullptr};

private:
    bool m_isDragging;
    QPoint m_startPos;
    
};
#endif // MAINWINDOW_H

