#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtEftHelper.h"
#include "JsonReader.h"

class QtEftHelper : public QMainWindow
{
    Q_OBJECT

public:
    QtEftHelper(QWidget *parent = nullptr);
    ~QtEftHelper();

private:
    Ui::QtEftHelperClass ui;
	JsonReader *jsonReader;
};
