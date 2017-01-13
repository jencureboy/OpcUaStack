/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComplexDataTypeParser
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ComplexDataTypeParser::ComplexDataTypeParser(void)
	: fileName_("")
	, complexDataTypeMap_()
	, typeName_("")
	{
	}

	ComplexDataTypeParser::~ComplexDataTypeParser(void)
	{
	}

	ComplexDataType::Map&
	ComplexDataTypeParser::complexDataTypeMap(void)
	{
		return complexDataTypeMap_;
	}

	bool
	ComplexDataTypeParser::parse(const std::string& fileName)
	{
		fileName_ = fileName;

		bool success;

		//
		// read configuration file
		//
        Log(Info, "read complex data type configuration file")
            .parameter("FileName", fileName);
		Config config;
		ConfigXml configXml;
		success = configXml.parse(fileName_, &config);
		if (!success) {
			Log(Error, "read complex data type configuration file error")
			   .parameter("FileName", fileName)
			   .parameter("ErrorMessage", configXml.errorMessage());
			   return false;
		}

		// read complex data types
		std::vector<Config> configVec;
		config.getChilds("OpcUaComplexDataTypes.ComplexDataType", configVec);
		if (configVec.size() == 0) {
			Log(Error, "parameter missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("FileName", fileName);
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = configVec.begin(); it != configVec.end(); it++) {
			Config& child = *it;
			ComplexDataType::SPtr complexDataType = constructSPtr<ComplexDataType>();

			success = parseComplexDataType(child, complexDataType);
			if (!success) return false;

			complexDataTypeMap_.insert(std::make_pair(complexDataType->name(), complexDataType));
		}

		return true;
	}

	bool
	ComplexDataTypeParser::parseComplexDataType(Config& config, ComplexDataType::SPtr& complexDataType)
	{
		// type name
		if (!config.getConfigParameter("<xmlattr>.TypeName", typeName_)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("Attribute", "TypeName")
				.parameter("FileName", fileName_);
			return false;
		}
		complexDataType->name(typeName_);

		// type binary node id
		std::string binaryNodeIdStr;
		if (!config.getConfigParameter("<xmlattr>.TypeBinaryNodeId", binaryNodeIdStr)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("Attribute", "TypeBinaryNodeId")
				.parameter("FileName", fileName_);
			return false;
		}
		OpcUaNodeId binaryNodeId;
		if (!binaryNodeId.fromString(binaryNodeIdStr)) {
			Log(Error, "attribute value error in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
				.parameter("Attribute", "TypeBinaryNodeId")
				.parameter("Value", binaryNodeIdStr)
				.parameter("FileName", fileName_);
			return false;
		}
		complexDataType->binaryTypeId(binaryNodeId);

		// type xml node id
		OpcUaNodeId xmlNodeId;
		std::string xmlNodeIdStr;
		if (config.getConfigParameter("<xmlattr>.TypeXmlNodeId", xmlNodeIdStr)) {
			if (!binaryNodeId.fromString(xmlNodeIdStr)) {
				Log(Error, "attribute value error in complex data type config file")
					.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType")
					.parameter("Attribute", "TypeXmlNodeId")
					.parameter("Value", xmlNodeIdStr)
					.parameter("FileName", fileName_);
				return false;
			}
		}
		complexDataType->xmlTypeId(xmlNodeId);

		// read complex data type items
		std::vector<Config> configVec;
		config.getChilds("Variable", configVec);
		if (configVec.size() == 0) {
			Log(Error, "parameter missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType.Variable")
				.parameter("FileName", fileName_);
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = configVec.begin(); it != configVec.end(); it++) {
			Config& child = *it;
			ComplexDataTypeItem::SPtr complexDataTypeItem = constructSPtr<ComplexDataTypeItem>();

			bool success = parseComplexDataTypeVariable(child, complexDataTypeItem);
			if (!success) return false;

			complexDataType->addComplexDataTypeItem(*complexDataTypeItem);
		}

		return true;
	}

	bool
	ComplexDataTypeParser::parseComplexDataTypeVariable(Config& config, ComplexDataTypeItem::SPtr& complexDataTypeItem)
	{
		// name
		std::string name;
		if (!config.getConfigParameter("<xmlattr>.Name", name)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType.Variable")
				.parameter("Attribute", "Name")
				.parameter("TypeName", typeName_)
				.parameter("FileName", fileName_);
			return false;
		}
		complexDataTypeItem->itemName(name);

		// type
		std::string type;
		if (!config.getConfigParameter("<xmlattr>.Type", type)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType.Variable")
				.parameter("Attribute", "Type")
				.parameter("TypeName", typeName_)
				.parameter("FileName", fileName_);
			return false;
		}
		OpcUaBuildInType buildInType = OpcUaBuildInTypeMap::string2BuildInType(type);
		if (buildInType == OpcUaBuildInType_Unknown) {
			Log(Error, "attribute value error in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType.Variable")
				.parameter("Attribute", "Type")
				.parameter("Value", type)
				.parameter("TypeName", typeName_)
				.parameter("FileName", fileName_);
			return false;
		}
		complexDataTypeItem->itemType(buildInType);

		// modelling rule
		std::string modellingRule;
		if (!config.getConfigParameter("<xmlattr>.ModellingRule", modellingRule)) {
			Log(Error, "attribute missing in complex data type config file")
				.parameter("Parameter", "OpcUaComplexDataTypes.ComplexDataType.Variable")
				.parameter("Attribute", "ModellingRule")
				.parameter("TypeName", typeName_)
				.parameter("FileName", fileName_);
			return false;
		}
		if (modellingRule == "M") {
			complexDataTypeItem->mandatory(true);
		}
		else {
			complexDataTypeItem->mandatory(false);
		}

		return true;
	}

}


