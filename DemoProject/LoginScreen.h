#pragma once

#include <QWidget>
#include "ui_LoginScreen.h"
#include "DemoProject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreenClass; };
QT_END_NAMESPACE

class LoginScreen : public QWidget
{
	Q_OBJECT

public:
	LoginScreen(QWidget *parent = nullptr);
	~LoginScreen();

private:
	Ui::LoginScreenClass *ui;
	DemoProject *demo = new DemoProject();

private slots:
	void on_loginButton_clicked();
	void on_savedBox_stateChanged();
	bool checkLogin();
};
