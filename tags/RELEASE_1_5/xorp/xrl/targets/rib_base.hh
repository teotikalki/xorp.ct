/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/rib_base.hh,v 1.47 2008/01/04 03:18:13 pavlin Exp $
 */


#ifndef __XRL_TARGETS_RIB_BASE_HH__
#define __XRL_TARGETS_RIB_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlRibTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlRibTargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlRibTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlRibTargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    const char* version() const { return "rib/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target birth to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_birth(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target death to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_death(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Configure a policy filter.
     *
     *  @param filter the identifier of the filter to configure.
     *
     *  @param conf the configuration of the filter.
     */
    virtual XrlCmdError policy_backend_0_1_configure(
	// Input values,
	const uint32_t&	filter,
	const string&	conf) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Reset a policy filter.
     *
     *  @param filter the identifier of the filter to reset.
     */
    virtual XrlCmdError policy_backend_0_1_reset(
	// Input values,
	const uint32_t&	filter) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Push all available routes through all filters for re-filtering.
     */
    virtual XrlCmdError policy_backend_0_1_push_routes() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable/start/stop RIB.
     */
    virtual XrlCmdError rib_0_1_enable_rib() = 0;

    virtual XrlCmdError rib_0_1_disable_rib() = 0;

    virtual XrlCmdError rib_0_1_start_rib() = 0;

    virtual XrlCmdError rib_0_1_stop_rib() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Make errors fatal; used to detect errors we'd normally mask
     */
    virtual XrlCmdError rib_0_1_make_errors_fatal() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of registered protocols.
     *
     *  @param ipv4 if true, then include the IPv4 protocols.
     *
     *  @param ipv6 if true, then include the IPv6 protocols.
     *
     *  @param unicast if true, then include the protocols registered with the
     *  unicast RIB.
     *
     *  @param multicast if true, then include the protocols registered with
     *  the multicast RIB.
     *
     *  @param ipv4_unicast_protocols the list of IPv4 protocols registered
     *  with the unicast RIB.
     *
     *  @param ipv6_unicast_protocols the list of IPv6 protocols registered
     *  with the unicast RIB.
     *
     *  @param ipv4_multicast_protocols the list of IPv4 protocols registered
     *  with the multicast RIB.
     *
     *  @param ipv6_multicast_protocols the list of IPv6 protocols registered
     *  with the multicast RIB.
     */
    virtual XrlCmdError rib_0_1_get_registered_protocols(
	// Input values,
	const bool&	ipv4,
	const bool&	ipv6,
	const bool&	unicast,
	const bool&	multicast,
	// Output values,
	XrlAtomList&	ipv4_unicast_protocols,
	XrlAtomList&	ipv6_unicast_protocols,
	XrlAtomList&	ipv4_multicast_protocols,
	XrlAtomList&	ipv6_multicast_protocols) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/delete an IGP or EGP table.
     *
     *  @param protocol the name of the protocol.
     *
     *  @param target_class the target class of the protocol.
     *
     *  @param target_instance the target instance of the protocol.
     *
     *  @param unicast true if the table is for the unicast RIB.
     *
     *  @param multicast true if the table is for the multicast RIB.
     */
    virtual XrlCmdError rib_0_1_add_igp_table4(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_igp_table6(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_igp_table4(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_igp_table6(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_egp_table4(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_add_egp_table6(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_egp_table4(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    virtual XrlCmdError rib_0_1_delete_egp_table6(
	// Input values,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/replace/delete a route.
     *
     *  @param protocol the name of the protocol this route comes from.
     *
     *  @param unicast true if the route is for the unicast RIB.
     *
     *  @param multicast true if the route is for the multicast RIB.
     *
     *  @param network the network address prefix of the route.
     *
     *  @param nexthop the address of the next-hop router toward the
     *  destination.
     *
     *  @param metric the routing metric.
     *
     *  @param policytags a set of policy tags used for redistribution.
     */
    virtual XrlCmdError rib_0_1_add_route4(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_add_route6(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_replace_route4(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_replace_route6(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_delete_route4(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network) = 0;

    virtual XrlCmdError rib_0_1_delete_route6(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add/replace a route by explicitly specifying the network interface
     *  toward the destination.
     *
     *  @param protocol the name of the protocol this route comes from.
     *
     *  @param unicast true if the route is for the unicast RIB.
     *
     *  @param multicast true if the route is for the multicast RIB.
     *
     *  @param network the network address prefix of the route.
     *
     *  @param nexthop the address of the next-hop router toward the
     *  destination.
     *
     *  @param ifname of the name of the physical interface toward the
     *  destination.
     *
     *  @param vifname of the name of the virtual interface toward the
     *  destination.
     *
     *  @param metric the routing metric.
     *
     *  @param policytags a set of policy tags used for redistribution.
     */
    virtual XrlCmdError rib_0_1_add_interface_route4(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_add_interface_route6(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_replace_interface_route4(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    virtual XrlCmdError rib_0_1_replace_interface_route6(
	// Input values,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Lookup nexthop.
     *
     *  @param addr address to lookup.
     *
     *  @param unicast look in unicast RIB.
     *
     *  @param multicast look in multicast RIB.
     *
     *  @param nexthop contains the resolved nexthop if successful, IPv4::ZERO
     *  otherwise. It is an error for the unicast and multicast fields to both
     *  be true or both false.
     */
    virtual XrlCmdError rib_0_1_lookup_route_by_dest4(
	// Input values,
	const IPv4&	addr,
	const bool&	unicast,
	const bool&	multicast,
	// Output values,
	IPv4&	nexthop) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Lookup nexthop.
     *
     *  @param addr address to lookup.
     *
     *  @param unicast look in unicast RIB.
     *
     *  @param multicast look in multicast RIB.
     *
     *  @param nexthop contains the resolved nexthop if successful, IPv6::ZERO
     *  otherwise. It is an error for the unicast and multicast fields to both
     *  be true or both false.
     */
    virtual XrlCmdError rib_0_1_lookup_route_by_dest6(
	// Input values,
	const IPv6&	addr,
	const bool&	unicast,
	const bool&	multicast,
	// Output values,
	IPv6&	nexthop) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add a vif or a vif address to the RIB. This interface should be used
     *  only for testing purpose.
     *
     *  @param name the name of the vif.
     */
    virtual XrlCmdError rib_0_1_new_vif(
	// Input values,
	const string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add a vif address to the RIB. This interface should be used only for
     *  testing purpose.
     *
     *  @param name the name of the vif.
     *
     *  @param addr the address to add.
     *
     *  @param subnet the subnet address to add.
     */
    virtual XrlCmdError rib_0_1_add_vif_addr4(
	// Input values,
	const string&	name,
	const IPv4&	addr,
	const IPv4Net&	subnet) = 0;

    virtual XrlCmdError rib_0_1_add_vif_addr6(
	// Input values,
	const string&	name,
	const IPv6&	addr,
	const IPv6Net&	subnet) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable route redistribution from one routing protocol to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist4/0.1.
     *
     *  @param from_protocol the name of the routing process routes are to be
     *  redistributed from.
     *
     *  @param unicast enable for unicast RIBs matching from and to.
     *
     *  @param multicast enable for multicast RIBs matching from and to.
     *
     *  @param network_prefix redistribite only the routes that fall into this
     *  prefix address.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist4/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_enable4(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network_prefix,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable route redistribution from one routing protocol to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist6/0.1.
     *
     *  @param from_protocol the name of the routing process routes are to be
     *  redistributed from.
     *
     *  @param unicast enable for unicast RIBs matching from and to.
     *
     *  @param multicast enable for multicast RIBs matching from and to.
     *
     *  @param network_prefix redistribite only the routes that fall into this
     *  prefix address.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist6/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_enable6(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network_prefix,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Disable route redistribution from one routing protocol to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist4/0.1 and previously called redist_enable4.
     *
     *  @param unicast disable for unicast RIBs matching from and to.
     *
     *  @param multicast disable for multicast RIBs matching from and to.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist4/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_disable4(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Disable route redistribution from one routing protocol to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist6/0.1 and previously called redist_enable6.
     *
     *  @param unicast disable for unicast RIBs matching from and to.
     *
     *  @param multicast disable for multicast RIBs matching from and to.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist6/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_disable6(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable transaction-based route redistribution from one routing protocol
     *  to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist_transaction4/0.1.
     *
     *  @param from_protocol the name of the routing process routes are to be
     *  redistributed from.
     *
     *  @param unicast enable for unicast RIBs matching from and to.
     *
     *  @param multicast enable for multicast RIBs matching from and to.
     *
     *  @param network_prefix redistribite only the routes that fall into this
     *  prefix address.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist_transaction4/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_transaction_enable4(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network_prefix,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable transaction-based route redistribution from one routing protocol
     *  to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist_transaction6/0.1.
     *
     *  @param from_protocol the name of the routing process routes are to be
     *  redistributed from.
     *
     *  @param unicast enable for unicast RIBs matching from and to.
     *
     *  @param multicast enable for multicast RIBs matching from and to.
     *
     *  @param network_prefix redistribite only the routes that fall into this
     *  prefix address.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist_transaction6/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_transaction_enable6(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network_prefix,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Disable transaction-based route redistribution from one routing
     *  protocol to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist_transaction4/0.1 and previously called
     *  redist_transaction_enable4.
     *
     *  @param unicast disable for unicast RIBs matching from and to.
     *
     *  @param multicast disable for multicast RIBs matching from and to.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist_transaction4/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_transaction_disable4(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Disable transaction-based route redistribution from one routing
     *  protocol to another.
     *
     *  @param to_xrl_target the XRL Target instance name of the caller. The
     *  caller must implement redist_transaction6/0.1 and previously called
     *  redist_transaction_enable6.
     *
     *  @param unicast disable for unicast RIBs matching from and to.
     *
     *  @param multicast disable for multicast RIBs matching from and to.
     *
     *  @param cookie a text value passed back to creator in each call from the
     *  RIB. This allows creators to identity the source of updates it receives
     *  through the redist_transaction6/0.1 interface.
     */
    virtual XrlCmdError rib_0_1_redist_transaction_disable6(
	// Input values,
	const string&	to_xrl_target,
	const string&	from_protocol,
	const bool&	unicast,
	const bool&	multicast,
	const string&	cookie) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Register an interest in a route.
     *
     *  @param target the name of the XRL module to notify when the information
     *  returned by this call becomes invalid.
     *
     *  @param addr address of interest.
     *
     *  @param resolves returns whether or not the address resolves to a route
     *  that can be used for forwarding.
     *
     *  @param base_addr returns the address of interest (actually the base
     *  address of the subnet covered by addr/prefix_len).
     *
     *  @param prefix_len returns the prefix length that the registration
     *  covers. This response applies to all addresses in addr/prefix_len.
     *
     *  @param real_prefix_len returns the actual prefix length of the route
     *  that will be used to route addr. If real_prefix_len is not the same as
     *  prefix_len, this is because there are some more specific routes that
     *  overlap addr/real_prefix_len. real_prefix_len is primarily given for
     *  debugging reasons.
     *
     *  @param nexthop returns the address of the next hop for packets sent to
     *  addr.
     *
     *  @param metric returns the IGP metric for this route.
     */
    virtual XrlCmdError rib_0_1_register_interest4(
	// Input values,
	const string&	target,
	const IPv4&	addr,
	// Output values,
	bool&	resolves,
	IPv4&	base_addr,
	uint32_t&	prefix_len,
	uint32_t&	real_prefix_len,
	IPv4&	nexthop,
	uint32_t&	metric) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  De-register an interest in a route.
     *
     *  @param target the name of the XRL module that registered the interest.
     *
     *  @param addr the address of the previous registered interest. addr
     *  should be the base address of the add/prefix_len subnet.
     *
     *  @param prefix_len the prefix length of the registered interest, as
     *  given in the response from register_interest.
     */
    virtual XrlCmdError rib_0_1_deregister_interest4(
	// Input values,
	const string&	target,
	const IPv4&	addr,
	const uint32_t&	prefix_len) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Register an interest in a route.
     *
     *  @param target the name of the XRL module to notify when the information
     *  returned by this call becomes invalid.
     *
     *  @param addr address of interest.
     *
     *  @param resolves returns whether or not the address resolves to a route
     *  that can be used for forwarding.
     *
     *  @param base_addr returns the address of interest (actually the base
     *  address of the subnet covered by addr/prefix_len).
     *
     *  @param prefix_len returns the prefix length that the registration
     *  covers. This response applies to all addresses in addr/prefix_len.
     *
     *  @param real_prefix_len returns the actual prefix length of the route
     *  that will be used to route addr. If real_prefix_len is not the same as
     *  prefix_len, this is because there are some more specific routes that
     *  overlap addr/real_prefix_len. real_prefix_len is primarily given for
     *  debugging reasons.
     *
     *  @param nexthop returns the address of the next hop for packets sent to
     *  addr.
     *
     *  @param metric returns the IGP metric for this route.
     */
    virtual XrlCmdError rib_0_1_register_interest6(
	// Input values,
	const string&	target,
	const IPv6&	addr,
	// Output values,
	bool&	resolves,
	IPv6&	base_addr,
	uint32_t&	prefix_len,
	uint32_t&	real_prefix_len,
	IPv6&	nexthop,
	uint32_t&	metric) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  De-register an interest in a route.
     *
     *  @param target the name of the XRL module that registered the interest.
     *
     *  @param addr the address of the previous registered interest. addr
     *  should be the base address of the add/prefix_len subnet.
     *
     *  @param prefix_len the prefix length of the registered interest, as
     *  given in the response from register_interest.
     */
    virtual XrlCmdError rib_0_1_deregister_interest6(
	// Input values,
	const string&	target,
	const IPv6&	addr,
	const uint32_t&	prefix_len) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Add policy tags for a specific protcol in the redistribution map.
     *
     *  @param protocol The destination protocol of the redistribution.
     *
     *  @param policytags The set of policytags of interest for the protocol.
     */
    virtual XrlCmdError rib_0_1_insert_policy_redist_tags(
	// Input values,
	const string&	protocol,
	const XrlAtomList&	policytags) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Reset the policy redistribution map. No policy based route
     *  redistribution will be available at this point.
     */
    virtual XrlCmdError rib_0_1_reset_policy_redist_tags() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get administrative distance for all protocols registered as having an
     *  admin distance in a selected RIB.
     *
     *  @param ipv4 true if getting admin distances from IPv4 RIB; false if
     *  getting admin distances from IPv6 RIB.
     *
     *  @param unicast true if getting admin distances from unicast RIB; false
     *  if getting admin distances from multicast RIB.
     *
     *  @param protocols the list of protocols registered as having an admin
     *  distance in the selected RIB.
     *
     *  @ref protocols list.
     */
    virtual XrlCmdError rib_0_1_get_protocol_admin_distances(
	// Input values,
	const bool&	ipv4,
	const bool&	unicast,
	// Output values,
	XrlAtomList&	protocols,
	XrlAtomList&	admin_distances) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get administrative distance for an individual protocol in a selected
     *  RIB.
     *
     *  @param protocol the name of the protocol.
     *
     *  @param ipv4 true if getting admin distance from IPv4 RIB; false if
     *  getting admin distance from IPv6 RIB.
     *
     *  @param unicast true if getting admin distance from unicast RIB; false
     *  if getting admin distance from multicast RIB.
     *
     *  @param admin_distance the administrative distance (1-255)
     */
    virtual XrlCmdError rib_0_1_get_protocol_admin_distance(
	// Input values,
	const string&	protocol,
	const bool&	ipv4,
	const bool&	unicast,
	// Output values,
	uint32_t&	admin_distance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set administrative distance for an individual protocol.
     *
     *  @param protocol the name of the protocol.
     *
     *  @param ipv4 true if setting admin distance for IPv4 RIB.
     *
     *  @param ipv6 true if setting admin distance for IPv6 RIB.
     *
     *  @param unicast true if setting admin distance for unicast RIB.
     *
     *  @param multicast true if setting admin distance for multicast RIB.
     *
     *  @param admin_distance the administrative distance (1-255)
     */
    virtual XrlCmdError rib_0_1_set_protocol_admin_distance(
	// Input values,
	const string&	protocol,
	const bool&	ipv4,
	const bool&	ipv6,
	const bool&	unicast,
	const bool&	multicast,
	const uint32_t&	admin_distance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable profiling
     *
     *  @param pname profile variable
     */
    virtual XrlCmdError profile_0_1_enable(
	// Input values,
	const string&	pname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Disable profiling
     *
     *  @param pname profile variable
     */
    virtual XrlCmdError profile_0_1_disable(
	// Input values,
	const string&	pname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get log entries.
     *
     *  @param pname profile variable
     *
     *  @param instance_name to send the profiling info to.
     */
    virtual XrlCmdError profile_0_1_get_entries(
	// Input values,
	const string&	pname,
	const string&	instance_name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Clear the profiling entries
     *
     *  @param pname profile variable
     */
    virtual XrlCmdError profile_0_1_clear(
	// Input values,
	const string&	pname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  List all the profiling variables registered with this target.
     */
    virtual XrlCmdError profile_0_1_list(
	// Output values,
	string&	info) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_configure(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_reset(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_push_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_enable_rib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_disable_rib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_start_rib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_stop_rib(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_make_errors_fatal(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_get_registered_protocols(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_igp_table4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_igp_table6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_delete_igp_table4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_delete_igp_table6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_egp_table4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_egp_table6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_delete_egp_table4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_delete_egp_table6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_replace_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_replace_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_delete_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_delete_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_replace_interface_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_replace_interface_route6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_lookup_route_by_dest4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_lookup_route_by_dest6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_new_vif(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_vif_addr4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_add_vif_addr6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_enable4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_enable6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_disable4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_disable6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_transaction_enable4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_transaction_enable6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_transaction_disable4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_redist_transaction_disable6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_register_interest4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_deregister_interest4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_register_interest6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_deregister_interest6(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_insert_policy_redist_tags(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_reset_policy_redist_tags(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_get_protocol_admin_distances(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_get_protocol_admin_distance(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_rib_0_1_set_protocol_admin_distance(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_enable(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_disable(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_get_entries(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_clear(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_list(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif // __XRL_TARGETS_RIB_BASE_HH__