#ifndef T_ENGINEER_CPP
#define T_ENGINEER_CPP

#include "T_Engineer.h"
#include "ElaText.h"
#include <ElaLineEdit.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
T_Engineer::T_Engineer(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("工程操控数据总览");
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);
    
    QFont font;
    font.setPointSize(15);
    setFont(font);

    // TODO:机械臂控制
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

    ElaLineEdit* arm_control_h0_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_control_x1_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_control_q2_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_control_q3_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_control_q4_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_control_q5_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_control_q6_edit = new ElaLineEdit(this);
    
    QHBoxLayout* arm_control_text_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_h0_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_x1_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_q2_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_q3_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_q4_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_q5_layout = new QHBoxLayout();
    QHBoxLayout* arm_control_q6_layout = new QHBoxLayout();

    arm_control_text_layout->addWidget(arm_control_label);
    arm_control_text_layout->setAlignment(arm_control_label, Qt::AlignCenter);
    arm_control_h0_layout->addWidget(arm_control_h0_label);
    arm_control_h0_layout->addWidget(arm_control_h0_edit);
    arm_control_x1_layout->addWidget(arm_control_x1_label);
    arm_control_x1_layout->addWidget(arm_control_x1_edit);
    arm_control_q2_layout->addWidget(arm_control_q2_label);
    arm_control_q2_layout->addWidget(arm_control_q2_edit);
    arm_control_q3_layout->addWidget(arm_control_q3_label);
    arm_control_q3_layout->addWidget(arm_control_q3_edit);
    arm_control_q4_layout->addWidget(arm_control_q4_label);
    arm_control_q4_layout->addWidget(arm_control_q4_edit);
    arm_control_q5_layout->addWidget(arm_control_q5_label);
    arm_control_q5_layout->addWidget(arm_control_q5_edit);
    arm_control_q6_layout->addWidget(arm_control_q6_label);
    arm_control_q6_layout->addWidget(arm_control_q6_edit);

    QVBoxLayout* arm_control_layout = new QVBoxLayout();
    arm_control_layout->addLayout(arm_control_text_layout);
    arm_control_layout->addLayout(arm_control_h0_layout);
    arm_control_layout->addLayout(arm_control_x1_layout);
    arm_control_layout->addLayout(arm_control_q2_layout);
    arm_control_layout->addLayout(arm_control_q3_layout);
    arm_control_layout->addLayout(arm_control_q4_layout);
    arm_control_layout->addLayout(arm_control_q5_layout);
    arm_control_layout->addLayout(arm_control_q6_layout);
    arm_control_layout->setSpacing(10);



    //TODO:机械臂信息

    ElaText* arm_info_label = new ElaText("机械臂反馈信息", this);
    arm_info_label->setFont(font);
    ElaText* arm_info_h0_label = new ElaText("龙门架抬升: h0", this);
    arm_info_h0_label->setFont(font);
    ElaText* arm_info_x1_label = new ElaText("龙门架滑轨: x1", this);
    arm_info_x1_label->setFont(font);
    ElaText* arm_info_q2_label = new ElaText("肩关节: q2", this);
    arm_info_q2_label->setFont(font);
    ElaText* arm_info_q3_label = new ElaText("肘关节: q3", this);
    arm_info_q3_label->setFont(font);
    ElaText* arm_info_q4_label = new ElaText("腕关节旋转yaw: q4", this);
    arm_info_q4_label->setFont(font);
    ElaText* arm_info_q5_label = new ElaText("腕关节旋转pitch: q5", this);
    arm_info_q5_label->setFont(font);
    ElaText* arm_info_q6_label = new ElaText("腕关节旋转roll: q6", this);
    arm_info_q6_label->setFont(font);

    ElaLineEdit* arm_info_h0_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_info_x1_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_info_q2_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_info_q3_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_info_q4_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_info_q5_edit = new ElaLineEdit(this);
    ElaLineEdit* arm_info_q6_edit = new ElaLineEdit(this);
    
    QHBoxLayout* arm_info_text_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_h0_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_x1_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_q2_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_q3_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_q4_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_q5_layout = new QHBoxLayout();
    QHBoxLayout* arm_info_q6_layout = new QHBoxLayout();

    arm_info_text_layout->addWidget(arm_info_label);
    arm_info_text_layout->setAlignment(arm_info_label, Qt::AlignCenter);
    arm_info_h0_layout->addWidget(arm_info_h0_label);
    arm_info_h0_layout->addWidget(arm_info_h0_edit);
    arm_info_x1_layout->addWidget(arm_info_x1_label);
    arm_info_x1_layout->addWidget(arm_info_x1_edit);
    arm_info_q2_layout->addWidget(arm_info_q2_label);
    arm_info_q2_layout->addWidget(arm_info_q2_edit);
    arm_info_q3_layout->addWidget(arm_info_q3_label);
    arm_info_q3_layout->addWidget(arm_info_q3_edit);
    arm_info_q4_layout->addWidget(arm_info_q4_label);
    arm_info_q4_layout->addWidget(arm_info_q4_edit);
    arm_info_q5_layout->addWidget(arm_info_q5_label);
    arm_info_q5_layout->addWidget(arm_info_q5_edit);
    arm_info_q6_layout->addWidget(arm_info_q6_label);
    arm_info_q6_layout->addWidget(arm_info_q6_edit);

    QVBoxLayout* arm_info_layout = new QVBoxLayout();
    arm_info_layout->addLayout(arm_info_text_layout);
    arm_info_layout->addLayout(arm_info_h0_layout);
    arm_info_layout->addLayout(arm_info_x1_layout);
    arm_info_layout->addLayout(arm_info_q2_layout);
    arm_info_layout->addLayout(arm_info_q3_layout);
    arm_info_layout->addLayout(arm_info_q4_layout);
    arm_info_layout->addLayout(arm_info_q5_layout);
    arm_info_layout->addLayout(arm_info_q6_layout);
    arm_info_layout->setSpacing(10);





    //TODO:交互控制
    ElaText* interaction_control_label = new ElaText("交互控制", this);
    interaction_control_label->setFont(font);
    ElaText* interaction_control_type_label = new ElaText("type (0:吸盘 1:兑换)", this);
    interaction_control_type_label->setFont(font);
    ElaText* interaction_control_content_label = new ElaText("content", this);
    interaction_control_content_label->setFont(font);

    ElaLineEdit* interaction_control_type_edit = new ElaLineEdit(this);
    ElaLineEdit* interaction_control_content_edit = new ElaLineEdit(this);

    QHBoxLayout* interaction_control_text_layout = new QHBoxLayout();
    QHBoxLayout* interaction_control_type_layout = new QHBoxLayout();
    QHBoxLayout* interaction_control_content_layout = new QHBoxLayout();

    interaction_control_text_layout->addWidget(interaction_control_label);
    interaction_control_text_layout->setAlignment(interaction_control_label, Qt::AlignCenter);
    interaction_control_type_layout->addWidget(interaction_control_type_label);
    interaction_control_type_layout->addWidget(interaction_control_type_edit);
    interaction_control_content_layout->addWidget(interaction_control_content_label);
    interaction_control_content_layout->addWidget(interaction_control_content_edit);

    QVBoxLayout* interaction_control_layout = new QVBoxLayout();
    interaction_control_layout->addLayout(interaction_control_text_layout);
    interaction_control_layout->addLayout(interaction_control_type_layout);
    interaction_control_layout->addLayout(interaction_control_content_layout);
    interaction_control_layout->setSpacing(20);
    interaction_control_layout->setAlignment(interaction_control_type_layout, Qt::AlignCenter);






    //TODO:交互信息


    ElaText* interaction_info_label = new ElaText("交互反馈信息", this);
    interaction_info_label->setFont(font);
    ElaText* interaction_info_type_label = new ElaText("type (0:吸盘 1:兑换)", this);
    interaction_info_type_label->setFont(font);
    ElaText* interaction_info_content_label = new ElaText("content", this);
    interaction_info_content_label->setFont(font);

    ElaLineEdit* interaction_info_type_edit = new ElaLineEdit(this);
    ElaLineEdit* interaction_info_content_edit = new ElaLineEdit(this);

    QHBoxLayout* interaction_info_text_layout = new QHBoxLayout();
    QHBoxLayout* interaction_info_type_layout = new QHBoxLayout();
    QHBoxLayout* interaction_info_content_layout = new QHBoxLayout();

    interaction_info_text_layout->addWidget(interaction_info_label);
    interaction_info_text_layout->setAlignment(interaction_info_label, Qt::AlignCenter);
    interaction_info_type_layout->addWidget(interaction_info_type_label);
    interaction_info_type_layout->addWidget(interaction_info_type_edit);
    interaction_info_content_layout->addWidget(interaction_info_content_label);
    interaction_info_content_layout->addWidget(interaction_info_content_edit);

    QVBoxLayout* interaction_info_layout = new QVBoxLayout();
    interaction_info_layout->addLayout(interaction_info_text_layout);
    interaction_info_layout->addLayout(interaction_info_type_layout);
    interaction_info_layout->addLayout(interaction_info_content_layout);
    interaction_info_layout->setSpacing(20);
    interaction_info_layout->setAlignment(interaction_info_type_layout, Qt::AlignCenter);





    QVBoxLayout* main1_layout = new QVBoxLayout();
    QVBoxLayout* main2_layout = new QVBoxLayout();
    QHBoxLayout* main_layout = new QHBoxLayout();

    main1_layout->addLayout(arm_control_layout);
    main1_layout->addLayout(interaction_control_layout);
    main1_layout->setSpacing(10);
    main1_layout->setAlignment(arm_control_layout, Qt::AlignCenter);

    main2_layout->addLayout(arm_info_layout);
    main2_layout->addLayout(interaction_info_layout);
    main2_layout->setSpacing(10);
    main2_layout->setAlignment(arm_info_layout, Qt::AlignCenter);

    main_layout->addLayout(main1_layout);
    main_layout->addLayout(main2_layout);
    main_layout->setSpacing(10);
    main_layout->setAlignment( Qt::AlignCenter);
    
    setLayout(main_layout);
}






T_Engineer::~T_Engineer(){

}



#endif // T_ENGINEER_CPP
