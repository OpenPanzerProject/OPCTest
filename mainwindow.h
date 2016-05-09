#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStringList>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:


signals:


private slots:
    void changeStackedWidget(const QModelIndex&, const QModelIndex&);
    // A fix for the dual-select bug in Qt 5.6
    //void changeStackedWidget56Fix(const QModelIndex&);

private:
      Ui::MainWindow *ui;
      QStringListModel *listViewWestModel;

};

#endif // MAINWINDOW_H
