#ifndef SOURCEBUTTON_H
#define SOURCEBUTTON_H

#include "Widgets/SourceWidget.h"
#include <QWidget>
#include <QPushButton>

class SourceButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SourceButton(QWidget *parent = nullptr);

signals:
    void sendCreateSource();

private slots:
    void sourceButtonClicked();

};

#endif // SOURCEBUTTON_H
