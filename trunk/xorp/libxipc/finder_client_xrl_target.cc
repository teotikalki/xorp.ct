// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/libxipc/finder_client_xrl_target.cc,v 1.1 2003/02/24 19:39:18 hodson Exp $"

#include "finder_client_xrl_target.hh"
#include "finder_client.hh"

FinderClientXrlTarget::FinderClientXrlTarget(
			 FinderClientXrlCommandInterface* client,
			 XrlCmdMap* cmds)
    : XrlFinderclientTargetBase(cmds), _client(client)
{}

XrlCmdError
FinderClientXrlTarget::common_0_1_get_target_name(string& n)
{
    n = name();
    return XrlCmdError::OKAY();
}

XrlCmdError
FinderClientXrlTarget::common_0_1_get_version(string& v)
{
    v = version();
    return XrlCmdError::OKAY();
}

XrlCmdError
FinderClientXrlTarget::finder_client_0_1_hello()
{
    return XrlCmdError::OKAY();
}

XrlCmdError
FinderClientXrlTarget::finder_client_0_1_remove_xrl_from_cache(const string& xrl)
{
    _client->uncache_xrl(xrl);
    return XrlCmdError::OKAY();
}

XrlCmdError
FinderClientXrlTarget::finder_client_0_1_remove_xrls_for_target_from_cache(const string& target)
{
    _client->uncache_xrls_from_target(target);
    return XrlCmdError::OKAY();
}

