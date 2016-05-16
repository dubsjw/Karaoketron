#include "src/CDGModel.h"

// cdgdecode dependencies
#include <cdgdecode/ColorTable.h>

namespace cdgqt5
{


struct CDGModelPrivate
{
	cdgdecode::ColorTable m_palette;
};


CDGModel::CDGModel(QObject* parent)
: QObject(parent)
, d_ptr(new CDGModelPrivate())
{
}


CDGModel::~CDGModel()
{
	delete d_ptr;
}


cdgdecode::ColorTable& CDGModel::Palette()
{
	return d_ptr->m_palette;
}

}
