#pragma once

// cdgqt5 dependencies
#include <cdgqt5/Globals.h>

// qt dependencies
#include <QWidget>

// std dependencies
#include <cstdint>
#include <memory>

namespace cdgdecode { class ColorTable; }
namespace cdgdecode { class Tile; }

namespace cdgqt5
{

struct CDGWidgetPrivate;
class CDGControls;
class CDGModel;

/**
 * The following widget is used.
 */
class CDGQT5_EXPORT CDGWidget : public QWidget
{
	Q_OBJECT

	public:
		CDGWidget(CDGModel* model, QWidget* parent = nullptr);
		CDGWidget(QWidget* parent = nullptr);
		~CDGWidget();
		CDGWidget(CDGWidget const&) = delete;
		CDGWidget(CDGWidget&&) = delete;
		CDGWidget& operator=(CDGWidget const&) = delete;

		CDGModel* Model();
		CDGModel const* Model() const;
		void SetModel(CDGModel* m);

	protected:
		void paintEvent(QPaintEvent* evt);


	private:
		CDGWidgetPrivate* d_ptr;
};

}
