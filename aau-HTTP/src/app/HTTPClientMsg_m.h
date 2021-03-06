//
// Generated file, do not edit! Created by nedtool 5.2 from app/HTTPClientMsg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __HTTPCLIENTMSG_M_H
#define __HTTPCLIENTMSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>app/HTTPClientMsg.msg:20</tt> by nedtool.
 * <pre>
 * packet HTTPClientMsg
 * {
 *     string request;
 *     string method;
 * }
 * </pre>
 */
class HTTPClientMsg : public ::omnetpp::cPacket
{
  protected:
    ::omnetpp::opp_string request;
    ::omnetpp::opp_string method;

  private:
    void copy(const HTTPClientMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HTTPClientMsg&);

  public:
    HTTPClientMsg(const char *name=nullptr, short kind=0);
    HTTPClientMsg(const HTTPClientMsg& other);
    virtual ~HTTPClientMsg();
    HTTPClientMsg& operator=(const HTTPClientMsg& other);
    virtual HTTPClientMsg *dup() const override {return new HTTPClientMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getRequest() const;
    virtual void setRequest(const char * request);
    virtual const char * getMethod() const;
    virtual void setMethod(const char * method);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HTTPClientMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HTTPClientMsg& obj) {obj.parsimUnpack(b);}


#endif // ifndef __HTTPCLIENTMSG_M_H

