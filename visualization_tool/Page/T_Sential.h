#ifndef T_SENTIAL_H
#define T_SENTIAL_H

#include <ElaWidget.h>
#include <ElaLineEdit.h>

class T_Sential : public ElaWidget
{
    Q_OBJECT
public:
    ElaLineEdit* Chassis_vx_editor;
    ElaLineEdit* Chassis_vy_editor;

    ElaLineEdit* Interaction_type_editor;
    ElaLineEdit* Interaction_content_editor;

    ElaLineEdit* moudle_ctl_type_editor;
    ElaLineEdit* moudle_ctl_content_editor;

    ElaLineEdit* command_target_x_editor;
    ElaLineEdit* command_target_y_editor;
    ElaLineEdit* command_keyboard_editor;
    ElaLineEdit* command_robot_id_editor;

    ElaLineEdit* hitted_editor;
    
    ElaLineEdit* shoot_status_17_editor;
    ElaLineEdit* shoot_status_42_editor;
    ElaLineEdit* shoot_status_heat_editor;
    ElaLineEdit* shoot_frequency_editor;
    
    explicit T_Sential(QWidget* parent = nullptr);
    ~T_Sential();


};

#endif // T_SENTIAL_H