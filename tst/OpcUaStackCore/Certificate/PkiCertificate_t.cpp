#include "unittest.h"
#include <boost/asio/ip/host_name.hpp>
#include "OpcUaStackCore/Certificate/PkiCertificate.h"
#include "OpcUaStackCore/Certificate/PkiRsaKey.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(PkiCertificate_t)

BOOST_AUTO_TEST_CASE(PkiCertificate_)
{
	std::cout << "PkiCertificate_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(PkiCertificate_create)
{
	boost::posix_time::ptime validTimeNotBefore(boost::posix_time::time_from_string("2016-03-15 15:00:00"));
	boost::posix_time::ptime validTimeNotAfter(boost::posix_time::time_from_string("2021-03-15 15:00:00"));

	std::string hostname = boost::asio::ip::host_name();

	PkiIdentity identity;
	identity.commonName()		= "ASNeG-Demo@" + hostname;
	identity.organization()		= "ASNeG";
	identity.organizationUnit()	= "Unit";
	identity.locality()			= "LocationName";
	identity.state()			= "State";
	identity.country()			= "DE";
	identity.domainComponent()	= hostname;

	PkiCertificateInfo info;
	info.URI()					= "urn:" + hostname + ":ASNeG::ASNeG-Demo";
	info.dnsNames().push_back(hostname);
	info.validTimeNotBefore(validTimeNotBefore);
	info.validTimeNotAfter(validTimeNotBefore);

	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);

	PkiPrivateKey issuerPrivateKey;
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPrivateKey) == true);

	PkiPublicKey subjectPublicKey;
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPublicKey) == true);

	PkiCertificate certificate;
	BOOST_REQUIRE(certificate.createNewCertificate(info, identity, subjectPublicKey, identity, issuerPrivateKey) == true);
}

BOOST_AUTO_TEST_CASE(PkiCertificate_write_key)
{
	boost::posix_time::ptime validTimeNotBefore(boost::posix_time::time_from_string("2016-03-15 15:00:00"));
	boost::posix_time::ptime validTimeNotAfter(boost::posix_time::time_from_string("2021-03-15 15:00:00"));

	std::string hostname = boost::asio::ip::host_name();

	PkiIdentity identity;
	identity.commonName()		= "ASNeG-Demo@" + hostname;
	identity.organization()		= "ASNeG";
	identity.organizationUnit()	= "Unit";
	identity.locality()			= "LocationName";
	identity.state()			= "State";
	identity.country()			= "DE";
	identity.domainComponent()	= hostname;

	PkiCertificateInfo info;
	info.URI()					= "urn:" + hostname + ":ASNeG::ASNeG-Demo";
	info.dnsNames().push_back(hostname);
	info.validTimeNotBefore(validTimeNotBefore);
	info.validTimeNotAfter(validTimeNotAfter);

	PkiRsaKey rsaKey;
	BOOST_REQUIRE(rsaKey.createKey(1024) == true);

	PkiPrivateKey issuerPrivateKey;
	BOOST_REQUIRE(rsaKey.getPrivateKey(issuerPrivateKey) == true);

	PkiPublicKey subjectPublicKey;
	BOOST_REQUIRE(rsaKey.getPublicKey(subjectPublicKey) == true);

	PkiCertificate certificate;
	BOOST_REQUIRE(
		certificate.createNewCertificate(
			info, identity, subjectPublicKey, identity, issuerPrivateKey
		) == true);

	//
	// store certificate
	//
	BOOST_REQUIRE(certificate.toDERFile("../tst/data/ASNeG-Test.der") == true);

	//
	// store private key
	//
	BOOST_REQUIRE(rsaKey.writePEMFile("../tst/data/ASNeG-Test.PEM", "") == true);
}

