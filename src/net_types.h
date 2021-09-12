// Copyright (c) 2019 The Flocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FLOCOIN_NET_TYPES_H
#define FLOCOIN_NET_TYPES_H

#include <map>

class CBanEntry;
class CSubNet;

using banmap_t = std::map<CSubNet, CBanEntry>;

#endif // FLOCOIN_NET_TYPES_H
