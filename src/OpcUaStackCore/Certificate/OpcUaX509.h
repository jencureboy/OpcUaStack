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

#ifndef __OpcUaStackCore_OpcUaX509_h__
#define __OpcUaStackCore_OpcUaX509_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Certificate/PkiError.h"
#include <openssl/x509.h>

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaX509NameEntry
	{
	  public:
		OpcUaX509NameEntry(void);
		OpcUaX509NameEntry(const std::string& name, const std::string& value);
		~OpcUaX509NameEntry(void);

		std::string name_;
		std::string value_;
	};


	class DLLEXPORT OpcUaX509Extension
	{
	  public:
		OpcUaX509Extension(void);
		OpcUaX509Extension(const std::string& name, const std::string& value);
		~OpcUaX509Extension(void);

		std::string name_;
		std::string value_;
	};


	class DLLEXPORT OpcUaX509
	: public PkiError
	{
	  public:
		OpcUaX509(void);
		~OpcUaX509(void);

		OpcUaStatusCode addEntryByName(X509_NAME** x509Name, const std::string& name, const std::string& value);
		OpcUaStatusCode addEntryByName(X509_NAME** x509Name, const OpcUaX509NameEntry& x509NameEntry);

		OpcUaStatusCode addV3Extension(X509** cert, const std::string& name, const std::string& value, X509V3_CTX* ctx);
		OpcUaStatusCode addV3Extension(X509** cert, const OpcUaX509Extension& extension, X509V3_CTX* ctx);
	};

}

#endif