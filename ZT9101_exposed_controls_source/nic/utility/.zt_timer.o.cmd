savedcmd_nic/utility/zt_timer.o := gcc-13 -Wp,-MMD,nic/utility/.zt_timer.o.d -nostdinc -I/usr/src/linux-headers-6.17.0-35-generic/arch/x86/include -I/usr/src/linux-headers-6.17.0-35-generic/arch/x86/include/generated -I/usr/src/linux-headers-6.17.0-35-generic/include -I/usr/src/linux-headers-6.17.0-35-generic/include -I/usr/src/linux-headers-6.17.0-35-generic/arch/x86/include/uapi -I/usr/src/linux-headers-6.17.0-35-generic/arch/x86/include/generated/uapi -I/usr/src/linux-headers-6.17.0-35-generic/include/uapi -I/usr/src/linux-headers-6.17.0-35-generic/include/generated/uapi -include /usr/src/linux-headers-6.17.0-35-generic/include/linux/compiler-version.h -include /usr/src/linux-headers-6.17.0-35-generic/include/linux/kconfig.h -I/usr/src/linux-headers-6.17.0-35-generic/ubuntu/include -include /usr/src/linux-headers-6.17.0-35-generic/include/linux/compiler_types.h -D__KERNEL__ -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mno-sse4a -fcf-protection=none -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -march=x86-64 -mtune=generic -mno-red-zone -mcmodel=kernel -mstack-protector-guard-reg=gs -mstack-protector-guard-symbol=__ref_stack_chk_guard -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -mindirect-branch-cs-prefix -mfunction-return=thunk-extern -fno-jump-tables -mharden-sls=all -fpatchable-function-entry=16,16 -fno-delete-null-pointer-checks -O2 -fno-allow-store-data-races -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -ftrivial-auto-var-init=zero -fno-stack-clash-protection -fzero-call-used-regs=used-gpr -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -falign-functions=16 -fstrict-flex-arrays=3 -fno-strict-overflow -fno-stack-check -fconserve-stack -fno-builtin-wcslen -Wall -Wextra -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=1024 -Wno-main -Wno-dangling-pointer -Wvla-larger-than=1 -Wno-pointer-sign -Wcast-function-type -Wno-array-bounds -Wno-stringop-overflow -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wenum-conversion -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-type-limits -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter -g -gdwarf-5 -DCONFIG_LITTLE_ENDIAN -D'ZT_VERSION="V1.2.xxx.xxxxxxxx"' -D'COMPILE_TIME="2026-09-04 09:06:26"' -DZT_DEBUG_LEVEL=0 -DCONFIG_FW_FILE -DCONFIG_ZT9101XV20_SUPPORT -DCONFIG_ZT9101XV30_SUPPORT -O1 -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/ -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux/os_porting -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux/hif -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux/netdev -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux/cfg80211 -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux/iw -I/home/wk/Downloads/ZT9101_exposed_controls_source/os/linux/pwr -I/home/wk/Downloads/ZT9101_exposed_controls_source/nic -I/home/wk/Downloads/ZT9101_exposed_controls_source/nic/utility -I/home/wk/Downloads/ZT9101_exposed_controls_source/nic/p2p -D__linux__ -Wall -Wextra -Wno-unused-parameter -Wno-implicit-fallthrough -Wno-sign-compare -Wno-missing-field-initializers -Wno-address-of-packed-member -Wno-uninitialized -Wno-type-limits -Wno-empty-body -w -DCONFIG_USB_FLAG -DCFG_ENABLE_AP_MODE -DCFG_ENABLE_ADHOC_MODE -DCFG_ENABLE_MONITOR_MODE -DZT_WEP_AUTH_ENABLE_WEXT -DCONFIG_IOCTL_CFG80211 -DZT_USE_CFG80211_STA_EVENT  -fsanitize=bounds-strict -fsanitize=shift -fsanitize=bool -fsanitize=enum    -DMODULE  -DKBUILD_BASENAME='"zt_timer"' -DKBUILD_MODNAME='"zt9101_ztopmac_usb"' -D__KBUILD_MODNAME=kmod_zt9101_ztopmac_usb -c -o nic/utility/zt_timer.o nic/utility/zt_timer.c   ; /usr/src/linux-headers-6.17.0-35-generic/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --retpoline --rethunk --sls --stackval --static-call --uaccess --prefix=16 --Werror   --module nic/utility/zt_timer.o

source_nic/utility/zt_timer.o := nic/utility/zt_timer.c

deps_nic/utility/zt_timer.o := \
  /usr/src/linux-headers-6.17.0-35-generic/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /usr/src/linux-headers-6.17.0-35-generic/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /usr/src/linux-headers-6.17.0-35-generic/include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/CC_HAS_COUNTED_BY) \
    $(wildcard include/config/CC_HAS_MULTIDIMENSIONAL_NONSTRING) \
    $(wildcard include/config/UBSAN_INTEGER_WRAP) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /usr/src/linux-headers-6.17.0-35-generic/include/linux/compiler_attributes.h \
  /usr/src/linux-headers-6.17.0-35-generic/include/linux/compiler-gcc.h \
    $(wildcard include/config/MITIGATION_RETPOLINE) \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \
    $(wildcard include/config/CC_HAS_TYPEOF_UNQUAL) \
  /home/wk/Downloads/ZT9101_exposed_controls_source/os/zt_typedef.h \

nic/utility/zt_timer.o: $(deps_nic/utility/zt_timer.o)

$(deps_nic/utility/zt_timer.o):

nic/utility/zt_timer.o: $(wildcard /usr/src/linux-headers-6.17.0-35-generic/tools/objtool/objtool)
