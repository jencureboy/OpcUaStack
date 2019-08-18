/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackServer_MethodService_h__
#define __OpcUaStackServer_MethodService_h__

#include "OpcUaStackCore/ServiceSet/MethodServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MethodService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<MethodService> SPtr;

		MethodService(void);
		~MethodService(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveCallRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		OpcUaStackCore::OpcUaStatusCode forwardAuthorizationMethod(
			OpcUaStackCore::UserContext::SPtr& userContext,
			OpcUaStackCore::OpcUaNodeId& objectNodeId,
			OpcUaStackCore::OpcUaNodeId& funcNodeId
		);
	};

}

#endif
