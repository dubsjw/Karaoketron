#include "src/Viewer.h"
#include <QFileDialog>

Viewer::Viewer()
: QDialog(nullptr)
, m_ui()
, m_model(nullptr)
, m_widget(nullptr)
, m_layout(nullptr)
{
	m_ui.setupUi(this);
	setWindowTitle("CDG Viewer");

	m_widget = new cdgqt5::CDGWidget(m_ui.View);
	
	m_layout = new QVBoxLayout();
	m_layout->addWidget(m_widget);	
	m_ui.View->setLayout(m_layout);
}


void Viewer::on_Load_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this
	                                               , "Please select a cdg file"
	                                               , QString()
	                                               , "CDG Files (*.cdg)");
	if (filename.isNull() != false)
	{
		
	}
}


void Viewer::on_Play_clicked()
{
}


void Viewer::on_Stop_clicked()
{
}


