/*
 * cfg_parse.c
 *
 * used for .....
 *
 * Author: renhaibo
 *
 * Copyright (c) 2021 Shandong ZTop Microelectronics Co., Ltd
 *
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 */
#include <linux/string.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/list.h>
#include <linux/usb.h>
#include <linux/time.h>

#include "common.h"
#include "hif.h"
#include "power.h"

struct cfg_preparse_t
{
    const zt_s8 *key;
    zt_s32(*preparse_handle)(hif_mngent_st *hif, const zt_s8 *value);
};

static zt_s32 fw_path_preparse_handle(hif_mngent_st *hif, const zt_s8 *value);
static zt_s32 fw1_path_preparse_handle(hif_mngent_st *hif, const zt_s8 *value);
static zt_s32 ifname_preparse_handle(hif_mngent_st *hif, const zt_s8 *value);
static zt_s32 if2name_preparse_handle(hif_mngent_st *hif, const zt_s8 *value);

static const struct cfg_preparse_t __gl_cfg_preparse_st[] =
{
    {"fw", fw_path_preparse_handle},
    {"fw1", fw1_path_preparse_handle},
    {"ifname", ifname_preparse_handle},
    {"if2name", if2name_preparse_handle},
};

static zt_s32 fw_path_preparse_handle(hif_mngent_st *hif, const zt_s8 *value)
{
    LOG_I("fw: %s", value);
    zt_memcpy(hif->fw_path, value, zt_strlen(value));
    return 0;
}

static zt_s32 fw1_path_preparse_handle(hif_mngent_st *hif, const zt_s8 *value)
{
    LOG_I("fw1: %s", value);
    zt_memcpy(hif->fw1_path, value, zt_strlen(value));
    return 0;
}

static zt_s32 ifname_preparse_handle(hif_mngent_st *hif, const zt_s8 *value)
{
    LOG_I("ifname: %s", value);
    zt_memcpy(hif->ifname, value, zt_strlen(value));
    return 0;
}

static zt_s32 if2name_preparse_handle(hif_mngent_st *hif, const zt_s8 *value)
{
    LOG_I("if2name: %s", value);
    zt_memcpy(hif->if2name, value, zt_strlen(value));
    return 0;
}

struct cfg_parse_t
{
    const zt_s8 *key;
    zt_s32(*parse_handle)(nic_info_st *nic_info, const zt_s8 *value);
};

#ifdef CFG_ENABLE_AP_MODE
static zt_s32 ssid_parse_handle(nic_info_st *nic_info, const zt_s8 *value);
#endif
static zt_s32 channel_parse_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 bw_parse_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 work_mode_parse_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 channelplan_parse_handle(nic_info_st *nic_info,
                                       const zt_s8 *value);
static zt_s32 ba_func_tx_parse_handle(nic_info_st *nic_info,
                                      const zt_s8 *value);
static zt_s32 ba_func_rx_parse_handle(nic_info_st *nic_info,
                                      const zt_s8 *value);
static zt_s32 scan_ch_to_parse_handle(nic_info_st *nic_info,
                                      const zt_s8 *value);
static zt_s32 scan_prb_times_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 scan_active_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 cfg_bool_value(const zt_s8 *value);
static zt_s32 scan_que_deep_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 scan_que_node_ttl_handle(nic_info_st *nic_info,
                                       const zt_s8 *value);
static zt_s32 ars_policy_handle(nic_info_st *nic_info,
                                const zt_s8 *value);
static zt_s32 max_ampdu_len_ulimit_handle(nic_info_st *nic_info,
        const zt_s8 *value);
static zt_s32 wlan_guard_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 rf_power_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 txpower_dbm_handle(nic_info_st *nic_info, const zt_s8 *value);
#ifdef CFG_ENABLE_ADHOC_MODE
static zt_s32 adhoc_master_handle(nic_info_st *nic_info, const zt_s8 *value);
#endif
static zt_s32 rf_power1_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 rf_power2_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 vco_cur_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 sdio_clk_pwr_save_handle(nic_info_st *nic_info,
                                       const zt_s8 *value);
