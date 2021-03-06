// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2016-2018, The Karbowanec developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {
  
const uint64_t DIFFICULTY_TARGET                             = 240; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 153; // addresses start with "Sb"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 7;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(10000000000000000000);
const uint64_t TAIL_EMISSION_REWARD                          = UINT64_C(1000000000000);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 20;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 12;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000000000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000000);
const uint64_t MAX_TX_MIXIN_SIZE                             = 20;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 17; // blocks
const size_t   DIFFICULTY_WINDOW_V3                          = 60;  // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 60000;
const uint32_t UPGRADE_HEIGHT_V3                             = 2160000;
const unsigned UPGRADE_VOTING_THRESHOLD = 90;               // percent
const uint32_t   UPGRADE_VOTING_WINDOW                       = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t   UPGRADE_WINDOW                              = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "soldi";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff00019e91c191c79502029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210112187cd452a904bcfb49b5f1c3b3f893fee59a3369f51cac6e578e9cabc02765";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  52280;
const int      RPC_DEFAULT_PORT                              =  52281;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "3a96y6a8u557i8p1640o55336858doyuio8c668pe635pui365u8i84d085pa210";

const char* const SEED_NODES[] = { 
  "80.211.191.90:52280",
  "94.177.187.216:52280",
  "80.211.225.136:52280",
  "212.237.29.222:52280"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = { 
  {3500,	"347b6c9f0dfe57cc62582fb0424c2845ed1509489a59a36319ecd7a40b83994f" },
  {7000,	"80ee2bac7a8e7085494a0218de135a297d6730e51864d2b8d24625b4b89f4a2f" },
  {10000,	"c2f81935c5d244ba56d43b96a008b67699289a8fcef64267f188e014c57a5ea5" },
  {12000,	"ebe5cf3c4313177e921e84a705734ca4de45e40c572afe00ae209fad030b9f6f" },
  {16000,	"48d9c70ee4e9fd79e0e708c1f3a4bca650103d8cabc738a165a264c0b1aaa0ea" },
  {20000,	"57de61d0f58c73aa598d8bfb94d0d02463ab6c399367c387e77980f79a630f8c" },
  {24000,	"ff8bb51b3bdb0a99c867be5b7cef2b3092ba42d5dca56cd589fe4f5c356957e6" },
  {32000,	"8da054213ec5275e17af806efb5299cdd64a36814fd898ac3db1daa6a850f571" },
  {40000,	"2e5a1e10f71bc8851c59355efb4ecc0244843d28e1c9736e966384603a23a37e" },
  {46000,	"46f5d75bef3b74bbbe689dfd9ad86a7c4d701c20f3b16e966139fdf08fd6db7d" },
  {50000,	"3e4775e5ff8dfcb554c8fc990dfce5fcd260624ef502e0bd5dc7fd110e469a3a" },
  {60000,	"7bc708348ba6dd3dda792a12126b26caff8583ddda0030f9df2fa432e25e6af6" },
  {70000,	"f99313283ae886eddc567fb99a7e181564eb8e029a1df05faefca26d146a3468" },
  {80000,	"a2f8cd2ceb76f3d995427bf2d4a7237a5793b8e65743f833283846429719aabb" },
  {90000,	"01836fa4fcd409014f4bb82ef9c5dc5435cccc70d2fe8409148bcee060b88814" },
  {100000,	"87b47d41090254be8aee79572754e2beb64373891abcc2047470410fdfedf71f" },
  {110000,	"51d286c2100b3f2e77b70385cf612d001402528c4ed85d448830265b7b5e05a8" },
  {120000,	"90528e44db16552af142fb74e35f9ffbb0f04a1a97e040d8656bdad7979e62d8" },
  {130000,	"5014d5fce103cdc6d8180a972095e8e07fda50d4e176229f0a0039265f9f5f95" }
  
    };

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



