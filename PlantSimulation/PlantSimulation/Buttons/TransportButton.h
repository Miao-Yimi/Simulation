#ifndef TRANSPORTBUTTON_H
#define TRANSPORTBUTTON_H

#include <QWidget>
#include <QPushButton>

class TransportButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TransportButton(QWidget *parent = nullptr);

signals:
    void sendCreateTrans();

private slots:
    void transportButtonClicked();

};

#endif // TRANSPORTBUTTON_H
