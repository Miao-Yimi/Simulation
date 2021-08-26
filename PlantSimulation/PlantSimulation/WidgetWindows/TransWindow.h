#ifndef TRANSWINDOW_H
#define TRANSWINDOW_H

#include "TextOptions/LabelEditCheck.h"
#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class TransWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TransWindow(QWidget *parent = nullptr);

    LabelEditCheck *textOption,*textOption2;

private:
    QString nameLabel;
signals:

};

#endif // TRANSWINDOW_H
