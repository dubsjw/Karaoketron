#include "src/CDGControls.h"

namespace cdgqt5
{

struct CDGControlsPrivate
{
		
};


CDGControls::CDGControls()
: d_ptr(new CDGControlsPrivate())
{
}


CDGControls::~CDGControls()
{
	delete d_ptr;
}

}

