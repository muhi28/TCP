//
// Generated file, do not edit! Created by nedtool 5.2 from tcp/TCPControlInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "TCPControlInfo_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(TCPControlInfo)

TCPControlInfo::TCPControlInfo(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->srcPort = 0;
    this->destPort = 0;
    this->tcpCommand = 0;
    this->tcpStatus = 0;
}

TCPControlInfo::TCPControlInfo(const TCPControlInfo& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TCPControlInfo::~TCPControlInfo()
{
}

TCPControlInfo& TCPControlInfo::operator=(const TCPControlInfo& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TCPControlInfo::copy(const TCPControlInfo& other)
{
    this->srcIPv4 = other.srcIPv4;
    this->srcIPv6 = other.srcIPv6;
    this->srcPort = other.srcPort;
    this->destIPv4 = other.destIPv4;
    this->destIPv6 = other.destIPv6;
    this->destPort = other.destPort;
    this->tcpCommand = other.tcpCommand;
    this->tcpStatus = other.tcpStatus;
}

void TCPControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->srcIPv4);
    doParsimPacking(b,this->srcIPv6);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destIPv4);
    doParsimPacking(b,this->destIPv6);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->tcpCommand);
    doParsimPacking(b,this->tcpStatus);
}

void TCPControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->srcIPv4);
    doParsimUnpacking(b,this->srcIPv6);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destIPv4);
    doParsimUnpacking(b,this->destIPv6);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->tcpCommand);
    doParsimUnpacking(b,this->tcpStatus);
}

inet::IPv4Address& TCPControlInfo::getSrcIPv4()
{
    return this->srcIPv4;
}

void TCPControlInfo::setSrcIPv4(const inet::IPv4Address& srcIPv4)
{
    this->srcIPv4 = srcIPv4;
}

inet::IPv6Address& TCPControlInfo::getSrcIPv6()
{
    return this->srcIPv6;
}

void TCPControlInfo::setSrcIPv6(const inet::IPv6Address& srcIPv6)
{
    this->srcIPv6 = srcIPv6;
}

int TCPControlInfo::getSrcPort() const
{
    return this->srcPort;
}

void TCPControlInfo::setSrcPort(int srcPort)
{
    this->srcPort = srcPort;
}

inet::IPv4Address& TCPControlInfo::getDestIPv4()
{
    return this->destIPv4;
}

void TCPControlInfo::setDestIPv4(const inet::IPv4Address& destIPv4)
{
    this->destIPv4 = destIPv4;
}

inet::IPv6Address& TCPControlInfo::getDestIPv6()
{
    return this->destIPv6;
}

void TCPControlInfo::setDestIPv6(const inet::IPv6Address& destIPv6)
{
    this->destIPv6 = destIPv6;
}

int TCPControlInfo::getDestPort() const
{
    return this->destPort;
}

void TCPControlInfo::setDestPort(int destPort)
{
    this->destPort = destPort;
}

int TCPControlInfo::getTcpCommand() const
{
    return this->tcpCommand;
}

void TCPControlInfo::setTcpCommand(int tcpCommand)
{
    this->tcpCommand = tcpCommand;
}

int TCPControlInfo::getTcpStatus() const
{
    return this->tcpStatus;
}

void TCPControlInfo::setTcpStatus(int tcpStatus)
{
    this->tcpStatus = tcpStatus;
}

class TCPControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPControlInfoDescriptor();
    virtual ~TCPControlInfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(TCPControlInfoDescriptor)

TCPControlInfoDescriptor::TCPControlInfoDescriptor() : omnetpp::cClassDescriptor("TCPControlInfo", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

TCPControlInfoDescriptor::~TCPControlInfoDescriptor()
{
    delete[] propertynames;
}

bool TCPControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPControlInfo *>(obj)!=nullptr;
}

const char **TCPControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int TCPControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *TCPControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcIPv4",
        "srcIPv6",
        "srcPort",
        "destIPv4",
        "destIPv6",
        "destPort",
        "tcpCommand",
        "tcpStatus",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int TCPControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIPv4")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIPv6")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIPv4")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIPv6")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "tcpCommand")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "tcpStatus")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::IPv4Address",
        "inet::IPv6Address",
        "int",
        "inet::IPv4Address",
        "inet::IPv6Address",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TCPControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TCPControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPControlInfo *pp = (TCPControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPControlInfo *pp = (TCPControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPControlInfo *pp = (TCPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcIPv4(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSrcIPv6(); return out.str();}
        case 2: return long2string(pp->getSrcPort());
        case 3: {std::stringstream out; out << pp->getDestIPv4(); return out.str();}
        case 4: {std::stringstream out; out << pp->getDestIPv6(); return out.str();}
        case 5: return long2string(pp->getDestPort());
        case 6: return long2string(pp->getTcpCommand());
        case 7: return long2string(pp->getTcpStatus());
        default: return "";
    }
}

bool TCPControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPControlInfo *pp = (TCPControlInfo *)object; (void)pp;
    switch (field) {
        case 2: pp->setSrcPort(string2long(value)); return true;
        case 5: pp->setDestPort(string2long(value)); return true;
        case 6: pp->setTcpCommand(string2long(value)); return true;
        case 7: pp->setTcpStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *TCPControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(inet::IPv4Address));
        case 1: return omnetpp::opp_typename(typeid(inet::IPv6Address));
        case 3: return omnetpp::opp_typename(typeid(inet::IPv4Address));
        case 4: return omnetpp::opp_typename(typeid(inet::IPv6Address));
        default: return nullptr;
    };
}

void *TCPControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPControlInfo *pp = (TCPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcIPv4()); break;
        case 1: return (void *)(&pp->getSrcIPv6()); break;
        case 3: return (void *)(&pp->getDestIPv4()); break;
        case 4: return (void *)(&pp->getDestIPv6()); break;
        default: return nullptr;
    }
}


