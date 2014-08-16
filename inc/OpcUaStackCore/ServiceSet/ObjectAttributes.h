#ifndef __OpcUaStackCore_ObjectAttributes_h__
#define __OpcUaStackCore_ObjectAttributes_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"


// Unitittest : Vor der ersten Instanz...
// ExtensibleParameter ep;
// BOOST_REQUIRE(ep.registerFactoryElement<ObjectAttributes>((OpcUaUInt32)12345) == true);

// ep.ObjectAttributes().nodeId((OpcUaUInt32)12345);
// ObjectAttributes_::SPtr attr = ep.parameter<ObjectAttributes>();
// atrr->dislayName("ABC"),


// ep.opcUaBinaryEncode(..)


namespace OpcUaStackCore
{

	class DLLEXPORT ObjectAttributes : public  ObjectPool<ObjectAttributes>, public ExtensibleParameterBase
	{
	  public:
		ObjectAttributes(void);
		virtual ~ObjectAttributes(void);

        ExtensibleParameterBase::SPtr factory(void) { return ObjectAttributes::construct();  }

        OpcUaUInt32 specifiedAttributes(void) const;
        void displayName(const OpcUaLocalizedText::SPtr displayNameSPtr);
        OpcUaLocalizedText::SPtr displayName(void) const;
        void description(const OpcUaLocalizedText::SPtr descriptionSPtr);
        OpcUaLocalizedText::SPtr description(void) const;
        void eventNotifier(const OpcUaByte eventNotifier);
        OpcUaByte eventNotifier(void) const;
        void writeMask(const OpcUaUInt32 writeMask);
        OpcUaUInt32 writeMask(void) const;
        void userWriteMask(const OpcUaUInt32 userWriteMask);
        OpcUaUInt32 userWriteMask(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		OpcUaUInt32 specifiedAttributes_;
		OpcUaLocalizedText::SPtr displayName_;
		OpcUaLocalizedText::SPtr description_;
		OpcUaByte eventNotifier_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 userWriteMask_;
	};

}

#endif
