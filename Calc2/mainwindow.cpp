#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QtMath>
#include <QDebug>

double first_num, second_num, window_number;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qApp->installEventFilter(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_negative, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_extent, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_root, SIGNAL(clicked()), this, SLOT(on_pushButton_root_clicked()));
    connect(ui->pushButton_root_n, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_log_n, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(math_operations()));

    connect(ui->pushButton_clear_all, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_all_clicked()));

    connect(ui->pushButton_clear_last, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_last_clicked()));

    connect(ui->pushButton_result, SIGNAL(clicked()), this, SLOT(on_pushButton_result_clicked()));

    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_extent->setCheckable(true);
    ui->pushButton_root->setCheckable(true);
    ui->pushButton_root_n->setCheckable(true);
    ui->pushButton_log->setCheckable(true);
    ui->pushButton_log_n->setCheckable(true);
    ui->pushButton_ln->setCheckable(true);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    double numbers;

    QString window;

    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if(keyEvent->key() >= Qt::Key_0 && keyEvent->key() <= Qt::Key_9)
        {
            //ui->result_window->setText("");
            QString str = QString(QChar(keyEvent->key()));
            ui->result_window->setText(ui->result_window->text() + str);
        }
        else
            if(keyEvent->key() == Qt::Key_Delete)
            {
                on_pushButton_clear_all_clicked();
            }
            else
                if(keyEvent->key() == Qt::Key_Backspace)
                {
                    on_pushButton_clear_last_clicked();
                }
                else
                    if(keyEvent->key() == Qt::Key_Plus)
                    {
                        ui->pushButton_plus->setChecked(true);
                        ui->result_window->setText("");
                        on_pushButton_result_clicked();
                    }
                    else
                        if(keyEvent->key() == Qt::Key_Minus)
                        {
                            ui->pushButton_minus->setChecked(true);
                            ui->result_window->setText("");
                            on_pushButton_result_clicked();
                        }
                        else
                        {
                            ui->result_window->setText("Wrong symbol");
                        }
    }

    QObject::eventFilter(watched, event);

    return QMainWindow::eventFilter(watched, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = static_cast<QPushButton *>(sender());

    double numbers;

    QString window;

    if(ui->result_window->text().contains(".") && button->text() == "0")
    {
        window = ui->result_window->text() + button->text();
    }
    else
    {
        numbers = (ui->result_window->text() + button->text()).toDouble();

        window = QString::number(numbers, 'g', 12);
    }

    ui->result_window->setText(window);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_window->text().contains('.')))
        ui->result_window->setText(ui->result_window->text() + '.');
}

void MainWindow::operations()
{
    QPushButton *button = static_cast<QPushButton *>(sender());

    double numbers;
    QString window;

    if(button->text() == "±")
    {
        numbers = (ui->result_window->text()).toDouble();

        numbers *= -1;

        window = QString::number(numbers, 'g', 12);

        ui->result_window->setText(window);
    }
}

void MainWindow::on_pushButton_clear_all_clicked()
{
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_extent->setChecked(false);

    ui->result_window->setText("0");
}

void MainWindow::on_pushButton_clear_last_clicked()
{
    //ui->result_window->setText(ui->result_window->text().left(ui->result_window->text().leghth() - 1));
}

void MainWindow::on_pushButton_root_clicked()
{
    QString window;

    first_num = ui->result_window->text().toDouble();


}

void MainWindow::on_pushButton_result_clicked()
{
    QString window;

    if(ui->pushButton_minus->isChecked())
    {
        second_num = ui->result_window->text().toDouble();

        window_number = first_num - second_num;

        window = QString::number(window_number, 'g', 12);

        ui->result_window->setText(window);

        ui->pushButton_minus->setChecked(false);
    }
    else
        if(ui->pushButton_plus->isChecked())
        {
            second_num = ui->result_window->text().toDouble();

            window_number = first_num + second_num;

            window = QString::number(window_number, 'g', 12);

            ui->result_window->setText(window);

            ui->pushButton_plus->setChecked(false);
        }
        else
            if(ui->pushButton_divide->isChecked())
            {
                if(second_num == 0)
                {
                    ui->result_window->setText("inf");
                }
                else
                {
                    second_num = ui->result_window->text().toDouble();

                    window_number = first_num / second_num;

                    window = QString::number(window_number, 'g', 12);

                    ui->result_window->setText(window);

                    ui->pushButton_divide->setChecked(false);
                }               
            }
            else
                if(ui->pushButton_multiply->isChecked())
                {
                    second_num = ui->result_window->text().toDouble();

                    window_number = first_num * second_num;

                    window = QString::number(window_number, 'g', 12);

                    ui->result_window->setText(window);

                    ui->pushButton_multiply->setChecked(false);
                }
                else
                    if(first_num < 0)
                    {
                        ui->result_window->setText("Error");
                    }
                    else
                        if(ui->pushButton_root->isChecked())
                        {
                            window_number = qSqrt(first_num);

                            window = QString::number(window_number, 'g', 12);

                            ui->result_window->setText(window);

                            ui->pushButton_root->setChecked(false);
                        }
                        else
                            if(ui->pushButton_extent->isChecked())
                            {
                                second_num = ui->result_window->text().toDouble();

                                window_number = qPow(first_num, second_num);

                                window = QString::number(window_number, 'g', 12);

                                ui->result_window->setText(window);

                                ui->pushButton_extent->setChecked(false);
                            }
                            else
                                if(ui->pushButton_root_n->isChecked())
                                {
                                    second_num = ui->result_window->text().toDouble();

                                    window_number = qPow(first_num, (1 / second_num));

                                    window = QString::number(window_number, 'g', 12);

                                    ui->result_window->setText(window);

                                    ui->pushButton_root_n->setChecked(false);
                                }
                                else
                                    if(ui->pushButton_log->isChecked())
                                    {
                                        second_num = ui->result_window->text().toDouble();

                                        window_number = log(first_num);

                                        window = QString::number(window_number, 'g', 12);

                                        ui->result_window->setText(window);

                                        ui->pushButton_log->setChecked(false);
                                    }
                                    else
                                        if(ui->pushButton_log_n->isChecked())
                                        {
                                            second_num = ui->result_window->text().toDouble();

                                            window_number = log(first_num) / log(second_num);

                                            window = QString::number(window_number, 'g', 12);

                                            ui->result_window->setText(window);

                                            ui->pushButton_log_n->setChecked(false);
                                        }
                                        else
                                            if(ui->pushButton_ln->isChecked())
                                            {
                                                window_number = qLn(first_num);

                                                window = QString::number(window_number, 'g', 12);

                                                ui->result_window->setText(window);

                                                ui->pushButton_ln->setChecked(false);
                                            }
}

void MainWindow::math_operations()
{
    QPushButton *button = static_cast<QPushButton *>(sender());

    first_num = ui->result_window->text().toDouble();

    ui->result_window->setText("");

    button->setChecked(true);
}
