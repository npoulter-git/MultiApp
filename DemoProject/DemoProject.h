#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DemoProject.h"
#include "Notepad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DemoProjectClass; };
QT_END_NAMESPACE

class DemoProject : public QMainWindow
{
    Q_OBJECT

public:
    DemoProject(QWidget *parent = nullptr);
    ~DemoProject();

private:
    Ui::DemoProjectClass *ui;
    Notepad* notepad;

private slots:
    void on_actionNotepad_triggered();
};
