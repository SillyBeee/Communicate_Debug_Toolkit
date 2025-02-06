#ifndef T_COM_GENERAL_CPP
#define T_COM_GENERAL_CPP
#include "T_com_general.h"
#include "ElaText.h"
#include "ElaLineEdit.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QLayout"

T_Com_general::T_Com_general(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("上下位机通信数据总览");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);
    //2个标题
    ElaText* Text_left = new ElaText("视觉自瞄数据");
    Text_left->setTextPixelSize(18);
    ElaText* Text_right = new ElaText("反馈云台数值");
    Text_right->setTextPixelSize(18);
    //各个数据标识
    ElaText* down_find_bool_label = new ElaText("find_bool");
    down_find_bool_label->setTextPixelSize(14);
    ElaText* down_pitch_label = new ElaText("pitch");
    down_pitch_label->setTextPixelSize(14);
    ElaText* down_yaw_label = new ElaText("yaw");
    down_yaw_label->setTextPixelSize(14);
    ElaText* up_enemy_color_label = new ElaText("enemy_team_color");
    up_enemy_color_label->setTextPixelSize(14);
    ElaText* up_pitch_label = new ElaText("pitch");
    up_pitch_label->setTextPixelSize(14);
    ElaText* up_yaw_label = new ElaText("yaw");
    up_yaw_label->setTextPixelSize(14);
    ElaText* up_mode_label = new ElaText("mode");
    up_mode_label->setTextPixelSize(14);
    ElaText* up_rune_flag_label = new ElaText("rune_flag");
    up_rune_flag_label->setTextPixelSize(14);
    //左侧上位机发下位机数据框
    down_find_bool_editor = new ElaLineEdit(this);
    down_find_bool_editor->setReadOnly(true);
    down_pitch_editor = new ElaLineEdit(this);
    down_pitch_editor->setReadOnly(true);
    down_yaw_editor = new ElaLineEdit(this);
    down_yaw_editor->setReadOnly(true);
    //右侧下位机发上位机数据框
    up_enemy_color_editor = new ElaLineEdit(this);
    up_enemy_color_editor->setReadOnly(true);
    up_pitch_editor = new ElaLineEdit(this);
    up_pitch_editor->setReadOnly(true);
    up_yaw_editor = new ElaLineEdit(this);
    up_yaw_editor->setReadOnly(true);
    up_mode_editor = new ElaLineEdit(this);
    up_mode_editor->setReadOnly(true);
    up_rune_flag_editor = new ElaLineEdit(this);
    up_rune_flag_editor->setReadOnly(true);

    //左布局

    QHBoxLayout* left1layout = new QHBoxLayout();
    left1layout->setSizeConstraint(QLayout::SetFixedSize);
    QHBoxLayout* left2layout = new QHBoxLayout();
    QHBoxLayout* left3layout = new QHBoxLayout();
    QHBoxLayout* left0layout = new QHBoxLayout();
    left0layout->addWidget(Text_left);
    left0layout->setAlignment(Qt::AlignCenter);
    left1layout->addWidget(down_find_bool_label);
    left1layout->addWidget(down_find_bool_editor);
    left2layout->addWidget(down_yaw_label);
    left2layout->addWidget(down_yaw_editor);
    left3layout->addWidget(down_pitch_label);
    left3layout->addWidget(down_pitch_editor);

    left0layout->setSizeConstraint(QLayout::SetFixedSize);
    QVBoxLayout* left_total_layout = new QVBoxLayout();
    left_total_layout->addLayout(left0layout);
    left_total_layout->addLayout(left1layout);
    left_total_layout->addLayout(left2layout);
    left_total_layout->addLayout(left3layout);
    left_total_layout->setSpacing(20);
    left_total_layout->setAlignment(Qt::AlignCenter);

    //右布局

    QHBoxLayout* right1layout = new QHBoxLayout();
    QHBoxLayout* right2layout = new QHBoxLayout();
    QHBoxLayout* right3layout = new QHBoxLayout();
    QHBoxLayout* right4layout = new QHBoxLayout();
    QHBoxLayout* right5layout = new QHBoxLayout();
    QHBoxLayout* right0layout = new QHBoxLayout();
    right0layout->addWidget(Text_right);
    right0layout->setAlignment(Qt::AlignCenter);

    right1layout->addWidget(up_enemy_color_label);
    right1layout->addWidget(up_enemy_color_editor);
    right2layout->addWidget(up_mode_label);
    right2layout->addWidget(up_mode_editor);
    right3layout->addWidget(up_rune_flag_label);
    right3layout->addWidget(up_rune_flag_editor);
    right4layout->addWidget(up_yaw_label);
    right4layout->addWidget(up_yaw_editor);
    right5layout->addWidget(up_pitch_label);
    right5layout->addWidget(up_pitch_editor);
    QVBoxLayout* right_total_layout = new QVBoxLayout();
    right_total_layout->addLayout(right0layout);
    right_total_layout->addLayout(right1layout);
    right_total_layout->addLayout(right2layout);
    right_total_layout->addLayout(right3layout);
    right_total_layout->addLayout(right4layout);
    right_total_layout->addLayout(right5layout);
    right_total_layout->setSpacing(20);
    right_total_layout->setAlignment(Qt::AlignCenter);
    //总布局
    QHBoxLayout* total_layout = new QHBoxLayout();
    total_layout->addLayout(left_total_layout);
    total_layout->addLayout(right_total_layout);
    total_layout->setSpacing(100);
    total_layout->setAlignment(Qt::AlignCenter);
    setLayout(total_layout);
}

T_Com_general::~T_Com_general()
{
}

#endif // T_COM_GENERAL_CPP