BOOST_AUTO_TEST_CASE(PkiCertificate_write_read_key)
{
	PkiRsaKey rsaKey;

	std::string hostname = boost::asio::ip::host_name();

	{ // read certificate from file
		PkiCertificate certificate;
		std::stringstream ss;

		PkiCertificateInfo pkiCertificateInfo;
		PkiIdentity subjectPkiIdentity;
		PkiPublicKey subjectPkiPublicKey;
		PkiIdentity issuerPkiIdentity;
		PkiPrivateKey issuerPrivateKey;

		BOOST_REQUIRE(certificate.fromDERFile("../tst/data/ASNeG-Demo-Server.der") == true);
		BOOST_REQUIRE(
			certificate.getCertificate(
				pkiCertificateInfo,
				subjectPkiIdentity,
				subjectPkiPublicKey,
				issuerPkiIdentity,
				issuerPrivateKey
			) == true
		);


		BOOST_REQUIRE(subjectPkiIdentity.commonName()	== "AggregationServer");
		BOOST_REQUIRE(subjectPkiIdentity.organization() == "Baker Hughes");
		BOOST_REQUIRE(subjectPkiIdentity.organizationUnit() == "Drilling Systems Automation");
		BOOST_REQUIRE(subjectPkiIdentity.locality() == "Celle");
		BOOST_REQUIRE(subjectPkiIdentity.state() == "Lower Saxony");
		BOOST_REQUIRE(subjectPkiIdentity.country() == "DE");
		BOOST_REQUIRE(subjectPkiIdentity.domainComponent() == "siemens-ipc");


		BOOST_REQUIRE(issuerPkiIdentity.commonName()	== "AggregationServer");
		BOOST_REQUIRE(issuerPkiIdentity.organization() == "Baker Hughes");
		BOOST_REQUIRE(issuerPkiIdentity.organizationUnit() == "Drilling Systems Automation");
		BOOST_REQUIRE(issuerPkiIdentity.locality() == "Celle");
		BOOST_REQUIRE(issuerPkiIdentity.state() == "Lower Saxony");
		BOOST_REQUIRE(issuerPkiIdentity.country() == "DE");
		BOOST_REQUIRE(issuerPkiIdentity.domainComponent() == "siemens-ipc");


		BOOST_REQUIRE(pkiCertificateInfo.version() == 2); // V3
		BOOST_REQUIRE(pkiCertificateInfo.serialNumber() == 1);
		ss.str("");
		ss << pkiCertificateInfo.validTimeNotBefore();
		BOOST_REQUIRE(ss.str() == std::string("2016-Feb-25 14:33:47"));
		ss.str("");
		ss << pkiCertificateInfo.validTimeNotAfter();
		BOOST_REQUIRE(ss.str() == std::string("2019-Feb-24 15:33:47"));

		// FIXME: todo
		// Zertifikat Fingerabdrücke

		BOOST_REQUIRE(subjectPkiPublicKey.keyType() == PkiPublicKey::KT_RSA);
		//  FIXME: todo - Schluesselparameter
		PkiRsaKey pkiRsaKey;
		pkiRsaKey.setPublicKey(subjectPkiPublicKey);
		BOOST_REQUIRE(pkiRsaKey.keyLength() == 2048);
		// FIXME: todo - SHA1 Fingerabdruck des Schluessel
		// FIXME: todo - Öffentlicher Schlüssel

		std::string str;
		pkiRsaKey.toHexStringPublicKey(str);
		std::cout << ".....KEY=" << str << std::endl;


	}
}


