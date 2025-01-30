#include "mainwindow.h"
#include <iostream>

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QHBoxLayout>

#include "ElaContentDialog.h"
#include "ElaDockWidget.h"
#include "ElaEventBus.h"
#include "ElaLog.h"
#include "ElaMenu.h"
#include "ElaMenuBar.h"
#include "ElaProgressBar.h"
#include "ElaStatusBar.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaToolBar.h"
#include "ElaToolButton.h"


MainWindow::MainWindow(QWidget *parent)
    : ElaWindow(parent) , m_isDragging(false)
{
    initWindow();
    initContent();
}


void MainWindow::initWindow(){
    setWindowIcon(QIcon(":/ElaWidgetTool.png"));
    resize(1200, 720);
    // ElaLog::getInstance()->initMessageLog(true);
    // eTheme->setThemeMode(ElaThemeType::Dark);
    // setIsNavigationBarEnable(false);
    // setNavigationBarDisplayMode(ElaNavigationType::Compact);
    // setWindowButtonFlag(ElaAppBarType::MinimizeButtonHint, false);
    // setUserInfoCardPixmap(QPixmap(":/Resource/Image/Cirno.jpg"));
    // setUserInfoCardTitle("Ela Tool");
    // setUserInfoCardSubTitle("Liniyous@gmail.com");
    setWindowTitle("Communicate Debug Toolkit");
    // setIsStayTop(true);
    setUserInfoCardVisible(false);
    setAttribute(Qt::WA_Hover, true);
}

void MainWindow::initContent(){
    std::cout << "initContent" << std::endl;
    // general_page = new T_com_general(this);
    
    about_page = new T_About(this);
    general_page = new T_Com_general(this);
    addPageNode("通信总览",general_page,ElaIconType::MagnifyingGlassChart);
    addPageNode("关于",about_page,ElaIconType::User);
    std::cout << "initContent  Finished" << std::endl;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = true;
        m_startPos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - m_startPos);
        event->accept();
    }
}


MainWindow::~MainWindow()
{
}

