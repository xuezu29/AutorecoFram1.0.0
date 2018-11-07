#include "AutorecoFram.h"

//#define  DEF_LABEL(GROUP,NAM,INDEX)\
//{\
//	QLabel * (NAM) = new QLabel(varName[INDEX], ui.groupBox); \
//	(GROUP)->addWidget((NAM),INDEX,0);\
//}
//
//#define  DEF_DOUBLE_BOX(GROUP,NAM,INDEX)\
//{\
//	QDoubleSpinBox * (NAM) = new QDoubleSpinBox(ui.groupBox); \
//	NAM->setMaximum(999999.99);\
//	NAM->setMinimum(-999999.99);\
//	NAM->setValue(valDict[varName[INDEX]]);\
//	(GROUP)->addWidget((NAM),INDEX,1);\
//}
//
//#define CREATE_LABEL(GROUPBOX,NUM)\
//{\
//	QGridLayout *gruopLayout = new QGridLayout();\
//	for (int i = 0; i < NUM; i++)\
//		{\
//			QString label_name = "label_" + varName[i];\
//			DEF_LABEL(gruopLayout, label_name,i);\
//			QString box_name = "box_" + varName[i];\
//			DEF_DOUBLE_BOX(gruopLayout, box_name, i); \
//		}\
//	ui.groupBox->setLayout(gruopLayout);\
//}

AutorecoFram::AutorecoFram(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	readSettings(QString("recoConfig.ini"));
	crateUi();
}

void AutorecoFram::readSettings(const QString &settingPath)
{
	QSettings settings(settingPath, QSettings::IniFormat);
	m_groups = settings.childGroups();

	QHBoxLayout *groupLayout = new QHBoxLayout(ui.configTab);
	for (int i = 0; i < m_groups.size(); i++)
	{
		QGroupBox *tempGroupBox = new QGroupBox(m_groups[i], ui.configTab);
		m_groupBoxes.insert(m_groups[i], tempGroupBox);
		groupLayout->addWidget(tempGroupBox);
	}
	ui.configTab->setLayout(groupLayout);	

	for (int i = 0; i < m_groups.size(); i++)
	{
		settings.beginGroup(m_groups[i]);
		QStringList vals = settings.allKeys();
		std::vector<QString> valNam;
		QMap<QString, double>valDict;
		for (int j = 0; j < vals.size(); j++)
		{
			valNam.push_back(vals[j]);
			double var_value = settings.value(vals[j]).toDouble();
			valDict.insert(vals[j], var_value);
		}
		settings.endGroup();
		m_valName.push_back(valNam);
		m_valDict.push_back(valDict);
	}
}

void AutorecoFram::createLabelBox(QString groupName, QGroupBox* groupBox, std::vector<QString> valName, QMap<QString, double> valDict)
{
	QGridLayout *setLayout = new QGridLayout(groupBox);
	QMap<QString, QDoubleSpinBox*> doubleBoxes;
	for (int i = 0; i < valDict.size(); i++)
	{
		QLabel * label = new QLabel(valName[i], groupBox);
		setLayout->addWidget(label, i, 0);
		QDoubleSpinBox *doubleBox = new QDoubleSpinBox(groupBox);
		doubleBox->setMaximum(999999.99);
		doubleBox->setMinimum(-999999.99);
		doubleBox->setValue(valDict[valName[i]]);
		doubleBoxes.insert(valName[i], doubleBox);
		setLayout->addWidget(doubleBox, i, 1);
	}
	m_doubleBox.insert(groupName, doubleBoxes);
	setLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	m_groupBoxes["KitConfig"]->setLayout(setLayout);
}

void AutorecoFram::crateUi()
{
	for (int i = 0; i < m_groupBoxes.size(); i++)
	{
		createLabelBox(m_groups[i],m_groupBoxes[m_groups[i]], m_valName[i], m_valDict[i]);
	}
	//m_groupBoxes["KitConfig"]->setAlignment();
	//kitLayout->addLayout(kitSetLayout);
	//kitLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));		
}
void AutorecoFram::writeSettings(const QString &settingPath)
{
	QSettings settings(settingPath, QSettings::IniFormat);
	for (int i =0;i<m_groups.size();i++)
	{
		settings.beginGroup(m_groups[i]);
		for (int j = 0; j<m_valName[i].size();j++)
		{
			settings.setValue(m_valName[i][j], m_doubleBox[m_groups[i]][m_valName[i][j]]->value());
		}
		settings.endGroup();
	}
}