#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *) sender();

    double numbers;
    QString window;

    numbers = (ui->result_window->text() + button->text()).toDouble();

    window = QString::number(numbers, 'g', 12);

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
