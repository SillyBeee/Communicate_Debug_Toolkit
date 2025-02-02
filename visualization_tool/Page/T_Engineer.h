#ifndef T_ENGINEER_H
#define T_ENGINEER_H

#include <ElaWidget.h>
#include <ElaLineEdit.h>

class T_Engineer : public ElaWidget
{
    Q_OBJECT
public:

    ElaLineEdit* arm_control_h0_edit;
    ElaLineEdit* arm_control_x1_edit;
    ElaLineEdit* arm_control_q2_edit;
    ElaLineEdit* arm_control_q3_edit;
    ElaLineEdit* arm_control_q4_edit;
    ElaLineEdit* arm_control_q5_edit;
    ElaLineEdit* arm_control_q6_edit;
    

    ElaLineEdit* arm_info_h0_edit; 
    ElaLineEdit* arm_info_x1_edit; 
    ElaLineEdit* arm_info_q2_edit; 
    ElaLineEdit* arm_info_q3_edit;
    ElaLineEdit* arm_info_q4_edit; 
    ElaLineEdit* arm_info_q5_edit;
    ElaLineEdit* arm_info_q6_edit; 


    ElaLineEdit* interaction_control_type_edit ;
    ElaLineEdit* interaction_control_content_edit ;

    ElaLineEdit* interaction_info_type_edit ;
    ElaLineEdit* interaction_info_content_edit ;


    explicit T_Engineer(QWidget* parent = nullptr);
    ~T_Engineer();


};

#endif // T_ENGINEER_H
