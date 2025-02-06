#ifndef T_FAKE_INFO_SENDER_AIM_H
#define T_FAKE_INFO_SENDER_AIM_H

#include <ElaWidget.h>
#include "ElaLineEdit.h"
#include "ElaToggleSwitch.h"
#include "ElaSlider.h"
#include "ElaText.h"
class T_Fake_info_sender_aim : public ElaWidget
{
    Q_OBJECT
public:

    ElaSlider* yaw_slider ;
    ElaSlider* pitch_slider ;
    ElaSlider* is_find_slider ;

    ElaToggleSwitch* total_switch ;

    ElaLineEdit* yaw_editor;
    ElaLineEdit* pitch_editor;
    ElaLineEdit* is_find_editor;



    std::atomic<bool> publish_flag{false};
    void set_publish_flag(bool flag);

    void on_yaw_slider_valueChanged(int value);
    void on_pitch_slider_valueChanged(int value);
    void on_is_find_slider_valueChanged(int value);

    void on_yaw_editor_textChanged();
    void on_pitch_editor_textChanged();
    void on_is_find_editor_textChanged();

    explicit T_Fake_info_sender_aim(QWidget* parent = nullptr);
    ~T_Fake_info_sender_aim();

};




#endif // T_FAKE_INFO_SENDER_AIM_H