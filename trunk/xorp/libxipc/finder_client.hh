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

// $XORP: xorp/libxipc/finder_client.hh,v 1.5 2003/03/08 20:56:52 hodson Exp $

#ifndef __LIBXIPC_FINDER_NG_CLIENT_HH__
#define __LIBXIPC_FINDER_NG_CLIENT_HH__

#include <list>
#include <map>
#include <string>

#include "finder_client_base.hh"
#include "finder_messenger.hh"

#include "xrl_pf.hh"

struct FinderDBEntry {
    FinderDBEntry(const string& key)
	: _key(key) {}

    FinderDBEntry(const string& key, const string& value)
	: _key(key) { _values.push_back(value); }

    inline const string& key() const { return _key; }

    inline const list<string>& values() const { return _values; }
    inline list<string>& values() { return _values; }
    inline void clear() { _values.erase(_values.begin(), _values.end()); }
    
protected:
    string	 _key;
    list<string> _values;
};

class FinderClientOp;

class FinderClientXrlCommandInterface
{
public:
    virtual void uncache_xrl(const string& xrl)= 0;
    virtual void uncache_xrls_from_target(const string& target) = 0;
};

class FinderClient :
    public FinderMessengerManager, public FinderClientXrlCommandInterface
{
public:
    typedef
    XorpCallback2<void, const XrlError&, const FinderDBEntry*>::RefPtr
    QueryCallback;
    typedef ref_ptr<FinderClientOp> Operation;
    typedef list<Operation> OperationQueue;

    typedef map<string, FinderDBEntry> ResolvedTable;
    typedef map<string, string>        LocalResolvedTable;
    typedef vector<string>	       TargetIdList;
    
public:
    FinderClient();
    virtual ~FinderClient();

    bool register_xrl_target(const string& instance_name,
			     const string& class_name,
			     uint32_t&     target_id);

    bool unregister_xrl_target(uint32_t target_id);
    
    bool register_xrl(uint32_t	    target_id,
		      const string& xrl,
		      const string& pf_name,
		      const string& pf_args);

    bool enable_xrls(uint32_t target_id);
    
    void query(const string&	    key,
	       const QueryCallback& qcb);

    bool query_self(const string& incoming_xrl_command,
		    string& local_xrl_command) const;

    bool forward_finder_xrl(const Xrl&, const XrlPFSender::SendCallback&);
    
    FinderMessengerBase* messenger();

    inline OperationQueue& todo_list() { return _todo_list; }
    inline OperationQueue& done_list() { return _done_list; }
    void   notify_done(const FinderClientOp* completed);
    void   notify_failed(const FinderClientOp* completed);

    inline XrlCmdMap& commands() { return _commands; }

    inline bool connected() const { return _messenger != 0 && _xrls_registered; }
    
protected:
    // FinderMessengerManager interface
    void messenger_birth_event(FinderMessengerBase*);
    void messenger_death_event(FinderMessengerBase*);
    void messenger_active_event(FinderMessengerBase*);
    void messenger_inactive_event(FinderMessengerBase*);
    void messenger_stopped_event(FinderMessengerBase*);
    bool manages(const FinderMessengerBase*) const;

protected:
    // FinderClientXrlCommandInterface
    void uncache_xrl(const string& xrl);
    void uncache_xrls_from_target(const string& target);
    
protected:
    void crank();
    void prepare_for_restart();
    
protected:
    OperationQueue	_todo_list;
    OperationQueue	_done_list;
    ResolvedTable	_rt;
    LocalResolvedTable  _lrt;
    TargetIdList	_tids;

    XrlCmdMap		_commands;
    
    FinderMessengerBase* _messenger;
    bool		 _pending_result;
    bool		 _xrls_registered;
};

#endif // __LIBXIPC_FINDER_NG_CLIENT_HH__
