/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/QueryDataSet.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryDataSet
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryDataSet::QueryDataSet(void)
	: Object()
	, nodeIdSPtr_(boost::make_shared<OpcUaExpandedNodeId>())
	, typeDefinitionNodeSPtr_(boost::make_shared<OpcUaExpandedNodeId>())
	, valueArraySPtr_(boost::make_shared<OpcUaVariantArray>())
	{
	}

	QueryDataSet::~QueryDataSet(void)
	{
	}

	void 
	QueryDataSet::nodeId(const OpcUaExpandedNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaExpandedNodeId::SPtr 
	QueryDataSet::nodeId(void) const
	{
		return nodeIdSPtr_;
	}
	
	void 
	QueryDataSet::typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode)
	{
		typeDefinitionNodeSPtr_ = typeDefinitionNode;
	}
	
	OpcUaExpandedNodeId::SPtr 
	QueryDataSet::typeDefinitionNode(void) const
	{
		return typeDefinitionNodeSPtr_;
	}
	
	void 
	QueryDataSet::values(const OpcUaVariantArray::SPtr values)
	{
		valueArraySPtr_ = values;
	}
	
	OpcUaVariantArray::SPtr 
	QueryDataSet::values(void) const
	{
		return valueArraySPtr_;
	}

	void 
	QueryDataSet::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		typeDefinitionNodeSPtr_->opcUaBinaryEncode(os);
		valueArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	QueryDataSet::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		typeDefinitionNodeSPtr_->opcUaBinaryDecode(is);
		valueArraySPtr_->opcUaBinaryDecode(is);
	}

}
