#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AutorecoFram.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSettings>
#include "QLabel"
#include <QtDebug>
#include <vector>
#include <QDoubleSpinBox>
#include <QMap>
#include <QGroupBox>
#include <QSpacerItem>
#include <QSizePolicy>

class AutorecoFram : public QMainWindow
{
	Q_OBJECT
public:
	AutorecoFram(QWidget *parent = Q_NULLPTR);
	~AutorecoFram() { writeSettings("recoConfig.ini"); };
private:
	void crateUi();
	void readSettings(const QString &settingPath);
	void createLabelBox(QString groupName, QGroupBox* groupBox, std::vector<QString> valName, QMap<QString, double> valDict);
	void writeSettings(const QString &settingPath);
private:
	Ui::AutorecoFramClass ui;
	std::vector<std::vector<QString>> m_valName;
	std::vector<QMap<QString, double>> m_valDict;

	QStringList m_groups;
	QMap<QString, QGroupBox*> m_groupBoxes;
	QMap<QString,QMap<QString, QDoubleSpinBox*>> m_doubleBox;
};
