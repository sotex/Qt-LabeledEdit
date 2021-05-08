#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->setText("aaaaaa");
    ui->widget->setLabelText(QStringLiteral("用户名"));
    ui->widget->setTipText(QStringLiteral("允许大小写字母、数字、下划线"));
    ui->widget_2->setLabelText(QStringLiteral("密码"));
    ui->widget_2->setTipText(QStringLiteral("任意文字"));
    ui->widget_2->editor()->setEchoMode(QLineEdit::EchoMode::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->widget->editor()->hasFocus()) {
        ui->widget->showCorrect();
        ui->widget->setMsgText("");
    }
    else if (ui->widget_2->editor()->hasFocus()) {
        ui->widget_2->showCorrect();
        ui->widget_2->setMsgText("");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->widget->editor()->hasFocus()) { ui->widget->showWrong(QStringLiteral("用户名已存在")); }
    else if (ui->widget_2->editor()->hasFocus()) {
        ui->widget_2->showWrong(QStringLiteral("密码错误，您还剩余2次机会"), true);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->widget->editor()->hasFocus()) { ui->widget->showLoading(); }
    else if (ui->widget_2->editor()->hasFocus()) {
        ui->widget_2->showLoading();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->widget->editor()->hasFocus()) { ui->widget->hideLoading(); }
    else if (ui->widget_2->editor()->hasFocus()) {
        ui->widget_2->hideLoading();
    }
}
