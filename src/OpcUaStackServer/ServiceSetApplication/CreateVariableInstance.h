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

#ifndef __OpcUaStackServer_CreateVariableInstance_h__
#define __OpcUaStackServer_CreateVariableInstance_h__

#include <vector>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT CreateVariableInstance
	{
	  public:
		typedef boost::shared_ptr<CreateVariableInstance> SPtr;

		CreateVariableInstance(void);
		CreateVariableInstance(
			const std::string& namespaceName,
			const OpcUaStackCore::OpcUaLocalizedText& displayName,
			const OpcUaStackCore::OpcUaNodeId& parentNodeId,
			const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId,
			OpcUaStackCore::Object::SPtr& variableInstance
		);
		virtual ~CreateVariableInstance(void);

		void namespaceName(const std::string& namespaceName);
		std::string& namespaceName(void);
		void displayName(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		OpcUaStackCore::OpcUaLocalizedText& displayName(void);
		void parentNodeId(const OpcUaStackCore::OpcUaNodeId& parentNodeId);
		OpcUaStackCore::OpcUaNodeId& parentnodeId(void);
		void referenceTypeNodeId(const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId);
		OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId(void);
		void variableInstance(OpcUaStackCore::Object::SPtr& variableInstance);
		OpcUaStackCore::Object::SPtr& variableInstace(void);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);

	  private:
		std::string namespaceName_;
		OpcUaStackCore::OpcUaLocalizedText displayName_;
		OpcUaStackCore::OpcUaNodeId parentNodeId_;
		OpcUaStackCore::OpcUaNodeId referenceTypeNodeId_;
		OpcUaStackCore::Object::SPtr variableInstance_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
	};

}
#endif
