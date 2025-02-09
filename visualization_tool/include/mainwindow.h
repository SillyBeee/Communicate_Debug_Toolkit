#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ElaWindow.h"
#include "T_BasePage.h"
#include "T_com_general.h"
#include "T_About.h"
#include "T_Engineer.h"
#include "T_Sential.h"
#include "T_Game_info.h"
#include "T_Fake_info_sender.h"
#include "T_Fake_info_sender_aim.h"
#include <QMutex>
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
    void initTimer();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    //自瞄通信界面
    T_Com_general* general_page{nullptr};
    
    //上位机发
    double down_yaw ;
    double down_pitch ;
    int down_is_find ;
    //下位机发
    double up_yaw ;
    double up_pitch ;
    int up_enemy_color ;
    int up_mode ;
    int up_rune_flag ;

    //关于界面
    T_About* about_page{nullptr};

    //工程机械臂界面
    T_Engineer* engineer_page{nullptr};
    T_Sential* sential_page{nullptr};
    T_Game_info* game_info_page{nullptr};
    T_Fake_info_sender* fake_info_sender_page{nullptr};
    T_Fake_info_sender_aim* fake_info_sender_aim_page{nullptr};

    QMutex general_mutex;
    // QMutex general_down_mutex;
public slots:
    void set_down_data_to_general_page(double down_yaw , double down_pitch , int down_is_find);
    void set_up_data_to_general_page(double up_yaw, double up_pitch, int up_enemy_color, int up_mode, int up_rune_flag);
    void get_data_from_general_page();
private:
    bool m_isDragging;
    QPoint m_startPos;
    
};
#endif // MAINWINDOW_H

