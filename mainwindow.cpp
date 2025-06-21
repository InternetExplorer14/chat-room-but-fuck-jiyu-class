#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<cstdlib>

#include<QMessageBox>
#include<QCoreApplication>
#include<QThread>
#include<QDebug>
#include<QStyleHints>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    if (QThread::currentThread() != QApplication::instance()->thread()) {
        qDebug()<<"Not in main thread!\n";
    }

    ui->setupUi(this);
    ui->welcome->setOpenExternalLinks(true);
    setWindowTitle("聊天室");
    connect(ui->login,&QPushButton::clicked,this,&MainWindow::login);

    if(QGuiApplication::styleHints()->colorScheme()==Qt::ColorScheme::Dark){

        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(35, 35, 35));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::Highlight, QColor(142, 45, 197));
        darkPalette.setColor(QPalette::HighlightedText, Qt::white);
        qApp->setPalette(darkPalette);
        qApp->setStyleSheet(
            "QWidget {"
            "    background-color: #2E2E2E;"
            "    color: #FFFFFF;"
            "}"
            "QPushButton {"
            "    background-color: #555555;"
            "    color: #FFFFFF;"
            "    border: 1px solid #888888;"
            "    padding: 5px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #666666;"
            "}"
            "QLabel {"
            "    background-color: transparent;"
            "    color: #FFFFFF;"
            "}"
            "QMenuBar {"
            "    background-color: #2E2E2E;"
            "    color: #FFFFFF;"
            "}"
            "QMenuBar::item {"
            "    background-color: #2E2E2E;"
            "    color: #FFFFFF;"
            "    padding: 4px 8px;"
            "}"
            "QMenuBar::item:selected {"
            "    background-color: #555555;"
            "}"
            "QMenu {"
            "    background-color: #2E2E2E;"
            "    color: #FFFFFF;"
            "    border: 1px solid #888888;"
            "}"
            "QMenu::item {"
            "    background-color: #2E2E2E;"
            "    color: #FFFFFF;"
            "    padding: 4px 20px;"
            "}"
            "QMenu::item:selected {"
            "    background-color: #555555;"
            "}"
            "QToolTip {"
            "    background-color: #2E2E2E;" // 工具提示背景
            "    color: #FFFFFF;" // 工具提示文字
            "    border: 1px solid #888888;" // 边框
            "    padding: 2px;"
            "}"
            );
    }

    {
        this->hide();
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("声明");
        msgBox.setText("本软件保证不掺后门,病毒,窃取文件,文件仅会读写存档、用户主动导入的存档、必要的库,若有问题可能是bug,可以反馈。\n"
                       "作者不对软件的兼容性,稳定性,安全性做保证,仅用于学习使用,作者不对造成的任何后果(包括但不限于被老师抓到,被同学哄抢导致移动存储损坏)赔偿和道歉!\n"
                       "如果你收到了他人辱骂,本人概不负责!\n是否同意？");
        msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgBox.setWindowFlags(msgBox.windowFlags()&~Qt::WindowCloseButtonHint);
        msgBox.setEscapeButton(nullptr);
        msgBox.setButtonText(QMessageBox::Yes, QString("同意"));
        msgBox.setButtonText(QMessageBox::No, QString("不同意(立刻退出)"));
        if(QGuiApplication::styleHints()->colorScheme()==Qt::ColorScheme::Dark){
        }
        int ans=msgBox.exec();
        if(ans==QMessageBox::No){
            qDebug()<<"exiting...\n";
            qApp->quit();
            qDebug()<<"qApp->quit() failed!\n";
            QCoreApplication::exit(0);
            qDebug()<<"QCoreApplication::exit(0) failed!\n";
            exit(0);
            qDebug()<<"exit(0) failed!\n";
        }
        this->show();
    }
    {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("");
        msgBox.setText("已知问题:\n"
                       "    -访问网络问题\n"
                       //"    -\n"
                       //"    -\n"
                       //"    -\n"
                       "\n"
                       "已修复:\n"
                       "    -亮色显示问题\n"
                       //"    -\n"
                       //"    -\n"
                       //"    -\n"
                       "反馈:\n"
                       "    -不能一键切换亮暗色\n"
                       "    -催更反极域，锐捷云系统\n"
                       //"    -\n"
                       //"    -\n"
                       "版本:0.0.1");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes,QString("知道了"));
        int ans=msgBox.exec();
        if(ans==QMessageBox::No){
            qDebug()<<"exiting...\n";
            qApp->quit();
            qDebug()<<"qApp->quit() failed!\n";
            QCoreApplication::exit(0);
            qDebug()<<"QCoreApplication::exit(0) failed!\n";
            exit(0);
            qDebug()<<"exit(0) failed!\n";
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login() {
    QMessageBox::information(this, "提示", "登录还没做呢……");
    //runchatroom_logined(id,);
}
void MainWindow::unlogin(){

}
void MainWindow::run(){

}
/*
void MainWindow::run(int id,){

}
*/
