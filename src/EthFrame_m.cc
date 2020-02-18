//
// Generated file, do not edit! Created by nedtool 5.6 from EthFrame.msg.
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
#include "EthFrame_m.h"

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

Register_Class(EthFrame)

EthFrame::EthFrame(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->destinationAddress = 0;
    this->sourceAddress = 0;
    this->typeLength = 0;
    this->vlanProtocolId = 0;
    this->vlanTagCtrl = 0;
    data_arraysize = 0;
    this->data = 0;
    this->fcs = 0;
}

EthFrame::EthFrame(const EthFrame& other) : ::omnetpp::cPacket(other)
{
    data_arraysize = 0;
    this->data = 0;
    copy(other);
}

EthFrame::~EthFrame()
{
    delete [] this->data;
}

EthFrame& EthFrame::operator=(const EthFrame& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void EthFrame::copy(const EthFrame& other)
{
    this->destinationAddress = other.destinationAddress;
    this->sourceAddress = other.sourceAddress;
    this->typeLength = other.typeLength;
    this->vlanProtocolId = other.vlanProtocolId;
    this->vlanTagCtrl = other.vlanTagCtrl;
    delete [] this->data;
    this->data = (other.data_arraysize==0) ? nullptr : new uint8_t[other.data_arraysize];
    data_arraysize = other.data_arraysize;
    for (unsigned int i=0; i<data_arraysize; i++)
        this->data[i] = other.data[i];
    this->fcs = other.fcs;
}

void EthFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->typeLength);
    doParsimPacking(b,this->vlanProtocolId);
    doParsimPacking(b,this->vlanTagCtrl);
    b->pack(data_arraysize);
    doParsimArrayPacking(b,this->data,data_arraysize);
    doParsimPacking(b,this->fcs);
}

void EthFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->typeLength);
    doParsimUnpacking(b,this->vlanProtocolId);
    doParsimUnpacking(b,this->vlanTagCtrl);
    delete [] this->data;
    b->unpack(data_arraysize);
    if (data_arraysize==0) {
        this->data = 0;
    } else {
        this->data = new uint8_t[data_arraysize];
        doParsimArrayUnpacking(b,this->data,data_arraysize);
    }
    doParsimUnpacking(b,this->fcs);
}

uint64_t EthFrame::getDestinationAddress() const
{
    return this->destinationAddress;
}

void EthFrame::setDestinationAddress(uint64_t destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

uint64_t EthFrame::getSourceAddress() const
{
    return this->sourceAddress;
}

void EthFrame::setSourceAddress(uint64_t sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

uint16_t EthFrame::getTypeLength() const
{
    return this->typeLength;
}

void EthFrame::setTypeLength(uint16_t typeLength)
{
    this->typeLength = typeLength;
}

uint16_t EthFrame::getVlanProtocolId() const
{
    return this->vlanProtocolId;
}

void EthFrame::setVlanProtocolId(uint16_t vlanProtocolId)
{
    this->vlanProtocolId = vlanProtocolId;
}

uint16_t EthFrame::getVlanTagCtrl() const
{
    return this->vlanTagCtrl;
}

void EthFrame::setVlanTagCtrl(uint16_t vlanTagCtrl)
{
    this->vlanTagCtrl = vlanTagCtrl;
}

void EthFrame::setDataArraySize(unsigned int size)
{
    uint8_t *data2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = data_arraysize < size ? data_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        data2[i] = this->data[i];
    for (unsigned int i=sz; i<size; i++)
        data2[i] = 0;
    data_arraysize = size;
    delete [] this->data;
    this->data = data2;
}

unsigned int EthFrame::getDataArraySize() const
{
    return data_arraysize;
}

uint8_t EthFrame::getData(unsigned int k) const
{
    if (k>=data_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    return this->data[k];
}

void EthFrame::setData(unsigned int k, uint8_t data)
{
    if (k>=data_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    this->data[k] = data;
}

uint32_t EthFrame::getFcs() const
{
    return this->fcs;
}

void EthFrame::setFcs(uint32_t fcs)
{
    this->fcs = fcs;
}

class EthFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EthFrameDescriptor();
    virtual ~EthFrameDescriptor();

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

Register_ClassDescriptor(EthFrameDescriptor)

EthFrameDescriptor::EthFrameDescriptor() : omnetpp::cClassDescriptor("EthFrame", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

EthFrameDescriptor::~EthFrameDescriptor()
{
    delete[] propertynames;
}

bool EthFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthFrame *>(obj)!=nullptr;
}

const char **EthFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EthFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EthFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int EthFrameDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *EthFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destinationAddress",
        "sourceAddress",
        "typeLength",
        "vlanProtocolId",
        "vlanTagCtrl",
        "data",
        "fcs",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int EthFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "typeLength")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlanProtocolId")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlanTagCtrl")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "fcs")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EthFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",
        "uint64_t",
        "uint16_t",
        "uint16_t",
        "uint16_t",
        "uint8_t",
        "uint32_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **EthFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *EthFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EthFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EthFrame *pp = (EthFrame *)object; (void)pp;
    switch (field) {
        case 5: return pp->getDataArraySize();
        default: return 0;
    }
}

const char *EthFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EthFrame *pp = (EthFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EthFrame *pp = (EthFrame *)object; (void)pp;
    switch (field) {
        case 0: return uint642string(pp->getDestinationAddress());
        case 1: return uint642string(pp->getSourceAddress());
        case 2: return ulong2string(pp->getTypeLength());
        case 3: return ulong2string(pp->getVlanProtocolId());
        case 4: return ulong2string(pp->getVlanTagCtrl());
        case 5: return ulong2string(pp->getData(i));
        case 6: return ulong2string(pp->getFcs());
        default: return "";
    }
}

bool EthFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EthFrame *pp = (EthFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setDestinationAddress(string2uint64(value)); return true;
        case 1: pp->setSourceAddress(string2uint64(value)); return true;
        case 2: pp->setTypeLength(string2ulong(value)); return true;
        case 3: pp->setVlanProtocolId(string2ulong(value)); return true;
        case 4: pp->setVlanTagCtrl(string2ulong(value)); return true;
        case 5: pp->setData(i,string2ulong(value)); return true;
        case 6: pp->setFcs(string2ulong(value)); return true;
        default: return false;
    }
}

const char *EthFrameDescriptor::getFieldStructName(int field) const
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

void *EthFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EthFrame *pp = (EthFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


