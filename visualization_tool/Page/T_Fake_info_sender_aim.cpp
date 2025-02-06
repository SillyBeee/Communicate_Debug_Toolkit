#ifndef T_FAKE_INFO_SENDER_AIM_CPP
#define T_FAKE_INFO_SENDER_AIM_CPP

#include "T_Fake_info_sender_aim.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

T_Fake_info_sender_aim::T_Fake_info_sender_aim(QWidget* parent) : ElaWidget(parent){
    setWindowTitle("自瞄假数据发送器");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);

    QFont font;
    font.setPointSize(10);
    setFont(font);


    total_switch = new ElaToggleSwitch(this);
    connect(total_switch, 
    &ElaToggleSwitch::toggled, 
    [=](bool checked){
        this->set_publish_flag(checked);
        }
    );

    ElaText* total_text = new ElaText("自瞄假数据发送");
    total_text->setFont(font);
    ElaText* yaw_text = new ElaText("Yaw:");
    yaw_text->setFont(font);
    ElaText* pitch_text = new ElaText("Pitch:");
    pitch_text->setFont(font);
    ElaText* is_find_text = new ElaText("Is Find:");
    is_find_text->setFont(font);

    yaw_slider = new ElaSlider();
    pitch_slider = new ElaSlider();
    is_find_slider = new ElaSlider();

    yaw_slider->setRange(-3140,3140);
    pitch_slider->setRange(-810,380);
    is_find_slider->setRange(0,1);

    yaw_slider->setTracking(true);
    pitch_slider->setTracking(true);
    is_find_slider->setTracking(true);
    connect(yaw_slider, &ElaSlider::valueChanged, this, &T_Fake_info_sender_aim::on_yaw_slider_valueChanged);
    connect(pitch_slider, &ElaSlider::valueChanged, this, &T_Fake_info_sender_aim::on_pitch_slider_valueChanged);
    connect(is_find_slider, &ElaSlider::valueChanged, this, &T_Fake_info_sender_aim::on_is_find_slider_valueChanged);


    yaw_editor = new ElaLineEdit();
    pitch_editor = new ElaLineEdit();
    is_find_editor = new ElaLineEdit();

    connect(yaw_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender_aim::on_yaw_editor_textChanged);
    connect(pitch_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender_aim::on_pitch_editor_textChanged);
    connect(is_find_editor, &ElaLineEdit::editingFinished, this, &T_Fake_info_sender_aim::on_is_find_editor_textChanged);
    yaw_editor->setText(QString::number(yaw_slider->value()/1000.0));
    pitch_editor->setText(QString::number(pitch_slider->value()/1000.0));
    is_find_editor->setText(QString::number(is_find_slider->value()));
    
    QHBoxLayout* total_text_layout = new QHBoxLayout();
    QHBoxLayout* yaw_layout = new QHBoxLayout();
    QHBoxLayout* pitch_layout = new QHBoxLayout();
    QHBoxLayout* is_find_layout = new QHBoxLayout();

    total_text_layout->addWidget(total_text);
    total_text_layout->addWidget(total_switch);
    yaw_layout->addWidget(yaw_text);
    yaw_layout->addWidget(yaw_slider);
    yaw_layout->addWidget(yaw_editor);
    pitch_layout->addWidget(pitch_text);
    pitch_layout->addWidget(pitch_slider);
    pitch_layout->addWidget(pitch_editor);
    is_find_layout->addWidget(is_find_text);
    is_find_layout->addWidget(is_find_slider);
    is_find_layout->addWidget(is_find_editor);

    QVBoxLayout* total_layout = new QVBoxLayout();
    total_layout->addLayout(total_text_layout);
    total_layout->addLayout(yaw_layout);
    total_layout->addLayout(pitch_layout);
    total_layout->addLayout(is_find_layout);

    setLayout(total_layout);






}


T_Fake_info_sender_aim::~T_Fake_info_sender_aim(){

}

void T_Fake_info_sender_aim::set_publish_flag(bool flag){
    this->publish_flag = flag;
    // set_read_only(flag);
    // std::cout << "publish_flag: " << this->publish_flag << std::endl;
}

void T_Fake_info_sender_aim::on_yaw_slider_valueChanged(int value){
    // std::cout << "yaw_slider_valueChanged: " << value << std::endl;
    yaw_editor->setText(QString::number(value/1000.0));
}

void T_Fake_info_sender_aim::on_pitch_slider_valueChanged(int value){
    // std::cout << "pitch_slider_valueChanged: " << value << std::endl;
    pitch_editor->setText(QString::number(value/1000.0));
}
void T_Fake_info_sender_aim::on_is_find_slider_valueChanged(int value){
    // std::cout << "is_find_slider_valueChanged: " << value << std::endl;
    is_find_editor->setText(QString::number(value));
}

void T_Fake_info_sender_aim::on_yaw_editor_textChanged(){
    // std::cout << "yaw_editor_textChanged: " << text.toStdString() << std::endl;
    double text = yaw_editor->text().toDouble();
    yaw_slider->setValue(text*1000);
}

void T_Fake_info_sender_aim::on_pitch_editor_textChanged(){
    // std::cout << "pitch_editor_textChanged: " << text.toStdString() << std::endl;
    double text = pitch_editor->text().toDouble();
    pitch_slider->setValue(text*1000);
}

void T_Fake_info_sender_aim::on_is_find_editor_textChanged(){
    // std::cout << "is_find_editor_textChanged: " << text.toStdString() << std::endl;
    int text = is_find_editor->text().toInt();
    is_find_slider->setValue(text);
}
#endif // T_FAKE_INFO_SENDER_AIM_CPP