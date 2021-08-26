#ifndef PARTWIDGET_H
#define PARTWIDGET_H

#include <QWidget>

class PartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PartWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

};

#endif // PARTWIDGET_H
