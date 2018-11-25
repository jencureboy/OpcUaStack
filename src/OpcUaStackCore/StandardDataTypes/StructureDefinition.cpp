/*
    DataTypeClass: StructureDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StructureDefinition.h"

namespace OpcUaStackCore
{
    
    StructureDefinition::StructureDefinition(void)
    : DataTypeDefinition()
    , defaultEncodingId_()
    , baseDataType_()
    , structureType_()
    , fields_()
    {
    }
    
    StructureDefinition::~StructureDefinition(void)
    {
    }
    
    OpcUaNodeId&
    StructureDefinition::defaultEncodingId(void)
    {
        return defaultEncodingId_;
    }
    
    OpcUaNodeId&
    StructureDefinition::baseDataType(void)
    {
        return baseDataType_;
    }
    
    StructureType&
    StructureDefinition::structureType(void)
    {
        return structureType_;
    }
    
    StructureFieldArray&
    StructureDefinition::fields(void)
    {
        return fields_;
    }
    
    bool
    StructureDefinition::operator==(const StructureDefinition& value)
    {
        StructureDefinition* dst = const_cast<StructureDefinition*>(&value);
        if (defaultEncodingId_ != dst->defaultEncodingId()) return false;
        if (baseDataType_ != dst->baseDataType()) return false;
        if (structureType_ != dst->structureType()) return false;
        if (fields_ != dst->fields()) return false;
        return true;
    }
    
    bool
    StructureDefinition::operator!=(const StructureDefinition& value)
    {
        return !this->operator==(value);
    }
    
    void
    StructureDefinition::copyTo(StructureDefinition& value)
    {
        defaultEncodingId_.copyTo(value.defaultEncodingId());
        baseDataType_.copyTo(value.baseDataType());
        structureType_.copyTo(value.structureType());
        fields_.copyTo(value.fields());
    }
    
    StructureDefinition&
    StructureDefinition::operator=(const StructureDefinition& value)
    {
        const_cast<StructureDefinition*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    StructureDefinition::factory(void)
    {
    	return constructSPtr<StructureDefinition>();
    }
    
    std::string
    StructureDefinition::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StructureDefinition::typeName(void)
    {
    	return "StructureDefinition";
    }
    
    OpcUaNodeId
    StructureDefinition::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)99,0);
    }
    
    OpcUaNodeId
    StructureDefinition::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)122, 0);
    }
    
    OpcUaNodeId
    StructureDefinition::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14798, 0);
    }
    
    OpcUaNodeId
    StructureDefinition::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15066, 0);
    }
    
    void
    StructureDefinition::opcUaBinaryEncode(std::ostream& os) const
    {
        defaultEncodingId_.opcUaBinaryEncode(os);
        baseDataType_.opcUaBinaryEncode(os);
        structureType_.opcUaBinaryEncode(os);
        fields_.opcUaBinaryEncode(os);
    }
    
    void
    StructureDefinition::opcUaBinaryDecode(std::istream& is)
    {
        defaultEncodingId_.opcUaBinaryDecode(is);
        baseDataType_.opcUaBinaryDecode(is);
        structureType_.opcUaBinaryDecode(is);
        fields_.opcUaBinaryDecode(is);
    }
    
    bool
    StructureDefinition::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    StructureDefinition::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    StructureDefinition::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StructureDefinition::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!defaultEncodingId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DefaultEncodingId", elementTree));
    
        elementTree.clear();
        if (!baseDataType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("BaseDataType", elementTree));
    
        elementTree.clear();
        if (!structureType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StructureType", elementTree));
    
        elementTree.clear();
        if (!fields_.xmlEncode(elementTree, "StructureField", xmlns)) return false;
        pt.push_back(std::make_pair("Fields", elementTree));
    
        return true;
    }
    
    bool
    StructureDefinition::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureDefinition::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("DefaultEncodingId");
        if (!tree) return false;
        if (!defaultEncodingId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("BaseDataType");
        if (!tree) return false;
        if (!baseDataType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("StructureType");
        if (!tree) return false;
        if (!structureType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Fields");
        if (!tree) return false;
        if (!fields_.xmlDecode(*tree, "StructureField", xmlns)) return false;
    
        return true;
    }
    
    bool
    StructureDefinition::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    StructureDefinition::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    StructureDefinition::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    StructureDefinition::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    StructureDefinition::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StructureDefinition* dst = dynamic_cast<StructureDefinition*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StructureDefinition::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StructureDefinition* dst = dynamic_cast<StructureDefinition*>(&extensionObjectBase);
    	return *const_cast<StructureDefinition*>(this) == *dst;
    }
    
    void
    StructureDefinition::out(std::ostream& os)
    {
        os << "DefaultEncodingId="; defaultEncodingId_.out(os);
        os << ", BaseDataType="; baseDataType_.out(os);
        os << ", StructureType="; structureType_.out(os);
        os << ", Fields="; fields_.out(os);
    }

}