#if 0
BOOST_AUTO_TEST_CASE(PkiCertificate_write_read_key)
{
	PkiRsaKey rsaKey1, rsaKey2;
	boost::posix_time::ptime validTimeNotBefore(boost::posix_time::time_from_string("2016-03-15 15:00:00"));
	boost::posix_time::ptime validTimeNotAfter(boost::posix_time::time_from_string("2021-03-15 15:00:00"));

	std::string hostname = boost::asio::ip::host_name();

	{ // write certificate to file

		PkiIdentity identity;
		identity.commonName()		= "ASNeG-Demo@" + hostname;
		identity.organization()		= "ASNeG";
		identity.organizationUnit()	= "Unit";
		identity.locality()			= "LocationName";
		identity.state()			= "State";
		identity.country()			= "DE";
		identity.domainComponent()	= hostname;

		PkiCertificateInfo info;
		info.URI()					= "urn:" + hostname + ":ASNeG::ASNeG-Demo";
		info.dnsNames().push_back(hostname);
		info.validTimeNotBefore(validTimeNotBefore);
		info.validTimeNotAfter(validTimeNotAfter);

		BOOST_REQUIRE(rsaKey1.createKey(1024) == true);

		PkiPrivateKey issuerPrivateKey;
		BOOST_REQUIRE(rsaKey1.getPrivateKey(issuerPrivateKey) == true);

		PkiPublicKey subjectPublicKey;
		BOOST_REQUIRE(rsaKey1.getPublicKey(subjectPublicKey) == true);

		PkiCertificate certificate;
		BOOST_REQUIRE(
			certificate.createNewCertificate(
				info, identity, subjectPublicKey, identity, issuerPrivateKey
			) == true
		);

		//
		// store certificate
		//
		BOOST_REQUIRE(certificate.toDERFile("../tst/data/ASNeG-Test.der") == true);

		//
		// store private key
		//
		BOOST_REQUIRE(rsaKey1.writePEMFile("../tst/data/ASNeG-Test.PEM", "") == true);
	}

	{ // read certificate from file
		PkiCertificate certificate;

		PkiCertificateInfo pkiCertificateInfo;
		PkiIdentity subjectPkiIdentity;
		PkiPublicKey subjectPkiPublicKey;
		PkiIdentity issuerPkiIdentity;
		PkiPrivateKey issuerPrivateKey;

		certificate.fromDERFile("../tst/data/ASNeG-Test.der");

		BOOST_REQUIRE(certificate.fromDERFile("../tst/data/ASNeG-Test.der") == true);
		BOOST_REQUIRE(
			certificate.getCertificate(
				pkiCertificateInfo,
				subjectPkiIdentity,
				subjectPkiPublicKey,
				issuerPkiIdentity,
				issuerPrivateKey
			) == true
		);

		BOOST_REQUIRE(subjectPkiIdentity.commonName()	== "ASNeG-Demo@" + hostname);
		BOOST_REQUIRE(subjectPkiIdentity.organization() == "ASNeG");
		BOOST_REQUIRE(subjectPkiIdentity.organizationUnit() == "Unit");
		BOOST_REQUIRE(subjectPkiIdentity.locality() == "LocationName");
		BOOST_REQUIRE(subjectPkiIdentity.state() == "State");
		BOOST_REQUIRE(subjectPkiIdentity.country() == "DE");
		BOOST_REQUIRE(subjectPkiIdentity.domainComponent() == hostname);

		BOOST_REQUIRE(issuerPkiIdentity.commonName()	== "ASNeG-Demo@" + hostname);
		BOOST_REQUIRE(issuerPkiIdentity.organization() == "ASNeG");
		BOOST_REQUIRE(issuerPkiIdentity.organizationUnit() == "Unit");
		BOOST_REQUIRE(issuerPkiIdentity.locality() == "LocationName");
		BOOST_REQUIRE(issuerPkiIdentity.state() == "State");
		BOOST_REQUIRE(issuerPkiIdentity.country() == "DE");
		BOOST_REQUIRE(issuerPkiIdentity.domainComponent() == hostname);

		// inaccuracy available
		//BOOST_REQUIRE(pkiCertificateInfo.validTimeNotBefore() == validTimeNotBefore);
		//BOOST_REQUIRE(pkiCertificateInfo.validTimeNotAfter() == validTimeNotAfter);

	}
}
#endif

BOOST_AUTO_TEST_SUITE_END()