static zt_s32 rts_thresh_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 frag_thresh_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 vcs_en_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 vcs_type_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 tx_data_rpt_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 sm_ps_support_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 wdn_sleep_support_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 ldpc_support_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 tx_stbc_support_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 max_rx_ampdu_factor_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 best_ampdu_density_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 ht_mcs_max_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 wireless_mode_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 sgi_20_handle(nic_info_st *nic_info, const zt_s8 *value);
static zt_s32 sgi_40_handle(nic_info_st *nic_info, const zt_s8 *value);

static const struct cfg_parse_t __gl_cfg_parse_st[] =
{
#ifdef CFG_ENABLE_AP_MODE
    {"ssid", ssid_parse_handle},
#endif
    {"channel", channel_parse_handle},
    {"bw", bw_parse_handle},
    {"work_mode", work_mode_parse_handle},
    {"channelplan", channelplan_parse_handle},
    {"ba_func_tx", ba_func_tx_parse_handle},
    {"ba_func_rx", ba_func_rx_parse_handle},
    {"scan_ch_to", scan_ch_to_parse_handle},
    {"scan_prb_times", scan_prb_times_handle},
    {"scan_active", scan_active_handle},
    {"scan_que_deep", scan_que_deep_handle},
    {"scan_que_node_ttl", scan_que_node_ttl_handle},
    {"ars_policy", ars_policy_handle},
    {"max_ampdu_len_ulimit", max_ampdu_len_ulimit_handle},
    {"wlan_guard", wlan_guard_handle},
    /* Generic rf_power is applied first; rf_power1/rf_power2 below override it per silicon generation. */
    {"rf_power", rf_power_handle},
    {"txpower_dbm", txpower_dbm_handle},
#ifdef CFG_ENABLE_ADHOC_MODE
    {"adhoc_master", adhoc_master_handle},
#endif
    {"rf_power1", rf_power1_handle},
    {"rf_power2", rf_power2_handle},
    {"vco_cur", vco_cur_handle},
    {"vco_curr", vco_cur_handle}, /* legacy spelling retained for existing cfg files */
    {"sdio_clk_pwr_save", sdio_clk_pwr_save_handle},
    {"rts_thresh", rts_thresh_handle},
    {"frag_thresh", frag_thresh_handle},
    {"vcs_en", vcs_en_handle},
    {"vcs_type", vcs_type_handle},
    {"tx_data_rpt", tx_data_rpt_handle},
    {"sm_ps_support", sm_ps_support_handle},
    {"wdn_sleep_support", wdn_sleep_support_handle},
    {"ldpc_support", ldpc_support_handle},
    {"tx_stbc_support", tx_stbc_support_handle},
    {"max_rx_ampdu_factor", max_rx_ampdu_factor_handle},
    {"best_ampdu_density", best_ampdu_density_handle},
    {"ht_mcs_max", ht_mcs_max_handle},
    {"wireless_mode", wireless_mode_handle},
    {"sgi_20", sgi_20_handle},
    {"sgi_40", sgi_40_handle},
};

#ifdef CFG_ENABLE_AP_MODE
static zt_s32 ssid_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("ssid: %s", value);
    zt_memcpy(plocal->ssid, value, zt_strlen(value));
    return 0;
}
#endif

static zt_s32 channel_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("channel: %s", value);
    plocal->channel = zt_atoi(value);
    return 0;
}

static zt_s32 bw_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("bw: %s", value);
    if (zt_strncmp(value, "20M", zt_strlen("20M")) == 0)
    {
        plocal->bw = 0;
    }
    else if (zt_strncmp(value, "40M", zt_strlen("40M")) == 0)
    {
        plocal->bw = 1;
    }
    else
    {
        LOG_E("cfg file format error for bw");
    }
    return 0;
}

static zt_s32 work_mode_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("work_mode: %s (nic=%d)", value, nic_info->nic_num);

    /* Exact matching is intentional: prefix matching made "apsta" select
     * AP because "ap" was tested first. */
    if (zt_strcmp(value, "sta") == 0)
        plocal->work_mode = ZT_INFRA_MODE;
#ifdef CONFIG_STA_AND_AP_MODE
    else if (zt_strcmp(value, "apsta") == 0 ||
             zt_strcmp(value, "repeat") == 0)
        /* No native repeater opcode exists in the firmware.  Repeat is the
         * supported two-NIC STA+AP topology; Linux bridging/routing forwards
         * traffic between the two interfaces. */
        plocal->work_mode = (nic_info->nic_num == 0) ? ZT_INFRA_MODE : ZT_MASTER_MODE;
