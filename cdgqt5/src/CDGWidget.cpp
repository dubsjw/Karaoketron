
// cdgqt5 dependencies
#include "src/CDGWidget.h"
#include "src/CDGModel.h"

// qt dependencies
#include <QImage>
#include <QPainter>
#include <QPaintEvent>

// std dependencies
#include <cstdint>

namespace cdgqt5
{

struct CDGWidgetPrivate
{
	//! The index.
	int m_index;

	//! Write to two images, third image is current.
	QImage m_image[3];

	//! The pointer to the model.
	CDGModel* m_model;

	CDGWidgetPrivate(CDGModel* model)
	: m_index(0)
	, m_image()
	, m_model(model)
	{
	}
};


CDGWidget::CDGWidget(QWidget* parent)
: QWidget( parent )
, d_ptr(new CDGWidgetPrivate(nullptr))
{
}


CDGWidget::CDGWidget(CDGModel* model, QWidget* parent)
: QWidget( parent )
, d_ptr(new CDGWidgetPrivate(model))
{
}



CDGWidget::~CDGWidget()
{
	delete d_ptr;
}


CDGModel* CDGWidget::Model()
{
	return d_ptr->m_model;
}


CDGModel const* CDGWidget::Model() const
{
	return d_ptr->m_model;
}


void CDGWidget::SetModel(CDGModel* m)
{
	d_ptr->m_model = m;
}


void CDGWidget::paintEvent(QPaintEvent* )
{
	QPainter painter(this);

}


}


