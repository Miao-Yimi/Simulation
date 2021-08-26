#ifndef CABLEBUTTON_H
#define CABLEBUTTON_H

#include <QWidget>
#include <QPushButton>

class CableButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CableButton(QWidget *parent = nullptr);

signals:
    void sendCreateCable();

private slots:
    void lineButtonClicked();

};

#endif // CABLEBUTTON_H