#endif
#ifdef CFG_ENABLE_AP_MODE
    else if (zt_strcmp(value, "ap") == 0)
        plocal->work_mode = ZT_MASTER_MODE;
    else if (zt_strcmp(value, "second") == 0 ||
             zt_strcmp(value, "secondary") == 0)
        plocal->work_mode = (nic_info->nic_num == 1) ? ZT_MASTER_MODE : ZT_INFRA_MODE;
#else
    else if (zt_strcmp(value, "apsta") == 0 ||
             zt_strcmp(value, "repeat") == 0 ||
             zt_strcmp(value, "second") == 0 ||
             zt_strcmp(value, "secondary") == 0)
    {
        LOG_W("work_mode=%s: AP support is not compiled; using STA role", value);
        plocal->work_mode = ZT_INFRA_MODE;
    }
#endif
#ifdef CFG_ENABLE_ADHOC_MODE
    else if (zt_strcmp(value, "adhoc") == 0)
        plocal->work_mode = ZT_ADHOC_MODE;
#endif
#ifdef CFG_ENABLE_MONITOR_MODE
    else if (zt_strcmp(value, "monitor") == 0 ||
             zt_strcmp(value, "moniter") == 0)
        plocal->work_mode = ZT_MONITOR_MODE;
#endif
    else if (zt_strcmp(value, "mesh") == 0)
    {
#ifdef CFG_ENABLE_ADHOC_MODE
        /* Linux exposes a real NL80211 mesh interface, while this firmware
         * has no 802.11s MCU opcode.  Keep the hardware on the proven IBSS
         * data path; cfg80211 mesh callbacks translate mesh join/leave into
         * that path.  This is intentionally a mesh/IBSS compatibility mode,
         * not a claim of native 802.11s HWMP/MPM support. */
        LOG_W("work_mode=mesh: Linux mesh interface using IBSS data path");
        plocal->work_mode = ZT_ADHOC_MODE;
#else
        LOG_W("work_mode=mesh: ADHOC support is not compiled; using STA role");
        plocal->work_mode = ZT_INFRA_MODE;
#endif
    }
    else
        LOG_E("cfg file format error for param work_mode");

    return 0;
}

static zt_s32 channelplan_parse_handle(nic_info_st *nic_info,
                                       const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("channelplan: %s", value);
    plocal->channel_plan = zt_atoi(value);
    return 0;
}

static zt_s32 ba_func_tx_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("ba_func_tx: %s", value);
    plocal->ba_enable_tx = zt_atoi(value);
    return 0;
}

static zt_s32 ba_func_rx_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    LOG_I("ba_func_rx: %s", value);
    plocal->ba_enable_rx = zt_atoi(value);
    return 0;
}

static zt_s32 scan_ch_to_parse_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    zt_s32 v = zt_atoi(value);
    if (v < 1) v = 1;
    if (v > 255) v = 255;
    LOG_I("scan_ch_to: %s -> %d", value, v);
    plocal->scan_ch_to = (zt_u8)v;
    return 0;
}

static zt_s32 scan_prb_times_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    zt_s32 v = zt_atoi(value);
    if (v < 1) v = 1;
    if (v > 8) v = 8;
    LOG_I("scan_prb_times: %s -> %d", value, v);
    plocal->scan_prb_times = (zt_u8)v;
    return 0;
}

static zt_s32 cfg_bool_value(const zt_s8 *value)
{
    if (zt_strncmp(value, "true", zt_strlen("true")) == 0 ||
            zt_strncmp(value, "on", zt_strlen("on")) == 0 ||
            zt_strncmp(value, "yes", zt_strlen("yes")) == 0)
        return 1;
    if (zt_strncmp(value, "false", zt_strlen("false")) == 0 ||
            zt_strncmp(value, "off", zt_strlen("off")) == 0 ||
            zt_strncmp(value, "no", zt_strlen("no")) == 0)
        return 0;
    return !!zt_atoi(value);
}

