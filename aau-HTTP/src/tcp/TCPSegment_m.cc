//
// Generated file, do not edit! Created by nedtool 5.2 from tcp/TCPSegment.msg.
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
#include "TCPSegment_m.h"

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

Register_Class(TCPSegment)

TCPSegment::TCPSegment(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->srcPort = -1;
    this->destPort = -1;
    this->seqNr = 0;
    this->ackNr = 0;
    this->ack = false;
    this->syn = false;
    this->fin = false;
    this->rst = false;
    this->headerLength = 0;
    this->receiveWindow = 0;
    this->psh = false;
    this->urg = false;
}

TCPSegment::TCPSegment(const TCPSegment& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

TCPSegment::~TCPSegment()
{
}

TCPSegment& TCPSegment::operator=(const TCPSegment& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void TCPSegment::copy(const TCPSegment& other)
{
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->seqNr = other.seqNr;
    this->ackNr = other.ackNr;
    this->ack = other.ack;
    this->syn = other.syn;
    this->fin = other.fin;
    this->rst = other.rst;
    this->headerLength = other.headerLength;
    this->receiveWindow = other.receiveWindow;
    this->psh = other.psh;
    this->urg = other.urg;
}

void TCPSegment::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->seqNr);
    doParsimPacking(b,this->ackNr);
    doParsimPacking(b,this->ack);
    doParsimPacking(b,this->syn);
    doParsimPacking(b,this->fin);
    doParsimPacking(b,this->rst);
    doParsimPacking(b,this->headerLength);
    doParsimPacking(b,this->receiveWindow);
    doParsimPacking(b,this->psh);
    doParsimPacking(b,this->urg);
}

void TCPSegment::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->seqNr);
    doParsimUnpacking(b,this->ackNr);
    doParsimUnpacking(b,this->ack);
    doParsimUnpacking(b,this->syn);
    doParsimUnpacking(b,this->fin);
    doParsimUnpacking(b,this->rst);
    doParsimUnpacking(b,this->headerLength);
    doParsimUnpacking(b,this->receiveWindow);
    doParsimUnpacking(b,this->psh);
    doParsimUnpacking(b,this->urg);
}

int TCPSegment::getSrcPort() const
{
    return this->srcPort;
}

void TCPSegment::setSrcPort(int srcPort)
{
    this->srcPort = srcPort;
}

int TCPSegment::getDestPort() const
{
    return this->destPort;
}

void TCPSegment::setDestPort(int destPort)
{
    this->destPort = destPort;
}

int TCPSegment::getSeqNr() const
{
    return this->seqNr;
}

void TCPSegment::setSeqNr(int seqNr)
{
    this->seqNr = seqNr;
}

int TCPSegment::getAckNr() const
{
    return this->ackNr;
}

void TCPSegment::setAckNr(int ackNr)
{
    this->ackNr = ackNr;
}

bool TCPSegment::getAck() const
{
    return this->ack;
}

void TCPSegment::setAck(bool ack)
{
    this->ack = ack;
}

bool TCPSegment::getSyn() const
{
    return this->syn;
}

void TCPSegment::setSyn(bool syn)
{
    this->syn = syn;
}

bool TCPSegment::getFin() const
{
    return this->fin;
}

void TCPSegment::setFin(bool fin)
{
    this->fin = fin;
}

bool TCPSegment::getRst() const
{
    return this->rst;
}

void TCPSegment::setRst(bool rst)
{
    this->rst = rst;
}

int TCPSegment::getHeaderLength() const
{
    return this->headerLength;
}

void TCPSegment::setHeaderLength(int headerLength)
{
    this->headerLength = headerLength;
}

int TCPSegment::getReceiveWindow() const
{
    return this->receiveWindow;
}

void TCPSegment::setReceiveWindow(int receiveWindow)
{
    this->receiveWindow = receiveWindow;
}

bool TCPSegment::getPsh() const
{
    return this->psh;
}

void TCPSegment::setPsh(bool psh)
{
    this->psh = psh;
}

bool TCPSegment::getUrg() const
{
    return this->urg;
}

void TCPSegment::setUrg(bool urg)
{
    this->urg = urg;
}

class TCPSegmentDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPSegmentDescriptor();
    virtual ~TCPSegmentDescriptor();

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

Register_ClassDescriptor(TCPSegmentDescriptor)

TCPSegmentDescriptor::TCPSegmentDescriptor() : omnetpp::cClassDescriptor("TCPSegment", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

TCPSegmentDescriptor::~TCPSegmentDescriptor()
{
    delete[] propertynames;
}

bool TCPSegmentDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPSegment *>(obj)!=nullptr;
}

const char **TCPSegmentDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPSegmentDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPSegmentDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int TCPSegmentDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *TCPSegmentDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "seqNr",
        "ackNr",
        "ack",
        "syn",
        "fin",
        "rst",
        "headerLength",
        "receiveWindow",
        "psh",
        "urg",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int TCPSegmentDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNr")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackNr")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "ack")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "syn")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "fin")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "rst")==0) return base+7;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+8;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiveWindow")==0) return base+9;
    if (fieldName[0]=='p' && strcmp(fieldName, "psh")==0) return base+10;
    if (fieldName[0]=='u' && strcmp(fieldName, "urg")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPSegmentDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "bool",
        "bool",
        "bool",
        "bool",
        "int",
        "int",
        "bool",
        "bool",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPSegmentDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPSegmentDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPSegmentDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPSegment *pp = (TCPSegment *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPSegmentDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPSegment *pp = (TCPSegment *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPSegmentDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPSegment *pp = (TCPSegment *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcPort());
        case 1: return long2string(pp->getDestPort());
        case 2: return long2string(pp->getSeqNr());
        case 3: return long2string(pp->getAckNr());
        case 4: return bool2string(pp->getAck());
        case 5: return bool2string(pp->getSyn());
        case 6: return bool2string(pp->getFin());
        case 7: return bool2string(pp->getRst());
        case 8: return long2string(pp->getHeaderLength());
        case 9: return long2string(pp->getReceiveWindow());
        case 10: return bool2string(pp->getPsh());
        case 11: return bool2string(pp->getUrg());
        default: return "";
    }
}

bool TCPSegmentDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPSegment *pp = (TCPSegment *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcPort(string2long(value)); return true;
        case 1: pp->setDestPort(string2long(value)); return true;
        case 2: pp->setSeqNr(string2long(value)); return true;
        case 3: pp->setAckNr(string2long(value)); return true;
        case 4: pp->setAck(string2bool(value)); return true;
        case 5: pp->setSyn(string2bool(value)); return true;
        case 6: pp->setFin(string2bool(value)); return true;
        case 7: pp->setRst(string2bool(value)); return true;
        case 8: pp->setHeaderLength(string2long(value)); return true;
        case 9: pp->setReceiveWindow(string2long(value)); return true;
        case 10: pp->setPsh(string2bool(value)); return true;
        case 11: pp->setUrg(string2bool(value)); return true;
        default: return false;
    }
}

const char *TCPSegmentDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *TCPSegmentDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPSegment *pp = (TCPSegment *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


