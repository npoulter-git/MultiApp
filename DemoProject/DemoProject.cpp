#include "DemoProject.h"

// This screen is the main screen of the application
DemoProject::DemoProject(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DemoProjectClass())
{
    ui->setupUi(this);
}

DemoProject::~DemoProject()
{
    delete ui;
}

// This function will load the notepad application
void DemoProject::on_actionNotepad_triggered() {
    notepad = new Notepad();
    notepad->show();
}