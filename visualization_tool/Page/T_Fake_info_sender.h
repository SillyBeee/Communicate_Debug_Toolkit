#ifndef T_FAKE_INFO_SENDER_H
#define T_FAKE_INFO_SENDER_H

#include <ElaWidget.h>
#include "ElaLineEdit.h"
#include "ElaSlider.h"
#include "ElaToggleSwitch.h"

class ElaSlider;
class ElaToggleSwitch;
class T_Fake_info_sender : public ElaWidget
{
    Q_OBJECT
public:

    ElaToggleSwitch* engineer_toggleSwitch{nullptr};
    ElaSlider* arm_h0_slider{nullptr};
    ElaSlider* arm_x1_slider{nullptr};
    ElaSlider* arm_q2_slider{nullptr};
    ElaSlider* arm_q3_slider{nullptr};
    ElaSlider* arm_q4_slider{nullptr};
    ElaSlider* arm_q5_slider{nullptr};
    ElaSlider* arm_q6_slider{nullptr};

    ElaLineEdit* arm_h0_editor{nullptr};
    ElaLineEdit* arm_x1_editor{nullptr};
    ElaLineEdit* arm_q2_editor{nullptr};
    ElaLineEdit* arm_q3_editor{nullptr};
    ElaLineEdit* arm_q4_editor{nullptr};
    ElaLineEdit* arm_q5_editor{nullptr};
    ElaLineEdit* arm_q6_editor{nullptr};
    
    explicit T_Fake_info_sender(QWidget* parent = nullptr);
    ~T_Fake_info_sender();

};

#endif // T_FAKE_INFO_SENDER_H