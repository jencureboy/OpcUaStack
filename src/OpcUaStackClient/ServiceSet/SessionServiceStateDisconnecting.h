/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionServiceStateDisconnecting_h__
#define __OpcUaStackClient_SessionServiceStateDisconnecting_h__

#include "OpcUaStackClient/ServiceSet/SessionServiceStateIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceStateDisconnecting
	: public SessionServiceStateIf
	{
	  public:
		SessionServiceStateDisconnecting(void);
		~SessionServiceStateDisconnecting(void);

		virtual SessionServiceStateId asyncConnect(void) override;
		virtual SessionServiceStateId asyncDisconnect(bool deleteSubscriptions) override;
		virtual SessionServiceStateId asyncCancel(uint32_t requestHandle) override;

		virtual SessionServiceStateId handleConnect(SecureChannel* secureChannel) override;
		virtual SessionServiceStateId handleDisconnect(SecureChannel* secureChannel) override;
		virtual SessionServiceStateId recvCreateSessionResponse(
			SecureChannel* secureChannel,
			ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvActivateSessionResponse(
			SecureChannel* secureChannel,
			ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvCloseSessionResponse(
			SecureChannel* secureChannel,
			ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvMessageResponse(
			SecureChannel* secureChannel,
			ResponseHeader::SPtr& responseHeader
		) override;

		virtual SessionServiceStateId sendMessageRequest(Message::SPtr message) override;

		virtual SessionServiceStateId reconnectTimeout(void) override;
		virtual SessionServiceStateId pendingQueueTimeout(Object::SPtr& object) override;
	};

}

#endif
