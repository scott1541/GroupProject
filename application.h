#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

namespace Ui {
class application;
}

class application : public QMainWindow
{
    Q_OBJECT

public:
    explicit application(QWidget *parent = 0);
    ~application();

private:
    Ui::application *ui;
};

#endif // APPLICATION_H
