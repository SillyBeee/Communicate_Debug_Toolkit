#ifndef T_SQUARE_H
#define T_SQUARE_H

#include <ElaWidget.h>
#include "ElaLineEdit.h"
#include "ElaToggleSwitch.h"
#include <atomic>
class T_Square : public ElaWidget
{
    Q_OBJECT
public:
    explicit T_Square(QWidget* parent = nullptr);
    ~T_Square();

    std::atomic<bool> send_flag {false};

    ElaLineEdit* yaw_min_editor{nullptr};
    ElaLineEdit* yaw_max_editor{nullptr};
    ElaLineEdit* time_interval{nullptr};

    ElaToggleSwitch* yaw_switch{nullptr};
};

#endif // T_Square_H
