#pragma once

// cdgqt5 dependencies
#include <cdgqt5/Globals.h>

// qt dependencies
#include <QObject>

namespace cdgqt5
{

struct CDGControlsPrivate;

/**
 * Controls that can move along playback in the CDGWidget.
 */
class CDGQT5_EXPORT CDGControls : public QObject
{
	Q_OBJECT

	public:
		CDGControls();	
		~CDGControls();	
		CDGControls(CDGControls const&) = delete;
		CDGControls& operator=(CDGControls const&) = delete;

	private:
		CDGControlsPrivate* d_ptr;
};

}

