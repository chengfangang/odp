/* Copyright (c) 2014, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */


/**
 * @file
 *
 * ODP ethernet header
 */

#ifndef ODP_ETH_H_
#define ODP_ETH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <odp_std_types.h>
#include <odp_byteorder.h>
#include <odp_align.h>
#include <odp_debug.h>

#define ODP_ETHADDR_LEN     6
#define ODP_ETHHDR_LEN      14
#define ODP_VLANHDR_LEN     4
#define ODP_ETH_LEN_MIN     60   /* exclude 4B CRC/FCS */
#define ODP_ETH_LEN_MIN_CRC 64   /* include 4B CRC/FCS */
#define ODP_ETH_LEN_MAX     1514 /* exclude 4B CRC/FCS */
#define ODP_ETH_LEN_MAX_CRC 1518 /* include 4B CRC/FCS */

/**
 * Ethernet MAC address
 */
typedef struct ODP_PACKED {
	uint8_t addr[ODP_ETHADDR_LEN];
} odp_ethaddr_t;

ODP_ASSERT(sizeof(odp_ethaddr_t) == ODP_ETHADDR_LEN, ODP_ETHADDR_T__SIZE_ERROR);

/**
 * Ethernet header
 */
typedef struct ODP_PACKED {
	odp_ethaddr_t dst;
	odp_ethaddr_t src;
	uint16be_t type;
} odp_ethhdr_t;

ODP_ASSERT(sizeof(odp_ethhdr_t) == ODP_ETHHDR_LEN, ODP_ETHHDR_T__SIZE_ERROR);

/**
 * VLAN header
 */
typedef struct ODP_PACKED {
	uint16be_t tpid;
	uint16be_t tci;
} odp_vlanhdr_t;

ODP_ASSERT(sizeof(odp_vlanhdr_t) == ODP_VLANHDR_LEN, ODP_VLANHDR_T__SIZE_ERROR);


/* Ethernet header Ether Type ('type') values, a selected few */
#define ODP_ETHTYPE_IPV4       0x0800 /**< Internet Protocol version 4 */
#define ODP_ETHTYPE_ARP        0x0806 /**< Address Resolution Protocol */
#define ODP_ETHTYPE_RARP       0x8035 /**< Reverse Address Resolution Protocol*/
#define ODP_ETHTYPE_VLAN       0x8100 /**< VLAN-tagged frame IEEE 802.1Q */
#define ODP_ETHTYPE_VLAN_OUTER 0x88A8 /**< Stacked VLANs/QinQ, outer-tag/S-TAG*/
#define ODP_ETHTYPE_IPV6       0x86dd /**< Internet Protocol version 6 */
#define ODP_ETHTYPE_FLOW_CTRL  0x8808 /**< Ethernet flow control */
#define ODP_ETHTYPE_MPLS       0x8847 /**< MPLS unicast */
#define ODP_ETHTYPE_MPLS_MCAST 0x8848 /**< MPLS multicast */
#define ODP_ETHTYPE_MACSEC     0x88E5 /**< MAC security IEEE 802.1AE */
#define ODP_ETHTYPE_1588       0x88F7 /**< Precision Time Protocol IEEE 1588 */

#ifdef __cplusplus
}
#endif

#endif
