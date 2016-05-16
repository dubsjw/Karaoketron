#pragma once

// cdgqt5 dependencies
#include <cdgqt5/Globals.h>

// qt dependencies
#include <QObject>

namespace cdgdecode { class ColorTable; }

namespace cdgqt5
{

struct CDGModelPrivate;

class CDGQT5_EXPORT CDGModel : public QObject
{
	Q_OBJECT

	public:
		CDGModel(QObject* parent=nullptr);
		~CDGModel();
		CDGModel(CDGModel const&) = delete;
		CDGModel& operator=(CDGModel const&) = delete;

		cdgdecode::ColorTable& Palette();

	private:
		//! 
		CDGModelPrivate* d_ptr;
};

}


