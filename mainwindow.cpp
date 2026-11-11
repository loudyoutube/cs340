#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QAction>
#include <QMenu>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Quit_Button_clicked()
{
    QApplication::quit();
}


void MainWindow::on_File_Button_pressed()
{
    // this will create a new menu container
    QMenu myMenu(this);

    // this adds my choices to the menu
    QAction *newEmailAct = myMenu.addAction("New Email");
    QAction *saveDraftAct = myMenu.addAction("Save Draft");


    QMenu *settingsMenu = myMenu.addMenu("Settings");

     QAction *lightModeAct = settingsMenu -> addAction("Light Mode");
     QAction *darkModeAct = settingsMenu  -> addAction("Dark Mode");


    // this connects choices to actions using a lambda function

    connect(newEmailAct, &QAction::triggered, this, [=]() {
        // put the new email code here
        QMessageBox::information(this, "Outview", "Creating a new email template...");
    });

    connect(saveDraftAct, &QAction::triggered, this, [=]() {
        // put the save sraft code here
    });

        // this adds my choices to the menu

    connect(lightModeAct, &QAction::triggered, this, [=]() {
            // put the dark mode  code here

    });

    connect(darkModeAct, &QAction::triggered, this, [=]() {
            // put the light mode code here
    });


\


    // this will hopefully put the menu at the bottom left of the button
    myMenu.exec(ui->File_Button->mapToGlobal(QPoint(0, ui->File_Button->height())));
}

