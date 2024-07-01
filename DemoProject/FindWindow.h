#pragma once

#include <QWidget>
#include "ui_FindWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FindWindowClass; };
QT_END_NAMESPACE

class FindWindow : public QWidget
{
	Q_OBJECT

public:
	FindWindow(QWidget *parent = nullptr);
	~FindWindow();

signals:
	void findText(QString findWord);
	void replaceText(QString findWord, QString replaceWord);

private:
	Ui::FindWindowClass *ui;

private slots:
	void searchClicked();
	void replaceClicked();
};
