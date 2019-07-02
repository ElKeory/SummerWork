#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

double first_num;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    connect(ui->pushButton_extent, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));

    connect(ui->pushButton_clear_all, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_all_clicked()));

    connect(ui->pushButton_clear_last, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_last_clicked()));

    connect(ui->pushButton_result, SIGNAL(clicked()), this, SLOT(on_pushButton_result_clicked()));

    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvents(QKeyEvent *event)
{
    if(event->key() == Qt::Key_1)
    {

    }
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *) sender();

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
    QPushButton *button = (QPushButton *) sender();

    double numbers;
    QString window;

    if(button->text() == "+/-")
    {
        numbers = (ui->result_window->text()).toDouble();

        numbers *= -1;

        window = QString::number(numbers, 'g', 12);

        ui->result_window->setText(window);
    }
    else
        if(button->text() == "^")
    {
        numbers = (ui->result_window->text()).toDouble();

        numbers *= numbers;

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

    ui->result_window->setText("0");
}

void MainWindow::on_pushButton_clear_last_clicked()
{

}

void MainWindow::on_pushButton_result_clicked()
{
    double window_number, second_num;

    QString window;

    second_num = ui->result_window->text().toDouble();

    if(ui->pushButton_minus->isChecked())
    {
        window_number = first_num - second_num;

        window = QString::number(window_number, 'g', 12);

        ui->result_window->setText(window);
        ui->pushButton_minus->setChecked(false);
    }
    else
        if(ui->pushButton_plus->isChecked())
        {
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
                    window_number = first_num / second_num;

                    window = QString::number(window_number, 'g', 12);

                    ui->result_window->setText(window);
                }
                ui->pushButton_divide->setChecked(false);
            }
            else
                if(ui->pushButton_multiply->isChecked())
                {
                    window_number = first_num * second_num;

                    window = QString::number(window_number, 'g', 12);

                    ui->result_window->text().contains('*');
                    ui->result_window->setText(window);
                    ui->pushButton_multiply->setChecked(false);
                }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender();

    first_num = ui->result_window->text().toDouble();
    //ui->result_window->setText("");

    button->setChecked(true);
}
