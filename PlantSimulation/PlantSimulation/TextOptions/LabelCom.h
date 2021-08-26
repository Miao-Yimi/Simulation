#ifndef LABELCOM_H
#define LABELCOM_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>

class LabelCom : public QWidget
{
    Q_OBJECT
public:
    explicit LabelCom(QWidget *parent = nullptr);

    QLabel *label;
    QComboBox *combo;

protected:

private:


signals:

};

#endif // LABELCOM_H
