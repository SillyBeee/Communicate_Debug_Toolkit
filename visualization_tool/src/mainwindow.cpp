#include "mainwindow.h"
#include <iostream>

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QTimer>

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
    initTimer();
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
    square_sender_page = new T_Square(this);

    addPageNode("通信总览",general_page,ElaIconType::MagnifyingGlassChart);
    addPageNode("比赛数据总览",game_info_page,ElaIconType::GamepadModern);
    addPageNode("哨兵&英雄数据总览",sential_page,ElaIconType::Robot);
    addPageNode("工程数据总览",engineer_page,ElaIconType::Wrench);
    addPageNode("自瞄假消息发送器",fake_info_sender_aim_page,ElaIconType::Crosshairs);
    addPageNode("机械臂假消息发送器",fake_info_sender_page,ElaIconType::MessageDots);
    addPageNode("方波发射器",square_sender_page,ElaIconType::WaveSquare);
    addPageNode("关于",about_page,ElaIconType::User);
    
    // std::cout << "initContent  Finished" << std::endl;
}

void MainWindow::initTimer(){
    QTimer* timer_general = new QTimer(this);
    timer_general->setInterval(10);
    timer_general->start();
    connect(timer_general, &QTimer::timeout, this, &MainWindow::get_data_from_general_page);
    
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



void MainWindow::set_down_data_to_general_page(double down_yaw, double down_pitch, int down_is_find){
    QMutexLocker locker(&general_mutex);
    this->general_update_flag = true;
    this->down_yaw = down_yaw;
    this->down_pitch = down_pitch;
    this->down_is_find = down_is_find;
}

void MainWindow::set_up_data_to_general_page(double up_yaw, double up_low_yaw, double up_pitch, int up_enemy_color, int up_mode, int up_rune_flag){
    QMutexLocker locker(&general_mutex);
    this->general_update_flag = true;
    this->up_yaw = up_yaw;
    this->up_low_yaw = up_low_yaw;
    this->up_pitch = up_pitch;
    this->up_enemy_color = up_enemy_color;
    this->up_mode = up_mode;
    this->up_rune_flag = up_rune_flag;
}

void MainWindow::get_data_from_general_page(){
    QMutexLocker locker(&general_mutex);
    // QMutexLocker locker2(&general_up_mutex);
    if (!this->general_update_flag){
        return;
    }
    // std::cout<<"update success"<<std::endl;
    this->general_page->down_find_bool_editor->setText(QString::number(this->down_is_find));
    this->general_page->down_yaw_editor->setText(QString::number(this->down_yaw));
    this->general_page->down_pitch_editor->setText(QString::number(this->down_pitch));
    this->general_page->up_yaw_editor->setText(QString::number(this->up_yaw));
    this->general_page->up_pitch_editor->setText(QString::number(this->up_pitch));
    this->general_page->up_enemy_color_editor->setText(QString::number(this->up_enemy_color));
    this->general_page->up_mode_editor->setText(QString::number(this->up_mode));
    this->general_page->up_rune_flag_editor->setText(QString::number(this->up_rune_flag));
    


}
MainWindow::~MainWindow()
{
    delete general_page;
    delete sential_page;
    delete engineer_page;
    delete game_info_page;
    delete fake_info_sender_page;
    delete fake_info_sender_aim_page;
    delete about_page;
    
}

