/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/bgp_xif.hh,v 1.21 2004/03/23 19:33:20 atanu Exp $
 */

#ifndef __XRL_INTERFACES_BGP_XIF_HH__
#define __XRL_INTERFACES_BGP_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifBgp"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlBgpV0p2Client {
public:
    XrlBgpV0p2Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlBgpV0p2Client() {}

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetBgpVersionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the BGP version currently running.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_bgp_version(
	const char*	target_name,
	const GetBgpVersionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr LocalConfigCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get local config
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param id our BGP ID.
     */
    bool send_local_config(
	const char*	target_name,
	const uint32_t&	as,
	const IPv4&	id,
	const LocalConfigCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetLocalAsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the local AS number.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param as our AS number.
     */
    bool send_set_local_as(
	const char*	target_name,
	const uint32_t&	as,
	const SetLocalAsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetLocalAsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the local AS number.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_local_as(
	const char*	target_name,
	const GetLocalAsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetBgpIdCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the BGP id.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param id our BGP ID.
     */
    bool send_set_bgp_id(
	const char*	target_name,
	const IPv4&	id,
	const SetBgpIdCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv4*>::RefPtr GetBgpIdCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the BGP id.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_bgp_id(
	const char*	target_name,
	const GetBgpIdCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddPeerCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add peer.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param as the peer's AS number.
     *
     *  @param next_hop the local next hop.
     *
     *  @param holdtime expects traffic in this time interval.
     */
    bool send_add_peer(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const uint32_t&	as,
	const IPv4&	next_hop,
	const uint32_t&	holdtime,
	const AddPeerCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeletePeerCB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete peer.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_delete_peer(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const DeletePeerCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnablePeerCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable this peer.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_enable_peer(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const EnablePeerCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DisablePeerCB;
    /**
     *  Send Xrl intended to:
     *
     *  Disable this peer.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_disable_peer(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const DisablePeerCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetParameterCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set which parameters we support per peer
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_set_parameter(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const string&	parameter,
	const SetParameterCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr NextHopRewriteFilterCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set next hop rewrite filter. XXX - This is a temporary hack until we
     *  get programmable filters.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_next_hop_rewrite_filter(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const IPv4&	next_hop,
	const NextHopRewriteFilterCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetPeerStateCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the peer state enabled or disabled.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param toggle enabled or disabled.
     */
    bool send_set_peer_state(
	const char*	target_name,
	const string&	local_ip,
	const uint32_t&	local_port,
	const string&	peer_ip,
	const uint32_t&	peer_port,
	const bool&	toggle,
	const SetPeerStateCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr OriginateRoute4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Originate route IPv4
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param nlri subnet to announce
     *
     *  @param next_hop to forward to
     *
     *  @param unicast if true install in unicast routing table
     *
     *  @param multicast if true install in multicast routing table
     */
    bool send_originate_route4(
	const char*	target_name,
	const IPv4Net&	nlri,
	const IPv4&	next_hop,
	const bool&	unicast,
	const bool&	multicast,
	const OriginateRoute4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr OriginateRoute6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Originate route IPv6
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param nlri subnet to announce
     *
     *  @param next_hop to forward to
     *
     *  @param unicast if true install in unicast routing table
     *
     *  @param multicast if true install in multicast routing table
     */
    bool send_originate_route6(
	const char*	target_name,
	const IPv6Net&	nlri,
	const IPv6&	next_hop,
	const bool&	unicast,
	const bool&	multicast,
	const OriginateRoute6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr WithdrawRoute4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Withdraw route IPv4
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param nlri subnet to withdraw
     *
     *  @param unicast if true withdraw from unicast routing table
     *
     *  @param multicast if true withdraw from multicast routing table
     */
    bool send_withdraw_route4(
	const char*	target_name,
	const IPv4Net&	nlri,
	const bool&	unicast,
	const bool&	multicast,
	const WithdrawRoute4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr WithdrawRoute6CB;
    /**
     *  Send Xrl intended to:
     *
     *  Withdraw route IPv6
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param nlri subnet to withdraw
     *
     *  @param unicast if true withdraw from unicast routing table
     *
     *  @param multicast if true withdraw from multicast routing table
     */
    bool send_withdraw_route6(
	const char*	target_name,
	const IPv6Net&	nlri,
	const bool&	unicast,
	const bool&	multicast,
	const WithdrawRoute6CB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const bool*>::RefPtr GetPeerListStartCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the first item of a list of BGP peers See RFC 1657 (BGP MIB) for
     *  full definitions of return values.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_peer_list_start(
	const char*	target_name,
	const GetPeerListStartCB&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const IPv4*, const uint32_t*, const IPv4*, const uint32_t*, const bool*>::RefPtr GetPeerListNextCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the next item of a list of BGP peers
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param token token from prior call to get_peer_list
     */
    bool send_get_peer_list_next(
	const char*	target_name,
	const uint32_t&	token,
	const GetPeerListNextCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv4*>::RefPtr GetPeerIdCB;

    bool send_get_peer_id(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerIdCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const uint32_t*>::RefPtr GetPeerStatusCB;

    bool send_get_peer_status(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerStatusCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const int32_t*>::RefPtr GetPeerNegotiatedVersionCB;

    bool send_get_peer_negotiated_version(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerNegotiatedVersionCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetPeerAsCB;

    bool send_get_peer_as(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerAsCB&	cb
    );

    typedef XorpCallback7<void, const XrlError&, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*>::RefPtr GetPeerMsgStatsCB;

    bool send_get_peer_msg_stats(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerMsgStatsCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const uint32_t*>::RefPtr GetPeerEstablishedStatsCB;

    bool send_get_peer_established_stats(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerEstablishedStatsCB&	cb
    );

    typedef XorpCallback8<void, const XrlError&, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*, const uint32_t*>::RefPtr GetPeerTimerConfigCB;

    bool send_get_peer_timer_config(
	const char*	target_name,
	const IPv4&	local_ip,
	const uint32_t&	local_port,
	const IPv4&	peer_ip,
	const uint32_t&	peer_port,
	const GetPeerTimerConfigCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterRibCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register rib.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param name rib name.
     */
    bool send_register_rib(
	const char*	target_name,
	const string&	name,
	const RegisterRibCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetV4RouteListStartCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the first item of a list of BGP routes See RFC 1657 (BGP MIB) for
     *  full definitions of return values.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_v4_route_list_start(
	const char*	target_name,
	const GetV4RouteListStartCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetV6RouteListStartCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the first item of a list of BGP routes See RFC 1657 (BGP MIB) for
     *  full definitions of return values.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_v6_route_list_start(
	const char*	target_name,
	const GetV6RouteListStartCB&	cb
    );

    typedef XorpCallback13<void, const XrlError&, const IPv4*, const IPv4Net*, const uint32_t*, const vector<uint8_t>*, const IPv4*, const int32_t*, const int32_t*, const int32_t*, const vector<uint8_t>*, const int32_t*, const vector<uint8_t>*, const bool*>::RefPtr GetV4RouteListNextCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the next route in the list See RFC 1657 (BGP MIB) for full
     *  definitions of return values.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_v4_route_list_next(
	const char*	target_name,
	const uint32_t&	token,
	const GetV4RouteListNextCB&	cb
    );

    typedef XorpCallback13<void, const XrlError&, const IPv4*, const IPv6Net*, const uint32_t*, const vector<uint8_t>*, const IPv6*, const int32_t*, const int32_t*, const int32_t*, const vector<uint8_t>*, const int32_t*, const vector<uint8_t>*, const bool*>::RefPtr GetV6RouteListNextCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the next route in the list See RFC 1657 (BGP MIB) for full
     *  definitions of return values.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_v6_route_list_next(
	const char*	target_name,
	const uint32_t&	token,
	const GetV6RouteListNextCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_get_bgp_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetBgpVersionCB		cb
    );

    void unmarshall_local_config(
	const XrlError&	e,
	XrlArgs*	a,
	LocalConfigCB		cb
    );

    void unmarshall_set_local_as(
	const XrlError&	e,
	XrlArgs*	a,
	SetLocalAsCB		cb
    );

    void unmarshall_get_local_as(
	const XrlError&	e,
	XrlArgs*	a,
	GetLocalAsCB		cb
    );

    void unmarshall_set_bgp_id(
	const XrlError&	e,
	XrlArgs*	a,
	SetBgpIdCB		cb
    );

    void unmarshall_get_bgp_id(
	const XrlError&	e,
	XrlArgs*	a,
	GetBgpIdCB		cb
    );

    void unmarshall_add_peer(
	const XrlError&	e,
	XrlArgs*	a,
	AddPeerCB		cb
    );

    void unmarshall_delete_peer(
	const XrlError&	e,
	XrlArgs*	a,
	DeletePeerCB		cb
    );

    void unmarshall_enable_peer(
	const XrlError&	e,
	XrlArgs*	a,
	EnablePeerCB		cb
    );

    void unmarshall_disable_peer(
	const XrlError&	e,
	XrlArgs*	a,
	DisablePeerCB		cb
    );

    void unmarshall_set_parameter(
	const XrlError&	e,
	XrlArgs*	a,
	SetParameterCB		cb
    );

    void unmarshall_next_hop_rewrite_filter(
	const XrlError&	e,
	XrlArgs*	a,
	NextHopRewriteFilterCB		cb
    );

    void unmarshall_set_peer_state(
	const XrlError&	e,
	XrlArgs*	a,
	SetPeerStateCB		cb
    );

    void unmarshall_originate_route4(
	const XrlError&	e,
	XrlArgs*	a,
	OriginateRoute4CB		cb
    );

    void unmarshall_originate_route6(
	const XrlError&	e,
	XrlArgs*	a,
	OriginateRoute6CB		cb
    );

    void unmarshall_withdraw_route4(
	const XrlError&	e,
	XrlArgs*	a,
	WithdrawRoute4CB		cb
    );

    void unmarshall_withdraw_route6(
	const XrlError&	e,
	XrlArgs*	a,
	WithdrawRoute6CB		cb
    );

    void unmarshall_get_peer_list_start(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerListStartCB		cb
    );

    void unmarshall_get_peer_list_next(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerListNextCB		cb
    );

    void unmarshall_get_peer_id(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerIdCB		cb
    );

    void unmarshall_get_peer_status(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerStatusCB		cb
    );

    void unmarshall_get_peer_negotiated_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerNegotiatedVersionCB		cb
    );

    void unmarshall_get_peer_as(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerAsCB		cb
    );

    void unmarshall_get_peer_msg_stats(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerMsgStatsCB		cb
    );

    void unmarshall_get_peer_established_stats(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerEstablishedStatsCB		cb
    );

    void unmarshall_get_peer_timer_config(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerTimerConfigCB		cb
    );

    void unmarshall_register_rib(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterRibCB		cb
    );

    void unmarshall_get_v4_route_list_start(
	const XrlError&	e,
	XrlArgs*	a,
	GetV4RouteListStartCB		cb
    );

    void unmarshall_get_v6_route_list_start(
	const XrlError&	e,
	XrlArgs*	a,
	GetV6RouteListStartCB		cb
    );

    void unmarshall_get_v4_route_list_next(
	const XrlError&	e,
	XrlArgs*	a,
	GetV4RouteListNextCB		cb
    );

    void unmarshall_get_v6_route_list_next(
	const XrlError&	e,
	XrlArgs*	a,
	GetV6RouteListNextCB		cb
    );

};

#endif /* __XRL_INTERFACES_BGP_XIF_HH__ */
