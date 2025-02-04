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
    connect(engineer_toggleSwitch, 
    &ElaToggleSwitch::toggled, 
    [=](bool checked){
        this->set_publish_flag(checked);
        }
    );
        


    //机械臂控制编辑框
    arm_h0_editor = new ElaLineEdit(this);
    connect(arm_h0_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_h0_editor_editing_finished);
    arm_x1_editor = new ElaLineEdit(this);
    connect(arm_x1_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_x1_editor_editing_finished);
    arm_q2_editor = new ElaLineEdit(this);
    connect(arm_q2_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_q2_editor_editing_finished);
    arm_q3_editor = new ElaLineEdit(this);
    connect(arm_q3_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_q3_editor_editing_finished);
    arm_q4_editor = new ElaLineEdit(this);
    connect(arm_q4_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_q4_editor_editing_finished);
    arm_q5_editor = new ElaLineEdit(this);
    connect(arm_q5_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_q5_editor_editing_finished);
    arm_q6_editor = new ElaLineEdit(this);
    connect(arm_q6_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender::on_arm_q6_editor_editing_finished);
    
    
    
    //机械臂控制滑块
    arm_h0_slider = new ElaSlider(this);
    arm_h0_slider->setRange(min_h0*100, max_h0*100);
    arm_h0_slider->setTracking(true);
    arm_h0_editor->setText(QString::number((arm_h0_slider->value())/100.0));
    connect(arm_h0_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_h0_slider_valueChanged);

    

    arm_x1_slider = new ElaSlider(this);
    arm_x1_slider->setRange(min_x1*100, max_x1*100);
    arm_x1_slider->setTracking(true);
    arm_x1_editor->setText(QString::number((arm_x1_slider->value())/100.0));
    connect(arm_x1_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_x1_slider_valueChanged);

    arm_q2_slider = new ElaSlider(this);
    arm_q2_slider->setRange(min_q2*100, max_q2*100);
    arm_q2_slider->setTracking(true);
    arm_q2_editor->setText(QString::number((arm_q2_slider->value())/100.0));
    connect(arm_q2_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_q2_slider_valueChanged);

    arm_q3_slider = new ElaSlider(this);
    arm_q3_slider->setRange(min_q3*100, max_q3*100);
    arm_q3_slider->setTracking(true);
    arm_q3_editor->setText(QString::number((arm_q3_slider->value())/100.0));
    connect(arm_q3_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_q3_slider_valueChanged);

    arm_q4_slider = new ElaSlider(this);
    arm_q4_slider->setRange(min_q4*100, max_q4*100);
    arm_q4_slider->setTracking(true);
    arm_q4_editor->setText(QString::number((arm_q4_slider->value())/100.0));
    connect(arm_q4_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_q4_slider_valueChanged);

    arm_q5_slider = new ElaSlider(this);
    arm_q5_slider->setRange(min_q5*100, max_q5*100);
    arm_q5_slider->setTracking(true);
    arm_q5_editor->setText(QString::number((arm_q5_slider->value())/100.0));
    connect(arm_q5_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_q5_slider_valueChanged);

    arm_q6_slider = new ElaSlider(this);
    arm_q6_slider->setRange(min_q6*100, max_q6*100);
    arm_q6_slider->setTracking(true);
    arm_q6_editor->setText(QString::number((arm_q6_slider->value())/100.0));
    connect(arm_q6_slider,&ElaSlider::valueChanged,this,&T_Fake_info_sender::on_arm_q6_slider_valueChanged);

    



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
    arm_control_layout->setSpacing(35);
    setLayout(arm_control_layout);










}


T_Fake_info_sender::~T_Fake_info_sender(){

}

void T_Fake_info_sender::set_publish_flag(bool flag){
    this->publish_flag = flag;
    set_read_only(flag);
    // std::cout << "publish_flag: " << this->publish_flag << std::endl;
}


