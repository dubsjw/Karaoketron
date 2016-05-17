#pragma once

#include <cdgqt5/CDGModel.h>
#include <cdgqt5/CDGWidget.h>
#include <QDialog>
#include <QVBoxLayout>
#include "ui_Viewer.h"

class Viewer : public QDialog
{
	Q_OBJECT
	public:
		Viewer();

	public Q_SLOTS:
		void on_Load_clicked();
		void on_Play_clicked();
		void on_Stop_clicked();

	private:
		Ui::Viewer m_ui;
		cdgqt5::CDGModel* m_model;
		cdgqt5::CDGWidget* m_widget;
		QVBoxLayout* m_layout;
};
