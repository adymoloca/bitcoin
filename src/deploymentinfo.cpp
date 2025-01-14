// Copyright (c) 2016-2020 The Bitcoin Core developers
// Copyright (c) Flo Developers 2013-2021
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <deploymentinfo.h>

#include <consensus/params.h>

const struct VBDeploymentInfo VersionBitsDeploymentInfo[Consensus::MAX_VERSION_BITS_DEPLOYMENTS] = {
    {
        /*.name =*/ "testdummy",
        /*.gbt_force =*/ true,
    },
    {
        /*.name =*/ "csv",
        /*.gbt_force =*/ true,
    },
    {
        /*.name =*/ "segwit",
        /*.gbt_force =*/ true,
    }
};

std::string DeploymentName(Consensus::DeploymentPos dep)
{
    assert(ValidDeployment(dep));
    switch (dep) {
    case Consensus::DEPLOYMENT_TESTDUMMY:
        return "testdummy";
    case Consensus::DEPLOYMENT_CSV:
        return "csv";
    case Consensus::DEPLOYMENT_SEGWIT:
        return "segwit";
    } // no default case, so the compiler can warn about missing cases
    return "";
}
