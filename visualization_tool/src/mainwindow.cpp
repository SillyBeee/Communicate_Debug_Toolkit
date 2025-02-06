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
    setIsStayTop(false);
    setUserInfoCardVisible(false);
    setAttribute(Qt::WA_Hover, true);
}

void MainWindow::initContent(){
    // std::cout << "initContent" << std::endl;
    about_page = new T_About(this);
    general_page = new T_Com_general(this);
    sential_page = new T_Sential(this);
    engineer_page = new T_Engineer(this);
    game_info_page = new T_Game_info(this);
    fake_info_sender_page = new T_Fake_info_sender(this);
    fake_info_sender_aim_page = new T_Fake_info_sender_aim(this);

    addPageNode("通信总览",general_page,ElaIconType::MagnifyingGlassChart);
    addPageNode("比赛数据总览",game_info_page,ElaIconType::GamepadModern);
    addPageNode("哨兵&英雄数据总览",sential_page,ElaIconType::Robot);
    addPageNode("工程数据总览",engineer_page,ElaIconType::Wrench);
    addPageNode("自瞄假消息发送器",fake_info_sender_aim_page,ElaIconType::Crosshairs);
    addPageNode("机械臂假消息发送器",fake_info_sender_page,ElaIconType::MessageDots);
    addPageNode("关于",about_page,ElaIconType::User);
    
    // std::cout << "initContent  Finished" << std::endl;
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

