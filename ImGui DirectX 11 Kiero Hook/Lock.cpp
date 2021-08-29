#include "Lock.h"
#include "framework/il2cpp-appdata.h"

void Lock::LockAll()
{
	app::Controll__StaticFields* controll = (*app::Controll__TypeInfo)->static_fields;
	if (active)
	{		
		controll->lockLook = true;
		controll->lockMove = true;
	}
	else
	{		
		controll->lockLook = false;
		controll->lockMove = false;
	}
}