#!/usr/bin/env python3
# Copyright (c) 2009-2020 The Bitcoin Core developers
# Copyright (c) Flo Developers 2013-2021
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test the getchaintips RPC.
- introduce a network split
- work on chains of different lengths
- join the network together again
- verify that getchaintips now returns two chain tips.
"""

import time

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_equal

class GetChainTipsTest (BitcoinTestFramework):
    def __init__(self):
        super().__init__()
        self.num_nodes = 4
        self.extra_args = [['-nlrlimit=0'], ['-nlrlimit=10'], ['-nlrlimit=10'], ['-nlrlimit=10']]
        self.setup_clean_chain = False

    def run_test (self):

        tips = self.nodes[0].getchaintips ()
        assert_equal (len (tips), 1)
        assert_equal (tips[0]['branchlen'], 0)
        assert_equal (tips[0]['height'], 200)
        assert_equal (tips[0]['status'], 'active')

        # Split the network and build two chains of different lengths.
        self.split_network()
        self.nodes[0].generate(10)
        self.nodes[2].generate(20)
        self.sync_all([self.nodes[:2], self.nodes[2:]])

        tips = self.nodes[1].getchaintips ()
        assert_equal (len (tips), 1)
        shortTip = tips[0]
        assert_equal(shortTip['branchlen'], 0)
        assert_equal(shortTip['height'], 210)
        assert_equal(tips[0]['status'], 'active')

        tips = self.nodes[3].getchaintips ()
        assert_equal (len (tips), 1)
        longTip = tips[0]
        assert_equal (longTip['branchlen'], 0)
        assert_equal (longTip['height'], 220)
        assert_equal (tips[0]['status'], 'active')

        # Join the network halves and check that we now have two tips
        # (at least at the nodes that previously had the short chain).
        print("pre join")
        self.join_network_no_sync ()
        time.sleep(10)
        print("post join")

        print("node 0")
        print(self.nodes[0].getchaintips())
        print("node 1")
        print(self.nodes[1].getchaintips())
        print("node 2")
        print(self.nodes[2].getchaintips())

        print("reconsider")
        self.nodes[1].reconsiderblock(self.nodes[2].getbestblockhash())
        self.sync_all()

        print("node 0")
        print(self.nodes[0].getchaintips ())
        print("node 1")
        print(self.nodes[1].getchaintips ())
        print("node 2")
        print(self.nodes[2].getchaintips ())
        self.nodes[2].generate(20)

        self.sync_all()
        self.nodes[1].generate(20)

        self.sync_all()

        print("node 0")
        print(self.nodes[0].getchaintips ())
        print("node 1")
        print(self.nodes[1].getchaintips ())
        print("node 2")
        print(self.nodes[2].getchaintips ())

        # tips = self.nodes[1].getchaintips ()
        # assert_equal (len (tips), 2)
        # assert_equal (tips[0], longTip)
        #
        # assert_equal (tips[1]['branchlen'], 10)
        # assert_equal (tips[1]['status'], 'valid-fork')
        # tips[1]['branchlen'] = 0
        # tips[1]['status'] = 'active'
        # assert_equal (tips[1], shortTip)

        assert_equal(1, 3)

if __name__ == '__main__':
    GetChainTipsTest().main()