#ifndef T_COM_GENERAL_H
#define T_COM_GENERAL_H

#include <ElaWidget.h>
#include "ElaLineEdit.h"
class T_Com_general : public ElaWidget
{
    Q_OBJECT
public:
    explicit T_Com_general(QWidget* parent = nullptr);
    ~T_Com_general();

    ElaLineEdit* down_find_bool_editor;
    ElaLineEdit* down_pitch_editor;
    ElaLineEdit* down_yaw_editor;
    ElaLineEdit* up_enemy_color_editor ;
    ElaLineEdit* up_pitch_editor;
    ElaLineEdit* up_yaw_editor;
    ElaLineEdit* up_low_yaw_editor;
    ElaLineEdit* up_mode_editor;
    ElaLineEdit* up_rune_flag_editor;
};

#endif // T_COM_GENERAL_H