static zt_s32 scan_active_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    LOG_I("scan_active: %s", value);
    plocal->scan_active = cfg_bool_value(value);
    return 0;
}

static zt_s32 scan_que_deep_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    zt_s32 v = zt_atoi(value);
    if (v < 1) v = 1;
    if (v > 255) v = 255;
    LOG_I("scan_que_deep: %s -> %d", value, v);
    plocal->scan_que_deep = (zt_u8)v;
    return 0;
}

static zt_s32 scan_que_node_ttl_handle(nic_info_st *nic_info,
                                       const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    zt_s32 v = zt_atoi(value);
    if (v < 1) v = 1;
    if (v > 255) v = 255;
    LOG_I("scan_que_node_ttl: %s -> %d", value, v);
    plocal->scan_que_node_ttl = (zt_u8)v;
    return 0;
}

static zt_s32 ars_policy_handle(nic_info_st *nic_info,
                                const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    LOG_I("ars_policy: %s", value);
    plocal->ars_policy = zt_atoi(value);
    return 0;
}

static zt_s32 max_ampdu_len_ulimit_handle(nic_info_st *nic_info,
        const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    LOG_I("max_ampdu_len_ulimit: %s", value);
    plocal->max_ampdu_len_ulimit = zt_atoi(value);
    return 0;
}

static zt_s32 wlan_guard_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;

    LOG_I("wlan_guard: %s", value);
    plocal->wlan_guard = zt_atoi(value);
    return 0;
}

static zt_s32 rf_power_parse_level(const zt_s8 *value)
{
    zt_s32 v;

    if (zt_strncmp(value, "low", zt_strlen("low")) == 0 ||
            zt_strncmp(value, "l", zt_strlen("l")) == 0)
        return E_RADIO_POWER_LEVEL_L;
    if (zt_strncmp(value, "medium", zt_strlen("medium")) == 0 ||
            zt_strncmp(value, "med", zt_strlen("med")) == 0 ||
            zt_strncmp(value, "m", zt_strlen("m")) == 0)
        return E_RADIO_POWER_LEVEL_M;
    if (zt_strncmp(value, "high", zt_strlen("high")) == 0 ||
            zt_strncmp(value, "h", zt_strlen("h")) == 0)
        return E_RADIO_POWER_LEVEL_H;

    v = zt_atoi(value);
    if (v < E_RADIO_POWER_LEVEL_L)
        v = E_RADIO_POWER_LEVEL_L;
    if (v > E_RADIO_POWER_LEVEL_H)
        v = E_RADIO_POWER_LEVEL_H;
    return v;
}

static zt_s32 rf_power_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = rf_power_parse_level(value);

    LOG_I("rf_power: %s -> %d", value, v);
    if (!plocal->txpower_cfg_set)
        plocal->rf_power = (zt_u8)v;
    return 0;
}

static zt_s32 txpower_dbm_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 dbm = zt_atoi(value);

    if (dbm < 0)
        dbm = 0;
    if (dbm > 30)
        dbm = 30;

    /* The hardware has calibrated L/M/H tables rather than a linear dBm DAC. */
    if (dbm <= 7)
        plocal->rf_power = E_RADIO_POWER_LEVEL_L;
    else if (dbm <= 15)
        plocal->rf_power = E_RADIO_POWER_LEVEL_M;
    else
        plocal->rf_power = E_RADIO_POWER_LEVEL_H;

    plocal->txpower_dbm = (zt_s8)dbm;
    plocal->txpower_cfg_set = 1;
    LOG_I("txpower_dbm: %s -> %d dBm (rf table %u)", value, dbm,
          plocal->rf_power);
    return 0;
}

#ifdef CFG_ENABLE_ADHOC_MODE
static zt_s32 adhoc_master_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = cfg_bool_value(value);

    plocal->adhoc_master = !!v;
    LOG_I("adhoc_master: %s -> %d", value, plocal->adhoc_master);
    return 0;
}
#endif

static zt_s32 rf_power1_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    hif_node_st *hif_node = (hif_node_st *)nic_info->hif_node;

    if (hif_node->drv_ops->driver_flag != 0)
        return 0;

    zt_s32 v = zt_atoi(value);
    if (v < E_RADIO_POWER_LEVEL_L) v = E_RADIO_POWER_LEVEL_L;
    if (v > E_RADIO_POWER_LEVEL_H) v = E_RADIO_POWER_LEVEL_H;
    LOG_I("rf_power1: %s -> %d", value, v);
    if (!plocal->txpower_cfg_set)
        plocal->rf_power = (zt_u8)v;
    return 0;
}

