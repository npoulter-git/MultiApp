#include "Notepad.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QDebug>

Notepad::Notepad(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::NotepadClass())
{
	ui->setupUi(this);
	findWindow = new FindWindow();
	connect(findWindow, SIGNAL(findText(QString)), this, SLOT(handleFindText(QString)));
	connect(findWindow, SIGNAL(replaceText(QString, QString)), this, SLOT(handleReplaceText(QString, QString)));
}

Notepad::~Notepad()
{
	delete ui;
}

// This function will reset the notepad to blank text
void Notepad::on_actionNew_triggered() {
	ui->notepadEdit->setText("");
}

// This function will open a text document and display it in notepad
void Notepad::on_actionOpen_triggered() {
	QString filter = "All File (*.txt)";
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", "./", filter);
	QFile openedFile(fileName);
	if (openedFile.open(QFile::ReadOnly | QFile::Text)) {
		QTextStream input(&openedFile);
		QString text = input.readAll();
		ui->notepadEdit->setText(text);
		openedFile.close();
	}
}

// This function will close notepad
void Notepad::on_actionClose_triggered() {
	hide();
}

// This function will open a save dialog for saving your text document
void Notepad::on_actionSave_triggered() {
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));
	if (fileName.isEmpty()) {
		return;
	}
	QFile saveFile(fileName);
	if (saveFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QTextStream output(&saveFile);
		output << ui->notepadEdit->toPlainText();
		saveFile.close();
	}
}

// This function will allow you to change the font settings
void Notepad::on_actionFont_triggered() {
	bool fontSelect;
	QFont font = QFontDialog::getFont(&fontSelect, this);
	if (fontSelect) {
		ui->notepadEdit->setFont(font);
	}
	else {
		return;
	}
}

// This function will open a dialog for changing the font color
void Notepad::on_actionFont_Color_triggered() {
	QColor color = QColorDialog::getColor(Qt::black, this, "Update Font Color");
	if (color.isValid()) {
		ui->notepadEdit->setTextColor(color);
	}
}

// This function will open a dialog for changing the background color
void Notepad::on_actionBackground_Color_triggered() {
	QColor color = QColorDialog::getColor(Qt::black, this, "Update Font Color");
	if (color.isValid()) {
		QPalette palet = ui->notepadEdit->palette();
		palet.setColor(QPalette::Base, color);
		ui->notepadEdit->setPalette(palet);
	}
}

// This function will open the search dialog
void Notepad::on_actionFind_triggered() {
	findWindow->show();
}

// This function will handle the performing of search from the search dialog
void Notepad::handleFindText(QString findWord) {
	ui->notepadEdit->find(findWord);
}

// This function will replace all text using the search dialog
void Notepad::handleReplaceText(QString findWord, QString replaceWord) {
	QString notepadText = ui->notepadEdit->toPlainText();
	notepadText.replace(findWord, replaceWord, Qt::CaseSensitive);
	ui->notepadEdit->setText(notepadText);
}