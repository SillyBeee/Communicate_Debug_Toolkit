#include "health_bar.h"
#include <QPainter>
#include <QStyleOption>

HealthBar::HealthBar(QWidget *parent)
    : QWidget(parent), currentHealth(100), maxHealth(100)
{
    setFixedSize(180, 20); // 设置固定大小
}

HealthBar::~HealthBar() {}

void HealthBar::setHealth(int health) {
    currentHealth = health;
    update(); // 调用update()以触发重绘
}

void HealthBar::setMaxHealth(int max) {
    maxHealth = max;
    update(); // 调用update()以触发重绘
}

void HealthBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制背景
    painter.setBrush(QColor(255, 255, 255));
    painter.drawRect(rect());

    // 计算血条的宽度
    double healthRatio = static_cast<double>(currentHealth) / maxHealth;
    int healthWidth = static_cast<int>(healthRatio * width());

    // 绘制血条
    painter.setBrush(QColor(255, 0, 0));
    painter.drawRect(0, 0, healthWidth, height());

    QString healthText = QString("%1").arg(currentHealth);
    painter.setPen(Qt::black);
    painter.drawText(rect(), Qt::AlignCenter, healthText);
}