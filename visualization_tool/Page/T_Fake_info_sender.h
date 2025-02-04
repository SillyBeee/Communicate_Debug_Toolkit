#ifndef T_FAKE_INFO_SENDER_H
#define T_FAKE_INFO_SENDER_H

#include <ElaWidget.h>
#include "ElaLineEdit.h"
#include "ElaSlider.h"
#include "ElaToggleSwitch.h"
#include <atomic>
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

    std::atomic<bool> publish_flag{false};



    //上下限
    double min_h0 = 0;
    double max_h0 = 1.3;
    double min_x1 = 0;
    double max_x1 = 0.8;
    double min_q2 = -3.14;
    double max_q2 = 3.14;
    double min_q3 = -3.14;
    double max_q3 = 3.14;
    double min_q4 = -3.14;
    double max_q4 = 3.14;
    double min_q5 = -3.14;
    double max_q5 = 3.14;
    double min_q6 = -3.14;
    double max_q6 = 3.14;
    
    void set_publish_flag(bool flag);

    void set_read_only(bool flag);
    explicit T_Fake_info_sender(QWidget* parent = nullptr);
    ~T_Fake_info_sender();
private slots:
    //slider槽
    void on_arm_h0_slider_valueChanged(int value);
    void on_arm_x1_slider_valueChanged(int value);
    void on_arm_q2_slider_valueChanged(int value);
    void on_arm_q3_slider_valueChanged(int value);
    void on_arm_q4_slider_valueChanged(int value);
    void on_arm_q5_slider_valueChanged(int value);
    void on_arm_q6_slider_valueChanged(int value);
    //editor槽
    void on_arm_h0_editor_editing_finished();
    void on_arm_x1_editor_editing_finished();
    void on_arm_q2_editor_editing_finished();
    void on_arm_q3_editor_editing_finished();
    void on_arm_q4_editor_editing_finished();
    void on_arm_q5_editor_editing_finished();
    void on_arm_q6_editor_editing_finished();

};

#endif // T_FAKE_INFO_SENDER_H