static zt_s32 rf_power2_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    hif_node_st *hif_node = (hif_node_st *)nic_info->hif_node;

    if (hif_node->drv_ops->driver_flag != 1)
        return 0;

    zt_s32 v = zt_atoi(value);
    if (v < E_RADIO_POWER_LEVEL_L) v = E_RADIO_POWER_LEVEL_L;
    if (v > E_RADIO_POWER_LEVEL_H) v = E_RADIO_POWER_LEVEL_H;
    LOG_I("rf_power2: %s -> %d", value, v);
    if (!plocal->txpower_cfg_set)
        plocal->rf_power = (zt_u8)v;
    return 0;
}

static zt_s32 vco_cur_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 vco_cur = 0;
    const char *p = (const char *)value;

    /* Preserve firmware legacy/default calibration sentinel 0xff. */
    while (*p == ' ' || *p == '\t')
        p++;

    if ((p[0] == '0') && (p[1] == 'x' || p[1] == 'X') &&
            (p[2] == 'f' || p[2] == 'F') &&
            (p[3] == 'f' || p[3] == 'F'))
    {
        vco_cur = 0xff;
    }
    else
    {
        vco_cur = zt_atoi(value);
        if (vco_cur < 0)
            vco_cur = 0;
        else if (vco_cur > 32)
            /* Preserve the firmware/calibration sentinel for out-of-range
             * values; do not clamp it to 32. */
            vco_cur = 0xff;
    }

    LOG_I("vco_cur: %d (0x%02x)", vco_cur, vco_cur);
    plocal->vco_cur = (zt_u8)vco_cur;
    return 0;
}

static zt_s32 sdio_clk_pwr_save_handle(nic_info_st *nic_info,
                                       const zt_s8 *value)
{
    hif_node_st *hif_node = nic_info->hif_node;

    LOG_I("sdio_clk_pwr_save: %s", value);
    if (hif_node->hif_type == HIF_SDIO)
    {
        hif_node->u.sdio.clk_pwr_save = !!zt_atoi(value);
    }
    return 0;
}

static zt_s32 rts_thresh_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = zt_atoi(value);
    if (v < 1) v = 1;
    if (v > 2347) v = 2347;
    plocal->rts_thresh = (zt_u16)v;
    LOG_I("rts_thresh: %s -> %d", value, v);
    return 0;
}

static zt_s32 frag_thresh_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = zt_atoi(value);
    if (v < 256) v = 256;
    if (v > 2346) v = 2346;
    plocal->frag_thresh = (zt_u16)v;
    LOG_I("frag_thresh: %s -> %d", value, v);
    return 0;
}

static zt_s32 vcs_en_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    plocal->vcs_en = !!cfg_bool_value(value);
    LOG_I("vcs_en: %s -> %d", value, plocal->vcs_en);
    return 0;
}

static zt_s32 vcs_type_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = zt_atoi(value);
    if (v < NONE_VCS) v = NONE_VCS;
    if (v > CTS_TO_SELF) v = CTS_TO_SELF;
    plocal->vcs_type = (zt_u8)v;
    LOG_I("vcs_type: %s -> %d", value, v);
    return 0;
}

static zt_s32 tx_data_rpt_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    plocal->tx_data_rpt = !!cfg_bool_value(value);
    LOG_I("tx_data_rpt: %s -> %d", value, plocal->tx_data_rpt);
    return 0;
}

static zt_s32 sm_ps_support_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = zt_atoi(value);
    if (v != 0 && v != 1) v = 0;
    plocal->sm_ps_support = (zt_u8)v;
    LOG_I("sm_ps_support: %s -> %d", value, v);
    return 0;
}

static zt_s32 wdn_sleep_support_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    plocal->wdn_sleep_support = !!cfg_bool_value(value);
    LOG_I("wdn_sleep_support: %s -> %d", value, plocal->wdn_sleep_support);
    return 0;
}