void T_Fake_info_sender::set_read_only(bool flag){
    arm_h0_slider->setDisabled(flag);
    arm_x1_slider->setDisabled(flag);
    arm_q2_slider->setDisabled(flag);
    arm_q3_slider->setDisabled(flag);
    arm_q4_slider->setDisabled(flag);
    arm_q5_slider->setDisabled(flag);
    arm_q6_slider->setDisabled(flag);
    arm_h0_editor->setReadOnly(flag);
    arm_x1_editor->setReadOnly(flag);
    arm_q2_editor->setReadOnly(flag);
    arm_q3_editor->setReadOnly(flag);
    arm_q4_editor->setReadOnly(flag);
    arm_q5_editor->setReadOnly(flag);
    arm_q6_editor->setReadOnly(flag);
}
void T_Fake_info_sender::on_arm_h0_slider_valueChanged(int value){
    arm_h0_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_h0_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_x1_slider_valueChanged(int value){
    arm_x1_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_x1_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_q2_slider_valueChanged(int value){
    arm_q2_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_q2_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_q3_slider_valueChanged(int value){
    arm_q3_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_q3_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_q4_slider_valueChanged(int value){
    arm_q4_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_q4_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_q5_slider_valueChanged(int value){
    arm_q5_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_q5_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_q6_slider_valueChanged(int value){
    arm_q6_editor->setText(QString::number(value/100.0));
    // std::cout << "arm_q6_slider value: " << value/100.0 << std::endl;
}

void T_Fake_info_sender::on_arm_h0_editor_editing_finished(){
    double value = arm_h0_editor->text().toDouble();
    if (value > min_h0 && value < max_h0){
        arm_h0_slider->setValue(value*100);
    }
    else if (value <= min_h0){
        arm_h0_slider->setValue(min_h0*100);
        arm_h0_editor->setText(QString::number(min_h0));
    }
    else if (value >= max_h0){
        arm_h0_slider->setValue(max_h0*100);
        arm_h0_editor->setText(QString::number(max_h0));
    }
}

void T_Fake_info_sender::on_arm_x1_editor_editing_finished(){
    double value = arm_x1_editor->text().toDouble();
    if (value > min_x1 && value < max_x1){
        arm_x1_slider->setValue(value*100);
    }
    else if (value <= min_x1){
        arm_x1_slider->setValue(min_x1*100);
        arm_x1_editor->setText(QString::number(min_x1));
    }
    else if (value >= max_x1){
        arm_x1_slider->setValue(max_x1*100);
        arm_x1_editor->setText(QString::number(max_x1));
    }
}
void T_Fake_info_sender::on_arm_q2_editor_editing_finished(){
    double value = arm_q2_editor->text().toDouble();
    if (value > min_q2 && value < max_q2){
        arm_q2_slider->setValue(value*100);
    }
    else if (value <= min_q2){
        arm_q2_slider->setValue(min_q2*100);
        arm_q2_editor->setText(QString::number(min_q2));
    }
    else if (value >= max_q2){
        arm_q2_slider->setValue(max_q2*100);
        arm_q2_editor->setText(QString::number(max_q2));
    }
}

void T_Fake_info_sender::on_arm_q3_editor_editing_finished(){
    double value = arm_q3_editor->text().toDouble();
    if (value > min_q3 && value < max_q3){
        arm_q3_slider->setValue(value*100);
    }
    else if (value <= min_q3){
        arm_q3_slider->setValue(min_q3*100);
        arm_q3_editor->setText(QString::number(min_q3));
    }
    else if (value >= max_q3){
        arm_q3_slider->setValue(max_q3*100);
        arm_q3_editor->setText(QString::number(max_q3));
    }
}
void T_Fake_info_sender::on_arm_q4_editor_editing_finished(){
    double value = arm_q4_editor->text().toDouble();
    if (value > min_q4 && value < max_q4){
        arm_q4_slider->setValue(value*100);
    }
    else if (value <= min_q4){
        arm_q4_slider->setValue(min_q4*100);
        arm_q4_editor->setText(QString::number(min_q4));
    }
    else if (value >= max_q4){
        arm_q4_slider->setValue(max_q4*100);
        arm_q4_editor->setText(QString::number(max_q4));
    }
}

void T_Fake_info_sender::on_arm_q5_editor_editing_finished(){
    double value = arm_q5_editor->text().toDouble();
    if (value > min_q5 && value < max_q5){
        arm_q5_slider->setValue(value*100);
    }
    else if (value <= min_q5){
        arm_q5_slider->setValue(min_q5*100);
        arm_q5_editor->setText(QString::number(min_q5));
    }
    else if (value >= max_q5){
        arm_q5_slider->setValue(max_q5*100);
        arm_q5_editor->setText(QString::number(max_q5));
    }
}
void T_Fake_info_sender::on_arm_q6_editor_editing_finished(){
    double value = arm_q6_editor->text().toDouble();
    if (value > min_q6 && value < max_q6){
        arm_q6_slider->setValue(value*100);
    }
    else if (value <= min_q6){
        arm_q6_slider->setValue(min_q6*100);
        arm_q6_editor->setText(QString::number(min_q6));
    }
    else if (value >= max_q6){
        arm_q6_slider->setValue(max_q6*100);
        arm_q6_editor->setText(QString::number(max_q6));
    }
}


#endif // T_FAKE_INFO_SENDER_CPP    