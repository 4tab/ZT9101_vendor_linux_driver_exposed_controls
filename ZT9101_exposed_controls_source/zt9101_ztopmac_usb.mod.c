#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x85c198fe, "cfg80211_inform_bss_frame_data" },
	{ 0x3efd9ef1, "alloc_etherdev_mqs" },
	{ 0x22755710, "filp_open" },
	{ 0xc1249a30, "strcpy" },
	{ 0xbee76e2a, "usb_alloc_urb" },
	{ 0x04cd5a4f, "cfg80211_mgmt_tx_status_ext" },
	{ 0xd272d446, "yield" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x887ecaba, "usb_free_urb" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x57860fb4, "wait_for_completion_timeout" },
	{ 0xf5ef60bd, "skb_put" },
	{ 0x649ce331, "iwe_stream_add_event" },
	{ 0x9b3fafdc, "cfg80211_scan_done" },
	{ 0x534ed5f3, "__msecs_to_jiffies" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0x40a621c5, "snprintf" },
	{ 0x65026e43, "complete" },
	{ 0x49733ad6, "queue_work_on" },
	{ 0x9a1b2a81, "unregister_netdev" },
	{ 0x08c44b14, "cfg80211_remain_on_channel_expired" },
	{ 0xb2051ad0, "skb_dequeue" },
	{ 0x60c9c0b3, "__init_swait_queue_head" },
	{ 0x756dc180, "usb_register_driver" },
	{ 0x4073d0de, "up" },
	{ 0xe3e5b59b, "dev_alloc_name" },
	{ 0xedb8a7bb, "___pskb_trim" },
	{ 0xa53f4e29, "memcpy" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xfcd3de9e, "proc_create_data" },
	{ 0x2352b148, "timer_delete" },
	{ 0x5e505530, "kthread_should_stop" },
	{ 0x83af67b6, "cfg80211_new_sta" },
	{ 0x4d1cf242, "unregister_netdevice_queue" },
	{ 0xe1e1f979, "_raw_spin_lock_irqsave" },
	{ 0xde338d9a, "_raw_spin_lock" },
	{ 0x91a87e4e, "cfg80211_disconnected" },
	{ 0xd272d446, "__fentry__" },
	{ 0xdba15b90, "wake_up_process" },
	{ 0x09fcf3e0, "proc_get_parent_data" },
	{ 0xc627dd48, "eth_type_trans" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0x19076252, "wiphy_new_nm" },
	{ 0xe8213e80, "_printk" },
	{ 0x01a37e1a, "cfg80211_ready_on_channel" },
	{ 0x5629a063, "strncasecmp" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x33c506c2, "usb_put_dev" },
	{ 0x9ffccd00, "usb_bulk_msg" },
	{ 0x9ba12bc2, "usb_reset_device" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xde338d9a, "_raw_spin_unlock_bh" },
	{ 0x49003753, "wiphy_register" },
	{ 0xf64ac983, "__copy_overflow" },
	{ 0x9479a1e8, "strnlen" },
	{ 0xb68fbe57, "usb_get_dev" },
	{ 0x50249c8a, "cfg80211_put_bss" },
	{ 0x5a844b26, "__x86_indirect_thunk_rdx" },
	{ 0xb3cfa727, "usb_submit_urb" },
	{ 0x6d0c3d6a, "skb_queue_tail" },
	{ 0x3ae5d2b5, "ieee80211_get_channel_khz" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0x9c0551c6, "tasklet_kill" },
	{ 0xb1172073, "init_net" },
	{ 0x47e70606, "cfg80211_ibss_joined" },
	{ 0xf5ef60bd, "skb_pull" },
	{ 0x630954b9, "__write_overflow_field" },
	{ 0x32feeafc, "mod_timer" },
	{ 0xcdec1689, "tasklet_init" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xd7a59a65, "vmalloc_noprof" },
	{ 0x70578dfa, "wiphy_apply_custom_regulatory" },
	{ 0xf8b91c45, "proc_mkdir_data" },
	{ 0xbeb1d261, "destroy_workqueue" },
	{ 0xf46d5bf3, "mutex_lock" },
	{ 0xf5ef60bd, "skb_push" },
	{ 0x5a844b26, "__x86_indirect_thunk_rbx" },
	{ 0x2435d559, "strncmp" },
	{ 0x95bff530, "usb_control_msg" },
	{ 0x83af67b6, "cfg80211_del_sta_sinfo" },
	{ 0xc31cb4a7, "wireless_send_event" },
	{ 0xd94efd11, "const_current_task" },
	{ 0xff3fa122, "register_netdev" },
	{ 0xc609ff70, "strncpy" },
	{ 0x9c0551c6, "__tasklet_schedule" },
	{ 0x5a844b26, "__x86_indirect_thunk_r13" },
	{ 0x6fa50bae, "wiphy_unregister" },
	{ 0x9a1b2a81, "free_netdev" },
	{ 0x402db74e, "memcmp" },
	{ 0x2e56bcda, "kthread_stop" },
	{ 0x173ec8da, "sscanf" },
	{ 0xc1e6c71e, "__mutex_init" },
	{ 0x91f40251, "usb_deregister" },
	{ 0x12694399, "down_trylock" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0xe199f25f, "jiffies_to_msecs" },
	{ 0x81a1a811, "_raw_spin_unlock_irqrestore" },
	{ 0x9a1b2a81, "netif_tx_stop_all_queues" },
	{ 0xf5755d70, "netif_tx_wake_queue" },
	{ 0xc0112974, "default_llseek" },
	{ 0x7295b8c3, "ieee80211_freq_khz_to_channel" },
	{ 0x27683a56, "memset" },
	{ 0x5a844b26, "__x86_indirect_thunk_r10" },
	{ 0x4d8419c6, "param_ops_charp" },
	{ 0xa96ed8ce, "kernel_read" },
	{ 0xbeb1d261, "__flush_workqueue" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x9d212913, "iwe_stream_add_point" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0x9ae3e77c, "netif_rx" },
	{ 0xec1444cd, "__netdev_alloc_skb" },
	{ 0x888b8f57, "strcmp" },
	{ 0x3685d001, "skb_trim" },
	{ 0x357aaab3, "mutex_trylock" },
	{ 0xbd03ed67, "USER_PTR_MAX" },
	{ 0xfd285498, "unregister_netdevice_notifier" },
	{ 0x058c185a, "jiffies" },
	{ 0x3855aac9, "kthread_create_on_node" },
	{ 0x11bacf83, "seq_read" },
	{ 0xdd6830c7, "sprintf" },
	{ 0x82fd7238, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7ec472ba, "cpu_number" },
	{ 0x7ec472ba, "__preempt_count" },
	{ 0xf1de9e85, "vfree" },
	{ 0xe4e340ac, "cfg80211_rx_mgmt_ext" },
	{ 0xa5c7582d, "strsep" },
	{ 0xf46d5bf3, "mutex_unlock" },
	{ 0x13e72361, "filp_close" },
	{ 0xcdeafffc, "remove_proc_entry" },
	{ 0xecd17989, "__kmalloc_cache_noprof" },
	{ 0x887ecaba, "usb_kill_urb" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0x75738bed, "__warn_printk" },
	{ 0xee5132ff, "netif_carrier_off" },
	{ 0xfd285498, "register_netdevice_notifier" },
	{ 0x0d8b6c91, "seq_printf" },
	{ 0x12694399, "down_interruptible" },
	{ 0xc01aafd2, "get_random_u32" },
	{ 0xa8eeec5f, "skb_clone" },
	{ 0xde338d9a, "_raw_spin_lock_bh" },
	{ 0xee5132ff, "netif_carrier_on" },
	{ 0xc0112974, "vfs_llseek" },
	{ 0x9c0551c6, "__tasklet_hi_schedule" },
	{ 0x024d45a2, "single_release" },
	{ 0x02f9bbf0, "timer_init_key" },
	{ 0xdf4bee3d, "alloc_workqueue_noprof" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0x43a349ca, "strlen" },
	{ 0x0ccfc673, "dev_kfree_skb_any_reason" },
	{ 0xce105414, "single_open" },
	{ 0x296b9459, "strchr" },
	{ 0xde338d9a, "_raw_spin_unlock" },
	{ 0x1d59f5ba, "cfg80211_connect_done" },
	{ 0x50249c8a, "cfg80211_unlink_bss" },
	{ 0x0f04945e, "__cfg80211_get_bss" },
	{ 0x6fa50bae, "wiphy_free" },
	{ 0x67628f51, "msleep" },
	{ 0x12ca6142, "ktime_get_with_offset" },
	{ 0x08bfc903, "kmalloc_caches" },
	{ 0xb11f725c, "d_path" },
	{ 0xff3fa122, "register_netdevice" },
	{ 0x814e12e5, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x85c198fe,
	0x3efd9ef1,
	0x22755710,
	0xc1249a30,
	0xbee76e2a,
	0x04cd5a4f,
	0xd272d446,
	0xa61fd7aa,
	0x887ecaba,
	0x092a35a2,
	0x57860fb4,
	0xf5ef60bd,
	0x649ce331,
	0x9b3fafdc,
	0x534ed5f3,
	0xd710adbf,
	0x40a621c5,
	0x65026e43,
	0x49733ad6,
	0x9a1b2a81,
	0x08c44b14,
	0xb2051ad0,
	0x60c9c0b3,
	0x756dc180,
	0x4073d0de,
	0xe3e5b59b,
	0xedb8a7bb,
	0xa53f4e29,
	0xcb8b6ec6,
	0xfcd3de9e,
	0x2352b148,
	0x5e505530,
	0x83af67b6,
	0x4d1cf242,
	0xe1e1f979,
	0xde338d9a,
	0x91a87e4e,
	0xd272d446,
	0xdba15b90,
	0x09fcf3e0,
	0xc627dd48,
	0x5a844b26,
	0x19076252,
	0xe8213e80,
	0x01a37e1a,
	0x5629a063,
	0xbd03ed67,
	0x33c506c2,
	0x9ffccd00,
	0x9ba12bc2,
	0xd272d446,
	0xde338d9a,
	0x49003753,
	0xf64ac983,
	0x9479a1e8,
	0xb68fbe57,
	0x50249c8a,
	0x5a844b26,
	0xb3cfa727,
	0x6d0c3d6a,
	0x3ae5d2b5,
	0x90a48d82,
	0x9c0551c6,
	0xb1172073,
	0x47e70606,
	0xf5ef60bd,
	0x630954b9,
	0x32feeafc,
	0xcdec1689,
	0xbd03ed67,
	0xd7a59a65,
	0x70578dfa,
	0xf8b91c45,
	0xbeb1d261,
	0xf46d5bf3,
	0xf5ef60bd,
	0x5a844b26,
	0x2435d559,
	0x95bff530,
	0x83af67b6,
	0xc31cb4a7,
	0xd94efd11,
	0xff3fa122,
	0xc609ff70,
	0x9c0551c6,
	0x5a844b26,
	0x6fa50bae,
	0x9a1b2a81,
	0x402db74e,
	0x2e56bcda,
	0x173ec8da,
	0xc1e6c71e,
	0x91f40251,
	0x12694399,
	0xe54e0a6b,
	0xe199f25f,
	0x81a1a811,
	0x9a1b2a81,
	0xf5755d70,
	0xc0112974,
	0x7295b8c3,
	0x27683a56,
	0x5a844b26,
	0x4d8419c6,
	0xa96ed8ce,
	0xbeb1d261,
	0xd272d446,
	0x9d212913,
	0x092a35a2,
	0x9ae3e77c,
	0xec1444cd,
	0x888b8f57,
	0x3685d001,
	0x357aaab3,
	0xbd03ed67,
	0xfd285498,
	0x058c185a,
	0x3855aac9,
	0x11bacf83,
	0xdd6830c7,
	0x82fd7238,
	0x7ec472ba,
	0x7ec472ba,
	0xf1de9e85,
	0xe4e340ac,
	0xa5c7582d,
	0xf46d5bf3,
	0x13e72361,
	0xcdeafffc,
	0xecd17989,
	0x887ecaba,
	0x546c19d9,
	0x75738bed,
	0xee5132ff,
	0xfd285498,
	0x0d8b6c91,
	0x12694399,
	0xc01aafd2,
	0xa8eeec5f,
	0xde338d9a,
	0xee5132ff,
	0xc0112974,
	0x9c0551c6,
	0x024d45a2,
	0x02f9bbf0,
	0xdf4bee3d,
	0xe4de56b4,
	0x43a349ca,
	0x0ccfc673,
	0xce105414,
	0x296b9459,
	0xde338d9a,
	0x1d59f5ba,
	0x50249c8a,
	0x0f04945e,
	0x6fa50bae,
	0x67628f51,
	0x12ca6142,
	0x08bfc903,
	0xb11f725c,
	0xff3fa122,
	0x814e12e5,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"cfg80211_inform_bss_frame_data\0"
	"alloc_etherdev_mqs\0"
	"filp_open\0"
	"strcpy\0"
	"usb_alloc_urb\0"
	"cfg80211_mgmt_tx_status_ext\0"
	"yield\0"
	"__check_object_size\0"
	"usb_free_urb\0"
	"_copy_from_user\0"
	"wait_for_completion_timeout\0"
	"skb_put\0"
	"iwe_stream_add_event\0"
	"cfg80211_scan_done\0"
	"__msecs_to_jiffies\0"
	"__kmalloc_noprof\0"
	"snprintf\0"
	"complete\0"
	"queue_work_on\0"
	"unregister_netdev\0"
	"cfg80211_remain_on_channel_expired\0"
	"skb_dequeue\0"
	"__init_swait_queue_head\0"
	"usb_register_driver\0"
	"up\0"
	"dev_alloc_name\0"
	"___pskb_trim\0"
	"memcpy\0"
	"kfree\0"
	"proc_create_data\0"
	"timer_delete\0"
	"kthread_should_stop\0"
	"cfg80211_new_sta\0"
	"unregister_netdevice_queue\0"
	"_raw_spin_lock_irqsave\0"
	"_raw_spin_lock\0"
	"cfg80211_disconnected\0"
	"__fentry__\0"
	"wake_up_process\0"
	"proc_get_parent_data\0"
	"eth_type_trans\0"
	"__x86_indirect_thunk_rax\0"
	"wiphy_new_nm\0"
	"_printk\0"
	"cfg80211_ready_on_channel\0"
	"strncasecmp\0"
	"__ref_stack_chk_guard\0"
	"usb_put_dev\0"
	"usb_bulk_msg\0"
	"usb_reset_device\0"
	"__stack_chk_fail\0"
	"_raw_spin_unlock_bh\0"
	"wiphy_register\0"
	"__copy_overflow\0"
	"strnlen\0"
	"usb_get_dev\0"
	"cfg80211_put_bss\0"
	"__x86_indirect_thunk_rdx\0"
	"usb_submit_urb\0"
	"skb_queue_tail\0"
	"ieee80211_get_channel_khz\0"
	"__ubsan_handle_out_of_bounds\0"
	"tasklet_kill\0"
	"init_net\0"
	"cfg80211_ibss_joined\0"
	"skb_pull\0"
	"__write_overflow_field\0"
	"mod_timer\0"
	"tasklet_init\0"
	"random_kmalloc_seed\0"
	"vmalloc_noprof\0"
	"wiphy_apply_custom_regulatory\0"
	"proc_mkdir_data\0"
	"destroy_workqueue\0"
	"mutex_lock\0"
	"skb_push\0"
	"__x86_indirect_thunk_rbx\0"
	"strncmp\0"
	"usb_control_msg\0"
	"cfg80211_del_sta_sinfo\0"
	"wireless_send_event\0"
	"const_current_task\0"
	"register_netdev\0"
	"strncpy\0"
	"__tasklet_schedule\0"
	"__x86_indirect_thunk_r13\0"
	"wiphy_unregister\0"
	"free_netdev\0"
	"memcmp\0"
	"kthread_stop\0"
	"sscanf\0"
	"__mutex_init\0"
	"usb_deregister\0"
	"down_trylock\0"
	"__fortify_panic\0"
	"jiffies_to_msecs\0"
	"_raw_spin_unlock_irqrestore\0"
	"netif_tx_stop_all_queues\0"
	"netif_tx_wake_queue\0"
	"default_llseek\0"
	"ieee80211_freq_khz_to_channel\0"
	"memset\0"
	"__x86_indirect_thunk_r10\0"
	"param_ops_charp\0"
	"kernel_read\0"
	"__flush_workqueue\0"
	"__x86_return_thunk\0"
	"iwe_stream_add_point\0"
	"_copy_to_user\0"
	"netif_rx\0"
	"__netdev_alloc_skb\0"
	"strcmp\0"
	"skb_trim\0"
	"mutex_trylock\0"
	"USER_PTR_MAX\0"
	"unregister_netdevice_notifier\0"
	"jiffies\0"
	"kthread_create_on_node\0"
	"seq_read\0"
	"sprintf\0"
	"__ubsan_handle_shift_out_of_bounds\0"
	"cpu_number\0"
	"__preempt_count\0"
	"vfree\0"
	"cfg80211_rx_mgmt_ext\0"
	"strsep\0"
	"mutex_unlock\0"
	"filp_close\0"
	"remove_proc_entry\0"
	"__kmalloc_cache_noprof\0"
	"usb_kill_urb\0"
	"validate_usercopy_range\0"
	"__warn_printk\0"
	"netif_carrier_off\0"
	"register_netdevice_notifier\0"
	"seq_printf\0"
	"down_interruptible\0"
	"get_random_u32\0"
	"skb_clone\0"
	"_raw_spin_lock_bh\0"
	"netif_carrier_on\0"
	"vfs_llseek\0"
	"__tasklet_hi_schedule\0"
	"single_release\0"
	"timer_init_key\0"
	"alloc_workqueue_noprof\0"
	"__ubsan_handle_load_invalid_value\0"
	"strlen\0"
	"dev_kfree_skb_any_reason\0"
	"single_open\0"
	"strchr\0"
	"_raw_spin_unlock\0"
	"cfg80211_connect_done\0"
	"cfg80211_unlink_bss\0"
	"__cfg80211_get_bss\0"
	"wiphy_free\0"
	"msleep\0"
	"ktime_get_with_offset\0"
	"kmalloc_caches\0"
	"d_path\0"
	"register_netdevice\0"
	"module_layout\0"
;

MODULE_INFO(depends, "cfg80211");

MODULE_ALIAS("usb:v350Bp9101d*dc*dsc*dp*icFFiscFFipFFin*");
MODULE_ALIAS("usb:v2310p9086d*dc*dsc*dp*icFFiscFFipFFin*");
MODULE_ALIAS("usb:v350Bp9086d*dc*dsc*dp*icFFiscFFipFFin*");
MODULE_ALIAS("usb:v350Bp9106d*dc*dsc*dp*icFFiscFFipFFin*");

MODULE_INFO(srcversion, "ACE9936DD57A811BEEC63AA");
