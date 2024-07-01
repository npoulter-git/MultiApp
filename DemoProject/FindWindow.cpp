#include "FindWindow.h"

FindWindow::FindWindow(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::FindWindowClass())
{
	ui->setupUi(this);
	connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchClicked()));
	connect(ui->replaceButton, SIGNAL(clicked()), this, SLOT(replaceClicked()));
}

FindWindow::~FindWindow()
{
	delete ui;
}

// This function will handle clicking of the search button and emitting the signal to notepad
void FindWindow::searchClicked() {
	QString findWord = ui->searchEdit->text();
	emit findText(findWord);
}

// This function will handle clicking of the replace button and emitting the signal to notepad
void FindWindow::replaceClicked() {
	QString findWord = ui->searchEdit->text();
	QString replaceWord = ui->replaceEdit->text();
	emit replaceText(findWord, replaceWord);
}