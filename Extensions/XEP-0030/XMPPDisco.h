//
//  XMPPDisco.h
//  iPhoneXMPP
//
//  Created by Rick Mellor on 1/9/13.
//
//

#import <XMPP/XMPP.h>

@interface XMPPDisco : XMPPModule
{
    NSXMLElement *myDiscoInfoQuery; // Full list of discovery info <query/>

    BOOL collectingMyDiscoInfo;
}

@end


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@protocol XMPPCapabilitiesDelegate
@optional

/**
 * Use this delegate method to add specific capabilities.
 * This method in invoked automatically when the stream is connected for the first time,
 * or if the module detects an outgoing presence element and my capabilities haven't been collected yet
 *
 * The design of XEP-115 is such that capabilites are expected to remain rather static.
 * However, if the capabilities change, the recollectMyCapabilities method may be used to perform a manual update.
 **/
- (void)xmppDisco:(XMPPDisco *)sender collectingMyDiscoInfo:(NSXMLElement *)query;

/**
 * Invoked when identity/feature info have been discovered for an available JID.
 *
 * The discoInfo element is the <query/> element response to a disco#info request.
 **/
- (void)xmppDisco:(XMPPDisco *)sender didReceiveDiscoveryInfo:(NSXMLElement *)discoInfo forJID:(XMPPJID *)jid;

@end