static zt_s32 ldpc_support_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    plocal->ldpc_support = !!cfg_bool_value(value);
    LOG_I("ldpc_support: %s -> %d", value, plocal->ldpc_support);
    return 0;
}

static zt_s32 tx_stbc_support_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    plocal->tx_stbc_support = !!cfg_bool_value(value);
    LOG_I("tx_stbc_support: %s -> %d", value, plocal->tx_stbc_support);
    return 0;
}

static zt_s32 max_rx_ampdu_factor_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = zt_atoi(value);
    if (v < 0) v = 0;
    if (v > 3) v = 3;
    plocal->max_rx_ampdu_factor = (zt_u8)v;
    LOG_I("max_rx_ampdu_factor: %s -> %d", value, v);
    return 0;
}

static zt_s32 best_ampdu_density_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v = zt_atoi(value);
    if (v < 0) v = 0;
    if (v > 7) v = 7;
    plocal->best_ampdu_density = (zt_u8)v;
    LOG_I("best_ampdu_density: %s -> %d", value, v);
    return 0;
}

static zt_s32 ht_mcs_max_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_s32 v;

    if (zt_strncmp(value, "auto", zt_strlen("auto")) == 0)
    {
        plocal->ht_mcs_max = 0xff;
        LOG_I("ht_mcs_max: auto");
        return 0;
    }

    v = zt_atoi(value);
    if (v < 0) v = 0;
    if (v > 7) v = 7;
    plocal->ht_mcs_max = (zt_u8)v;
    LOG_I("ht_mcs_max: %s -> %d", value, v);
    return 0;
}

static zt_s32 wireless_mode_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    zt_u8 mode = WIRELESS_AUTO;
    LOG_I("wireless_mode: %s", value);

    if (zt_strncmp(value, "auto", 4) == 0) mode = WIRELESS_AUTO;
    else if (zt_strncmp(value, "bgn", 3) == 0) mode = WIRELESS_11BG_24N;
    else if (zt_strncmp(value, "bg", 2) == 0) mode = WIRELESS_11BG;
    else if (zt_strncmp(value, "gn", 2) == 0) mode = WIRELESS_11G_24N;
    else if (zt_strncmp(value, "bn", 2) == 0) mode = WIRELESS_11B_24N;
    else if (zt_strncmp(value, "b", 1) == 0) mode = WIRELESS_11B;
    else if (zt_strncmp(value, "g", 1) == 0) mode = WIRELESS_11G;
    else if (zt_strncmp(value, "n", 1) == 0) mode = WIRELESS_11_24N;
    else
    {
        LOG_E("cfg file format error for wireless_mode");
        return 0;
    }
    plocal->wireless_mode = mode;
    return 0;
}

static zt_s32 sgi_20_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    if (zt_strncmp(value, "auto", 4) == 0) plocal->sgi_20 = 255;
    else plocal->sgi_20 = cfg_bool_value(value) ? 1 : 0;
    LOG_I("sgi_20: %d", plocal->sgi_20);
    return 0;
}

static zt_s32 sgi_40_handle(nic_info_st *nic_info, const zt_s8 *value)
{
    local_info_st *plocal = (local_info_st *)nic_info->local_info;
    if (zt_strncmp(value, "auto", 4) == 0) plocal->sgi_40 = 255;
    else plocal->sgi_40 = cfg_bool_value(value) ? 1 : 0;
    LOG_I("sgi_40: %d", plocal->sgi_40);
    return 0;
}

static void cfg_buffer_handle(const zt_s8 *in_buffer, zt_s8 *out_buffer)
{
    zt_s32 i, j;
    zt_s32 len = zt_strlen(in_buffer);

    for (i = 0, j = 0; i < len; i++)
    {
        if (!zt_isspace(in_buffer[i]))
        {
            out_buffer[j] = in_buffer[i];
            j++;
        }
    }
    out_buffer[j] = '\0';
}

