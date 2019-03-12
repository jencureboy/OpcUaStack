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


#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateError.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateError::SessionServiceStateError(void)
	: SessionServiceStateIf("Error", SessionServiceStateId::Error)
	{
	}

	SessionServiceStateError::~SessionServiceStateError(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateError::asyncConnect(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::asyncDisconnect(bool deleteSubscriptions)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::handleConnect(SecureChannel* secureChannel)
	{

	}

	SessionServiceStateId
	SessionServiceStateError::handleDisconnect(SecureChannel* secureChannel)
	{
		assert(ctx_ != nullptr);
		assert(ctx_->sessionServiceIf_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto sessionServiceIf = ctx_->sessionServiceIf_;
		auto sessionService = ctx_->sessionService_;

		// start reconnect timer
		ctx_->startReconnectTimer();

		sessionServiceIf->sessionStateUpdate(*sessionService, SessionState::Disconnected);
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateError::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::sendMessageRequest(Message::SPtr message)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::reconnectTimeout(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateError::pendingQueueTimeout(const Object::SPtr& object)
	{
		// FIXME: todo
		return SessionServiceStateId::Error;
	}

}
