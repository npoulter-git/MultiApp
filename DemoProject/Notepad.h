#pragma once

#include <QMainWindow>
#include "ui_Notepad.h"
#include "FindWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NotepadClass; };
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
	Q_OBJECT

public:
	Notepad(QWidget *parent = nullptr);
	~Notepad();

private:
	Ui::NotepadClass *ui;
	FindWindow* findWindow;

private slots:
	void on_actionNew_triggered();
	void on_actionOpen_triggered();
	void on_actionClose_triggered();
	void on_actionSave_triggered();
	void on_actionFont_triggered();
	void on_actionFont_Color_triggered();
	void on_actionBackground_Color_triggered();
	void on_actionFind_triggered();
	void handleFindText(QString findWord);
	void handleReplaceText(QString findWord, QString replaceWord);
};