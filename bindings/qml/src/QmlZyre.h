/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_ZYRE_H
#define QML_ZYRE_H

#include <QtQml>

#include <zyre.h>
#include "qml_zyre_plugin.h"


class QmlZyre : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)
    
public:
    zyre_t *self;
    
    QmlZyre() { self = NULL; }
    bool isNULL() { return self == NULL; }
    
    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZyre.cpp
    
public slots:
    //  Print properties of object
    void print ();

    //  Return our node UUID string, after successful initialization
    const QString uuid ();

    //  Return our node name, after successful initialization
    const QString name ();

    //  Set node header; these are provided to other nodes during discovery
    //  and come in each ENTER message.                                    
    void setHeader (const QString &name, const QString &format);

    //  Set verbose mode; this tells the node to log all traffic as well as 
    //  all major events.                                                   
    void setVerbose ();

    //  Set UDP beacon discovery port; defaults to 5670, this call overrides 
    //  that so you can create independent clusters on the same network, for 
    //  e.g. development vs. production. Has no effect after zyre_start().   
    void setPort (int portNbr);

    //  Set UDP beacon discovery interval, in milliseconds. Default is instant
    //  beacon exploration followed by pinging every 1,000 msecs.             
    void setInterval (size_t interval);

    //  Set network interface for UDP beacons. If you do not set this, CZMQ will
    //  choose an interface for you. On boxes with several interfaces you should
    //  specify which one you want to use, or strange things can happen.        
    void setInterface (const QString &value);

    //  By default, Zyre binds to an ephemeral TCP port and broadcasts the local 
    //  host name using UDP beaconing. When you call this method, Zyre will use  
    //  gossip discovery instead of UDP beaconing. You MUST set-up the gossip    
    //  service separately using zyre_gossip_bind() and _connect(). Note that the
    //  endpoint MUST be valid for both bind and connect operations. You can use 
    //  inproc://, ipc://, or tcp:// transports (for tcp://, use an IP address   
    //  that is meaningful to remote as well as local nodes). Returns 0 if       
    //  the bind was successful, else -1.                                        
    int setEndpoint (const QString &format);

    //  Set-up gossip discovery of other nodes. At least one node in the cluster
    //  must bind to a well-known gossip endpoint, so other nodes can connect to
    //  it. Note that gossip endpoints are completely distinct from Zyre node   
    //  endpoints, and should not overlap (they can use the same transport).    
    void gossipBind (const QString &format);

    //  Set-up gossip discovery of other nodes. A node may connect to multiple
    //  other nodes, for redundancy paths. For details of the gossip network  
    //  design, see the CZMQ zgossip class.                                   
    void gossipConnect (const QString &format);

    //  Start node, after setting header values. When you start a node it
    //  begins discovery and connection. Returns 0 if OK, -1 if it wasn't
    //  possible to start the node.                                      
    int start ();

    //  Stop node; this signals to other peers that this node will go away.
    //  This is polite; however you can also just destroy the node without 
    //  stopping it.                                                       
    void stop ();

    //  Join a named group; after joining a group you can send messages to
    //  the group and all Zyre nodes in that group will receive them.     
    int join (const QString &group);

    //  Leave a group
    int leave (const QString &group);

    //  Receive next message from network; the message may be a control
    //  message (ENTER, EXIT, JOIN, LEAVE) or data (WHISPER, SHOUT).   
    //  Returns zmsg_t object, or NULL if interrupted                  
    zmsg_t *recv ();

    //  Send message to single peer, specified as a UUID string
    //  Destroys message after sending                         
    int whisper (const QString &peer, zmsg_t **msgP);

    //  Send message to a named group 
    //  Destroys message after sending
    int shout (const QString &group, zmsg_t **msgP);

    //  Send formatted string to a single peer specified as UUID string
    int whispers (const QString &peer, const QString &format);

    //  Send formatted string to a named group
    int shouts (const QString &group, const QString &format);

    //  Return zlist of current peer ids. The caller owns this list and should
    //  destroy it when finished with it.                                     
    zlist_t *peers ();

    //  Return zlist of currently joined groups. The caller owns this list and
    //  should destroy it when finished with it.                              
    zlist_t *ownGroups ();

    //  Return zlist of groups known through connected peers. The caller owns this
    //  list and should destroy it when finished with it.                         
    zlist_t *peerGroups ();

    //  Return the endpoint of a connected peer. Caller owns the string.
    QString peerAddress (const QString &peer);

    //  Return the value of a header of a conected peer. 
    //  Returns null if peer or key doesn't exits. Caller
    //  owns the string                                  
    QString peerHeaderValue (const QString &peer, const QString &name);

    //  Return socket for talking to the Zyre node, for polling
    zsock_t *socket ();

    //  Prints Zyre node information
    void dump ();
};

class QmlZyreAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;
    
public:
    QmlZyreAttached (QObject* attached) {
        Q_UNUSED (attached);
    };
    
public slots:
    //  Return the Zyre version for run-time API detection
    void version (int *major, int *minor, int *patch);

    //  Self test of this class
    void test (bool verbose);

    //  Constructor, creates a new Zyre node. Note that until you start the
    //  node it is silent and invisible to other nodes on the network.     
    //  The node name is provided to other nodes during discovery. If you  
    //  specify NULL, Zyre generates a randomized node name from the UUID. 
    QmlZyre *construct (const QString &name);

    //  Destructor, destroys a Zyre node. When you destroy a node, any
    //  messages it is sending or receiving will be discarded.        
    void destruct (QmlZyre *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZyre, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
