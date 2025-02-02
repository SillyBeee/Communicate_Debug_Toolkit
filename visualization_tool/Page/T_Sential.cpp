#ifndef T_SENTIAL_CPP
#define T_SENTIAL_CPP

#include "T_Sential.h"
#include "health_bar.h"
#include <ElaText.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
T_Sential::T_Sential(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("哨兵&英雄数据总览");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);

    QFont font;
    font.setPointSize(12);
    setFont(font);
    
    //TODO:　底盘数据
    ElaText* Chassis_vx_text = new ElaText("底盘x轴速度",this);
    ElaText* Chassis_vy_text = new ElaText("底盘y轴速度",this);
    Chassis_vx_text->setFont(font);
    Chassis_vy_text->setFont(font);
    Chassis_vx_editor = new ElaLineEdit(this);
    Chassis_vy_editor = new ElaLineEdit(this);
    Chassis_vx_editor->setReadOnly(true);
    Chassis_vy_editor->setReadOnly(true);

    QHBoxLayout* Chassis_vx_layout = new QHBoxLayout;
    QHBoxLayout* Chassis_vy_layout = new QHBoxLayout;
    QVBoxLayout* Chassis_layout = new QVBoxLayout;
    Chassis_vx_layout->addWidget(Chassis_vx_text);
    Chassis_vx_layout->addWidget(Chassis_vx_editor);
    Chassis_vy_layout->addWidget(Chassis_vy_text);
    Chassis_vy_layout->addWidget(Chassis_vy_editor);
    Chassis_layout->addLayout(Chassis_vx_layout);
    Chassis_layout->addLayout(Chassis_vy_layout);
    
    //TODO: 交互数据
    ElaText* Interaction_type_text = new ElaText("交互类型(0:无 1:买活 2:买弹丸)",this); 
    ElaText* Interaction_content_text = new ElaText("具体内容",this);
    Interaction_type_text->setFont(font);
    Interaction_content_text->setFont(font);
    Interaction_type_editor = new ElaLineEdit(this);
    Interaction_content_editor = new ElaLineEdit(this);
    Interaction_type_editor->setReadOnly(true);
    Interaction_content_editor->setReadOnly(true);

    QHBoxLayout* Interaction_type_layout = new QHBoxLayout;
    QHBoxLayout* Interaction_content_layout = new QHBoxLayout;
    QVBoxLayout* Interaction_layout = new QVBoxLayout;
    Interaction_type_layout->addWidget(Interaction_type_text);
    Interaction_type_layout->addWidget(Interaction_type_editor);
    Interaction_content_layout->addWidget(Interaction_content_text);
    Interaction_content_layout->addWidget(Interaction_content_editor);
    Interaction_layout->addLayout(Interaction_type_layout);
    Interaction_layout->addLayout(Interaction_content_layout);

    //TODO: 模块控制数据
    ElaText* moudle_ctl_type_text = new ElaText("模块控制类型(0:无 1:小陀螺 2:云台单连发控)",this);
    ElaText* moudle_ctl_content_text = new ElaText("具体内容",this);
    moudle_ctl_type_text->setFont(font);
    moudle_ctl_content_text->setFont(font);
    moudle_ctl_type_editor = new ElaLineEdit(this);
    moudle_ctl_content_editor = new ElaLineEdit(this);
    moudle_ctl_type_editor->setReadOnly(true);
    moudle_ctl_content_editor->setReadOnly(true);

    QHBoxLayout* moudle_ctl_type_layout = new QHBoxLayout;
    QHBoxLayout* moudle_ctl_content_layout = new QHBoxLayout;
    QVBoxLayout* moudle_ctl_layout = new QVBoxLayout;
    moudle_ctl_type_layout->addWidget(moudle_ctl_type_text);
    moudle_ctl_type_layout->addWidget(moudle_ctl_type_editor);
    moudle_ctl_content_layout->addWidget(moudle_ctl_content_text);
    moudle_ctl_content_layout->addWidget(moudle_ctl_content_editor);
    moudle_ctl_layout->addLayout(moudle_ctl_type_layout);
    moudle_ctl_layout->addLayout(moudle_ctl_content_layout);

    //TODO: 指令数据
    ElaText* command_target_x_text = new ElaText("目标位置x",this);
    ElaText* command_target_y_text = new ElaText("目标位置y",this);
    ElaText* command_keyboard_text = new ElaText("键盘指令",this);
    ElaText* command_robot_id_text = new ElaText("机器人ID",this);
    command_target_x_text->setFont(font);
    command_target_y_text->setFont(font);
    command_keyboard_text->setFont(font);
    command_robot_id_text->setFont(font);
    command_target_x_editor = new ElaLineEdit(this);
    command_target_y_editor = new ElaLineEdit(this);
    command_keyboard_editor = new ElaLineEdit(this);
    command_robot_id_editor = new ElaLineEdit(this);
    command_target_x_editor->setReadOnly(true);
    command_target_y_editor->setReadOnly(true);
    command_keyboard_editor->setReadOnly(true);
    command_robot_id_editor->setReadOnly(true);

    QHBoxLayout* command_target_x_layout = new QHBoxLayout;
    QHBoxLayout* command_target_y_layout = new QHBoxLayout;
    QHBoxLayout* command_keyboard_layout = new QHBoxLayout;
    QHBoxLayout* command_robot_id_layout = new QHBoxLayout;
    QVBoxLayout* command_layout = new QVBoxLayout;
    command_target_x_layout->addWidget(command_target_x_text);
    command_target_x_layout->addWidget(command_target_x_editor);
    command_target_y_layout->addWidget(command_target_y_text);
    command_target_y_layout->addWidget(command_target_y_editor);
    command_keyboard_layout->addWidget(command_keyboard_text);
    command_keyboard_layout->addWidget(command_keyboard_editor);
    command_robot_id_layout->addWidget(command_robot_id_text);
    command_robot_id_layout->addWidget(command_robot_id_editor);
    command_layout->addLayout(command_target_x_layout);
    command_layout->addLayout(command_target_y_layout);
    command_layout->addLayout(command_keyboard_layout);
    command_layout->addLayout(command_robot_id_layout);

    //TODO: 受击打数据
    ElaText* hitted_text = new ElaText("受击打",this);
    hitted_text->setFont(font);
    hitted_editor = new ElaLineEdit(this);
    hitted_editor->setReadOnly(true);

    QHBoxLayout* hitted_layout = new QHBoxLayout;
    hitted_layout->addWidget(hitted_text);
    hitted_layout->addWidget(hitted_editor);


    //TODO: 发射数据
    ElaText* shoot_status_17_text = new ElaText("17mm弹丸允许发弹量",this);
    ElaText* shoot_status_42_text = new ElaText("42mm弹丸允许发弹量",this);
    ElaText* shoot_status_heat_text = new ElaText("发射机构热量",this);
    ElaText* shoot_frequency_text = new ElaText("弹丸射速(单位:Hz)",this);
    shoot_status_17_text->setFont(font);
    shoot_status_42_text->setFont(font);
    shoot_status_heat_text->setFont(font);
    shoot_frequency_text->setFont(font);
    shoot_status_17_editor = new ElaLineEdit(this);
    shoot_status_42_editor = new ElaLineEdit(this);
    shoot_status_heat_editor = new ElaLineEdit(this);
    shoot_frequency_editor = new ElaLineEdit(this);
    shoot_status_17_editor->setReadOnly(true);
    shoot_status_42_editor->setReadOnly(true);
    shoot_status_heat_editor->setReadOnly(true);
    shoot_frequency_editor->setReadOnly(true);

    QHBoxLayout* shoot_status_17_layout = new QHBoxLayout;
    QHBoxLayout* shoot_status_42_layout = new QHBoxLayout;
    QHBoxLayout* shoot_status_heat_layout = new QHBoxLayout;
    QHBoxLayout* shoot_frequency_layout = new QHBoxLayout;
    QVBoxLayout* shoot_layout = new QVBoxLayout;
    shoot_status_17_layout->addWidget(shoot_status_17_text);
    shoot_status_17_layout->addWidget(shoot_status_17_editor);
    shoot_status_42_layout->addWidget(shoot_status_42_text);
    shoot_status_42_layout->addWidget(shoot_status_42_editor);
    shoot_status_heat_layout->addWidget(shoot_status_heat_text);
    shoot_status_heat_layout->addWidget(shoot_status_heat_editor);
    shoot_frequency_layout->addWidget(shoot_frequency_text);
    shoot_frequency_layout->addWidget(shoot_frequency_editor);
    shoot_layout->addLayout(shoot_status_17_layout);
    shoot_layout->addLayout(shoot_status_42_layout);
    shoot_layout->addLayout(shoot_status_heat_layout);
    shoot_layout->addLayout(shoot_frequency_layout);




    //TODO: 总布局
    QHBoxLayout* total1_layout = new QHBoxLayout;
    QHBoxLayout* total2_layout = new QHBoxLayout;
    QHBoxLayout* total3_layout = new QHBoxLayout;
    QVBoxLayout* total_layout = new QVBoxLayout;
    total1_layout->addLayout(Chassis_layout);
    total1_layout->addLayout(Interaction_layout);
    total2_layout->addLayout(moudle_ctl_layout);
    total2_layout->addLayout(command_layout);
    total3_layout->addLayout(hitted_layout);
    total3_layout->addLayout(shoot_layout);
    total_layout->addLayout(total1_layout);
    total_layout->addLayout(total2_layout);
    total_layout->addLayout(total3_layout);
    setLayout(total_layout);
}

T_Sential::~T_Sential(){

}




#endif // T_SENTIAL_CPP