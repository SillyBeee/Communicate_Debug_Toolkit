#ifndef T_FAKE_INFO_SENDER_CPP
#define T_FAKE_INFO_SENDER_CPP

#include "T_Fake_info_sender.h"
#include "ElaText.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ElaSlider.h"
#include "ElaToggleSwitch.h"

#include <iostream>
T_Fake_info_sender::T_Fake_info_sender(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("机械臂假消息发送器");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);

    QFont font;
    font.setPointSize(10);
    setFont(font);

    //TODO:机械臂控制
    ElaText* arm_control_label = new ElaText("机械臂控制", this);
    arm_control_label->setFont(font);
    ElaText* arm_control_h0_label = new ElaText("龙门架抬升: h0", this);
    arm_control_h0_label->setFont(font);
    ElaText* arm_control_x1_label = new ElaText("龙门架滑轨: x1", this);
    arm_control_x1_label->setFont(font);
    ElaText* arm_control_q2_label = new ElaText("肩关节: q2", this);
    arm_control_q2_label->setFont(font);
    ElaText* arm_control_q3_label = new ElaText("肘关节: q3", this);
    arm_control_q3_label->setFont(font);
    ElaText* arm_control_q4_label = new ElaText("腕关节旋转yaw: q4", this);
    arm_control_q4_label->setFont(font);
    ElaText* arm_control_q5_label = new ElaText("腕关节旋转pitch: q5", this);
    arm_control_q5_label->setFont(font);
    ElaText* arm_control_q6_label = new ElaText("腕关节旋转roll: q6", this);
    arm_control_q6_label->setFont(font);

    //机械臂话题控制开关
    engineer_toggleSwitch = new ElaToggleSwitch(this);

    //机械臂控制滑块
    arm_h0_slider = new ElaSlider(this);
    arm_h0_slider->setRange(0, 100);
    arm_h0_slider->setTracking(false);

    arm_x1_slider = new ElaSlider(this);
    arm_x1_slider->setRange(0, 100);
    arm_x1_slider->setTracking(false);

    arm_q2_slider = new ElaSlider(this);
    arm_q2_slider->setRange(0, 100);
    arm_q2_slider->setTracking(false);

    arm_q3_slider = new ElaSlider(this);
    arm_q3_slider->setRange(0, 100);
    arm_q3_slider->setTracking(false);

    arm_q4_slider = new ElaSlider(this);
    arm_q4_slider->setRange(0, 100);
    arm_q4_slider->setTracking(false);

    arm_q5_slider = new ElaSlider(this);
    arm_q5_slider->setRange(0, 100);
    arm_q5_slider->setTracking(false);

    arm_q6_slider = new ElaSlider(this);
    arm_q6_slider->setRange(0, 100);
    arm_q6_slider->setTracking(false);

    //机械臂控制编辑框
    arm_h0_editor = new ElaLineEdit(this);
    arm_x1_editor = new ElaLineEdit(this);
    arm_q2_editor = new ElaLineEdit(this);
    arm_q3_editor = new ElaLineEdit(this);
    arm_q4_editor = new ElaLineEdit(this);
    arm_q5_editor = new ElaLineEdit(this);
    arm_q6_editor = new ElaLineEdit(this);





    //布局
    QHBoxLayout* arm_control_text_layout = new QHBoxLayout();
    QHBoxLayout* arm_h0_layout = new QHBoxLayout();
    QHBoxLayout* arm_x1_layout = new QHBoxLayout();
    QHBoxLayout* arm_q2_layout = new QHBoxLayout();
    QHBoxLayout* arm_q3_layout = new QHBoxLayout();
    QHBoxLayout* arm_q4_layout = new QHBoxLayout();
    QHBoxLayout* arm_q5_layout = new QHBoxLayout();
    QHBoxLayout* arm_q6_layout = new QHBoxLayout();

    arm_control_text_layout->addWidget(arm_control_label);
    arm_control_text_layout->addWidget(engineer_toggleSwitch);


    arm_h0_layout->addWidget(arm_control_h0_label);
    arm_h0_layout->addWidget(arm_h0_slider);
    arm_h0_layout->addWidget(arm_h0_editor);

    arm_x1_layout->addWidget(arm_control_x1_label);
    arm_x1_layout->addWidget(arm_x1_slider);
    arm_x1_layout->addWidget(arm_x1_editor);

    arm_q2_layout->addWidget(arm_control_q2_label);
    arm_q2_layout->addWidget(arm_q2_slider);
    arm_q2_layout->addWidget(arm_q2_editor);

    arm_q3_layout->addWidget(arm_control_q3_label);
    arm_q3_layout->addWidget(arm_q3_slider);
    arm_q3_layout->addWidget(arm_q3_editor);

    arm_q4_layout->addWidget(arm_control_q4_label);
    arm_q4_layout->addWidget(arm_q4_slider);
    arm_q4_layout->addWidget(arm_q4_editor);

    arm_q5_layout->addWidget(arm_control_q5_label);
    arm_q5_layout->addWidget(arm_q5_slider);
    arm_q5_layout->addWidget(arm_q5_editor);

    arm_q6_layout->addWidget(arm_control_q6_label);
    arm_q6_layout->addWidget(arm_q6_slider);
    arm_q6_layout->addWidget(arm_q6_editor);

    QVBoxLayout* arm_control_layout = new QVBoxLayout();
    
    arm_control_layout->addLayout(arm_control_text_layout);
    arm_control_layout->addLayout(arm_h0_layout);
    arm_control_layout->addLayout(arm_x1_layout);
    arm_control_layout->addLayout(arm_q2_layout);
    arm_control_layout->addLayout(arm_q3_layout);
    arm_control_layout->addLayout(arm_q4_layout);
    arm_control_layout->addLayout(arm_q5_layout);
    arm_control_layout->addLayout(arm_q6_layout);
    arm_control_layout->setSpacing(40);
    setLayout(arm_control_layout);










}


T_Fake_info_sender::~T_Fake_info_sender(){

}





#endif // T_FAKE_INFO_SENDER_CPP    