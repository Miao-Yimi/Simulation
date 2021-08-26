#ifndef LABLEEDITCHOCK_H
#define LABLEEDITCHOCK_H

#include "Widgets/EditWidget.h"
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QKeyEvent>

class LabelEditCheck : public QWidget
{
    Q_OBJECT
public:
    explicit LabelEditCheck(QWidget *parent = nullptr);

    QLabel *label;
    EditWidget *edit;
    QCheckBox *check;

    QString str;//获取edit中的文本
    int fontWidth;//获取文本宽度

protected:

private:


signals:
    void sendName(QString,int);
    void sendUpdate();
    void sendTime(QString);
    void sendLength(QString);

private slots:
    void getKeyPressed();

};

#endif // LABLEEDITCHOCK_H
