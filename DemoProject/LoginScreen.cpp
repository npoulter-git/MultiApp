#include "LoginScreen.h"
#include <QPixmap>

// This screen is for logging into the application
LoginScreen::LoginScreen(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::LoginScreenClass())
{
	ui->setupUi(this);
	QPixmap loginImg("login.png");
	int width = ui->LoginImage->width();
	int height = ui->LoginImage->height();
	ui->LoginImage->setPixmap(loginImg.scaled(width, height, Qt::KeepAspectRatio));
}

LoginScreen::~LoginScreen()
{
	delete ui;
}

// This function will handle clicking of the login button
void LoginScreen::on_loginButton_clicked() {
	if (checkLogin()) {
		hide();
		demo->show();
	}
	else {
		ui->badLogin->setText("Failed to login, please Use Saved Login!");
	}
}

// This function will handle the user clicking the "Use saved info" checkbox
void LoginScreen::on_savedBox_stateChanged() {
	if (ui->savedBox->checkState()) {
		ui->usernameEdit->setText("John Smith");
		ui->passwordEdit->setText("My Password");
	}
	else {
		ui->usernameEdit->setText("");
		ui->passwordEdit->setText("");
	}
}

// This function will check if the login information is valid
bool LoginScreen::checkLogin() {
	return (ui->usernameEdit->text() == "John Smith" && ui->passwordEdit->text() == "My Password");
}