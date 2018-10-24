/*
    EnumTypeClass: DiagnosticsLevel

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor:     Kai Huebl (kai@huebl-sgh.de)
    BuildDate: 2018-Oct-24 21:52:50.099977
*/

#ifndef __OpcUaStackCore_DiagnosticsLevel_h__
#define __OpcUaStackCore_DiagnosticsLevel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
    
    class DiagnosticsLevel
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<DiagnosticsLevel> SPtr;
    
        typedef enum {
            EnumBasic = 0,
            EnumAdvanced = 1,
            EnumInfo = 2,
            EnumLog = 3,
            EnumDebug = 4,
        } Enum;
    
        DiagnosticsLevel(void);
        virtual ~DiagnosticsLevel(void);
        
        uint32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(DiagnosticsLevel& value);
        bool operator==(const DiagnosticsLevel& value) const;
        bool operator!=(const DiagnosticsLevel& value) const;
    
      private:
        uint32_t value_;
    
    };

}

#endif