static void cfg_parse_handle(nic_info_st *nic_info, const zt_s8 *buffer)
{
    zt_s32 i;
    const zt_s8 *key;
    zt_s8 *pos;
    zt_s32 num = sizeof(__gl_cfg_parse_st) / sizeof(struct cfg_parse_t);

    pos = zt_strchr(buffer, '=');
    if (pos == NULL)
    {
        LOG_E("can't find sep for this param");
        return;
    }
    *pos++ = '\0';
    key = (zt_s8 *)buffer;
    for (i = 0; i < num; i++)
    {
        if (zt_strcmp(__gl_cfg_parse_st[i].key, key) == 0)
        {
            __gl_cfg_parse_st[i].parse_handle(nic_info, pos);
            return;
        }
    }
    LOG_W("[%s]: no handler for key: %s", __func__, key);
}

static void cfg_preparse_handle(hif_mngent_st *hif, const zt_s8 *buffer)
{
    zt_s32 i;
    const zt_s8 *key;
    zt_s8 *pos;
    zt_s32 num = sizeof(__gl_cfg_preparse_st) / sizeof(struct cfg_preparse_t);

    pos = zt_strchr(buffer, '=');
    if (pos == NULL)
    {
        LOG_E("can't find sep for this param");
        return;
    }
    *pos++ = '\0';
    key = (zt_s8 *)buffer;
    for (i = 0; i < num; i++)
    {
        if (zt_strcmp(__gl_cfg_preparse_st[i].key, key) == 0)
        {
            __gl_cfg_preparse_st[i].preparse_handle(hif, pos);
            return;
        }
    }
    //    LOG_W("[%s]:can't find handler for this key:%s, please register it!",
    //          __func__, key);
}

static zt_s32 cfg_read_line(const zt_s8 *cfg_content, size_t size, loff_t *pos,
                            zt_s8 *buffer, zt_u32 length)
{
    zt_s32 ret;
    zt_u32 read_length;
    zt_s8 *eol;
    loff_t offset = *pos;

    if (offset >= size)
    {
        return 0;
    }

    if ((offset + length) > size)
    {
        read_length = size - offset;
    }
    else
    {
        read_length = length;
    }
    zt_memcpy(buffer, &cfg_content[offset], read_length);
    offset += read_length;
    eol = strstr(buffer, ZT_FILE_EOF);
    if (eol != NULL)
    {
        *eol++ = '\0';
        if (!zt_strcmp(ZT_FILE_EOF, "\r\n"))
        {
            *eol++ = '\0';
        }
        ret = (size_t)(eol - buffer);
        offset -= (read_length - ret);
        *pos = offset;
    }
    else
    {
        return -1;
    }

    return ret;
}

zt_s32 zt_cfg_file_parse(void *pnic_info)
{
    zt_s8 read_buffer[513] = {0};
    zt_s8 handle_buffer[513] = {0};
    loff_t pos = 0;
    nic_info_st *nic_info = (nic_info_st *)pnic_info;
    hif_mngent_st *hif = hif_mngent_get();

    if (hif->cfg_size == 0)
    {
        LOG_E("cfg_size is 0, no need parse");
        return -1;
    }

    while (cfg_read_line(hif->cfg_content, hif->cfg_size, &pos, read_buffer,
                         512) > 0)
    {
        if (zt_strlen(read_buffer) == 0)
        {
            continue;
        }

        cfg_buffer_handle((const zt_s8 *)read_buffer, handle_buffer);
        if ((handle_buffer[0] == '#') || (zt_strlen(handle_buffer) == 0))
        {
            continue;
        }

        cfg_parse_handle(nic_info, handle_buffer);
    }

    return 0;
}

zt_s32 zt_cfg_file_preparse(void *phif)
{
    zt_s8 read_buffer[513] = {0};
    zt_s8 handle_buffer[513] = {0};
    loff_t pos = 0;
    hif_mngent_st *hif = phif;

    if (hif->cfg_size == 0)
    {
        LOG_E("cfg_size is 0, no need parse");
        return -1;
    }

    while (cfg_read_line(hif->cfg_content, hif->cfg_size, &pos,
                         read_buffer, 512) > 0)
    {
        if (zt_strlen(read_buffer) == 0)
        {
            continue;
        }

        cfg_buffer_handle((const zt_s8 *)read_buffer, handle_buffer);
        if ((handle_buffer[0] == '#') || (zt_strlen(handle_buffer) == 0))
        {
            continue;
        }

        cfg_preparse_handle(hif, handle_buffer);
    }

    return 0;
}

