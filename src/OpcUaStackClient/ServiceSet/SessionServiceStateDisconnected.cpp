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
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateDisconnected.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateDisconnected::SessionServiceStateDisconnected(void)
	: SessionServiceStateIf("Disconnected", SessionServiceStateId::Disconnected)
	{
	}

	SessionServiceStateDisconnected::~SessionServiceStateDisconnected(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncConnect(void)
	{
		// check configuration parameter
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannelClientConfig_.get() != nullptr);
		assert(ctx_->sessionServiceIf_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto clientConfig = ctx_->secureChannelClientConfig_;
		auto sessionServiceIf = ctx_->sessionServiceIf_;
		auto& secureChannelClient = ctx_->secureChannelClient_;
		auto secureChannel = ctx_->secureChannel_;
		auto sessionService = ctx_->sessionService_;

		// check server uri. In case of an error inform the application
		Url endpointUrl(clientConfig->endpointUrl());
		if (!endpointUrl.good()) {
			Log(Debug, "endpoint url error")
				.parameter("SessId", ctx_->id_)
				.parameter("EndpointUrl", clientConfig->endpointUrl());
			sessionServiceIf->sessionStateUpdate(*sessionService, SS_ServerUriError);

			ctx_->startReconnectTimer();
			return SessionServiceStateId::Disconnected;
		}

		// open secure channel
		secureChannelClient.secureChannelClientIf(sessionService);
		secureChannel = secureChannelClient.connect(clientConfig);
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncDisconnect(bool deleteSubscriptions)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::handleConnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::handleDisconnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvMessageResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::sendMessageRequest(Message::SPtr message)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::reconnectTimeout(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::pendingQueueTimeout(Object::SPtr& object)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

}
