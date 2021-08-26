#ifndef LABLECOMEDITCHECK_H
#define LABLECOMEDITCHECK_H

#include "Widgets/EditWidget.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QKeyEvent>

class LabelComEditCheck : public QWidget
{
    Q_OBJECT
public:
    explicit LabelComEditCheck(QWidget *parent = nullptr);

    QLabel *label;
    QComboBox *combo;
    EditWidget *edit;
    QCheckBox *check;
    QString str;

protected:
    int timeInterval;//时间间隔
private:
    void timeTransform(QString);
    void dateTimeTransform(QString);
    int hour,min,sec;

signals:
    void sendTimeInterval(int);
    void sendDateTimeInterval(int);

private slots:
    void getKeyPressed();

};

#endif // LABLECOMEDITCHECK_H
