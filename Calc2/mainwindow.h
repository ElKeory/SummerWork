#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
private:
    Ui::MainWindow *ui;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_clear_all_clicked();
    void on_pushButton_clear_last_clicked();
    void on_pushButton_result_clicked();
    void math_operations();
    void on_pushButton_root_clicked();
};

#endif // MAINWINDOW_H
