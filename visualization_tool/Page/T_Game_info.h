#ifndef T_GAME_INFO_H
#define T_GAME_INFO_H

#include <ElaWidget.h>
#include "health_bar.h"
#include <ElaLineEdit.h>
class T_Game_info : public ElaWidget
{
    Q_OBJECT
public:
    HealthBar* r1_robot_hp_bar;
    HealthBar* r2_robot_hp_bar;
    HealthBar* r3_robot_hp_bar;
    HealthBar* r4_robot_hp_bar;
    HealthBar* r5_robot_hp_bar;
    HealthBar* r7_robot_hp_bar;
    HealthBar* red_outpost_hp_bar;
    HealthBar* red_base_hp_bar;

    HealthBar* b1_robot_hp_bar;
    HealthBar* b2_robot_hp_bar;
    HealthBar* b3_robot_hp_bar;
    HealthBar* b4_robot_hp_bar;
    HealthBar* b5_robot_hp_bar;
    HealthBar* b7_robot_hp_bar;
    HealthBar* blue_outpost_hp_bar;
    HealthBar* blue_base_hp_bar;

    ElaLineEdit* enemy_color_editor;
    ElaLineEdit* game_progress_editor;
    ElaLineEdit* Stage_remain_time_editor;
    ElaLineEdit* remaining_gold_coin_editor;

    ElaLineEdit* r1_robot_position_editor;
    ElaLineEdit* r2_robot_position_editor;
    ElaLineEdit* r3_robot_position_editor;
    ElaLineEdit* r4_robot_position_editor;
    ElaLineEdit* r5_robot_position_editor;
    ElaLineEdit* r7_robot_position_editor;

    ElaLineEdit* b1_robot_position_editor;
    ElaLineEdit* b2_robot_position_editor;
    ElaLineEdit* b3_robot_position_editor;
    ElaLineEdit* b4_robot_position_editor;
    ElaLineEdit* b5_robot_position_editor;
    ElaLineEdit* b7_robot_position_editor;

    explicit T_Game_info(QWidget* parent = nullptr);
    ~T_Game_info();
};

#endif // T_GAME_INFO_H
