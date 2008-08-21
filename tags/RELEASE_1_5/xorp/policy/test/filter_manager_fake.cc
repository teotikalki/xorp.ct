// vim:set sts=4 ts=8:

// Copyright (c) 2001-2008 XORP, Inc.
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

#ident "$XORP: xorp/policy/test/filter_manager_fake.cc,v 1.7 2008/01/04 03:17:21 pavlin Exp $"

#include "libxorp/xorp.h"

#include <iostream>

#include "filter_manager_fake.hh"

void
FilterManagerFake::update_filter(const Code::Target& t) {
    cout << "FilterManagerFake update_filter: " << t.str() << endl;
}

void
FilterManagerFake::flush_updates(uint32_t msec) {
    cout << "FilterManagerFake flush_updates msec: " << msec << endl;
}