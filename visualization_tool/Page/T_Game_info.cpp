#ifndef T_GAME_INFO_CPP
#define T_GAME_INFO_CPP

#include "T_Game_info.h"
#include <ElaText.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
T_Game_info::T_Game_info(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("比赛信息概览");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);

    QFont font;
    font.setPointSize(12);
    setFont(font);

    //红方信息
    ElaText* r1_robot_hp_text = new ElaText("红1英雄",this);
    r1_robot_hp_text->setFont(font);
    ElaText* r2_robot_hp_text = new ElaText("红2工程",this);
    r2_robot_hp_text->setFont(font);
    ElaText* r3_robot_hp_text = new ElaText("红3步兵",this);
    r3_robot_hp_text->setFont(font);
    ElaText* r4_robot_hp_text = new ElaText("红4步兵",this);
    r4_robot_hp_text->setFont(font);
    ElaText* r5_robot_hp_text = new ElaText("红5步兵",this);
    r5_robot_hp_text->setFont(font);
    ElaText* r7_robot_hp_text = new ElaText("红7哨兵",this);
    r7_robot_hp_text->setFont(font);
    ElaText* red_outpost_hp_text = new ElaText("红方前哨站血量",this);
    red_outpost_hp_text->setFont(font);
    ElaText* red_base_hp_text = new ElaText("红方基地血量",this);
    red_base_hp_text->setFont(font);

    //蓝方信息
    ElaText* b1_robot_hp_text = new ElaText("蓝1英雄",this);
    b1_robot_hp_text->setFont(font);
    ElaText* b2_robot_hp_text = new ElaText("蓝2工程",this);
    b2_robot_hp_text->setFont(font);
    ElaText* b3_robot_hp_text = new ElaText("蓝3步兵",this);
    b3_robot_hp_text->setFont(font);
    ElaText* b4_robot_hp_text = new ElaText("蓝4步兵",this);
    b4_robot_hp_text->setFont(font);
    ElaText* b5_robot_hp_text = new ElaText("蓝5步兵",this);
    b5_robot_hp_text->setFont(font);
    ElaText* b7_robot_hp_text = new ElaText("蓝7哨兵",this);
    b7_robot_hp_text->setFont(font);
    ElaText* blue_outpost_hp_text = new ElaText("蓝方前哨站血量",this);
    blue_outpost_hp_text->setFont(font);
    ElaText* blue_base_hp_text = new ElaText("蓝方基地血量",this);
    blue_base_hp_text->setFont(font);   

    ElaText* enemy_color_text = new ElaText("敌方颜色(0:红 1:蓝)",this);
    enemy_color_text->setFont(font);
    ElaText* game_progress_text = new ElaText("当前比赛阶段",this);
    game_progress_text->setFont(font);
    ElaText* stage_remain_time_text = new ElaText("当前阶段剩余时间",this);
    stage_remain_time_text->setFont(font);
    ElaText* remaining_gold_coin_text = new ElaText("剩余金币",this);
    remaining_gold_coin_text->setFont(font);

    r1_robot_hp_bar = new HealthBar(this);
    r2_robot_hp_bar = new HealthBar(this);
    r3_robot_hp_bar = new HealthBar(this);
    r4_robot_hp_bar = new HealthBar(this);
    r5_robot_hp_bar = new HealthBar(this);
    r7_robot_hp_bar = new HealthBar(this);
    red_outpost_hp_bar = new HealthBar(this);
    red_base_hp_bar = new HealthBar(this);

    b1_robot_hp_bar = new HealthBar(this);
    b2_robot_hp_bar = new HealthBar(this);
    b3_robot_hp_bar = new HealthBar(this);
    b4_robot_hp_bar = new HealthBar(this);
    b5_robot_hp_bar = new HealthBar(this);
    b7_robot_hp_bar = new HealthBar(this);
    blue_outpost_hp_bar = new HealthBar(this);
    blue_base_hp_bar = new HealthBar(this);
    
    enemy_color_editor = new ElaLineEdit(this);
    game_progress_editor = new ElaLineEdit(this);
    Stage_remain_time_editor = new ElaLineEdit(this);
    remaining_gold_coin_editor = new ElaLineEdit(this);

    r1_robot_position_editor = new ElaLineEdit(this);
    r2_robot_position_editor = new ElaLineEdit(this);
    r3_robot_position_editor = new ElaLineEdit(this);
    r4_robot_position_editor = new ElaLineEdit(this);
    r5_robot_position_editor = new ElaLineEdit(this);
    r7_robot_position_editor = new ElaLineEdit(this);

    b1_robot_position_editor = new ElaLineEdit(this);
    b2_robot_position_editor = new ElaLineEdit(this);
    b3_robot_position_editor = new ElaLineEdit(this);
    b4_robot_position_editor = new ElaLineEdit(this);
    b5_robot_position_editor = new ElaLineEdit(this);
    b7_robot_position_editor = new ElaLineEdit(this);
    

    //TODO: 红方布局
    QVBoxLayout* red_side_layout = new QVBoxLayout();
    QHBoxLayout* r1_robot_layout = new QHBoxLayout();
    QHBoxLayout* r2_robot_layout = new QHBoxLayout();
    QHBoxLayout* r3_robot_layout = new QHBoxLayout();
    QHBoxLayout* r4_robot_layout = new QHBoxLayout();
    QHBoxLayout* r5_robot_layout = new QHBoxLayout();
    QHBoxLayout* r7_robot_layout = new QHBoxLayout();
    QHBoxLayout* red_outpost_layout = new QHBoxLayout();
    QHBoxLayout* red_base_layout = new QHBoxLayout();


    r1_robot_layout->addWidget(r1_robot_hp_text);
    r1_robot_layout->addWidget(r1_robot_hp_bar);
    r1_robot_layout->addWidget(r1_robot_position_editor);
    r1_robot_layout->setSpacing(10);

    r2_robot_layout->addWidget(r2_robot_hp_text);
    r2_robot_layout->addWidget(r2_robot_hp_bar);
    r2_robot_layout->addWidget(r2_robot_position_editor);
    r2_robot_layout->setSpacing(10);

    r3_robot_layout->addWidget(r3_robot_hp_text);
    r3_robot_layout->addWidget(r3_robot_hp_bar);
    r3_robot_layout->addWidget(r3_robot_position_editor);
    r3_robot_layout->setSpacing(10);

    r4_robot_layout->addWidget(r4_robot_hp_text);
    r4_robot_layout->addWidget(r4_robot_hp_bar);
    r4_robot_layout->addWidget(r4_robot_position_editor);
    r4_robot_layout->setSpacing(10);

    r5_robot_layout->addWidget(r5_robot_hp_text);
    r5_robot_layout->addWidget(r5_robot_hp_bar);
    r5_robot_layout->addWidget(r5_robot_position_editor);
    r5_robot_layout->setSpacing(10);

    r7_robot_layout->addWidget(r7_robot_hp_text);
    r7_robot_layout->addWidget(r7_robot_hp_bar);
    r7_robot_layout->addWidget(r7_robot_position_editor);
    r7_robot_layout->setSpacing(10);

    red_outpost_layout->addWidget(red_outpost_hp_text);
    red_outpost_layout->addWidget(red_outpost_hp_bar);
    red_outpost_layout->setSpacing(10);

    red_base_layout->addWidget(red_base_hp_text);
    red_base_layout->addWidget(red_base_hp_bar);
    red_base_layout->setSpacing(10);


    red_side_layout->addLayout(r1_robot_layout);
    red_side_layout->addLayout(r2_robot_layout);
    red_side_layout->addLayout(r3_robot_layout);
    red_side_layout->addLayout(r4_robot_layout);
    red_side_layout->addLayout(r5_robot_layout);
    red_side_layout->addLayout(r7_robot_layout);
    red_side_layout->addLayout(red_outpost_layout);
    red_side_layout->addLayout(red_base_layout);
    red_side_layout->setAlignment(Qt::AlignCenter);
    red_side_layout->setSpacing(26);

    //TODO: 蓝方布局
    QVBoxLayout* blue_side_layout = new QVBoxLayout();
    QHBoxLayout* b1_robot_layout = new QHBoxLayout();
    QHBoxLayout* b2_robot_layout = new QHBoxLayout();
    QHBoxLayout* b3_robot_layout = new QHBoxLayout();
    QHBoxLayout* b4_robot_layout = new QHBoxLayout();
    QHBoxLayout* b5_robot_layout = new QHBoxLayout();
    QHBoxLayout* b7_robot_layout = new QHBoxLayout();
    QHBoxLayout* blue_outpost_layout = new QHBoxLayout();
    QHBoxLayout* blue_base_layout = new QHBoxLayout();

    b1_robot_layout->addWidget(b1_robot_hp_text);
    b1_robot_layout->addWidget(b1_robot_hp_bar);
    b1_robot_layout->addWidget(b1_robot_position_editor);
    b1_robot_layout->setSpacing(10);

    b2_robot_layout->addWidget(b2_robot_hp_text);
    b2_robot_layout->addWidget(b2_robot_hp_bar);
    b2_robot_layout->addWidget(b2_robot_position_editor);
    b2_robot_layout->setSpacing(10);

    b3_robot_layout->addWidget(b3_robot_hp_text);
    b3_robot_layout->addWidget(b3_robot_hp_bar);
    b3_robot_layout->addWidget(b3_robot_position_editor);
    b3_robot_layout->setSpacing(10);

    b4_robot_layout->addWidget(b4_robot_hp_text);
    b4_robot_layout->addWidget(b4_robot_hp_bar);
    b4_robot_layout->addWidget(b4_robot_position_editor);
    b4_robot_layout->setSpacing(10);

    b5_robot_layout->addWidget(b5_robot_hp_text);
    b5_robot_layout->addWidget(b5_robot_hp_bar);
    b5_robot_layout->addWidget(b5_robot_position_editor);
    b5_robot_layout->setSpacing(10);

    b7_robot_layout->addWidget(b7_robot_hp_text);
    b7_robot_layout->addWidget(b7_robot_hp_bar);
    b7_robot_layout->addWidget(b7_robot_position_editor);
    b7_robot_layout->setSpacing(10);

    blue_outpost_layout->addWidget(blue_outpost_hp_text);
    blue_outpost_layout->addWidget(blue_outpost_hp_bar);
    blue_outpost_layout->setSpacing(10);

    blue_base_layout->addWidget(blue_base_hp_text);
    blue_base_layout->addWidget(blue_base_hp_bar);
    blue_base_layout->setSpacing(10);

    blue_side_layout->addLayout(b1_robot_layout);
    blue_side_layout->addLayout(b2_robot_layout);
    blue_side_layout->addLayout(b3_robot_layout);
    blue_side_layout->addLayout(b4_robot_layout);
    blue_side_layout->addLayout(b5_robot_layout);
    blue_side_layout->addLayout(b7_robot_layout);
    blue_side_layout->addLayout(blue_outpost_layout);
    blue_side_layout->addLayout(blue_base_layout);

    blue_side_layout->setAlignment(Qt::AlignCenter);
    blue_side_layout->setSpacing(26);

    //TODO: 比赛信息布局
    QVBoxLayout* game_info_layout = new QVBoxLayout();
    QHBoxLayout* enemy_color_layout = new QHBoxLayout();
    QHBoxLayout* game_progress_layout = new QHBoxLayout();
    QHBoxLayout* stage_remain_time_layout = new QHBoxLayout();
    QHBoxLayout* remaining_gold_coin_layout = new QHBoxLayout();
    enemy_color_layout->addWidget(enemy_color_text);
    enemy_color_layout->addWidget(enemy_color_editor);
    game_progress_layout->addWidget(game_progress_text);
    game_progress_layout->addWidget(game_progress_editor);
    stage_remain_time_layout->addWidget(stage_remain_time_text);
    stage_remain_time_layout->addWidget(Stage_remain_time_editor);
    remaining_gold_coin_layout->addWidget(remaining_gold_coin_text);
    remaining_gold_coin_layout->addWidget(remaining_gold_coin_editor);
    
    QHBoxLayout* game_info_1_layout = new QHBoxLayout();
    QHBoxLayout* game_info_2_layout = new QHBoxLayout();
    game_info_1_layout->addLayout(enemy_color_layout);
    game_info_1_layout->addLayout(game_progress_layout);
    game_info_2_layout->addLayout(stage_remain_time_layout);
    game_info_2_layout->addLayout(remaining_gold_coin_layout);
    game_info_layout->addLayout(game_info_1_layout);
    game_info_layout->addLayout(game_info_2_layout);
    game_info_layout->setAlignment(Qt::AlignCenter);
    game_info_layout->setSpacing(40);


    //TODO: 整体布局
    QVBoxLayout* main_layout = new QVBoxLayout();
    QHBoxLayout* submain_layout = new QHBoxLayout();
    submain_layout->addLayout(red_side_layout);
    submain_layout->addLayout(blue_side_layout);
    submain_layout->setSpacing(10);
    main_layout->addLayout(game_info_layout);
    main_layout->addLayout(submain_layout);
    main_layout->setAlignment(Qt::AlignCenter);
    main_layout->setSpacing(30);
    setLayout(main_layout);







}


T_Game_info::~T_Game_info(){

}



#endif // T_GAME_INFO_CPP