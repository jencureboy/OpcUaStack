/*
    DataTypeClass: XVType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/XVType.h"

namespace OpcUaStackCore
{
    
    XVType::XVType(void)
    : Object()
    , ExtensionObjectBase()
    , x_()
    , value_()
    {
    }
    
    XVType::~XVType(void)
    {
    }
    
    OpcUaDouble&
    XVType::x(void)
    {
        return x_;
    }
    
    OpcUaFloat&
    XVType::value(void)
    {
        return value_;
    }
    
    bool
    XVType::operator==(const XVType& value)
    {
        XVType* dst = const_cast<XVType*>(&value);
        if (x_ != dst->x()) return false;
        if (value_ != dst->value()) return false;
        return true;
    }
    
    bool
    XVType::operator!=(const XVType& value)
    {
        return !this->operator==(value);
    }
    
    void
    XVType::copyTo(XVType& value)
    {
        value.x_ = x_;
        value.value_ = value_;
    }
    
    XVType&
    XVType::operator=(const XVType& value)
    {
        const_cast<XVType*>(&value)->copyTo(*this);
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
    XVType::factory(void)
    {
    	return constructSPtr<XVType>();
    }
    
    std::string
    XVType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    XVType::typeName(void)
    {
    	return "XVType";
    }
    
    OpcUaNodeId
    XVType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12080,0);
    }
    
    OpcUaNodeId
    XVType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12090, 0);
    }
    
    OpcUaNodeId
    XVType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12082, 0);
    }
    
    OpcUaNodeId
    XVType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15380, 0);
    }
    
    void
    XVType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,x_);
        OpcUaNumber::opcUaBinaryEncode(os,value_);
    }
    
    void
    XVType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,x_);
        OpcUaNumber::opcUaBinaryDecode(is,value_);
    }
    
    bool
    XVType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    XVType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    XVType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    XVType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, x_)) return false;
        pt.push_back(std::make_pair("X", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, value_)) return false;
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    XVType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    XVType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("X");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, x_)) return false;
    
        tree = pt.get_child_optional("Value");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, value_)) return false;
    
        return true;
    }
    
    bool
    XVType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    XVType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    XVType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    XVType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    XVType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	XVType* dst = dynamic_cast<XVType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    XVType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	XVType* dst = dynamic_cast<XVType*>(&extensionObjectBase);
    	return *const_cast<XVType*>(this) == *dst;
    }
    
    void
    XVType::out(std::ostream& os)
    {
        os << "X=" << x_;
        os << ", Value=" << value_;
    }

}