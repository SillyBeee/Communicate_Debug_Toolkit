#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <QWidget>

class HealthBar : public QWidget {
    Q_OBJECT
public:
    explicit HealthBar(QWidget *parent = nullptr);
    ~HealthBar();

    void setHealth(int health);
    void setMaxHealth(int max);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int currentHealth;
    int maxHealth;
};

#endif // HEALTH_BAR_H